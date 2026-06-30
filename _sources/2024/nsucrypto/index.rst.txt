NSUCRYPTO 2024
**************

Trong hai bài viết mình sẽ giới thiệu cách giải các bài trong NSUCRYPTO 2024 từ bài giải của team mình lẫn từ team các bạn mà mình tham khảo sau khi kết thúc giải. Hiện tại chỉ có team của Robin Jadoul, Jack Pope, Esrever Yievs chia sẻ bài giải gần hoàn chỉnh trên discord của một cộng đồng toxic nào đó mà ai cũng biết nên mình sẽ gọi là team JPY khi đề cập tới cách giải của các bạn (lấy chữ cái đầu họ của ba người :v).

Lời nói đầu
===========

Đầu tiên mình xin cám ơn rất nhiều người đã ủng hộ, giúp đỡ mình trong mấy năm qua, để mình có thể đi tới ngày hôm nay.

Đề thi năm nay khiến mình có chút hoang mang khi bắt đầu làm. Round 2 có 11 câu với hai câu special prize. Thường những năm trước có từ 4 tới 5 câu special prize và đây là nơi đột biến xảy ra. Nếu chỉ có hai câu thì mình không hy vọng được giải cao mà mục tiêu là giải trọn vẹn và không mắc lỗi ở tất cả câu khác.

Và điều kì diệu đã xảy ra :))) team mình được hai bài BEST SOLUTION do hai bạn teammate giải, còn mình thì ... ké :D

Chân thành cám ơn bạn Chương và bạn Uyên đã đồng hành cũng mình hai năm nay.

RSA signature
=============

Đây là bài 7 ở round 1 và bài 1 ở round 2.

Đề bài
------

Chúng ta cần ký thông điệp :math:`M` bằng thuật toán RSA. Như bình thường, đặt :math:`N = p \cdot q` là RSA-modulus với :math:`p` và :math:`q` là hai số nguyên tố lớn.

Đặt :math:`e` là public exponent và :math:`d` là secret exponent với

.. math:: e \cdot d = 1 \bmod (p - 1)(q - 1).

Signature của chúng ta sẽ là

.. math:: S = M^d \bmod N.

Giả sử kẻ tấn công biết giá trị

.. math:: M_p = M^{d_p} \bmod p,

nhưng không biết giá trị

.. math:: M_q = M^{d_q} \bmod q,

trong đó

.. math:: d_p = d \bmod (p-1), \quad d_q = d \bmod (q-1).

Nếu kẻ tấn công biết modulo :math:`N` (nhưng không biết :math:`p` và :math:`q`), biết public exponent :math:`e` (nhưng không biết :math:`d`) và biết thông điệp gốc :math:`M`. Các thông số bí mật nào kẻ tấn công có thể tìm ra?

Lời giải
--------

Vì :math:`S \equiv M^d \pmod N` nên suy ra :math:`S \equiv M^d \pmod p` vì

.. math:: (S - M^d) \ \vdots \ N \ \vdots \ p,

tương tự :math:`S \equiv M^d \pmod q`.

Ngoài ra ta có

.. math:: 
    :label: nsu24-eq-1

    S^e \equiv M^{ed} \equiv M \pmod N.

Tương tự phía trên ta cũng có

.. math:: S^e \equiv M^{ed} \equiv M \pmod p,

nhưng :math:`d_p \equiv d \pmod{p-1}`, tương đương với

.. math:: d = d_p + k_p \cdot (p-1)

với :math:`k_p \in \mathbb{Z}`.

Do đó

.. math:: 
    :label: nsu24-eq-2

    S^e & \equiv M^{e \cdot (d_p + k_p \cdot (p - 1))} \pmod{p} \\
        & \equiv M^{e \cdot d_p} \pmod{p} \quad (\text{định lý Euler}) \\
        & \equiv M_p^e \pmod{p}.

Từ hai phương trình :eq:`nsu24-eq-1` và :eq:`nsu24-eq-2` suy ra

.. math:: M^e_p \equiv M \pmod p,

hay ta có thể nói là

.. math:: (M^e_p \bmod N) - M \ \vdots \ p.

Từ đây, sử dụng thuật toán Euclid ta tìm được

.. math:: p = \gcd((M^e_p \bmod N) - M, N).

Vậy là ta đã tìm được :math:`p` nên có thể tìm được tất cả tham số secret khác của RSA là :math:`q`, :math:`d`, :math:`d_p` và :math:`d_q`.

.. admonition:: solve.py
    :class: dropdown

    .. code-block:: python

        from Crypto.Util.number import getPrime
        import random

        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        p, q = [getPrime(1024) for _ in range(2)]

        print(f"{p = }")
        print(f"{q = }")

        e = 65537
        N = p * q
        d = pow(e, -1, (p - 1) * (q - 1))

        M = random.randint(1, N - 1)

        dp = d % (p - 1)
        Mp = pow(M, dp, p)

        print(f"{N = }")
        print(f"{e = }")
        print(f"{M = }")
        print(f"{Mp = }")

        p_guess = gcd(pow(Mp, e, N) - M, N)
        assert p == p_guess
        print("Successfully recoverd p")

AntCipher 2.0
=============

Đây là bài 2 ở round 2.

Đề bài
------

Một phút một lần, GPS được track bởi vệ tinh. Khi đó, vĩ độ ở dạng IEEE 754 single-precision floating-point sẽ được chuyển thành dãy 32 bit. Tương tự cho kinh độ.

Khi đó hai dãy nhị phân sẽ được nối lại (lattile || longitude) thành plaintext có 64 bit. Sau đó plaintext được XOR với keystream để tạo thành ciphertext 64 bit.

Cách thực hiện sinh khóa như sau. Tại điểm khởi tạo, secret key 64 bit được viết vào thanh ghi :math:`R` dung lượng 64 bit.

Với mỗi số :math:`i` với :math:`i \geqslant 1`, dãy :math:`K_i` 64 bit sẽ được sinh từ input là :math:`R` và keystream cũng dùng để cập nhật thanh ghi :math:`R`, nghĩa là sau khi tính toán thì giá trị :math:`K_i` sẽ được ghi vào :math:`R`.

Xét dạng CNF của hàm :math:`C`, với CNF là conjunction of disjunction (tích của các tổng), có dạng sau:

.. math:: 

    C = (x_1 \lor v_2 \lor \neg x_5) \land (\neg x_1 \lor \neg x_2 \lor x_5) \land (x_1 \lor x_3 \lor \neg x_5) \land (\neg x_1 \lor \neg x_3 \lor x_5) \\
    \land (x_2 \lor x_3 \lor \neg x_5) \land (\neg x_2 \lor \neg x_3 \lor x_5) \land (x_1 \lor x_2 \lor \neg x_6) \land (\neg x_1 \lor \neg x_2 \lor x_6) \\
    \land (x_1 \lor x_4 \lor \neg x_6) \land (\neg x_1 \lor \neg x_4 \lor x_6) \land (x_2 \lor x_4 \lor \neg x_6) \land (\neg x_2 \lor \neg x_4 \lor x_6) \\
    \land (x_1 \lor x_3 \lor \neg x_7) \land (\neg x_1 \lor \neg x_3 \lor x_7) \land (x_1 \lor x_4 \lor \neg x_7) \land (\neg x_1 \lor \neg x_4 \lor x_7) \\
    \land (x_3 \lor x_4 \lor \neg x_7) \land (\neg x_3 \lor \neg x_4 \lor x_7) \land (x_2 \lor x_3 \lor \neg x_8) \land (\neg x_2 \lor \neg x_3 \lor x_8) \\
    \land (x_2 \lor x_4 \lor \neg x_8) \land (\neg x_2 \lor \neg x_4 \lor x_8) \land (x_3 \lor x_4 \lor \neg x_8) \land (\neg x_3 \lor \neg x_4 \lor x_8)

Phương trình :math:`C = 1` biểu diễn một hàm không tuyến tính :math:`F_G` lấy đầu vào là :math:`4` bits :math:`(x_1, x_2, x_3, x_4)` và sinh ra :math:`4` bits :math:`(x_5, x_6, x_7, x_8)` làm output.

Ở vòng lặp thứ :math:`i` của cipher, :math:`64` bits của :math:`R` được chia thành :math:`16` đoạn, mỗi đoạn :math:`4` bit. Mỗi đoạn thành input cho :math:`F_G` và kết quả là :math:`16` đoạn :math:`4` bits mới được nối với nhau thành :math:`K_i` có :math:`64` bits.

:math:`1704` ciphertexts được truyền đi không gặp vấn đề. Tuy nhiên ở hai keystream tiếp theo gặp sự cố về đĩa cứng nên chỉ nhận được ciphertext thứ :math:`1704` là dãy

.. code-block:: 
    
    1001 1000 0011 1101 0110 0011 1101 0101 1011 0011 1011 0111 0000 0000 1000 0011

và hai keystrem :math:`1702` và :math:`1703` nhưng bị mất một phần:

.. math:: 

    K_{1702} & = \text{0101 1001 1111 0011 00X1 X111 1X00 00X0} \\
            & \text{111X X000 XXXX XXXX XXXX XXXX XXXX XXXX}, \\
    K_{1703} & = \text{XXXX XXXX XXXX XXXX XXXX XXXX XXXX XXXX} \\
            & \text{X111 000X X010 01X1 0X10 0101 0000 1111}.

Hãy tìm lại plaintext thứ :math:`1704`.

Lời giải
--------

Đầu tiên mình cần tìm những bộ số :math:`(x_1, \ldots, x_8)` mà :math:`C = 1`.

.. code-block:: python

    from itertools import product

    def f(x1, x2, x3, x4, x5, x6, x7, x8):
        result = 1
        result = result & (x1 | x2 | ~x5)
        result = result & (~x1 | ~x2 | x5)
        result = result & (x1 | x3 | ~x5)
        result = result & (~x1 | ~x3 | x5)
        result = result & (x2 | x3 | ~x5)
        result = result & (~x2 | ~x3 | x5)
        result = result & (x1 | x2 | ~x6)
        result = result & (~x1 | ~x2 | x6)
        result = result & (x1 | x4 | ~x6)
        result = result & (~x1 | ~x4 | x6)
        result = result & (x2 | x4 | ~x6)
        result = result & (~x2 | ~x4 | x6)
        result = result & (x1 | x3 | ~x7)
        result = result & (~x1 | ~x3 | x7)
        result = result & (x1 | x4 | ~x7)
        result = result & (~x1 | ~x4 | x7)
        result = result & (x3 | x4 | ~x7)
        result = result & (~x3 | ~x4 | x7)
        result = result & (x2 | x3 | ~x8)
        result = result & (~x2 | ~x3 | x8)
        result = result & (x2 | x4 | ~x8)
        result = result & (~x2 | ~x4 | x8)
        result = result & (x3 | x4 | ~x8)
        result = result & (~x3 | ~x4 | x8)

        return result

    key = { }

    for x1, x2, x3, x4, x5, x6, x7, x8 in product(range(2), repeat=8):
        t = f(x1, x2, x3, x4, x5, x6, x7, x8)
        if t == 1:
            print(f"{x1, x2, x3, x4} -> {x5, x6, x7, x8}")
            a = x1 + (x2 << 1) + (x3 << 2) + (x4 << 3)
            b = x5 + (x6 << 1) + (x7 << 2) + (x8 << 3)
            key[a] = b

Bảng biến đổi sẽ như sau:

+------------------------------+---------------------+------------------------------+
| :math:`(x_1, x_2, x_3, x_4)` | :math:`\rightarrow` | :math:`(x_5, x_6, x_7, x_8)` |
+==============================+=====================+==============================+
| :math:`(0, 0, 0, 0)`         | :math:`\rightarrow` | :math:`(0, 0, 0, 0)`         |
+------------------------------+---------------------+------------------------------+
| :math:`(0, 0, 0, 1)`         | :math:`\rightarrow` | :math:`(0, 0, 0, 0)`         |
+------------------------------+---------------------+------------------------------+
| :math:`(0, 0, 1, 0)`         | :math:`\rightarrow` | :math:`(0, 0, 0, 0)`         |
+------------------------------+---------------------+------------------------------+
| :math:`(0, 0, 1, 1)`         | :math:`\rightarrow` | :math:`(0, 0, 1, 1)`         |
+------------------------------+---------------------+------------------------------+
| :math:`(0, 1, 0, 0)`         | :math:`\rightarrow` | :math:`(0, 0, 0, 0)`         |
+------------------------------+---------------------+------------------------------+
| :math:`(0, 1, 0, 1)`         | :math:`\rightarrow` | :math:`(0, 1, 0, 1)`         |
+------------------------------+---------------------+------------------------------+
| :math:`(0, 1, 1, 0)`         | :math:`\rightarrow` | :math:`(1, 0, 0, 1)`         |
+------------------------------+---------------------+------------------------------+
| :math:`(0, 1, 1, 1)`         | :math:`\rightarrow` | :math:`(1, 1, 1, 1)`         |
+------------------------------+---------------------+------------------------------+
| :math:`(1, 0, 0, 0)`         | :math:`\rightarrow` | :math:`(0, 0, 0, 0)`         |
+------------------------------+---------------------+------------------------------+
| :math:`(1, 0, 0, 1)`         | :math:`\rightarrow` | :math:`(0, 1, 1, 0)`         |
+------------------------------+---------------------+------------------------------+
| :math:`(1, 0, 1, 0)`         | :math:`\rightarrow` | :math:`(1, 0, 1, 0)`         |
+------------------------------+---------------------+------------------------------+
| :math:`(1, 0, 1, 1)`         | :math:`\rightarrow` | :math:`(1, 1, 1, 1)`         |
+------------------------------+---------------------+------------------------------+
| :math:`(1, 1, 0, 0)`         | :math:`\rightarrow` | :math:`(1, 1, 0, 0)`         |
+------------------------------+---------------------+------------------------------+
| :math:`(1, 1, 0, 1)`         | :math:`\rightarrow` | :math:`(1, 1, 1, 1)`         |
+------------------------------+---------------------+------------------------------+
| :math:`(1, 1, 1, 0)`         | :math:`\rightarrow` | :math:`(1, 1, 1, 1)`         |
+------------------------------+---------------------+------------------------------+
| :math:`(1, 1, 1, 1)`         | :math:`\rightarrow` | :math:`(1, 1, 1, 1)`         |
+------------------------------+---------------------+------------------------------+

