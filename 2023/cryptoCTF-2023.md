## Crypto CTF 2023

### ASlv1

```python
#!/usr/bin/env python3

from Crypto.Util.number import *
from flag import flag

def base(n, l):
    D = []
    while n > 0:
        n, r = divmod(n, l)
        D.append(r)
    return ''.join(str(d) for d in reversed(D)) or '0'

def asiv_prng(seed):
	l = len(seed)
	_seed = base(bytes_to_long(seed), 3)
	_seed = [int(_) for _ in _seed]
	_l = len(_seed)
	R = [[getRandomRange(0, 3) for _ in range(_l)] for _ in range(_l**2)]
	S = []
	for r in R:
		s = 0
		for _ in range(_l):
			s += (r[_] * _seed[_]) % 3
		# s += getRandomRange(0, 3)
		s %= 3
		S.append(s)
	return R, S

seed = flag.lstrip(b'CCTF{').rstrip(b'}')
R, S = asiv_prng(seed)

f = open('output.txt', 'w')
f.write(f'R = {R}\nS = {S}')
f.close()
```

Flag được biểu diễn ở dạng cơ số :math:`3`, giả sử là số nguyên có dạng

$$f = s_0 + 3 s_1 + 3^2 s_2 + \cdots + 3^{l-1} s_{l-1}$$

thì `_seed` sẽ là vector

$$seed = (s_{l-1}, s_{l-2}, \ldots, s_1, s_0).$$

Sau đó đề sinh ma trận $(r_{ij})$ kích thước $l^2 \times l$ gồm các phần tử ngẫu nhiên trong khoảng $[0, 3]$. Cuối cùng tính vector $S = R \cdot seed$. Giả hệ phương trình tuyến tính ta có được flag.

```python
from sage.all import GF, matrix, vector

MR = matrix(GF(3), R)
MS = vector(GF(3), S)

f = int("".join(map(str, MR.solve_right(MS))), 3)
print(f.to_bytes(f.bit_length() // 8 + 1, 'big'))

# b'CCTF{3Xpl0i7eD_bY_AtT4ck3r!}'
```

### [TODO] ASIv2

```python
#!/usr/bin/env python3

from Crypto.Util.number import *
from flag import flag

def base(n, l):
    D = []
    while n > 0:
        n, r = divmod(n, l)
        D.append(r)
    return ''.join(str(d) for d in reversed(D)) or '0'

def asiv_prng(seed):
	l = len(seed)
	_seed = base(bytes_to_long(seed), 3)
	_l = len(_seed)
	R = [[getRandomRange(0, 3) for _ in range(_l)] for _ in range(_l**2)]
	S = []
	for r in R:
		s = 0
		for _ in range(_l):
			b = ((int(r[_]) + int(_seed[_])) % 3) % 2
			s = s ^ b
		S.append(s)
	
	return R, S

seed = flag.lstrip(b'CCTF{').rstrip(b'}')
R, S = asiv_prng(seed)

f = open('output.txt', 'w')
f.write(f'R = {R}\nS = {S}')
f.close()
```

### [TODO] Barak

```python
#!/usr/bin/env sage

from Crypto.Util.number import *
from flag import flag

def on_barak(P, E):
	c, d, p = E
	x, y = P
	return (x**3 + y**3 + c - d*x*y) % p == 0

def add_barak(P, Q, E):
	if P == (0, 0):
		return Q
	if Q == (0, 0):
		return P
	assert on_barak(P, E) and on_barak(Q, E)
	x1, y1 = P
	x2, y2 = Q
	if P == Q:
		x3 = y1 * (c - x1**3) * inverse(x1**3 - y1**3, p) % p
		y3 = x1 * (y1**3 - c) * inverse(x1**3 - y1**3, p) % p
	else:

		x3 = (y1**2*x2 - y2**2*x1) * inverse(x2*y2 - x1*y1, p) % p
		y3 = (x1**2*y2 - x2**2*y1) * inverse(x2*y2 - x1*y1, p) % p
	return (x3, y3)

def mul_barak(m, P, E):
	if P == (0, 0):
		return P
	R = (0, 0)
	while m != 0:
		if m & 1:
			R = add_barak(R, P, E)
		m = m >> 1
		if m != 0:
			P = add_barak(P, P, E)
	return R

def rand_barak(E):
	c, d, p = E
	while True:
		y = randint(1, p - 1)
		K = Zmod(p)
		P.<x> = PolynomialRing(K) 
		f = x**3 - d*x*y + c + y^3
		R = f.roots()
		try:
			r = R[0][0]
			return (r, y)
		except:
			continue

p = 73997272456239171124655017039956026551127725934222347
d = 68212800478915688445169020404812347140341674954375635
c = 1
E = (c, d, p)

P = rand_barak(E)

FLAG = flag.lstrip(b'CCTF{').rstrip(b'}')
m = bytes_to_long(FLAG) 
assert m < p
Q = mul_barak(m, P, E)
print(f'P = {P}')
print(f'Q = {Q}')
```

