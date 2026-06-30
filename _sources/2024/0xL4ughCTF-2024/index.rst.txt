0xL4ugh CTF 2024
****************

RSA_GCD
=======

.. admonition:: chall.py
    :class: dropdown
    
    .. code-block:: python

        import math
        from Crypto.Util.number import *
        from secret import flag,p,q
        from gmpy2 import next_prime
        m = bytes_to_long(flag.encode())
        n=p*q


        power1=getPrime(128)
        power2=getPrime(128)
        out1=pow((p+5*q),power1,n)
        out2=pow((2*p-3*q),power2,n)
        eq1 = next_prime(out1)

        c = pow(m,eq1,n)


        with open('chall2.txt', 'w') as f:
            f.write(f"power1={power1}\npower2={power2}\neq1={eq1}\nout2={out2}\nc={c}\nn={n}")

Đề bài cho mình thuật toán RSA với các tham số gồm ``power1``, ``power2``, ``eq1``, ``out2``, ``c`` và ``n``.

Trong đó ``c`` là ciphertext RSA với modulo là ``n``, số mũ là ``eq1``.

Mình đã có ``out2`` nhưng chưa có ``out1``. Vì ``eq1`` là số nguyên tố tiếp theo kể từ ``out1``, nếu mình gọi ``eq0`` là số nguyên tố trước ``eq1`` thì ``out1`` sẽ nằm trong khoảng ``[eq0, eq1]`` và mình sẽ bruteforce ``out1`` trong khoảng này.

Để tìm :math:`p` và :math:`q`, do :math:`o_1 = (p+5q)^{e_1} \pmod n` và :math:`o_2 = (2p - 3q)^{e_2} \pmod n` (ở đây :math:`o_1` và :math:`o_2` tương ứng ``out1`` và ``out2``, :math:`e_1` và :math:`e_2` tương ứng ``power1`` và ``power2``).

Vì :math:`o_1^{e_2} = (p+5q)^{e_1 e_2} \pmod n`, mà :math:`q \mid n` nên

.. math:: o_1^{e_2} = (p+5q)^{e_1 e_2} \pmod q = p^{e_1 e_2} \pmod q.

Thêm một bước nữa là

.. math:: o_1^{e_2} \cdot 2^{e_1 e_2} = (2p)^{e_1 e_2} \pmod q.

Tương tự, :math:`o_2^{e_1} = (2p)^{e_1 e_2} \pmod q`.

Như vậy :math:`o_1^{e_2} \cdot 2^{e_1 e_2} - o_2^{e_1}` chia hết cho :math:`q` nên có ước chung lớn nhất với :math:`n` bằng :math:`q`. Từ đó mình tìm được :math:`q` và :math:`p` và decrypt plaintext. Các bạn có thể xem code giải ở :download:`đây <solve_rsa_gcd.py>`.

Poisson
=======

Đề bài mình để ở :download:`đây <chall_poisson.py>`.            

Đề bài cho mình đường cong elliptic với điểm generator :math:`G`. Flag được biểu diễn bằng dãy nhị phân `my_priv`.

Ở mỗi vòng lặp ở vị trí `count`, chương trình sẽ

- sinh random số :math:`k`;
- tính điểm :math:`Q = my\_priv * G`;
- random điểm :math:`M` trong elliptic;
- tính điểm :math:`C_1 = k * G`;
- tính điểm :math:`C_2 = M + k * Q`;
- tính `new_priv = poisson(my_priv, ind)` là đảo bit ở vị trí `ind`. Ví dụ, với dãy nhị phân `111001` và `ind` là :math:`2` thì kết quả là `110001` (vị trí thứ hai là bit :math:`1` đổi thành bit :math:`0`);
- tính điểm :math:`dec = C_2 - new\_priv * C_1`.

Mình để ý rằng, khi đảo một bit thì lúc trừ số ban đầu và số sau khi đảo sẽ ra lũy thừa của :math:`2` (có thể là số âm). Với ví dụ ở trên, `111001 - 110001 = 1000` chính là :math:`2^3`.

Như vậy, biến đổi một chút mình có

.. math:: 
    
    dec = & C_2 - new\_priv * C_1 = M + k * Q - new\_priv * k * G \\
    = & M + k * my\_priv * G - k * new\_priv * G \\
    \Leftrightarrow dec - M = & (my\_priv - new\_priv) * k * G \\ = & (my\_priv - new\_priv) * C_1.
    
