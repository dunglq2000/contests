from sage.all import *
from pwn import remote, process, context

context.log_level = 'Debug'

p = 2**255 - 19
k = 15

Fp = GF(p)
RFp = Fp['SECRET, a, b']
SECRET, a, b = RFp.gens()

# SECRET = random.randrange(0, p)

def lcg(x, a, b, p):
    return (a * x + b) % p

# a = random.randrange(0, p)
# b = random.randrange(0, p)

poly = [SECRET]
while len(poly) != k: poly.append(lcg(poly[-1], a, b, p))

def evaluate_poly(f, x):
    return sum(c * pow(x, i, p) for i, c in enumerate(f)) % p

print(poly)

# pr = remote('ssss.challs.sekai.team', 1337)
# pr.readline()

pr = process(['python', 'server.py'])

pr.readline()

c = []

for _ in range(k - 1):
    x = random.randrange(1, p-1)
    pr.writeline(str(x).encode())
    y = int(pr.readline().decode())
    c.append(evaluate_poly(poly, x) - y)

I = ideal(*c, p)
G = I.groebner_basis()
s = -G[0].constant_coefficient()

pr.sendlineafter("secret? ", str(s).encode())
pr.recvline()
