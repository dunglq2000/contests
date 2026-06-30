Amateurs CTF 2023
*****************

Minimalaestic
=============

Đề bài ở :download:`aes.py <Minimalaestic/aes.py>`.

Phân tích hiện trường
---------------------

Đây là một bài AES nhưng trên ma trận :math:`2 \times 2`. Ma trận đầu vào có dạng

.. math:: \begin{pmatrix}s_{00} & s_{01} \\ s_{10} & s_{11}\end{pmatrix}.

Các động tác cơ bản giống với AES gốc, bao gồm: add round key, shift rows, mix columns và sub bytes. Đối với vòng cuối sử dụng một biến thể của sub byte, shift rows và add round key. Ở bài này có 100 vòng biến đổi bình thường và 1 vòng cuối sử dụng các biến thể trên.

Sub Bytes và Final Sub Bytes
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

SBox được sử dụng trong bài là SBox của AES gốc. Do đó mình cũng không nghĩ rằng sẽ khai thác được gì ở đây. Ở đây có một điều mình cần nhớ là Sub Bytes biến đổi trên cột đầu, và Final Sub Bytes biến đổi trên cột sau.

Đối với Sub Bytes thì

.. math:: \begin{pmatrix} s_{00} & s_{01} \\ s_{10} & s_{11} \end{pmatrix} \to \begin{pmatrix} s_{00} & S(s_{01}) \\ s_{10} & S(s_{11}) \end{pmatrix}.

Đối với Final Sub Bytes thì

.. math:: \begin{pmatrix} s_{00} & s_{01} \\ s_{10} & s_{11} \end{pmatrix} \to \begin{pmatrix} S(s_{00}) & s_{01} \\ S(s_{10}) & s_{11} \end{pmatrix}.

Shift Rows và Final Shift Rows
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Đối với Shift Rows thay đổi vị trí 2 bytes ở cột (?) đầu.

.. math:: \begin{pmatrix} s_{00} & s_{01} \\ s_{10} & s_{11}\end{pmatrix} \to \begin{pmatrix}s_{10} & s_{01} \\ s_{00} & s_{11}\end{pmatrix}.

Đối với Final Shift Rows thay đổi vị trí 2 bytes ở cột (?) sau.

.. math:: \begin{pmatrix} s_{00} & s_{01} \\ s_{10} & s_{11}\end{pmatrix} \to \begin{pmatrix} s_{00} & s_{11} \\ s_{10} & s_{01} \end{pmatrix}.

Mình thấy rằng phép biến đổi ngược đối với shift rows và final shift rows cũng là chính nó.

Mix Columns
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Đối với Mix Columns, cột đầu mới sẽ là cột đầu cũ XOR với cột sau.

.. math:: \begin{pmatrix} s_{00} & s_{01} \\ s_{10} & s_{11} \end{pmatrix} \to \begin{pmatrix} s_{00} \oplus s_{01} & s_{01} \\ s_{10} \oplus s_{11} & s_{11} \end{pmatrix}.

Tương tự shift rows, phép biến đổi ngược của mix columns cũng là chính nó.

Add Round Keys
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Phép Add Round Keys ở bài này khá thú vị (mặc dù mình cũng không khai thác từ đó).

.. code-block:: python

    def add_round_key(s, k):
        for i in range(2):
            for j in range(2):
                s[i][j] ^= k[k[k[k[i*2+j]%4]%4]%4]

Đối với final add round keys thì chỉ thực hiện phép XOR trên cột sau.

Okay, tới đây thì việc phân tích mã hóa của bài này đã tạm xong và mình cũng không thấy điểm nào có thể dùng để khai thác (hoặc chưa thấy). Điều làm mình quan tâm là hàm ``schedule_key``.

Key Schedule
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: python

    def schedule_key(k):
        for i in range(4):
            for j in range(2*ROUNDS):
                k[i] = pow(pow(sbox[sbox[sbox[((((k[i] << 4) ^ k[i]) << 4) ^ k[i]) % 256]]], pow(k[i], k[i]), 256), 
                    pow(sbox[k[i]], sbox[k[i]]), 
                    256)

    def final_schedule(k):
        for i in range(4):
            k[i] = sbox[k[i]]

Hàm sinh khóa con khá lạ. Do đó mình thử in ra khóa con ở các vòng với một chút điều chỉnh ở hàm ``encrypt`` với các khóa được random.

.. code-block:: python

    def encrypt(p, k):
        ciphertext = b""
        for i in split_blocks(p):
            key = k.copy()
            i = bytes2matrix(i)
            add_round_key(i, key)
            for j in range(ROUNDS):
                schedule_key(key)
                print(f"{j}, {key}")
                sub_bytes(i)
                shift_rows(i)
                mix_columns(i)
                add_round_key(i, key)
            final_schedule(key)
            print(f"100, {key}")
            final_sub(i)
            final_shift(i)
            final_add(i, key)
            ciphertext += matrix2bytes(i)
        return ciphertext

    pt = b"haha"
    for _ in range(1000):
        key = [random.choice(range(256)) for _ in range(4)]
        encrypt(pt, key)

