Google CTF 2023
***************

LEAST COMMON GENOMINATOR?
=========================

Bài này sinh ra :math:`8` số nguyên tố để mã hóa. Từ một trạng thái seed ban đầu :math:`s`, số tiếp theo được sinh ra bởi số trước bởi công thức :math:`s_{i+1} = (m s_i + c) \bmod{n}`.

Chúng ta chỉ biết seed ban đầu, không biết :math:`m`, :math:`c` hay :math:`n`. Đề cho chúng ta dãy :math:`6` số đầu tạo bởi chuỗi trên, giả sử là :math:`s_0`, :math:`s_1`, :math:`s_2`, ...

Mình thấy rằng :math:`s_1 = (m s_0 + c) \bmod n`, :math:`s_2 = (m s_1 + c) \bmod n` và :math:`s_3 = (m s_2 + c) \bmod n`.

Trừ vế theo vế mình có :math:`s_2 - s_1 = m (s_1 - s_0) \bmod n` và :math:`s_3 - s_2 = m (s_2 - s_1) \bmod n`.

Suy ra :math:`n \mid (s_2 - s_1) - m (s_1 - s_0)` và :math:`n \mid (s_3 - s_2) - m (s_2 - s_1)`. Như vậy nhân chéo lên để khử :math:`m` mình thu được 

.. math:: 
    
    \begin{cases}
        n \mid (s_2 - s_1)^2 - m(s_1 - s_0) (s_2 - s_1) \\ 
        n \mid (s_3 - s_2) (s_1 - s_0) - m (s_2 - s_1) (s_1 - s_0)
    \end{cases},

hay tương đương với 

.. math:: n \mid (s_2 - s_1)^2 - (s_3 - s_2)(s_1 - s_0)

Tương tự như vậy với các cặp khác, dùng gcd mình sẽ tìm ra được :math:`n`.

Khi đã có :math:`n`, nhớ lại rằng :math:`s_2 - s_1 = m (s_1 - s_0) \bmod n` sẽ suy ra được :math:`m`. Cuối cùng do :math:`s_1 = (m s_0 + c) \bmod n` nên sẽ tìm được :math:`c`.

Có đủ :math:`n`, :math:`m` và :math:`c` mình chạy hàm như đề bài là sẽ tìm được các số nguyên tố từ đó decrypt ra được kết quả.

.. only:: html

    .. code-block:: python

        s0 = 2166771675595184069339107365908377157701164485820981409993925279512199123418374034275465590004848135946671454084220731645099286746251308323653144363063385
        s1 = 6729272950467625456298454678219613090467254824679318993052294587570153424935267364971827277137521929202783621553421958533761123653824135472378133765236115
        s2 = 2230396903302352921484704122705539403201050490164649102182798059926343096511158288867301614648471516723052092761312105117735046752506523136197227936190287
        s3 = 4578847787736143756850823407168519112175260092601476810539830792656568747136604250146858111418705054138266193348169239751046779010474924367072989895377792
        s4 = 7578332979479086546637469036948482551151240099803812235949997147892871097982293017256475189504447955147399405791875395450814297264039908361472603256921612
        s5 = 2550420443270381003007873520763042837493244197616666667768397146110589301602119884836605418664463550865399026934848289084292975494312467018767881691302197
        s_ = 211286818345627549183608678726370412218029639873054513839005340650674982169404937862395980568550063504804783328450267566224937880641772833325018028629959635

        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        u = -(s2 - s1)**2 + (s1 - s0)*(s3 - s2)
        v = -(s2 - s1)*(s3 - s2) + (s1 - s0)*(s4 - s3)
        w = (s3 - s2)**2 - (s2 - s1)*(s4 - s3)

        n = gcd(gcd(u, v), w) // 7
        m = pow(s1-s2, -1, n) * (s2-s3) % n
        c = (s1 - m*s0) % n


        class LCG:
            lcg_m = m
            lcg_c = c
            lcg_n = n

            def __init__(self, lcg_s):
                self.state = lcg_s

            def next(self):
                self.state = (self.state * self.lcg_m + self.lcg_c) % self.lcg_n
                return self.state
            
        primes_arr = []
        primes_n = 1
        lcg = LCG(s_)

        from Crypto.Util.number import isPrime, bytes_to_long, long_to_bytes
        from Crypto.PublicKey import RSA

        while True:
            for i in range(8):
                while True:
                    prime_candidate = lcg.next()
                    if not isPrime(prime_candidate):
                        continue
                    elif prime_candidate.bit_length() != 512:
                        continue
                    else:
                        primes_n *= prime_candidate
                        primes_arr.append(prime_candidate)
                        break
            
            if primes_n.bit_length() > 4096:
                primes_arr.clear()
                primes_n = 1
                continue
            else:
                break

        print(primes_arr)

        n = 1
        for j in primes_arr:
            n *= j
        print("[+] Public Key: ", n)
        print("[+] size: ", n.bit_length(), "bits")

        # Calculate totient 'Phi(n)'
        phi = 1
        for k in primes_arr:
            phi *= (k - 1)

        # Calculate private key 'd'
        d = pow(65537, -1, phi)
        rsa = RSA.importKey(open("public.pem").read())
        assert rsa.n == n
        assert rsa.e == 65537

        with open("flag.txt", "rb") as f:
            data = int.from_bytes(f.read(), "little")
            m = pow(data, d, n)
            print(long_to_bytes(m))

        # b'CTF{C0nGr@tz_RiV35t_5h4MiR_nD_Ad13MaN_W0ulD_b_h@pPy}'

Cursved
=======

Bài này định nghĩa một đường cong (có lẽ vậy) là tập hợp các điểm thỏa phương trình :math:`x^2 = D y^2 + 1 \bmod p` với :math:`D = 3` và :math:`p` là số nguyên tố cho trước.

Phép cộng hai điểm :math:`(x_1, y_1)` và :math:`(x_2, y_2)` được định nghĩa là điểm :math:`(x_1 x_2 + D y_1 y_2, x_1 y_2 + x_2 y_1)` (tất cả trong modulo :math:`p`).

Đề bài cho chúng ta biết điểm generator là :math:`G = (2, 1)`, public key là một điểm không đổi trong tất cả lần chạy (điểm :math:`P`). Mình gọi :math:`k` là private key, là một số trong modulo :math:`n = p-1` sao cho :math:`P = k G`.

Hướng tấn công của bài này là xây dựng một homomorphism từ nhóm các điểm trên lên :math:`\mathrm{GF}(p)` và giải discrete logarithm trên :math:`\mathrm{GF}(p)`. Mình xét ánh xạ