Có thể thấy đầu ra không chứa đủ :math:`16` trường hợp mà chỉ gồm các trường hợp là

.. math:: (0, 0, 0, 0), (0, 0, 1, 1), (0, 1, 0, 1), (1, 0, 0, 1), (0, 1, 1, 0,), (1, 0, 1, 0), (1, 1, 0, 0), (1, 1, 1, 1).

Ở đây mỗi vector đều có số lượng chẵn phần tử :math:`1`.

Xét biến đổi từ :math:`K_{1702}` thành :math:`K_{1703}` như sau:

+---------------------+---------------------+---------------------+
| :math:`K_{1702}`    | :math:`\rightarrow` | :math:`K_{1703}`    |
+=====================+=====================+=====================+
| :math:`\text{0101}` | :math:`\rightarrow` | :math:`\text{XXXX}` |
+---------------------+---------------------+---------------------+
| :math:`\text{1001}` | :math:`\rightarrow` | :math:`\text{XXXX}` |
+---------------------+---------------------+---------------------+
| :math:`\text{1111}` | :math:`\rightarrow` | :math:`\text{XXXX}` |
+---------------------+---------------------+---------------------+
| :math:`\text{0011}` | :math:`\rightarrow` | :math:`\text{XXXX}` |
+---------------------+---------------------+---------------------+
| :math:`\text{00X1}` | :math:`\rightarrow` | :math:`\text{XXXX}` |
+---------------------+---------------------+---------------------+
| :math:`\text{X111}` | :math:`\rightarrow` | :math:`\text{XXXX}` |
+---------------------+---------------------+---------------------+
| :math:`\text{1X00}` | :math:`\rightarrow` | :math:`\text{XXXX}` |
+---------------------+---------------------+---------------------+
| :math:`\text{00X0}` | :math:`\rightarrow` | :math:`\text{XXXX}` |
+---------------------+---------------------+---------------------+
| :math:`\text{111X}` | :math:`\rightarrow` | :math:`\text{X111}` |
+---------------------+---------------------+---------------------+
| :math:`\text{X000}` | :math:`\rightarrow` | :math:`\text{000X}` |
+---------------------+---------------------+---------------------+
| :math:`\text{XXXX}` | :math:`\rightarrow` | :math:`\text{X010}` |
+---------------------+---------------------+---------------------+
| :math:`\text{XXXX}` | :math:`\rightarrow` | :math:`\text{01X1}` |
+---------------------+---------------------+---------------------+
| :math:`\text{XXXX}` | :math:`\rightarrow` | :math:`\text{0X10}` |
+---------------------+---------------------+---------------------+
| :math:`\text{XXXX}` | :math:`\rightarrow` | :math:`\text{0101}` |
+---------------------+---------------------+---------------------+
| :math:`\text{XXXX}` | :math:`\rightarrow` | :math:`\text{0000}` |
+---------------------+---------------------+---------------------+
| :math:`\text{XXXX}` | :math:`\rightarrow` | :math:`\text{1111}` |
+---------------------+---------------------+---------------------+

Dựa vào bảng biến đổi ở trên và lưu ý đầu ra (có :math:`8` trường hợp tất cả) thì ta có kết luận cho từng bộ :math:`4` như sau:

1. :math:`0101 \rightarrow 010`.
2. :math:`1001 \rightarrow 0110`.
3. :math:`1111 \rightarrow 1111`.
4. :math:`0011 \rightarrow 0011`.
5. :math:`\text{00X1} \rightarrow 0000`. Vì :math:`K_{1702}` nhận được từ :math:`K_{1701}` nên X chỉ có thể là :math:`1` và kết quả ở :math:`K_{1703}` sẽ là :math:`0000`.
6. :math:`\text{X111} \rightarrow 1111`.
7. :math:`\text{1X00} \rightarrow 0000`. Tương tự, vì :math:`K_{1702}` nhận được từ :math:`K_{1701}` nên X chỉ có thể là :math:`1` và kết quả ở :math:`K_{1703}` là :math:`0000`.
8. :math:`\text{0X00} \rightarrow 0000`.
9. :math:`\text{111X} \rightarrow 1111`.
10. :math:`\text{X000} \rightarrow 0000`.
11. :math:`\text{XXXX} \rightarrow 1010`. Trong mỗi bộ số trong :math:`8` trường hợp ở trên thì số lượng chữ số :math:`1` là chẵn.
12. :math:`\text{XXXX} \rightarrow 0101`. Tương tự.
13. :math:`\text{XXXX} \rightarrow 0110`. Tương tự
14. :math:`\text{XXXX} \rightarrow 0101`.
15. :math:`\text{XXXX} \rightarrow 0000`.
16. :math:`\text{XXXX} \rightarrow 1111`.

Như vậy mình đã khôi phục được :math:`K_{1703}` và có thể decrypt.

.. code-block:: python

    # https://gist.github.com/AlexEshoo/d3edc53129ed010b0a5b693b88c7e0b5
    def ieee_754_conversion(n, sgn_len=1, exp_len=8, mant_len=23):
        """
        Converts an arbitrary precision Floating Point number.
        Note: Since the calculations made by python inherently use floats, the accuracy is poor at high precision.
        :param n: An unsigned integer of length `sgn_len` + `exp_len` + `mant_len` to be decoded as a float
        :param sgn_len: number of sign bits
        :param exp_len: number of exponent bits
        :param mant_len: number of mantissa bits
        :return: IEEE 754 Floating Point representation of the number `n`
        """
        if n >= 2 ** (sgn_len + exp_len + mant_len):
            raise ValueError("Number n is longer than prescribed parameters allows")

        sign = (n & (2 ** sgn_len - 1) * (2 ** (exp_len + mant_len))) >> (exp_len + mant_len)
        exponent_raw = (n & ((2 ** exp_len - 1) * (2 ** mant_len))) >> mant_len
        mantissa = n & (2 ** mant_len - 1)

        sign_mult = 1
        if sign == 1:
            sign_mult = -1

        if exponent_raw == 2 ** exp_len - 1:  # Could be Inf or NaN
            if mantissa == 2 ** mant_len - 1:
                return float('nan')  # NaN

            return sign_mult * float('inf')  # Inf

        exponent = exponent_raw - (2 ** (exp_len - 1) - 1)

        if exponent_raw == 0:
            mant_mult = 0  # Gradual Underflow
        else:
            mant_mult = 1

        for b in range(mant_len - 1, -1, -1):
            if mantissa & (2 ** b):
                mant_mult += 1 / (2 ** (mant_len - b))

        return sign_mult * (2 ** exponent) * mant_mult

    ciphertext = "1001 1000 0011 1101 0110 0011 1101 0101 1011 0011 1011 0111 0000 0000 1000 0011"
    ciphertext = list(map(int, "".join(ciphertext.split(" "))))

    keystream = "0101 0110 1111 0011 0011 1111 1100 0000 1111 0000 1010 0101 0110 0101 0000 1111"
    keystream = [int(i, 2) for i in keystream.split(" ")]
    keystream = [key[k] for k in keystream] # Find K_{1704} from K_{1703} by table 1
    keystream = "".join(f"{k:04b}" for k in keystream)
    keystream = list(map(int, keystream))

    plaintext = [c^k for c, k in zip(ciphertext, keystream)]  # Recover plaintext
    plaintext = "".join(map(str, plaintext))
    assert len(plaintext) == 64
    m, n = int(plaintext[:32], 2), int(plaintext[32:], 2)     # Extract first 32 bits and last 32 bits

    latitude = ieee_754_conversion(m)   # Convert first 32 bits to latitude
    longitude = ieee_754_conversion(n)  # Convert last 32 bits to longitude

    print(f"({latitude}, {longitude})")

Mình nhận được tọa độ là

.. math:: (-25.79496192932129, 146.58416748046875).

Tọa độ này chỉ tới Australia (Augathella), cụ thể là một công viên tên là "Meat Ant Park". Chữ "Ant" có vẻ khớp với đề bài.

Steganography and codes
=======================

Đây là bài 3 ở round 2.

Đề bài
------

Sam và Betty sử dụng kênh mở cho giao tiếp bí mật. Họ không muốn ai biết về hội thoại của mình.

Sam có thể gửi co Betty một trong :math:`16` thông điệp.

Khi đó, Sam lấy một ảnh với format RGB bất kì, đổi pixel đầu tiên theo cách nào đó và publish lên website.

Betty sẽ tải bức ảnh đó xuống và phân tích xem Sam đã gửi thông điệp nào.

Sam sẽ làm gì với bức ảnh? Chúng ta nên chú ý rằng phải thay đổi pixel sao cho không thể nhận biết sự thay đổi bởi mắt thường.

Cụ thể, mỗi pixel RGB được biểu diễn ở dạng :math:`24` bit:

- :math:`8` bit đầu là độ sáng của màu đỏ :math:`(r_1, \ldots, r_8)`;
- :math:`8` bit tiếp theo là độ sáng màu xanh lá :math:`(g_1, \ldots, g_8)`;
- :math:`8` bit cuối là độ sáng màu xanh dương :math:`(b_1, \ldots, b_8)`.

Sam không được thay đổi các bit :math:`r`, :math:`g`, :math:`b` từ :math:`1` tới :math:`5` vì điều đó sẽ dễ nhận thấy khi nhìn bằng mắt.

Nếu Sam đổi một trong các bit :math:`r_6`, :math:`r_7`, :math:`g_6`, :math:`g_7` và :math:`b_6` sẽ tốn :math:`2` coins mỗi lần đổi.

Nếu Sam đổi một trong các bit :math:`r_8`, :math:`g_8`, :math:`b_7` và :math:`b_8` thì tốn :math:`1` coin mỗi lần đổi.

Hãy đưa ra một phương pháp coding cho :math:`16` thông điệp vào một pixel mà tốn không quá :math:`2` coins (mà không thể nhận thấy bằng mắt thường).

Thêm nữa hãy đưa ra một phương để Betty có thể biết được thông điệp mà Sam giấu vào ảnh là gì. Lưu ý rằng Betty không biết ảnh gốc như thế nào.

Lời giải
--------

Tạm thời trống.

Weak key schedule for DES
=========================

Đây là bài 6 ở round 1 và bài 4 ở round 2.

Đề bài
------

Alice sử dụng thuật toán DES để mã hóa file `Book.txt` thành `Book_Cipher.txt`. Tuy nhiên khi code thuật toán DES thì Alice đã code lỗi và khiến cả thuật toán chỉ sử dụng subkey đầu tiên cho tất cả các vòng (thay vì mỗi vòng mỗi khóa con như DES chuẩn).

Hãy giúp Carol tìm lại khóa ban đầu và decrypt bản mã sau:

.. code-block:: 

    86991641D28259604412D6BA88A5C0A6471CA722
    2C52482BF2D0E841D4343DFB877DC8E0147F3D5F
    20FC18FF28CB5C4DA8A0F4694861AB5E98F37ADB
    C2D69B35779D9001BB4B648518FE6EBC00B2AB10

Lời giải
--------

Bài này được giải bởi bạn Chương và được thêm BEST SOLUTION :)))

Ý tưởng của bài này là slide attack. Các bạn có thể xem lời giải ở bài viết về `slide attack <../../cryptanalysis/slide-attack>`_ của mình.

Reverse engineering
===================

Đây là bài 5 ở round 2.

Đề bài
------

Sau khi reverse engineering cài đặt của một thuật toán mật mã nào đó chưa biết thì Bob nhận được hàm boolean sau:

.. math:: f_{2n} (x_1, \ldots, x_{2n}) = \bigoplus_{i=1}^n x_i x_{i+n} \prod_{j=i+1}^n (x_j \oplus x_{j + n}).

Bob cố gắng hiểu ý nghĩa mật mã của hàm boolean trên là gì, và nhanh chóng tìm thấy một "liên hệ". Đây là hàm gì?

.. figure:: cast.png

Mở đầu
------

Bài này mình chứng minh được tính chất của hàm đề bài cho chứ không tìm ra ý nghĩa của hàm nên chỉ được 4/6 điểm.

Tham khảo lời giải của team JPY thì đây là hàm kiểm tra tràn bit số nguyên (integer overflow).

Mình sẽ trình bày cả cách giải của mình lẫn cách giải của team bạn.

Hình đề cho là CAST cipher - tiêu chuẩn mã hóa của Canada.

S-boxes trong CAST cipher được lựa chọn từ các hàm boolean có nonlinearity cao nhất nên trong lúc làm bài mình cắm đầu vào tìm một tính chất gì đó của hàm boolean trên liên quan tới nonlinearity.

Mình đã chứng minh được hai điều:

