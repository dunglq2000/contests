ISITDTU Quals 2024
******************

Share Mixer 1
=============

.. only:: html

    .. code-block:: python

        import random   # TODO: heard that this is unsafe but nvm
        from Crypto.Util.number import getPrime, bytes_to_long

        flag = bytes_to_long(open("flag.txt", "rb").read())
        p = getPrime(256)
        assert flag < p
        l = 32


        def share_mixer(xs):
            cs = [random.randint(1, p - 1) for _ in range(l - 1)]
            cs.append(flag)

            # mixy mix
            random.shuffle(xs)
            random.shuffle(cs)

            shares = [sum((c * pow(x, i, p)) %
                        p for i, c in enumerate(cs)) % p for x in xs]
            return shares


        if __name__ == "__main__":
            try:
                print(f"{p = }")
                queries = input("Gib me the queries: ")
                xs = list(map(lambda x: int(x) % p, queries.split()))

                if 0 in xs or len(xs) > 256:
                    print("GUH")
                    exit(1)

                shares = share_mixer(xs)
                print(f"{shares = }")
            except:
                exit(1)

Cho :math:`p` là số nguyên tố lớn :math:`256` bit. Chúng ta sẽ nhập vào dãy :math:`x_0`, :math:`x_1`, ..., :math:`x_{n-1}` với :math:`n \leqslant 256`.

Sau đó đề (hàm `share_mixer`) tạo random một dãy :math:`c_0`, :math:`c_1`, ..., :math:`c_{30}` và đặt :math:`c_{31} = \text{flag}`. Sau đó hai dãy `xs` và `cs` sẽ được xáo trộn thành dãy :math:`\{x_i'\}` và :math:`\{c_i'\}`, và tính `shares` là dãy

.. math:: s_j = \sum_{i=0}^{31} c_i' \cdot (x_j')^i \pmod p

với :math:`j = 0, 1, \ldots, n-1`.

Ý tưởng là mình sẽ gửi lên dãy gồm :math:`1` số :math:`1`, :math:`2` số :math:`2`, ..., :math:`15` số :math:`15`. Thêm nữa mình gửi :math:`1` số :math:`16`, ..., :math:`15` số :math:`30`. Cuối cùng là hai số :math:`31` và :math:`32`.

.. only:: html

    .. code-block:: python

        # solve.py
        from pwn import process, context, remote
        from sage.all import *
        import itertools
        from Crypto.Util.number import long_to_bytes
        import hashlib
        import sys

        context.log_level = 'Debug'

        # pr = process(["python", "chall.py"])
        pr = remote("35.187.238.100", "5001")

        for _ in range(3):
            pr.recvline()

        data = pr.recvline().decode()
        u = data.index("\"") + 1
        v = data.index("\" + ?")

        print(u, v)

        prefix = data[u:v]
        difficulty = 6 * 4 # data[v+10:].count("0")
        zeros = '0' * difficulty

        def is_valid(digest):
            if sys.version_info.major == 2:
                digest = [ord(i) for i in digest]
            bits = ''.join(bin(i)[2:].zfill(8) for i in digest)
            return bits[:difficulty] == zeros

        i = 0
        while True:
            i += 1
            s = prefix + str(i)
            if is_valid(hashlib.sha256(s.encode()).digest()):
                print(i)
                break

        def extract(cnt: list[int, int]):
            return cnt[0][0], [c[1] for c in cnt]

        pr.sendlineafter(b"Suffix: ", str(i).encode())

        l = 32

        p = int(pr.recvline().decode()[4:])
        print(f"{p = }")

        x = []

        for i in range(1, 16):
            x.extend([i] * i)

        for i in range(16, 31):
            x.extend([i] * (i - 15))

        x.extend([31, 32])

        assert len(x) <= 256, len(x)

        pr.sendlineafter(b"Gib me the queries: ", " ".join(map(str, x)).encode())

        shares = eval(pr.recvline().decode()[9:])
        pr.close()

        PR = PolynomialRing(GF(p), 'y')
        y = PR.gen()

        s = set(shares)

        cnts = [(shares.count(i), i) for i in s]

        cnts.sort(key = lambda x: x[0])
        cnts = [extract(cnts[:4])] + [extract(cnts[i:i+2]) for i in range(4, len(cnts), 2)]
        print(cnts)

        points = []

        def bruteforce(i):
            if i == 15:
                pol = PR.lagrange_polynomial(points)
                # assert pol.degree() == 32
                coeffs = pol.coefficients(sparse=False)
                for coeff in coeffs:
                    try:
                        print(long_to_bytes(int(coeff)).decode())
                    except:
                        pass
            else:
                if i == 0:
                    xs = [1, 16, 31, 32]
                    for ys in itertools.permutations(cnts[0][1]):
                        points.extend(list(zip(xs, ys)))
                        bruteforce(i+1)
                        for _ in range(4): points.pop()
                else:
                    __x = cnts[i][0]
                    xs = [__x, __x + 15]
                    for ys in itertools.permutations(cnts[i][1]):
                        points.extend(list(zip(xs, ys)))
                        bruteforce(i+1)
                        for _ in range(2): points.pop()

        bruteforce(0)

        # ISITDTU{Mix1_a5850c98ad583157f0}