.. math:: \varphi: \mathbb{F}_p \times \mathbb{F}_p \to \mathbb{F}_p, \quad (x, y) \to x + yW

Ở đây :math:`W` là một số nào đó thuộc :math:`\mathrm{GF}(p)`. Mình muốn ánh xạ này là homomorphism thì tương đương với điều kiện

.. math:: \varphi(x_1, y_1) \cdot \varphi(x_2, y_2) = \varphi(x_1 x_2 + D y_1 y_2, x_1 y_2 + x_2 y_1)

Tương đương với

.. math:: (x_1 + y_1 W) \cdot (x_2 + y_2 W) = (x_1 x_2 + D y_1 y_2) + (x_1 y_2 + x_2 y_1) W

Khai triển và thu gọn mình có được :math:`W^2 = D`. Như vậy :math:`W = \sqrt{3} \bmod p`.

Và đúng là :math:`D` là số chính phương modulo :math:`p` thật, quá tốt :))))

Như vậy mình sẽ chuyển việc tính toán discrete logarithm :math:`P = k G` trên tập hợp các điểm trên thành việc tính toán discrete logarithm ứng với phương trình

.. math:: (x_G + y_G W)^k = (x_P + y_P W) \bmod p

Tới đây thì khá bế tắc vì :math:`p-1` có các thừa số rất lớn. Mình đi "hỏi thăm" 1 vòng thì biết có tool open source rất mạnh để tính việc này là `cado-nfs <https://github.com/cado-nfs/cado-nfs>`_.

Đặt :math:`g = x_G + y_G W \bmod p` và :math:`h = x_P + y_P W \bmod p`. Lúc giải mình thấy một điều lạ lùng là mình không dùng tool trên tính dlog modulo 2 được, nên mình chỉ tính dlog của :math:`g` và :math:`h` trên modulo :math:`(p-1)/2`. Cado-nfs sẽ trả về base, mình gọi là :math:`b`, và dlog của :math:`g` và :math:`h` lần lượt là :math:`t_1` và :math:`t_2`.

Do :math:`g = b^{t_1}`, :math:`h = b^{t_2}`, :math:`h = g^k` nên :math:`b^{t_2} = b^{t_1 k}` (tất cả modulo :math:`p`). Suy ra :math:`t_2 = t_1 k \bmod \dfrac{p-1}{2}`, từ đó mình tìm được :math:`k` và :math:`k` này thỏa mãn :math:`P = k G`.

Như vậy mình đã khôi phục lại private key và sẵn sàng ký bất cứ `nonce` nào gửi tới.

.. only:: html

    .. code-block:: python

        from pwn import remote, context, process

        context.log_level = 'Debug'

        C = Curve(0x34096DC6CE88B7D7CB09DE1FEC1EDF9B448D4BE9E341A9F6DC696EF4E4E213B3,
                0x3,
                0x34096DC6CE88B7D7CB09DE1FEC1EDF9B448D4BE9E341A9F6DC696EF4E4E213B2)
        G = C @ (0x2, 0x1)
        P = C @ (0x2FE4D1B7BA0F64D6E5BD5E4E8D55E898FF13B76974646D97BFDCD9DC688C0E2F, 0x8C33E2FC2957EFF24DD1CD5382169C3BFAAC2E75A900D322A8C84D3C641A27E)
        x = 597042838662739992479017662198571932571177156379622917145185173378909836425
        print(x * G == P)
        r = remote("cursved.2023.ctfcompetition.com", 1337)
        #r = process(["python3", "chal.py"])
        priv = Priv(x, G)
        r.recvline()
        pub = r.recvline().strip().decode().split(" ")
        nonce = r.recvline().strip().decode().split(" ")[-1]
        print(priv.get_pub().P)
        print(nonce)
        sig = priv.sign(bytes.fromhex(nonce))
        Rx, Ry, s = sig[0].x, sig[0].y, sig[1]
        r.sendlineafter(b"sig = ", " ".join(str(i) for i in [Rx, Ry, s]).encode())
        r.recvline()
        r.close()

        # b'CTF{pe11_conics_are_not_quite_e11iptic_curves}\n'

MHK2
====

1. Tạo private key
------------------

Để tạo private key, server random hai dãy số :math:`s_1 = (s_{11}, s_{12}, \ldots, s_{1n})` và :math:`s_2 = (s_{21}, s_{22}, \ldots, s_{2n})` với :math:`n = 256` và :math:`s_{ij}` :math:`64` bit.

Hệ thống sinh dãy số cho tới khi :math:`\displaystyle{p_1 = \sum_{i=1}^n s_{1i} + 2}` là số nguyên tố, tương tự cho :math:`\displaystyle{p_2 = \sum_{i=1}^n s_{2i} + 2}` là số nguyên tố. Sau đó hệ thống chọn ngẫu nhiên số :math:`e_1 \in \Bigl[\dfrac{p_1}{2}, p_1\Bigl]` và :math:`e_2 \in \Bigl[\dfrac{p_2}{2}, p_2\Bigr]`.

Cuối cùng tính 

.. math:: s = (s_{11} + s_{21}, s_{12} + s_{22}, \ldots, s_{1n} + s_{2n}) = (s_1, s_2, \ldots, s_n).

2. Tạo public key
-----------------

Từ hai dãy :math:`s_1` và :math:`s_2` ở trên hệ thống tính hai dãy :math:`a_1 = (e_1 * s_{11}, e_1 * s_{12}, \ldots, e_1 * s_{1n})` (tất cả trong modulo :math:`p_1`) và :math:`a_2 = (e_2 * s_{21}, e_2 * s_{22}, \ldots, e_2 * s_{2n})` (tất cả trong modulo :math:`p_2`).

Đặt 

.. math:: b_1 = (s_{11} \bmod 2, s_{12} \bmod 2, \ldots, s_{1n} \bmod 2).

Đặt 

.. math:: b_2 = (s_{21} \bmod 2, s_{22} \bmod 2, \ldots, s_{2n} \bmod 2).

Đặt

.. math:: b = (s_1 \bmod 2, s_2 \bmod 2, \ldots, s_n \bmod 2).

Cuối cùng, :math:`c` được chọn ngẫu nhiên, hoặc là :math:`b_1`, hoặc là :math:`b_2`.

3. Mã hóa
---------

Để mã hóa một bit, :math:`\mathrm{bit} \in \{0, 1\}`, đầu tiên tạo hai dãy ngẫu nhiên :math:`r_1 = (r_{11}, r_{12}, \ldots, r_{1n})` và :math:`r_2 = (r_{21}, r_{22}, \ldots, r_{2n})` với :math:`r_{ij} \in \{0, 1\}`.