Các khóa con trong các vòng từ 0 tới 99 đều có vẻ như nằm trong một tập hợp nhất định là :math:`\{ 0, 1, 175 \}`. Từ đó khóa con ở vòng 100 (vòng final) cũng nằm trong một tập hợp nhất định do đã đi qua hàm sbox (``final_schedule``) và kết quả là tập :math:`\{99, 121, 124 \}`.

Truy tìm đầu mối
----------------

Nơi cryptanalysis bắt đầu
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Chiến thuật của mình là tìm khóa trước khi đi vào vòng lặp với known-plaintext là format của flag. Chú ý rằng ở đây không cần phải tìm khóa ban đầu mà chỉ cần tìm khóa trước khi vào vòng lặp, tức là khóa tham gia vào phép XOR ``add_round_key`` đầu tiên.

.. code-block:: python

    def encrypt(p, k):
        ciphertext = b""
        for i in split_blocks(p):
            key = k.copy()
            i = bytes2matrix(i)
            add_round_key(i, key)
            #   Find intermediate key used in add_round_key #
            for j in range(ROUNDS):
                schedule_key(key)
                sub_bytes(i)
                shift_rows(i)
                mix_columns(i)
                add_round_key(i, key)
            final_schedule(key)
            final_sub(i)
            final_shift(i)
            final_add(i, key)
            ciphertext += matrix2bytes(i)
        return ciphertext

Để tìm khóa ở điểm được đánh dấu, mình sẽ đi ngược từ ciphertext lên. Mình bruteforce các khóa con dùng trong vòng lặp (:math:`3^4 = 81` trường hợp). Ứng với mỗi khóa con cho vòng lặp mình có một khóa con cho vòng cuối cùng (final). Kết hợp hai khóa đó và ciphertext mình sẽ tìm được state trước khi vào vòng lặp. Cuối cùng mình XOR kết quả đó cho known-plaintext thì sẽ được khóa ở điểm được đánh dấu.

Từ nhận xét bên trên, 100 vòng (0 tới 99) sử dụng cùng một khóa con, mình đặt là :math:`k_1`. Ở vòng final sử dụng một khóa con, mình đặt là :math:`k_2`. Quan hệ giữa chúng là ``k_2 = final_schedule(k_1)``.

Man-In-The-Middle
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Với mỗi block :math:`4` bytes ciphertext và known-plaintext tương ứng, mình đi ngược từ dưới lên để tìm key trung gian. Lưu ý rằng mình chỉ cần xây dựng bảng ``inv_sbox`` vì các phép biến đổi khác có phép biến đổi ngược là chính nó.

.. code-block:: python

    final_add(ciphertext, k2_)
    final_shift(ciphertext)
    inv_final_sub(ciphertext)
    for j in range(ROUNDS):
        add_round_key(ciphertext, k1_)
        mix_columns(ciphertext)
        shift_rows(ciphertext)
        inv_sub_bytes(ciphertext)

    pt = matrix2bytes(plaintext)
    ct = matrix2bytes(ciphertext)
    key = xor(pt, ct)

