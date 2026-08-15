Các bài toán sưu tầm
********************

Олимпиада Якут
==============

.. admonition:: Câu 1

    Tính :math:`\lim\limits_{t \to +\infty} t \sum\limits_{k=1}^{+\infty} \dfrac{1}{k^2 + t^2}`.

Ta có công thức thông dụng

.. math:: \int \frac{dx}{x^2 + t^2} = \frac{1}{t} \arctan \frac{x}{t}.

Ta có chặn

.. math:: \frac{1}{(k+1)^2 + t^2} \leqslant \int\limits_{k}^{k+1} \frac{dx}{x^2 + t^2} \leqslant \frac{1}{k^2 + t^2},

suy ra

.. math:: \frac{1}{k^2 + t^2} \leqslant \int\limits_{k-1}^k \frac{dx}{x^2 + t^2}.

Cộng tất cả phương trình trên với :math:`k=1, 2, \ldots` thì

.. math:: \sum_{k=1}^\infty \frac{1}{k^2 + t^2} \leqslant \int\limits_0^{+\infty} \frac{dx}{x^2 + t^2} = \frac{1}{t} \cdot \arctan \frac{x}{t} \Big|_0^{+\infty} = \frac{1}{t} \cdot \frac{\pi}{2}.

Tương tự

.. math:: 

    & \int\limits_{k}^{k+1} \frac{dx}{x^2 + t^2} \leqslant \frac{1}{k^2 + t^2} \\
    \Rightarrow & \int\limits_{1}^\infty \frac{dx}{x^2 + t^2} \leqslant \sum_{k=1}^\infty \frac{1}{k^2 + t^2}

Do

.. math:: \int\limits_1^\infty \frac{dx}{x^2 + t^2} = \frac{1}{t} \arctan \frac{x}{t} \Big|_1^\infty = \frac{1}{t} \left( \frac{\pi}{2} - \arctan \frac{1}{t} \right)

nên

.. math:: \left( \frac{\pi}{2} - \arctan \frac{1}{t} \right) \leqslant t \sum_{k=1}^\infty \frac{1}{k^2 + t^2} \leqslant \frac{\pi}{2}.

Như vậy

.. math:: \lim\left(\frac{\pi}{2} - \arctan \frac{1}{t}\right) = \lim \frac{\pi}{2} = \frac{\pi}{2}

khi :math:`t \to \infty`.

.. admonition:: Câu 2

    Giải phương trình

    .. math:: 19^x - 13^x = 9^x - 3^x.

Dễ thấy :math:`x = 0` là một nghiệm của phương trình.

Giả sử phương trình có nghiệm khác :math:`0` là :math:`x`.

Cố định :math:`x`, đặt :math:`g(t) = t^x`.

Theo định lí Lagrange, tồn tại :math:`\xi \in (a, b)` để :math:`g(a) - g(b) = g'(\xi) \cdot (a - b)`.

Như vậy

.. math:: g'(\xi) \cdot (19 - 13) = g'(\eta) \cdot (9 - 6)

với :math:`\xi \in (13, 19)` và :math:`\eta \in (6, 9)`. Suy ra :math:`g'(\xi) = g'(\eta)`, nói cách khác là

.. math:: x \cdot \xi^{x-1} = x \cdot \eta^{x-1}

mà :math:`x \neq 0` nên :math:`\left(\dfrac{\xi}{\eta}\right)^{x-1} = 1`. Điều này chỉ xảy ra khi :math:`x-1 = 0`, hay :math:`x = 1`.

Kết luận: phương trình có hai nghiệm là :math:`x = 0` và :math:`x = 1`.

Bài tập sưu tầm
===============

Tính tổng

.. math:: \sum_{k=1}^n \cos(kx).

Đặt

.. math:: 

   \alpha & = e^{ix} = \cos(x) + i \sin(x) \\
   \alpha^2 & = e^{2ix} = \cos(2x) + i \sin(2x) \\
   \cdots & \cdots \\\
   \alpha^n & = e^{nix} = \cos(nx) + i \sin(nx)

Ta có

.. math:: 

   I & = 1 + \alpha + \alpha^2 + \cdots + \alpha^n = \frac{\alpha^{n+1} - 1}{\alpha - 1} \\
      & = \frac{\cos(n+1)x + i \sin(n+1)x - 1}{\cos(x) + i \sin(x) - 1} \\
      & = \frac{\left(\cos(n+1)x - 1 + i \sin(n+1)x\right)\left(\cos(x) - 1 - i \sin(x)\right)}{\left(\cos(x) - 1 + i \sin(x)\right)\left(\cos(x) - 1 - i \sin(x)\right)} \\
      & = \frac{\cos(n+1)x \cdot \cos(x) - \cos(n+1)x - \cos(x) + 1 - \sin(n+1)x \cdot \sin(x) + i\left((\cos(n+1)x - 1) \cdot \sin x + (\cos(x) - 1) \cdot \sin(n+1)x\right)}{(\cos(x) - 1)^2 + \sin(x)^2}

Vì tổng :math:`\sum\limits_{k=1}^n \cos(kx)` là phần thực của :math:`I - 1` nên ta chỉ cần xét phần thực của :math:`I`, tức là

.. math:: 

   \sum_{k=1}^n \cos(kx) & = \frac{\cos(n+1)x \cdot \cos(x) - \cos(n+1)x - \cos(x) + 1 - \sin(n+1)x \cdot \sin(x)}{(\cos(x) - 1)^2 + \sin(x)^2} - 1 \\
      & = \frac{\cos(n+1)x \cdot \cos(x) - \cos(n+1)x - \cos(x) + 1 - \sin(n+1)x \cdot \sin(x)}{2 - 2 \cos(x)} - 1 \\
      & = \frac{\cos(n+2)x - \cos(n+1)x + \cos(x) - 1}{2 - 2 \cos(x)}.

----

Cho :math:`0 < x < 1`. Chứng minh rằng :math:`x - x^2 < \sin x < x`.

Xét :math:`f(x) = \sin x - x + x^2`. Ta có

.. math:: f'(x) = \cos x - 1 + 2x, f''(x) = -\sin x + 2 > 0

vì :math:`-1 \leqslant \sin x \leqslant 1` với mọi :math:`x \in (0; 1)`. Do đó :math:`f'(x)` đồng biến trên :math:`(0, 1)` nên suy ra

.. math:: f'(x) > f'(0) = \cos 0 - 1 + 2 \cdot 0 = 0

với mọi :math:`0 < x < 1`. Như vậy, vì :math:`f'(x) > 0` với mọi :math:`x \in (0; 1)` nên :math:`f(x)` đồng biến trên :math:`(0; 1)`, hay

.. math:: f(x) > f(0) = \sin 0 - 0 + 0^2 = 0 \Longleftrightarrow \sin x > x - x^2.

Tương tự, xét :math:`g(x) = \sin x - x`. Ta có

.. math:: g'(x) = \cos x - 1 \leqslant 0

với mọi :math:`x \in (0; 1)` nên suy ra :math:`g(x)` nghịch biến trên :math:`(0; 1)`, hay

.. math:: g(x) < g(0) = \sin 0 - 0 = 0

với mọi :math:`x \in (0; 1)`, từ đó :math:`\sin x < x`.