Khi đó ciphertext là :math:`c_1 = \sum_{i=1}^n a_{1i} \cdot r_{1i}` và :math:`c_2 \sum_{i=1}^n a_{2i} \cdot r_{2i}` (điều kiện đối với :math:`\mathrm{bit}` ở :math:`m_1`, :math:`m_2` và :math:`eq` nhưng hiện tại chúng ta không cần dùng tới).

4. Khôi phục private key
------------------------

Chi tiết cách giải bài này mình tham khảo writeup của Google và Mystiz. Về mặt lý thuyết mình không hiểu sao họ có thể nghĩ ra lattice hay như vậy :)))) Do đó ở đây mình chỉ trình bày cách xây dựng lattice để giải bài này.

Ý tưởng là từ public key :math:`a_1` (:math:`a_2` tương tự) mình sẽ khôi phục lại :math:`p_1` và :math:`e_1`.

Đặt :math:`A_1 = \sum_{i=1}^n a_{1i}`. 

Do :math:`a_{1i} = e_1 \cdot s_{1i} \bmod p_1` với :math:`i = \overline{1, n}` nên :math:`A_1 = \sum\limits_{i=1}^n e_1 \cdot s_{1i} = e_1 \sum\limits_{i=1}^N s_{1i}`. Mà mình đã biết :math:`p_1 = \sum\limits_{i=1}^n s_{1i} + 2` nên phương trình trên tương đương với :math:`A_1 = e_1 * (p_1 - 2)`. Lấy modulo :math:`p_1` ta có :math:`A_1 \equiv -2 e_1 \bmod p_1`.

Từ việc :math:`a_{1i} \equiv e_1 \cdot s_{1i} \bmod p_1`, ta có :math:`2 a_{1i} \equiv 2 e_1 \cdot s_{1i} \equiv -A_1 \cdot s_{1i} \bmod p_1`.

Nghĩa là tồn tại số :math:`x_{1i} \in \mathbb{Z}` sao cho :math:`2 a_{1i} + A_1 \cdot s_{1i} = x_{1i} \cdot p_1` với :math:`i = \overline{1, n}`.

Mình có thể đánh giá :math:`x_{1i}` đơn giản như sau: 

.. math:: x_{1i} = \dfrac{2 a_{1i} + A_1 s_{1i}}{p_1} \leqslant \dfrac{2 \max(a_{1i}) + A_1 \cdot 2^{128}}{\max(a_{1i})}

xấp xỉ 136 bit.

Lấy :math:`i=1` ta có :math:`2 a_{11} + A_1 \cdot s_{11} = x_{11} \cdot p_1` (1).

Lấy :math:`2 \leqslant i \leqslant n` ta có :math:`2 a_{1i} + A_1 \cdot s_{1i} = x_{1i} \cdot p_1` (2).

Để khử :math:`p_1` mình nhân hai vế phương trình (1) cho :math:`x_{1i}` và nhân hai vế phương trình (2) cho :math:`x_{11}`, rồi trừ vế theo vế thu được

.. math:: 2 a_{11} \cdot x_{1i} - 2 a_{1i} \cdot x_{11} + A_1 (s_{11} \cdot x_{1i} - s_{1i} \cdot x_{11}) = 0.

Ở đây chúng ta đã biết :math:`a_{11}`, :math:`a_{1i}` và :math:`A_1`. Việc xây dựng lattice sẽ dựa trên các hệ số :math:`x_{1i}`, :math:`x_{11}` và :math:`s_{11} \cdot x_{1i} - s_{1i} * s_{11}`. Do đó mình viết

.. math:: 
    
    \begin{array}{ccc}
        x_{11} & \cdot & (\ldots, -2a_{1i}, \ldots) \\ 
        x_{1i} & \cdot & (\ldots, 2a_{11}, \ldots) \\ 
        \ldots & \cdot & (\ldots, \ldots, \ldots) \\ 
        (s_{11} \cdot x_{1i} - s_{1i} * x_{11}) & * & (\ldots, A_1, \ldots) \\ 
        \ldots & \cdot & (\ldots, \ldots, \ldots)
    \end{array}

Với :math:`i = \overline{2, n}` thì mình sẽ cần :math:`255` cột. Tuy nhiên chúng ta thường sử dụng :math:`1` để khi tính ra lattice thì sẽ thu được số cần tìm, cụ thể ở đây là :math:`x_{11}` và :math:`s_{11} \cdot x_{1i} - s_{1i} \cdot x_{11}`. Do đó mình sẽ modify nhẹ lại lattice trên thành

.. math:: 
    
    \begin{array}{ccc}
        x_{11} & \cdot & (1, \ldots, -2a_{1i}, \ldots) \\ 
        x_{1i} & \cdot & (\ldots, \ldots, 2a_{11}, \ldots) \\ 
        \ldots & \cdot & (\ldots, \ldots, \ldots, \ldots) \\ 
        (s_{11} \cdot x_{1i} - s_{1i} * x_{11}) & * & (0, 1, \ldots, A_1, \ldots) \\ 
        \ldots & \cdot & (\ldots, \ldots, \ldots, \ldots)
    \end{array}

Ở dòng :math:`s_{11} \cdot x_{1i} - s_{1i} \cdot x_{11}` chúng ta không muốn nó đụng độ với số :math:`x_{11}` bên trên nên sẽ dịch qua phải một ô. Ta cần :math:`255` cột như vậy vì sẽ có :math:`i=\overline{2, 256}`. Và để sắp xếp :math:`-2 a_{1i}` cũng cần :math:`255` cột như đã nói ở trên. Vậy lattice này có :math:`1 + 255 + 255 = 511` cột và cũng là số hàng. Lattice như vậy sẽ có dạng ma trận như sau

.. math:: \begin{pmatrix}1 & 0 & 0 & \ldots & -2a_{12} & -2a_{13} & \ldots \\ 0 & 0 & 0 & \ldots & 2a_{11} & 0 & \ldots \\ 0 & 0 & 0 & \ldots & 0 & 2a_{11} & \ldots \\ \ldots & \ldots & \ldots & \ldots & \ldots & \ldots & \ldots \\ 0 & 1 & \ldots & \ldots & A_1 & 0 & \ldots \\ 0 & 0 & 1 & \ldots & 0 & A_1 & \ldots \\ \ldots & \ldots & \ldots & \ldots & \ldots & \ldots & \ldots \\ \end{pmatrix}

