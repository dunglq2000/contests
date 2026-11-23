#!/usr/bin/env python3
"""
Solve for "AliceSigSlip" (Ed25519 signature CTF challenge).

--------------------------------------------------------------------
VULNERABILITY
--------------------------------------------------------------------
pycryptodome's eddsa.verify() uses the *cofactored* verification
equation for Ed25519:

    8*s*G  ==  8*R + 8*k*Q        where k = SHA512(R || Q || msg) mod L

alice_check() verifies every row INDEPENDENTLY, each with whatever
public key is stored in THAT row - the five rows don't have to share
the same key.

If we pick Q to be a point of small order dividing 8 (a "torsion"
point), then 8*k*Q = O (identity) for *every* k, which means the
message and the hash no longer matter at all - the equation reduces
to the trivial check  8*s*G == 8*R.

The only guard in the challenge is:
    public_key.pointQ.x * public_key.pointQ.y == 0  -> reject

which only blocks the degenerate torsion points that have a zero
coordinate (identity, the order-2 point, and the two order-4 points).
There are still 4 order-8 torsion points with *both* coordinates
non-zero - those sail right through.

Per-row plan (erase() wipes the first i fields of row i):
  row0 - untouched: gives us Alice's REAL public key "A" directly.
  row1 - only pubkey erased, (r,s,msg) still genuine -> just restore A.
  row2 - pubkey,r erased; s,msg genuine -> set pubkey = T (torsion),
         set r = encode(s*G)   (so 8sG == 8R trivially, independent of k)
  row3 - pubkey,r,s erased; msg genuine -> set pubkey = T, r = O (identity),
         s = 0   (0 == 0 + 8k*T = O, for ANY k/message)
  row4 - everything erased -> same as row3, msg can be anything non-empty.
--------------------------------------------------------------------
"""
import sys

# ---------------- pure-python Edwards25519 arithmetic ----------------
p = 2**255 - 19
d = (-121665 * pow(121666, p - 2, p)) % p
L = 2**252 + 27742317777372353535851937790883648493


def inv(x):
    return pow(x, p - 2, p)


def point_add(P, Q):
    x1, y1 = P
    x2, y2 = Q
    dn_x = (1 + d * x1 * x2 * y1 * y2) % p
    dn_y = (1 - d * x1 * x2 * y1 * y2) % p
    x3 = ((x1 * y2 + x2 * y1) * inv(dn_x)) % p
    y3 = ((y1 * y2 + x1 * x2) * inv(dn_y)) % p
    return (x3, y3)


def point_mul(P, n):
    R = (0, 1)
    Q = P
    while n > 0:
        if n & 1:
            R = point_add(R, Q)
        Q = point_add(Q, Q)
        n >>= 1
    return R


def xrecover(y, sign):
    xx = ((y * y - 1) * inv(d * y * y + 1)) % p
    x = pow(xx, (p + 3) // 8, p)
    if (x * x - xx) % p != 0:
        I = pow(2, (p - 1) // 4, p)
        x = (x * I) % p
    if x % 2 != sign:
        x = p - x
    return x


def encode_point(P):
    x, y = P
    y_enc = y | ((x & 1) << 255)
    return y_enc.to_bytes(32, "little")


By = (4 * inv(5)) % p
Bx = xrecover(By, 0)
G = (Bx, By)

# A fixed order-8 torsion point with BOTH coordinates non-zero
# (passes the pointQ.x*pointQ.y == 0 check, but 8*T == identity,
#  so it nukes the hash term k*8*Q for ANY message/hash).
T_HEX = "26e8958fc2b227b045c3f489f2ef98f0d5dfac05d3c63339b13802886d53fc85"
IDENTITY_HEX = "01" + "00" * 31
ZERO32_HEX = "00" * 32


# ---------------------------- I/O helper ------------------------------
def get_io():
    """
    Returns an object with .sendline(str) / .recvline()->bytes .
    Uses pwntools if available (recommended, handles HOST/PORT from
    argv or env automatically); otherwise falls back to a local
    subprocess for testing, or a raw socket if HOST/PORT are given.
    """
    try:
        from pwn import remote, process, args

        host = args.HOST or (sys.argv[1] if len(sys.argv) > 1 else None)
        port = args.PORT or (int(sys.argv[2]) if len(sys.argv) > 2 else None)
        if host and port:
            return remote(host, port)
        return process(["python3", "AliceSigSlip.py"])
    except ImportError:
        import socket

        if len(sys.argv) > 2:
            host, port = sys.argv[1], int(sys.argv[2])
            s = socket.create_connection((host, port))

            class Sock:
                def __init__(self, s):
                    self.s = s
                    self.buf = b""

                def sendline(self, line):
                    self.s.sendall(line.encode() + b"\n")

                def recvline(self):
                    while b"\n" not in self.buf:
                        chunk = self.s.recv(4096)
                        if not chunk:
                            break
                        self.buf += chunk
                    if b"\n" in self.buf:
                        line, self.buf = self.buf.split(b"\n", 1)
                        return line + b"\n"
                    line, self.buf = self.buf, b""
                    return line

            return Sock(s)
        raise SystemExit("usage: solve.py <host> <port>   (or install pwntools)")


def main():
    io = get_io()

    def sendline(s):
        io.sendline(s)

    def recvline():
        l = io.recvline()
        # return l.decode(errors="replace") if isinstance(l, bytes) else l
        return l

    # drain banner / menu up to first prompt
    for _ in range(10):
        l = recvline()
        print(l)
        if b"Options" in l:
            break

    # --- Get data ---
    sendline(b"g")
    rows = {}
    while len(rows) < 5:
        l = recvline()
        print(l, end="")
        s = l.strip()
        # if ":" in s and s.split(":", 1)[0].strip("|").strip().isdigit():
        #     idx_part, rest = s.split(":", 1)
        #     idx = int(idx_part.strip("|").strip())
        #     rows[idx] = [x.strip() for x in rest.strip().split(",")]
        if b":" in s and s.split(b":", 1)[0].strip(b"|").strip().isdigit():
            idx_part, rest = s.split(b":", 1)
            idx = int(idx_part.strip(b"|").strip())
            rows[idx] = [x.strip() for x in rest.strip().split(b",")]
    print("End of while ...")
    # drain rest of menu
    for _ in range(5):
        l = recvline()
        print(l, end="")
        if b"Options" in l:
            break

    pubkey_real = rows[0][0]
    s2_hex = rows[2][2]
    msg1, msg2, msg3 = rows[1][3], rows[2][3], rows[3][3]

    s2_int = int.from_bytes(bytes.fromhex(s2_hex), "little")
    R2_hex = encode_point(point_mul(G, s2_int)).hex()

    updates = [
        (1, pubkey_real, rows[1][1], rows[1][2], msg1),
        (2, T_HEX, R2_hex, s2_hex, msg2),
        (3, T_HEX, IDENTITY_HEX, ZERO32_HEX, msg3),
        (4, T_HEX, IDENTITY_HEX, ZERO32_HEX, "6767"),  # msg = b"gg"
    ]

    for row_inx, pk, r, s, msg in updates:
        sendline("u")
        print(recvline(), end="")  # prompt line
        sendline(f"{row_inx},{pk},{r},{s},{msg}")
        for _ in range(8):
            l = recvline()
            print(l, end="")
            if "Options" in l:
                break

    sendline("a")
    for _ in range(5):
        l = recvline()
        if not l:
            break
        print(l, end="")


if __name__ == "__main__":
    main()