### [TODO] Bertrand

```python
#!/usr/bin/env python3

import sys
import math
import functools
from PIL import Image
from random import randint
import string
from secret import flag, key, n

def pad(s, l):
	while len(s) < l:
		s += string.printable[randint(0, 61)]
	return s

def sox(n, d):
	x, y, t = 0, 0, d
	for s in range(n - 1):
		u = 1 & t // 2
		v = 1 & t ^ u
		x, y = spin(2**s, x, y, u, v)
		x += 2**s * u
		y += 2**s * v
		t = t // 4
	return x, y

def spin(n, x, y, u, v):
	if v == 0:
		if u == 1:
			x = n - 1 - x
			y = n - 1 - y
		x, y = y, x
	return x, y

def encrypt(msg, key, n):
	_msg = pad(msg, n ** 2)
	_msg, _key = [ord(_) for _ in _msg], [ord(_) for _ in key]
	img = Image.new('RGBA', (n, n), 'darkblue')
	pix = img.load()

	for _ in range(len(key)):
		w = len(_key)
		h = n**2 // w + 1
		arr = [[_msg[w*x + y] if w*x + y < n**2 else None for x in range(h)] for y in range(w)]
		_conf = sorted([(_key[i], i) for i in range(w)])
		_marshal = [arr[_conf[i][1]] for i in range(w)]
		_msg = functools.reduce(lambda a, r: a + _marshal[r], range(w), [])
		_msg = list(filter(lambda x: x is not None, _msg))
		_msg = [(_msg[_] + _key[_ % w]) % 256 for _ in range(n**2)]

	for d in range(n**2):
		x, y = sox(n, d)
		pix[x,y] = (_msg[d], _msg[d], _msg[d])
	keysum = sum(_key) if w > 0 else 0
	orient = keysum % 4
	img = img.rotate(90*orient)
	return img

assert len(key) == 3
img = encrypt(flag, key, n)
img.save('enc.png')
```

### [TODO] Big

```python
#!/usr/bin/env sage

from Crypto.Util.number import *
from hashlib import sha512
from flag import flag

def genkey(nbit):
	while True:
		p = getPrime(nbit)
		if p % 4 == 3:
			q = int(str(p)[::-1])
			if isPrime(q):
				return p * q, (p, q)

def setup(msg, pkey):
	hid = sha512(msg).digest()
	while True:
		a = bytes_to_long(hid)
		if kronecker(a, pkey) == 1:
			return a
		else:
			hid = sha512(hid).digest()

def encrypt(msg, pkey):
	a, m = setup(msg, pkey), bytes_to_long(msg)
	B, C = bin(m)[2:], []
	for b in B:
		while True:
			t = randint(1, pkey)
			if kronecker(t, pkey) == 2 * int(b) - 1:
				C.append((t - a * inverse(t, pkey)) % pkey)
				break
	return (a, C)


pkey, privkey = genkey(512)
E = encrypt(flag, pkey)

print(f'pkey = {pkey}')
print(f'E = {E}')
```

### [TODO] blobfish

```python
#!/usr/bin/env python3

import os
from hashlib import md5
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from PIL import Image
from PIL import ImageDraw
from flag import flag

key = get_random_bytes(8) * 2
iv = md5(key).digest()

cipher = AES.new(key, AES.MODE_CFB, iv=iv)
enc = cipher.encrypt(flag)

img = Image.new('RGB', (800, 50))
drw = ImageDraw.Draw(img)
drw.text((20, 20), enc.hex(), fill=(255, 0, 0))
img.save("flag.png")

hkey = ''.join('\\x{:02x}'.format(x) for x in key[:10])

os.system(f'/bin/zip -0 flag.zip flag.png -e -P \"$(/bin/echo -en \"{hkey}\")\"')
```

### [TODO] blue_office

```python
#!/usr/bin/enc python3

import binascii
from secret import seed, flag

def gen_seed(s):
	i, j, k = 0, len(s), 0
	while i < j:
		k = k + ord(s[i])
		i += 1
	i = 0
	while i < j:
		if (i % 2) != 0:
			k = k - (ord(s[i]) * (j - i + 1))            
		else:
			k = k + (ord(s[i]) * (j - i + 1))
	
		k = k % 2147483647
		i += 1

	k = (k * j) % 2147483647
	return k

def reseed(s):
	return s * 214013 + 2531011

def encrypt(s, msg):
	assert s <= 2**32
	c, d = 0, s
	enc, l = b'', len(msg)
	while c < l:
		d = reseed(d)
		enc += (msg[c] ^ ((d >> 16) & 0xff)).to_bytes(1, 'big')
		c += 1
	return enc

enc = encrypt(seed, flag)
print(f'enc = {binascii.hexlify(enc)}')
```