Tới lúc này chúng ta đã hoàn thành ... 10% chặng đường. Lý do là vì với lattice này chúng ta không thể giải ra short vector mong muốn được. Dựa trên lattice mình hy vọng sẽ chạy ra vector

.. math:: v = (x_{11}, s_{11} \cdot x_{12} - s_{12} \cdot x_{11}, \ldots, s_{11} \cdot x_{1n} - s_{1n} \cdot x_{11}, 0, 0, \ldots, 0)

Tuy nhiên cần nhớ rằng :math:`s_{1i}` có :math:`64` bit và :math:`x_{1i}` xấp xỉ :math:`136` bit. Bằng tính toán có thể thấy :math:`s_{11} \cdot x_{1i} - s_{1i} \cdot x_{11}` cũng có :math:`64` bit. Như vậy chúng ta cần scale lattice trên để các giá trị không sai khác nhau quá lớn.

Cụ thể, do :math:`x_{11}` có :math:`136` bit nên ta sẽ nhân với :math:`\dfrac{1}{2^{136}}`, do :math:`s_{11} \cdot x_{1i} - s_{1i} \cdot x_{11}` có :math:`64` bit nên ta sẽ nhân với :math:`\dfrac{1}{2^{128}}`. Đối với :math:`-2a_{1i}`, :math:`2a_{11}` và :math:`A_1` thì mình cần chúng lớn để lattice tìm ra short vector, nên nhân với :math:`2^{1024}`.

Sử dụng tính chất

.. math:: \begin{pmatrix} a_{11} & a_{12} & \ldots & a_{1n} \\ a_{21} & a_{22} & \ldots & a_{2n} \\ \ldots & \ldots & \ldots & \ldots \\ a_{n1} & a_{n2} & \ldots & a_{nn} \end{pmatrix} \times \begin{pmatrix} b_1 & 0 & 0 & 0 \\ 0 & b_2 & 0 & 0 \\ 0 & 0 & \ddots & 0 \\ 0 & 0 & 0 & b_n \end{pmatrix} = \begin{pmatrix} a_{11} b_1 & a_{12} b_2 & \ldots & a_{1n} b_n \\ a_{21} b_1 & a_{22} b_2 & \ldots & a_{2n} b_n \\ \ldots & \ldots & \ldots & \ldots \\ a_{n1} b_1 & a_{n2} b_2 & \ldots & a_{nn} b_n \end{pmatrix}

Mình sẽ nhân lattice trên với ma trận sau là sẽ scale được hệ số theo nhu cầu

.. math:: \begin{pmatrix}\dfrac{1}{2^{136}} & & & & & & \\ & \dfrac{1}{2^{128}} & & & & & \\ & & \ddots & \dfrac{1}{2^{128}} & & & & \\ & & & & 2^{1024} & & \\ & & & & & \ddots & \\ & & & & & & 2^{1024}\end{pmatrix}

Phần tử đầu tiên của short vector là :math:`x_{11}` (có lẽ vậy :v). Thật ra thì phần tử đầu tiên của short vector là :math:`x_{11} \bmod a_{11}` hoặc :math:`-x_{11} \bmod a_{11}`. Phía trên mình đã tính được chặn trên của :math:`x_{11}` là :math:`\dfrac{2 \max(a_{1i}) + A_1 \cdot 2^{128}}{\max(a_{1i})}`. Từ đây mình duyệt vòng for qua các giá trị :math:`x_{11} + k a_{11}` và :math:`-x_{11} + k a_{11}` để tìm các số :math:`s_{1i}` theo cách sau

a. Khôi phục modulo
^^^^^^^^^^^^^^^^^^^

Nhắc lại :math:`2 a_{11} + A_1 \cdot s_{11} = x_{11} \cdot p_1`. Modulo hai vế cho :math:`A_1` thì được :math:`2 a_{11} = x_{11} * p_1 \bmod A_1`. Ở đây có thể tìm được :math:`p_1 = 2a_{11} x_{11}^{-1} \bmod A_1`. Tuy nhiên chúng ta cần lưu ý rằng điều kiện để tồn tại nghịch đảo là :math:`\gcd(x_{11}, A_1) = 1`. Do đó để đảm bảo chúng ta tính toán thêm một bước.

Đặt :math:`g = \gcd(2a_{11}, A_1)`. Khi đó phương trình đồng dư có nghiệm khi và chỉ khi :math:`\gcd(x_{11} \cdot p_1, A_1)` chia hết cho :math:`g`. Sau khi thỏa các điều kiện này, đặt :math:`\dfrac{A_1}{g} = A_1'`, :math:`2 a_{11}' = \dfrac{2a_{11}}{g} \bmod \dfrac{A_1}{g}`, và :math:`x_{11}' = \dfrac{x_{11}}{g} \bmod \dfrac{A_1}{g}`. Khi đó :math:`p_1 = 2a_{11}' \cdot x_{11}'^{-1} \bmod A_1'`.

b. Khôi phục e
^^^^^^^^^^^^^^

Bên trên mình đã có :math:`A_1 = -2e_1 \bmod p_1` nên mình sẽ tìm được :math:`e_1`. Sau đó từ :math:`a_1 = (a_{11}, a_{12}, \ldots, a_{1n})` và :math:`e_1` mình tính lại được tất cả :math:`s_{1i}` và kiểm tra xem :math:`\sum\limits_{i=1}^n s_i + 2 \equiv p_1`, đồng thời không có số :math:`s_{1i}` nào vượt quá :math:`64` bit.

c. Giải
^^^^^^^

Đoạn code mình lấy của Google. Lưu ý rằng sau khi LLL xong mình cần scale ngược lại độ lớn ban đầu, ở đây là chia cho ma trận :math:`Q`. Do một chút lười nên ở đây thay `a2` thành `a_1` để áp dụng cho :math:`p_1`.

