ISITDTU Quals 2022
******************

Glitch in the matrix
====================

Đề bài các bạn có thể xem ở :download:`chall.py <glitch_in_the_matrix/chall.py>`.

Bài này mình re-writeup từ hint của của một idol. :))))

Thử thách ở đây là cần đoán một token hex độ dài :math:`64` bit với secret key là ``SECRET_BASIS``.

Gọi token hex có :math:`64` bit là :math:`(m_1, m_2, \cdots, m_{64})`. Với ``SECRET_BASIS`` là ma trận trên :math:`\mathbb{F}_2` kích thước :math:`128 \times 128`, ta thực hiện encrypt như sau:

* random một chuỗi :math:`64` bit `C`;
* nếu :math:`m_i = 1` thì thực hiện ``f(SECRET_BASIS[:64], C)``, nếu là :math:`0` thì ``f(SECRET_BASIS[64:], C)``;
* nghĩa là secret key được chia thành hai nửa trái phải theo chiều dọc.

Hàm :math:`f` thực hiện như sau:

* Với ``C`` là một chuỗi :math:`64` bit, đặt :math:`C = (c_1, c_2, \cdots, c_{64})`;
* Nếu :math:`c_i = 1` thì dòng :math:`i` được xor vào kết quả;
* Hay viết dưới dạng vector sẽ là 

.. math:: c_1 \cdot (m_{1,1}, m_{1,2}, \cdots m_{1,128}) + \cdots + c_{64} \cdot (m_{64,1}, m_{64,2}, \cdots, m_{64,128}).

Ý tưởng để làm bài này là mình lấy thật nhiều ciphertext tương ứng với một plaintext (password). Do từng bit của plaintext được mã hóa riêng nhau nên mình sẽ tìm mối liên hệ giữa hai block mã hóa để xem chúng có cùng thuộc nửa trái (hoặc nửa phải) của secret key hay không.

Vì :math:`64` bit plaintext được mã hóa thành :math:`64 \times 128` bit của ciphertext, mình chia mỗi ciphertext thành :math:`64` block. Giả sử mình lấy :math:`n` ciphertext, mỗi ciphertext cũng được chia thành :math:`64` block thì mình sẽ có 64 ma trận :math:`n \times 128`.

Nếu hai ma trận có chung base (cùng thuộc nửa trái hoặc nửa phải) thì hiệu của chúng sẽ có cùng rank với ma trận đầu. Do đó mình giả sử bit đầu là :math:`0`, vậy thì những block thứ :math:`2` tới :math:`64` (tương ứng bit thứ :math:`2` tới :math:`64`) nếu có cùng rank thì sẽ mang bit :math:`0`, không thì mang bit :math:`1`. Do đó mình cần lấy :math:`n` ciphertext đủ lớn để block đầu có rank là :math:`64` (max).

Lưu ý rằng do mình giả sử bit đầu là :math:`0`, nên nếu bit đầu của plaintext là :math:`1` thì sẽ không giải ra. Do đó xác suất cách làm này là :math:`1/2`.

Code giải của mình ở :download:`solve.py <glitch_in_the_matrix/solve.py>`.