- trọng số Hamming của hàm :math:`f_{2n}` bằng :math:`2^{n-1} \cdot (2^n - 1)`;
- nonlinearity của hàm :math:`f_{2n}` bằng :math:`2^{2n-2}`.

Nhắc lại hàm boolean :math:`f_{2n}` đề cho là hàm

.. math:: f_{2n}(x_1, \ldots, x_{2n}) = \bigoplus_{i=1}^n x_i x_{i+n} \prod_{j=i+1}^n (x_j \oplus x_{j+n}).

Trọng số Hamming của hàm boolean
--------------------------------

Để tìm công thức hoặc tính chất thì thường mình sẽ thử với các số nhỏ và sau đó đoán công thức.

Với :math:`n = 1` thì :math:`f_2(x_1, x_2) = x_1 x_2`. Dễ thấy rằng :math:`f_2 = 1` khi :math:`x_1 = x_2 = 1`.

Thay vì viết bảng chân trị gồm :math:`4` dòng thì mình viết thành bảng ô vuông :math:`2 \times 2`:

+-----------------+-----------------+------------------------------+
|                 | :math:`x_2 = 0` | :math:`x_2 = 1`              |
+-----------------+-----------------+------------------------------+
| :math:`x_1 = 0` | :math:`f_2 = 0` | :math:`f_2 = 0`              |
+-----------------+-----------------+------------------------------+
| :math:`x_1 = 1` | :math:`f_2 = 0` | :math:`f_2 = {\color{red}1}` |
+-----------------+-----------------+------------------------------+

Với :math:`n = 2` thì hàm boolean là

.. math:: f_4(x_1, x_, x_3, x_4) = \left[x_1 x_3 (x_2 \oplus x_4)\right] \oplus x_2 x_4 = x_1 x_2 x_3 \oplus x_1 x_3 x_4 \oplus x_2 x_4.

Cũng tương tự, mình viết bảng chân trị thành bảng ô vuông :math:`4 \times 4`:

+----------------------+----------------------+------------------------------+------------------------------+------------------------------+
|                      | :math:`x_3 x_4 = 00` | :math:`x_3 x_4 = 01`         | :math:`x_3 x_4 = 10`         | :math:`x_3 x_4 = 11`         |
+----------------------+----------------------+------------------------------+------------------------------+------------------------------+
| :math:`x_1 x_2 = 00` | :math:`f_4 = 0`      | :math:`f_4 = 0`              | :math:`f_4 = 0`              | :math:`f_4 = 0`              |
+----------------------+----------------------+------------------------------+------------------------------+------------------------------+
| :math:`x_1 x_2 = 01` | :math:`f_4 = 0`      | :math:`f_4 = 0`              | :math:`f_4 = 0`              | :math:`f_4 = {\color{red}1}` |
+----------------------+----------------------+------------------------------+------------------------------+------------------------------+
| :math:`x_1 x_2 = 10` | :math:`f_4 = 0`      | :math:`f_4 = 0`              | :math:`f_4 = {\color{red}1}` | :math:`f_4 = {\color{red}1}` |
+----------------------+----------------------+------------------------------+------------------------------+------------------------------+
| :math:`x_1 x_2 = 11` | :math:`f_4 = 0`      | :math:`f_4 = {\color{red}1}` | :math:`f_4 = {\color{red}1}` | :math:`f_4 = {\color{red}1}` |
+----------------------+----------------------+------------------------------+------------------------------+------------------------------+

Với :math:`n = 3` thì mình viết bảng chân trị thành bảng :math:`8 \times 8`:

+-------------+-------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+
|             | :math:`000` | :math:`001`            | :math:`010`            | :math:`011`            | :math:`100`            | :math:`101`            | :math:`110`            | :math:`111`            |
+-------------+-------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+
| :math:`000` | :math:`0`   | :math:`0`              | :math:`0`              | :math:`0`              | :math:`0`              | :math:`0`              | :math:`0`              | :math:`0`              |
+-------------+-------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+
| :math:`001` | :math:`0`   | :math:`0`              | :math:`0`              | :math:`0`              | :math:`0`              | :math:`0`              | :math:`0`              | :math:`{\color{red}1}` |
+-------------+-------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+
| :math:`010` | :math:`0`   | :math:`0`              | :math:`0`              | :math:`0`              | :math:`0`              | :math:`0`              | :math:`{\color{red}1}` | :math:`{\color{red}1}` |
+-------------+-------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+
| :math:`011` | :math:`0`   | :math:`0`              | :math:`0`              | :math:`0`              | :math:`0`              | :math:`{\color{red}1}` | :math:`{\color{red}1}` | :math:`{\color{red}1}` |
+-------------+-------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+
| :math:`100` | :math:`0`   | :math:`0`              | :math:`0`              | :math:`0`              | :math:`{\color{red}1}` | :math:`{\color{red}1}` | :math:`{\color{red}1}` | :math:`{\color{red}1}` |
+-------------+-------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+
| :math:`101` | :math:`0`   | :math:`0`              | :math:`0`              | :math:`{\color{red}1}` | :math:`{\color{red}1}` | :math:`{\color{red}1}` | :math:`{\color{red}1}` | :math:`{\color{red}1}` |
+-------------+-------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+
| :math:`110` | :math:`0`   | :math:`0`              | :math:`{\color{red}1}` | :math:`{\color{red}1}` | :math:`{\color{red}1}` | :math:`{\color{red}1}` | :math:`{\color{red}1}` | :math:`{\color{red}1}` |
+-------------+-------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+
| :math:`111` | :math:`0`   | :math:`{\color{red}1}` | :math:`{\color{red}1}` | :math:`{\color{red}1}` | :math:`{\color{red}1}` | :math:`{\color{red}1}` | :math:`{\color{red}1}` | :math:`{\color{red}1}` |
+-------------+-------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+------------------------+

Đến đây thì mình nhận thấy hàm :math:`f_{2n}` sẽ nhận giá trị :math:`1` tại:

- :math:`1` ô hàng thứ hai;
- :math:`2` ô hàng thứ ba;
- ...
- :math:`2^n-1` ô hàng cuối.

Như vậy trọng số Hamming được dự đoán là

.. math:: 1 + 2 + \ldots + (2^n - 1) = \dfrac{(2^n - 1) \cdot 2^n}{2} = 2^{n-1} \cdot (2^n - 1).

Sau đây mình sẽ chứng minh công thức trọng số Hamming này bằng quy nạp.

Với :math:`n = 1`, hàm :math:`f_2(x_1, x_2) = x_1 x_2` có trọng số Hamming là :math:`1 = 2^{1-1} \cdot (2^1 - 1)`. Như vậy công thức đúng với :math:`n = 1`.

Giả sử công thức đúng với :math:`n = k \geqslant 1`, nghĩa là hàm

.. math:: f_{2k}(x_1, \ldots, x_{2k}) = \bigoplus_{i=1}^k x_i x_{i+k} \prod_{j=i+1}^k (x_j \oplus x_{j+k})

có trọng số Hamming là :math:`2^{k-1} \cdot (2^k - 1)`.

Với :math:`n = k + 1`, xét hàm

.. math:: f_{2k+2}(x_1, \ldots, x_k, y, x_{k+1}, \ldots, x_{2k}, z) = \bigoplus_{i=1}^k x_i x_{i+k} \left[ \prod_{j=i+1}^k (x_j \oplus x_{j+k}) \cdot (y \oplus z)  \right] \oplus yz.

Ta có các trường hợp sau:

- khi :math:`y = z = 0` thì :math:`y \oplus z = 0` và :math:`yz = 0`. Khi đó mọi phép nhân :math:`\prod\limits_{j=i+1}^k (x_j \oplus x_{j+k}) \cdot (y \oplus z) = 0` nên khiến cả hàm :math:`f_{2k+2} = 0` tại tất cả vector :math:`(x_1, \ldots, x_{2k})`;
- khi :math:`y = 0` và :math:`z = 1` thì :math:`y \oplus z = 1` và :math:`yz = 0`. Thay vào hàm :math:`f_{2k+2}` ta có

.. math:: f_{2k+2}(x_1, \ldots, x_k, 0, x_{k+1}, \ldots, x_{2k}, 1) = \bigoplus_{i=1}^k x_i x_{i+k} \left[ \prod_{j=i+1}^k (x_j \oplus x_{j+k}) \cdot 1 \right] \oplus 0 \equiv f_{2k}(x_1, \ldots, x_{2k}).

Như vậy khi :math:`y = 0` và :math:`z = 1` thì :math:`f_{2k+2}` chính xác bằng :math:`f_{2k}`. Nghĩa là trọng số Hamming của :math:`f_{2k+2}` lúc này bằng trọng số Hamming của :math:`f_{2k}` và bằng :math:`2^{k-1} \cdot (2^k - 1)` theo giả thiết quy nạp.

- khi :math:`y = 1` và :math:`z = 0` thì tương tự, trọng số Hamming của :math:`f_{2k+2}` trong trường hợp này cũng bằng :math:`2^{k-1} \cdot (2^k - 1)`.
- khi :math:`y = z = 1` thì :math:`y \oplus z = 0` và :math:`yz = 1`. Khi đó tất cả biểu thức :math:`\prod\limits_{j=i+1}^k (x_j \oplus x_{j+k}) \cdot (y \oplus z) = 0` nên hàm :math:`f_{2k+2} = 1` với mọi đầu vào :math:`(x_1, \ldots, x_{2k}) \in \mathbb{F}_2^{2k}`. Như vậy trọng số Hamming của :math:`f_{2k+2}` ở trường hợp này là :math:`2^{2k}`.

Kết hợp bốn trường hợp lại thì trọng số Hamming của :math:`f_{2k+2}` là

.. math:: \mathrm{wt}(f_{2k}) = 2^{k-1} \cdot (2^k - 1) \cdot 2 + 2^{2k} = 2^k (2^{k+1} - 1).

Như vậy công thức trọng số Hamming đúng với :math:`k + 1` nên theo quy nạp thì công thức đúng với mọi :math:`n \geqslant 1`.

Biến đổi Walsh-Hadamard và nonlinearity
---------------------------------------

Gọi :math:`W_f(\bm{a})` là hệ số Walsh của hàm boolean :math:`f` (trên :math:`2n` biến) ứng với vector :math:`\bm{a} \in \mathbb{F}_2^{2n}`.

Đặt :math:`\bm{0}` là vector độ dài :math:`2n` chỉ gồm các số :math:`0`, nghĩa là :math:`\bm{0} = (0, \ldots, 0)`.

Một tính chất đơn giản của phổ Walsh là

.. math:: W_f(\bm{0}) = 2^{2n} - 2 \cdot \mathrm{wt}(f),

với :math:`f` là hàm boolean :math:`2n` biến.

Từ kết quả về trọng số ở trên, thay vào công thức ta có

.. math:: W_f(\bm{0}) = 2^{2n} - 2 \cdot 2^{n-1} \cdot (2^n - 1) = 2^n.

Bây giờ xét hệ số Walsh cho vector dạng

.. math:: \bm{a} = (0, 0, \ldots, a_n, 0, 0, \ldots, a_{2n}).

Công thức tính hệ số Walsh là

.. math:: W_f(\bm{a}) = \sum_{\bm{x} \in \mathbb{F}_2^{2n}} (-1)^{f(\bm{x}) \oplus x_n a_n \oplus x_{2n} a_{2n}}.

Nếu :math:`a_n = a_{2n} = 0` thì ta có trường hợp :math:`W_f(\bm{0})` như vừa rồi.

Nếu :math:`a_n = 1` và :math:`a_{2n} = 0` ta sẽ chứng minh hệ số Walsh lúc này có giá trị tuyệt đối lớn nhất. Tương tự đối với :math:`a_n = 0` và :math:`a_{2n} = 1` cũng sẽ cho hệ số Walsh có giá trị tuyệt đối lớn nhất.

Khi :math:`a_n = 1` và :math:`a_{2n} = 0` thì hệ số Walsh sẽ có dạng

.. math:: W_f(\bm{a}) = \sum_{\bm{x} \in \mathbb{F}_2^{2n}} (-1)^{f(\bm{x}) \oplus x_n},

ở đây :math:`\bm{x} = (x_1, \ldots, x_{2n})`.

Ta có hai trường hợp:

**Trường hợp 1.** Nếu :math:`x_n = 0` thì trong số :math:`2^{2n-1}` vector :math:`(x_1, \ldots, x_{n-1}, 0, x_{n+1}, \ldots, x_{2n})`, ta cần tìm số lượng vector khiến :math:`f_{2n} = 1`.

Theo chứng minh về trọng số Hamming ở trên thì nếu :math:`x_{2n} = 0` thì hàm :math:`f_{2n}` (hiện là hàm :math:`2n - 2` biến do :math:`x_n` và :math:`x_{2n}` đã cố định) sẽ luôn có giá trị :math:`0`. Tuy nhiên chỉ với dữ liệu này thì không đủ để biết có bao nhiêu vector khiến :math:`f_{2n} = 1`.

Thay đổi cách tiếp cận nhưng xét :math:`x_{2n} = 1`, khi đó hàm :math:`f_{2n}` cũng là hàm :math:`2n - 2` biến do :math:`x_n` và :math:`x_{2n}` đã cố định, nhưng hàm :math:`f_{2n}` sẽ bằng :math:`1` tại đúng :math:`2^{n-2} \cdot (2^{n-1} - 1)` vectors trong số :math:`2^{2n-1}` vectors đang xét. Vậy theo nguyên lý bù trừ thì :math:`f_{2n} = 0` tại

