# https://github.com/dunglq2000/lfsr-berlekamp-massey.git
from berlekamp_massey import *
from lfsr import *

FEEDBACK = [1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
state = [0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0]

with open("ciphertext.txt") as f:
    data = f.readlines()
    ct = "".join(d.strip() for d in data)
    pt = "".join([f"{p:08b}" for p in b'wctf{'])
    assert len(pt) % 8 == 0 and len(ct) % 8 == 0
    # find keystream
    # keystream = [int(p) ^ int(c) for p, c in zip(pt, ct)]
    # lfsr = BerlekampMassey(keystream)
    for i in range(16, len(ct)):
        new_s = sum(f * s for f, s in zip(FEEDBACK, state[i-16:i])) % 2
        state.append(new_s)
    pt = [int(c) ^ s for c, s in zip(ct, state)]
    pt = ["".join(map(str, pt[i:i+8])) for i in range(0, len(pt), 8)]
    pt = [int(p, 2) for p in pt]
    print(bytes(pt))

# wctf{cr4ck1nG_w34k_3ncrYpt10N_W17h_tH3_p0w3r_0f_M4TH_843953}