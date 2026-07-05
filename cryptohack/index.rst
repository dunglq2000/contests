Wargame chill chill
*******************

Để tránh vấn đề bản quyền và bị soi bởi cộng đồng toxic nào đó thì mình sẽ không để đề ở đây.

Đã giải:

- Bounded Noise (đã viết lời giải)
- Forbiden Fruit
- Noise Free
- Too Many Errors
- Pad-Thai
- Paper Plane

Bound noise
===========

.. only:: html

    .. code-block:: python

        import random
        import json
        from sage.all import *


        FLAG = b"crypto{?????????????????????????????????????????}"


        def keygen(secret, q, erange=range(2)):
            n, m = len(secret), len(secret) ** 2
            A = Matrix(GF(q), m, n, lambda i, j: randint(0, q - 1))
            e = vector(random.choices(erange, k=m), GF(q))
            b = (A * secret) + e
            return A, b, e


        flag_int = int.from_bytes(FLAG, "big")
        q = 0x10001
        secret_key = []
        while flag_int:
            secret_key.append(flag_int % q)
            flag_int //= q

        secret_key = vector(GF(q), secret_key)
        A, b, e = keygen(secret_key, q)

        with open("output.txt", "w") as f:
            json.dump({"A": str(list(A)), "b": str(b)}, f)

Đây là một bài LWE cơ bản.

Giả sử flag là một số nguyên :math:`M`. Chọn số nguyên tố :math:`q = 65537` và biểu diễn :math:`M` ở dạng cơ số :math:`q` thì ta được vector

.. math:: M = s_0 + s_1 q + s_2 q^2 + \cdots + s_{n-1} q^n \mapsto (s_0, s_1, \ldots, s_{n-1}).

Secret sẽ là vector :math:`(s_0, \ldots, s_{n-1})` và mình kí hiệu ngắn gọn là :math:`\bm{s}`.

Chọn ngẫu nhiên ma trận :math:`\bm{A}` kích thước :math:`m \times n` với các phần tử thuộc :math:`\mathbb{F}_q`, trong đó :math:`n` là độ dài vector :math:`\bm{s}` và :math:`m = n^2`.

Sau đó chọn ngẫu nhiên vector :math:`\bm{e}` độ dài :math:`m` với các phần tử thuộc :math:`\{ 0, 1 \}`. Tính vector :math:`\bm{b} = \bm{A} \cdot \bm{s} + \bm{e}`.

Khi đó public key là ma trận :math:`\bm{A}` và vector :math:`\bm{b}`. Ta cần tìm flag là secret key.

