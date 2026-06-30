from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
import random
from itertools import product

def gen():
    myrandom = random.Random(42)
    k1 = myrandom.randbytes(8)
    choices = list(myrandom.randbytes(6))
    k2 = b''
    for _ in range(8):
        k2 += bytes([choices[random.randint(0, 3)]])
    return k1, k2

def enc(data, k1, k2,  k3, k4):
    key1 = k1+k2
    cipher = AES.new(key1, mode=AES.MODE_ECB)
    ct1 = cipher.encrypt(pad(data, 16))
    key2 = k4+k3
    cipher = AES.new(key2, mode=AES.MODE_ECB)
    ct2 = cipher.encrypt(ct1)
    return ct2

k1, k2 = gen()
k3, k4 = gen()

ct_test = bytes.fromhex("7125383e330c692c75e0ee0886ec7779")
ct_flag = bytes.fromhex("9ecba853742db726fb39e748a0c5cfd06b682c8f15be13bc8ba2b2304897eca2")

myrandom = random.Random(42)
k1 = myrandom.randbytes(8)
choices = list(myrandom.randbytes(6))
k3 = k1

# get from solve.cpp
key1 = bytes.fromhex("9d79b1a37f31801c1a1a1a1a67671a06")
key2 = bytes.fromhex("1a671a1a06d11a1a9d79b1a37f31801c")

cipher = AES.new(key2, AES.MODE_ECB)
ct1 = cipher.decrypt(ct_flag)

cipher = AES.new(key1, AES.MODE_ECB)
flag = cipher.decrypt(ct1)

print(unpad(flag, AES.block_size))