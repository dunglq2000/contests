Sekai CTF 2022
**************

Mình làm 1 bài rồi đứng hình. :)))

FalLProoF
=========

Đề bài có thể tải ở file :download:`chall.py <FalLProoF/chall.py>`.

Ở bài này hệ mật mã tạo một public key từ một secret và một hàm hash.

Tạo public key
--------------

Để tạo public key cần truyền vào một chuỗi byte secret và hàm hash. Chúng ta đã biết hàm hash luôn cho output có độ dài cố định không liên quan độ dài input.

Mình gọi hàm hash là :math:`H(x)` cho input :math:`x` và độ dài (cố định) của hàm hash là :math:`L`. Mình kí hiệu việc thực hiện hash :math:`k` lần là :math:`H^{(k)}(x)`. Tức là :math:`H^{(k)}(x) = H(H(\cdots (H(x))\cdots))` (:math:`k` lần). Như vậy public key tương ứng với secret :math:`s` đầu vào là :math:`[H^{(1)}(s), H^{(2)}(s), \ldots, H^{(4*L)}(s)]`.

Prototype của hàm tạo public key dùng SHA512 nhưng ở chương trình chính dùng SHA256. Do đó :math:`L = 32` bytes và độ dài public key là :math:`64`.

Encode message
--------------

Bước vào hàm encrypt, message ban đầu sẽ được pad thành bội của :math:`32` (theo ``độ dài public key / 4 - độ dài hàm hash``) và được chia thành từng chunk :math:`32` bytes.

Happiness
--------------

Hàm ``happiness`` có một tính chất thú vị.

Giả sử mình có đầu vào là :math:`x=x_n 2^n + x_{n-1} 2^{n-1} + \ldots + x_1 2 + x_0`.

Khi đó:

.. math:: 

    & x \gg 1 = x_n 2^{n-1} + x_{n-1} 2^{n-2} + \cdots + x_2 2 + x_1 \\
    & x \gg 2 = x_n 2^{n-2} + x_{n-1} 2^{n-3} + \cdots + x_3 2 + x_2 \\
    & \cdots \\
    & x \gg n = x_n,

suy ra 

.. math:: 
    
    & x - (x \gg 1 + x \gg 2 + \cdots x \gg n) \\
    = & x_n 2^n + x_{n-1} 2^{n-1} + \cdots + x_1 2 + x_0 \\
    - & [x_n (2^{n-1} + 2^{n-2} + \cdots + 1) + x_{n-1} (2^{n-2} + \cdots + 1) + \cdots + x_1] \\
    = & x_n \left(2^n - \frac{2^n - 1}{2 - 1}\right) + x_{n-1} \left(2^{n-1} - \frac{2^{n-1} - 1}{2-1} \right) + \cdots + x_1 (2 - 2 + 1) + x_0 \\
    = & x_n + x_{n-1} + \cdots + x_1 + x_0.

Tóm lại hàm ``happiness`` tính tổng các bit của :math:`x`. :))))

Encrypt
--------------

Giả sử mình gọi chunk đầu là :math:`m`. Do :math:`m` có :math:`32` bytes, tương ứng :math:`256` bit, nên mình viết dưới dạng nhị phân là

.. math:: m = m_{255} 2^{255} + m_{254} 2^{254} + \cdots + m_1 2 + m_0,

:math:`m_i \in \{0, 1\}`.

Mình tiếp tục kí hiệu public key thứ :math:`j` là :math:`p_j`, :math:`j = \overline{0, 127}`. Và mình cũng viết dưới dạng nhị phân

.. math:: p_j = p_{j, 255} 2^{255} + p_{j, 254} 2^{254} + \cdots + p_{j, 1} 2 + p_{j, 0}.

Do đó phép AND cho kết quả 

.. math:: (m_{255} \cdot p_{j, 255}) \cdot 2^{255} + (m_{254} \cdot p_{j, 254}) \cdot 2^{254} + \cdots + (m_1 \cdot p_{j, 1}) \cdot 2 + (m_0 \cdot p_{j, 0}).

Qua hàm `happiness` chính là tổng

.. math:: m_{255} \cdot p_{j, 255} + m_{254} \cdot p_{j, 254} + \cdots + m_1 \cdot p_{j, 1} + m_0 \cdot p_{j,0}.

Do đó với 128 public key mình có thể viết dưới dạng ma trận như sau

.. math:: 
    
    \begin{pmatrix}
        p_{0, 255} & p_{0, 254} & \cdots & p_{0, 1} & p_{0, 0} \\
        p_{1, 255} & p_{1, 254} & \cdots & p_{1, 1} & p_{1, 0} \\
        \vdots & \vdots & \ddots & \vdots & \vdots \\ 
        p_{126, 255} & p_{126, 254} & \cdots & p_{126, 1} & p_{126, 0} \\ 
        p_{127, 255} & p_{127, 254} & \cdots & p_{127, 1} & p_{127, 0} 
    \end{pmatrix} \cdot \begin{pmatrix}
        m_{255} \\ m_{254} \\ \cdots \\ m_1 \\ m_0 \end{pmatrix} = \begin{pmatrix} c_{0} \\ c_{1} \\ \cdots \\ c_{126} \\ c_{127} \end{pmatrix}.

Vấn đề ở đây là ma trận :math:`P` không phải ma trận vuông. Do đó mình không thể tính nghịch đảo được :((

Để ý rằng :math:`m` luôn không đổi mỗi lần netcat nên mình chỉ cần request thêm một lần nữa và có thêm :math:`64` public key nữa. Khi đó ghép các public key đó nối tiếp xuống dưới ma trận :math:`P` cũng như ghép thêm các ciphertext mới xuống dưới cột :math:`c` thì mình đã đủ ma trận vuông để giải.

Code giải các bạn xem ở :download:`solve.py <FalLProoF/solve.py>`.

Cám ơn các bạn đã đọc writeup siêu dài cho một bài ... không dài lắm.
