# solve.py
import random
from skipjack import *

with open("ct.txt", encoding="cp1251") as f:
    data = f.read()
    dd = [ord(d.encode("cp1251")) for d in data]

    Kroot = list(random.randbytes(10))
    IV = [0x43,0x72,0x79,0x70,0x74,0x46,0x6f, 0x78]
    Kprev = [0] * 32
    flag = ""
    # Generate K_i with random K_{root}
    for _ in range(len(data) * 2):
        # Calculate K_i from K_{i-1} with CFB
        Kprev = encrypt_cfb(Kroot, IV, Kprev)

        F = bytes(Kprev).hex()
        for i in range(0, len(F), 16):
            if F[i:i+16] == "0" *  16: # Check K_i[j] == 0 for j = 0, 1, 2, 3
                flag += "0"
            else:
                flag += "1"

    gamma = [int(flag[i:i+8], 2) for i in range(0, len(flag), 8)]

    pt = [g ^ d for g, d in zip(gamma, dd)]
    print(bytes(pt))
