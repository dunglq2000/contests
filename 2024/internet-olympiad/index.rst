Internet Olympiad 2024
**********************

Vòng 2
=======

Bài 2
--------------

Đề bài
^^^^^^^^^^^

Cho hai số tự nhiên :math:`x, y` sao cho

.. math::
   A = \dfrac{2y}{x(y-x)}, B = \dfrac{(y-x)(y+1)}{2y^2} \in \mathbb{Z}.

Tìm :math:`x, y`.

Lời giải
^^^^^^^^^^^

Do :math:`A, B \in \mathbb{Z}` nên

.. math::
   A \cdot B = \dfrac{2y}{x(y-x)} \cdot \dfrac{(y-x)(y+1)}{2y^2} = \dfrac{y+1}{xy} \in \mathbb{Z}

Suy ra tồn tại :math:`k \in \mathbb{Z}` sao cho :math:`y + 1 = kxy`, tương đương với :math:`y(kx - 1) = 1`. Điều này chỉ xảy ra khi :math:`y = 1, x = 2` (có một nghiệm khác là :math:`y = 1, x = 1` nhưng sẽ không thỏa mẫu số của :math:`A`).

Bài 8
--------------

Đề bài
^^^^^^^^^^^

Cho :math:`x, y` là các số thực thỏa :math:`x^2 + y^2 + xy = x + y`. Tìm giá trị lớn nhất của :math:`x^2 + y^2`.

Lời giải
^^^^^^^^^^^

Thầy mình bảo đây là dạng bậc hai nên có thể biến đổi để thành phương trình ellipse. Ở đây mình giải theo cách của mình.

Ta có

.. math:: 

   x^2 + y^2 + xy &= x + y \\
   2x^2 + 2y^2 + 2xy &= 2x + 2y \\
   x^2 + y^2 &= -(x+y)^2 + 2(x+y) = -t^2 + 2t = f(t)

Ta có :math:`f'(t) = -2t + 2`, :math:`f'(t) = 0 \Leftrightarrow t = 1`. 

Do đó :math:`f(t)_{\max} = f(1) = 1`.

Bài 9
--------------

Đề bài
^^^^^^^^^^^

Xét đa thức :math:`P(x) = x^4 - 4x^2 - x + 1`. Tính :math:`\displaystyle{\sum_{i=1}^4 \dfrac{2x_i + 1}{(x_i^2 - 1)^2}}` với :math:`x_i` là các nghiệm của :math:`P(x)`.

Lời giải
^^^^^^^^^^^

Ta biến đổi

.. math:: 

   P(x) = x^4 - 4x^2 - x + 1 = (x^2-1)^2 - x(2x+1).

Do :math:`x_i` là nghiệm nên :math:`P(x_i) = 0`, tương đương với :math:`\dfrac{1}{x_i} = \dfrac{2x_i+1}{(x_i^2-1)^2}`.

Tổng trên tương đương với :math:`\sum \dfrac{1}{x_i}`. Dùng Viete có thể tính ra.

Bài 10
--------------

Đề bài
^^^^^^^^^^^

Cho hàm số

.. math:: 

   f(x) = \frac{4x - 3}{(x+2)(x+2^2) \ldots (x+2^{2023})}

Gọi :math:`M` là đạo hàm của :math:`f(x)` tại :math:`x_0 = 0`. Tính giá trị :math:`2^{1013 \cdot 2023} \cdot M - 7 \cdot 2^{2023}`.

Lời giải
^^^^^^^^^^^

Đặt :math:`f(x) = \dfrac{4x-3}{g(x)}` thì 

.. math:: 

   f'(x) = \dfrac{4 g(x) - (4x - 3) g'(x)}{g^2(x)}.

Do

.. math::

   g(x) = \prod_{i=1}^{2023} (x + 2^i),

ta lấy log hai vế thì được

.. math:: 

   \ln g = \sum_{i=1}^{2023} \ln (x + 2^i)

Suy ra

