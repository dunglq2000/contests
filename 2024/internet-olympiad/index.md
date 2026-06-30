## Internet Olympiad 2024

### Vòng 2

#### Bài 2

##### Đề bài

Cho hai số tự nhiên $x, y$ sao cho

$$A = \dfrac{2y}{x(y-x)}, B = \dfrac{(y-x)(y+1)}{2y^2} \in \mathbb{Z}.$$

Tìm $x, y$.

##### Lời giải

Do $A, B \in \mathbb{Z}$ nên

$$A \cdot B = \dfrac{2y}{x(y-x)} \cdot \dfrac{(y-x)(y+1)}{2y^2} = \dfrac{y+1}{xy} \in \mathbb{Z}$$

Suy ra tồn tại $k \in \mathbb{Z}$ sao cho $y + 1 = kxy$, tương đương với $y(kx - 1) = 1$. Điều này chỉ xảy ra khi $y = 1, x = 2$ (có một nghiệm khác là $y = 1, x = 1$ nhưng sẽ không thỏa mẫu số của :math:`A`).

#### Bài 8

##### Đề bài

Cho $x, y$ là các số thực thỏa $x^2 + y^2 + xy = x + y$. Tìm giá trị lớn nhất của $x^2 + y^2$.

##### Lời giải

Thầy mình bảo đây là dạng bậc hai nên có thể biến đổi để thành phương trình ellipse. Ở đây mình giải theo cách của mình.

Ta có

$$
    x^2 + y^2 + xy = & x + y \\
    2x^2 + 2y^2 + 2xy = & 2x + 2y \\
    x^2 + y^2 = & -(x+y)^2 + 2(x+y) = -t^2 + 2t = f(t)
$$

Ta có $f'(t) = -2t + 2$, $f'(t) = 0 \Leftrightarrow t = 1$. 

Do đó $f(t)_{\max} = f(1) = 1$.

#### Bài 9

##### Đề bài

Xét đa thức $P(x) = x^4 - 4x^2 - x + 1$. Tính $\displaystyle{\sum_{i=1}^4 \dfrac{2x_i + 1}{(x_i^2 - 1)^2}}$ với $x_i$ là các nghiệm của $P(x)$.

##### Lời giải

Ta biến đổi

$$P(x) = x^4 - 4x^2 - x + 1 = (x^2-1)^2 - x(2x+1).$$

Do $x_i$ là nghiệm nên $P(x_i) = 0$, tương đương với $\dfrac{1}{x_i} = \dfrac{2x_i+1}{(x_i^2-1)^2}$.

Tổng trên tương đương với $\sum \dfrac{1}{x_i}$. Dùng Viete có thể tính ra.

#### Bài 10

##### Đề bài

Cho hàm số

.. math:: 
    f(x) = \frac{4x - 3}{(x+2)(x+2^2) \ldots (x+2^{2023})}


Gọi :math:`M` là đạo hàm của $f(x)$ tại $x_0 = 0$. Tính giá trị $2^{1013 \cdot 2023} \cdot M - 7 \cdot 2^{2023}$.

##### Lời giải

Đặt $f(x) = \dfrac{4x-3}{g(x)}$ thì 

$$f'(x) = \dfrac{4 g(x) - (4x - 3) g'(x)}{g^2(x)}.$$

Do

$$g(x) = \prod_{i=1}^{2023} (x + 2^i),$$

ta lấy log hai vế thì được

$$\ln g = \sum_{i=1}^{2023} \ln (x + 2^i)$$

Suy ra

