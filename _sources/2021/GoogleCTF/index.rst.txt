Google CTF 2021
***************

Pythia
======

Đề bài ở file :download:`service.py <Pythia/service.py>`.

Ở bài này random ba password từ các ký tự in thường, mỗi password có độ dài là :math:`3`.

Nhiệm vụ của chúng ta là tìm ba password này và ghép lại (theo thứ tự) để lấy flag.

Trong :math:`150` queries, chúng ta có thể làm một trong ba việc:

* chọn password để decrypt;
* thử password để lấy flag;
* gửi nonce và ciphertext để kiểm tra xem có thể decrypt bằng AES-GCM không.

Chúng ta sẽ cần hiểu cách AES-GCM hoạt động.

Counter mode (CTR)
------------------

Chúng ta bắt đầu với CTR trước.

Ở đây một bộ đếm (counter) được sử dụng. Chúng ta có thể dùng bộ đếm cơ bản :math:`0`, :math:`1`, :math:`2`, ... hoặc các bộ đếm phức tạp hơn. Mô hình mã hóa với khóa :math:`K` là :math:`C_i = P_i \oplus \mathsf{Enc}_K (\text{counter}_i)`. Việc dùng bộ đếm nào cũng không quá quan trọng, qua thuật toán AES thì đều khó cả.

Trong AES-GCM, CTR đóng vai trò mã hóa.

Authenticated encryption (AEAD)
-------------------------------

Một vấn đề quan trọng đối với mã hóa đối xứng (stream cipher và block cipher) là làm sao để kiểm tra thông tin có bị sửa đổi không?

Khi đó chúng ta thêm một trường dữ liệu gọi là associated data. Do đó mô hình mã hóa được gọi là authenticated encryption with associated data (AEAD). Chúng ta cần định nghĩa sau:

    Message authentication code (MAC) là một hàm bất kì, kí hiệu là :math:`\text{MAC}_K (N, C, A^d)`. Sử dụng secret key :math:`K` trao đổi bởi Alice và Bob, hàm lấy nonce :math:`N`, ciphertext :math:`C` và associated data :math:`A^d` nào đó để tạo ra tag :math:`T`. Dựa vào tag :math:`T` này Bob kiểm tra tính hợp lệ của ciphertext :math:`C` do Alice gửi tới.

Chúng ta có thể hiểu nonce là một giá trị khởi đầu nào đó.

Ví dụ, giả sử Alice muốn gửi cho Bob plaintext :math:`P`. Alice chọn nonce :math:`N` và encrypt plaintext với :math:`C = E_K (N, P)`. Sau đó Alice tạo tag :math:`T = \text{MAC}_K (N, C, A^d)` và gửi message :math:`M = \{N, C, T\}` tới cho Bob.

Giả sử Bob nhận được message :math:`M' = \{N', C', T'\}`. Bob tính :math:`\tau = \text{MAC}_K (N', C', A^d)` và so sánh với :math:`T'`. Nếu :math:`\tau = T'` thì ciphertext không bị sai lệch, từ đó Bob có thể decrypt :math:`P' = D_K(N', C')`.

Galois/Counter mode (GCM)
-------------------------

Ở GCM:

* CTR được sử dụng để mã hóa các khối plaintext :math:`P_0`, :math:`P_1`, ..., :math:`P_{n-1}` thành các khối ciphertext :math:`C_0`, :math:`C_1`, ..., :math:`C_{n-1}`;
* các khối ciphertext kết hợp với associated data để tạo ra tag. Tất cả việc tính toán qua hàm :math:`\text{mult}_H` hay :math:`C_i \oplus \text{mult}_H` được thực hiện trên :math:`\mathbb{F}_{2^{128}}` với đa thức tối giản là :math:`f(x) = x^{128} + x^7 + x^2 + x + 1`. Lý do của việc này là mỗi block của AES :math:`16` byte, tương đương :math:`128` bit, nên ta có thể chuyển đổi từ khối :math:`16` bytes thành đa thức thuộc :math:`\mathbb{F}_{2^{128}}`.

