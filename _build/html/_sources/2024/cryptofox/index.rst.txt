CryptoFox 2024
**************

Olympiad mật mã và bảo mật thông tin CryptoFox 2024

Задача 1. дешифрование файла
============================

Câu hỏi
-------

.. only:: html

    .. code-block:: python 

        import os.path		# стандартная библиотека
        import gostcrypto	# сторонняя библиотека (https://pypi.org/project/gostcrypto/)

        # преобразование числа в двоичный массив
        def bitlist(x, l = 512):
            return [x >> i & 1 for i in range(l-1,-1,-1)]

        # преобразование двоичного массива в число
        def bittoint(x):
            res = 0
            for bit in x:
                res = (res << 1) | bit
            return res

        # определение перестановки
        perm = [ 35,	 39,	326,	478,	507,	299,	233,	 47,
                7,	 56,	293,	383,	322,	354,	185,	385,
                104,	414,	 66,	267,	106,	475,	101,	212,
                270,	 26,	398,	490,	496,	131,	 72,	495,
                186,	168,	509,	 27,	196,	437,	401,	194,
                200,	405,	176,	422,	294,	145,	370,	237,
                12,	246,	152,	 40,	403,	482,	471,	328,
                153,	183,	487,	 34,	484,	260,	 91,	397,
                340,	 15,	446,	  0,	273,	389,	266,	268,
                117,	361,	468,	 11,	 74,	141,	 52,	254,
                486,	 71,	277,	307,	419,	501,	489,	164,
                384,	362,	349,	210,	171,	187,	 76,	418,
                220,	 97,	315,	 19,	209,	312,	257,	402,
                500,	400,	216,	232,	463,	424,	314,	128,
                58,	493,	 17,	258,	 55,	433,	316,	166,
                503,	479,	173,	208,	491,	416,	498,	231,
                159,	415,	359,	342,	310,	235,	123,	244,
                122,	 23,	129,	440,	508,	308,	338,	189,
                68,	452,	214,	240,	155,	480,	462,	180,
                298,	 21,	313,	248,	396,	285,	388,	 37,
                286,	 84,	 81,	134,	 96,	223,	505,	256,
                87,	234,	262,	  9,	343,	390,	410,	455,
                67,	236,	466,	103,	356,	279,	339,	109,
                73,	222,	269,	351,	469,	 98,	  5,	100,
                348,	 62,	317,	241,	499,	 43,	197,	 54,
                448,	 60,	114,	332,	191,	250,	311,	395,
                48,	465,	 24,	172,	  6,	436,	 16,	 65,
                177,	225,	358,	 44,	423,	439,	 95,	318,
                198,	330,	178,	179,	 20,	249,	 90,	261,
                88,	450,	127,	137,	502,	263,	 63,	 32,
                219,	407,	453,	369,	175,	271,	 31,	230,
                346,	 59,	 61,	292,	213,	281,	290,	406,
                425,	297,	381,	142,	108,	203,	295,	411,
                485,	459,	 28,	387,	302,	464,	327,	429,
                125,	205,	243,	379,	454,	 85,	510,	 14,
                215,	255,	300,	  8,	275,	193,	169,	 22,
                494,	276,	372,	224,	207,	336,	363,	148,
                247,	124,	427,	229,	296,	504,	420,	353,
                280,	116,	284,	150,	481,	154,	 93,	 30,
                272,	331,	252,	378,	320,	421,	 83,	443,
                374,	289,	163,	511,	 99,	304,	451,	253,
                474,	303,	 38,	  2,	 53,	 89,	329,	447,
                41,	 57,	199,	 51,	 77,	151,	288,	412,
                147,	161,	 18,	426,	376,	352,	394,	497,
                375,	399,	245,	140,	506,	132,	409,	221,
                10,	366,	165,	477,	357,	120,	373,	156,
                188,	333,	344,	102,	170,	325,	264,	239,
                29,	392,	118,	227,	 64,	 86,	174,	274,
                130,	211,	 75,	287,	 78,	111,	  3,	291,
                79,	135,	 94,	335,	228,	 42,	337,	 45,
                195,	259,	441,	404,	 33,	432,	380,	133,
                467,	144,	309,	  4,	226,	251,	121,	435,
                319,	386,	306,	 92,	321,	182,	167,	126,
                242,	434,	113,	367,	107,	355,	483,	204,
                456,	282,	350,	408,	238,	334,	301,	364,
                138,	428,	105,	431,	460,	 82,	115,	341,
                430,	278,	190,	143,	 46,	473,	110,	445,
                1,	 69,	 25,	201,	438,	393,	184,	323,
                265,	444,	149,	136,	476,	368,	365,	488,
                371,	472,	324,	360,	202,	 50,	 49,	305,
                206,	 36,	158,	492,	181,	391,	 13,	217,
                218,	157,	 80,	119,	377,	382,	160,	442,
                449,	146,	345,	139,	283,	112,	192,	461,
                458,	457,	470,	413,	417,	162,	 70,	347]

        # инициализационный вектор шифрования
        iv = bytearray([0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01])

        # перестановка битов числа
        def intpermute(x):
            t = bitlist(x)
            res = [0] * len(t)
            for i in range(len(t)):
                res[perm[i]] = t[i]
            return bittoint(res)

        # преобразование пароля в ключ
        def pwdtokey(x):
            str = x.encode('cp1251')
            hash = gostcrypto.gosthash.new('streebog512', data=str)
            res = int.from_bytes(hash.digest(),"big")
            for i in range(500):
                res = intpermute(res) >> 1
            res = res % 115792089237316195423570985008687907853269984665640564039457584007913129639936
            return bytearray(res.to_bytes(32, "big"))

        # зашифрование файла
        def encrypt(plain_file_path , cipher_file_path, key):
            cipher_obj = gostcrypto.gostcipher.new('kuznechik',
                                            key,
                                            gostcrypto.gostcipher.MODE_CTR,
                                            init_vect=iv)
            buffer_size = 128
            plain_file = open(plain_file_path, 'rb')
            cipher_file = open(cipher_file_path, 'wb')
            buffer = plain_file.read(buffer_size)
            while len(buffer) > 0:
                cipher_data = cipher_obj.encrypt(buffer)
                cipher_file.write(cipher_data)
                buffer = plain_file.read(buffer_size)
            return

        # расшифрование файла
        def decrypt(cipher_file_path, plain_file_path, key):
            cipher_obj = gostcrypto.gostcipher.new('kuznechik',
                                            key,
                                            gostcrypto.gostcipher.MODE_CTR,
                                            init_vect=iv)
            buffer_size = 128
            cipher_file = open(cipher_file_path, 'rb')
            plain_file = open(plain_file_path, 'wb')
            buffer = cipher_file.read(buffer_size)
            while len(buffer) > 0:
                plain_data = cipher_obj.decrypt(buffer)
                plain_file.write(plain_data)
                buffer = cipher_file.read(buffer_size)
            return



        if __name__ == '__main__':
            password = "некий пароль"   # здесь был пароль
            k = pwdtokey(password)      # преобразовываем пароль в ключ

            plain_file_path = 'plain_file.txt'  # файл исходного ОТ
            cipher_file_path = 'cipher_file.txt'    # файл для записи ШТ
            decipher_file_path = 'decipher_file.txt'    # файл полученного ОТ
            if os.path.isfile(plain_file_path):
                encrypt(plain_file_path, cipher_file_path, k)  # зашифрование ОТ

            if os.path.isfile(cipher_file_path):
                decrypt(cipher_file_path, decipher_file_path, k)    # расшифрование ШТ


