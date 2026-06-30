from sage.all import *
from pwn import remote, process, context

# def gcd(a, b):
#     while b:
#         a, b = b, a % b
#     return a

context.log_level = 'Debug'

p = 2**255 - 19
k = 15

def lcg(x, a, b, p):
    return (a * x + b) % p

def evaluate_poly(f, x):
    return sum(c * pow(x, i, p) for i, c in enumerate(f)) % p

pr = process(['python', 'server.py'])

pr.readline()

c = []

for i in range((k - 1) // 2):
    x = (i + 1) % p
    pr.writeline(str(x).encode())
    y1 = int(pr.readline().decode())
    
    pr.writeline(str(p - x).encode())
    y2 = int(pr.readline().decode())

    y = ((y1 - y2) * pow(2 * x, -1, p)) % p
    c.append((pow(x, 2, p), y))

PR = PolynomialRing(GF(p), 'z')
z = PR.gen()
f = PR.lagrange_polynomial(c)

s = list(map(Integer, f.coefficients(sparse=False)))

t = []
for i in range(len(s) - 1):
    t.append(s[i+1] - s[i])

u = []
for i in range(len(t) - 2):
    u.append(abs(Integer((t[i + 2] * t[i] - t[i+1]**2))))

q = gcd(u)

if is_prime(q) and q.bit_length() == 256:
    A = t[1] * pow(t[0], -1, q) % q
    B = (s[1] - A * s[0]) % q
    a = Mod(A, q).sqrt()
    print(f"{a = }")
    b = B * pow(a + 1, -1 ,q)
    print(f"{b = }")
    secret = (s[0] - b) * pow(a, -1, q) % q

    pr.sendlineafter(b"secret? ", str(secret).encode())
    pr.recvline()

pr.close()