.. only:: html

    .. code-block:: python

        M = Matrix(QQ, 511, 511)
        sum_a = sum(a2)
        M[0, 0] = 1
        for i in range(255):
            M[256+i, i+1] = 1

        for i in range(255):
            M[0, 256+i] = -2*a2[i+1]
            M[i+1, 256+i] = 2*a2[0]
            M[256+i, 256+i] = sum_a

        weights = [1/2^136] + [1/2^128 for _ in range(255)] + [2^1024 for _ in range(255)]
        Q = diagonal_matrix(weights)

        M *= Q
        M = M.LLL()
        print(f"Done LLL!")
        M /= Q

        for row in M:
            x0_ = row[0]
            y = row[1:256]
            zeros = row[256:]

            if list(y) == [0 for _ in range(255)]: continue
            if min(zeros) != 0: continue
            if max(zeros) != 0: continue

            x0_bound = (2*max(a2) + sum_a * 2^128) // max(a2)
            for x0 in range(+x0_, x0_bound, +a2[0]):
                u, v, m = x0, 2*a2[0], sum_a
                #print(u, v, m)
                g = gcd(v, m)
                if gcd(u, m) % g != 0: continue
                u, v, m = u // g, v // g, m // g
                try:
                    p1 = int(Zmod(m)(v/u))
                    if p1 % 2 == 0: continue
                    if not is_prime(p1): continue
                    e = int(Zmod(p1)(-sum_a / 2))
                    if e == 0 or gcd(e, p1) != 1: continue
                    s = [int(Zmod(p1)(a_/e)) for a_ in a2]
                    if sum(s) + 2 != p1: continue
                    if max(s) >= 2^128: continue
                    print(f"Found! p = {p1}, e = {e}")
                except:
                    pass

            for x0 in range(-x0_, x0_bound, +a2[0]):
                u, v, m = x0, 2*a2[0], sum_a
                #print(u, v, m)
                g = gcd(v, m)
                if gcd(u, m) % g != 0: continue
                u, v, m = u // g, v // g, m // g
                try:
                    p1 = int(Zmod(m)(v/u))
                    if p1 % 2 == 0: continue
                    if not is_prime(p1): continue
                    e = int(Zmod(p1)(-sum_a / 2))
                    if e == 0 or gcd(e, p1) != 1: continue
                    s = [int(Zmod(p1)(a_/e)) for a_ in a2]
                    if sum(s) + 2 != p1: continue
                    if max(s) >= 2^128: continue
                    print(f"Found! p = {p1}, e = {e}")
                except:
                    pass

Cuối cùng chạy decrypt và lấy flag thôi.

.. code-block:: python

    # CTF{faNNYPAcKs_ARe_4maZiNg_AnD_und3Rr@t3d}

MYTLS
=====

Bài này dựa trên nguyên lý handshake của TLS (mãi sau mình đàm đạo với các bạn khác mới biết :v). Trong bài này đề cho các file sau:

* admin-ecdhcert.pem
* ca-crt.pem
* Dockerfile
* guest-ecdhcert.pem
* guest-ecdhkey.pem
* server-ecdhcert.pem
* server.py
* start.sh

Ở bài này xảy ra hai công đoạn trao đổi khóa, mình sẽ gọi là `share_key` và `share_ephemeral_key`.

Đối với `share_ephemeral_key`, mình sẽ cần gửi lên một chuỗi hex độ dài :math:`32` ký tự, và một public key ECDH theo dạng PEM. Server cũng sẽ tạo một chuỗi hex độ dài :math:`32` ký tự, private key và public key ECDH, sau đó gửi public key ECDH này về cho mình cũng ở dạng PEM.

Khi đó `share_ephemeral_key` sẽ được tính là

.. code-block:: python

    server_ephemeral_secret = client_ephemeral_private_key.exchange(
        ec.ECDH(), server_ephemeral_public_key)

Điều này là tương đương với đoạn code sau của đề vì việc trao đổi khóa sẽ giống nhau ở hai bên trao đổi khóa.

.. code-block:: python
    
    server_ephemeral_secret = server_ephemeral_key.exchange(
        ec.ECDH(), client_ephemeral_public_key)

Do đó mình chỉ cần tạo một ECDH key mỗi lần trao đổi khóa, hoặc tạo một lần cũng được.

Tiếp theo là ``share_key``.

Ở đầu bài, mình sẽ cần cung cấp một public key (certificate) cho server. Server sẽ sử dụng ca-crt.pem để verify xem cert của mình có hợp lệ không (có được ký bởi CA không). Server cũng sẽ đọc private key tương ứng (ở file `server-ecdhkey.pem`) và tiến hành trao đổi khóa ECDH lần hai.

.. code-block:: python
    
    server_secret = server_key.exchange(ec.ECDH(), client_cert.public_key())

Đoạn code trên thực hiện việc thực hiện trao đổi khóa với certificate (public key) nhận từ client, và server private key.

Mình thấy rằng đề đã cung cấp cho mình hai file cert và key của guest đã được ký bởi CA. Do đó mình dùng `guest-ecdhcert.pem` làm `client_cert`, và đề cũng đã cho mình `server-ecdhcert.pem` nên mình có thể tính toán khóa trao đổi ở phía mình.

.. code-block:: python

    server_secret = client_key.exchange(ec.ECDH(), server_cert.public_key())

Đoạn code sau đây sẽ thực hiện việc bắt tay trên TLS.

.. only:: html

    .. code-block:: python

        r = remote("mytls.2023.ctfcompetition.com", 1337)
        r.recvuntil(b'Please provide the client certificate in PEM format:')
        with open("guest-ecdhcert.pem", "rb") as f:
            for line in f.readlines():
                r.send(line)
        r.sendline()

        # Exchange ECDH
        r.sendlineafter(b'Please provide the ephemeral client random:', bytes(16).hex().encode())
        r.recvuntil(b'Please provide the ephemeral client key:')
        with open("client-ecdhcert.pem", "rb") as f:
            for line in f.readlines():
                r.send(line)
        r.sendline()

        # Get server ephemeral public key
        r.recvuntil(b'Server ephemeral random:\n')
        server_random = r.recvline().strip()
        r.recvuntil(b'Server ephemeral key:\n')

        server_cert = b""
        while True:
            data = r.recvline()
            if data == b'\n': break
            server_cert += data

        server_cert = serialization.load_pem_public_key(server_cert)

        # Load client epehmeral private key
        with open("client-ecdhkey.pem", "rb") as f:
            client_ephemeral_private_key = serialization.load_pem_private_key(
                f.read(),
                None,
                default_backend()
            )

        # Calculate shared key
        server_ephemeral_secret = client_ephemeral_private_key.exchange(ec.ECDH(), server_cert)

        # Exchange cert and key
        with open("server-ecdhcert.pem", "rb") as f:
            server_public_key = x509.load_pem_x509_certificate(f.read())
            server_public_key = server_public_key.public_key()

        with open("guest-ecdhkey.pem", "rb") as f:
            client_key = serialization.load_pem_private_key(f.read(), None)
            
        server_secret = client_key.exchange(ec.ECDH(), server_public_key)

        derived_key = HKDF(algorithm=hashes.SHA256(),
                        length=32,
                        salt=b'SaltyMcSaltFace',
                        info=b"mytls").derive(
                            server_ephemeral_secret +
                            server_secret +
                            bytes(16).hex().encode() +
                            server_random
                        )

        client_hmac = hmac.HMAC(derived_key, hashes.SHA256())
        client_hmac.update(b'client myTLS successful!')
        r.sendlineafter(b'Please provide the client HMAC:\n', client_hmac.finalize().hex().encode())

        server_hmac = hmac.HMAC(derived_key, hashes.SHA256())
        server_hmac.update(b'server myTLS successful!')
        r.recvuntil(b'Server HMAC:\n')
        assert server_hmac.finalize().hex() == r.recvline().strip().decode()