Giả sử mình có ciphertext :math:`C` gồm :math:`n` block, kí hiệu là

.. math:: C = C_0 \Vert C_1 \Vert C_2 \Vert \cdots \Vert C_{n-1}.

Đối với bài CTF này thì associated data không được dùng nên mình sẽ bỏ qua.

Vậy :math:`H` trong chỗ :math:`\text{mult}_H` là gì? Ở đây :math:`H = \text{AES}_K (0^{128})`, nghĩa là encrypt một dãy gồm :math:`128` bits :math:`0`.

Quá trình tính tag diễn ra như sau.

Với lần :math:`\text{mult}_H` đầu, do không có associated data nên giá trị khởi tạo là :math:`0^{128}`.

Với lần :math:`\text{mult}_H` thứ hai, :math:`(0^{128} \oplus C_0) \cdot H = C_0 H`.

Với lần :math:`\text{mult}_H` thứ ba, :math:`(C_0 H \oplus C_1) \cdot H = C_0 H^2 \oplus C_1 H`.

Cứ tiếp tục như vậy nhưng để ý hai lần :math:`\text{mult}_H` cuối cùng.

Độ dài toàn bộ associated data tính theo bit được biểu diễn bởi số nguyên :math:`\text{len}(A)` độ dài :math:`64` bits. Tương tự, độ dài toàn bộ ciphertext tính theo bit được biểu diễn bởi số nguyên :math:`64` bits là :math:`\text{len}(C)`. Vì ở đây không có associated data nên :math:`\text{len}(A) = 0` và :math:`\text{len(C)} = 128 \cdot n` với :math:`n` là số lượng khối và mỗi khối có :math:`128` bits. Như vậy chúng ta có :math:`128` bits kết quả cho :math:`\text{len}(A) \Vert \text{len}(C)` là :math:`0^{64} \Vert (128 \cdot n)`.

Với lần kế cuối ta sẽ có

.. math:: C_0 H^{n+1} \oplus C_1 H^{n} \oplus \cdots \oplus L H
    
với :math:`L = 0^{64} \Vert (128 \cdot n)`.

Với lần cuối ta cộng thêm encrypt của :math:`\text{counter}_0` nữa là xong.

Vậy kết quả cuối cùng của toàn bộ quá trình là tag

.. math:: T = C_0 H^{n+1} + C_1 H^{n} + \cdots + C_{n-1} H^2 + LH + \text{AES}_K (J_0).

Theo cách chọn nonce của AES-GCM thì nonce có độ dài :math:`12` bytes (:math:`96` bits) và 

.. math:: J_0 = IV \Vert 0^{31} \Vert 1.

trong đó :math:`IV` là nonce.

Quay lại bài toán
-----------------

Để giải bài này mình cần làm như sau:

* cố định :math:`IV` và :math:`T`;
* mình chia tập hợp khóa thành hai nửa trái phải (tìm nhị phân) và kiểm tra xem key (trong bài là password) nằm ở nửa nào cho tới khi không gian key chỉ còn 1.

Tới đây, mục đích của mình là tìm các ciphertext :math:`C_0`, :math:`C_1`, ..., :math:`C_{n-1}` sao cho với tất cả key trong một nửa trái đều cho ra cùng một tag.

Khi mình gửi ciphertext và tag này lên server, nếu server trả về ``Decryption successful`` nghĩa là key cần tìm nằm trong nửa trái, nếu fail nghĩa là key nằm ở nửa phải.

Để tìm được các ciphertext như vậy mình sử dụng nội suy Lagrange (Lagrange interpolation).

Mình thấy rằng

.. math:: T = C_0 H^{n+1} + C_1 H^{n} + \cdots + C_{n-1} H^2 + LH + \text{AES}_K (J_0).

Tương đương với 

.. math:: C_0 H^{n-1} + C_1 H^{n-2} + \cdots + C_{n-1} = (LH + \text{AES}_K (J_0) + T) \cdot H^{-2}.