.. math::

   \dfrac{g'}{g} = \sum_{i=1}^{2023} \dfrac{1}{x+2^i}

nên suy ra

.. math::

   g'(0) = g(0) \cdot \sum_{i=1}^{2023} \dfrac{1}{2^i}

Như vậy :math:`f'(0) = \dfrac{4 - 3 \sum_{i=1}^{2023} \dfrac{1}{2^i}}{\prod_{i=1}^{2023} 2^i} = M`.

Vòng siêu chung kết (Uzbekistan)
================================

Bài 1
--------------

Đề bài
^^^^^^^^^^^

Một người đi bộ từ vị trí :math:`A` đến vị trí :math:`B` tại thời điểm :math:`T` với :math:`0 < T < 12`. Cùng lúc đó có một người đi bộ khác từ :math:`B` đến :math:`A`. Hai người đi với cùng vận tốc và gặp nhau lúc :math:`12` giờ nhưng không dừng lại mà tiếp tục đi. Người đầu tiên tới :math:`B` lúc :math:`16` giờ và người thứ hai tới :math:`A` lúc :math:`21` giờ. Tìm thời điểm :math:`T`.

Lời giải
^^^^^^^^^^^

Kết quả là :math:`6`.

Bài 2
--------------

Đề bài
^^^^^^^^^^^

Tâm của :math:`6` đường tròn có cùng bán kính :math:`R` nằm trên cùng đường thẳng nằm ngang. Khoảng cách giữa các tâm bằng nhau và diện tích vùng giao nhau cũng bằng nhau và bằng :math:`8`.

Giả sử :math:`A` là điểm thấp nhất của đường tròn ngoài cùng bên trái và :math:`B` là điểm cao nhất của đường tròn ngoài cùng bên phải. Diện tích phần giới hạn bởi đường thẳng :math:`AB` và các đường tròn bằng :math:`40`. Tìm bán kính :math:`R`.

Lời giải
^^^^^^^^^^^

Đáp án là :math:`R = \dfrac{2 \sqrt{5}}{\sqrt{\pi}}`.

Bài 3
--------------

Chả hiểu đề nói gì @@@

Bài 4
--------------

Đề bài
^^^^^^^^^^^

Đặt

.. math:: f(x) = a_n x^n + a_{n-1} x^{n-1} + \ldots + a_0

là đa thức có bậc lẻ với hệ số nguyên. Xét tập hợp các điểm của nó trên đồ thị với tọa độ là các số nguyên:

.. math:: M = \{ P_i = (b_i, f(b_i)) : b_i \in \mathbb{Z} \}.

Chứng minh rằng tập hợp tất cả các cặp :math:`(P_i, P_j) \in M` với :math:`i \neq j` thì khoảng cách giữa hai điểm đó là số nguyên và hữu hạn.

Giải
^^^^^^^^^^^

Đặt :math:`d(P, Q) \in \mathbb{Z}` là khoảng cách giữa hai điểm :math:`P(a, f(a))` và :math:`Q(b, f(b))`. Khi đó

.. math:: d^2 = (b - a)^2 + (f(b) - f(a))^2

là số chính phương. Tuy nhiên

.. math:: f(b) - f(a) = a_n(b^n - a^n) + a_{n-1} (b^{n-1} - a^{n-1}) + \ldots + a_1 (b - a) = (b - a) \cdot U.

Do đó

.. math:: d^2 = (b-a)^2 + ((b-a) \cdot U)^2 = (b-a)^2(1 + U^2)

và :math:`1 + U^2` cũng là số chính phương. Điều này xảy ra khi và chỉ khi :math:`U^2 = 0`, hay :math:`f(b) = f(a)`. Đối với đa thức bậc lẻ thì luôn tồn tại số :math:`N` sao cho với :math:`x \in (-\infty, N) \cup (N, +\infty)` thì đa thức :math:`f(x)` tăng nghiêm ngặt (khi :math:`a_n > 0`) và giảm nghiêm ngặt (khi :math:`a_n < 0`). Do đó trên khoảng :math:`(-N, N)` số lượng cặp :math:`(P, Q)` mà :math:`f(b) = f(a)` là hữu hạn.

Bài 5
--------------

Đề bài
^^^^^^^^^^^

Cho ma trận vuông :math:`A` bậc :math:`2025` sao cho tổng mọi phần tử của :math:`(E + A)^{-1}`, với :math:`E` là ma trận đơn vị, bằng :math:`10`. Tính tổng mọi phần tử của ma trận :math:`(E + A^{-1})^{-1}`.

Lời giải
^^^^^^^^^^^

Đáp án là :math:`2015`.

Bài 6
--------------

Đề bài
^^^^^^^^^^^

Hàm :math:`f(x)` liên tục trên :math:`[0, +\infty)`. Biết rằng mọi giá trị của hàm đó nằm trong đoạn :math:`[0, 1]` và với mọi :math:`x, y` không âm đều thỏa :math:`f(x + y) \leqslant f(x) f(y)`. Chứng minh rằng với mọi :math:`x` không âm ta đều có :math:`\int\limits_{0}^x f(u) \, du \geqslant x \sqrt{f(2x)}`.

Giải
^^^^^^^^^^^

Vì :math:`f(x) \in [0, 1]`, từ điều kiện :math:`f(x + y) \leqslant f(x) f(y)` suy ra :math:`f(x + y) \leqslant f(x)`. Như vậy :math:`f(x)` không tăng.

Do đó

.. math:: \left(\int\limits_0^x f(u)\,du \right)^2 = \int\limits_0^x\int\limits_0^x f(u) f(t)\,du \ dt \geqslant \int\limits_0^x dt \int\limits_0^x f(u + t) \, du = \int\limits_0^x dt \int\limits_t^{x+t} f(s) \, ds.

Vì với mọi :math:`t \in [0, x]` và :math:`s \in [t, x+t]` ta có :math:`s \leqslant 2x` nên :math:`f(s) \leqslant f(2x)` và

.. math:: \int\limits_0^x dt \int\limits_t^{x+t} f(s) \, ds \geqslant f(2x) \int\limits_0^xdt \int\limits_t^{x+t} ds = f(2x) \cdot x^2.

Kết quả là :math:`\int\limits_0^x f(u) \, du \geqslant x \sqrt{f(2x)}`.

Bài 7
--------------

Đề bài
^^^^^^^^^^^

Đặt :math:`A` là tập hợp gồm các cặp :math:`(x, y)` sao cho :math:`x \in [0, 1)` và :math:`y \in [0, 1)`, nghĩa là

.. math::
   A = \{ (x, y) : x \in [0, 1), y \in [0, 1) \}

Trên tập :math:`A` xét hàm số

.. math:: Q(x, y) = \sum_{\frac{1}{2} \leqslant \frac{m}{n} \leqslant 2, n, m \in \mathbb{N}} x^m y^n

với :math:`n, m` là các số nguyên dương. Tìm giá trị của giới hạn

.. math:: \lim_{\substack{(x, y) \to (1, 1) \\ (x, y) \in A}} \lvert (1 - xy^2) \cdot (1 - x^2y) \cdot Q(x, y) \rvert.

Lời giải
^^^^^^^^^^^

Đáp án là :math:`3`.

Bài 8
--------------

Đề bài
^^^^^^^^^^^

Chứng minh rằng tổng

.. math:: \frac{1}{4} + \frac{1}{7} + \ldots + \frac{1}{3n + 1}

không phải số nguyên với mọi số tự nhiên :math:`n`.

Bài 9
--------------

Đề bài
^^^^^^^^^^^

Đặt :math:`x_1, x_2, \ldots, x_n` với :math:`n > 1` là các số thuộc :math:`[0, 1]` và khác nhau đôi một.

Đặt :math:`A_k` là trung bình của tất cả tích gồm :math:`k` phần tử khác nhau.

Chứng minh rằng dãy :math:`A_k` không tăng.

Bài 10
--------------

Đề bài
^^^^^^^^^^^

Trên mặt phẳng cho các điểm :math:`A_1, A_2, \ldots, A_n` không nằm cùng một đường thẳng. Với mọi :math:`1 \leqslant i, j, k \leqslant n` và :math:`i \neq j`, ta định nghĩa :math:`\delta_{ijk}` bằng :math:`1` nếu điểm :math:`A_k` nằm trên đường thẳng :math:`A_i A_j`, bằng :math:`0` nếu ngược lại.

Chứng minh rằng hệ vector

.. math:: \vec{v}_{ij} = (\delta_{ij1}, \delta_{ij2}, \ldots, \delta_{ijn}), \, 1 \leqslant i < j \leqslant n

sinh ra không gian :math:`\mathbb{R}^n`.
