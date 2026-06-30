import os
from sage.all import *

def power(base, a, mod):
    res = 1
    b = base
    while a > 0:
        if a & 1:
            res = (res * b) % mod
        b = (b * b) % mod
        a //= 2
    return res
        

assert pow(12, 5, 1111) == power(12, 5, 1111)

p = 276784813000398431755706235529589161781
q = 302904819256337380397575865141537456903
N = 83839453754784827797201083929300181050320503279359875805303608931874182224243
c = 32104483815246305654072935180480116143927362174667948848821645940823281560338
e = 65537

assert p * q == N
assert c < N

d = pow(e, -1, (p - 1) * (q - 1))
known = b'The flag is maltactf{'

PRx = PolynomialRing(GF(p), 'x')
x = PRx.gen()

a = int.from_bytes(known, 'big')

f_1 = (a * pow(256, 41 + 12 - len(known), p) + x)**e + ((a * pow(256, 41 + 12 - len(known), p) + x) * 256 + ord('.'))**e - c
g_1 = f_1.gcd(pow(x, p - 1, f_1) - 1)

PRy = PolynomialRing(GF(q), 'y')
y = PRy.gen()

f_2 = (a * pow(256, 41 + 12 - len(known), q) + y)**e + ((a * pow(256, 41 + 12 - len(known), q) + y) * 256 + ord('.'))**e - c
g_2 = f_2.gcd(pow(y, q - 1, f_2) - 1)

print(g_1.roots())
print(g_2.roots())

for r_1 in g_1.roots():
    for r_2 in g_2.roots():
        u, v = int(r_1[0]), int(r_2[0])
        flag = int(crt([u, v], [p, q]))
        m = a * 256**(41 + 12 - len(known)) + flag
        print(m.to_bytes(m.bit_length() // 8 + 1, 'big'))
