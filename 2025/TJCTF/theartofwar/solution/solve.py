from sympy.ntheory.modular import crt
import re
import gmpy2

e = 229

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

with open("output.txt") as f:
    lines = f.readlines()[1:]
    lines = [line.strip() for line in lines]

    ns = []
    cs = []
    for i in range(0, len(lines), 2):
        ns.append(int(re.findall(r"\d+", lines[i])[1]))
        cs.append(int(re.findall(r"\d+", lines[i+1])[1]))
    me = crt(ns, cs)
    m = gmpy2.iroot(me[0], e)
    m = int(m[0])
    print(m.to_bytes(m.bit_length() // 8 + 1, 'big'))

    



    