.. math:: 2^{2n-1} - 2^{n-2} \cdot (2^{n-1} - 1) = 3 \cdot 2^{2n-3} + 2^{n-2} \ \text{vectors}.

Lúc này ta có thể tính

.. math:: 
    :label: nsu24-p5-1

    \sum_{\substack{\bm{x} \in \mathbb{F}_2^{2n} \\ x_n = 0}} (-1)^{f(\bm{x}) \oplus 0} = (-1)^{0} \cdot \left[ 2^{n-2} \cdot (2^{n-1} - 1) \right] + (-1)^{1} \cdot (3 \cdot 2^{2n-3} + 2^{n-2}) = 2^{2n-2} + 2^{n-1}.

**Trường hợp 2.** Nếu :math:`x_n = 1`, tương tự, trong số :math:`2^{2n-1}` vector :math:`(x_1, \ldots, x_{n-1}, 1, x_{n+1}, \ldots, x_{2n})` ta cần tìm xem có bao nhiêu vector khiến :math:`f_{2n} = 1`.

Sử dụng chứng minh cho trọng số Hamming ở trên thì

1. Nếu :math:`x_{2n} = 0` thì

.. math:: f_{2n}(x_1, \ldots, x_{n-1}, 1, x_{n+1}, \ldots, 0)

bằng :math:`1` tại :math:`2^{n-2} \cdot (2^{n-1} - 1)` vectors.

2. Nếu :math:`x_{2n} = 1` thì

.. math:: f_{2n}(x_1, \ldots, x_{n-1}, 1, x_{n+1}, \ldots, 1)

bằng :math:`1` tại tất cả :math:`2^{2n-2}` vectors.

Tổng kết lại, hàm :math:`f_{2n} = 1` tại

.. math:: A = 2^{n-2} \cdot (2^{n-1} - 1) + 2^{2n-2}

vectors. Điều này dẫn tới :math:`f_{2n} = 0` tại :math:`2^{2n-1} - A` vectors.

Ở đây do :math:`x_n = 1` nên khi tính :math:`\sum (-1)^{f(\bm{x}) \oplus 1}` ta cần chuyển dấu

.. math:: 
    :label: nsu24-p5-2

    \sum_{\substack{\bm{x} \in \mathbb{F}_2^{2n} \\ x_n = 1}} (-1)^{f(\bm{x}) \oplus 1} = & (-1) \cdot (2^{2n-1} - A) + 1 \cdot A = 2A - 2^{2n-1} \\ = & 2^{2n-1} + 2^{n-1} \cdot (2^{n-1} - 1) - 2^{2n-1} = 2^{2n-2} - 2^{n-1}.

Kết hợp :eq:`nsu24-p5-1` và :eq:`nsu24-p5-2` ta có hệ số Walsh ứng với vector :math:`\bm{a}` có :math:`a_n = 1` là

.. math:: W_f(\bm{a}) = 2^{2n-2} + 2^{n-1} + 2^{2n-2} - 2^{n-1} = 2^{2n-1}.

Tương tự, tại vector :math:`\bm{a}'` có :math:`a_{2n} = 1` thì ta cũng có :math:`W_f(\bm{a}') = 2^{2n-1}`.

Theo định lí Parseval thì

.. math:: \sum_{\bm{a} \in \mathbb{F}_2^n} (W_f(a))^2 = 2^{2 \cdot 2n} = 2^{4n}

vì :math:`f` ở đây là hàm boolean :math:`2n` biến.

Như vậy ta chỉ cần chứng minh được rằng không tồn tại vector nào khác :math:`\bm{a}` và :math:`\bm{a}'` có hệ số Walsh lớn hơn hoặc bằng :math:`2^{2n-1}`.

Thật vậy, do tính giao hoán của phép XOR (phép cộng) và phép nhân nên công thức của :math:`f_{2n}` cho thấy hai bộ :math:`(x_1, \ldots, x_n)` và :math:`(x_{n+1}, \ldots, x_{2n})` có thể thay thế nhau, nghĩa là

.. math:: f_{2n}(x_1, \ldots, x_n, x_{n+1}, \ldots, x_{2n}) \equiv f_{2n}(x_{n+1}, \ldots, x_{2n}, x_1, \ldots, x_{n}).

Do đó hệ số Walsh cũng có tính đối xứng như vậy. Nếu tồn tại vector :math:`\bm{b}` có hệ số Walsh :math:`W_f(\bm{b}) \geqslant 2^{2n-1}` thì cũng tồn tại vector :math:`\bm{b}'` khác :math:`\bm{b}` có hệ số Walsh :math:`W_f(\bm{b}') \geqslant 2^{2n-1}`.

Khi đó ta có

.. math:: \underbrace{(W_f(\bm{a}))^2}_{=(2^{2n-1})^2} + \underbrace{(W_f(\bm{a}'))^2}_{=(2^{2n-1})^2} + \underbrace{(W_f(\bm{0}))^2}_{=(2^n)^2} + \underbrace{(W_f(\bm{b}))^2}_{> (2^{2n-1})^2} + \underbrace{(W_f(\bm{b}'))^2}_{> (2^{2n-1})^2} > 2^{4n} + 2^{2n}.

Điều này vô lý theo đẳng thức Parseval nên không tồn tại vector :math:`\bm{b}` có hệ số Walsh lớn hơn hoặc bằng :math:`2^{2n-1}`.

.. Cơ mà, nếu :math:`\bm{b} = (b_1, \ldots, b_{2n})` có :math:`(b_1, \ldots, b_n) \equiv (b_{n+1}, \ldots, b_{2n})` thì sao? Lúc này hệ số Walsh có dạng

.. .. math:: W_f(\bm{b}) = \sum_{\bm{x} \in \mathbb{F}_2^{2n}} (-1)^{f(\bm{x}) \oplus b_1 x_1 \oplus \ldots \oplus b_{2n} \oplus x_{2n}}.

Như vậy giá trị tuyệt đối lớn nhất trong các hệ số Walsh là :math:`2^{2n-1}`, từ đó nonlinearity là

.. math:: N_f = 2^{2n-1} - \frac{1}{2} \max \lvert W_f(\bm{a}) \rvert = 2^{2n-1} - \frac{1}{2} \cdot 2^{2n-1} = 2^{2n-1} - 2^{2n-2} = 2^{2n-2}.

Như vậy mình đã chứng minh xong công thức cho nonlinearity.

Lời giải của team JPY và gợi ý của thầy Kolomeec
------------------------------------------------

Sau khi hết giải thì mình hỏi ý kiến thầy Kolomeec về cách làm của mình thì có vẻ là không khớp đáp án. Đáp án là nếu ta xem hai vector :math:`(x_1, \ldots, x_n)` và :math:`(x_{n+1}, \ldots, x_{2n})` như các số nguyên, tức là

.. math:: 

    u & = x_1 + 2 x_2 + \ldots + 2^{n-1} x_n, \\
    v & = x_{n+1} + 2 x_{n+2} + \ldots + 2^{n-1} x_{2n},

thì hàm boolean :math:`f_{2n}` có giá trị :math:`1` nếu :math:`u + v \geqslant 2^n` và ngược lại, đạt giá trị :math:`0` nếu :math:`u + v < 2^n`.

Gợi ý của thầy hoàn toàn khớp với bài giải của team JPY, trong đó nói rằng hàm :math:`f_{2n}` là hàm kiểm tra tràn số khi cộng hai số nguyên (integer overflow). Ví dụ khi cộng hai số kiểu `unsigned int` thì có thể xảy ra hiện tượng tràn bit vì `unsigned int` chỉ có :math:`32` bit. Điều này hợp lý vì CAST cipher có một phép cộng modulo :math:`2^{32}`, nghĩa là có liên quan đến hình vẽ.

Mình cũng sẽ dùng quy nạp để chứng minh khi :math:`u + v \geqslant 2^n` thì :math:`f_{2n}` nhận giá trị :math:`1`.

Với :math:`n = 1`, hàm :math:`f_2(x_1, x_2) = x_1 x_2` nhận giá trị :math:`1` khi :math:`x_1 = x_2 = 1`. Lúc này :math:`u = x_1 = 1` và :math:`v = x_2 = 1` nên :math:`u + v = 2 \geqslant 2^1`. Như vậy mệnh đề đúng với :math:`n = 1`.

Giả thiết quy nạp: giả sử mệnh đề đúng với :math:`n = k \geqslant 1`, nghĩa là hàm boolean

.. math:: f_{2k}(x_1, \ldots, x_k, x_{k+1}, \ldots, x_{2k}) = 1

khi :math:`u + v \geqslant 2^k` với

.. math:: 

    u & = x_1 + 2 x_2 + \ldots + 2^{k-1} x_k, \\
    v & = x_{k+1} + 2 x_{k+2} + \ldots + 2^{k-1} x_{2k}.

Với :math:`n = k + 1`, xét hàm

.. math:: f_{2k+2}(x_1, \ldots, x_k, y, x_{k+1}, \ldots, x_{2k}, z) = \bigoplus_{i=1}^k x_i x_{i+k} \left[\prod_{j=i+1}^k (x_j \oplus x_{j+k}) \cdot (y \oplus z)\right] \oplus yz.

Mình cũng sẽ có bốn trường hợp cho :math:`(y, z)`:

1. Khi :math:`y = z = 0` thì :math:`f_{2k+2} = 0` với mọi :math:`(x_1, \ldots, x_{2k})` nên chúng ta bỏ qua.
2. Khi :math:`y = 1` và :math:`z = 0` thì :math:`f_{2k+2} \equiv f_{2k}` như chứng minh ở phần trên. Khi đó :math:`f_{2k+2}` bằng :math:`1` tại các vector :math:`(x_1, \ldots, x_{2k})` khiến :math:`f_{2k}` bằng :math:`1`, nói cách khác là

.. math:: 

    u' & = x_1 + 2 x_2 + \ldots + 2^{k-1} x_k + 2^k y = u + 2^k y, \\
    v' & = x_{k+1} + 2 x_{k+2} + \ldots + 2^{k-1} x_{2k} + 2^k z = v + 2^k z.

Với :math:`y = 1` và :math:`z = 0` thì

.. math:: u' + v' = u + 2^k y + v = (u + v) + 2^k y \geqslant 2^k + 2^k \cdot 1 = 2^{k+1}.

Như vậy nếu :math:`y = 1` và :math:`z = 0` thì mệnh đề cần chứng minh đúng cho :math:`n = k + 1`.

1. Khi :math:`y = 0` và :math:`z = 1`, chứng minh tương tự trường hợp :math:`y = 1` và :math:`z = 0`.
2. Khi :math:`y = 1` và :math:`z = 1` thì :math:`f_{2k+2}` luôn bằng :math:`1`, tương ứng với

.. math:: u' + v' = u + 2^k y + v + 2^k z = (u + v) + 2^k \cdot (1 + 1) \geqslant 2^k + 2 \cdot 2^k > 2^{k+1}.

Như vậy mệnh đề đúng cho :math:`n = k + 1` với mọi trường hợp :math:`(y, z)` và ta có điều cần chứng minh.

Open competition: NSUCRYPTO lightweight cipher
==============================================

Đây là bài 6 ở round 2.

Đề bài
------

.. note:: 
    
    Problem for special prize

NSUCRYPTO team tổ chức cuộc thi phát triển mã khối light-weight mới.

Một số yêu cầu:

- Block size là :math:`64` bits.
- Key size là :math:`80`, :math:`96` hoặc :math:`64` bits.
- Số vòng là :math:`32`.
- Cấu trúc xây dựng tùy ý. Nghĩa là SPN, ARX, Feistel đều có thể sử dụng, thậm chí là một cách xây dựng mới.

Thí sinh cần xem xét PRESENT light-weight cipher (2007) và cố gắng tìm ra điều có thể làm tốt hơn mã khối này.

Hãy so sánh đáp án của bạn với PRESENT: khi thực hiện, khi chống phá mã (linear, differential, algebraic, ...) và đưa ra các giải thích cần thiết.

Lời giải
--------

Đây là bài có tính mở rất cao nhưng để tìm ra điều gì đó mới (và hiệu quả) trong 7 ngày là rất khó. Do đó lúc thi mình đã xây dựng một block cipher mới tốt hơn PRESENT về mặt lưu trữ, còn các tính chất khác như kháng phá mã thì mình không đề cập tới. Bài này mình được 6/10 điểm.

Về PRESENT thì mình đã có tóm tắt trong một bài viết của blog này nên mình không viết lại. PRESENT cipher là thuật toán light-weight, tức là thuật toán được thiết kế nhỏ gọn để chạy trên các thiết bị có bộ xử lý và lưu trữ nhỏ (như các hệ thống nhúng).

Cải tiến của mình dựa trên việc PRESENT sử dụng mạng SP nên sẽ cần lưu trữ phép biến đổi để mã hóa và phép biến đổi ngược để giải mã:

- cần lưu trữ đồng thời S-box là :math:`S[x]` và inverse S-box là :math:`S^{-1}[x]`;
- cần lưu trữ biến đổi tuyến tính pLayer và biến đổi ngược của nó;
- addRoundKey có phép biến đổi ngược là chính nó nên mình bỏ qua.

Như vậy, ta tốn hai phần bộ nhớ: một cho phép biến đổi mã hóa và một cho phép biến đổi ngược để giải mã.

Làm sao để cải tiến? Mình dùng mô hình Feistel, hoặc mô hình Feistel tổng quát (generalize Feistel network) để xây dựng mã khối mới.

Khối đầu vào (plaintext) có :math:`64` bits sẽ được chia thành :math:`4` phần bằng nhau, mỗi phần có :math:`16` bits:

