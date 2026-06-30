Siberian Mathematical Contest 2023
**********************************

Đề và lời giải gốc (tiếng Nga) các bạn có thể tải ở :download:`solutions_SMC_2023.pdf`.

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

Từ quy nạp toán học có thể tìm được

.. math:: a_n = n a_{n-1} + \frac{(-1)^n}{n+1}.

Từ đó,

.. math:: 

    a_n & = n \left( (n-1) a_{n-2} + \frac{(-1)^{n-1}}{n} \right) + \frac{(-1)^n}{n+1} \\
    & = n (n-1) a_{n-2} + (-1)^{n-1} + \frac{(-1)^n}{n+1} \\
    & = \ldots \\
    & = n! a_0 - \frac{n!}{2!} + \frac{(-1)^2 n!}{3!} + \frac{(-1)^3 n!}{4!} + \cdots + \frac{(-1)^{n-1} n!}{n!} + \frac{(-1)^n n!}{n!} 

Nói cách khác,

.. math:: 

    \frac{a_n}{n!} & = a_0 + \frac{(-1)^1}{2!} + \frac{(-1)^2}{3!} + \frac{(-1)^3}{4!} + \cdots + \frac{(-1)^{n-1}}{n!} + \frac{(-1)^n}{n!} \\
    & = \sum_{k=0}^n \frac{(-1)^k}{(k+1)!} = 1 - \sum_{k=0}^{n+1} \frac{(-1)^k}{k!} \to 1 - \frac{1}{e}

Bài 3
-----

Đề bài
^^^^^^^^

Cho hàm đơn điệu liên tục tăng nghiêm ngặt :math:`f(x)` xác định trên nửa khoảng :math:`[0, +\infty)` và thỏa :math:`f(0) = 0`. Đặt :math:`g(x)` là hàm ngược của :math:`f(x)`. Chứng minh rằng, với mọi số nguyên :math:`m, n` thì bất đẳng thức sau thỏa mãn:

.. math:: m n \leqslant \sum_{k=0}^m [f(k)] + \sum_{s=0}^n [g(s)].

Lời giải
^^^^^^^^

Giả sử, :math:`[f(m)] \geqslant n`. Đặt :math:`[f(s)] = l_s`. Theo tính đơn điệu thì :math:`l_s \leqslant f(s) < l_{s+1}`. Do :math:`f(x)` liên tục và đơn điệu tăng nghiêm ngặt nên :math:`g(x)` cũng liên tục và đơn điệu.

.. math:: 
    
    \sum_{k=0}^m [f(k)] = l_1 + l_2 + \cdots + l_m;

    \sum_{s=0}^n [g(s)] = 1 (l_2 - l_1) + 2(l_3 - l_2) + 3 (l_4 - l_3) + \cdots + p(n - l_p).

với :math:`p` nào đó mà :math:`l_p < n \leqslant l_{p+1}`. Từ đây ta có

.. math:: l_1 + l_2 + \cdots + l_p + 1 (l_2 - l_1) + 2 (l_3 - l_2) + \cdots + (p-1) (l_p - l_{p-1}) = p l_p.

Vì :math:`l_{p+1}, l_{p+2}, \ldots, l_m > n` nên

.. math:: 

    \sum_{k=0}^m [f(k)] + \sum_{s=0}^n [g(s)] & = p l_p + p(n - l_p) + l_{p+1} + l_{p+2} + \cdots + l_m \\
    & = pn + l_{p+1} + l_{p+2} + \cdots + l_m > pn + (m - p) n = mn.

Chứng minh tương tự cho :math:`[f(m)] < n` (thay :math:`f(x)` thành :math:`g(x)`).

Bài 4
-----

Đề bài
^^^^^^^^

Cho đa thức với hệ số nguyên

.. math:: f(x) = x^{2m} + x^{m+2} - 4 x^m + x^{m-n} + 1.

với :math:`m > n` là hai số tự nhiên nguyên tố cùng nhau. Tìm ước chung lớn nhất giữa :math:`f(x)` và :math:`f'(x)`.

Lời giải
^^^^^^^^

Ta thấy rằng :math:`x=1` là nghiệm bậc hai của :math:`f(x)`. Ta sẽ chứng minh rằng :math:`f(x)` và :math:`f'(x)` không có nghiệm tổng quát (nghiệm phức) nào khác. Giả sử có nghiệm :math:`z \in \mathbb{C}`. Khi đó

.. math:: z^m + z^{-m} + z^n + z^{-n} = 4, m(z^m - z^{-m}) + n(z^n - z^{-n}) = 0.

Đặt :math:`u = z^m` và :math:`v = z^n`. Khi đó

.. math:: u + u^{-1} + v + v^{-1} = 4, m (u - u^{-1}) + n (v - v^{-1}) = 0.

Nếu :math:`u` và :math:`v` bằng :math:`1` thì :math:`z = 1` vì :math:`(m, n) = 1`. Nếu :math:`u \neq 1` và :math:`v \neq 1` thì ta nghiệm của hệ phương trình là :math:`(u, v) \in \{ (u_0, v_0), (u_0^{-1}, v_0^{-1}) \}` với

.. math:: u_0 = - \frac{m^2 + 3n^2 + 2n \sqrt{2(m^2 + n^2)}}{m^2 - n^2}, v_0 = \frac{3m^2 + n^2 + 2m \sqrt{2 (m^2 + n^2)}}{m^2 - n^2}.

Ở đây :math:`u_0` và :math:`v_0` là các số thực và thỏa mãn đẳng thức :math:`u_0^n = v_0^m`. Nhưng vì :math:`1 < \lvert u_0 \rvert < v_0` nên khi :math:`m > n` các đẳng thức trên không đúng.