### [TODO] Derik

```python
#!/usr/bin/env python3

from Crypto.Util.number import *
from secret import C, e, d, p, q, r, flag

O = [1391526622949983, 2848691279889518, 89200900157319, 31337]

assert isPrime(e) and isPrime(d) and isPrime(p) and isPrime(q) and isPrime(r)
assert C[0] * p - C[1] * q >= 0
assert C[2] * q - C[3] * r >= 0
assert C[4] * r - C[5] * p >= 0
assert (C[0] * p - C[1] * q) ** e + (C[2] * q - C[3] * r) ** e + (C[4] * r - C[5] * p) ** e == d * (C[0] * p - C[1] * q) * (C[2] * q - C[3] * r) * (C[4] * r - C[5] * p)
assert C[6] * e - C[7] * d == O[3]

n = e * d * p * q * r
m = bytes_to_long(flag)
c = pow(m, 65537, n)
print(f'C = {C}')
print(f'c = {c}')
```

### [TODO] DiD

```python
#!/usr/bin/env python3

from random import randint
import sys
from flag import flag

def die(*args):
	pr(*args)
	quit()

def pr(*args):
	s = " ".join(map(str, args))
	sys.stdout.write(s + "\n")
	sys.stdout.flush()

def sc():
	return sys.stdin.buffer.readline()

def did(n, l, K, A):
	A, K = set(A), set(K)
	R = [pow(_, 2, n) + randint(0, 1) for _ in A - K]
	return R

def main():
	border = "+"
	pr(border*72)
	pr(border, ".::   Hi all, she DID it, you should do it too! Are you ready? ::.  ", border)
	pr(border*72)

	_flag = False
	n, l = 127, 20
	N = set(list(range(0, n)))
	K = [randint(0, n-1) for _ in range(l)]
	cnt, STEP = 0, 2 * n // l - 1
	
	while True:
		ans = sc().decode().strip()
		try:
			_A = [int(_) for _  in ans.split(',')]
			if len(_A) <= l and set(_A).issubset(N):
				DID = did(n, l, K, _A)
				pr(border, f'DID = {DID}')
				if set(_A) == set(K):
					_flag = True
			else:
				die(border, 'Exception! Bye!!')
		except:
			die(border, 'Your input is not valid! Bye!!')
		if _flag:
			die(border, f'Congrats! the flag: {flag}')
		if cnt > STEP:
			die(border, f'Too many tries, bye!')
		cnt += 1

if __name__ == '__main__':
	main()
```

### [TODO] Insights

```python
#!/usr/bin/env sage

from Crypto.Util.number import *
from flag import flag

def getRandomNBits(n):
	nb = '1' + ''.join([str(randint(0, 1)) for _ in range(n - 1)])
	return nb

def getLeader(L, n):
	nb = L + getRandomNBits(n)
	return int(nb, 2)

def genPrime(L, nbit):
	l = len(L)
	assert nbit >= l
	while True:
		p = getLeader(L, nbit - l)
		if is_prime(p):
			return p

def genKey(L, nbit):
	p, q = [genPrime(L, nbit) for _ in '__']
	n = p * q
	d = next_prime(pow(n, 0.2919))
	phi = (p - 1) * (q - 1)
	e = inverse(d, phi)
	pubkey, privkey = (n, e), (p, q)
	return pubkey, privkey

def encrypt(msg, pubkey):
	n, e = pubkey
	m = bytes_to_long(msg)
	c = pow(m, e, n)
	return c

nbit = 1024
L = bin(bytes_to_long(b'Practical'))[2:]
pubkey, privkey = genKey(L, nbit)
p, q = privkey
c = encrypt(flag, pubkey)

print('Information:')
print('-' * 85)
print(f'n = {p * q}')
print(f'e = {pubkey[1]}')
print(f'c = {c}')
print(f'p = {bin(p)[2:len(L)]}...[REDACTED]')
print(f'q = {bin(q)[2:len(L)]}...[REDACTED]')
print('-' * 85)
```

### [TODO] keymoted