.. math:: P = (X^0, X^1, X^2, X^3).

Khóa :math:`K` có :math:`64` bits sẽ sinh ra các khóa con :math:`K_0`, :math:`K_1`, ..., :math:`K_{31}` cho :math:`32` vòng.

Tại vòng thứ :math:`i` với :math:`0 \leqslant i \leqslant 31`, :math:`X^{i+4}` được tính như sau

.. math:: X^{i+4} = X^i \oplus F(X^{i+1} \oplus X^{i+2} \oplus X^{i+3}, K_i),

trong đó :math:`F: \mathbb{F}_2^{16} \times \mathbb{F}_2^{16} \to \mathbb{F}_2^{16}` là round function.

.. figure:: solution-6.*

Ciphertext sau :math:`32` vòng sẽ là trạng thái cuối viết theo thứ tự ngược lại, nghĩa là

.. math:: C = (X^{35}, X^{34}, X^{33}, X^{32}).

**Round function.** Round function :math:`F: \mathbb{F}_2^{16} \times \mathbb{F}_2^{16} \to \mathbb{F}_2^{16}` gồm ba phép biến đổi là cộng modulo :math:`2^{16}`, S-box và linear layer.

1. Phép cộng modulo :math:`2^{16}`, đặt :math:`Y = X^i \oplus X^{i+1} \oplus X^{i+2}`, khi đó ta tính :math:`Y + K_i \pmod{2^{16}}` và kí hiệu là :math:`Y \boxplus K_i`.
2. S-box là ánh xạ :math:`S: \mathbb{F}_2^4 \to \mathbb{F}_2^4`, trong đó :math:`16` bits từ phép cộng trên được chia thành :math:`4` phần, mỗi phần có :math:`4` bits đi qua S-box. Sau đó ta nối các kết quả lại thành :math:`16` bits mới.
3. Linear layer :math:`L`. Ta xor :math:`X` với :math:`X \lll 11`, trong đó :math:`\lll` là phép dịch :math:`11` bits sang trái.

Như vậy

.. math:: S(X) = S(a_0, a_1, a_2, a_3) = (\mathtt{Sbox}(a_0), \mathtt{Sbox}(a_1), \mathtt{Sbox}(a_2), \mathtt{Sbox}(a_3)),

với :math:`X = (a_0, a_1, a_2, a_3) \in \mathbb{F}_2^{16}` và :math:`a_i \in \mathbb{F}_2^4`.

S-box được cho bởi bảng sau

+--------------+------------------+-----------+------------------+------------------+-----------+------------------+-----------+-----------+-----------+-----------+------------------+------------------+------------------+------------------+------------------+------------------+
| :math:`x`    | :math:`0`        | :math:`1` | :math:`2`        | :math:`3`        | :math:`4` | :math:`5`        | :math:`6` | :math:`7` | :math:`8` | :math:`9` | :math:`\text{A}` | :math:`\text{B}` | :math:`\text{C}` | :math:`\text{D}` | :math:`\text{E}` | :math:`\text{F}` |
+==============+==================+===========+==================+==================+===========+==================+===========+===========+===========+===========+==================+==================+==================+==================+==================+==================+
| :math:`S(x)` | :math:`\text{C}` | :math:`0` | :math:`\text{F}` | :math:`\text{A}` | :math:`2` | :math:`\text{B}` | :math:`9` | :math:`5` | :math:`8` | :math:`3` | :math:`\text{D}` | :math:`7`        | :math:`1`        | :math:`\text{E}` | :math:`6`        | :math:`4`        |
+--------------+------------------+-----------+------------------+------------------+-----------+------------------+-----------+-----------+-----------+-----------+------------------+------------------+------------------+------------------+------------------+------------------+

Linear layer như sau:

.. math:: L(X) = X \oplus (X \lll 11).

**Round key.** Khóa đầu vào :math:`K` có :math:`64` bits sẽ được chia thành :math:`8` phần :math:`K_0`, :math:`K_1`, ..., :math:`K_7`. Các vòng dùng khóa con như sau:

1. Các vòng 0, 1, ..., 7 sử dụng lần lượt các khóa :math:`K_0`, :math:`K_1`, ..., :math:`K_7`.
2. Các vòng 8, 9, ..., 15 sử dụng lần lượt các khóa :math:`K_0`, :math:`K_1`, ..., :math:`K_7`.
3. Các vòng 16, 17, ..., 23 sử dụng lần lượt các khóa :math:`K_0`, :math:`K_1`, ..., :math:`K_7`.
4. Các vòng 24, 25, ..., 31 sử dụng lần lượt các khóa :math:`K_7`, :math:`K_6`, ..., :math:`K_0`.

**Decryption.** Đẻ giải mã ta thực hiện theo thứ tự ngược lại. Giả sử ciphertext là

.. math:: C = (X^{35}, X^{34}, X^{33}, X^{32}),

ta viết theo thứ tự ngược lại là

.. math:: C_{32} = (X^{32}, X^{33}, X^{34}, X^{35}).

Tại vòng thứ :math:`i` với :math:`i = 31, \ldots, 0`, :math:`X^i` sẽ được tính bởi

.. math:: X^i = X^{i+4} \oplus F(X^{i+1} \oplus X^{i+2} \oplus X^{i+3}, K_i),

trong đó :math:`F` là round function được định nghĩa ở trên. Cuối cùng plaintext là

.. math:: P = (X^0, X^1, X^2, X^3).

A nonlinear generator
=====================

Đây là bài 4 ở round 1 và bài 7 ở round 2.

Đề bài
------

Alice tạo ra một bộ sinh khóa như hình sau:

.. figure:: problem-7.png

Bộ sinh khóa gồm hai thanh ghi độ dài :math:`47` và :math:`49` với các hàm không tuyến tính (non-linear feedback).

Tại mỗi thời điểm :math:`t = 1,2,\ldots`, mỗi thanh ghi sẽ sinh keystream tại trạng thái ở thời điểm :math:`t` và sau đó chuyển sang trạng thái ở thời điểm :math:`t+1`.

Cụ thể, trạng thái của thanh ghi ở thời điểm :math:`t` là

.. math:: A(t) = (a_1(t), \ldots, a_{47}(t)) \, \text{và} \, B(t) = (b_1(t), \ldots, b_{49}(t)).

Hai thanh ghi được dịch chuyển đồng thời. Ví dụ

.. math:: A(t+1) = (a_1(t), \ldots, a_{47}(t), (a_1(t) \& a_2(t)) \oplus a_{13}(t) \oplus a_{44}(t)).

Keystream :math:`\gamma` với độ dài :math:`8192` tạo bởi bộ sinh khóa trên được ghi lại trong file `keystream.txt`. Ngoài ra chúng ta cũng có trạng thái :math:`A(8192)` và :math:`B(8192)` là:

.. math:: 

    A(8192) & = (00101001110001001110111001100001010100000101110), \\
    B(8192) & = (0000010000101001000011000001010111001110000100101).

Bạn có thể tìm lại trạng thái khởi tạo :math:`A(1)` và :math:`B(1)` không?

Lời giải
--------

Bài này chúng ta bruteforce từ cặp bit :math:`A(i)` và :math:`B(i)` bắt đầu từ vị trí :math:`8191` về :math:`1`.

Mình sẽ viết lại dãy của đề bài. Dãy trên và dãy dưới lần lượt là :math:`a_0, a_1, \ldots` và :math:`b_0, b_1, \ldots` và các phần tử sau được sinh ra từ các phần tử trước theo công thức

.. math:: a_{i+47} = (a_i \& a_{i+1}) \oplus a_{i+12} \oplus a_{i+43}

và

.. math:: b_{i+49} = (b_i \& b_{i+1}) \oplus b_{i+10} \oplus b_{i+47}.

Keystream :math:`\{ g_n \}` sẽ được sinh theo công thức

.. math:: 

    g_i & = a_i \oplus a_{i+3} \oplus (a_{i+7} \& a_{i+8}) \\
        & \oplus b_i \oplus (b_{i+4} \& b_{i+5}) \oplus b_{i+7}.

Như vậy mình sẽ bruteforce từ vị trí :math:`i` từ :math:`8190` về :math:`0`. Ở mỗi vị trí mình có hai trường hợp :math:`a_i` và hai trường hợp :math:`b_i`. Nếu đặt được tới :math:`i = 0` thì đây là dãy cần tìm.

Keystream là một chuỗi :math:`8192` bits nên mình sẽ lưu ở file :download:`keystream.txt <keystream.txt>`.

.. code-block:: python

    from itertools import product
    import sys

    sys.setrecursionlimit(100000)

    g = list(map(int, open("keystream.txt").read()))

    def check_a(val, x, i):
        return x[i+47] == (val & x[i+1]) ^ x[i+12] ^ x[i+43]

    def check_b(val, y, i):
        return y[i+49] == (val & y[i+1]) ^ y[i+10] ^ y[i+47]

    def check_g(valx, valy, x, y, z, i):
        return z[i] == valx ^ x[i+3] ^ (x[i+7] & x[i+8]) ^ valy ^ (y[i+4] & y[i+5]) ^ y[i+7]

    a = [-1] * 8191 + list(map(int, '00101001110001001110111001100001010100000101110'))
    b = [-1] * 8191 + list(map(int, '0000010000101001000011000001010111001110000100101'))

    def bruteforce(i):
        if i == -1:
            assert "".join(map(str, a[:47])) == "01111100001110000110010001011000110000110011110"
            assert "".join(map(str, b[:49])) == "1100110011010001010101000101110100011011010010110"
            return
        else:
            for ai, bi in product(range(2), repeat=2):
                if check_a(ai, a, i) and check_b(bi, b, i) and check_g(ai, bi, a, b, g, i):
                    a[i], b[i] = ai, bi
                    bruteforce(i-1)
                    a[i], b[i] = -1, -1

    bruteforce(8190)

Bài này được giải bởi bạn Uyên và là BEST SOLUTION. Điều thú vị là rất nhiều đội được BEST SOLUTION cho bài này :)))

Unsecure SP-network
===================

Đây là bài 5 ở round 1 và bài 8 ở round 2.

Đề bài
------

Bob có nghe về mạng SP và quyết định xây dựng mật mã của riêng mình.

Block size (kích thước khối) là :math:`32` bits. Bob tạo S-boxes kích thước :math:`2 \times 2` là :math:`P`-layer sử dụng một phần của secret key.

Ở đây :math:`P` là một biến đổi tuyến tính :math:`P : \mathbb{F}_2^{32} \to \mathbb{F}_2^{32}`, nghĩa là

.. math:: P(x \oplus y) = P(x) \oplus P(y)

với mọi :math:`x, y \in \mathbb{F}_2^{32}`.

Ngoài ra, secret key là :math:`K \in \mathbb{F}_2^{128}`. Với nó Bob đặt

.. math:: K^i = (K_{32 (i \bmod 4) + 1}, \ldots, K_{32(i \bmod 4) + 32})

có độ dài :math:`32` với mọi :math:`i \in \{ 1, \ldots, 100 \}`.

Như vậy vòng thứ :math:`i` của mã khối sẽ như sau:

.. math:: r_i(x) = P(S(x_1 \oplus K_1^i, x_2 \oplus K_2^i), S(x_3 \oplus K_3^i, x_4 \oplus K_4^i), \ldots, S(x_{31} \oplus K_{31}^i, x_{32} \oplus K_{32}^i))

với :math:`x \in \mathbb{F}_2^{32}`.

Ciphertext sẽ là

.. math:: c = K^{100} \oplus r_{99}(r_{98}(\ldots r_1(m)))

với :math:`m` là plaintext ban đầu, :math:`m = (m_1, \ldots, m_{32})` và :math:`m_i \in \mathbb{F}_2`.

Tuy nhiên Bob nhanh chóng nhận ra Carol có thể đọc được plaintext mà không gặp vấn đề nếu Carol biết :math:`100` cặp plaintext và ciphertext bất kì.

Tại sao cô ấy làm được?

Lời giải
--------

Giả sử việc mã hóa có dạng :math:`C = \mathtt{Enc}(P)`. Mình sẽ chứng minh rằng với hai plaintext :math:`P` và :math:`P'`, nếu ciphertext tương ứng là :math:`C` và :math:`C'` thì

.. math:: C \oplus C' = \mathtt{Enc}(P \oplus P').

Một điều khá buồn cười là bài này mình mất kha khá thời gian vì những suy nghĩ ... vĩ mô. Theo đề bài có thể nhận thấy S-box :math:`S` là ánh xạ từ :math:`\mathbb{F}_2^2` tới :math:`\mathbb{F}_2^2`. Theo quy tắc nhân có tất cả :math:`2^{2^2} = 16` ánh xạ từ :math:`\mathbb{F}_2^2` tới :math:`\mathbb{F}_2` (số lượng hàm boolean hai biến). Do đó có :math:`16^2 = 256` trường hợp S-box :math:`S`.

Đối với các S-box tuyến tính hoặc affine thì câu chuyện không phải vấn đề. Tuy nhiên các trường hợp khác rất khó kiểm soát. Lúc này bạn Uyên nói với mình có :math:`4! = 24` trường hợp của S-box thôi, là số lượng hoán vị trên tập :math:`\{ 0, 1, 2, 3 \}`. Lý do là vì thuật toán mã hóa sử dụng mạng SP, do đó mỗi phép biến đổi phải có phép biến đổi ngược. Chân lý đây rồi, ánh sáng đây rồi :v :v :v Vậy mà mình nghĩ mãi, haizz.

