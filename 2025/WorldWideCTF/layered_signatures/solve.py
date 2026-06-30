from pwn import process, context, remote
from Crypto.Util.number import long_to_bytes, bytes_to_long
from hashlib import sha256

def nxt(m):
    return bytes_to_long(sha256(long_to_bytes(m)).digest())

def weird_schnorr_sign(m, x):
    k = 1
    r = pow(g, k, p)
    e = bytes_to_long(sha256(long_to_bytes(r) + long_to_bytes(m)).digest())
    s = (k + x * e) % ((p - 1) // 2)
    return [s, e]

context.log_level = 'Debug'

# pr = process(["python", "chall.py"])
pr = remote("chal.wwctf.com", "8001")

nbits = 1024
p = 157177458027947738464608587718505170872557537311336022386936190418737852141444802600222526305430833558655717806361264485789209743716195302937247478034883845835496282499162731072456548430299962306072692670825782721923481661135742935447793446928303177027490662275563294516442565718398572361235897805000082380599
g = 25
q = int(pr.recvline().strip()[2:])
gs = int(pr.recvline().strip()[3:])

msg = b"this is just a test so that you trust the algo"

sm = eval(pr.recvline().strip()[3:])
leak = int(pr.recvline().strip()[5:])
s, e, a, t = sm[0], sm[1], sm[2], sm[3:]
assert len(t) == 4
tmp = (a * gs * pow(g, a, p)) % p
s = a + tmp * (p - 1)
assert s % p == 0
s = p - 1 - (s // p)
assert pow(g, s, p) == gs

cc_ = [nxt(leak)]
for _ in range(3):
    cc_ += [nxt(cc_[-1])]

sta_ = (leak - sum(pow(g, b, p) * c % p for b, c in zip(t, cc_))) % q
r_ = 1
a_ = (p - 1 - s) * p - (q * r_ + sta_) * (p - 1)
assert (a_ * gs * pow(g, a_, p)) % p == q * r_ + sta_

payload = str(weird_schnorr_sign(a_, s) + [a_] + t)[1:-1].replace(' ', '')
pr.recvline()
pr.sendline(payload.encode())

print(pr.recvline())


pr.close()

# b'wwf{d1d_y0u_kn0w_tH3_pow3r_0f_W@gner?4b84gb5v783439u392093hr2b293rv3f283ru2bf3}\n'