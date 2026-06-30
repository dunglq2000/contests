from sage.all import *

PR = PolynomialRing(QQ, 'x')
x = PR.gen()

poly = loads(open("output.raw", "rb").read())
for L in range(20, 100):
    flag = [0] * L
    for n in range(L):
        flag[(63 * n - 40) % L] = poly(-(1 + (19 * n - 14) % L))
    print(bytes(flag))

# b'CCTF{7h3_!nTeRn4t10naL_Cr!Min41_pOlIc3_0r9An!Zati0n!}'