```python
#!/usr/bin/env sage

from Crypto.Util.number import *
from flag import flag

def gen_koymoted(nbit):
	p = getPrime(nbit)
	a, b = [randint(1, p - 1) for _ in '__']
	Ep = EllipticCurve(GF(p), [a, b])
	tp = p + 1 - Ep.order()
	_s = p ^^ ((2 ** (nbit - 1)) + 2 ** (nbit // 2))
	q = next_prime(2 * _s + 1)
	Eq = EllipticCurve(GF(q), [a, b])
	n = p * q
	tq = q + 1 - Eq.order()
	e = 65537
	while True:
		if gcd(e, (p**2 - tp**2) * (q**2 - tq**2)) == 1:
			break
		else:
			e = next_prime(e)
	pkey, skey = (n, e, a, b), (p, q)
	return pkey, skey

def encrypt(msg, pkey, skey):
	n, e, a, b = pkey
	p, q = skey
	m = bytes_to_long(msg)
	assert m < n
	while True:
		xp = (m**3 + a*m + b) % p
		xq = (m**3 + a*m + b) % q
		if pow(xp, (p-1)//2, p) == pow(xq, (q-1)//2, q) == 1:
			break
		else:
			m += 1
	eq1, eq2 = Mod(xp, p), Mod(xq, q)
	rp, rq = sqrt(eq1), sqrt(eq2)
	_, x, y = xgcd(p, q)
	Z = Zmod(n)
	x = (Z(rp) * Z(q) * Z(y) + Z(rq) * Z(p) * Z(x)) % n
	E = EllipticCurve(Z, [a, b])
	P = E(m, x)
	enc = e * P
	return enc

nbit = 256
pkey, skey = gen_koymoted(nbit)
enc = encrypt(flag, pkey, skey)

print(f'pkey = {pkey}')
print(f'enc = {enc}')
```

### [TODO] Marjan

```python
#!/usr/bin/env sage

import sys
from Crypto.Util.number import *
from hashlib import sha256
from flag import flag


p = 114863632180633827211184132915225798242263961691870412740605315763112513729991
A = -3
B = 105675527217961035404524512435875047840495516468907806313576241823653895562912
E = EllipticCurve(GF(p), [A, B])
G = E.random_point()
_o = E.order()
original_msg = 'I love all cryptographers!!!'

def die(*args):
	pr(*args)
	quit()

def pr(*args):
	s = " ".join(map(str, args))
	sys.stdout.write(s + "\n")
	sys.stdout.flush()

def sc():
	return sys.stdin.buffer.readline()

def keygen(E):
	skey = randint(1, _o)
	pkey = skey * G
	return pkey, skey

def encrypt(msg, pkey):
	e, l = randint(1, _o), len(msg)
	m1, m2 = bytes_to_long(msg[:l // 2]), bytes_to_long(msg[l // 2:])
	assert m1 < p and m2 < p
	e1, e2 = (e * pkey).xy()
	c1, c2 = m1 * e1 % p, m2 * e2 % p
	return (c1, c2, e * G)

def sign(msg, skey):
	_tail = bytes_to_long(sha256(str(skey).encode('utf-8')).digest()) % (1 << 24)
	while True:
		K = [randint(1, 2**255) // (1 << 24) + _tail for _ in '__']
		r, s = int((K[0] * G).xy()[0]), int((K[1] * G).xy()[1])
		if r * s != 0:
			break
	h = bytes_to_long(sha256(msg).digest())
	t = inverse(K[0], _o) * (h * r - s * skey) % _o
	return (r, s, t)

def verify(msg, pkey, _sign):
	r, s, t = [int(_) % _o for _ in _sign]
	h = bytes_to_long(sha256(msg.encode('utf-8')).digest())
	u = int(h * r * inverse(t, _o) % _o)
	v = int(s * inverse(t, _o) % _o)
	# u = h * r * inverse(t, _o) % _o
	# v = s * inverse(t, _o) % _o
	_R = (u * G - v * pkey).xy()[0]
	return _R == r

def main():
	border = "|"
	pr(border*72)
	pr(border, "Hi all, now it's time to solve a probably simple ECC challenge about", border)
	pr(border, "encryption and signing in elliptic curves! Follow the questions and ", border)
	pr(border, "find the secret flag, are you ready!?                               ", border)
	pr(border*72)

	pkey, skey = keygen(E)

	while True:
		pr("| Options: \n|\t[E]ncrypt a message! \n|\t[G]et the flag \n|\t[P]ublic Key \n|\t[S]ign a message \n|\t[V]erify signature \n|\t[Q]uit")
		ans = sc().decode().lower().strip()
		if ans == 'e':
			pr(border, 'Send your message here: ')
			_msg = sc()
			_enc = encrypt(_msg, pkey)
			pr(border, f'enc = {_enc}')
		elif ans == 'g':
			pr(border, 'You should send the valid signature for my given message!')
			pr(border, 'Send the signature of original message here: ')
			_sgn = sc().split(b',')
			try:
				_sgn = [int(_) for _ in _sgn]
				if verify(original_msg, pkey, _sgn):
					die(border, f'Congratz! You got the flag: {flag}')
				else:
					pr(border, 'Your signature is not correct!')
			except:
				import traceback; traceback.print_exc()
				pr(border, 'Try to send valid signature!')
				continue
		elif ans == 's':
			pr(border, 'Send your message to sign: ')
			_msg = sc()
			if len(_msg) >= 10:
				die(border, 'Sorry, I sign only short messages! :/')
			_sgn = sign(_msg, skey)
			pr(border, f'sgn = {_sgn}')
		elif ans == 'v':
			pr(border, 'Send your signature to verify: ')
			_sgn = sc().split(b',')
			try:
				_sgn = [int(_) for _ in _sgn]
				pr(border, 'Send your message: ')
				_msg = sc()
				if verify(_msg, pkey, _sgn):
					pr(border, 'Your message successfully verified :)')
				else:
					pr(border, 'Verification failed :(')
			except:
				pr(border, 'Try to send valid signature!')
				continue
		elif ans == 'p':
			pr(border, f'pkey = {pkey}')
			pr(border, f'G = {G}')
		elif ans == 'q':
			die(border, 'Quitting...')
		else:
			die(border, 'You should select valid choice!')

if __name__ == '__main__':
	main()
```