Tuy nhiên tới đây chúng ta vấp phải một vấn đề, đó là subject được ký trên certificate phải là `admin.tls`, trong khi nếu sử dụng `guest-ecdhcert.pem` thì subject là `guest.tls`. Hmm tình hình có vẻ khá phức tạp. Tới đây thì mình chịu chết, sau giải mới làm ra :D

Khi nhìn vào file Docker, mình thấy rằng file `server-ecdhkey`.pem cũng được chép vào container. Từ đó, ở mỗi lần chạy vòng lặp, mình sẽ chỉ định path của file thành `../../app/server-ecdhkey.pem` để thoát khỏi path `/tmp/storage`, vì khi đó mình sẽ "đọc" được một ít thông tin nào đó từ `server-ecdhkey.pem`.

Do `server-ecdhcert.pem` có :math:`241` bytes, mình đoán rằng `server-ecdhkey.pem` cũng có :math:`241` bytes. Do đó chiến thuật của mình là ghi đè lên :math:`240` bytes đầu của `server-ecdh.pem`, server sẽ trả về hash `H(240_bytes_ghi_đè || byte_cuối)`. Mình có thể bruteforce byte cuối với :math:`240` bytes ghi đè ban đầu fix sẵn.

Sau đó mình connect lại. Với byte cuối đã biết, mình sẽ bruteforce byte kế cuối với :math:`239` bytes ghi đè. Lúc này server trả về hash `H(239_bytes_ghi_đè || byte_kế_cuối || byte_cuối)`.

Như vậy mình bruteforce từ dưới lên với công thức `((240-số bytes đã biết) || byte_cần_brute || bytes_đã_biết)` (có 241 bytes).

Full code để bruteforce `server-ecdhkey.pem`:

.. only:: html

    .. code-block:: python
        
        # get_key.py
        from pwn import remote, context
        from cryptography.hazmat.primitives import serialization
        from cryptography.hazmat.backends import default_backend
        from cryptography.hazmat.primitives.asymmetric import ec
        from cryptography.hazmat.primitives.asymmetric import rsa
        from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
        from cryptography.hazmat.primitives.kdf.hkdf import HKDF
        from cryptography.hazmat.primitives import hashes
        from cryptography.hazmat.primitives import hmac
        from cryptography import x509
        import binascii
        import hashlib

        #context.log_level = 'Debug'

        def print_encrypted(message, iv, key):
            cipher = Cipher(
                algorithms.AES(key),
                modes.CBC(binascii.unhexlify(iv)))
            encryptor = cipher.encryptor()
            message = message.encode('utf-8')
            payload = encryptor.update(
                message + b'\x00' * (16 - len(message) % 16)) + encryptor.finalize()

            return binascii.hexlify(payload).decode('utf-8')

        def print_decrypted(message, iv, key):
            cipher = Cipher(
                algorithms.AES(key),
                modes.CBC(binascii.unhexlify(iv)))
            decryptor = cipher.decryptor()
            message = bytes.fromhex(message)
            payload = decryptor.update(message)

            return payload.strip(b"\x00")

        def input_encrypted(iv, key):
            cipher = Cipher(
                algorithms.AES(key),
                modes.CBC(binascii.unhexlify(iv)))
            decryptor = cipher.decryptor()
            payload = input()
            payload = binascii.unhexlify(payload)
            res = decryptor.update(payload)

            return res.strip(b'\x00')


        key_path = "../../app/server-ecdhkey.pem"
        known = ''

        while True:
            r = remote("mytls.2023.ctfcompetition.com", 1337)
            r.recvuntil(b'Please provide the client certificate in PEM format:')
            with open("guest-ecdhcert.pem", "rb") as f:
                for line in f.readlines():
                    r.send(line)
            r.sendline()

            # Exchange ECDH
            r.sendlineafter(b'Please provide the ephemeral client random:', bytes(16).hex().encode())
            r.recvuntil(b'Please provide the ephemeral client key:')
            with open("client-ecdhcert.pem", "rb") as f:
                for line in f.readlines():
                    r.send(line)
            r.sendline()

            # Get server ephemeral public key
            r.recvuntil(b'Server ephemeral random:\n')
            server_random = r.recvline().strip()
            r.recvuntil(b'Server ephemeral key:\n')

            server_cert = b""
            while True:
                data = r.recvline()
                if data == b'\n': break
                server_cert += data

            server_cert = serialization.load_pem_public_key(server_cert)

            # Load client epehmeral private key
            with open("client-ecdhkey.pem", "rb") as f:
                client_ephemeral_private_key = serialization.load_pem_private_key(
                    f.read(),
                    None,
                    default_backend()
                )

            # Calculate shared key
            server_ephemeral_secret = client_ephemeral_private_key.exchange(ec.ECDH(), server_cert)

            # Exchange cert and key
            with open("server-ecdhcert.pem", "rb") as f:
                server_public_key = x509.load_pem_x509_certificate(f.read())
                server_public_key = server_public_key.public_key()

            with open("guest-ecdhkey.pem", "rb") as f:
                client_key = serialization.load_pem_private_key(f.read(), None)
                
            server_secret = client_key.exchange(ec.ECDH(), server_public_key)

            derived_key = HKDF(algorithm=hashes.SHA256(),
                            length=32,
                            salt=b'SaltyMcSaltFace',
                            info=b"mytls").derive(
                                server_ephemeral_secret +
                                server_secret +
                                bytes(16).hex().encode() +
                                server_random
                            )

            client_hmac = hmac.HMAC(derived_key, hashes.SHA256())
            client_hmac.update(b'client myTLS successful!')
            r.sendlineafter(b'Please provide the client HMAC:\n', client_hmac.finalize().hex().encode())

            server_hmac = hmac.HMAC(derived_key, hashes.SHA256())
            server_hmac.update(b'server myTLS successful!')
            r.recvuntil(b'Server HMAC:\n')
            assert server_hmac.finalize().hex() == r.recvline().strip().decode()

            ciphertext = r.recvline() # now ignore
            ctx = r.recvline().strip().decode()
            print_decrypted(ctx, server_random, derived_key)
            storage_slot = r.sendline(print_encrypted(key_path, server_random, derived_key).encode())
            ctx = r.recvline().strip().decode()
            print_decrypted(ctx, server_random, derived_key)

            overwrite_payload = "A"*(240 - len(known))
            secret = r.sendline(print_encrypted(overwrite_payload, server_random, derived_key).encode())
            prev_hash = print_decrypted(
                r.recvline().strip().decode(),
                server_random,
                derived_key)
            prev_hash = prev_hash.split(b" ")[-1]

            # Phase 2
            ctx = r.recvline().strip().decode()
            print(print_decrypted(ctx, server_random, derived_key))
            storage_slot = r.sendline(print_encrypted(key_path, server_random, derived_key).encode())
            ctx = r.recvline().strip().decode()
            print(print_decrypted(ctx, server_random, derived_key))

            #overwrite_payload = "A"*240
            secret = r.sendline(print_encrypted("A", server_random, derived_key).encode())
            prev_hash = print_decrypted(
                r.recvline().strip().decode(),
                server_random,
                derived_key)
            prev_hash = prev_hash.split(b" ")[-1]

            for i in range(256):
                h = hashlib.new("sha256")
                h.update((overwrite_payload + chr(i) + known).encode())
                if h.hexdigest() == prev_hash.decode():
                    known = chr(i) + known
                    print("Found", i)
                    break
            print(known)
            if len(known) == 241:
                break

        r.close()