Lời giải
--------

Bài này cho file encrypt bằng thuật toán Kuznyechik 256 bit. Với password bị ẩn đi, khóa cho Kuznyechik được sinh bằng việc hash password bằng Streebog, sau đó các bit sau khi hash đi qua một hoán vị.

Do Streebog là hash 512 bit nên sau khi qua bảng hoán vị vẫn có 512 bit. Do đó khóa là 256 bit thấp sau khi hash.

Cả Streebog và Kuznyechik là các tiêu chuẩn mật mã nên không thể phá. Lỗi nằm ở bảng hoán vị.

Sau khi thử tạo key từ một số password (tiếng Nga), ta thấy rằng trong 256 bit của khóa chỉ có một số ít bit 1. Đặc biệt là các vị trí xuất hiện 1 là không nhiều. Do đó chúng ta có thể giảm không gian 256 bit xuống một tập nhỏ hơn.

Giả sử ta tạo các key Kuznyechik :math:`K_1, K_2, \ldots` từ việc hash các password :math:`w_1, w_2, \ldots`, nghĩa là :math:`K_i = H(w_i)`, đặt :math:`I_i` là tập hợp các vị trí bit 1 xuất hiện.

Đặt :math:`I = I_1 \cup I_2 \cup \ldots` là tập các vị trí có thể là bit 1 khi hash một password bất kì. Tập này chứa không quá 10 phần tử.

.. only:: html

    .. code-block:: python 

        import random
        from itertools import combinations
        import string

        # Здесь найти позиции, где возможно появится единицы
        alphabet = 'АБВГДЕЁЖЗИЙКЛМНОРПСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийabcdefghijklmn0123456789'
        ss = set()
        for _ in range(100):
            pwd = "".join([random.choice(alphabet) for __ in range(256)])
            key = pwdtokey(pwd)
            bits = []
            for b in key:
            bits.extend(list(map(int, "{:08b}".format(b))))
            assert len(bits) == 256
            for i in range(256):
            if bits[i] == 1: ss.add(i)

        print(ss)

Khi đó khóa Kuznyechik để mã hóa sẽ là khóa có bit 1 nằm ở các vị trí theo tập :math:`J \subset I`. Thử tất cả tập con của :math:`I` đến khi decrypt và decode thành công.

Khóa decrypt viết ở dạng hex là 

.. code-block:: 

    0000e00000000080000000000000000000000004000000000000004000000004

.. only:: html

    .. code-block:: python 

        import random
        from itertools import combinations
        import string

        file = open("cipher_file.txt", "rb")
        ciphertext = file.read(16)
        file.close()

        ss = set([128, 104, 16, 17, 18, 243, 180, 157, 56, 217, 253, 159])

        for t in range(len(ss)):
            for comb in combinations(list(ss), t):
                kk = [0] * 256
                for i in comb: kk[i] = 1
                blocks = ["".join(map(str, kk[i:i+8])) for i in range(0, 256, 8)]
                key = bytearray(int(block, 2) for block in blocks)
                cipher_obj = gostcrypto.gostcipher.new(
                    'kuznechik', 
                    key, 
                    gostcrypto.gostcipher.MODE_CTR, 
                    init_vect=iv)
                plaintext = cipher_obj.decrypt(ciphertext)
                try:
                    print(plaintext.decode('utf-8'), key)
                except:
                    pass

