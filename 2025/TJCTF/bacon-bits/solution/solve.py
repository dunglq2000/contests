baconian = {
'a': '00000',	'b': '00001',
'c': '00010',	'd': '00011',
'e': '00100',	'f': '00101',
'g': '00110',	'h': '00111',
'i': '01000',    'j': '01000',
'k': '01001',    'l': '01010',
'm': '01011',    'n': '01100',
'o': '01101',    'p': '01110',
'q': '01111',    'r': '10000',
's': '10001',    't': '10010',
'u': '10011',    'v': '10011',
'w': '10100',	'x': '10101',
'y': '10110',	'z': '10111'
}

from itertools import product

baconian_inv = [(baconian[i], i) for i in baconian]
baconian_inv = dict(baconian_inv)

with open("out.txt") as f:
    ct = f.read()
    ct = ''.join([chr(ord(i) + 13) for i in ct])
    ct = ''.join(["1" if i.isupper() else "0" for i in ct])
    assert len(ct) % 5 == 0
    pt = ''.join([baconian_inv[ct[i:i+5]] for i in range(0, len(ct), 5)])
    flag = "tjctf{" + pt[5:] + "}"
    br = list(b"ij")
    flag = list(flag.encode())
    for i0, i1, i2, i3 in product(range(2), repeat=4):
        flag[7] = br[i0]
        flag[12] = br[i1]
        flag[18] = br[i2]
        flag[25] = br[i3]

        print(bytes(flag))
    