.. only:: html

    .. code-block:: python

        import json
        import numpy as np
        from sage.all import GF

        js = json.loads(open("output.txt").read())

        A = eval(js["A"])
        b = eval(js["b"])
        q = 0x10001

        # https://github.com/jvdsn/crypto-attacks/blob/master/attacks/lwe/arora_ge.py
        def attack(q, A, b, E, S=None):
            """
            Recovers the secret key s from the LWE samples A and b.
            More information: "The Learning with Errors Problem: Algorithms" (Section 1)
            :param q: the modulus
            :param A: the matrix A, represented as a list of lists
            :param b: the vector b, represented as a list
            :param E: the possible error values
            :param S: the possible values of the entries in s (default: None)
            :return: a list representing the secret key s
            """
            m = len(A)
            n = len(A[0])
            gf = GF(q)
            pr = gf[tuple(f"x{i}" for i in range(n))]
            gens = pr.gens()

            f = []
            for i in range(m):
                p = 1
                for e in E:
                    p *= (b[i] - sum(A[i][j] * gens[j] for j in range(n)) - e)
                f.append(p)

            if S is not None:
                # Use information about the possible values for s to add more polynomials.
                for j in range(n):
                    p = 1
                    for s in S:
                        p *= (gens[j] - s)
                    f.append(p)

            s = []
            for p in pr.ideal(f).groebner_basis():
                assert p.nvariables() == 1 and p.degree() == 1
                s.append(int(-p.constant_coefficient()))

            return s


        s = attack(q, A, b, range(2))
        flag = 0
        for i in s[::-1]:
            flag = flag * q + i

        print(int.to_bytes(flag, flag.bit_length() // 8 + 1, 'big'))

[TODO] Cần hiểu cách thực hiện của đoạn code kia.

Forbiden fruit
==============

.. only:: html

    .. code-block:: python

        from Crypto.Cipher import AES
        from Crypto.Util.number import long_to_bytes, bytes_to_long
        from sage.all import *
        import requests
        import json


        FLAG = b'crypto{}'
        KEY = b'deadbeaf00112233'
        IV = b'dddduuuupppp'

        assert len(IV) == 12

        def decrypt(nonce, ciphertext, tag, associated_data):
            ciphertext = bytes.fromhex(ciphertext)
            tag = bytes.fromhex(tag)
            header = bytes.fromhex(associated_data)
            nonce = bytes.fromhex(nonce)

            if header != b'CryptoHack':
                return {"error": "Don't understand this message type"}

            cipher = AES.new(KEY, AES.MODE_GCM, nonce=nonce)
            encrypted = cipher.update(header)
            try:
                decrypted = cipher.decrypt_and_verify(ciphertext, tag)
            except ValueError as e:
                return {"error": "Invalid authentication tag"}

            if b'give me the flag' in decrypted:
                return {"plaintext": FLAG.encode().hex()}

            return {"plaintext": decrypted.hex()}


        def encrypt(plaintext):
            plaintext = bytes.fromhex(plaintext)
            header = b"CryptoHack"

            cipher = AES.new(KEY, AES.MODE_GCM, nonce=IV)
            encrypted = cipher.update(header)
            ciphertext, tag = cipher.encrypt_and_digest(plaintext)

            if b'flag' in plaintext:
                return {
                    "error": "Invalid plaintext, not authenticating",
                    "ciphertext": ciphertext.hex(),
                }

            return {
                "nonce": IV.hex(),
                "ciphertext": ciphertext.hex(),
                "tag": tag.hex(),
                "associated_data": header.hex(),
            }


        def xor(a, b):
            return bytes(x^y for x, y in zip(a, b))


        def byte_to_pol(block):
            n = int.from_bytes(block, 'big')
            nn = list(map(int, bin(n)[2:].zfill(128)))
            pol = sum(j*x**i for i, j in enumerate(nn))
            return F128(pol)

        def pol_to_byte(element):
            coeff = element.polynomial().coefficients(sparse=False)
            coeff = coeff + [0] * (128 - len(coeff))
            num = int(''.join(list(map(str, coeff))), 2)
            return int.to_bytes(num, 16, 'big')


        F = GF(2)['x']
        x = F.gen()
        F128 = GF(2**128, 'x', modulus=x**128 + x**7 + x**2 + x + 1)
        PR = PolynomialRing(F128, 'z')
        z = PR.gen()

        pt0 = "01" * 16
        pt1 = "02" * 16
        rq = requests.get("https://aes.cryptohack.org/forbidden_fruit/encrypt/" + pt0)
        res0 = json.loads(rq.text)

        rq = requests.get("https://aes.cryptohack.org/forbidden_fruit/encrypt/" + pt1)
        res1 = json.loads(rq.text)

        tag0 = byte_to_pol(bytes.fromhex(res0["tag"]))
        tag1 = byte_to_pol(bytes.fromhex(res1["tag"]))

        ct0 = byte_to_pol(bytes.fromhex(res0["ciphertext"]))
        ct1 = byte_to_pol(bytes.fromhex(res1["ciphertext"]))

        H2 = (tag0 + tag1) * (ct0 + ct1)**(-1)

        pt2 = b"give me the flag"
        P = byte_to_pol(bytes.fromhex(pt0)) + byte_to_pol(pt2)
        C = P + ct0
        T = tag0 + P * H2

        nonce = res0["nonce"]
        ciphertext = pol_to_byte(C).hex()
        tag = pol_to_byte(T).hex()
        associated_data = res0["associated_data"]

        rq = requests.get(f"https://aes.cryptohack.org/forbidden_fruit/decrypt/{nonce}/{ciphertext}/{tag}/{associated_data}")
        print(bytes.fromhex(json.loads(rq.text)["plaintext"]))

Noise free
==========

.. only:: html

    .. code-block:: python

        from utils import listener
        from sage.all import *


        FLAG = b"crypto{????????????????????????}"

        # dimension
        n = 64
        # plaintext modulus
        p = 257
        # ciphertext modulus
        q = 0x10001

        V = VectorSpace(GF(q), n)
        S = V.random_element()

        def encrypt(m):
            A = V.random_element()
            b = A * S + m
            return A, b


        class Challenge:
            def __init__(self):
                self.before_input = "Would you like to encrypt your own message, or see an encryption of a character in the flag?\n"

            def challenge(self, your_input):
                if 'option' not in your_input:
                    return {'error': 'You must specify an option'}

                if your_input['option'] == 'get_flag':
                    if "index" not in your_input:
                        return {"error": "You must provide an index"}
                        self.exit = True

                    index = int(your_input["index"])
                    if index < 0 or index >= len(FLAG) :
                        return {"error": f"index must be between 0 and {len(FLAG) - 1}"}
                        self.exit = True

                    A, b = encrypt(FLAG[index])
                    return {"A": str(list(A)), "b": str(int(b))}

                elif your_input['option'] == 'encrypt':
                    if "message" not in your_input:
                        return {"error": "You must provide a message"}
                        self.exit = True

                    message = int(your_input["message"])
                    if message < 0 or message >= p:
                        return {"error": f"message must be between 0 and {p - 1}"}
                        self.exit = True

                    A, b = encrypt(message)
                    return {"A": str(list(A)), "b": str(int(b))}

                return {'error': 'Unknown action'}


        import builtins; builtins.Challenge = Challenge # hack to enable challenge to be run locally, see https://cryptohack.org/faq/#listener
        listener.start_server(port=13411)

.. only:: html

    .. code-block:: python

        from pwn import remote, process, context
        import numpy as np
        import json
        from sage.all import *

        # context.log_level = "Debug"

        pr = remote("socket.cryptohack.org", 13411)
        # pr = process(["python", "13411.py"])

        # dimension
        n = 64
        # plaintext modulus
        p = 257
        # ciphertext modulus
        q = 0x10001

        pr.recvline()

        A = []
        B = []

        for m in range(p):
            d = {"option": "encrypt", "message": m}
            pr.sendline(json.dumps(d).encode())
            dj = json.loads(pr.recvline().strip().decode())
            a = eval(dj["A"])
            b = eval(dj["b"])
            if len(A) == 0:
                A = np.array(a)
                B.append(b - m)
            else:
                At = np.vstack([A, a])
                if np.linalg.matrix_rank(At) == np.linalg.matrix_rank(A) + 1:
                    A = np.vstack([A, a])
                    B.append(b - m)
            
            if np.linalg.matrix_rank(A) == n:
                break

        A = matrix(GF(q), A)
        B = vector(GF(q), B)

        S = A.inverse() * B

        print(B)
        print(S)

        flag = []

        for index in range(p):
            d = {"option": "get_flag", "index": index}
            pr.sendline(json.dumps(d).encode())
            dj = json.loads(pr.recvline().strip().decode())
            a = eval(dj["A"])
            b = eval(dj["b"])
            flag.append((b - vector(GF(q), a) * S) % q)
            print(bytes(flag))

        pr.close()

Too Many Errors
===============

.. only:: html

    .. code-block:: python

        from Crypto.Random.random import getrandbits
        import random
        from utils import listener

        SEED = getrandbits(32)
        FLAG = b'crypto{????????????????????}'
        q = 127


        class Challenge():
            def __init__(self):
                self.before_input = f"Welcome to the LWE sample generator! Retrieve a sample using the 'get_sample' option, or reset the distribution using the 'reset' option.\n"
                self.rand = random.Random(SEED)

            def challenge(self, your_input):
                if not "option" in your_input:
                    return {"error": "You must send an option to this server"}

                elif your_input["option"] == "reset":
                    self.rand.seed(SEED)
                    return {"success": "The distribution has been reset"}

                elif your_input["option"] == "get_sample":
                    a = []
                    for i in range(len(FLAG)):
                        a.append(self.rand.randint(0, q - 1))

                    e = self.rand.randint(-1, 1)

                    self.rand.seed(getrandbits(32))
                    if self.rand.randint(0, 1):
                        a[self.rand.randint(0, len(a) - 1)] = self.rand.randint(0, q - 1)

                    b = 0
                    for (i, j) in zip(a, FLAG):
                        b += i * j
                    b += e
                    b %= q

                    return {"a": a, "b": b}

                else:
                    return {"error": "Invalid option"}


        import builtins; builtins.Challenge = Challenge # hack to enable challenge to be run locally, see https://cryptohack.org/faq/#listener
        """
        When you connect, the 'challenge' function will be called on your JSON
        input.
        """
        listener.start_server(port=13390)

.. only:: html

    .. code-block:: python

        from pwn import remote, context
        import json

        # context.log_level = 'Debug'

        q = 127

        flag = [-1] * 28

        flag = b'crypto{f4ult_4ttack5_0n_lw3}'
        flag = list(flag)

        while True:
            ff = [0 if f == -1 else f for f in flag]
            print(bytes(ff))
            if all(i > 0 for i in flag): break

            pr = remote("socket.cryptohack.org", "13390")
            pr.recvline()

            # Phase 1
            js = { "option": "get_sample" }
            pr.sendline(json.dumps(js).encode())

            ds = json.loads(pr.recvline().strip().decode())
            a1 = ds["a"]
            b1 = ds["b"]

            # Reset
            js = { "option": "reset" }
            pr.sendline(json.dumps(js).encode())
            pr.recvline()

            # Phase 2
            js = { "option": "get_sample" }
            pr.sendline(json.dumps(js).encode())

            ds = json.loads(pr.recvline().strip().decode())
            a2 = ds["a"]
            b2 = ds["b"]

            while all(i == j for i, j in zip(a1, a2)):
                # Reset
                js = { "option": "reset" }
                pr.sendline(json.dumps(js).encode())
                pr.recvline()

                # Phase 2
                js = { "option": "get_sample" }
                pr.sendline(json.dumps(js).encode())

                ds = json.loads(pr.recvline().strip().decode())
                a2 = ds["a"]
                b2 = ds["b"]

            for i in range(len(a1)):
                if a1[i] != a2[i] and flag[i] == 0:
                    a = (a1[i] - a2[i]) % q
                    b = (b1 - b2) % q
                    f = (b * pow(a, -1, q)) % q
                    flag[i] = f
                    break
            
            pr.close()

        print(bytes(flag))

Pad Thai
========

.. only:: html

    .. code-block:: python

        # challenge.py
        from Crypto.Util.Padding import unpad
        from Crypto.Cipher import AES
        from os import urandom


        FLAG = "Hello, World"

        class Challenge:
            def __init__(self):
                self.before_input = "Let's practice padding oracle attacks! Recover my message and I'll send you a flag.\n"
                self.message = urandom(16).hex()
                self.key = urandom(16)

            def get_ct(self):
                iv = urandom(16)
                cipher = AES.new(self.key, AES.MODE_CBC, iv=iv)
                ct = cipher.encrypt(self.message.encode("ascii"))
                return {"ct": (iv+ct).hex()}

            def check_padding(self, ct):
                ct = bytes.fromhex(ct)
                iv, ct = ct[:16], ct[16:]
                cipher = AES.new(self.key, AES.MODE_CBC, iv=iv)
                pt = cipher.decrypt(ct)  # does not remove padding
                try:
                    unpad(pt, 16)
                except ValueError:
                    good = False
                else:
                    good = True
                return {"result": good}

            def check_message(self, message):
                if message != self.message:
                    self.exit = True
                    return {"error": "incorrect message"}
                return {"flag": FLAG}

            #
            # This challenge function is called on your input, which must be JSON
            # encoded
            #
            def challenge(self, msg):
                if "option" not in msg or msg["option"] not in ("encrypt", "unpad", "check"):
                    return {"error": "Option must be one of: encrypt, unpad, check"}

                if msg["option"] == "encrypt": return self.get_ct()
                elif msg["option"] == "unpad": return self.check_padding(msg["ct"])
                elif msg["option"] == "check": return self.check_message(msg["message"])

.. only:: html

    .. code-block:: python

        # 13421.py
        #!/usr/bin/env python3

        from Crypto.Util.Padding import unpad
        from Crypto.Cipher import AES
        from os import urandom

        from utils import listener

        FLAG = 'crypto{?????????????????????????????????????????????????????}'

        class Challenge:
            def __init__(self):
                self.before_input = "Let's practice padding oracle attacks! Recover my message and I'll send you a flag.\n"
                self.message = urandom(16).hex()
                self.key = urandom(16)

            def get_ct(self):
                iv = urandom(16)
                cipher = AES.new(self.key, AES.MODE_CBC, iv=iv)
                ct = cipher.encrypt(self.message.encode("ascii"))
                return {"ct": (iv+ct).hex()}

            def check_padding(self, ct):
                ct = bytes.fromhex(ct)
                iv, ct = ct[:16], ct[16:]
                cipher = AES.new(self.key, AES.MODE_CBC, iv=iv)
                pt = cipher.decrypt(ct)  # does not remove padding
                try:
                    unpad(pt, 16)
                except ValueError:
                    good = False
                else:
                    good = True
                return {"result": good}

            def check_message(self, message):
                if message != self.message:
                    self.exit = True
                    return {"error": "incorrect message"}
                return {"flag": FLAG}

            #
            # This challenge function is called on your input, which must be JSON
            # encoded
            #
            def challenge(self, msg):
                if "option" not in msg or msg["option"] not in ("encrypt", "unpad", "check"):
                    return {"error": "Option must be one of: encrypt, unpad, check"}

                if msg["option"] == "encrypt": return self.get_ct()
                elif msg["option"] == "unpad": return self.check_padding(msg["ct"])
                elif msg["option"] == "check": return self.check_message(msg["message"])

        import builtins; builtins.Challenge = Challenge # hack to enable challenge to be run locally, see https://cryptohack.org/faq/#listener
        listener.start_server(port=13421)

.. only:: html

    .. code-block:: python

        # solve.py
        import random
        from pwn import remote, context
        import json
        from challenge import Challenge

        is_local = False

        def xor(a, b):
            return bytes(x^y for x, y in zip(a, b))

        if is_local: # Local
            challenge = Challenge()

            first_message = []
            second_message = []

            S = list(b'0123456789abcdef')

            opt = { "option": "encrypt" }

            ct = challenge.challenge(opt)["ct"]
            ct = bytes.fromhex(ct)

            # First message
            print("Find first message")

            iv, ct = ct[:16], ct[16:]
            c1 = ct[:16]

            for x in range(1, 17):
                queries = 0
                payload = [x] * x
                payload = [0] * (16 - x) + payload
                payload = xor(iv, payload)
                for i in S:
                    iv_ = [0] * (15 - len(first_message)) + [i] + first_message
                    iv_ = xor(iv_, payload)
                    opt2 = { "option": "unpad", "ct": (iv_ + c1).hex() }
                    result = challenge.challenge(opt2)["result"]
                    if result == True:
                        print(f"Found char {chr(i)} at index {x}")
                        first_message = [i] + first_message
                        break
                print(bytes(first_message))

            # assert challenge.message[:16].encode() == bytes(first_message)
            assert len(first_message) == 16

            # Second part
            print("\nFind second part")
            iv = c1
            c1 = ct[16:]

            for x in range(1, 17):
                queries = 0
                payload = [x] * x
                payload = [0] * (16 - x) + payload
                payload = xor(iv, payload)
                ff = False
                for i in S:
                    iv_ = [0] * (15 - len(second_message)) + [i] + second_message
                    iv_ = xor(iv_, payload)
                    opt2 = { "option": "unpad", "ct": (iv_ + c1).hex() }
                    result = challenge.challenge(opt2)["result"]
                    if result == True:
                        second_message = [i] + second_message
                        break
                print(bytes(second_message))

            assert len(second_message) == 16

            assert challenge.message[16:].encode() == bytes(second_message)
            flag = challenge.challenge({ "option": "check", "message": (bytes(first_message + second_message)).decode()})["flag"]
            print(flag)
        else: # Remote
            context.log_level = 'Debug'
            pr = remote("socket.cryptohack.org", "13421")
            pr.recvline()

            first_message = []
            second_message = []

            S = list(b'0123456789abcdef')

            opt = { "option": "encrypt" }
            pr.sendline(json.dumps(opt).encode())
            ct = json.loads(pr.recvline().strip())["ct"]

            ct = bytes.fromhex(ct)

            # First message
            print("Find first message")

            iv, ct = ct[:16], ct[16:]
            c1 = ct[:16]

            for x in range(1, 17):
                queries = 0
                payload = [x] * x
                payload = [0] * (16 - x) + payload
                payload = xor(iv, payload)
                for i in S:
                    iv_ = [0] * (15 - len(first_message)) + [i] + first_message
                    iv_ = xor(iv_, payload)
                    opt2 = { "option": "unpad", "ct": (iv_ + c1).hex() }
                    pr.sendline(json.dumps(opt2).encode())
                    result = json.loads(pr.recvline().strip())["result"]
                    if result == True:
                        print(f"Found char {chr(i)} at index {x}")
                        first_message = [i] + first_message
                        break
                print(bytes(first_message))

            # assert challenge.message[:16].encode() == bytes(first_message)
            assert len(first_message) == 16

            # Second part
            print("\nFind second part")
            iv = c1
            c1 = ct[16:]

            for x in range(1, 17):
                queries = 0
                payload = [x] * x
                payload = [0] * (16 - x) + payload
                payload = xor(iv, payload)
                ff = False
                for i in S:
                    iv_ = [0] * (15 - len(second_message)) + [i] + second_message
                    iv_ = xor(iv_, payload)
                    opt2 = { "option": "unpad", "ct": (iv_ + c1).hex() }
                    pr.sendline(json.dumps(opt2).encode())
                    result = json.loads(pr.recvline().strip())["result"]
                    if result == True:
                        second_message = [i] + second_message
                        break
                print(bytes(second_message))

            assert len(second_message) == 16

            # assert challenge.message[16:].encode() == bytes(second_message)
            print(bytes(first_message + second_message))
            opt3 = { "option": "check", "message": bytes(first_message + second_message).decode("ascii") }
            pr.sendline(json.dumps(opt3).encode())
            print(pr.recvline())
            pr.close()

            # b'{"flag": "crypto{if_you_ask_enough_times_you_usually_get_what_you_want}"}\n'

Paper Plane
===========

.. only:: html

    .. code-block:: python

        # solve.py
        import requests


        def xor(a, b):
            return bytes(x^y for x, y in zip(a, b))


        c0 = bytes.fromhex("1e1cb70d4aaf8f74d845e8f85f636a22")
        ciphertext = bytes.fromhex("dd2d25c1e61648b6a1cbab88466e832e1758163b68165cf8c5efd21af5682bd5")
        m0 = bytes.fromhex("c8dd40be54e559068842351c72207dfd")

        flag1 = b'crypto{h3ll0_t3l'
        flag2 = b'3gr4m}\n\n\n\n\n\n\n\n\n\n'
        print(flag1 + flag2)
        exit(0)

        flag = b'\n' * 10
        idx = len(flag)
        flag = list(b'\x00'*(16-len(flag)) + flag)

        c0 = ciphertext[:16]
        ciphertext = ciphertext[16:]
        m0 = flag1

        for x in range(idx, 16):
            payload = bytes([x+1]) * x
            payload = b'\x00' * (16 - len(payload)) + payload
            padding = xor(c0, xor(flag, payload))[16-x:]
            for i in range(256):
                c0_ = c0[:(15-x)] + bytes([i]) + padding
                assert len(c0_) == 16
                rq = requests.get(f"https://aes.cryptohack.org/paper_plane/send_msg/{ciphertext.hex()}/{m0.hex()}/{c0_.hex()}")
                if 'received' in rq.text:
                    f = c0[-(x+1)] ^ i ^ (x+1)
                    if f > 127:
                        print(f"Something wrong: {f}")
                        exit(0)
                    print(f"Found character {i} at index {x}")
                    flag[15-x] = f
                    break
            print(i)
            if i == 256:
                print("Wrong padding")
                exit(0)
            print(bytes(flag))
