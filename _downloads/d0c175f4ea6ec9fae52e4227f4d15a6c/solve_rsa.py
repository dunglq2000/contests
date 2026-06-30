from sage.all import *


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


n = """45f9a1a7b27926c4310c4aec745f069487cb4ae65c717d43014012ba3520008a
5fae47d12490c9349b49a50737ae8225271ed1f64d2c8bffe7f4c5022e188316
ab96eada430e47af5a4ab879a211d3077f7f1dc230e15f7a6f531eb8a2c97a5e
c0f070ea1e2425e27db89eb70e7c03387ecf51736aef8ef0b0c389781728bd3"""

n = int(n.replace("\n", ""), 16)

e = 5

c1 = """525a04be10f92bc34e0f3fb9990a324a4519b946182e1530b827160b379d073f
8556df0b7c778ebde881eb6b55e33ef8e5ec9d9e8fed7661f224090dfbf81838
729ceb7bc9fc9109528551ecc28abcb0228e3a40d47f48f15b"""
c2 = """525a04be10f92bc34e0f3fb9990a324a451fd7512f0acce5fda8514c0fd46167
6b0d6b946a3ed1375a7b5981d64ecbda4699a7133886af3163570d9ddf858098
6048393f13b274c2967ae1d4386d8ce41731e343964ce00c00"""

c1 = int(c1.replace("\n", ""), 16)
c2 = int(c2.replace("\n", ""), 16)

PR = PolynomialRing(Zmod(n), 'x')
x = PR.gen()
f = x**e - c1
g = (x+1)**e - c2
res = Integer(-gcd(f, g).monic()[0])
print(res.to_bytes(res.nbits() // 8 + 1, 'big'))