Sau khi đã có `server-ecdhkey.pem`, mình quay lại bypass phần kiểm tra subject của certificate. Trong các file cert được cho thì có `admin-ecdhcert.pem` là có subject chúng ta cần (CN=admin.tls). Mình đã có `server-ecdhcert.pem` và `server-ecdhkey.pem` (vừa leak) để tiến hành trao đổi khóa. Tuy nhiên `server-ecdhcert.pem` thì lại không có CN=admin.tls.

Ở đây mình gửi lên `admin-ecdhcert.pem`, nhưng khi tính khóa trao đổi thì sử dụng `server-ecdhkey.pem` (không gửi `server-ecdhcert.pem`) và nó đã work!!! Đọc writeup của mọi người thì họ gọi là KCI attack do tính chất trao đổi khóa Diffie-Hellman.

Mình sửa đổi một tí file trên để lấy flag (gửi lên cert là `admin-ecdhcert.pem` và dùng `server-ecdhkey` để tính `share_key`).

.. only:: html

    .. code-block:: python
        
        # solve.py
        from pwn import remote, context
        from cryptography.hazmat.primitives import serialization
        from cryptography.hazmat.backends import default_backend
        from cryptography.hazmat.primitives.asymmetric import ec
        from cryptography.hazmat.primitives.asymmetric import rsa
        from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
        from cryptography.hazmat.primitives.kdf.hkdf import HKDF
        from cryptography.hazmat.primitives import hashes
        from cryptography.hazmat.primitives import hmac
        from cryptography import x509
        import binascii
        import hashlib

        context.log_level = 'Debug'

        def print_encrypted(message, iv, key):
            cipher = Cipher(
                algorithms.AES(key),
                modes.CBC(binascii.unhexlify(iv)))
            encryptor = cipher.encryptor()
            message = message.encode('utf-8')
            payload = encryptor.update(
                message + b'\x00' * (16 - len(message) % 16)) + encryptor.finalize()
            
            return binascii.hexlify(payload).decode('utf-8')


        def print_decrypted(message, iv, key):
            cipher = Cipher(
                algorithms.AES(key),
                modes.CBC(binascii.unhexlify(iv)))
            decryptor = cipher.decryptor()
            message = bytes.fromhex(message)
            payload = decryptor.update(message)

            return payload.strip(b"\x00")


        def input_encrypted(iv, key):
            cipher = Cipher(
                algorithms.AES(key),
                modes.CBC(binascii.unhexlify(iv)))
            decryptor = cipher.decryptor()
            payload = input()
            payload = binascii.unhexlify(payload)
            res = decryptor.update(payload)

            return res.strip(b'\x00')


        r = remote("mytls.2023.ctfcompetition.com", 1337)
        r.recvuntil(b'Please provide the client certificate in PEM format:')
        with open("admin-ecdhcert.pem", "rb") as f:
            for line in f.readlines():
                r.send(line)
        r.sendline()

        # Exchange ECDH
        r.sendlineafter(b'Please provide the ephemeral client random:', bytes(16).hex().encode())
        r.recvuntil(b'Please provide the ephemeral client key:')
        with open("client-ecdhcert.pem", "rb") as f:
            for line in f.readlines():
                r.send(line)
        r.sendline()

        # Get server ephemeral public key
        r.recvuntil(b'Server ephemeral random:\n')
        server_random = r.recvline().strip()
        r.recvuntil(b'Server ephemeral key:\n')

        server_cert = b""
        while True:
            data = r.recvline()
            if data == b'\n': break
            server_cert += data

        server_cert = serialization.load_pem_public_key(server_cert)
        # Load client epehmeral private key
        with open("client-ecdhkey.pem", "rb") as f:
            client_secret = serialization.load_pem_private_key(
                f.read(),
                None,
                default_backend()
            )

        # Calculate shared key
        server_ephemeral_secret = client_secret.exchange(ec.ECDH(), server_cert)

        # Exchange cert and key
        with open("admin-ecdhcert.pem", "rb") as f:
            server_public_key = x509.load_pem_x509_certificate(f.read())
            server_public_key = server_public_key.public_key()

        with open("server-ecdhkey.pem", "rb") as f:
            client_key = serialization.load_pem_private_key(f.read(), None)
        server_secret = client_key.exchange(ec.ECDH(), server_public_key)

        derived_key = HKDF(algorithm=hashes.SHA256(),
                        length=32,
                        salt=b'SaltyMcSaltFace',
                        info=b"mytls").derive(
                            server_ephemeral_secret +
                            server_secret +
                            bytes(16).hex().encode() +
                            server_random
                        )

        client_hmac = hmac.HMAC(derived_key, hashes.SHA256())
        client_hmac.update(b'client myTLS successful!')
        r.sendlineafter(b'Please provide the client HMAC:\n', client_hmac.finalize().hex().encode())

        server_hmac = hmac.HMAC(derived_key, hashes.SHA256())
        server_hmac.update(b'server myTLS successful!')
        r.recvuntil(b'Server HMAC:\n')
        assert server_hmac.finalize().hex() == r.recvline().strip().decode()

        ciphertext = r.recvline().strip().decode() # now ignore
        print(print_decrypted(ciphertext, server_random, derived_key))
        r.close()

        # b'Hello admin! CTF{KeyC0mpromiseAll0w51mpersonation}\n'