.. admonition:: Kết quả (thơ tiếng Nga)
    :class: dropdown

    Мой дядя самых честных правил,

    Когда не в шутку занемог,

    Он уважать себя заставил

    И лучше выдумать не мог.

    Его пример другим наука;

    Но, боже мой, какая скука

    С больным сидеть и день и ночь,

    Не отходя ни шагу прочь!

    Какое низкое коварство

    Полуживого забавлять,

    Ему подушки поправлять,

    Печально подносить лекарство,

    Вздыхать и думать про себя:

    Когда же черт возьмет тебя!


Задача 2. Анализ GOST-CryptoFox
===============================

Phân tích GOST-CryptoFox
------------------------

Đặt :math:`V_{n}(2^m)` là không gian vector :math:`n` chiều trên trường :math:`\mathbb{F}_{2^m}`, :math:`\boxplus` là phép cộng trên vành :math:`\mathbb{Z}_{2^{32}}` (phép cộng modulo :math:`2^{32}`), :math:`\oplus` là phép cộng trên :math:`V_{n}(2)` (phép XOR).

Đặt :math:`\psi : V_{32}(2) \to \mathbb{Z}_{2^{32}}` là hàm biến đổi vector 32 bit thành số nguyên 32 bit. Công thức của hàm :math:`\psi` là

.. math:: \psi(\beta) = \bar{\beta} = \sum_{i=1}^{32} \beta_i 2^{32-i}

với :math:`\beta = (\beta_1, \beta_2, \ldots, \beta_{32}) \in V_{32}(2)` và :math:`\bar{\beta} \in \mathbb{Z}_{2^{32}}`.

Trường :math:`\mathbb{F}_{2^8}` dùng đa thức tối giản :math:`1 + x^2 + x^3 + x^4 + x^8` với nghiệm :math:`\theta`. Phần tử trên :math:`\mathbb{F}_{2^8}` được viết dưới dạng vector :math:`V_8(2)`.

GOST-CryptoFox dùng 32 vòng, độ dài khối là 64 bit và độ dài khóa là 256 bit.

Ngoài ra, trong thuật toán sử dụng:

- các hoán vị :math:`\pi_1`, :math:`\pi_2`, :math:`\pi_3`, :math:`\pi_4` 
  trên tập :math:`\{ 1, 2, \ldots, 8 \}` để chỉ định khóa con cho từng vòng;
- các hoán vị :math:`8` bit :math:`s_1`, :math:`s_2`, :math:`s_3`, 
  :math:`s_4` là các S-box của thuật toán.

Thuật toán sinh khóa con
------------------------

Khóa đầu vào :math:`K` có 256 bit.

- Khóa :math:`K` đầu tiên được chia thành 8 đoạn 32 bit, :math:`K = K_1 \Vert K_2 \Vert \ldots \Vert K_8`. Như vậy :math:`K \in V_{256}(2)`, :math:`K_i \in V_{32}(2)` với :math:`1 \leqslant i \leqslant 8`
- Ở các vòng 1-8, sử dụng hoán vị :math:`\pi_1` để chỉ định khóa con, cụ thể là ở vòng thứ :math:`i` sẽ dùng khóa :math:`k_i = K_{\pi_1(i)}`, :math:`1 \leqslant i \leqslant 8`
- Ở các vòng 9-16, sử dụng hoán vị :math:`\pi_2` để chỉ định khóa con, cụ thể là ở vòng thứ :math:`i+8` sẽ dùng khóa con :math:`k_{i+8} = K_{\pi_2(i)}`, :math:`1 \leqslant i \leqslant 8`
- Ở các vòng 17-24, sử dụng hoán vị :math:`\pi_3` để chỉ định khóa con, cụ thể là ở vòng thứ :math:`i+16` sẽ dùng khóa con :math:`k_{i+16} = K_{\pi_3(i)}`, :math:`1 \leqslant i \leqslant 8`
- Ở các vòng 25-32, sử dụng hoán vị :math:`\pi_4` để chỉ định khóa con, cụ thể là ở vòng thứ :math:`i+24` sẽ dùng khóa con :math:`k_{i+24} =K_{\pi_4(i)}`, :math:`1 \leqslant i \leqslant 8`

Khi đó các khóa con cho 32 vòng là :math:`k_1`, :math:`k_2`, ..., :math:`k_{32}`.

Thuật toán mã hóa
-----------------

GOST-CryptoFox 2024 dựa trên mô hình Feistel. Round function :math:`f_k : V_{64}(2) \to V_{64}(2)` với khóa :math:`k \in V_{32}(2)`:

.. math:: f_k : (\alpha_1, \alpha_2) \to (\alpha_2, \alpha_1 \oplus g_k (\alpha_2, k)), \quad \alpha_1, \alpha_2 \in V_{32}(2)

với :math:`g_k : V_{32}(2) \to V_{32}(2)` xác định bởi

.. math:: g_k : \alpha \to h(S(\psi^{-1}(\psi(\alpha) \boxplus \psi(k)))),

trong đó:

- :math:`h` là ánh xạ tuyến tính trên :math:`V_{32}(2)` xác định bởi ma trận :math:`4 \times 4` là :math:`\bm{H}` trên :math:`\mathbb{F}_{2^8}`,

.. math:: 
    
    h(\lambda^{(1)}, \ldots, \lambda^{(4)}) = (\lambda^{(1)}, \ldots, \lambda^{(4)}) \bm{H}, \quad \lambda^{(1)}, \ldots, \lambda^{(4)} \in \mathbb{F}_{2^8},

    \bm{H} = \begin{pmatrix}
        \theta & \theta \oplus 1 & 1 & 1 \\
        1 & \theta & \theta \oplus 1 & 1 \\
        1 & 1 & \theta & \theta \oplus 1 \\
        \theta \oplus 1 & 1 & 1 & \theta \\
    \end{pmatrix},

