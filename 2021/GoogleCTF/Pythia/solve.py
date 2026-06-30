from pwn import remote, process, context
from sage.all import *
from Crypto.Cipher import AES
from itertools import product
import string
from base64 import b64encode, b64decode
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives.ciphers.aead import AESGCM
from cryptography.hazmat.primitives.kdf.scrypt import Scrypt
from tqdm import tqdm
import os

# context.log_level = 'Debug'

def aes_ecb(key, plaintext):
    return AES.new(key, AES.MODE_ECB).encrypt(plaintext)

def byte_to_pol(block):
    n = int.from_bytes(block, 'big')
    nn = list(map(int, bin(n)[2:].zfill(128)))
    pol = sum(j*x**i for i, j in enumerate(nn))
    return F(pol)

def pol_to_byte(element):
    coeff = element.polynomial().coefficients(sparse=False)
    coeff = coeff + [0] * (128 - len(coeff))
    num = int(''.join(list(map(str, coeff))), 2)
    return int.to_bytes(num, 16, 'big')

def find_poly(keys, nonce, tag):
    points = []
    L = byte_to_pol(b'\x00' * 8 + int.to_bytes(128 * len(keys), 8, 'big'))
    T = byte_to_pol(tag)
    N = nonce + b'\x00' * 3 + b'\x01'

    for key in keys:
        Hi = byte_to_pol(aes_ecb(key, bytes(16)))
        Bi = byte_to_pol(aes_ecb(key, N))
        fHi = ((L * Hi) + Bi + T) * Hi**(-2)
        points.append((Hi, fHi))

    lagrange = R.lagrange_polynomial(points)

    coeff = lagrange.coefficients(sparse=False)[::-1]

    C = b"".join([pol_to_byte(c) for c in coeff])

    return C

F2 = GF(2)['x']
x = F2.gen()
modulus = x**128 + x**7 + x**2 + x + 1
F = GF(2**128, 'x', modulus=modulus)
R = PolynomialRing(F, 'z')
z = R.gen()

NONCE = b'\x00' * 12
TAG = b'\x00' * 16

possible_keys = {}
keys = []
for a, b, c in product(string.ascii_lowercase, repeat=3):
    kdf = Scrypt(salt=b'', length=16, n=2**4, r=8, p=1, backend=default_backend())
    password = bytes(a+b+c, 'UTF-8')
    key = kdf.derive(password)
    possible_keys[key] = password
    keys.append(key)

p = process(["python3", "service.py"])

CACHE = {}
chunk_size = 512
for i in tqdm(range(0, len(keys), chunk_size)):
    test_keys = [key for key in keys[i:i+chunk_size]]
    C = find_poly(test_keys, NONCE, TAG)
    CACHE[i] = C
    aes = AES.new(test_keys[0], AES.MODE_GCM, nonce=NONCE)
    aes.decrypt_and_verify(C, TAG)

def attack(idx):
    p.sendlineafter(b">>> ", b"1")
    p.sendlineafter(b">>> ", str(idx).encode())
    # phase 1
    index = 0
    for cache in CACHE:
        C = CACHE[cache]
        payload = b64encode(NONCE) + b"," + b64encode(C + TAG)
        p.sendlineafter(b">>> ", b"3")
        p.sendlineafter(b">>> ", payload)
        p.recvline()
        if b'success' in p.recvline():
            index = cache
            break
    print(cache)
    # phase 2
    test_keys = [key for key in keys[cache:cache + chunk_size]]
    while len(test_keys) > 1:
        C = find_poly(test_keys[:len(test_keys) // 2], NONCE, TAG)
        payload = b64encode(NONCE) + b"," + b64encode(C + TAG)
        p.sendlineafter(b">>> ", b"3")
        p.sendlineafter(b">>> ", payload)
        p.recvline()
        if b"success" in p.recvline():
            test_keys = test_keys[:len(test_keys) // 2]
        else:
            test_keys = test_keys[len(test_keys) // 2:]
    return test_keys[0]

password = b""

for _ in range(3):
    password += possible_keys[attack(_)]

p.sendlineafter(b">>> ", b"2")
p.sendlineafter(b">>> ", password)
print(p.recvline())
print(p.recvline())
p.close()
