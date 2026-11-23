Siberian Mathematical Contest 2023
**********************************

Đề và lời giải gốc (tiếng Nga) người đọc có thể tải ở :download:`solutions_SMC_2023.pdf`.

Đề dành cho năm nhất
====================

Bài 1
-----

Đề bài
^^^^^^

Tồn tại hay không một đa thức :math:`p(x)` sao cho mọi hệ số khác không của nó không phải số nguyên, nhưng với hai số nguyên bất kì khác nhau :math:`a` và :math:`b` ta đều có :math:`\dfrac{p(a) - p(b)}{b - a}` là số nguyên?

Lời giải
^^^^^^^^

Tồn tại, ví dụ như :math:`p(x) = \dfrac{x^4 + x^2}{2}`:

.. math:: \frac{p(a) - p(b)}{a - b} = \cdots = \frac{(a + b)(a^2 + b^2 + 1)}{2}.

Vì :math:`a+b` và :math:`a^2 + b^2 + 1` khác tính chẵn lẻ nên tích trên luôn chia hết cho :math:`2` và do đó là số nguyên.

Bài 2
-----

Đề bài
^^^^^^^^

Cho dãy :math:`\{ a_n \}`, :math:`n \geqslant 0` thỏa điều kiện :math:`a_0 = 1`, :math:`a_1 = \dfrac{1}{2}`,

.. math:: a_n = \frac{n}{2} a_{n-1} + \frac{n(n-1)}{2} a_{n-2} + \frac{(-1)^n (1 - n)}{2(n+1)}.

Tìm :math:`\lim\limits_{n \to \infty} \dfrac{a_n}{n!}`.

Lời giải
^^^^^^^^

Từ quy nạp toán học có thể chứng minh (kiểm tra trực tiếp với :math:`a_1 = \tfrac12`, :math:`a_2 = \tfrac43`)

.. math:: a_n = n a_{n-1} + \frac{(-1)^n}{n+1}.

Từ đó,

.. math::

    a_n & = n \left( (n-1) a_{n-2} + \frac{(-1)^{n-1}}{n} \right) + \frac{(-1)^n}{n+1} \\
    & = n (n-1) a_{n-2} + (-1)^{n-1} + \frac{(-1)^n}{n+1} \\
    & = \ldots \\
    & = n! a_0 - \frac{n!}{2!} + \frac{(-1)^2 n!}{3!} + \frac{(-1)^3 n!}{4!} + \cdots + \frac{(-1)^{n-1} n!}{n!} + \frac{(-1)^n n!}{(n+1)!}

Nói cách khác,

.. math::

    \frac{a_n}{n!} & = a_0 + \frac{(-1)^1}{2!} + \frac{(-1)^2}{3!} + \frac{(-1)^3}{4!} + \cdots + \frac{(-1)^{n-1}}{n!} + \frac{(-1)^n}{(n+1)!} \\
    & = \sum_{k=0}^n \frac{(-1)^k}{(k+1)!} = 1 - \sum_{k=0}^{n+1} \frac{(-1)^k}{k!} \to 1 - \frac{1}{e}

Bài 3
-----

Đề bài
^^^^^^^^

Cho hàm đơn điệu liên tục tăng nghiêm ngặt :math:`f(x)` xác định trên nửa khoảng :math:`[0, +\infty)` và thỏa :math:`f(0) = 0`. Đặt :math:`g(x)` là hàm ngược của :math:`f(x)`. Chứng minh rằng, với mọi số nguyên :math:`m, n` thì bất đẳng thức sau thỏa mãn:

.. math:: m n \leqslant \sum_{k=0}^m [f(k)] + \sum_{s=0}^n [g(s)].

Lời giải
^^^^^^^^

Ta đếm các điểm nguyên. Với :math:`k \geqslant 0`, số :math:`[f(k)]` bằng số các số nguyên :math:`j` với :math:`1 \leqslant j \leqslant f(k)`, nên :math:`\sum_{k=0}^m [f(k)]` là số điểm nguyên :math:`(k, j)` với :math:`0 \leqslant k \leqslant m` và :math:`1 \leqslant j \leqslant f(k)`. Tương tự, :math:`\sum_{s=0}^n [g(s)]` là số điểm nguyên :math:`(i, s)` với :math:`0 \leqslant s \leqslant n` và :math:`1 \leqslant i \leqslant g(s)`.