- S-box :math:`S = (s_1, s_2, s_3, s_4)` gồm 4 S-box con theo quy tắc

.. math:: S(\beta) = (s_1 (\beta^{(1)}), \ldots, s_4 (\beta^{(4)})), \quad \beta = (\beta^{(1)}, \ldots, \beta^{(4)}) \in V_4(2^8),

nghĩa là khi đó:

- hai vector 32 bit :math:`\alpha` và :math:`k` sẽ được chuyển thành số nguyên 32 bit và cộng modulo :math:`2^{32}`, kết quả sau đó được chuyển lại thành vector 32 bit
        
.. math:: \lambda = \psi^{-1}(\psi(\alpha) \boxplus \psi(k));

- vector 32 bit :math:`\lambda` được chia thành 4 đoạn :math:`\lambda^{(1)}, \ldots, \lambda^{(4)}` là các phần tử :math:`\mathbb{F}_{2^8}` và biểu diễn :math:`\lambda = (\lambda^{(1)}, \ldots, \lambda^{(4)})` là không gian 4 chiều :math:`V_4(2^8)`. Sau đó tính :math:`\beta = \lambda \bm{H}`;
- vector 32 bit :math:`\beta` được chia thành 4 vector 8 bit là :math:`\beta^{(1)}, \ldots, \beta^{(4)}`. Sau đó mỗi vector :math:`\beta^{(i)}` đi qua S-box con :math:`s_i`, :math:`i = 1, 2, 3, 4`. Bốn kết quả được ghép lại nhau thành :math:`S(\beta)`.

Mã hóa là hàm :math:`b_K : V_{64}(2) \to V_{64}(2)` định nghĩa bởi phương trình:

.. math:: b_K(\alpha) = g_{k_32} g_{k_31} \ldots g_{k_2} g_{k_1} (\alpha), \quad \alpha \in V_{64}(2)

Câu hỏi
-------

1. Trong hệ mật mã GOST-CryptoFox trên đầy đủ 32 vòng tìm các vi sai liên quan đến các khóa với xác suất là 1 và chỉ sử dụng các khóa liên quan và cặp plaintext thích hợp. Điều đó nghĩa là, với mỗi khóa chưa biết :math:`K \in V_{256}` tìm phần tử :math:`\varepsilon \in V_{256} \backslash \{ \vec{0}_{256} \}` và :math:`\delta_1, \delta_2 \in V_{64}` sao cho với cách chọn ngẫu nhiên plaintext :math:`\alpha \in V_{64}(2)` đẳng thức vi sai với xác suất là 1 là phương trình:

.. math:: 
    :label: eq-fox24-2
    
    b_K(\alpha) \oplus b_{K \oplus \varepsilon} (\alpha \oplus \delta_1) = \delta_2

2. (Câu hỏi research). Thay phép :math:`\boxplus` bằng phép :math:`\oplus` trong mô hình GOST-CryptoFox 2024 ở trên và kí hiệu là mô hình GOST-CryptoFox-:math:`\oplus`. Thực hiện tấn công trên mô hình GOST-CryptoFox-:math:`\oplus` 2024 với nhiều vòng nhất có thể và đánh giá độ phức tạp. Có khả năng tấn công GOST-CryptoFox-:math:`\oplus` đầy đủ 32 vòng hay không?