Với mỗi :math:`K_i` thuộc nửa trái mình có :math:`H_i = \text{AES}_{K_i}(0^{128})` và :math:`\text{AES}_{K_i} (J_0)` tương ứng.

Đặt :math:`f(x) = C_0 x^{n-1} + C_1 x^{n-2} + \cdots + C_{n-1}`. Đa thức này thỏa mãn với mọi key :math:`K_i` thuộc nửa trái thì

.. math:: f(H_i) = (L H_i + \text{AES}_{K_i}(J_0) + T) \cdot H_i^{-2}.

Lưu ý rằng để tìm đa thức :math:`f(x)` bậc :math:`m` thì cần :math:`m+1` cặp :math:`(x_i, f(x_i))`. Do đó ở đây ta chọn :math:`n = \mathrm{len}(keys)` với :math:`keys` là tập chứa tất cả key của nửa trái.

Từ đó với :math:`n` key mình sẽ tìm được :math:`f(x)` (vì :math:`f(x)` có bậc :math:`n-1`).

Hàm encrypt một block AES. Hàm chuyển đối từ block :math:`16` byte sang đa thức thuộc :math:`\mathbb{F}_{2^{128}}` và ngược lại

.. code-block:: python

    def aes_ecb(key, plaintext):
        return AES.new(key, AES.MODE_ECB).encrypt(plaintext)

    def byte_to_pol(block):
        n = int.from_bytes(block, 'big')
        nn = list(map(int, bin(n)[2:].zfill(128)))
        pol = sum(j*x**i for i, j in enumerate(nn))
        return F(pol)

    def pol_to_byte(element):
        coeff = element.polynomial().coefficients(sparse=False)
        coeff = coeff + [0] * (128 - len(coeff))
        num = int(''.join(list(map(str, coeff))), 2)
        return int.to_bytes(num, 16, 'big')

Hàm attack tìm ciphertext với danh sách key, nonce và tag

.. code-block:: python

    def find_poly(keys, nonce, tag):
        points = []
        L = byte_to_pol(b'\x00' * 8 + int.to_bytes(128 * len(keys), 8, 'big'))
        T = byte_to_pol(tag)
        N = nonce + b'\x00' * 3 + b'\x01'

        for key in keys:
            Hi = byte_to_pol(aes_ecb(key, bytes(16)))
            Bi = byte_to_pol(aes_ecb(key, N))
            fHi = ((L * Hi) + Bi + T) * Hi**(-2)
            points.append((Hi, fHi))

        lagrange = R.lagrange_polynomial(points)

        coeff = lagrange.coefficients(sparse=False)[::-1]

        C = b"".join([pol_to_byte(c) for c in coeff])

        return C

**LƯU Ý 1**. Do không gian key ban đầu khá lớn (:math:`26^3`) nên việc tìm nhị phân ngay từ đầu khá là khoai (đa thức bậc :math:`26^3 / 2 = 8788`) nên mình chia ra các chunk key dài :math:`512` để tìm chunk nào chứa key (bản chất không thay đổi). Sau đó từ mỗi chunk mình mới dùng tìm nhị phân mò key.

**LƯU Ý 2**. Việc tính toán đa thức bậc :math:`512` cũng tốn thời gian nên chúng ta có thể tính trước rồi lưu lại trên dict hoặc hash table hoặc bất cứ thứ gì bạn nghĩ ra :v sau đó chúng ta mới giao tiếp với server.

Phần còn lại của code là attack thôi :) Source code mình để ở file :download:`solve.py <Pythia/service.py>`.
        
Với mỗi password mình dùng một query để chỉ định vị trí password (:math:`0`, :math:`1, :math:`2`), :math:`\lceil 26^3 / 512 \rceil = 35` query cho mỗi chunk, và :math:`\log_2(512) = 9` cho tìm nhị phân. Như vậy mình tốn :math:`(1 + 35 + 9) \cdot 3 = 135` query tổng cộng.

Bài viết tới đây là hết. Cám ơn các bạn đã đọc.
