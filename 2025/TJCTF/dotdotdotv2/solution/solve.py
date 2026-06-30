from sage.all import *
import itertools

n = 64

filler = "In cybersecurity, a CTF (Capture The Flag) challenge is a competitive, gamified event where participants, either individually or in teams, are tasked with finding and exploiting vulnerabilities in systems to capture hidden information known as flags. These flags are typically used to score points. CTFs test skills in areas like cryptography, web security, reverse engineering, and forensics, offering an exciting way to learn, practice, and showcase cybersecurity expertise.  This flag is for you: "

flag = "tjctf{"
flag = filler + flag

with open("encoded.txt") as f:
    lines = [line.strip() for line in f.readlines()]
    
    ff = flag[:504]
    ff = "".join(["".join(bin(ord(i))[2:].zfill(8)) for i in ff])
    ff = matrix(GF(2), [list(map(int,list(ff[i:i+n]))) for i in range(0, len(ff), n)])
    
    res = list(list(map(int, line.split())) for line in lines)
    res = matrix(GF(2), [list(map(int, line.split(' '))) for line in lines])

    sol = ff.solve_right(res[:63, :])

    a = [0] * 64
    a[58] = 1       # flip bit at the index 58

    rr = res * sol.pseudoinverse()
    rr = rr + matrix(GF(2), [a for _ in range(66)])
    result = b''
    for r in rr:
        row = ''.join(map(str, r))
        result += bytes([int(row[i:i+8], 2) for i in range(0, 64, 8)])
    print(result)

    # tjctf{us3fu289312953}

    