Ý tưởng của mình là sử dụng phá mã vi sai (differential cryptanalysis).

Với ánh xạ :math:`M: \mathbb{F}_2^n \to \mathbb{F}_2^n` mình gọi:

1. **Input differential** là :math:`x_1 \oplus x_2`.
2. **Output differential** là :math:`M(x_1) \oplus M(x_2)`.

Mình dùng SageMath để kiểm tra nhanh phân bố vi sai trên :math:`24` hoán vị (ứng với :math:`24` S-box).

.. code-block:: python

    import itertools
    from sage.crypto.sbox import SBox

    for perm in itertools.permutations(range(4)):
        print(f"S-box: {perm}")
        print(SBox(perm).difference_distribution_table())
        print()

Một dấu hiệu chung cho mọi S-box là nếu input differential cố định thì output differential cũng cố định.

Ví dụ, với S-box tương ứng với hoán vị

.. math:: S = \begin{pmatrix} 0 & 1 & 2 & 3 \\ 1 & 2 & 0 & 3 \end{pmatrix}

thì bảng phân bố vi sai là

+------------+------------------------+------------------------+------------------------+------------------------+
|            | :math:`00`             | :math:`01`             | :math:`10`             | :math:`11`             |
+------------+------------------------+------------------------+------------------------+------------------------+
| :math:`00` | :math:`\color{red}{4}` | :math:`0`              | :math:`0`              | :math:`0`              |
+------------+------------------------+------------------------+------------------------+------------------------+
| :math:`01` | :math:`0`              | :math:`0`              | :math:`0`              | :math:`\color{red}{4}` |
+------------+------------------------+------------------------+------------------------+------------------------+
| :math:`10` | :math:`0`              | :math:`\color{red}{4}` | :math:`0`              | :math:`0`              |
+------------+------------------------+------------------------+------------------------+------------------------+
| :math:`11` | :math:`0`              | :math:`0`              | :math:`\color{red}{4}` | :math:`0`              |
+------------+------------------------+------------------------+------------------------+------------------------+

Theo bảng trên, nếu input differential là :math:`10` thì output differential chắc chắn là :math:`01`.

Như vậy mình có nhận xét sau.

.. prf:remark:: 
    :label: nsu24-rmk-sp

    Với S-box bất kì là hoán vị trên tập :math:`\{ 0, 1, 2, 3 \}`, nếu input differential cố định thì output differential cũng cố định.

Đầu tiên mình cần viết lại các kí hiệu trong bài này.

Plaintext có :math:`32` bit:

.. math:: m = (m_1, \ldots, m_{32}), \quad m_i \in \mathbb{F}_2.

S-box là hoán vị trên tập :math:`\{ 0, 1, 2, 3 \}`. Nói cách khác S-box là song ánh :math:`S` từ :math:`\mathbb{F}_2^2` tới :math:`\mathbb{F}_2^2`.

Đặt :math:`\mathcal{S}` là ánh xạ biến đổi :math:`32` bit thành :math:`32` bit mới với S-box, nghĩa là

.. math:: 

    S : & \ \mathbb{F}_2^{32} \times \mathbb{F}_2^{32} \to \mathbb{F}_2^{32} \\
        & (x, K) \mapsto X,

trong đó:

- :math:`x = (x_1, \ldots, x_{32})` là khối :math:`32` bit
- :math:`K = (K_1, \ldots, K_{32})` là khóa con ở vòng tương ứng
- :math:`X = (X_1, \ldots, X_{32})` nhận được từ

.. math:: 
    
    \begin{array}{ccl}
        (X_1, X_2) & = & S(x_1 \oplus K_1, x_2 \oplus K_2), \\
        (X_3, X_4) & = & S(x_3 \oplus K_3, x_4 \oplus K_4), \\
        \cdots \\
        (X_{31}, X_{32}) & = & S(x_{31} \oplus K_{31}, x_{32} \oplus K_{32}).
    \end{array}

Biến đổi tuyến tính là ánh xạ :math:`P` từ :math:`\mathbb{F}_2^{32}` tới :math:`\mathbb{F}_2^{32}`.

Secret key là :math:`K \in \mathbb{F}_2^{128}`. Subkey ở vòng thứ :math:`i` nhận được từ :math:`K` theo công thức

.. math:: K^i = (K_{32 (i \bmod 4) + 1}, \ldots, K_{32 (i \bmod 4) + 32}),

với :math:`i \in \{ 1, \ldots, 100 \}`. Mỗi subkey :math:`K^i` có độ dài :math:`32` bit.

Biến đổi ở vòng thứ :math:`i` là

.. math:: r_i(x) = P(\mathcal{S}(x, K^i)).

Ciphertext sau :math:`100` vòng sẽ là

.. math:: c = K^{100} r_{99}(r_{98}(\ldots (r_1(m)))).

Tiếp theo, sử dụng differential attack mình sẽ tìm liên hệ known-plaintext. Mình xét vòng đầu tiên trước.

Giả sử mình có hai plaintext là

.. math:: m = (m_1, \ldots, m_{32}) \ \text{và} \ m' = (m_1', \ldots, m_{32}') \in \mathbb{F}_2^{32}.

Ta có

.. math:: 

    (m_1, m_2) \rightarrow S(m_1 \oplus K_1^1, m_2 \oplus K_2^1) = (X_1, X_2), \\
    (m_1', m_2') \rightarrow S(m_1' \oplus K_1^1, m_2' \oplus K_2^1) = (X_1', X_2').

Input differential cho S-box là

.. math:: (m_1 \oplus K_1^1 \oplus m_1' \oplus K_1^1, m_2 \oplus K_2^1 \oplus m_2' \oplus K_2^1) = (m_1 \oplus m_1', m_2 \oplus m_2').

Ở đây subkey không ảnh hưởng input differential và đây là yếu tố quan trọng cần chú ý.

Nếu mình cố định input differential :math:`(m_1 \oplus m_1', m_2 \oplus m_2')` thì output differential

