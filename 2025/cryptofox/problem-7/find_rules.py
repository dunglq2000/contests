# find_rules.py
import random
from skipjack import *

Kroot = list(random.randbytes(10))
IV = [0x43,0x72,0x79,0x70,0x74,0x46,0x6f, 0x78]
Kprev = [0] * 32

for _ in range(16):
    # Encrypt with CFB
    Kprev = encrypt_cfb(Kroot, IV, Kprev)
    # Split K_i into 4 chunks
    s = [bytes(Kprev[i:i+8]).hex() for i in range(0, len(Kprev), 8)]
    # Print K_i as 4 chunks
    print(" ".join(s))
