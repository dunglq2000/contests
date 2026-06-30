from sage.all import *

def mul(k, t):
    x0, x1 = 0, t
    for bit in bin(k)[2:]:
        if bit == '0':
            x1 = x0 + x1
            x0 = x0 + x0
        else:
            x0 = x0 + x1
            x1 = x1 + x1
    return x0

p = 3059506932006842768669313045979965122802573567548630439761719809964279577239571933
a = 2448848303492708630919982332575904911263442803797664768836842024937962142592572096
Gx = 3
Qx = 1461547606525901279892022258912247705593987307619875233742411837094451720970084133

b2 = (-4*a**3 * pow(27, -1, p)) % p
b = Mod(b2, p).sqrt()
Gy = -Mod(Gx**3 + a * Gx + b, p).sqrt()
Qy = Mod(Qx**3 + a * Qx + b, p).sqrt()

PR = PolynomialRing(GF(p), 'x')
x = PR.gen()
f = x**3 + a*x + b
roots = f.roots()

assert len(roots) == 2 # two roots, so one must be double
if roots[0][1] == 2:
    double_root = roots[0][0]
    single_root = roots[1][0]
else:
    double_root = roots[1][0]
    single_root = roots[0][0]

print("double root:", double_root)
print("single root:", single_root)

# map G and Q to the new "shifted" curve
Gx = (Gx - double_root)
Qx = (Qx - double_root)

# Transform G and Q into numbers g and q, such that q=g^n
t = double_root - single_root
t_sqrt = t.square_root()

def transform(x, y, t_sqrt):
    return (y + t_sqrt * x) / (y - t_sqrt * x)

g = transform(Gx, Gy, t_sqrt)
q = transform(Qx, Qy, t_sqrt)
print("g:", g)
print("q:", q)

# Find the private key n
print("Factors of p-1:", factor(p-1))
print("Calculating discrete log for g and q...")
found_key = discrete_log(q, g)
print("Found private key:", found_key)

from Crypto.Util.number import long_to_bytes
print("The secret is:", long_to_bytes(found_key))

# b'wwf{sup3rs1ngul4r_1s0m0rph15ms!}'