### [TODO] resuction

```python
#!/usr/bin/env python3

from Crypto.Util.number import *
from flag import flag

from decimal import *

def keygen(nbit, r):
	while True:
		p, q = [getPrime(nbit) for _ in '__']
		d, n = getPrime(64), p * q
		phi = (p - 1) * (q - 1)
		if GCD(d, phi) == 1:
			e = inverse(d, phi)
			N = bin(n)[2:-r]
			E = bin(e)[2:-r]
			PKEY = N + E
			pkey = (n, e)
			return PKEY, pkey

def encrypt(msg, pkey, r):
	m = bytes_to_long(msg)
	n, e = pkey
	c = pow(m, e, n)
	C = bin(c)[2:-r]
	return C

r, nbit = 8, 1024
PKEY, pkey = keygen(nbit, r)
print(f'PKEY = {int(PKEY, 2)}')
FLAG = flag.lstrip(b'CCTF{').rstrip(b'}')
enc = encrypt(FLAG, pkey, r)
print(f'enc = {int(enc, 2)}')
```

### [TODO] risk

```python
#!/usr/bin/env python3

from Crypto.Util.number import *
from secret import m, flag

def genPrime(m, nbit):
	assert m >= 2
	while True:
		a = getRandomNBitInteger(nbit // m)
		r = getRandomNBitInteger(m ** 2 - m + 2)
		p = a ** m + r
		if isPrime(p):
			return (p, r)

def genkey(m, nbit):
	p, r = genPrime(m, nbit // 2)
	q, s = genPrime(m, nbit // 2)
	n = p * q
	e = r * s
	return (e, n)

def encrypt(msg, pkey):
	e, n = pkey
	m = bytes_to_long(msg)
	c = pow(m, e, n)
	return c

pkey = genkey(m, 2048)
enc = encrypt(flag, pkey)

print(f'pkey = {pkey}')
print(f'enc = {enc}')
```

### [TODO] Roldy

```python
#!/usr/bin/env python3

from Crypto.Util.number import *
from pyope.ope import OPE as enc
from pyope.ope import ValueRange
import sys
from secret import key, flag

def die(*args):
	pr(*args)
	quit()

def pr(*args):
	s = " ".join(map(str, args))
	sys.stdout.write(s + "\n")
	sys.stdout.flush()

def sc(): 
	return sys.stdin.buffer.readline()

def encrypt(msg, key, params):
	if len(msg) % 16 != 0:
		msg += (16 - len(msg) % 16) * b'*'
	p, k1, k2 = params
	msg = [msg[_*16:_*16 + 16] for _ in range(len(msg) // 16)]
	m = [bytes_to_long(_) for _ in msg]
	inra = ValueRange(0, 2**128)
	oura = ValueRange(k1 + 1, k2 * p + 1)
	_enc = enc(key, in_range = inra, out_range = oura)
	C = [_enc.encrypt(_) for _ in m]
	return C

def main():
	border = "|"
	pr(border*72)
	pr(border, " Welcome to Roldy combat, we implemented an encryption method to    ", border)
	pr(border, " protect our secret. Please note that there is a flaw in our method ", border)
	pr(border, " Can you examine it and get the flag?                               ", border)
	pr(border*72)

	pr(border, 'Generating parameters, please wait...')
	p, k1, k2 = [getPrime(129)] + [getPrime(64) for _ in '__']
	C = encrypt(flag, key, (p, k1, k2))

	while True:
			pr("| Options: \n|\t[E]ncrypted flag! \n|\t[T]ry encryption \n|\t[Q]uit")
			ans = sc().decode().lower().strip()
			if ans == 'e':
				pr(border, f'encrypt(flag, key, params) = {C}')
			elif ans == 't':
				pr(border, 'Please send your message to encrypt: ')
				msg = sc().rstrip(b'\n')
				if len(msg) > 64:
					pr(border, 'Your message is too long! Sorry!!')
				C = encrypt(msg, key, (p, k1, k2))
				pr(border, f'C = {C}')
			elif ans == 'q':
				die(border, "Quitting ...")
			else:
				die(border, "Bye ...")

if __name__ == '__main__':
	main()
```

