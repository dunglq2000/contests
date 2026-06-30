TJCTF 2024
**********

Một ngày đẹp trời 20/05/20xx ...

Đề bài của CTF này có nhiều câu rất dài nên mình không để ở đây. Các bạn có thể tải đề từ github của cuộc thi tại `đây <https://github.com/TJCSec/tjctf-2024-challenges>`_.

weird-crypto
============

Đây là một bài RSA cơ bản và không may là lúc thi mình không vào được factordb, nhưng ``oops`` đủ nhỏ để bruteforce nên cũng không hề gì.

accountleak
============

Bài này cần tìm ``subs`` để recover lại ``p`` và ``q``. Tương tự bài trên, ``subs`` cũng đủ nhỏ để mình bruteforce đến khi nào tìm được cặp ``p`` và ``q`` là hai số nguyên tố và decrypt ``my_password``.

.. code-block:: python

    from sage.all import *
    from pwn import process, context, remote
    import re

    context.log_level = 'Debug'

    pr = process(["python3", "server.py"])
    # pr = remote("tjc.tf", 31601)

    pr.recvline()
    c, n = list(map(int, re.findall(r'\d+', pr.recvline().strip().decode())))

    pr.recvline()
    pr.recvline()
    pr.sendlineafter(b'<You>', b'yea')
    pr.recvline()
    dont_leak_this = int(re.findall(r'\d+', pr.recvline().strip().decode())[0])

    print(f"c = {c}")
    print(f"n = {n}")
    print(f"dont_leak_this = {dont_leak_this}")

    for sub in range(1, 2**20):
        if (n + sub**2 - dont_leak_this) % sub != 0: continue
        s = (n + sub**2 - dont_leak_this) // sub
        PR = PolynomialRing(ZZ, 'x')
        x = PR.gen()
        f = x**2 - s*x + n
        roots = f.roots()
        if len(roots) == 0: continue
        p, q = roots[0][0], roots[1][0]
        assert p * q == n
        d = pow(65537, -1, (p-1) * (q-1))
        my_password = pow(c, d, n)
        pr.recvline()
        pr.recvline()
        pr.sendlineafter(b"<You>", str(my_password).encode())
        pr.recvline()
        pr.recvline()
        print(pr.recvline())
        
    pr.close()

assume
============

Ở bài này mình chỉ cần kiểm tra xem if hay else được thực thi bằng việc kiểm tra message thứ 5 của mỗi đoạn có bằng ``(g^a)^b`` không.

.. code-block:: python

    with open("log.txt") as f:
        lines = [line.strip() for line in f.readlines()]

    p = int(lines[0])
    msg = lines[1:]
    g = 6

    flag = ""
    pos = 0

    for ln in range(0, len(msg), 6 * 20):
        for i in range(ln, ln + 6 * 20, 6):    
            ga = int(msg[i].split(" ")[-1])
            b = int(msg[i+1].split(" ")[-1])
            gb = int(msg[i+2].split(" ")[-1])
            c = msg[i+3].split(" ")[-1]
            guess = int(msg[i+4].split(" ")[-1])
            if pow(ga, b, p) == guess:
                flag += c
                pos += 1
                break
        print(flag)

    print(flag)

iodomethane
============
 
Ở bài này, nếu gọi :math:`K` là khóa thì :math:`K` là ma trận :math:`3 \times 3`. Giả sử flag gồm các bytes :math:`f_0 f_1 \ldots f_{n}` thì kết quả output là phép nhân ma trận

.. math:: \begin{pmatrix} f_0 & f_1 & f_2 \\ f_3 & f_4 & f_5 \\ & \ddots & \\ \end{pmatrix} \cdot K = \begin{pmatrix} e_0 & e_1 & e_2 \\ e_3 & e_4 & e_5 \\ & \ddots & \end{pmatrix}.