Do đó, ở vị trí :math:`i`, nếu :math:`dec - M = 2^i * C_1` thì bit ở vị trí :math:`i` là :math:`1` (do :math:`1` đổi thành :math:`0` nên số lúc trước lớn hơn số lúc sau). Tương tự, nếu :math:`dec - M = -2^i * C_1` thì bit ở vị trí :math:`i` là :math:`0`.

Code giải mình để ở :download:`đây <solve_poisson.py>`.

L4ugh
=====

Đề gồm hai file là :download:`challenge.py <L4ugh/challenge.py>` và :download:`utils.py <L4ugh/utils.py>`.        

Ở bài này, đầu tiên chương trình sinh số nguyên tố :math:`d` có :math:`666` bit sao cho :math:`333` bit đầu cũng là số nguyên tố.

Đặt :math:`d = d_e \cdot 2^{333} + d_g`, tương ứng trong chương trình :math:`d_e` là ``d_evil`` còn :math:`d_g` là ``d_good``.

Chương trình cho phép chọn một trong ba option. Mình sẽ dùng option :math:`1` để tìm :math:`d_e`, dùng option :math:`2` để tìm :math:`d_g`. Để sử dụng option :math:`3` mình cần cung cấp :math:`d` hoàn chỉnh.

1. Tìm d "good"
---------------

Phần này dễ hơn nên mình làm trước. Từ ``d_good`` và :math:`10` số nguyên tố sinh ngẫu nhiên, mình cần nhập số `user_input` nào đó không nhiều hơn :math:`333` bit và chương trình sẽ trả lại mảng :math:`d_g \cdot input + p_i`, :math:`0 \leqslant i \leqslant 9` và :math:`p_i` là số nguyên tố.

Mình muốn :math:`d_g` và :math:`p_i` độc lập với nhau, nghĩa là càng ít liên quan nhau càng tốt. Khi đó mình sẽ có lợi thế trích xuất thông tin hơn. Để ý rằng do :math:`p_i` là số nguyên tố :math:`333` bit nên nếu chọn :math:`input = 2^{333}` thì :math:`p_i` là :math:`333` bit thấp của kết quả và :math:`d_g` là :math:`333` bit cao của kết quả. Tuy nhiên :math:`2^{333}` có :math:`334` bit nên không được. Ở đây mình dùng trick lỏ là chọn :math:`input = 2^{333} - 1`.

Khi đó

.. math:: r_i = d_g \cdot (2^{333} - 1) + p_i = d_g \cdot 2^{333} + (p_i - d_g).

Lúc này :math:`d_g` thực sự là :math:`333` bit cao của :math:`r_i` nhưng chỉ khi :math:`p_i - d_g > 0`. Từ :math:`10` phần tử của mảng mình có thể chọn ra vị trí mà :math:`r_i - d_g \cdot (2^{333} - 1)` là số nguyên tố. Khi đó mình lấy :math:`d_g` thôi.