### [TODO] shevid

```python
#!/usr/bin/env sage

from Crypto.Util.number import *
from Crypto.Cipher import AES
from hashlib import md5
from flag import flag

def gen_param(B):
	while True:
		a = randint(B >> 1, B)
		b = randint(B >> 2, B >> 1)
		p = 2**a * 3**b - 1
		if is_prime(p):
			return a, b

def gen_dmap(E):
	return E.isogeny(E.lift_x(ZZ(1)), codomain = E)

def gen_tpt(E, a, b):
	P, Q = [((p + 1) // 2**a) * _ for _ in E.gens()]
	R, S = [((p + 1) // 3**b) * _ for _ in E.gens()]
	return P, Q, R, S

def keygen(EC, b, P, Q, R, S):
	skey = randint(1, 3**b)
	T = R + skey * S
	phi = EC.isogeny(T, algorithm = "factored")
	_phi_dom, _phi_P, _phi_Q = phi.codomain(), phi(P), phi(Q)
	return skey, _phi_dom, _phi_P, _phi_Q

a, b = gen_param(190)
p = 2**a * 3**b - 1

F.<x> = GF(p^2, modulus = x**2 + 1)
EC = EllipticCurve(F, [0, 6, 0, 1, 0])
P, Q, R, S = gen_tpt(EC, a, b)

print(f'P = {P.xy()}')
print(f'Q = {Q.xy()}')
print(f'R = {R.xy()}')
print(f'S = {S.xy()}')

skey, _phi_dom, _phi_P, _phi_Q = keygen(EC, b, P, Q, R, S)

print(f'_phi_dom = {_phi_dom}')
print(f'_phi_P   = {_phi_P.xy()}')
print(f'_phi_Q   = {_phi_Q.xy()}')

key = md5(long_to_bytes(skey)).digest()
iv = md5(str(skey).encode()).digest()

cipher = AES.new(key, AES.MODE_CFB, iv=iv)
enc = cipher.encrypt(flag)

print(f'enc = {enc.hex()}')
```

### [TODO] slowsum

```python
#!/usr/bin/env sage

import sys
from itertools import product
from flag import flag

def die(*args):
	pr(*args)
	quit()

def pr(*args):
	s = " ".join(map(str, args))
	sys.stdout.write(s + "\n")
	sys.stdout.flush()

def sc():
	return sys.stdin.buffer.readline()

def slowsum(p, n):
	g = 0
	perms = list(product([0, 1], repeat = n))
	for _prm in perms:
		g += p(_prm)
	return g

def h4sh(p, q):
	coeffs = p.coefficients()
	return pow(sum(coeffs), (q - 1) // 2 - sum(coeffs), q) 

def main():
	border = "|"
	pr(border*72)
	pr(border, "Hi all, I have created a basic and rudimentary version of a sumcheck", border)
	pr(border, "protocol. Your task is to generate a false statement and persuade   ", border)
	pr(border, "verifier of its validity.                                           ", border)
	pr(border*72)
	
	q = 113
	F = GF(q)

	while True:
		pr("| Options: \n|\t[C]laim the statement \n|\t[D]etermine parameters and polynomial \n|\t[Q]uit")
		ans = sc().decode().lower().strip()
		if ans == 'd':
			pr(border, f'Please first send the number of variable and the degree of your desired polynomial:')
			_ans = sc()
			try:
				_n, _d = [int(_) for _ in _ans.split(b',')]
				if (_n * _d) // q < 0.1 and _n >= 5 and _d >= 3:
					R = PolynomialRing(F, _n, 'x')
					x = R.gens()
				else:
					raise Exception()
			except:
				die(border, 'The parameters are not consistent! Try again!!')
			pr(border, f'Now, please send the {_n}-variable polynomial as p: ')
			_p = sc().strip().decode()
			try:
				_p = R(_p)
				p = _p
				_deg = _p.degree(std_grading=True)
				if _deg != _d:
					raise Exception()
			except:
				die(border, 'The polynomial is not valid or does not hold true in the given situations!')
			g = slowsum(_p, _n)
		elif ans == 'c':
			pr(border, 'Please send the g: ')
			_g = sc()
			try:
				_g = int(_g)
				if _g == g:
					die(border, 'Kidding me?! Bye :P')
			except:
				die(border, 'Some exception occurred! Bye!!')
			_P, _H = [], []
			for i in range(_n):
				pr(border, f'Please send the (p_{i}, h4sh(p_{i}, q)): ')
				pr(border, f'Note that the variable of p_{i} should be x. ')
				_ph = sc().strip()
				try:
					_p, _h = [_.decode() for _  in _ph.split(b',')]
					_R = PolynomialRing(F, 'x')
					_p, _h = _R(_p), F(_h)
					if _p.degree() > _d:
						raise Exception()
					_P.append(_p)
					_H.append(_h)
				except:
					die(border, 'Some exception occurred! Bye!!')
			j = 0
			for i in range(_n):
				if i == 0:
					if _P[i](0) + _P[i](1) != _g or h4sh(_P[i], q) != _H[i]:
						break
				else:
					if _P[i](0) + _P[i](1) != _P[i-1](_H[i-1]) or h4sh(_P[i], q) != _H[i]:
						break
				j += 1
			if j < _n or p(_H) != _P[_n-1](_H[_n-1]):
				die(border, 'Oops, verifier believes that the polynomial is not valid! Bye!!')
			die(border, f'Congrats, here the flag: {flag}')
		elif ans == 'q':
			die(border, 'Quitting...')
		else:
			die(border, 'You should select valid choice!')

if __name__ == '__main__':
	main()
```