Với flag format là ``tjctf{``, mình đã biết :math:`6` ký tự đầu của flag, mình chỉ cần bruteforce thêm :math:`3` ký tự nữa là có thể kết hợp với output để tìm :math:`K`. Ở đây :math:`K` cần thỏa mãn là ma trận khả nghịch và khi decrypt mỗi dòng của flag (trừ dòng cuối) phải cho kết quả nằm trong ``alphabet``.

Code giải mình để ở :download:`solve.py <iodomethane/solve.py>`.

alkane
============

Bài này mình giải ra sau cùng do một số nhầm lẫn. 

Giả sử gọi dòng :math:`i` của `schedule` là :math:`S^{(i)} = ( s^{(i)}_0, s^{(i)}_1, \ldots, s^{(i)}_{63} )`.

Gọi key là :math:`K = k_0 k_1 \ldots k_{128}`. Khi đó mảng `arr` sẽ được tạo bằng cách

.. math:: \text{arr}_i = k_{s^{(i)}_0} \oplus k_{s^{(i)}_1} \oplus \ldots \oplus k_{s^{(i)}_{63}}.

Ý tưởng của mình là xem phép tính trên như một tích vô hướng của hai vector :math:`\bar{a}_i = (a_0, \ldots, a_{127})` và :math:`K`, với :math:`a_j = 1` nếu :math:`j` nằm trong :math:`S^{(i)}`, ngược lại thì :math:`a_j = 0`.

Khi mình xây dựng ma trận :math:`M` gồm các dòng là các vector :math:`\bar{a}_i` như trên thì mình không decrypt ra được. Mãi về sau mình mới phát hiện rằng trong :math:`S^{(i)}` có một số phần tử trùng nhau chứ không hoàn toàn là :math:`64` phần tử phân biệt.

Khi đó mình cần xem số lần mỗi phần tử xuất hiện trong :math:`S^{(i)}` là chẵn hay lẻ.

Một vấn đề khác là ma trận :math:`M` có rank bằng 127, không phải full rank. Do đó để tìm tất cả nghiệm của hệ phương trình mình cần cộng với tất cả tổ hợp tuyến tính của các vector trong kernel.

.. code-block:: python

    from sage.all import *

    m = b'yellow submarine'
    c = b'\xb7\x8e\xb3\xd9\xfd\xf2\x1f\xa2\xeaz\xe3\x0f\x00xj\x08'

    assert len(m) == len(c)

    def xor(a, b):
        return bytes(x^y for x, y in zip(a, b))

    def get_bit(b, n):
        byte = b[n // 8]
        return (byte >> (7 - (n % 8))) & 1

    def set_bit(b, n, v):
        byte = b[n // 8]
        byte &= ~(v << (7 - (n % 8)))
        byte |= v << (7 - (n % 8))
        b[n // 8] = byte
        return b

    def rrot(x1, n):
        arr = bytearray(x1)
        for i in range(len(x1)):
            arr[(i + n) % len(x1)] = x1[i]
        return arr

    def lrot(x1, n):
        arr = bytearray(x1)
        for i in range(len(x1)):
            arr[i] = x1[(i + n) % len(x1)]
        return arr

    out = xor(m, c)

    M = matrix(GF(2), 128, 128)

    from challenge import schedule

    for i in range(128):
        for bit_loc in schedule[i]:
            M[i, bit_loc] += 1

    arr = vector(GF(2), [get_bit(out, i) for i in range(128)])

    try:
        sol = M.solve_right(arr)
    except: exit(0)

    ker = M.right_kernel()

    assert len(ker.basis()) == 1

    sol_ = sol + ker.basis()[0]
    assert M * sol == arr and M * sol_ == arr

    key = bytearray(b"\x00" * 16)
    for i in range(128):
        set_bit(key, i, int(sol[i]))

    print(b"tjctf{" + key + b"}")

    key_ = bytearray(b"\x00" * 16)
    for i in range(128):
        set_bit(key_, i, int(sol_[i]))

    print(b"tjctf{" + key_ + b"}")

lightweight-crypto-guard-system
===============================

Đây là một bài LCG cũng không quá phức tạp.

Với seed ban đầu :math:`x_0`, chuỗi sẽ được sinh theo công thức :math:`x_{i+1} = (a x_i + b) \bmod m`. Ở đây cả :math:`a`, :math:`b` và :math:`m` đều không biết.

Có nhiều hướng dẫn mình tham khảo để tìm lại modulo :math:`m` và :math:`a`, :math:`b` (mình lười :v). Ví dụ như ở `link <https://math.stackexchange.com/questions/2724959/how-to-crack-a-linear-congruential-generator-lcg>`_.

Nhưng vấn đề ở bài này là chúng ta được cho  một đoạn liên tục :math:`x_0, x_1, x_2, \ldots` mà thay vào đó là :math:`x_1`, :math:`x_{1+n}`, :math:`x_{2n+1}` (tổng có 6 số).

Thực ra cách giải vẫn giống nhau. Đầu tiên mình recover modulo :math:`m`. Sau đó để ý rằng

.. math:: 

    x_1 & = (a x_0 + b) \bmod m \\
    x_2 & = (a x_1 + b) \bmod m = (a \cdot (a x_0 + b) + b) = (a^2 x_0 + ab + b) \bmod m \\ 
    x_3 & = (a x_2 + b) \bmod m = \ldots = a^3 x_0 + a^2 b + ab + b = a^3 x_0 + \dfrac{a^3 - 1}{a - 1} \cdot b \bmod m.

Cứ tương tự vậy mình có :math:`x_{i+n} = (A x_n + B) \bmod m`,

với :math:`A = a^n \bmod m` và :math:`B = \dfrac{a^n - 1}{a - 1} \cdot b \bmod m`.

Như vậy mình có một LCG mới và giải ra được :math:`A`, :math:`B`.

Sau đó mình recover lại :math:`a` và :math:`b`. Như vậy là mình sinh được toàn bộ dãy.

hulksmash
============

Với hint là file ``keysmashes.txt`` thì các dòng trong file sẽ giúp mình tìm key.

Để ý rằng mỗi dòng chỉ gồm các ký tự ``fjdlska;`` (:math:`8` ký tự, mỗi ký tự xuất hiện hai lần).

Để ý thêm xíu nữa, mình phát hiện ra mỗi ký tự xuất hiện hai lần vào vị trí hoặc đều chẵn, hoặc đều lẻ. Cụ thể là các ký tự ``fdsa`` sẽ ở vị trí chẵn còn ``jlk;`` ở vị trí lẻ.

Như vậy mình bruteforce tất cả tổ hợp như vậy và thử decrypt ...

.. code-block:: python

    from Crypto.Cipher import AES
    from itertools import combinations

    with open("keysmashes.txt") as rf:
        lines = [line.strip() for line in rf.readlines()]

    alphabet = list(b"fjdlska;")
    assert len(alphabet) == 8

    ct = bytes.fromhex('ed05f1440f3ae5309a3125a91dfb0edef306e1a64d1c5f7d8cea88cdb7a0d7d66bb36860082a291138b48c5a6344c1ab')

    odd = set([1, 3, 5, 7, 9, 11, 13, 15])
    even = set([0, 2, 4, 6, 8, 10, 12, 14])

    for x1, x2 in combinations(odd, 2):
        ox = odd.difference([x1, x2])
        for y1, y2 in combinations(ox, 2):
            oy = ox.difference([y1, y2])
            for z1, z2 in combinations(oy, 2):
                t1, t2 = oy.difference([z1, z2])
                assert set([x1, x2, y1, y2, z1, z2, t1, t2]) == odd
                for a1, a2 in combinations(even, 2):
                    ea = even.difference([a1, a2])
                    for b1, b2 in combinations(ea, 2):
                        eb = ea.difference([b1, b2])
                        for c1, c2 in combinations(eb, 2):
                            d1, d2 = eb.difference([c1, c2])
                            key = [0] * 16
                            key[x1] = key[x2] = ord('j')
                            key[y1] = key[y2] = ord('l')
                            key[z1] = key[z2] = ord('k')
                            key[t1] = key[t2] = ord(';')

                            key[a1] = key[a2] = ord('f')
                            key[b1] = key[b2] = ord('d')
                            key[c1] = key[c2] = ord('s')
                            key[d1] = key[d2] = ord('a')

                            aes = AES.new(bytes(key), AES.MODE_ECB)
                            try:
                                print(aes.decrypt(ct).decode())
                            except:
                                pass

Tiếp theo mình sẽ trình bày các bài mình làm sau khi giải kết thúc (có tham khảo writeup).

c-8
============

Đề bài cho mình các file ``enc.py``, ``dec.py``, ``re_plaus``, ``plausibly.deniable``. Với hint là affine cipher và modulo ``n = 18446744073709551629`` mình cần khôi phục lại bốn file trên.

Do :math:`n` có :math:`65` bit nên việc mã hóa theo mã affine sẽ mã hóa :math:`8` bytes một lần ra :math:`9` bytes của ciphertext. Các bạn cũng có thể thấy rằng byte đầu của mỗi đoạn :math:`9` bytes các file trên là ``0x00`` hoặc ``0x01``.

Mã affine có dạng :math:`y = ax + b \bmod n` với :math:`a` và :math:`b` là hai số chưa biết cần đi tìm. Mình đã có :math:`y` và cần dự đoán :math:`x` nào sẽ mã hóa ra :math:`y` tương ứng. Đoạn đầu của các file mã hóa với Python thường sẽ dùng các thư viện như ``pycryptodome``. Mình thử một loạt các kiểu import và tìm ra phần đầu sẽ là

.. code-block:: python

    from Crypto.Cipher import AES

Mình chỉ cần :math:`16` bytes ở trên thôi là được. Dựa vào đó mình khôi phục lại :math:`a` và :math:`b` rồi decrypt bốn file ban đầu.

u-235
============

Lát viết.

titanium-isopropoxide
=====================

Bài này mã hóa bằng file C++ với thuật toán khá phức tạp.

Bug ở bài này là key được tạo ra từ S-box không đủ mạnh. Sử dụng known-plaintext là flag format `tjctf{` và XOR với :math:`6` bytes đầu của ciphertext của hai file mình:

.. code-block:: python

    flag2 = open("flag2.txt.enc", "rb").read()
    flag3 = open("flag3.txt.enc", "rb").read()

    def xor(a, b):
        return bytes(x^y for x, y in zip(a, b))

    known_plaintext = b"tjctf{"

    key = xor(flag2, known_plaintext)

    f2 = []
    f3 = []
    for i in range(len(flag2)):
        f2.append(key[i % len(key)] ^ flag2[i])
        f3.append(key[i % len(key)] ^ flag3[i])

    print(bytes(f2))
    print(bytes(f3))

Ở kết quả thu được từ đoạn code, mình thấy rằng `flag2` khá giống với đoạn văn có nghĩa. Sau dấu ``{`` là từ ``this`` (vì có sẵn chữ ``is``), sau dấu ``_`` là ``cube``. Như vậy, mình XOR đoạn ``tjctf{this_cube`` thì sẽ thấy được key:

.. code-block:: 

    b'<U\xed\x18\xed\x18\xed\x18\xed\x18\xed\x18\xf7\x1e\xed'

Mình thấy rằng key bắt đầu bởi ``<U`` và lặp lại cặp byte ```\xed\x18``. Do đó mình có thể decrypt ra flag.

.. code-block:: python

    flag2 = open("flag2.txt.enc", "rb").read()

    def xor(a, b):
        return bytes(x^y for x, y in zip(a, b))

    known_plaintext = b"tjctf{"

    key = xor(flag2, known_plaintext)

    while len(key) != 70:
        key += b"\xed\x18"

    f2 = []
    for i in range(len(flag2)):
        f2.append(key[i % len(key)] ^ flag2[i])

    print(bytes(f2))

lithium-stearate
================

Sau khi giải kết thúc một pro đã hint cho mình: Slide attack.

Bài này mình được cho :math:`20` cặp plaintext-ciphertext cùng với ciphertext của flag. Thông tin về cipher:

- độ dài block là :math:`16` bits (:math:`2` bytes);
- độ dài khóa là :math:`64` bits (:math:`8` bytes);
- số vòng thực hiện là :math:`100000` vòng.

Hàm mã hóa:

.. code-block:: cpp

    Word encrypt(Word in, Key k)
    {
        Word out = in;
        for (int i = 0; i < rounds; i++)
        {
            out = r(out, ksch(k, i));
        }
        return out;
    }

Trong đó ``rounds = 100000`` và ``ksch`` là key schedule sinh ra subkey cho mỗi vòng.

round function
--------------

Round function là hàm ``r`` với cấu trúc như sau:

.. code-block:: cpp

    Word r(Word in, RKey kin)
    {
        RKey k = kin;
        in ^= (k & 0xffff) ^ ((k >> 16) & 0xffff);
        return P_f(S_f(in));
    }

Trong đó, ``P_f`` và ``S_f`` là hai hàm:

.. code-block:: cpp

    Word S_f(Word in)
    {
        return (Sbox[in >> 8] << 8) | Sbox[in & 0xff];
    }

    Word P_f(Word in)
    {
        int r = 3;

        Word out = 0;
        out |= (in >> 8) & 0xff;
        out |= (in & 0xff) << 8;
        out ^= out >> 8;
        
        Word out2 = 0;
        out2 |= out >> r;
        out2 |= out << (16 - r);

        return out2;
    }

Như vậy, ``S_f`` là hàm sử dụng S-box cho trước, và ``P_f`` là hàm hoán vị. Mình kí hiệu hai hàm này là :math:`S_f` và :math:`P_f`.

Như vậy round function có dạng :math:`out = P_f(S_f(out \oplus k))`, trong đó :math:`r` là số :math:`16` bits và :math:`k` cũng là số :math:`16` bits. Ở đây lưu ý rằng tham số thứ hai của `r` là số :math:`32` bits nhưng thực chất là lấy nửa đầu XOR nửa cuối, như vậy key được dùng có :math:`16` bits.

key schedule
------------

Thuật toán sinh khóa ``ksch`` lấy đầu vào là khóa ban đầu :math:`8` bytes và vòng hiện tại :math:`i` để sinh ra khóa :math:`k_i`. Khi thử in ra tất cả :math:`1000000` khóa khi mã hóa một plaintext bất kì thì chúng ta có thể thấy rằng **chỉ có đúng bốn subkey xoay vòng**.

Kết hợp với lúc nãy mình chỉ ra, mỗi round function lấy vào key :math:`32` bits nhưng thực chất chỉ là :math:`16` bits. Như vậy nếu bruteforce cả bốn vòng với bốn subkeys thì sẽ cần :math:`16 \times 4 = 64` bits. À thì nó cũng chả khác việc key ban đầu có :math:`64` bits :))) nên chúng ta sẽ không bruteforce kiểu này.

Chúng ta sẽ xem kỹ hơn hàm sinh khóa con ``ksch``.

.. code-block:: cpp

    RKey ksch(Key k, int i)
    {
        // .............
        k |= 0xff << 24;
        k |= 0xffULL << (24 + 32);
        // .............
    }

Đoạn trên cho thấy rằng, sau một hồi biến đổi, hàm ``ksch`` sẽ set bit thứ :math:`3` và thứ :math:`7` của biến ``k`` thành ``0xff``, nghĩa là ``k`` lúc này có dạng ``0xff------ff------`` (:math:`64` bits).

.. code-block:: cpp

    RKey ksch(Key k, int i)
    {
        // .............
        if (i == 0)
        {
            r = k & 0xffffffff;
            r ^= 1162466901;
            r ^= r >> 16;
            r *= 3726821653;
        }
        if (i == 1)
        {
            r = ((k >> 32) & 0xffffffff) ^ (k & 0xffffffff);
            r ^= 3811777446;
            r = (r * 1240568533);
        }
        if (i == 2)
        {
            r = ((k >> 32) & 0xffffffff) ^ (k & 0xffffffff);
            r ^= 3915669785;
            r = (r * 1247778533);
        }
        if (i == 3)
        {
            r = ((k >> 32) & 0xffffffff) ^ (k & 0xffffffff);
            r ^= 3140176925;
            r = (r * 1934965865);
        }

        return r;
    }

Ở phần kế của hàm ``ksch`` có :math:`3/4` trường hợp ``r`` là XOR của :math:`32` bits cao và :math:`32` bits thấp. Ở trên mình đã phân tích rằng bytes thứ :math:`3` và thứ :math:`7` của ``k`` sẽ là ``0xff`` nên khi XOR như vậy sẽ triệt tiêu byte đầu tiên của ``r``, nên ``r`` chỉ còn :math:`24` bits và chúng ta sẽ bruteforce ở đây.

Trong trường hợp ``i = 0`` thì chương trình cũng chỉ lấy :math:`32` bits thấp nên chúng ta có thể bỏ qua. Lý do sẽ được trình bày ở phần sau.

slide attack
------------

*Giới thiệu qua loa:* slide attack là phương pháp tấn công block cipher thông qua việc chọn các cặp plaintext-ciphertext :math:`(P, C)` và  :math:`(P', C')` mà :math:`P' = F(P)` và :math:`C' = F(C)` với :math:`F(x)` là hàm nào đó. Khi thỏa mãn các điều kiện trên thì ta có thể thực hiện slide attack.

Để tìm hàm :math:`F(x)` như vậy thì phụ thuộc vào cipher nào. Thông thường hàm :math:`F(x)` sẽ chứa một hoặc nhiều round, trong đó chứa tất cả khóa con của cipher.

**Ví dụ.** Xét mô hình cipher đơn giản sau:

.. math:: P \xrightarrow{K_0} O_1 \xrightarrow{K_1} O_2 \xrightarrow{K_0} O_3 \xrightarrow{K_1} O_3 = C.

Như vậy hàm :math:`F(x)` ở đây sẽ chứa hai subkey là :math:`K_0` và :math:`K_1`. Do đó sơ đồ của :math:`F` sẽ là:

.. math:: P \xrightarrow{F} O_2 \xrightarrow{F} C.

Giả sử với một cặp plaintext-ciphertext khác là:

.. math:: P' \xrightarrow{K_0} O_1 \xrightarrow{K_1} O_2 \xrightarrow{K_0} O_3 \xrightarrow{K_1} O_3 = C'.

hay tương đương là

.. math:: P' \xrightarrow{F} O'_2 \xrightarrow{F} C'.

Slide attack lúc này sẽ hoạt động nếu :math:`P' = O_2 = F(P)` và :math:`C' = F(C)`. Khi vẽ ra sẽ có dạng:

.. math:: 
    :nowrap:

    \begin{align*}
        P & \xrightarrow{F} & O_2 & \xrightarrow{F} & C & \\
        & & P' & \xrightarrow{F} & O_2' & \xrightarrow{F} & C'
    \end{align*}

Quay lại bài lithium-stearate này, do chỉ có bốn subkeys nên có thể xem hàm :math:`F` ở trên có dạng:

.. math:: F(P, K) = G(G(G(G(P, K_0), K_1), K_2), K_3) = P'.

Trong đó :math:`K` là khóa ban đầu :math:`64` bits và mỗi :math:`K_i` là khóa con :math:`32` bits. Hàm :math:`G(x, k) = P_f(S_f(x \oplus k))` là round function.

Như vậy chiến thuật để giải bài này là:

- Tìm trong :math:`20` cặp plaintext-ciphertext đề cho các cặp :math:`(P, C)` và :math:`(P', C')` sao cho :math:`F(P, K) = P'` và :math:`F(C, K) = C'`.
- Từ hai cặp plaintext-ciphertext trên khôi phục khóa :math:`K`.

Tuy nhiên việc này khó khăn vì không có khóa :math:`K` thì không kiểm tra được điều kiện :math:`F(P, K) = P'`. Do đó chúng ta sẽ làm ngược lại.

Như ở trên đã phân tích, :math:`K_1`, :math:`K_2` và :math:`K_3` được sinh ra từ một ``k`` có :math:`24` bits, do đó chúng ta bruteforce các ``k`` như vậy và tính ra :math:`K_1`, :math:`K_2` và :math:`K_3` tương ứng.

Với mỗi hai plaintext :math:`P_i` và :math:`P_j` ta tính :math:`K_0` theo :math:`K_0 = S_f^{-1}(P^{-1}(T)) \oplus P`, với 

.. math:: T = G^{-1}(G^{-1}(G^{-1}(P', K_3), K_2), K_1)..

Khi đã có đủ :math:`K_0`, :math:`K_1`, :math:`K_2` và :math:`K_3`, mình sẽ kiểm tra điều kiện :math:`C' = F(C, K)`. Nếu thỏa mãn thì mình có được một cặp **slid pair** và sẽ thử mã hóa hai cặp plaintext-ciphertext bất kì để xem việc mã hóa với khóa có đúng không.

Khi tìm được khóa rồi thì mình giải mã lại flag.

Sau khi chạy :download:`findkey.cpp <lithium-stearate/findkey.cpp>` thì mình tìm được key là :math:`11892`, :math:`8704`, :math:`3384`, :math:`38922`. Sau đó mình decrypt ra flag. Ở đây mình compile với flag ``-O3`` và ``openmp`` vì mình không có nhiều kinh nghiệm dùng GCC lắm. :))) Code cũng sẽ chạy nhanh hơn nếu sử dụng các flag khác, cũng như C++ khác như 11, ...

Lệnh compile:

.. code-block:: bash

    g++ -O3 findkey.cpp -o findkey -fopenmp

Cuối cùng chúng ta giải mã với file :download:`decrypt.cpp <lithium-stearate/decrypt.cpp>`.

Mình dành hẳn một phần cho một bài vì bài này khá dài và phức tạp.

Đây cũng là bài viết đầu tiên của mình về một phương pháp tấn công cực kì phổ biến là differential attack (phá mã vi sai).

tetraethyllead
==============

Đây là một cipher sử dụng mô hình Feistel để mã hóa. Mô hình Feistel thường xuyên bị tấn công theo phương pháp differential, có thể kể đến như: DES, GOST, hay các phiên bản nhỏ hơn của chúng.

Do đó yêu cầu chống lại differential attack (cũng như người anh em khác của nó là linear attack) trở thành tiêu chuẩn để xây dựng block cipher hiện nay.

Mô hình Feistel
---------------

Trong mô hình Feistel, mỗi block của plaintext sẽ được chia đôi thành hai nửa trái phải - :math:`P = L_0 \Vert R_0`.

Ở bài này, plaintext có :math:`8` bytes và key cũng có :math:`8` bytes.

Trong mô hình Feistel chuẩn, ở mỗi vòng :math:`i+1`, sẽ thực hiện biến đổi sau:

.. math:: L_{i+1} = R_i, \quad R_{i+1} = L_i \oplus F(R_i, K_{i+1}).

Trong đó:

- :math:`K_{i+1}` là khóa ở vòng :math:`i+1` với :math:`i = 0, 1, \ldots`
- :math:`F` được gọi là round function. Hàm :math:`F` phụ thuộc vào cipher là loại nào. Ví dụ thuật toán DES thì :math:`F` là các phép biến đổi Expand, P-box và S-box. Hoặc đối với thuật toán GOST thì :math:`F` gồm cộng modulo :math:`2^{32}`, S-box và dịch :math:`11` bit sang trái.

Ở mô hình Feistel bên trên (cũng là mô hình chuẩn) thì hàm :math:`F` cố định cho mỗi vòng. Tuy nhiên ở bài này thì round function ở mỗi vòng khác nhau. Cụ thể thì ở vòng một dùng S-box `r2`, ở vòng thứ hai là S-box `r1`, các vòng sau thì dùng hàm `r345`.

Mình có thể viết quá trình biến đổi như sau:

+----------------+-----------------------------------------------+----------------------------------------------------------------+
| Vòng :math:`1` | :math:`L_1 = R_0`                             | :math:`R_1 = L_0 \oplus r_2(R_0, S_2)`                         |
+----------------+-----------------------------------------------+----------------------------------------------------------------+
| Vòng :math:`2` | :math:`L_2 = R_1`                             | :math:`R_2 = L_1 \oplus r_1(R_1, S_1)`                         |
+----------------+-----------------------------------------------+----------------------------------------------------------------+
| Vòng :math:`3` | :math:`L_3 = R_2`                             | :math:`R_3 = L_2 \oplus r_{345}(R_2, k_2, 3)`                  |
+----------------+-----------------------------------------------+----------------------------------------------------------------+
| Vòng :math:`4` | :math:`L_4 = R_3`                             | :math:`R_4 = L_3 \oplus r_{345}(R_3, k_2, 4)`                  |
+----------------+-----------------------------------------------+----------------------------------------------------------------+
| Vòng :math:`5` | :math:`L_5 = R_4`                             | :math:`R_5 = L_4 \oplus r_{345}(R_4, k_1 \oplus k_2, 5)`       |
+----------------+-----------------------------------------------+----------------------------------------------------------------+
| Vòng :math:`6` | :math:`L_6 = R_5`                             | :math:`R_6 = L_5 \oplus r_{345}(R_5, k_1, 6)`                  |
+----------------+-----------------------------------------------+----------------------------------------------------------------+
| Vòng :math:`7` | :math:`L_7 = L_6 \oplus r_{345}(R_6, k_2, 7)` | :math:`R_7 = R_6 \oplus L_7 = R_6 \oplus r_{345}(R_6, k_2, 7)` |
+----------------+-----------------------------------------------+----------------------------------------------------------------+

Lưu ý rằng vòng cuối hơi khác một tí.

Differential attack
-------------------

Differential là gì???

**Định nghĩa.** Xét hàm :math:`S` từ :math:`\mathbb{F}_2^n` tới :math:`\mathbb{F}_2^m`. Với mỗi cặp vector :math:`\boldsymbol{a}, \boldsymbol{b} \in \mathbb{F}_2^n` thì ta nói :math:`\boldsymbol{a} \oplus \boldsymbol{b}` là **input differential** và :math:`S(\boldsymbol{a}) \oplus S(\boldsymbol{b})` là **output differential** ứng với hàm :math:`S`.

Hàm :math:`S` thường là các S-box trong block cipher. Các S-box thường không tuyến tính, nghĩa là ta không có :math:`S(\boldsymbol{a} \oplus \boldsymbol{b}) = S(\boldsymbol{a}) \oplus S(\boldsymbol{b})`.

Differential dựa trên quan sát rằng khi :math:`\boldsymbol{a} \oplus \boldsymbol{b}` cố định thì output differential :math:`S(\boldsymbol{a}) \oplus S(\boldsymbol{b})` phân bố không đều. Giả sử mình có S-box như sau:

.. math:: 
    
    \begin{array}{|c|c|c|c|c|c|c|c|c||c|c|c|c|c|c|c|c|}
        \hline
        x & 0 & 1 & 2 & 3 & 4 & 5 & 6 & 7 & 8 & 9 & 10 & 11 & 12 & 13 & 14 & 15\\ \hline
        S(x) & 3 & 14 & 1 & 10 & 4 & 9 & 5 & 6 & 8 & 11 & 15 & 2 & 13 & 12 & 0 & 7 \\ \hline
    \end{array}

Nếu mình duyệt qua tất cả cặp :math:`\boldsymbol{a}, \boldsymbol{b} \in \mathbb{F}_2^4` thì mình sẽ có quan sát sau:

- Nếu input vi sai là :math:`0` thì output vi sai là :math:`0` với xác suất :math:`1`.
- Nếu input vi sai là :math:`1` thì output vi sai là :math:`13` với xác suất :math:`6 / 16`.
- Nếu input vi sai là :math:`4` thì output vi sai là :math:`7` với xác suất :math:`6 / 16`.
- Nếu input vi sai là :math:`8` thì output vi sai là :math:`5` với xác suất :math:`6 / 16`.
- Nếu input vi sai là :math:`15` thì output vi sai là :math:`14` với xác suất :math:`6 / 16`.

Đây là những output differential với **xác suất cao nhất** ứng với mỗi input differential cố định :math:`\boldsymbol{a} \oplus \boldsymbol{b}`.

Điều đó có nghĩa là cứ trung bình :math:`16` cặp :math:`\boldsymbol{a} \oplus \boldsymbol{b}` cho kết quả là :math:`1` thì có :math:`6` cặp cho output differential là :math:`13`.

Tận dụng điều này, chúng ta sẽ giải bài tetraethyllead.

Giả sử :math:`(P, C)` và :math:`(P', C')` là hai cặp plaintext-ciphertext sao cho khi input differential :math:`P \oplus P'` cố định thì xác suất xảy ra của output differential :math:`C \oplus C'` cao nhất. Khi tìm được input và output differential như vậy, ta mã hóa nhiều plaintext khác nhau và khả năng (xác suất) xuất hiện ciphertext tương ứng thỏa mãn differential đó sẽ cao.

Giả sử :math:`P = (L_0, R_0)` và :math:`P' = (L'_0, R'_0)` là hai nửa trái phải tương ứng với :math:`P` và :math:`P'`.

Đặt :math:`\Delta L_{in} = L_0 \oplus L'_0` và :math:`\Delta R_{in} = R_0 \oplus R_0` là input differential trước khi mã hóa.

Đặt :math:`\Delta L_{out} = L_7 \oplus L'_7` và :math:`\Delta_{in} = R_7 \oplus R'_7` là output differential sau khi mã hóa.

Chúng ta sẽ đi qua từng hàm để xem với input-output differential nào thì khả năng xảy ra là cao nhất.

Differential vòng 1
-------------------

Sau vòng :math:`1` ta có:

- :math:`L_1 = R_0` và :math:`R_1 = L_0 \oplus r_2(R_0, S_2)`.
- :math:`L'_1 = R'_0` và :math:`R'_1 = L'_0 \oplus r_2(R'_0, S_2)`.

Khi đó differential ở vòng :math:`1` là:

.. math:: 

    & \Delta L_1 = L_1 \oplus L'_1 = R_0 \oplus R'_0 \\
    & \Delta R_1 = R_1 \oplus R'_1 = L_0 \oplus L'_0 \oplus r_2(R_0, S_2) \oplus r_2(R'_0, S_2).

Như vậy :math:`\Delta R_1` phụ thuộc vào vi sai của hàm :math:`r_2`.

.. code-block:: python

    def r2(i, box):
        out = []

        i = long_to_bytes(i)

        for byte in i:
            out.append(box[byte])
            
        for idx in range(len(out) - 2, -1, -1):
            out[idx] ^= out[idx + 1]

        return bytes_to_long(b"".join([long_to_bytes(l) for l in out]))

Giả sử bốn bytes đầu vào của :math:`r_2` là :math:`a \Vert b \Vert c \Vert d`. Tiếp theo ta thay thế bốn bytes này bởi giá trị S-box của nó là :math:`S_2(a) \Vert S_2(b) \Vert S_2(c) \Vert S_2(d)`. Vòng lặp thứ hai XOR chồng các bytes lên nhau để có kết quả:

.. math:: S_2(a) \oplus S_2(b) \oplus S_2(c) \oplus S_2(d) \Vert S_2(b) \oplus S_2(c) \oplus S_2(d) \Vert S_2(c) \oplus S_2(d) \Vert S_2(d).

Như vậy nếu :math:`R_0 = a \Vert b \Vert c \Vert d` và :math:`R'_0 = a' \Vert b' \Vert c' \Vert d'` thì:

.. math:: 

    r_2(R_0, S_2) \oplus r_2(R_0', S_2) = & S_2(a) \oplus S_2(b) \oplus S_2(c) \oplus S_2(d) \oplus S_2(a') \oplus S_2(b') \oplus S_2(c') \oplus S_2(d') \\ 
    \Vert & S_2(b) \oplus S_2(c) \oplus S_2(d') \oplus S_2(b') \oplus S_2(c') \oplus S_2(d') \\ 
    \Vert & S_2(c) \oplus S_2(d) \oplus S_2(c') \oplus S_2(d') \\ 
    \Vert & S_2(d) \oplus S_2(d')

Dễ thấy rằng nếu chúng ta chọn :math:`d = d'` thì byte cuối triệt tiêu.

Tiếp theo chọn :math:`c = c'` thì byte kế cuối cũng triệt tiêu.

Tiếp theo chọn :math:`b = b'` thì byte thứ ba (từ phải sang trái) cũng triệt tiêu.

Khi đó vi sai sẽ là 

.. math:: r_2(R_0, S_2) \oplus r_2(R_0', S_2) = S_2(a) \oplus S_2(a') \Vert 00 \Vert 00 \Vert 00.

Bằng một cách *ảo ma* nào đó thì output differential :math:`S_2(a) \oplus S_2(a') = 0x80` có xác suất xảy ra cao nhất khi input differential là :math:`0x80`. Cái này writeup nói nhưng chúng ta cũng có thể kiểm tra phân bố vi sai của :math:`r_2`.

Đi ngược lên trên thì :math:`a \Vert b \Vert c \Vert d \oplus a' \Vert b' \Vert c' \Vert d' = 80 \Vert 00 \Vert 00 \Vert 00`. Đây chính là vi sai cho :math:`R_0 \oplus R_0'`.

Như vậy :math:`\Delta L_1 = 0x80000000` (với xác suất là :math:`1`) và :math:`\Delta R_1 = L_0 \oplus L_0' \oplus 0x80000000` (với xác suất cao).

Differential vòng 2
-------------------

Tương tự, đối với :math:`r_1` chúng ta cũng dùng phương pháp tương tự.

Sau vòng :math:`2` ta có:

- :math:`L_2 = R_1` và :math:`R_2 = L_1 \oplus r_1(R_1, S_1)`;
- :math:`L'_2 = R'_1` và :math:`R'_2 = L'_1 \oplus r_1(R'_1, S_1)`.

Khi đó differential ở vòng :math:`2` là:

.. math:: \Delta L_2 = L_2 \oplus L'_2 = R_1 \oplus R'_1 = L_0 \oplus L_0' \oplus 0x80000000.
 
với xác suất cao.

Tương tự

.. math:: \Delta R_2 = R_2 \oplus R'_2 = L_1 \oplus L'_1 \oplus r_1(R_1, S_1) \oplus r_1(R'_1, S_1) = 0x80000000 \oplus r_1(R_1, S_1) \oplus r_1(R'_1, S_1).

Khi này, :math:`R_1 \oplus R_1'` rất khó kiểm soát nên chúng ta sẽ khiến :math:`R_1 = R_1'`. Khi đó :math:`r_1(R_1, S_1) \oplus r_1(R_1', S_1) = 00` với xác suất bằng :math:`1`.

Nếu :math:`R_1 = R_1'` thì quay ngược lên trên, :math:`\Delta R_1 = 00 = L_0 \oplus L_0' \oplus 0x80000000` nên :math:`L_0 \oplus L_0' = 0x80000000`.

Như vậy mình đã tìm được input differential cho cả hàm mã hóa là :math:`L_0 \oplus L_0' = 0x80000000` và :math:`R_0 \oplus R_0' = 0x80000000`.

Lúc này, differential ở vòng :math:`2` có xác suất xảy ra cao nhất là :math:`L_2 \oplus L_2' = 0x00000000` và :math:`R_2 \oplus R_2' = 0x80000000`.

Tiếp theo, mình cần biết output differential nào của toàn bộ hàm ``encrypt`` sẽ có khả năng xảy ra nhất đối với input differential này.

.. _ham_z345:

Hàm ``z345``
-------------------

.. code-block:: python

    def r345(word, k, rnum):
        word ^= rrot(word, -463 + 439 * rnum + -144 * rnum**2 + 20 * rnum**3 - rnum**4) ^ lrot(word, 63 + -43 * rnum + 12 * rnum**2 + -rnum**3)

        word = (4124669716 + word * bytes_to_long(k))**3

        word ^= word << 5
        word ^= word << 5

        word ^= rrot(word, -463 + 439 * rnum + -144 * rnum**2 + 20 * rnum**3 - rnum**4) ^ lrot(word, 63 + -43 * rnum + 12 * rnum**2 + -rnum**3)

        return rrot(word, -504 + 418 * rnum -499 * rnum**2 + -511 * rnum**3 + 98 * rnum**4) & 0xffffffff

Khi thay các giá trị ``rnum`` vào thì mình thấy có :math:`3` vòng ``rrot`` và ``lrot`` ngược nhau (``rrot(word, 17)`` và ``lrot(word, 15)`` trên :math:`32` bit) nên ở những vòng này ``rrot`` và ``lrot`` sẽ triệt tiêu nhau do đa thức.

Tiếp theo, ``word ^= word << 5`` sẽ không làm thay đổi differential :math:`0x80`. Lấy ví dụ với :math:`8` bit :math:`\bar{a} = a_0 a_1 a_2 a_3 a_4 a_5 a_6 a_7` và :math:`\bar{b} = b_0 b_1 b_2 b_3 b_4 b_5 b_6 b_7`. Giả sử :math:`\bar{a} \oplus \bar{b} = 0x80` thì:

.. math:: 

    \bar{a} \oplus (\bar{a} << 5) \oplus \bar{b} \oplus (\bar{b} << 5) = & a_0 a_1 a_2 a_3 a_4 a_5 a_6 a_7 \oplus a_5 a_6 a_7 0 0 0 0 0 \\ \oplus & b_0 b_1 b_2 b_3 b_4 b_5 b_6 b_7 \oplus b_5 b_6 b_7 00000 \\ = & \underbrace{(a_0 a_1 a_2 a_3 a_4 a_5 a_6 a_7 \oplus b_0 b_1 b_2 b_3 b_4 b_5 b_6 b_7)}_{0x80} \\ \oplus & \underbrace{(a_5 a_6 a_7 00000 \oplus b_5 b_6 b_7 00000)}_{0x00} = 0x80.

Cuối cùng, phép nhân modulo :math:`2^{32}` có :math:`50\%` duy trì differential :math:`0x80000000` và do đó differential này vẫn có xác suất cao cho cả ``z345``.

Giải
-------------------

Chiến thuật để giải bài này là:

- Gửi lên các cặp plaintext sao cho :math:`\Delta L_{in} = 0x80000000` và :math:`\Delta R_{in} = 0x80000000`.
- Nhận các cặp ciphertext tương ứng thỏa mãn :math:`\Delta L_{out} \oplus R_{out} = 0x80000000`.

Các cặp plaintext, ciphertext như trên sẽ giúp ta khôi phục lại khóa.

**Note.** Để thuận tiện thì mình sẽ cố định khóa trong `server.py` và chỉ cần tìm ra khóa là xong. Ở trong giải thì sau khi request đủ :math:`1024` lần encrypt server cũng không đặt timeout nên chúng ta có thể để script chạy bao lâu tùy ý.

File :download:`solve.py <tetraethyllead/solve.py>` sau đây tương tác với ``server.py`` để lấy về các cặp plaintext, ciphertext thỏa mãn điều kiện trên.

Sau đó sử dụng thư viện SHA256 từ project `SHA256 <https://github.com/System-Glitch/SHA256>`_ (gồm file ``SHA256.h`` và ``SHA256.cpp``).

Chúng ta cần viết :download:`solve.h <tetraethyllead/solve.h>` chứa định nghĩa các hàm sẽ dùng để tìm khóa.

Đầu tiên chúng ta sẽ khôi phục ``k2`` đi ngược từ ciphertex lên. Chúng ta nhận các khóa thỏa mãn :math:`\Delta L_6 \oplus \Delta R_6 = 0x80000000` (vòng :math:`6`). Để tìm ``k2`` thì hàm ``main`` sẽ là:

.. code-block:: cpp

    int main()
    {    
        std::vector<uint32_t> key2 = bruteforce_k2();
        for (int i = 0; i < key2.size(); i++)
            std::cout << std::hex << key2[i] << std::endl;
        return 0;
    }

Sau đó với mỗi ``k2`` chúng ta bruteforce các ``k1`` và kiểm tra ``k = k1 || k2`` nào sẽ encrypt đúng. Ở đây do mình đã cố định khóa ở ``server.py`` nên mình biết ``k2`` nào là đúng để tiết kiệm thời gian viết lại writeup. Sau đó thì chỉ cần bruteforce ``k1`` thôi.

.. code-block:: cpp

    int main()
    {
        uint8_t k2[] = { 0xef, 0x13, 0x37, 0xff };
        get_sbox(k2, sbox2);
        
        uint64_t p = 2194090266659289430ULL;
        uint64_t c = 5313144679078469543ULL;

        #pragma omp for
        for (uint64_t k1 = 0; k1 < 0xffffff; k1++)
        {
            uint64_t key = (k1 << 32) | 0xef1337ff;
            if (encrypt(p, key) == c)
            {
                std::cout << "Found key: " << std::hex << key << std::endl;
            }
        }
        return 0;
    }

Cám ơn các bạn đã đọc writeup dài lê thê của mình.
