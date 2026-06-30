NSUCRYPTO 2025
**************

Crypto growth
=============

Đề bài
------

Một nhà mật mã lớn tuổi, nhiều kinh nghiệm nói với sinh viên rằng: "Em sẽ không thể sống thiếu hàm này. Thầy tin rằng em sẽ nhận ra nó ở mọi nơi".

Dãy số:

.. math:: 1, 1, ?, 2, ?, 2, 6, 4, ?, 4.

Giải
----

Đáp án là phi hàm Euler :math:`\varphi(n)`. Hàm Euler đếm số lượng phần tử từ :math:`1` tới :math:`n` mà nguyên tố cùng nhau với :math:`n`. Ở đây :math:`\varphi(1) = 1`, :math:`\varphi(2) = 1`, :math:`\varphi(3) = 2`, :math:`\varphi(4) = 2`, :math:`\varphi(5) = 4`, :math:`\varphi(6) = 2`, :math:`\varphi(7) = 6`, :math:`\varphi(8) = 4`, :math:`\varphi(9) = 6`, :math:`\varphi(10) = 4`.

Như vậy giá trị ở các dấu chấm hỏi lần lượt là :math:`2`, :math:`4`, :math:`6`.

Key for the 2025
================

Đề bài
------

Khóa bí mật được xác định bởi các số nguyên dương :math:`a`, :math:`b`, :math:`c`, :math:`d`, :math:`e`, :math:`f`, :math:`g`, :math:`h`, :math:`i` thỏa mãn

.. math:: a^3 + b^3 + c^3 + d^3 + e^3 + f^3 + g^3 + h^3 + i^3 = 2025^{2026}.

Hãy tìm lại khóa.

A Greek cipher
==============

Đề bài
------

Để mã hóa một thông điệp gồm ba kí tự ta làm như sau. Ta gắn mỗi kí tự với số tương ứng trong bảng và nhận được :math:`p_1`, :math:`p_2`, :math:`p_3`.

+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`0`   | :math:`1`   | :math:`2`   | :math:`3`   | :math:`4`   | :math:`5`   | :math:`6`   | :math:`7`   | :math:`8`   |
+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| SPACE       | A           | B           | C           | D           | E           | F           | G           | H           |
+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`9`   | :math:`10`  | :math:`11`  | :math:`12`  | :math:`13`  | :math:`14`  | :math:`15`  | :math:`16`  | :math:`17`  |
+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| I           | J           | K           | L           | M           | N           | O           | P           | Q           |
+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`18`  | :math:`19`  | :math:`20`  | :math:`21`  | :math:`22`  | :math:`23`  | :math:`24`  | :math:`25`  | :math:`26`  |
+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| R           | S           | T           | U           | V           | W           | X           | Y           | Z           |
+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+

Tiếp theo ta chọn một số tự nhiên bí mật là :math:`\delta` và tính :math:`p_4 = p_1 + p_2 + p_3 + \delta`.

Sau đó ta chọn số tự nhiên bí mật khác là :math:`\alpha` và tính với :math:`i = 1, 2, 3, 4`

.. math:: 

    c_i & = p_i + 2p_{i+1} + (-1)^{\frac{i+1}{2}} \cdot \delta \bmod 27, \ \text{nếu} \ i \ \text{lẻ}, \\
    c_i & = p_{i-1} + p_i + (-1)^{\frac{i}{2}} \cdot \alpha \bmod 27, \ \text{nếu} \ i \ \text{chẵn}.

Kết quả là ta nhận được "WGAD". Hãy khôi phục thông điệp gốc.

Hint từ hình ảnh: :math:`\alpha \delta`, :math:`700`.

Toy cipher cryptanalyst
=======================

Đề bài
------

Bob viết một chương trình C++ cho một phiên bản thu nhỏ của các hệ mã. Đoạn code như sau

.. code-block:: cpp

    uint32_t foo(uint32_t x) {
      uint32_t y = 0x20000000;
      for (uint32_t i = 0x40000000; i != 0x80000000; ++i) {
        if (x == y)
          return i ;
        y = y + ((i << 2) >> 1) + (i >> 30) + 1;
        y = ((y << 1) >> 1) + (y >> 31);
      }
      return 0x80000000;
    }

Mục đích của hàm này là gì? Có điểm nào cần sửa ở đây không?