.. admonition:: Lời giải bị sai của mình
    :class: dropdown

    Для каждого неизвестного ключа шифрования :math:`K \in V_{256}` нужно найти такие :math:`\varepsilon \in V_{256} \setminus \{ \bar{0}_{256} \}, \delta_1, \delta_2 \in V_{64}` что при случайном и равновероятном выборе открытого текста :math:`\alpha \in V_{64}(2)` равенство с вероятностью 1 справедливо равенство

    .. math:: b_K(\alpha) \oplus b_{K \oplus \varepsilon}(\alpha \oplus \delta_1) = \delta_2

    Допустим ключ шифрования :math:`K` разделяется на 8 частей :math:`K_1, K_2, \ldots, K_8`, где :math:`K_1, \ldots, K_8 \in V_{32}(2)`. Значит :math:`K = K_1 \Vert K_2 \Vert \ldots \Vert K_8`.

    Процесс шифрования задается равенством

    .. math:: b_K(\alpha) = g_{k_{32}} \ldots g_{k_2} g_{k_1} (\alpha)

    где :math:`\alpha \in V_{64}(2)` -- двоичный вектор длины 64.

    Допустим :math:`\alpha = \alpha_1 \Vert \alpha_2`, где :math:`\alpha_1, \alpha_2 \in V_{32}`. В первом раунде, мы рассмотрим часть :math:`\alpha_2`.

    У нас есть

    .. math:: g_{k_1}(\alpha_2) = h(S(\psi^{-1}(\psi(\alpha_2) \boxplus \psi(k_1))))

    Аналогично, обозначим 

    - :math:`\varepsilon = \varepsilon_1 \Vert \varepsilon_2 \Vert \ldots \Vert \varepsilon_{8}`, где :math:`\varepsilon \in V_{256}(2)` и :math:`\varepsilon_1, \varepsilon_2, \ldots, \varepsilon_{8} \in V_{32}(2)`
    - :math:`\delta_1 = \delta_{11} \Vert \delta_{12}`, где :math:`\delta_1 \in V_{64}(2)`, :math:`\delta_{11}, \delta_{12} \in V_{32}`    

    Тогда

    .. math:: g_{k_1 \oplus \varepsilon_2}(\alpha_2 \oplus \delta_{12}) = h(S(\psi^{-1}(\psi(\alpha_2 \oplus \delta_{12}) \boxplus \psi(k_1 \oplus \varepsilon_2))))

    Заметим, что если :math:`\varepsilon_2 \equiv \delta_{12}`, тогда :math:`\psi(\alpha_2) \boxplus \psi(k_1) \equiv \psi(\alpha_2 \oplus \delta_{12}) \boxplus \psi(k_1 \oplus \varepsilon_2)`. Например, если у меня есть (на кольце :math:`2^4 = 16`) :math:`a = 13` и :math:`k = 6`. Тогда :math:`a \boxplus b = 3 \pmod{2^{4}}`. Выбираем :math:`b = 10` и :math:`l = 10`, тогда :math:`a \oplus b = 13 \oplus 10 = 1101 \oplus 1010 = 0111 = 7`, и :math:`k \oplus l = 6 \oplus 10 = 0110 \oplus 1010 = 1100 = 12`. Получаем :math:`7 \boxplus 12 = 3 \pmod{2^{4}}`.

    Через перый раунд,

    .. math:: f_{k_1} : (a_1, a_2) \to (a_1' = a_2, a_2' = a_1 \oplus g_{k_1} (a_2))

    еще одно свойство

    .. math:: f_{k_1 \oplus \varepsilon_2} : (a_1 \oplus \delta_{11}, a_2 \oplus \delta_{12}) \to (A_1' = a_2 \oplus \delta_{12}, A_2' = a_1 \oplus \delta_{11} \oplus g_{k_1 \oplus \varepsilon_2}(a_2 \oplus \delta_{12}))

    Как показан выше, :math:`a_2' \oplus A_2' = \delta_{11}` и :math:`a_1' \oplus A_1' = \delta_{12}`.

    Через второй раунд,

    .. math:: f_{k_2} : (a_1', a_2') \to (a_1'' = a_2', a_2'' = a_1' \oplus g_{k_2} (a_2'))

    Это следует :math:`a_1'' = a_2' = a_1 \oplus g_{k_1}(a_2)` и :math:`a_2'' = a_2 \oplus g_{k_2} (a_1 \oplus g_{k_1} (a_2))`.

    Аналогично

    .. math:: f_{k_2 \oplus \varepsilon_1} : (A_1', A_2') \to (A_1'' = A_2', A_2'' = A_1' \oplus g_{k_2 \oplus \varepsilon_1} (A_2'))

    Это следует :math:`A_1'' = A_2' = a_1 \oplus \delta_{11} \oplus g_{k_1 \oplus \varepsilon_2} (a_2 \oplus \delta_{12})` и :math:`A_2'' = A_1' \oplus g_{k_2 \oplus \varepsilon_1}(A_2') = a_2 \oplus \delta_{12} \oplus g_{k_2 \oplus \varepsilon_1} (a_1 \oplus \delta_{11} \oplus g_{k_1 \oplus \varepsilon_2} (a_2 \oplus \delta_{12})`.

    Поэтому

    .. math:: a_1'' \oplus A_1'' = \delta_{11}

    так как :math:`g_{k_1 \oplus \varepsilon_2} (a_2 \oplus \delta_{12}) \equiv g_{k_1} (a_2)` как доказано выше. 

    И пусть :math:`G = a_1 \oplus g_{k_1 \oplus \varepsilon_2} (a_2 \oplus \delta_{12}) = a_1 \oplus g_{k_1} (a_2)`, тогда у нас есть

    .. math:: a_2'' \oplus A_2'' = \delta_{12} \oplus g_{k_2} (G) \oplus g_{k_2 \oplus \varepsilon_1} (\delta_{11} \oplus G)

    Аналогично, если выберем :math:`\varepsilon_1 \equiv \delta_{11}`, мы получми :math:`g_{k_2} (G) \equiv g_{k_2 \oplus \varepsilon_1} (\delta_{11} \oplus G)` и отсюда :math:`a_2'' \oplus A_2'' = \delta_{12}`.

    Можем отметить, что после два раунда, для любого открытого тектса :math:`a \in V_{64}` и для любого подключей шифрования :math:`k_1, k_2 \in V_{32}`, дифференциальный будет фиксирован

    .. math:: a_1'' \Vert a_2'' \oplus A_1'' \Vert a_2'' = \delta_{11} \Vert \delta_{12}

    Продолжаем этот процесс и получим, что

    .. math:: 

        \varepsilon_3 & = \delta_{12}, \\
        \varepsilon_4 & = \delta_{11}, \\
        \varepsilon_5 & = \delta_{12}, \\
        \varepsilon_6 & = \delta_{11}, \\
        \varepsilon_7 & = \delta_{12}, \\
        \varepsilon_8 & = \delta_{11}

    и дифференциал между :math:`a^{(i)}` и :math:`A^{(i)}` после :math:`i`-ого раунда, где :math:`1 \leqslant i \leqslant 32`, равен

    .. math:: 

        a^{(i)} \oplus A^{(i)} = \begin{cases}
            \delta_{12} \Vert \delta_{11}, \text{если } i \text{ нечетный}, \\
            \delta_{11} \Vert \delta_{12}, \text{если } i \text{ четный}
        \end{cases}

    Ответ: такие векторы, удовлетворящие равенство

    .. math:: b_K(a) \oplus b_{K \oplus \varepsilon} (a \oplus \delta_1) = \delta_2

    с вероятностью 1 построены со следующем образом:

    1. Быбрать любой ненулевой вектор :math:`\delta_1 = \delta_{11} \Vert \delta_{12}`, где :math:`\delta_1 \in V_{64}(2)` и :math:`\delta_{11}, \delta_{12} \in V_{32}(2)`
    2. Построить вектор :math:`\varepsilon = \delta_{12} \Vert \delta_{11} \Vert \delta_{12} \Vert \delta_{11} \Vert \delta_{12} \Vert \delta_{11} \Vert \delta_{12} \Vert \delta_{11}`, где :math:`\varepsilon \in V_{256}`
    3. Тогда получим :math:`\delta_2 \equiv \delta_1 = \delta_{11} \Vert \delta_{12} \in V_{64}`

Задача 3. Инвариантные структуры
================================

Câu hỏi
-------

Alice và Bob sử dụng thuật toán PRINTcipher-48 để mã hóa dữ liệu. Eva rất muốn biết Alice và Bob đã trao đổi thông tin gì bằng thuật toán này. Eva biết được perm key là 7e92c53f và 10 cặp plaintext-ciphertext theo bảng sau:

+----+------------------+------------------+
|  № | Открытый текст   | Шифртекст        |
+====+==================+==================+
|  1 | ``5ef30b0e8810`` | ``63b05da1572d`` |
+----+------------------+------------------+
|  2 | ``08419219c0a9`` | ``19919629a291`` |
+----+------------------+------------------+
|  3 | ``2ba2a41913b3`` | ``39f39539b0af`` |
+----+------------------+------------------+
|  4 | ``27da9fea907c`` | ``1feeef47a39b`` |
+----+------------------+------------------+
|  5 | ``2b52a13970b2`` | ``1b32b8080293`` |
+----+------------------+------------------+
|  6 | ``c0cb1af1b482`` | ``9c9e8cb63ff9`` |
+----+------------------+------------------+
|  7 | ``6cd9e41199a3`` | ``A6238ffd3462`` |
+----+------------------+------------------+
|  8 | ``0b40872901a5`` | ``2bf09e0a70ab`` |
+----+------------------+------------------+
|  9 | ``1a8d558c018c`` | ``2d16ebafea7a`` |
+----+------------------+------------------+
| 10 | ``38c3840ae3a9`` | ``2953ab0bf3b1`` |
+----+------------------+------------------+

Hãy giúp Eva khôi phục 80 bit của khóa bí mật. Tài liệu mô tả thuật toán cũng như cách tấn công dựa trên invariant structure (cấu trúc bất biến) :cite:`10.1007/978-3-642-22792-9_12`.

Задача 4. Корректирующий код и шифр Вернама
===========================================

Câu hỏi
-------

Alice gửi cho Bob thông điệp được mã hóa bằng mã Vernam.

Ở đây, để mã hóa thông điệp, Alice chọn một mã sửa lỗi nhị phân độ dài 256 với khả năng sửa một bit. Bob giải mã và decode thông điệp. One-time-key được sinh trước đó và được truyền bí mật giữa Alice và Bob, nghĩa là Alice gửi qua kênh truyền ciphertext :math:`y` bằng:

.. math:: y = \text{code}(x) \oplus key,

trong đó:

- :math:`x \in \{0, 1\}^m` - thông điệp
- :math:`y \in \{0, 1\}^{256}` - ciphertext
- :math:`key \in \{0, 1\}^{256}` - khóa bí mật one-time
- :math:`m` - độ dài thông điệp và là kích thước của code
- :math:`\text{code}: \{0, 1\}^m \to \{0, 1\}^{256}` - hàm encode của mã sửa lỗi
- :math:`\oplus` - phép XOR.

Bob nhận được ciphertext :math:`y` và giải mã bằng cách

.. math:: x = \text{decode}(y \oplus key),

với :math:`\text{decode} : \{ 0, 1 \}^{256} \to \{ 0, 1 \}^m` là hàm decode của mã sửa lỗi.

Anton và Bella muốn sử dụng kênh truyền của Alice và Bob để trao đổi thông tin. Anton có thể lặng lẽ đọc và thay đổi ciphertext :math:`y` trước khi Alice chuyển qua kênh truyền. Bella thì có thể đọc ciphertext từ kênh truyền. Cả Anton và Bella đều không biết khóa bí mật one-time, mà chỉ biết về mã sửa lỗi (độ dài :math:`m` và thuật toán). Biết rằng xác suất xảy ra lỗi trên kênh truyền là :math:`0`.

Anton có thể gửi thông điệp cho Bella, sử dụng kênh truyền của Alice và Bob, mà không ảnh hưởng hay tiết lộ sự tồn tại của bản thân không? Nếu có, lượng thông tin lớn nhất mà Anton có thể gửi đi trong một thông-điệp-Alice là bao nhiêu?

Задача 5. Эффективная реализация
================================

Câu hỏi
-------

Alice nhận được một thiết bị phần cứng, cho phép thực hiện các phép tính trên đường cong elliptic, bao gồm: cộng, trừ, nhân đôi, nhân ba và nhân 7 (nhân vô hướng một điểm với 7).

Để kiểm tra độ chính xác của thiết bị, Alice kiểm tra phép nhân vô hướng một điểm cho :math:`2024`.

Cô ấy tìm được một dãy gồm 9 hành động, bao gồm 1 phép cộng, 5 phép nhân đôi, 2 phép nhân ba và 1 phép nhân 7.

Có thể tính phép nhân :math:`2024 G` với ít hành động hơn không? Nếu có, hãy chỉ ra cách tính. Nếu không thể, hãy chứng minh.

.. admonition:: Lời giải bị sai của mình
    :class: dropdown

    Пусть :math:`G` - начальная точка. Нам нужно вычислять точку :math:`2024 G`.

    Так как :math:`2024 = 2^3 \cdot 11 \cdot 23`, значит это число не имеет вид :math:`2^i \cdot 3^j \cdot 7^k`, мы получим, что :math:`2024` должно разделиться на два слагаемых:

    .. math:: 2024 = 2^a \cdot 3^b \cdot 7^c + 2^m \cdot 3^n \cdot 7^p

    После пытаться получим, что :math:`2024 = 2^3 + 2^5 \cdot 3^2 \cdot 7`. Это значит, нужно одно действие сложения, 5 действий удвоения (:math:`5 = \max \{ 3, 5 \}`), 2 действия утроения и 1 усемерения. Общее число действия равно 9.

    Теперь докажу, что не можно вычислять :math:`2024 \cdot G` с меньше количеством действий, чем 9.

    Мы уже разделили 2024 на сумму двух слагаемых. Сейчас попробуем разделить на сумму трех слагаемых, т.е.

    .. math:: 2024 = 2^a \cdot 3^b \cdot 7^c + 2^m \cdot 3^n \cdot 7^p + 2^u \cdot 3^v \cdot 7^w

    Так как здесь уже есть 2 действия сложения, мы хотим уменьшить степени :math:`2^5`, или :math:`3^2`, или 7. Заметим, что

    - Удвоение эквивалент сложение, :math:`2 = 1 + 1`, или :math:`2G = G + G`. Это значит, что в каждом случае требуется одно действие (либо удвоение, либо сложение)
    - Утроение - :math:`3 = 2 + 1`. Здесь, для утроения требуется одно дейстие, а :math:`2+1` требуются два действия (удвоение и сложение). Поэтому разделение 3 на 2+1 не является актуальным
    - Усемерение - :math:`7 = 2 \cdot 3 + 1 = 2^2 + 3`. Здесь, для усемерения требуется одно действие, для :math:`2 \cdot 3 + 1` требуются 3 действия (одно удвоение, одно утроение, одно сложение), и для :math:`2^2 + 3` требуются 4 действия (два удвоения, одно утроения, одно сложение)
    - :math:`3^2 = 7 + 2` - :math:`3^2` требуются два действия утроения, а :math:`7+2` нужно 3 действия (удвоение, усемерение и слжение)
    - :math:`7^2 = 2^4 \cdot 3 + 1 = \ldots = 2^i \cdot 3^j \cdot 7^k + 2^r \cdot 3^s \cdot 7^t` (все способов разделения :math:`7^2` на сумму 2 слагаемых с факторами 2, 3 и 7) - для каждого способа требуются более 2 действия

    Это значит, когда разделить 2024 на сумму трёх слагаемых, количество действия либо сохраняется, либо увеличится.

    Ответ: НЕВОЗМОЖНО.

Задача 7. Диффенциальная равномерность
======================================

Câu hỏi
-------

Ánh xạ

.. math:: f : \mathrm{GF}(2^n) \to \mathrm{GF}(2^n)

được gọi là differential :math:`\delta`-uniformity, nếu với mọi :math:`a \in \mathrm{GF}(2^n)^*` và với mọi :math:`b \in \mathrm{GF}(2^n)` phương trình

.. math:: f(x + a) + f(x) = b

có không quá :math:`\delta` nghiệm trên :math:`\mathrm{GF}(2^n)`.

Ví dụ, hàm nghịch đảo trên :math:`\mathrm{GF}(2^8)` xác định bởi

.. math:: 
    
    I(x) = \begin{cases}
        x^{-1}, \ \text{nếu} \ x \neq 0 \\
        0, \ \text{ngược lại}
    \end{cases}

là hàm differential :math:`4`-uniformity.

Xét toán tử nhóm :math:`\circ` trên :math:`\mathrm{GF}(2^n)` với phần tử đơn vị là :math:`e`, sao cho với mọi :math:`x \in \mathrm{GF}(2^n)` ta có :math:`x \circ x = e`.

Gọi :math:`f` là ánh xạ

.. math:: f : \mathrm{GF}(2^n) \to \mathrm{GF}(2^n)

là ánh xạ differential :math:`\delta`-uniformity theo toán tử nhóm :math:`\circ`, nếu với mọi :math:`a \in \mathrm{GF}(2^n) \backslash \{ e \}` và với mọi :math:`b \in \mathrm{GF}(2^n)`  thì phương trình

.. math:: f(x \circ a) \circ f(x) = b

có không quá :math:`\delta` nghiệm trên :math:`\mathrm{GF}(2^n)`.

Hãy tìm toán tử :math:`\circ` sao cho hàm :math:`I(x)` có diffential formidity thấp nhất.

Задача 8. Разделение секретов
=============================

Câu hỏi
-------

Ông chủ trước khi đi nghỉ mát đã thay đổi code 6 chữ số của két sắt và, trong mọi trường hợp, chia bí mật đó theo sơ đồ ":math:`2` trong :math:`N`" bằng việc vẽ một "đường thẳng" bí mật dưới vành modulo :math:`1` triệu, trong đó code là tọa độ ban đầu của đường thẳng đó.

Hoàn cảnh khiến Andrey và Vladimir phải khẩn trương mở két sắt trong lúc không liên lạc được với ông chủ. Hãy giúp Andrey và Vladimir mở két với thông tin của họ: login của Andrey :math:`x_A = 137059`, chia sẻ bí mật :math:`y_A = 844061`, login của Vladimir là :math:`x_B = 752024`, chia sẻ bí mật :math:`y_B = 639516`.

.. admonition:: Lời giải bị sai của mình
    :class: dropdown

    Даны:

    - Логин Андрея :math:`x_A = 137059`, доля секрета :math:`y_A = 844061`
    - Логин Владимира :math:`x_B = 752024`, доля секрета :math:`y_B = 639516`

    Секреты созданы по схеме "2 из :math:`N`". Это значит существует числа :math:`i_A, i_B`, удовлетворящие равенство

    .. math:: y_A = C^{2}_{i_A} \bmod 10^6, \quad y_B = C^{2}_{i_B} \bmod 10^6

    Здесь :math:`C^a_b` - сочетание :math:`a` элементов из множества :math:`b` элементов.

    Нужно отметить, что пароль является шестизначный код, это следует, что :math:`10^5 \leqslant i_A, i_B < 10^6`. С использованием компьютерной программы можем найти такие числа. Эти числа будут:

    .. math:: i_A = 138967, \quad i_B = 674937

    Секретная прямая проходит через две точки :math:`(x_A, i_A)` и :math:`(x_B, i_B)`. На вещественном множестве :math:`\mathbb{R}`, уравнение прямой, которая проходит через две точки :math:`(x_1, y_1)` и :math:`(x_2, y_2)`, равно

    .. math:: \frac{x - x_1}{x_2 - x_1} = \frac{y - y_1}{y_2 - y_1} \Leftrightarrow (y_2 - y_1) (x - x_1) - (x_2 - x_1) (y - y_1) = 0

    Секретная прямая вычисляется над кольцом вычетов по модулю :math:`10^6`, поэтому уравнение секретной прямой равно

    .. math:: 
        
        & (i_B - i_A) (x - x_A) - (x_B - x_A) (y - i_A) = 0 \bmod{10^6} \\ \Leftrightarrow \, & 535970x + 385035y + 328925 = 0 \bmod{10^6}

    Теперь нам нужно найти начальную ординату прямой, т.е. самый минимальный :math:`y`, :math:`10^5 \leqslant y < 10^6`, который удовлетворяет это уравнение для :math:`x = 0`

    .. math:: 535970 \cdot 0 + 385035 y + 328925 = 0 \bmod{10^6}

    Это уравнение имеет некоторые решения, это 52745, 252745, 452745, 652745 и 852745. Мы берем самый минимальный 252745.

    Секретный код будет :math:`C^2_{252745} \bmod{10^6} = 891140`.

    Ответ: 891140.

Задача 9. Схемная сложность S-блока
===================================

Câu hỏi
-------

Kí hiệu độ phức tạp mạch của hàm boolean vector (S-box) :math:`F` trong cơ sở :math:`B` là :math:`L_B(F)`. Ta nói S-box khả nghịch :math:`F : \{ 0, 1 \}^n \to \{ 0, 1 \}` là bất đối xứng (asymmetric computing), nếu với cơ sở :math:`B` nào đó ta có :math:`L_B(F) \neq L_B(F^{-1})`.

1. Chỉ ra một S-box bất đối xứng như vậy.
2. Xây dựng một họ vô hạn các S-box bất đối xứng.
3. Xây dựng một họ vô hạn các S-box bất đối xứng :math:`\{ F_n \}` với :math:`F_n : \{ 0, 1 \}^n \to \{ 0, 1 \}^n` và :math:`\lim\limits_{n \to \infty} \dfrac{L_B(F_n)}{L_B(F^{-1}_n)} \neq 1`. (*Đây là bài toán chưa có lời giải*).

Задача 10. Анализ алгоритма блочного шифрования «TryHard» (исследовательская)
=============================================================================

Câu hỏi
-------

.. figure:: question-10-2024.png

Hình trên thể hiện một vòng của thuật toán mã khối. Tất cả toán tử chạy trong bộ nhớ :math:`16` bit. Các kí hiệu trên hình được giải nghĩa như sau:

+-----------+---------------------------------+
| Kí hiệu   | Ý nghĩa                         |
+===========+=================================+
| 1.1, 1.2  | Input round key                 |
+-----------+---------------------------------+
| 2.1, 2.2  | Input word                      |
+-----------+---------------------------------+
| 3         | Phép cộng modulo :math:`2^{16}` |
+-----------+---------------------------------+
| 4.1, 4.2  | Toán tử XOR                     |
+-----------+---------------------------------+
| 5         | Dịch trái :math:`5` bit         |
+-----------+---------------------------------+
| 6         | Dịch phải :math:`6` bit         |
+-----------+---------------------------------+
| 7         | Dịch trái :math:`9` bit         |
+-----------+---------------------------------+

Thuật toán sinh khóa con cho các vòng giống với GOST 28147-89 (Magma). Trong đó nửa :math:`16` bit đầu là round key cho 1.1 và :math:`16` bit sau là round key cho 1.2.

Đầu ra của thuật toán được biểu diễn ở bảng sau.

+-------------------------+-----------------+
| Tên gọi                 | Ý nghĩa         |
+=========================+=================+
| Kích thước khối đầu ra  | :math:`32` bit  |
+-------------------------+-----------------+
| Kích thước khóa         | :math:`64` bit  |
+-------------------------+-----------------+
| Số lượng vòng mã hóa    | :math:`20` vòng |
+-------------------------+-----------------+

**Câu hỏi.** Hãy đánh giá số lượng vòng của thuật toán mã hóa, trong đó số lượng vòng cho phép đánh giá sự độc lập thống kê giữa các plaintext và ciphertext, mà qua đó khôi phục được một phần hoặc toàn bộ khóa. Hãy đề xuất thuật toán khôi phục khóa mã hóa (phải hiệu quả hơn bruteforce).