Xét một điểm nguyên :math:`(k, j)` bất kỳ với :math:`1 \leqslant k \leqslant m` và :math:`1 \leqslant j \leqslant n`; có :math:`mn` điểm như vậy.

- Nếu :math:`j \leqslant f(k)` thì điểm này được đếm trong tổng thứ nhất.
- Nếu :math:`j > f(k)` thì, vì :math:`g` là hàm ngược tăng nghiêm ngặt của :math:`f`, ta có :math:`k < g(j)`, nên :math:`1 \leqslant k \leqslant g(j)` và điểm :math:`(k, j)` được đếm trong tổng thứ hai (với :math:`i = k`, :math:`s = j`).

Như vậy mỗi điểm trong số :math:`mn` điểm được đếm ít nhất một lần, suy ra

.. math:: m n \leqslant \sum_{k=0}^m [f(k)] + \sum_{s=0}^n [g(s)].

(Ở đây :math:`m, n` là các số nguyên không âm; các số hạng :math:`[f(0)] = [g(0)] = 0`.)

Bài 4
-----

Đề bài
^^^^^^^^

Cho đa thức với hệ số nguyên

.. math:: f(x) = x^{2m} + x^{m+n} - 4 x^m + x^{m-n} + 1.

với :math:`m > n` là hai số tự nhiên nguyên tố cùng nhau. Tìm ước chung lớn nhất giữa :math:`f(x)` và :math:`f'(x)`.

Lời giải
^^^^^^^^

Ta thấy rằng :math:`f(1) = f'(1) = 0`, tức :math:`x=1` là nghiệm bội (ít nhất) hai của :math:`f(x)`. Ta sẽ chứng minh rằng :math:`f(x)` và :math:`f'(x)` không có nghiệm tổng quát (nghiệm phức) nào khác. Giả sử có nghiệm :math:`z \in \mathbb{C}`. Khi đó

.. math:: z^m + z^{-m} + z^n + z^{-n} = 4, m(z^m - z^{-m}) + n(z^n - z^{-n}) = 0.

Đặt :math:`u = z^m` và :math:`v = z^n`. Khi đó

.. math:: u + u^{-1} + v + v^{-1} = 4, m (u - u^{-1}) + n (v - v^{-1}) = 0.

Nếu :math:`u = 1` thì từ phương trình đầu :math:`v + v^{-1} = 2`, tức :math:`v = 1` (và ngược lại). Khi :math:`u = v = 1`, tức :math:`z^m = z^n = 1`, ta có :math:`z = 1` vì :math:`(m, n) = 1`. Nếu :math:`u \neq 1` và :math:`v \neq 1` thì ta nghiệm của hệ phương trình là :math:`(u, v) \in \{ (u_0, v_0), (u_0^{-1}, v_0^{-1}) \}` với

.. math:: u_0 = - \frac{m^2 + 3n^2 + 2n \sqrt{2(m^2 + n^2)}}{m^2 - n^2}, v_0 = \frac{3m^2 + n^2 + 2m \sqrt{2 (m^2 + n^2)}}{m^2 - n^2}.

Ở đây :math:`u_0` và :math:`v_0` là các số thực và thỏa mãn đẳng thức :math:`u_0^n = v_0^m`. Nhưng vì :math:`1 < \lvert u_0 \rvert < v_0` nên khi :math:`m > n` thì :math:`\lvert u_0 \rvert^n < v_0^m`, các đẳng thức trên không đúng (tương tự với :math:`(u_0^{-1}, v_0^{-1})`). Vậy nghiệm chung duy nhất của :math:`f` và :math:`f'` là :math:`x = 1`, và vì :math:`f''(1) = 2(m^2 + n^2) \neq 0` nên :math:`x = 1` là nghiệm đơn của :math:`f'` (nghiệm kép của :math:`f`), do đó :math:`\gcd(f(x), f'(x)) = x - 1`.
