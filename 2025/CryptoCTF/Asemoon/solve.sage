#!/usr/bin/env sage
from sage.all import *
from pwn import process, context
import time
from Crypto.Util.number import long_to_bytes

context.log_level = 'Debug'   # change to 'debug' for verbose output

MASK = (1 << 64) - 1

def int_to_vec(x):
    return vector(GF(2), [(x >> i) & 1 for i in range(64)])

def vec_to_int(v):
    return sum(int(v[i]) << i for i in range(64))

def update(v, m, CT):
    v ^= m
    v = (v >> 8) ^ CT[v & 0xff]
    return v & MASK

def recheck(msg, v, CT):
    for m in msg:
        v ^= m
        v = (v >> 8) ^ CT[v & 0xff]
    return v & MASK

def make_CT(CP):
    CT = []
    for cb in range(256):
        v = cb
        for _ in range(8):
            if v & 1:
                v = (v >> 1) ^ CP
            else:
                v >>= 1
        CT.append(v & MASK)
    return CT

def build_U(CT):
    M = Matrix(GF(2), 64, 64)
    for j in range(64):
        img = update(1 << j, 0, CT)
        for i in range(64):
            if (img >> i) & 1:
                M[i, j] = 1
    return M

def build_B8(CT):
    """Matrix mapping an 8-byte message (64-bit int) to recheck(msg, 0)."""
    M = Matrix(GF(2), 64, 64)
    for j in range(64):
        msg = (1 << j).to_bytes(8, "big")
        img = recheck(msg, 0, CT)
        for i in range(64):
            if (img >> i) & 1:
                M[i, j] = 1
    return M

class Conn:
    def __init__(self, cmd):
        self.io = process(cmd)

    def query_P(self):
        self.io.recvuntil(b'[Q]uit')
        self.io.sendline(b'p')
        self.io.recvuntil(b'first public information is:')
        pub1 = int(self.io.recvline().strip())
        self.io.recvuntil(b'second public information is:')
        pub2 = int(self.io.recvline().strip())
        self.io.recvuntil(b'third public information is:')
        pub3 = int(self.io.recvline().strip())
        return pub1, pub2, pub3

    def login(self, token):
        self.io.recvuntil(b'[Q]uit')
        self.io.sendline(b'l')
        self.io.recvuntil(b'Please send your hex token here:')
        self.io.sendline(hex(token)[2:].encode())
        return self.io.recvall()

def recover_CP(c):
    rems, mods = [], []
    while True:
        pub1, pub2, pub3 = c.query_P()
        p = pub2
        fac = factor(p - 1)
        maxp = max(int(f[0]) for f in fac)
        if maxp > 2**32:
            continue
        x = discrete_log(Mod(pub3, p), Mod(5, p))
        ord5 = Mod(5, p).multiplicative_order()
        rems.append(int(x))
        mods.append(int(ord5))
        M = 1
        for m in mods:
            M = lcm(M, m)
        if M > 2**64:
            CP = int(crt(rems, mods)) % int(M)
            return CP

def main():
    print("Solving ...")
    c = Conn(['sage', 'asemoon.sage'])
    print("[*] recovering CP ...")
    CP = recover_CP(c)
    print(f"[+] CP = {CP}")

    CT = make_CT(CP)
    U = build_U(CT)
    B8 = build_B8(CT)
    I = identity_matrix(GF(2), 64)

    # Synchronize to the start of a 10-second block
    while int(time.time()) % 10 > 5:
        time.sleep(0.3)

    t_pub = int(time.time()) // 10 * 10
    pub1, _, _ = c.query_P()

    # pub1 = recheck(b"CCTF", F) where F = recheck(skey ^ t_pub, 0)
    C4 = recheck(b"CCTF", 0, CT)
    A4 = U ** 4
    F_vec = A4.solve_right(int_to_vec(pub1 ^ C4))
    F = vec_to_int(F_vec)

    # Recover msg_pub = skey ^ t_pub from F (assume 8-byte message)
    msg_pub_vec = B8.solve_right(F_vec)
    msg_pub = vec_to_int(msg_pub_vec)
    print(f"[+] recovered skey ^ t = {hex(msg_pub)}")

    # For login we need skey ^ t_login.
    # If the time block changed, adjust by XOR with (t_pub ^ t_login).
    t_login = int(time.time()) // 10 * 10
    if t_login != t_pub:
        msg_login = msg_pub ^ (t_pub ^ t_login)
    else:
        msg_login = msg_pub

    # Build the linear equation: (I + U^L) v = c
    msg_bytes = long_to_bytes(msg_login)
    L = len(msg_bytes)
    c_vec = int_to_vec(recheck(msg_bytes, 0, CT))
    A = U ** L

    v_vec = (I + A).solve_right(c_vec)
    token = vec_to_int(v_vec)

    print(f"[+] token = {hex(token)}")
    out = c.login(token)
    print(out.decode(errors='ignore'))

if __name__ == "__main__":
    main()
    