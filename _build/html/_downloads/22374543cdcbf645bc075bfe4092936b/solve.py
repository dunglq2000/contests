with open("out.txt") as f:
    ct = f.read()

ctx = bytes.fromhex(ct)

#n = 32
n = 79
l = len(ctx) // n

bb = [0] * l

for i in range(l):
    bb[(i * n) % l] = ctx[i * n]

for key in range(256):
    flag = [key ^ b for b in bb]
    print(key, bytes(flag[:24]))

flag = bytes(165 ^ b for b in bb)[0x1b2:0x1f8]
print(flag)

# b'amateursCTF{M4yb3_H4v3_b3tt3r_0tP_3ncrYpt10n_n3X7_t1m3_l0L!!_a585b81b}'