PRIMES
======

Đề bài cho mình một dãy các số nguyên tố :math:`p_i` cố định và một số nguyên tố :math:`q`.

Giả sử plaintext được biểu diễn ở dạng chuỗi bit :math:`b = (b_1, b_2, \ldots, b_n)` thì ciphertext sẽ là :math:`x = \prod\limits_{i=1}^n p_i^{b_i} \bmod q`.

Tuy nhiên message :math:`m` mà đề cho không encrypt ra :math:`x` tương ứng, mình sẽ gọi là :math:`y`. Nghĩa là nếu biểu diễn :math:`m = (m_1, m_2, \ldots, m_n)` thì mình có :math:`y = \prod\limits_{i=1}^n p_i^{m_i} \bmod q`. Ở đây :math:`m` và flag có cùng độ dài và sự sai lệch bit không đáng kể.

Hmm, sai lệch bit không đáng kể? :v

Đặt

.. math:: e = x y^{-1} = \prod_{i=1}^n p_i^{b_i - m_i} = \prod_{i=1}^n p_i^{e_i} \bmod q.

Khi đó :math:`e_i \in \{-1, 0, 1\}`.

Suy ra :math:`e = nd^{-1} \bmod q` với :math:`n` và :math:`d` phân tích được thành lũy thừa dương của các :math:`p_i`, từ đó tồn tại :math:`s \in \mathbb{Z}` để :math:`ed = n + sq`.

Do :math:`\lvert ed - sq \rvert = n` nên tương đương với :math:`\Bigg\lvert \dfrac{ed}{qd} - \dfrac{sq}{qd} \Bigg\rvert = \dfrac{n}{qd}`, hay :math:`\Bigg\lvert \dfrac{e}{q} - \dfrac{s}{d} \Bigg\rvert = \dfrac{n}{qd}`.

Bài này dựa trên ý tưởng `xấp xỉ Diophantine <https://en.wikipedia.org/wiki/Diophantine\_approximation>`_. Ở đây điều kiện để tồn tại chuỗi liên phân số hội tụ là :math:`nd < \dfrac{q}{2}`. Khi đó :math:`\dfrac{s}{d}` là liên phân số hội tụ dần tới :math:`\dfrac{1}{d^2}` do :math:`\dfrac{n}{qd} < \dfrac{1}{d^2}`.

Sử dụng SageMath mình có thể tìm được dãy các phân số :math:`\dfrac{s_j}{d_j}` hội tụ tới :math:`\dfrac{1}{d^2}`. Do đó chiến thuật để giải bài này là tìm :math:`d_j` mà có thể phân tích thành lũy thừa không âm của các :math:`p_i` (tương ứng :math:`y`). Sau đó với :math:`d_j e` mà cũng có thể phân tích thành lũy thừa không âm của các :math:`p_i` (tương ứng với :math:`x`) thì ta sẽ tìm được phân tích tốt nhất để sửa các bit error :math:`e_i`.

.. only:: html

    .. code-block:: python

        def to_bits(m):
            _bin = lambda b : [1 if b & (1 << n) else 0 for n in range(7)]
            return sum([_bin(b) for b in m], [])

        def from_bits(b):
            _byte = lambda c : bytes([sum([c[i] << i for i in range(7)])])
            return b''.join([_byte(b[i:i+7]) for i in range(0, len(b), 7)])

        def gen_primes(r, n):
            primes = Primes()[:n]
            bound = prod(primes[n - r:])
            return primes, next_prime(bound)

        def bitxor(a, b):
            return [a[i] ^^ b[i] for i in range(len(a))]

        def prod_exp(p, q, b):
            return prod([p[i]^b[i] for i in range(len(p))]) % q

        def encode(r, n, m):
            p, q = gen_primes(r, n)
            return p, q, prod_exp(p, q, to_bits(m))

        def cfactor(primes, x):
            res = []
            if x == 1: return None
            for p in primes:
                if x % p == 0:
                    res.append(p)
                    x //= p
            return res if x == 1 else None

        m = b"I have a sweet flag for you: CTF{YkDOLIStjpjP5Am1SXDt5d2r9es3b5KZP47v8rXF}"
        #p, q, x = encode(131, 7*len(m), m)

        q = 0xD2F8711CB5502C512ACEA59BE181A8FCF12F183B540D9A6998BF66370F9538F7E39FC507545DAD9AA2E71D3313F0B4408695A0A2C03A790662A9BD01650533C584C90779B73604FB8157F0AB7C9A82E724700E5937D9FF5FCF1EE3BE1EDD7E07B4C0F035A58CC2B9DB8B79F176F595C1B0E90B7957309B96106A50A01B78171599B41C8744BCB1C0E6A24F60AE8946D37F4D4BD8CF286A336E1022996B3BA3918E4D808627D0315BFE291AEB884CBE98BB620DAA735B0467F3287D158231D
        X = 0x947062E712C031ADD0B60416D3B87D54B50C1EFBC8DBB87346F960B242AF3DF6DD47406FEC98053A967D28FE91B130FF0FE93689122931F0BA6E73A3E9E6C873B8E2344A459244D1295E99A241E59E1EEA796E9738E6B1EDEED3D91AE6747E8ECA634C030B90B02BAF8AE0088058F6994C7CAC232835AC72D8B23A96F10EF03D74F82C49D4513423DAC298698094B5C631B9C7C62850C498330E9D112BB9CAA574AEE6B0E5E66D5B234B23C755AC1719B4B68133E680A7BCF48B4CFD0924D
        p = Primes()[:7*len(m)]
        b = to_bits(m)
        Y = prod_exp(p, q, b)
        E = X * pow(Y, -1, q) % q
        C = continued_fraction(E/q)
        for c in C.convergents():
            k = c.denominator() # D
            l = k*E % q
            if k != 0 and l != 0:
                F = cfactor(p, k)
                Fp = cfactor(p, l)
                if F is not None and Fp is not None:
                    mask = [0] * len(p)
                    for i in range(len(p)):
                        if p[i] in F+Fp:
                            mask[i] = 1
                    x = bitxor(b, mask)
                    print(from_bits(x))