.. code-block:: python

    from pwn import process, remote
    import json
    from Crypto.Util.number import isPrime
    from sage.all import *

    pr = process(["python", "challenge.py"])
    #pr = remote("20.55.48.101", 1337)
    pr.recvuntil(b'all input data is in json')

    pr.recvuntil(b'option:\t')
    pr.sendline(json.dumps({"option": "2"}).encode())

    pr.recvuntil(b"Enter your payload:\t")
    pr.sendline(str(2**333-1).encode())

    res = eval(pr.recvline().strip().decode()[7:])

    kres = [r // (2**333) for r in res]

    d_goods = [r - k * (2**333 - 1) for r, k in zip(res, kres)]
    d_good = None

    for r, k in zip(res, kres):
        d_ = r - k * (2**333 - 1)
        if isPrime(d_):
            d_good = k

    assert d_good != None
    print(f"d_good = {d_good}")

    d_good = 11676101755124723561993227185337871743077799520817686580225233864252891286503981386427236336665397269

2. Tìm d "evil"
---------------

Với :math:`d_e` là số nguyên tố, chương trình sinh các số :math:`N_i = p_i \cdot q_i` với :math:`p_i`, :math:`q_i` là các số nguyên tố và tính nghịch đảo :math:`e_i` của :math:`d_e` trong modulo :math:`\phi(N_i) = (p_i - 1) (q_i - 1)`.

Ta có :math:`e_i d_e \equiv 1 \pmod{\phi(N_i)}`, tương đương với

.. math:: e_i d_e - 1 = k \phi(N_i) = k_i (N_i - p_i - q_i + 1),

hay là

.. math:: k_i (p_i + q_i - 1) - 1 = k_i N_i - e_i d_e.

Do :math:`N_i`, :math:`e_i` là các số :math:`1024` bit, và :math:`d_e` là số :math:`333` bit nên suy ra :math:`k_i` cũng khoảng :math:`333` bit. Như vậy vế phải có :math:`1024+333` bit. Trong khi đó, vế trái sẽ có :math:`333+512` bit, nhỏ hơn nhiều so với vế phải. Điều này dẫn mình tới lattice.

Mình xây dựng lattice là ma trận sau

.. math:: 
    
    \begin{bmatrix}
        e_0 & e_1 & e_2 & 1 & 0 & 0 & 0 \\
        N_0 & 0 & 0 & 0 & 1 & 0 & 0 \\
        0 & N_1 & 0 & 0 & 0 & 1 & 0 \\
        0 & 0 & N_2 & 0 & 0 & 0 & 1
    \end{bmatrix}

thì khi nhân hàng đầu với :math:`-d_e`, nhân hàng hai với :math:`k_0`, hàng thứ ba với :math:`k_1` và hàng thứ tư với :math:`k_2` thì mình có vector ngắn trong lattice là

.. math:: \bm{v} = (k_0 (p_0 + q_0 - 1) - 1, \cdots, \cdots, -d_e, k_0, k_1, k_2).

Chạy LLL và lấy vị trí thứ ba trong vector ngắn (thêm giá trị tuyệt đối) là mình có :math:`d_e` rồi.

Nhưng mà khoan, không ra?

Nguyên nhân là vì các số hạng trong vector ngắn :math:`\bm{v}` không có cùng số bit. Ở trên mình đã nói :math:`k_i (p_i + q_i - 1) - 1` có :math:`333 + 512` bit, trong khi :math:`-d_e` có :math:`333` bit và :math:`k_i` cũng có :math:`333` bit. Do đó mình sẽ phải "scale" để chúng có số bit bằng nhau ở vector ngắn.

Quay ngược lên trên lattice, mình nhân thêm hệ số :math:`2^L` để đảm bảo khi nhân mỗi hàng với :math:`-d_e` và :math:`k_i` thì kết quả là vector ngắn :math:`\bm{v}` có số bit như nhau.

Lattice của mình lúc này sẽ là

.. math:: 
    
    \begin{bmatrix}
        e_0 & e_1 & e_2 & 2^{512} & 0 & 0 & 0 \\
        N_0 & 0 & 0 & 0 & 2^{512} & 0 & 0 \\
        0 & N_1 & 0 & 0 & 0 & 2^{512} & 0 \\
        0 & 0 & N_2 & 0 & 0 & 0 & 2^{512} \\
    \end{bmatrix}.

Vector ngắn lúc này là 

.. math:: \bm{v} = (k_0 (p_0 + q_0 - 1) - 1, \cdots, \cdots, -d_e \cdot 2^{512}, k_0 \cdot 2^{512}, k_1 \cdot 2^{512}, k_2 \cdot 2^{512}).

Như vậy mỗi phần tử trong :math:`\bm{v}` đều có :math:`512 + 333` bit rồi.

.. code-block:: python

    pr.recvuntil(b'option:\t')
    pr.sendline(json.dumps({"option": "1"}).encode())

    Ns = eval(pr.recvline().strip().decode()[3:])
    es = eval(pr.recvline().strip().decode()[3:])

    print([int(e).bit_length() for e in es])

    Mat = Matrix(ZZ, 4, 7)
    for i in range(3):
        Mat[0, i] = es[i]
    Mat[0, 3] = 2**512

    for i in range(3):
        Mat[i+1, i] = Ns[i]
        Mat[i+1, i+4] = 2**512

    N = Mat.LLL()

    d_evil = abs(N[0][3]) // 2**512

    assert isPrime(d_evil)

    print(f"d_evil = {d_evil}")


Output của đoạn code trên là:

.. code-block:: 

    [1022, 1021, 1022]
    d_evil = 9164192793237501841603085694166740261176767425415039425767329941821517155591215118383740675363639829

3. CBC Oracle
-------------

Tới đây thì dễ thở hơn rồi! Đầu tiên mình encrypt một lần và nhận về ciphertext. Chúng ta sẽ flip phần ciphertext để khi decrypt ra sẽ có đoạn ``isadmin: true``.

Giả sử ciphertext gồm các block :math:`C_0`, :math:`C_1`, ... Plaintext gồm các block tương ứng là :math:`P_0`, :math:`P_1`, ...

Giả sử tiếp, đoạn ``isadmin: false`` nằm trong block :math:`P_i`. Quá trình giải mã để tìm :math:`P_i` theo công thức :math:`P_i = C_{i-1} \oplus \text{DEC}(C_i)`.

Do mình muốn :math:`P_i'` chứa ``isadmin: true`` (thêm dấu cách ở cuối để số ký tự trước và sau khi đổi bằng nhau). Khi đó mình sẽ đổi

.. math:: C_{i-1}' = C_{i-1} \oplus \text{???isadmin: true ???}.
    
Các block ciphertext còn lại giữ nguyên.

Mình mang ciphertext mới đi decrypt thì sẽ nhận được lỗi do block đầu tiên khi decrypt ra không đúng (khác ciphertext ban đầu nên khi XOR với :math:`IV` không ra).

.. code-block:: python

    d = d_evil * 2**333 + d_good

    pr.recvuntil(b'option:\t')
    pr.sendline(json.dumps({"option": "3", "d": int(d)}).encode())

    pr.recvuntil(b'2.sign in')
    pr.sendline(json.dumps({"option": "1", "user": "user"}).encode())

    data = pr.recvline().strip().decode()
    data = data.replace("\'", "\"")

    print(data, len(data))

    idx = data.index("False")

    ctx = pr.recvline().strip().decode()

    iv, ct = ctx[:32], ctx[32:]
    iv, ct = bytes.fromhex(iv), list(bytes.fromhex(ct))

    tmp = [int(i).__xor__(int(j)) for i, j in zip(b'False', b'True ')]
    for i, j in zip(range(idx, idx + len(tmp)), range(len(tmp))):
        ct[i - 16] = int(ct[i - 16]).__xor__(int(tmp[j]))

    pr.recvuntil(b'option:\t')
    pr.sendline(json.dumps({"option": "3", "d": int(d)}).encode())

    pr.recvuntil(b'2.sign in')
    pr.sendline(json.dumps({"option": "2", "token": iv.hex() + bytes(ct).hex()}).encode())

    test = pr.recvline().strip().decode()

    {"id": 190504, "isadmin": False, "username": "user"} 52


Do đó mình cũng phải sửa :math:`IV` để khi decrypt :math:`C_0` và xor với :math:`IV'` thì sẽ ra được :math:`P_0` ban đầu.

Để ý rằng :math:`P_0' = IV \oplus \text{DEC}(C_0')` nên :math:`P_0 = P_0' \oplus IV \oplus P_0 \oplus \text{DEC}(C_0')`, suy ra :math:`IV' = P_0' \oplus IV \oplus P_0`.

.. code-block:: python

    assert test[:17] == 'Unpadding Error: '

    test = test[19:-1]

    def convert(st: str):
        result = []
        i = 0
        while i < len(st):
            if st[i:i+2] != "\\x":
                result.append(ord(st[i]))
                i += 1
            else:
                result.append(int(st[i+2:i+4], 16))
                i += 4
        return bytes(result)

    pti = convert(test) # P_0'
    pti = bytes(p_ ^ d_ for p_, d_ in zip(pti, data[:16].encode())) # XOR with P_0
    pti = bytes(p_ ^ i_ for p_, i_ in zip(pti, iv)) # XOR with IV

    pr.recvuntil(b'option:\t')
    pr.sendline(json.dumps({"option": "3", "d": int(d)}).encode())

    pr.recvuntil(b'2.sign in')
    pr.sendline(json.dumps({"option": "2", "token": pti.hex() + bytes(ct).hex()}).encode())

    pr.recvline()
    pr.recvline()
    pr.recvline()

    pr.recvuntil(b"2.Exit\n")
    pr.sendline(json.dumps({"option": "1"}).encode())

    print(pr.recvline())

    pr.close()

    # b'0xL4ugh{cryptocats_B3b0_4nd_M1ndfl4y3r}\n'

    # b'0xL4ugh{Fak3_Fl@g}\n'

Một vấn đề là đoạn ``isadmin: false`` phải nằm cùng block nếu không sẽ không decrypt ra, việc này may rủi tùy vào :math:`x` được random như nào. Một vấn đề khác là **bytes trong string** nên mình phải viết hàm extract chuỗi byte đó ra nên không chắc sẽ tránh được lỗi.

Nhưng chạy tới một lúc nào đó sẽ có flag thôi :)))

Writeup của mình đến đây là hết. Cám ơn các bạn đã đọc.
