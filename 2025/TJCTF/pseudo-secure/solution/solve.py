from extend_mt19937_predictor import ExtendMT19937Predictor
from pwn import remote, process, context
from base64 import b64decode, b64encode

tmp = b'Your sign-in key is: '
tmp_ = b"Your message: "
context.log_level = 'Debug'
# pr = process(["python", "server.py"])
pr = remote("tjc.tf", "31400")

predictor = ExtendMT19937Predictor()
pr.sendlineafter(b'Quit\n', b'2')
username = b"A" * (624 * 32 // 8)
username_bits = list(map(int, ''.join(bin(char)[2:].zfill(8) for char in username)))
pr.sendlineafter(b"Select username:  ", username)
pr.recvline()
data = pr.recvline().strip()[len(tmp):]
s = ((int.from_bytes(b64decode(data), 'big') ^ 0x5a) >> 3)
s = s.to_bytes(len(username), 'big')
s_bits = list(map(int, ''.join(bin(char)[2:].zfill(8) for char in s)))
key = ''.join(map(str, [x^y for x, y in zip(username_bits, s_bits)]))
assert len(key) % 32 == 0

predictor.setrandbits(int(key, 2), 624 * 32)

# this part is for testing correctness of predictor, is used only in local
# pr.sendlineafter(b'Quit\n', b'2')
# username = b"B" * (624 * 32 // 8)
# username_bits = list(map(int, ''.join(bin(char)[2:].zfill(8) for char in username)))
# pr.sendlineafter(b"Select username:  ", username)
# pr.recvline()
# data = pr.recvline().strip()[len(tmp):]
# s = ((int.from_bytes(b64decode(data), 'big') ^ 0x5a) >> 3)
# s = s.to_bytes(len(username), 'big')
# s_bits = list(map(int, ''.join(bin(char)[2:].zfill(8) for char in s)))
# key = ''.join(map(str, [x^y for x, y in zip(username_bits, s_bits)]))

# assert predictor.predict_getrandbits(624 * 32) == int(key, 2)

_ = [predictor.backtrack_getrandbits(624 * 32)]

flag = []

for idx in [3, 2, 1]:
    backtrack = predictor.backtrack_getrandbits(64)
    backtrack = list(map(int, bin(backtrack)[2:].zfill(64)))

    users = f"Admin00{idx}".encode()
    users_bits = list(map(int, ''.join([bin(char)[2:].zfill(8) for char in users])))
    keys = ''.join(map(str, [x^y for x, y in zip(backtrack, users_bits)]))
    assert len(keys) == len(backtrack)

    xor_result = int(keys, 2)
    shifted = ((xor_result << 3) & (1 << (64 + 3)) - 1) ^ 0x5a
    byte_data = shifted.to_bytes((shifted.bit_length() + 7) // 8, 'big')
    key = b64encode(byte_data)

    pr.sendlineafter(b'Quit\n', b'1')
    pr.sendlineafter(b"Enter your username:  ", users)
    pr.sendlineafter(b"Enter your sign-in key: ", key)

    pr.sendlineafter(b"Logout\n", b"1")
    flag.append(pr.recvline().strip()[len(tmp_):])
    pr.sendlineafter(b"Logout\n", b"l")

print(b''.join(flag[::-1]))
pr.close()

# tjctf{1_gu3ss_h1nds1ght_15_20/20}