Với format flag là ``amateursCTF{`` có 12 bytes tương ứng 3 block, mình thực hiện biến đổi trên với 12 bytes ciphertext tương ứng. Với mỗi block mình sẽ tìm ra được tập hợp các key tương ứng với các :math:`k_1` (và :math:`k_2` tương ứng với :math:`k_1`). Sau đó mình giao các tập hợp key lại sẽ được key ban đầu.

Nói cách khác

.. code-block:: python

    candidates1 = set()
    candidates2 = set()
    candidates3 = set()

    for k1 in product(K1, repeat=4):
        k2 = final_schedule_(list(k1))

        k1_ = list(k1).copy()
        k2_ = list(k2).copy()

        # Phase 1
        plaintext = bytes2matrix(flag[:4])
        ciphertext = bytes2matrix(ctx[:4])
        final_add(ciphertext, k2_)
        final_shift(ciphertext)
        inv_final_sub(ciphertext)
        for j in range(ROUNDS):
            add_round_key(ciphertext, k1_)
            mix_columns(ciphertext)
            shift_rows(ciphertext)
            inv_sub_bytes(ciphertext)

        pt = matrix2bytes(plaintext)
        ct = matrix2bytes(ciphertext)
        key = xor(pt, ct)
        candidates1.add(bytes(key))
        
        # Phase 2
        plaintext = bytes2matrix(flag[4:8])
        ciphertext = bytes2matrix(ctx[4:8])
        final_add(ciphertext, k2)
        final_shift(ciphertext)
        inv_final_sub(ciphertext)
        for j in range(ROUNDS):
            add_round_key(ciphertext, k1_)
            mix_columns(ciphertext)
            shift_rows(ciphertext)
            inv_sub_bytes(ciphertext)
        
        pt = matrix2bytes(plaintext)
        ct = matrix2bytes(ciphertext)
        key = xor(pt, ct)
        candidates2.add(bytes(key))
        
        # Phase 3
        plaintext = bytes2matrix(flag[8:12])
        ciphertext = bytes2matrix(ctx[8:12])
        final_add(ciphertext, k2_)
        final_shift(ciphertext)
        inv_final_sub(ciphertext)
        for j in range(ROUNDS):
            add_round_key(ciphertext, k1_)
            inv_mix_columns(ciphertext)
            inv_shift_rows(ciphertext)
            inv_sub_bytes(ciphertext)
        
        pt = matrix2bytes(plaintext)
        ct = matrix2bytes(ciphertext)
        key = xor(pt, ct)
        candidates3.add(bytes(key))

    key = list(candidates1.intersection(candidates2).intersection(candidates3))
    print(key)

Kết quả khi giao ba tập hợp chỉ có đúng một key ``b'\x00**\x00'``. Quá tốt!!!

Ờ mà khoan, từ từ đã :)))) Có gì đó không đúng lắm. Cụ thể là khi mình encrypt hai block plaintext đầu thì nó không ra đúng ciphertext. Cụ thể hơn nữa, encrypt ra đúng ở vị trí 0 và 2, sai ở vị trí 1 và 3 cho mỗi block (?!?!).

Sửa chữa lỗi lầm
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Mình mất cả ngày để tìm lỗi sai nhưng thất bại. Và mình đã chuyển sang *tấn công cưỡng ép*. Vì encrypt đúng ở vị trí 0 và 2 còn sai ở vị trí 1 và 3 nên mình kết luận được là :math:`k_2` có vấn đề, tức là key ở bước ``final_add``.

Mình thử in ra :math:`k_1` và :math:`k_2` tương ứng với khóa tìm được bên trên ``b'\x00**\x00'``.

.. code-block:: python

    for k1 in product(K1, repeat=4):
        k2 = final_schedule_(list(k1))

        k1_ = list(k1).copy()
        k2_ = list(k2).copy()

        # Phase 1
        plaintext = bytes2matrix(flag[:4])
        ciphertext = bytes2matrix(ctx[:4])
        final_add(ciphertext, k2_)
        final_shift(ciphertext)
        inv_final_sub(ciphertext)
        for j in range(ROUNDS):
            add_round_key(ciphertext, k1_)
            mix_columns(ciphertext)
            shift_rows(ciphertext)
            inv_sub_bytes(ciphertext)

        pt = matrix2bytes(plaintext)
        ct = matrix2bytes(ciphertext)
        key = xor(pt, ct)
        candidates1.add(bytes(key))
        if bytes(key) == b'\x00**\x00':
            print(k1, k2)

Hai trường hợp có thể xảy ra cho cặp :math:`(k_1, k_2)` là :math:`([1, 0, 0, 1], [124, 99, 99, 124])` và :math:`([1, 0, 175, 1], [124, 99, 121, 124])`. Mình chỉ cần xét trường hợp 1 là được.