### [TODO] suction

```python
#!/usr/bin/env python3

from Crypto.Util.number import *
from flag import flag

def keygen(nbit, r):
	while True:
		p, q = [getPrime(nbit) for _ in '__']
		e, n = getPrime(16), p * q
		phi = (p - 1) * (q - 1)
		if GCD(e, phi) == 1:
			N = bin(n)[2:-r]
			E = bin(e)[2:-r]
			PKEY = N + E
			pkey = (n, e)
			return PKEY, pkey

def encrypt(msg, pkey, r):
	m = bytes_to_long(msg)
	n, e = pkey
	c = pow(m, e, n)
	C = bin(c)[2:-r]
	return C

r, nbit = 8, 128
PKEY, pkey = keygen(nbit, r)
print(f'PKEY = {int(PKEY, 2)}')
FLAG = flag.lstrip(b'CCTF{').rstrip(b'}')
enc = encrypt(FLAG, pkey, r)
print(f'enc = {int(enc, 2)}')
```

### trex

```python
#!/usr/bin/env python3

import random
import sys
from flag import flag

def die(*args):
	pr(*args)
	quit()

def pr(*args):
	s = " ".join(map(str, args))
	sys.stdout.write(s + "\n")
	sys.stdout.flush()

def sc():
	return sys.stdin.buffer.readline()

def check_inputs(a, b, c):
	if not all(isinstance(x, int) for x in [a, b, c]):
		return False
	if a == 0 or b == 0 or c == 0:
		return False
	if a == b or b == c or a == c:
		return False
	return True

def check_solution(a, x, y, z):
	return (x*x + y*y - x*y - a*(z**3)) == 0

def main():
	border = "|"
	pr(border*72)
	pr(border, ".::   Hi all, she DID it, you should do it too! Are you ready? ::.  ", border)
	pr(border, "Welcome to the Ternary World! You need to pass each level until 20  ", border)
	pr(border, "to get the flag. Pay attention that your solutions should be nonzero", border)
	pr(border, "distinct integers. Let's start!                                     ", border)
	pr(border*72)

	level, step = 0, 19
	while level <= step:
		a = random.randint(2**(level * 12), 2**(level*12 + 12))
		equation = f'x^2 + y^2 - xy = {a}*z^3'
		pr(f"Level {level + 1}: {equation}")
		inputs = input().strip().split(",")
		try:
			x, y, z = map(int, inputs)
		except:
			die(border, "Invalid input, Bye!!")
		if check_inputs(x, y, z):
			if check_solution(a, x, y, z):
				pr(border, "Correct! Try the next level :)")
				level += 1
			else:
				pr(border, "You didn't provide the correct solution.")
				die(border, "Better luck next time!")			
		else:
			pr(border, "Your solutions should be non-zero distinct integers")
			die(border, "Quiting...")
		if level == step:
			pr(border, "Congratulations! You've successfully solved all the equations!")
			die(border, f"flag: {flag}")

if __name__ == '__main__':
	main()
```

Chúng ta có :math:`19` vòng, mỗi vòng thứ :math:`i` sinh một số ngẫu nhiên $a \in [2^{12 i}; 2^{12 i + 12}]$ và chúng ta phải gửi các số $x, y, z$ thỏa mãn phương trình

$$x^2 + y^2 - xy = a \cdot z^3$$

lên server. Các số $x, y, z$ không được đôi một bằng nhau hoặc không được bằng :math:`0`.