$$\dfrac{g'}{g} = \sum_{i=1}^{2023} \dfrac{1}{x+2^i}$$

nên suy ra

$$g'(0) = g(0) \cdot \sum_{i=1}^{2023} \dfrac{1}{2^i}$$

Như vậy $f'(0) = \dfrac{4 - 3 \sum_{i=1}^{2023} \dfrac{1}{2^i}}{\prod_{i=1}^{2023} 2^i} = M$.

### Vòng siêu chung kết (Uzbekistan)

#### Bài 1

##### Đề bài

Một người đi bộ từ vị trí :math:`A` đến vị trí :math:`B` tại thời điểm :math:`T` với $0 < T < 12$. Cùng lúc đó có một người đi bộ khác từ :math:`B` đến :math:`A`. Hai người đi với cùng vận tốc và gặp nhau lúc :math:`12` giờ nhưng không dừng lại mà tiếp tục đi. Người đầu tiên tới :math:`B` lúc :math:`16` giờ và người thứ hai tới :math:`A` lúc :math:`21` giờ. Tìm thời điểm :math:`T`.

##### Lời giải

Kết quả là :math:`6`.

#### Bài 2

##### Đề bài

Tâm của :math:`6` đường tròn có cùng bán kính :math:`R` nằm trên cùng đường thẳng nằm ngang. Khoảng cách giữa các tâm bằng nhau và diện tích vùng giao nhau cũng bằng nhau và bằng :math:`8`.

Giả sử :math:`A` là điểm thấp nhất của đường tròn ngoài cùng bên trái và :math:`B` là điểm cao nhất của đường tròn ngoài cùng bên phải. Diện tích phần giới hạn bởi đường thẳng $AB$ và các đường tròn bằng $40$. Tìm bán kính :math:`R`.

##### Lời giải

Đáp án là $R = \dfrac{2 \sqrt{5}}{\sqrt{\pi}}$.

#### Bài 3

Chả hiểu đề nói gì @@@

#### Bài 4

##### Đề bài

Đặt

$$f(x) = a_n x^n + a_{n-1} x^{n-1} + \ldots + a_0$$

là đa thức có bậc lẻ với hệ số nguyên. Xét tập hợp các điểm của nó trên đồ thị với tọa độ là các số nguyên:

$$M = \{ P_i = (b_i, f(b_i)) : b_i \in \mathbb{Z} \}.$$

Chứng minh rằng tập hợp tất cả các cặp $(P_i, P_j) \in M$ với $i \neq j$ thì khoảng cách giữa hai điểm đó là số nguyên và hữu hạn.

##### Giải

Đặt $d(P, Q) \in \mathbb{Z}$ là khoảng cách giữa hai điểm $P(a, f(a))$ và $Q(b, f(b))$. Khi đó

$$d^2 = (b - a)^2 + (f(b) - f(a))^2$$

là số chính phương. Tuy nhiên

$$f(b) - f(a) = a_n(b^n - a^n) + a_{n-1} (b^{n-1} - a^{n-1}) + \ldots + a_1 (b - a) = (b - a) \cdot U.$$

Do đó

$$d^2 = (b-a)^2 + ((b-a) \cdot U)^2 = (b-a)^2(1 + U^2)$$

và $1 + U^2$ cũng là số chính phương. Điều này xảy ra khi và chỉ khi $U^2 = 0$, hay $f(b) = f(a)$. Đối với đa thức bậc lẻ thì luôn tồn tại số :math:`N` sao cho với $x \in (-\infty, N) \cup (N, +\infty)$ thì đa thức $f(x)$ tăng nghiêm ngặt (khi $a_n > 0$) và giảm nghiêm ngặt (khi $a_n < 0$). Do đó trên khoảng $(-N, N)$ số lượng cặp $(P, Q)$ mà $f(b) = f(a)$ là hữu hạn.

#### Bài 5

##### Đề bài

Cho ma trận vuông :math:`A` bậc $2025$ sao cho tổng mọi phần tử của $(E + A)^{-1}$, với :math:`E` là ma trận đơn vị, bằng :math:`10`. Tính tổng mọi phần tử của ma trận $(E + A^{-1})^{-1}$.

##### Lời giải

Đáp án là $2015$.

#### Bài 6

##### Đề bài

Hàm $f(x)$ liên tục trên $[0, +\infty)$. Biết rằng mọi giá trị của hàm đó nằm trong đoạn $[0, 1]$ và với mọi $x, y$ không âm đều thỏa $f(x + y) \leqslant f(x) f(y)$. Chứng minh rằng với mọi :math:`x` không âm ta đều có $\int\limits_{0}^x f(u) \, du \geqslant x \sqrt{f(2x)}$.

##### Giải

Vì $f(x) \in [0, 1]$, từ điều kiện $f(x + y) \leqslant f(x) f(y)$ suy ra $f(x + y) \leqslant f(x)$. Như vậy $f(x)$ không tăng.

Do đó

$$\left(\int\limits_0^x f(u)\,du \right)^2 = \int\limits_0^x\int\limits_0^x f(u) f(t)\,du \ dt \geqslant \int\limits_0^x dt \int\limits_0^x f(u + t) \, du = \int\limits_0^x dt \int\limits_t^{x+t} f(s) \, ds.$$

Vì với mọi $t \in [0, x]$ và $s \in [t, x+t]$ ta có $s \leqslant 2x$ nên $f(s) \leqslant f(2x)$ và

$$\int\limits_0^x dt \int\limits_t^{x+t} f(s) \, ds \geqslant f(2x) \int\limits_0^xdt \int\limits_t^{x+t} ds = f(2x) \cdot x^2.$$

Kết quả là $\int\limits_0^x f(u) \, du \geqslant x \sqrt{f(2x)}$.

#### Bài 7

##### Đề bài

Đặt :math:`A` là tập hợp gồm các cặp $(x, y)$ sao cho $x \in [0, 1)$ và $y \in [0, 1)$, nghĩa là

$$A = \{ (x, y) : x \in [0, 1), y \in [0, 1) \}$$

Trên tập :math:`A` xét hàm số

$$Q(x, y) = \sum_{\frac{1}{2} \leqslant \frac{m}{n} \leqslant 2, n, m \in \mathbb{N}} x^m y^n$$

với $n, m$ là các số nguyên dương. Tìm giá trị của giới hạn

$$\lim_{\substack{(x, y) \to (1, 1) \\ (x, y) \in A}} \lvert (1 - xy^2) \cdot (1 - x^2y) \cdot Q(x, y) \rvert.$$

##### Lời giải

Đáp án là :math:`3`.

#### Bài 8

##### Đề bài

Chứng minh rằng tổng

$$\frac{1}{4} + \frac{1}{7} + \ldots + \frac{1}{3n + 1}$$

không phải số nguyên với mọi số tự nhiên :math:`n`.

#### Bài 9

##### Đề bài

Đặt $x_1, x_2, \ldots, x_n$ với $n > 1$ là các số thuộc $[0, 1]$ và khác nhau đôi một.

Đặt $A_k$ là trung bình của tất cả tích gồm :math:`k` phần tử khác nhau.

Chứng minh rằng dãy $A_k$ không tăng.

#### Bài 10

##### Đề bài

Trên mặt phẳng cho các điểm $A_1, A_2, \ldots, A_n$ không nằm cùng một đường thẳng. Với mọi $1 \leqslant i, j, k \leqslant n$ và $i \neq j$, ta định nghĩa $\delta_{ijk}$ bằng :math:`1` nếu điểm $A_k$ nằm trên đường thẳng $A_i A_j$, bằng :math:`0` nếu ngược lại.

Chứng minh rằng hệ vector

$$\vec{v}_{ij} = (\delta_{ij1}, \delta_{ij2}, \ldots, \delta_{ijn}), \, 1 \leqslant i < j \leqslant n$$

sinh ra không gian $\mathbb{R}^n$.