Khi nhìn vào hàm ``final_add`` thì mình biết chắc rằng ``k[k[k[k[i*2+1]]]`` chắc chắn nằm trong ``[124, 99]`` nên mình *bốc* đại :math:`k_2 = [124, 124, 124, 124]`, và nó đã thành công (????).

Hàm ``decrypt`` mình fix cứng :math:`k_1` và :math:`k_2` luôn, và decrypt ra toàn bộ flag ban đầu.

.. code-block:: python

    def decrypt(c, k):
        plaintext = b""

        for i in split_blocks(c):
            key = k.copy()
            k1, k2 = [1, 0, 0, 1], [124, 124, 124, 124]

            i = bytes2matrix(i)

            final_add(i, k2)
            final_shift(i)
            inv_final_sub(i)
            for j in range(ROUNDS):
                add_round_key(i, k1)
                mix_columns(i)
                shift_rows(i)
                inv_sub_bytes(i)

            plaintext += bytes(xor(matrix2bytes(i), key))
        return plaintext

    # b'amateursCTF{th1s_1s_wh4t_bad_k3y_sch3dul1ng_d03s_t0_a_p3rson_109bcd1f}\x02\x02.

Nếu bạn nhìn thấy được điểm sai nào đó trong bài làm của mình dẫn tới *tấn công cưỡng ép* thì có thể nói cho mình biết. Thực sự thì mình không biết mình đang lag chỗ nào :confused:

Owo Time Pad
=============

Đề bài ở file :download:`main.py <OwO Time Pad/main.py>`.

Bài này sẽ random một key có độ dài là số nguyên tố cùng nhau với độ dài của plaintext. Đặt :math:`l` là độ dài plaintext và :math:`n` là độ dài key. Chương trình tạo key mới bằng cách lặp lại key cũ :math:`l` lần, tương tự plaintext mới sẽ là plaintext cũ lặp lại :math:`n` lần. Chú ý rằng :math:`\gcd(l, n) = 1`, điều này rất quan trọng giải bài này.

Khi factor độ dài của ciphertext thì mình thấy có hai khả năng xảy ra của độ dài key là 32 hoặc 79. Mình giải với :math:`n = 79` (sai thì quay lại làm 32 :v).

Như một thói quen, để xử lý các bài toán với số lớn mình thường xem xét những trường hợp số nhỏ để xem mối liên hệ giữa chúng. 

Giả sử :math:`l = 5` và :math:`n =3`. Đặt key là :math:`\bm{k} = (k_0, k_1, k_2)` và :math:`\bm{P} = (p_0, p_1, p_2, p_3, p_4)`.

Khi đó ciphertext sẽ được ghép cặp XOR như sau

.. math:: 
    
    \left[\begin{array}{ccccccccccccccc}
    k_0 & k_1 & k_2 & k_0 & k_1 & k_2 & k_0 & k_1 & k_2 & k_0 & k_1 & k_2 & k_0 & k_1 & k_2 \\ 
    p_0 & p_1 & p_2 & p_3 & p_4 & p_0 & p_1 & p_2 & p_3 & p_4 & p_0 & p_1 & p_2 & p_3 & p_4 \\ 
    c_0 & c_1 & c_2 & c_3 & c_4 & c_5 & c_6 & c_7 & c_8 & c_9 & c_{10} & c_{11} & c_{12} & c_{13} & c_{14}
    \end{array}\right].

Nhìn vào :math:`k_0`, mình thấy rằng :math:`k_0` tác động lần lượt lên :math:`p_0`, :math:`p_3`, :math:`p_1`, :math:`p_4` và :math:`p_2`, tương ứng với các ciphertext :math:`c_0`, :math:`c_3`, :math:`c_6`, :math:`c_9` và :math:`c_{12}`. Như vậy mình chỉ cần *sắp xếp* lại :math:`p_0`, :math:`p_3`, ... về đúng vị trí của nó là được.

Vì :math:`\gcd(l, n) = 1` nên mình nhớ tới một tính chất mà chúng ta hay dùng để chứng minh định lý Wilson hoặc Euler là nếu :math:`\{ g_1, g_2, \ldots, g_{\phi(n)} \}` là hệ thặng dư thu gọn modulo :math:`n` và :math:`a` là số sao cho :math:`\gcd(a, n) = 1` thì tập

.. math:: \{ a g_1 \bmod n, a g_2 \bmod n, \ldots, a g_{\phi(n)} \bmod n \}
    
cũng là hệ thặng dư thu gọn modulo :math:`n`. Nói cách khác hai tập hợp

.. math:: \{ g_1, g_2, \ldots, g_{\phi(n)} \} \ \text{và} \ \{ a g_1 \bmod n, a g_2 \bmod n, \ldots, a g_{\phi(n)} \bmod n \}
    
là hoán vị của nhau.

Mình thử như sau:

- với :math:`i = 0` thì :math:`0 \cdot 3 = 0 \bmod 5`;
- với :math:`i = 1` thì :math:`1 \cdot 3 = 3 \bmod 5`;
- với :math:`i = 2` thì :math:`2 \cdot 3 = 1 \bmod 5`;
- với :math:`i = 3` thì :math:`3 \cdot 3 = 4 \bmod 5`;
- với :math:`i = 4` thì :math:`4 \cdot 3 = 2 \bmod 5`.

Nhìn chuỗi :math:`(0, 3, 1, 4, 2)` quen quen. Đó chính là :math:`p_0`, :math:`p_3`, :math:`p_1`, :math:`p_4`, :math:`p_2` ở trên.

Như vậy mình có công thức tổng quát là :math:`p_{i \cdot 3 \bmod 5} = c_{i \cdot 3}`, hay tổng quát hơn :math:`p_{i \cdot n \bmod l} = c_{i \cdot n}` với :math:`i = 0, 1, \ldots, l-1`.

Sau đó mình chỉ cần bruteforce 256 trường hợp :math:`k_0` nữa. Ở đây mình thấy với :math:`k_0 = 165` thì có chuỗi ``PNG`` (?).

Như vậy XOR với :math:`165` sẽ có flag. Code giải mình để ở :download:`main.py <OwO Time Pad/solve.py>`.

Okay vậy là xong bài.