.. math:: S(m_1 \oplus K_1^1, m_2 \oplus K_2^1) \oplus S(m_1' \oplus K_1^1, m_2' \oplus K_2^1) = (X_1, X_2) \oplus (X_1', X_2) = (X_1 \oplus X_1', X_2 \oplus X_2')

cũng cố định. Tương tự cho các cặp còn lại :math:`(m_3, m_4)`, ..., :math:`(m_{31}, m_{32})`.

Như vậy ở vòng đầu ta có

.. math:: 

    & r_1(m) = P(\mathcal{S}(m, K^1)) = P(X_1, X_2, \ldots, X_{32}), \\
    & r_1(m') = P(\mathcal{S}(m', K^1)) = P(X_1', X_2', \ldots, X_{32}').

Suy ra

.. math:: r_1(m) \oplus r_1(m') = P(X_1, \ldots, X_{32}) \oplus P(X_1', \ldots, X_{32}') = P(X_1 \oplus X_1', \ldots, X_{32} \oplus X_{32}')

vì :math:`P` là biến đổi tuyến tính. Rõ ràng nếu :math:`X_i \oplus X_i'` cố định với mọi :math:`i = 1, \ldots, 32` thì kết quả :math:`r_1(m) \oplus r_1(m')` cũng cố định theo.

Áp dụng kết quả này cho :math:`99` vòng. Ở vòng cuối (vòng :math:`100`) ta XOR với :math:`K^{100}` nhưng thực ra là

.. math:: 
    
    c \oplus c' & = (K^{100} \oplus r_{99}(r_98)(\ldots r_1(m))) \oplus (K^{100} \oplus r_{99}(r_{98}(\ldots r_1(m')))) \\
                & = r_{99}(r_98)(\ldots r_1(m)) \oplus r_{99}(r_{98}(\ldots r_1(m'))),

tức là :math:`K^{100}` cũng không ảnh hưởng differential như :math:`K_1, \ldots, K_{99}`.

Tóm lại mình nhận được kết quả sau.

.. prf:remark:: 
    :label: nsu24-rmk-sp-solve

    Nếu ta biết plaintext :math:`P` và ciphertext tương ứng là :math:`C`, thì với mọi ciphertext :math:`C'` mới nào đó ta luôn có thể tìm lại được plaintext tương ứng. Nói cách khác là chú ý ở đầu bài

    .. math:: C \oplus C' = \mathtt{Enc}(P \oplus P').

.. admonition:: Chứng minh
    :class: danger

    Đặt :math:`DDT_S` là ánh xạ từ input differential thành output differential của S-box. Do input differential cố định thì output differential, :math:`DDT_S` sẽ nhận được từ bảng phân bố vi sai bằng cách, nếu phần tử ở hàng :math:`i` và cột :math:`j` bằng :math:`4` thì :math:`DDT_S(i) = j`.

    VÍ dụ, với S-box

    .. math:: S = \begin{pmatrix} 0 & 1 & 2 & 3 \\ 1 & 2 & 0 & 3 \end{pmatrix}

    như trên thì

    .. math:: DDT_S = \begin{pmatrix} 0 & 1 & 2 & 3 \\ 0 & 3 & 1 & 2 \end{pmatrix}.

    Rõ ràng :math:`DDT_S` là hoán vị, hay song ánh. Do đó tồn tại biến đổi ngược

    .. math:: DDT_S^{-1} = \begin{pmatrix} 0 & 1 & 2 & 3 \\ 0 & 2 & 3 & 1 \end{pmatrix}.

    Đặt :math:`P^{-1}` là nghịch đảo của :math:`P`.

    Giả sử :math:`c = (c_1, \ldots, c_{32})` và :math:`c' = (c_1', \ldots, c_{32}')` là các ciphertexts.

    Đặt :math:`P^{-1}(c \oplus c') = (C_1, \ldots, C_{32})`. Áp dụng :math:`DDT_S^{-1}` ta có

    .. math:: DDT_S^{-1}(C_1, C_2), DDT_S^{-1}(C_3, C_4), \ldots, DDT_S^{-1}(C_{31}, C_{32}),

    và tương tự cho :math:`98` vòng còn lại. Cuối cùng ta sẽ nhận được differential của các plaintexts :math:`P` và :math:`P'`.

    Do đã biết :math:`P` và differential :math:`P \oplus P'` vừa tìm được, ta có thể tìm :math:`P'`.

.. code-block:: python

    # binmatrix.py

    # https://github.com/xiangzejun/binary_matrix
    # For feedback or questions, pleast contact at xiangzejun@iie.ac.cn

    # Implemented by Xiang Zejun, State Key Laboratory of Information Security, 
    # Institute Of Information Engineering, CAS

    from functools import reduce

    class DataError(Exception):
        """
        Define my data exception.
        Check whether the elements of the matrxi are binaries.
        """
        def __init__(self, x, y):
            """
            store the coordinate of the entry which is not binary.
            """
            self.x = x
            self.y = y

        def printError(self):
            print("The element at [{0}][{1}] is NOT binary!".format(self.x, self.y))

    class FormatError(Exception):
        """
        Define my format exception.
        Check whether input is a matrix or a square matrix.
        """
        def __init__(self, s):
            self.error = "The input is " + s
        def printError(self):
            print(self.error)

    class RankError(Exception):
        """
        Define my rank exception.
        Check whether the square matrix is full rank when calculating its inverse. 
        """
        def __init__(self, r):
            self.r = r
        def printError(self):
            print("The matrix is NOT full rank. (rank = {0})".format(self.r))

    class BinMatrix:
        def __init__(self, m = [[1]]):
            """
            Initilize a matrix.
            """
            self.m = m
            self.r_len = len(self.m) # row number
            self.c_len = len(self.m[0]) # column number
            # self.length = len(self.m)

        def __convertMatrixToInt(self):
            """
            Convert each row of the binary matrix to an integer.
            """
            return [int(reduce(lambda x , y: x + y, map(str, self.m[i])), 2) 
                for i in range(self.r_len)]

        def __appendUnitMatrix(self):
            """
            Append a unit matrix to m_int.
            """
            m_int = self.__convertMatrixToInt()
            return [(1 << (self.r_len + self.c_len - 1 - i)) ^ m_int[i] 
                for i in range(self.r_len)]

        def __chooseElement(self, r, c, m_int):
            """
            Choose a none-zero row started from position [r][c].
            """
            
            err = "The row index can not exceed the column index in row-reduced echelon matrix."
            assert r <= c, err
        
            if c == self.c_len:
                return None
            else:
                mask = (1 << (self.c_len - 1 - c))
                temp = [(m_int[i] & mask) for i in range(r, self.r_len)]
                if mask not in temp:
                    return self.__chooseElement(r, c + 1, m_int)
                else:
                    return (temp.index(mask) + r, c)

        @staticmethod
        def __switchRows(r1, r2, m_int):
            """
            Switch r1-th and r2-th rows of m_int.
            """
            temp = m_int[r1]
            m_int[r1] = m_int[r2]
            m_int[r2] = temp

        def __addRows(self, r, c, m_int):
            """
            Add the r-th row to all the other rows if the c-th element of 
            the corresponding rows are nonzero.
            """
            mask = (1 << (self.c_len - 1 - c))
            it = list(range(self.r_len))
            it.remove(r)
            for i in it:
                if m_int[i] & mask != 0:
                    m_int[i] ^= m_int[r]

        
        def __isMatrix(self):
            """
            Check whether the input is a matrix.
            """
            if [len(l) for l in self.m].count(self.c_len) != self.r_len:
                raise FormatError("NOT a matrix!")
            else:
                pass

        def __isSquareMatrix(self):
            """
            Check whether the input is a square matrix.
            """
            if [len(l) for l in self.m].count(self.r_len) != self.r_len:
                raise FormatError("NOT a Square matrix!")
            else:
                pass

        def __isBinary(self):
            """
            Check whether the entrys in the input are binaries.
            """
            for i in range(len(self.m)):
                for j in range(len(self.m[i])):
                    if self.m[i][j] not in [0,1]:
                        raise DataError(i, j)
                    else:
                        pass

        def rank(self):
            """
            Calculate the Rank of the matrix.
            """
            self.__isMatrix()
            self.__isBinary()
            m_int = self.__convertMatrixToInt()
            r = 0
            c = 0
            for i in range(self.r_len):
                arg = self.__chooseElement(r, c, m_int)
                if arg != None:
                    r_temp = arg[0]
                    c = arg[1]
                    self.__switchRows(r, r_temp, m_int)
                    self.__addRows(r, c, m_int)
                    r += 1
                    c += 1  
                else:
                    return r
            return self.r_len

        def det(self):
            """
            Calculate the Det of the matrix.
            """
            self.__isSquareMatrix()
            self.__isBinary()
            if self.rank() == self.r_len:
                return 1
            else:
                return 0

        def inv(self):
            """
            Calculate the inverse of the matrix.
            """
            self.__isSquareMatrix()
            self.__isBinary()
            m_adj = self.__appendUnitMatrix()
            r = 0
            c = 0
            for i in range(self.r_len):
                arg = self.__chooseElement(r, c, m_adj)
                if arg != None:
                    r_temp = arg[0]
                    c = arg[1]
                    self.__switchRows(r, r_temp, m_adj)
                    self.__addRows(r, c, m_adj)
                    r += 1
                    c += 1
                else:
                    raise RankError(r)
            return [
                list(map(int, list(format((m_adj[i] >> self.c_len), "0" + str(self.r_len) + "b")))) 
                for i in range(self.r_len)]

.. code-block:: python

    # cipher.py

    from binmatrix import BinMatrix
    import numpy as np
    import random

    sbox = list(range(4))
    random.shuffle(sbox)    # generate random S-box which is permuation

    P = None
    while True: # generate random invertible matrix on F_2
        P = np.random.randint(2, size=(32, 32))
        if np.linalg.det(P) % 2 == 1:
            break

    P = [row.tolist() for row in P] # convert from numpy.narray to list
    P_inv = BinMatrix(P).inv()      # calculate inverse of P

    difference_distribution_table = [[0 for _ in range(4)] for __ in range(4)]
    # i-th row -> input differential
    # o-th row -> output differential
    for a in range(4):
        for b in range(4):
            i = a ^ b
            o = sbox[a] ^ sbox[b]
            difference_distribution_table[i][o] += 1

    sbox_diff = [0] * 4
    # calculate DDT_S
    for i in range(4):
        for j in range(4):
            if difference_distribution_table[i][j] == 4:
                sbox_diff[i] = j

    sbox_diff_inv = [sbox_diff.index(i) for i in range(4)] # DDT_S^{-1}

    def matmul(M: list[list[int]], v: list[int]) -> list[int]:
        # multiplication of matrix M and vector v
        result = [0] * len(v)
        for i in range(len(v)):
            result[i] = sum(M[i][j] * v[j] for j in range(len(v))) % 2
        return result

    def encrypt(m: list[int], K: list[int]) -> list[int]:
        # encryption with plaintext m, key K
        Ki = [K[i:i+32] for i in range(0, len(K), 32)]
        pt = m.copy()
        for i in range(99):
            pt = [p ^ k for p, k in zip(pt, Ki[i % 4])]
            for j in range(0, len(pt), 2):
                z = (pt[j] << 1) + pt[j+1]  # get two bits for input of S-box
                z = sbox[z]
                pt[j] = z >> 1      # write two new bits
                pt[j+1] = z & 1     # after S-box
            pt = matmul(P, pt)
        pt = [p ^ k for p, k in zip(pt, Ki[100 % 4])]
        return pt

.. code-block:: python

    # solve.py

    import random
    from cipher import *

    pt1 = random.choices(range(2), k = 32)  # Known
    pt2 = random.choices(range(2), k = 32)  # Unknown

    K = random.choices(range(2), k = 128)

    ct1 = encrypt(pt1, K)   # Known
    ct2 = encrypt(pt2, K)   # Known

    ct_diff = [x ^ y for x, y in zip(ct1, ct2)] # ct1 ^ ct2

    for _ in range(99):
        ct_diff = matmul(P_inv, ct_diff)
        for i in range(0, len(ct_diff), 2):
            z = (ct_diff[i] << 1) + ct_diff[i+1]
            z = sbox_diff_inv[z]
            ct_diff[i] = z >> 1
            ct_diff[i+1] = z & 1

    pt2_guess = [x^y for x, y in zip(ct_diff, pt1)] # Recover pt2
    assert pt2 == pt2_guess

Một điều thú vị là có thể dùng nhiều S-box và quá trình tấn công vẫn tương tự. Ví dụ

.. math:: (x_1, \ldots, x_{32}) \xrightarrow{K^i} (S_1(x_1 \oplus K_1^i, x_2 \oplus K_2^i), S_2(x_3 \oplus K_3^i, x_4 \oplus K_4^i), \ldots, S_{16}(x_31 \oplus K_{31}^i, x_{32} \oplus K_{32}^i)),

với :math:`S_i` là hoán vị bất kì trên :math:`\{ 0, 1, 2, 3 \}`, :math:`i = 1, \ldots, 16`.

Ở đây ta sẽ áp dụng cùng phương pháp như trên nhưng ta sẽ tính :math:`DDT_{S_i}` cho mỗi S-box :math:`S_i`.

Lời giải hoàn chỉnh
-------------------

Thật ra mình đã đọc thiếu đề và chưa xét trường hợp S-box và :math:`P` là các phép biến đổi bí mật (giống secret key). Đây là lý do mình không được full điểm câu này.

S-box, theo phân tích của mình ở trên, thực chất là một ánh xạ affine. Nhắc lại ánh xạ affine là ánh xạ có dạng :math:`S(\bm{x}) = \bm{A} \cdot \bm{x} \oplus \bm{b}`, trong đó :math:`\bm{A}` là ma trận, :math:`\bm{x}` và :math:`\bm{b}` là các vector cột.

Khi đó, với hai đầu vào :math:`\bm{x}` và :math:`\bm{x}'` sao cho :math:`\bm{x} \oplus \bm{x}'` cố định (input differential) thì ta có

.. math:: S(\bm{x}) \oplus S(\bm{x}') = \bm{A} \cdot (\bm{x} \oplus \bm{x}')

cũng cố định do :math:`\bm{A}` đã xác định.

Theo đó toàn bộ quá trình encrypt là một ánh xạ affine lớn, do đó chúng ta hoàn toàn có thể tìm được ánh xạ affine đó nếu biết đủ :math:`32` vector độc lập tuyến tính.

Sử dụng `cipher.py` ở trên và đoạn code sau để giải:

.. code-block:: python

    import random
    from sage.all import random_vector, vector, GF, matrix, ones_matrix
    from cipher import encrypt

    random.seed(1333)

    K = [random.randrange(0, 2) for _ in range(128)]
    ms = [random_vector(GF(2), 32) for _ in range(100)]

    cs = [encrypt(list(map(int, m)), K) for m in ms]

    ms = matrix(GF(2), ms)
    cs = matrix(GF(2), cs)
    A = matrix(GF(2), 32, 32)
    b = vector(GF(2), 32)

    for i in range(32):
        for bb in range(2):
            try:
                res = ms.solve_right(cs[:, i] + bb * ones_matrix(GF(2), 100, 1))
                A[:, i] = res
                b[i] = bb
            except:
                pass

    u = random_vector(GF(2), 32)
    assert encrypt(list(map(int, u)), K) == list(map(int, u * A + b))

Ở đây mình viết plaintext ở dạng hàng. Giả sử plaintext và ciphertext là

.. math:: M = (m_1, \ldots, m_n), \quad C = (c_1, \ldots, c_n).

Ánh xạ affine của chúng ta tương ứng với

.. math:: (c_1, \ldots, c_n) = (m_1, \ldots, m_n) \cdot \bm{A} + (b_1, \ldots, b_n),

trong đó :math:`\bm{A}` là ma trận :math:`n \times n` (trong trường hợp bài này :math:`n = 32`).

Như vậy mình cần tìm ma trận :math:`\bm{A}` và vector :math:`\bm{b} = (b_1, \ldots, b_n)`. Nếu có :math:`T` phương trình như vậy

.. math:: 

    (c_{11}, \ldots, c_{1n}) & = (m_{11}, \ldots, m_{1n}) \cdot \bm{A} + (b_1, \ldots, b_n), \\
    (c_{21}, \ldots, c_{2n}) & = (m_{21}, \ldots, m_{2n}) \cdot \bm{A} + (b_1, \ldots, b_n), \\
    \cdots & = \cdots \\
    (c_{T1}, \ldots, c_{Tn}) & = (m_{T1}, \ldots, m_{Tn}) \cdot \bm{A} + (b_1, \ldots, b_n),

thì mình giải từng cột thứ :math:`i` của ma trận :math:`A` và từng số hạng :math:`b_i`. Nghĩa là

.. math:: 
    
    \begin{pmatrix} c_{11} \\ c_{12} \\ \vdots \\ c_{T1} \end{pmatrix} = 
    \begin{pmatrix} m_{11} & m_{12} & \cdots & m_{1n} \\ m_{21} & m_{22} & \cdots & m_{2n} \\ \vdots & \ddots & \ddots & \vdots \\ m_{T1} & m_{T2} & \cdots & m_{Tn} \end{pmatrix} \cdot
    \begin{pmatrix} a_{11} \\ a_{21} \\ \vdots \\ a_{n1} \end{pmatrix} + \begin{pmatrix} b_1 \\ b_1 \\ \vdots \\ b_1 \end{pmatrix}.

Như vậy chúng ta bruteforce :math:`b_1` và kiểm tra xem phương trình có nghiệm :math:`\begin{pmatrix} a_{11} \\ \vdots \\ a_{n1} \end{pmatrix}` không. Nếu có thì đây là kết quả cần tìm.

Tiến hành cho từng cột của :math:`\bm{A}` và từng phần tử :math:`b_i` sẽ tìm được ánh xạ affine.

Unknown function
================

Đây là bài 8 ở round 1 và bài 10 ở round 2.

Đề bài
------

Bob tạo một máy lượng tử :math:`M` mã hóa 4-bit word với 4-bit secret key :math:`k = (k_1, k_2, k_3, k_4)` theo mạch sau:

.. figure:: problem-10.png

Máy này thực hiện trên 4-bit plaintext :math:`x = (x_1, x_2, x_3, x_4)` với 4-qubit tương ứng, gọi là "plainstate", là :math:`\lvert x_1, x_2, x_3, x_4 \rangle`, tương tự với "keystate" là :math:`\lvert k_1, k_2, k_3, k_4 \rangle`.

Mô hình tính toán là

.. math:: \lvert x \rangle \lvert k \rangle \xrightarrow{M} \lvert x \rangle \lvert k \oplus f(x) \rangle,

trong đó

.. math:: f(x) = (f_1(x), f_2(x), f_3(x), f_4(x))

là hàm Boolean vectorial khả nghịch trên :math:`4` biến. Khi đó "cipherstate" là

.. math:: \lvert k_1 \oplus f_1(x), k_2 \oplus f_2(x), k_3 \oplus f_3(x), k_4 \oplus f_4(x) \rangle

và cuối cùng ta thu được ciphertext.

Alice có thể khôi phục secret key :math:`k` không nếu cô ấy không biết hàm :math:`f`?

Giả sử Alice có oracle access tới máy lượng tử với khóa cố định :math:`k` và thu được thông tin 

.. math:: f(0, 0, 0, 0) \oplus f(1, 1, 1, 1) \oplus f(1, 0, 0, 0) = c \in \mathbb{F}_2^4

với :math:`c` đã biết.

Lời giải
--------

Đặt :math:`\bm{x} = (x_1, x_2, x_3, x_4) \in \mathbb{F}_2^4`.


Kí hiệu bảng chân trị của các hàm bool :math:`f_1(\bm{x})`, :math:`f_2(\bm{x})`, :math:`f_3(\bm{x})` và :math:`f_4(\bm{x})` là

+-------------+-------------+-------------+-------------+---------------------+---------------------+---------------------+---------------------+
| :math:`x_1` | :math:`x_2` | :math:`x_3` | :math:`x_4` | :math:`f_1(\bm{x})` | :math:`f_2(\bm{x})` | :math:`f_3(\bm{x})` | :math:`f_4(\bm{x})` |
+=============+=============+=============+=============+=====================+=====================+=====================+=====================+
| :math:`0`   | :math:`0`   | :math:`0`   | :math:`0`   | :math:`m_0`         | :math:`n_0`         | :math:`p_0`         | :math:`q_0`         |
+-------------+-------------+-------------+-------------+---------------------+---------------------+---------------------+---------------------+
| :math:`0`   | :math:`0`   | :math:`0`   | :math:`1`   | :math:`m_1`         | :math:`n_1`         | :math:`p_1`         | :math:`q_1`         |
+-------------+-------------+-------------+-------------+---------------------+---------------------+---------------------+---------------------+
| :math:`0`   | :math:`0`   | :math:`1`   | :math:`0`   | :math:`m_2`         | :math:`n_2`         | :math:`p_2`         | :math:`q_2`         |
+-------------+-------------+-------------+-------------+---------------------+---------------------+---------------------+---------------------+
| :math:`0`   | :math:`0`   | :math:`1`   | :math:`1`   | :math:`m_3`         | :math:`n_3`         | :math:`p_3`         | :math:`q_3`         |
+-------------+-------------+-------------+-------------+---------------------+---------------------+---------------------+---------------------+
| :math:`0`   | :math:`1`   | :math:`0`   | :math:`0`   | :math:`m_4`         | :math:`n_4`         | :math:`p_4`         | :math:`q_4`         |
+-------------+-------------+-------------+-------------+---------------------+---------------------+---------------------+---------------------+
| :math:`0`   | :math:`1`   | :math:`0`   | :math:`1`   | :math:`m_5`         | :math:`n_5`         | :math:`p_5`         | :math:`q_5`         |
+-------------+-------------+-------------+-------------+---------------------+---------------------+---------------------+---------------------+
| :math:`0`   | :math:`1`   | :math:`1`   | :math:`0`   | :math:`m_6`         | :math:`n_6`         | :math:`p_6`         | :math:`q_6`         |
+-------------+-------------+-------------+-------------+---------------------+---------------------+---------------------+---------------------+
| :math:`0`   | :math:`1`   | :math:`1`   | :math:`1`   | :math:`m_7`         | :math:`n_7`         | :math:`p_7`         | :math:`q_7`         |
+-------------+-------------+-------------+-------------+---------------------+---------------------+---------------------+---------------------+
| :math:`1`   | :math:`0`   | :math:`0`   | :math:`0`   | :math:`m_8`         | :math:`n_8`         | :math:`p_8`         | :math:`q_8`         |
+-------------+-------------+-------------+-------------+---------------------+---------------------+---------------------+---------------------+
| :math:`1`   | :math:`0`   | :math:`0`   | :math:`1`   | :math:`m_9`         | :math:`n_9`         | :math:`p_9`         | :math:`q_9`         |
+-------------+-------------+-------------+-------------+---------------------+---------------------+---------------------+---------------------+
| :math:`1`   | :math:`0`   | :math:`1`   | :math:`0`   | :math:`m_{10}`      | :math:`n_{10}`      | :math:`p_{10}`      | :math:`q_{10}`      |
+-------------+-------------+-------------+-------------+---------------------+---------------------+---------------------+---------------------+
| :math:`1`   | :math:`0`   | :math:`1`   | :math:`1`   | :math:`m_{11}`      | :math:`n_{11}`      | :math:`p_{11}`      | :math:`q_{11}`      |
+-------------+-------------+-------------+-------------+---------------------+---------------------+---------------------+---------------------+
| :math:`1`   | :math:`1`   | :math:`0`   | :math:`0`   | :math:`m_{12}`      |  :math:`n_{12}`     | :math:`p_{12}`      | :math:`q_{12}`      |
+-------------+-------------+-------------+-------------+---------------------+---------------------+---------------------+---------------------+
| :math:`1`   | :math:`1`   | :math:`0`   | :math:`1`   | :math:`m_{13}`      | :math:`n_{13}`      | :math:`p_{13}`      | :math:`q_{13}`      |
+-------------+-------------+-------------+-------------+---------------------+---------------------+---------------------+---------------------+
| :math:`1`   | :math:`1`   | :math:`1`   | :math:`0`   | :math:`m_{14}`      | :math:`n_{14}`      | :math:`p_{14}`      | :math:`q_{14}`      |
+-------------+-------------+-------------+-------------+---------------------+---------------------+---------------------+---------------------+
| :math:`1`   | :math:`1`   | :math:`1`   | :math:`1`   | :math:`m_{15}`      | :math:`n_{15}`      | :math:`p_{15}`      | :math:`q_{15}`      |
+-------------+-------------+-------------+-------------+---------------------+---------------------+---------------------+---------------------+

Ở đây :math:`m_i` là giá trị của hàm :math:`f_1(\bm{x})` tại dòng thứ :math:`i` với :math:`0 \leqslant i \leqslant 15`. Tương tự cho :math:`n_i`, :math:`p_i` và :math:`q_i`.

Ta đã biết

.. math:: f(0, 0, 0, 0) \oplus f(1, 1, 1, 1) \oplus f(1, 0, 0, 0) = \bm{c} \in \mathbb{F}_2^4

với :math:`\bm{c}` đã biết.

Như vậy ta có

.. math:: 

    & f(0, 0, 0, 0) = (m_0, n_0, p_0, q_0), \\
    & f(1, 1, 1, 1) = (m_{15}, n_{15}, p_{15}, q_{15}), \\
    & f(1, 0, 0, 0) = (m_8, n_8, p_8, q_8),

suy ra

.. math:: \bm{c} = (m_0 \oplus m_{15} \oplus m_8, n_0 \oplus n_{15} \oplus n_8, p_0 \oplus p_{15} \oplus p_8, q_0 \oplus q_{15} \oplus q_8).

"Cipherstate"

.. math:: \lvert k_1 \oplus f_1(\bm{x}), k_2 \oplus f_2(\bm{x}), k_3 \oplus f_3(\bm{x}), k_4 \oplus f_4(\bm{x}) \rangle

chính là :math:`4` bit ciphertext

.. math:: (k_1 \oplus f_1(\bm{x}), k_2 \oplus f_2(\bm{x}), k_3 \oplus f_3(\bm{x}), k_4 \oplus f_4(\bm{x})).

Vì Alice có truy cập oracle tới máy với khóa cố định :math:`k` nên

1. Nếu Alice gửi plaintext :math:`(0, 0, 0, 0)` thì sẽ nhận lại ciphertext

.. math:: \bm{C}_0 = (k_1 \oplus m_0, k_2 \oplus n_0, k_3 \oplus p_0, k_4 \oplus q_0).

2. Nếu Alice gửi plaintext :math:`(1, 1, 1, 1)` thì sẽ nhận lại ciphertext

.. math:: \bm{C}_{15} = (k_1 \oplus m_{15}, k_2 \oplus n_{15}, k_3 \oplus p_{15}, k_4 \oplus q_{15}).

3. Nếu Alice gửi plaintext :math:`(1, 0, 0, 0)` thì sẽ nhận lại ciphertext

.. math:: \bm{C}_8 = (k_1 \oplus m_8, k_2 \oplus n_8, k_3 \oplus p_8, k_4 \oplus q_8).

Nói cách khác là

.. math:: 

    \bm{C}_0 \oplus \bm{C}_{15} \oplus \bm{C}_8 & = (k_1 \oplus (m_0 \oplus m_{15} \oplus m_8), k_2 \oplus (n_0 \oplus n_{15} \oplus n_8), k_3 \oplus (p_0 \oplus p_{15} \oplus p_8), k_4 \oplus (q_0 \oplus q_{15} \oplus q_8)) \\
    & = (k_1, k_2, k_3, k_4) \oplus \bm{c}.

Ta đã biết vector :math:`\bm{c}`, và có thể tính :math:`\bm{C}_0 \oplus \bm{C}_{15} \oplus \bm{C}_8` nên hoàn toàn có thể tìm lại được khóa :math:`\bm{k}` mà không cần hàm :math:`f`.

A simple hash function
======================

Đây là bài 11 ở round 2.

Đề bài
------

Carol tạo một thuật toán hash mới. Khóa :math:`k = (k_1, \ldots, k_6)` là vector nhị phân độ dài :math:`6`.

Đầu vào hàm hash là một dãy các chữ số. Dãy này được chia thành các khối độ dài :math:`6`. Nếu độ dài của dãy không chia hết cho sau thì ta thêm lần lượt các chữ số :math:`1`, :math:`2`, :math:`3`, ... vào sau dãy cho đến khi độ dài của dãy chia hết cho :math:`6`.

Mỗi khối, giả sử là :math:`(p_1, \ldots, p_6)`, được biến đổi thành số nguyên theo quy tắc

.. math:: (-1)^{k_1} \cdot p_1 + \ldots + \ldots + (-1)^{k_6} \cdot p_6.

Ở đây :math:`(-1)^0 = 1` và :math:`(-1)^1 = -1`.

Kết quả sau khi tính toán các khối :math:`n_1`, :math:`n_2`, ... sau đó được tổng hợp thành giá trị hash là

.. math:: H = n_1 - n_2 + n_3 - n_4 + \cdots

Carol áp dụng thuật toán hash này vào hệ thống log của trang web ngân hàng. Mỗi khi người dùng nhập mật khẩu :math:`P` thì hệ thống sẽ tính toán hash :math:`H(P, K)` và so sánh với giá trị hash lưu trên cơ sở dữ liệu để xem người dùng có nhập đúng mật khẩu không.

Nhưng mà Carol nhận ra hệ thống này không an toàn. Việc tìm va chạm (collision) là có thể và từ đó kẻ tấn công có thể truy cập hệ thống. Họ làm như thế nào?

Hãy đề xuất thuật toán đơn giản nhất để tìm va chạm cho mọi dãy đầu vào :math:`P` biết trước nếu khóa :math:`K` không biết.

Hơn nữa hãy tìm va chạm ngắn nhất cho dãy trong ví dụ (dãy :math:`P = 134875512293`). Lưu ý rằng do không biết :math:`K` nên chúng ta cũng không biết giá trị hash :math:`H(P, K)`.

Lời giải
--------

Bài này mình có chút nhầm lẫn nên không được full điểm.

Giả sử input có :math:`t` khối là :math:`n_1`, :math:`n_2`, ..., :math:`n_t`. Mỗi khối có :math:`6` chữ số.

Mình sẽ chứng minh rằng khi :math:`t` chẵn thì ta luôn tìm được collision mà không cần khóa :math:`K`.

Đầu tiên, với :math:`t = 2`, giả sử hai khối là

.. math:: n_1 = (p_{1, 1}, \ldots, p_{1, 6}), \quad n_2 = (p_{2, 1}, \ldots, p_{2, 6}).

Giả sử khóa là :math:`K = (k_1, \ldots, k_6)`. Khi đó hash là

.. math:: 

    H & = (-1)^{k_1} \cdot p_{1, 1} + \ldots + (-1)^{k_6} \cdot p_{1, 6} \\
    & - \left[ (-1)^{k_1} \cdot p_{2, 1} + \ldots + (-1)^{k_6} \cdot p_{2, 6} \right]

và nếu mình tăng hoặc giảm :math:`p_{1, i}` và :math:`p_{2, i}`, với :math:`1 \leqslant i \leqslant 6`, cùng một lượng, ví dụ như

.. math:: p_{1, 1}' = p_{1, 1} + a, \quad p_{2, 1}' = p_{2, 1} + a,

và thay :math:`p_{1, 1}'` và :math:`p_{2, 1}'` vào hash thì được

.. math:: 

    H' & = (-1)^{k_1} \cdot p_{1, 1}' + \ldots + (-1)^{k_6} \cdot p_{1, 6} - \left[ (-1)^{k_1} \cdot p_{2, 1}' + \ldots + (-1)^{k_6} \cdot p_{2, 6} \right] \\
    & = (-1)^{k_1} \cdot (p_{1, 1} + a) + \ldots + (-1)^{k_6} \cdot p_{1, 6} - \left[ (-1)^{k-1} \cdot (p_{2, 1} + a) + \ldots +  (-1)^{k_6} \cdot p_{2, 6} \right] \\
    & = H + (-1)^{k_1} \cdot a - \left[ (-1)^{k_1} \cdot a \right] = H.

Điều đó nghĩa là nếu tăng hoặc giảm :math:`p_{1, i}` và :math:`p_{2, i}` cùng lượng, tức là

.. math:: p_{1, i}' = p_{1, i} + a_i, \ p_{2, i}' = p_{2, i} + a_i, \ \text{where} \ a_i \in \{ -1, 0, 1\},

và phải thỏa điều kiện :math:`1 \leqslant p_{1, i}' \leqslant 9` và :math:`1 \leqslant p_{2, i}' \leqslant 9` thì mình sẽ tìm được input mới có cùng hash.

Khi :math:`t = 4, 6, \ldots` thì sử dụng phương pháp tương tự cho các cặp khối :math:`n_{2m+1}` và :math:`n_{2m+2}` (mỗi cặp sử dụng các giá trị :math:`a_i` tùy ý miễn thỏa các điều kiện trên) thì ta luôn tìm được collision bất kể khóa :math:`K` là gì.

Cryptographic Fish
==================

Đây là bài 1 ở round 1.

.. figure:: problem-1-round-1.png

Đây là tam giác Pascal.

Mình đã có một hàng là

.. math:: 1 \to 3 \to 3 \to 1.

Hàng kế tiếp là

.. math:: 1 \to 4 \to {\color{red}6} \to 4 \to 1.

Hàng kế nữa là

.. math:: 1 \to {\color{red}5} \to 10 \to 20 \to 10 \to {\color{red}5} \to 1.

Tiếp theo sẽ là

.. math:: 1 \to 6 \to {\color{red}15} \to {\color{red}15} \to 6 \to 1

vì theo thứ tự chúng ta sẽ cần :math:`C^2_6` (đi từ trên xuống) và :math:`C^4_6` (đi từ dưới lên).

Hàng cuối sẽ là

.. math:: 1 \to 7 \to 21 \to {\color{red}35} \to {\color{red}35} \to 21 \to 7 \to 1.

Còn về ô đầu tiên thì cần điền số :math:`\color{red}2` do dòng trước :math:`3` là :math:`2` theo tam giác Pascal.

Như vậy kết quả là

.. math:: 2 + 6 + 5 + 5 + 15 + 15 + 35 + 35 = 118.