Share Mixer 2
=============

.. only:: html

    .. code-block:: python
            
        import random   # TODO: heard that this is unsafe but nvm
        from Crypto.Util.number import getPrime, bytes_to_long

        flag = bytes_to_long(open("flag.txt", "rb").read())
        p = getPrime(256)
        assert flag < p
        l = 32

        def share_mixer(xs):
            cs = [random.randint(1, p - 1) for _ in range(l - 1)]
            cs.append(flag)
            
            # mixy mix
            random.shuffle(xs)
            random.shuffle(cs)

            shares = [sum((c * pow(x, i, p)) % p for i, c in enumerate(cs)) % p for x in xs]
            return shares


        if __name__ == "__main__":
            try:
                print(f"{p = }")
                queries = input("Gib me the queries: ")
                xs = list(map(lambda x: int(x) % p, queries.split()))

                if 0 in xs or len(xs) > 32:
                    print("GUH")
                    exit(1)

                shares = share_mixer(xs)
                print(f"{shares = }")
            except:
                exit(1)

Chưa làm ra. :)))

Sign
====

.. only:: html

    .. code-block:: python
            
        #!/usr/bin/env python3

        import os

        from Crypto.Util.number import *
        from Crypto.Signature import PKCS1_v1_5
        from Crypto.PublicKey import RSA
        from Crypto.Hash import SHA256

        flag = b'ISITDTU{aaaaaaaaaaaaaaaaaaaaaaaaaa}'
        flag = os.urandom(255 - len(flag)) + flag


        def genkey(e=11):
            while True:
                p = getPrime(1024)
                q = getPrime(1024)
                if GCD(p-1, e) == 1 and GCD(q-1, e) == 1:
                    break
            n = p*q
            d = pow(e, -1, (p-1)*(q-1))
            return RSA.construct((n, e, d))


        def gensig(key: RSA.RsaKey) -> bytes:
            m = os.urandom(256)
            h = SHA256.new(m)
            s = PKCS1_v1_5.new(key).sign(h)
            return s


        def getflagsig(key: RSA.RsaKey) -> bytes:
            return long_to_bytes(pow(bytes_to_long(flag), key.d, key.n))


        key = genkey()

        while True:
            print(
                """=================
        1. Generate random signature
        2. Get flag signature
        ================="""
            )

            try:
                choice = int(input('> '))
                if choice == 1:
                    sig = gensig(key)
                    print('sig =', sig.hex())
                elif choice == 2:
                    sig = getflagsig(key)
                    print('sig =', sig.hex())
            except Exception as e:
                print('huh')
                exit(-1)

Chưa làm ra. :)))

Thats so random
===============

.. only:: html

    .. code-block:: python

        import random
        flag  = random.randbytes(random.randint(13, 1337))
        flag += open("flag.txt", "rb").read()
        flag += random.randbytes(random.randint(13, 1337))
        random.seed(flag)
        print(len(flag) < 1337*1.733 and [random.randrange(0, int(0x13371337*1.337)) for _ in range(0x13337)])

Chưa làm ra. :)))
