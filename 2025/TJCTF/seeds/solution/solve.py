import time
from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad
from itertools import product

class RandomGenerator:
    def __init__(self, seed = None, modulus = 2 ** 32, multiplier = 157, increment = 1):
        if seed is None: 
            seed = time.asctime()
        if type(seed) is int: 
            self.seed = seed
        if type(seed) is str: 
            self.seed = int.from_bytes(seed.encode(), "big")
        if type(seed) is bytes: 
            self.seed = int.from_bytes(seed, "big")
        # print(seed)
        self.m = modulus
        self.a = multiplier
        self.c = increment

    def randint(self, bits: int):
        self.seed = (self.a * self.seed + self.c) % self.m
        result = self.seed.to_bytes(4, "big")
        while len(result) < bits // 8:
            self.seed = (self.a * self.seed + self.c) % self.m
            result += self.seed.to_bytes(4, "big")
        return int.from_bytes(result, "big") % (2 ** bits)

    def randbytes(self, len: int):
        return self.randint(len * 8).to_bytes(len, "big")

randgen = RandomGenerator()
key = randgen.randbytes(32)

# Get from netcat
ciphertext = b'I<B\x8f7\x1a\x9d\xba\xcb=Dz8\x97\xe9c\xb7\xaf\x15\x01\xf4\xd9\xd9\xc2\x83jm\x1a\xa2\xda\x10\xb5'

for x, y, z in product(range(24), range(60), range(60)):
    s = f"Sat Jun  7 {x:02d}:{y:02d}:{z:02d} 2025"
    randguess = RandomGenerator(seed = s)
    keyguess = randguess.randbytes(32)
    cipher = AES.new(keyguess, AES.MODE_ECB)
    try:
        plaintext = cipher.decrypt(ciphertext)
        print(unpad(plaintext, AES.block_size))
    except:
        continue