Ở đây, mình chọn $x = 19a^2$, $y = a^2$ và $z = 7a$ thì mình có

$$x^2 + y^2 - xy = 19^2 a^4 + a^4 - 19a^4 = 343 a^4 = 7^3 a^4 = a \cdot (7a)^3.$$

Lời giải của team Black Bauhinia ở [đây](https://b6a.black/posts/2023-08-28-cryptoctf/#blobfish-90-points-51-solves) dùng $x = 24a^2$, $y = -24a^2$ và $z = 12a$. Team bạn còn tổng quát hóa lên $x = 3k^3a^2$, $y = -3k^3 a^2$ và $z = 3k^2 a$ với :math:`k` bất kì khác :math:`0` vẫn cho lời giải đúng. Tuy nhiên lời giải của mình không có hệ số :math:`3` :v :v :v

Mấu chốt ở đây là chúng ta thấy bên trái là hàm bậc hai theo :math:`x` và :math:`y`, còn vế phải là hàm bậc ba theo :math:`z`. Như vậy nếu $x = u a^2$ và $y = v a^2$ với :math:`u`, :math:`v` là hệ số thì vế trái là hàm bậc bốn theo :math:`z` nên vế phải chỉ cần $z = w a$ là xong. Tìm :math:`u`, :math:`v` và :math:`w` chỉ cần bruteforce một lúc là ra.

```python
# solve.py

from pwn import remote, context

context.log_level = 'Debug'

r = remote('03.cr.yp.toc.tf', 31317)

def get_a(s):
    data = s.strip().decode().split(" ")[-1]
    data = int(data.split("*")[0])
    print(data)
    return data

for _ in range(5):
    r.recvline()

for _ in range(20):
    a = get_a(r.recvline())
    r.sendline(f"{19*a*a},{a*a},{7*a}".encode())
    r.recvline()

r.recvline()

r.close()

#[DEBUG] Received 0x86 bytes:
#    b'| Correct! Try the next level :)\n'
#    b"| Congratulations! You've successfully solved all the equations!\n"
#    b'| flag: CCTF{T3rn3ry_Tr3x_3Qu4t!0n}\n'
```

### [TODO] vinefruit

```python
#!/usr/bin/env python3

import sys
import random
import binascii
from flag import flag

def die(*args):
	pr(*args)
	quit()

def pr(*args):
	s = " ".join(map(str, args))
	sys.stdout.write(s + "\n")
	sys.stdout.flush()

def sc():
	return sys.stdin.buffer.readline()

def vinefruit(msg, mod, flag = 0):
	P = [16777619, 1099511628211, 309485009821345068724781371]
	O = [2166136261, 14695981039346656037, 144066263297769815596495629667062367629]
	assert mod in [0, 1, 2]
	p, o, m = P[mod], O[mod], 2 ** (2 << (4 + mod))
	vine = o
	for b in msg:
		if flag == 1:
			vine = (vine + b) % (2 ** 128)
		else:
			vine = vine ^ b
		vine = (vine * p) % m
	return vine

def main():
	border = "|"
	pr(border*72)
	pr(border, " Hi all, I have designed a gorgeous cryptography hash function in   ", border)
	pr(border, " order to secure the world! Your mission is to find collision for   ", border)
	pr(border, " this function with specific conditions.                            ", border)
	pr(border*72)
	
	step = 19

	while True:
		pr("| Options: \n|\t[S]ubmit collision \n|\t[Q]uit")
		ans = sc().decode().lower().strip()
		if ans == 's':
			S = []
			for level in range(step):
				mod = random.randint(0, 2)
				pr(border, f'Submit two different string such that vinefruit(m1, {mod}, 1) = vinefruit(m2, {mod}, 1)')
				pr(border, f'You are at level: {level + 1}')
				if level == step - 1 and len(S) == step - 1:
					die(border, f'Congrats, you got the flag: {flag}')
				try:
					pr(border, f'Please send first byte string: ')
					s1 = sc()[:-1]
					pr(border, f'Please send second byte string: ')
					s2 = sc()[:-1]
					s1, s2 = binascii.unhexlify(s1), binascii.unhexlify(s2)
				except:
					pr(border, 'You should send valid hex strings.')
					break
				if len(s1) == len(s2) == 35 - level and s1 != s2:
					if vinefruit(s1, mod, 1) == vinefruit(s2, mod, 1):
						if vinefruit(s1, mod, 1) not in S:
							S.append(vinefruit(s1, mod, 1))
							pr(border, 'gj, try the next level :)')
						else:
							break
					else:
						break
				else:
					die(border, 'Kidding me?! Try again and be smart!! Bye!!!')
		elif ans == 'q':
			die(border, 'Quitting...')
		else:
			die(border, 'You should select valid choice!')

if __name__ == '__main__':
	main()
```
