from secrets import randbits
from math import floor
from hashlib import sha256

class LFSR:
    def __init__(self, key, taps, format):
        self.key = key
        self.taps = taps
        self.state = list(map(int, list(format.format(key))))
    
    def _clock(self):
        ob = self.state[0]
        self.state = self.state[1:] + [sum([self.state[t] for t in self.taps]) % 2]
        return ob

def xnor_gate(a, b):
    if a == 0 and b == 0:
        return 1
    elif a == 0 and b == 1:
        return 0
    elif a == 1 and b == 0:
        return 0
    else:
        return 1

bits = [0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0]
ct = bytes.fromhex("9f7f799ec2fb64e743d8ed06ca6be98e24724c9ca48e21013c8baefe83b5a304af3f7ad6c4cc64fa4380e854e8")

for key1 in range(2**21):
    L1 = LFSR(key1, [2, 4, 5, 1, 7, 9, 8], "{:021b}")
    bits_1 = [xnor_gate(L1._clock(), c) for c in bits]
    key2 = int("".join(map(str, bits_1[:29])), 2)
    L1 = LFSR(key1, [2, 4, 5, 1, 7, 9, 8], "{:021b}")
    L2 = LFSR(key2, [5, 3, 5, 5, 9, 9, 7], "{:029b}")

    guess_bits = [xnor_gate(L1._clock(), L2._clock()) for _ in range(floor(72.7))]
    if any(u != v for u, v in zip(bits, guess_bits)): continue

    keystream = sha256((str(key1) + str(key2)).encode()).digest() * 2
    print(key1, bytes([b1 ^ b2 for b1, b2 in zip(ct, keystream)]))
    # 776071 b'osu{th1s_hr1_i5_th3_m0st_fun_m4p_3v3r_1n_0wc}'
