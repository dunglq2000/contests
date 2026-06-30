Internet Olympiad 2023 (Vòng 3)
*******************************

Bài 1
=====

Đề bài
------

Ở công viên cho trò chơi, với 5 dollar chúng ta được chơi 3 lượt
và được thưởng 1 viên kẹo. Nếu trả lại 2 lượt (không chơi) thì
chúng ta được trả lại 3 dollar đồng thời thêm 1 viên kẹo nữa.
Ở đây không có quy luật trao đổi khác. Một đứa trẻ vào chơi,
chỉ mang mỗi dollar. Kết thúc trò chơi, lượng dollar giảm
nhưng đứa trẻ có 50 viên kẹo (không còn lượt chơi sót lại). 
Hỏi đứa trẻ đã dùng bao nhiêu dollar cho trò chơi.

Lời giải
--------

Đặt :math:`x` là số dollar ban đầu đứa trẻ có, và :math:`y` là số lượt 5 dollar mà đứa trẻ mua, tương đương :math:`y` viên kẹo. Suy ra số lần chơi mà đứa trẻ bỏ lại 2 lượt là :math:`50-y`. 

Nếu chơi hết 3 lượt thì đứa trẻ mất 5 dollar, nếu chơi 1 lượt (trả lại 2) thì đứa trẻ mất  :math:`5-3=2` dollar. Theo giả thiết là không còn lượt chơi sót lại, như vậy số lần chơi hết 3 lượt phải bằng bù lại số lần bỏ 2 lượt.

Nói cách khác :math:`3y = 2(50-y)`. Vậy :math:`y=20` và :math:`50-y=30`. Nghĩa là số lần đứa trẻ trả lại 2 lượt chơi là :math:`3 \cdot 30 = 90` dollar, và số tiền trả là :math:`5 y = 100`. Như vậy để có 50 viên kẹo thì đứa trẻ cần :math:`100 - 90 = 10` dollar.

Bài 2
=====

Đề bài
------

Gọi :math:`x_0` là cực tiểu địa phương của hàm số khả vi :math:`f(x)` thỏa mãn :math:`f'(x) = 1 - x f^2(x)` với mọi :math:`x`. Hỏi có thể xác định nó là cực đại hay cực tiểu không?

Lời giải
--------

Có thể. Do :math:`x_0` là cực trị địa phương nên :math:`f'(x_0) = 0`.
Suy ra :math:`f'(x_0) = 1 - x_0 f^2(x_0) = 0` và dễ thấy :math:`x_0 = 0`
không là nghiệm của phương trình. Vậy ta có :math:`f^2(x_0) = \dfrac{1}{x_0} > 0`.

Từ :math:`f'(x) = 1 - x f^2(x)` ta đạo hàm 2 vế thu được :math:`f''(x) = -f^2(x) - 2xf(x) f'(x)`. 

Do :math:`f'(x_0) = 0` nên 

.. math:: f''(x_0) = -f^2(x_0) - 2 x_0 \cdot f(x_0) f'(x_0) = -f^2(x_0) < 0,

suy ra :math:`x_0` là cực đại.

Bài 3
=====

Đề bài
------

Có bao nhiêu cách xếp 4 phần tử của 4 loại gạch khác nhau lên bảng 4x4 ô vuông sao cho ở mỗi hàng và mỗi cột có đúng 4 viên gạch thuộc 4 loại khác nhau?

Lời giải
--------

Ta cố định hàng đầu tiên của bảng là 1-2-3-4.

.. figure:: 2023-figures-1.jpg

Tiếp theo ta bỏ các phần tử vào cột đầu theo thứ tự

.. figure:: 2023-figures-2.jpg

Trong bảng :math:`3 \times 3` còn lại ta phân bố các phần tử 1 vào các hàng, ta có 6 cách xếp như sau:

.. figure:: 2023-figures-3.jpg

Ta thấy rằng các trường hợp 1, 2, 4 và 6 sẽ có cách xếp các phần tử còn lại vào thỏa mãn. Nhưng trường hợp 3 và 5 sẽ bị đụng độ và không xếp được. Như vậy có 4 cách xếp.

Với mỗi cách xếp, ta có thể hoán vị 3 phần tử ở cột đầu tiên (hàng đầu cố định, hoán vị từ hàng 2 tới 4) nên ta có :math:`3!` cách chọn. Với mỗi cách cố định hàng đầu ta có :math:`4 \cdot 3!` cách chọn, và ta có :math:`4!` cách xếp hàng đầu tiên.

Như vậy kết quả là :math:`4 \cdot 3! \cdot 4! = 576`.

Bài 5
=====

Đề bài
------

Cho hàm :math:`f(x)` thỏa mãn :math:`f(x) + \dfrac{1}{2} \sin f(x) = x` với mọi :math:`x \in \mathbb{R}`. Tính tích phân :math:`\displaystyle{\int\limits_{0}^{\pi} f(x) \,dx}`.

Lời giải
--------

Đặt :math:`t = f(x)` thì :math:`dt = f'(x)\,dx`. Sử dụng tích phân từng
phần với :math:`u = f(x)` và :math:`dv = dx` ta có :math:`du = f'(x)\,dx` và
:math:`v = x`, suy ra:

.. math:: \int\limits_{0}^{\pi} f(x) \, dx = x f(x) \Big|^\pi_0 - \int\limits_{0}^{\pi}x f'(x) \,dx

Từ giả thiết :math:`f(x) + \dfrac{1}{2} \sin f(x) = x`, đạo hàm 2 vế ta có 

.. math:: f'(x) + \dfrac{1}{2} \cos f(x) f'(x) = 1,

tương đương với :math:`f'(x) = \dfrac{2}{2 + \cos f(x)}` mà :math:`-1 \leqslant \cos f(x) \leqslant 1` với mọi :math:`x \in \mathbb{R}` nên :math:`f'(x) > 0` với mọi :math:`x \in \mathbb{R}`. Nghĩa là hàm đồng biến trên :math:`\mathbb{R}`.

Từ đó, với mỗi :math:`x \in \mathbb{R}` tồn tại duy nhất :math:`f(x)` tương ứng với nó. Ta thay :math:`x = 0` và :math:`f(x) = 0` vào phương trình thì 
thấy thỏa mãn. Như vậy :math:`f(0) = 0`. Tương tự :math:`f(\pi) = \pi`.
Do đó :math:`x f(x) \Big|^\pi_0 = \pi^2`.

Cũng từ đó ta có 

.. math:: \displaystyle{\int\limits_{0}^{\pi} x f'(x)\,dx = \int\limits_{0}^{\pi} x \, dt = \int\limits_{0}^{\pi} (t + \dfrac{1}{2} \sin t)\,dt = \dfrac{\pi^2}{2} + 1}.

Tóm lại :math:`\displaystyle{\int\limits_{0}^{\pi}f(x)\,dx = \pi^2 - (\dfrac{\pi^2}{2} + 1) = \frac{\pi^2}{2} - 1}`.

Bài 6
=====

Đề bài
------

Trong không gian cho tam giác vuông cân :math:`ABC`. 

Gọi :math:`A_1 B_1 C_1` là hình chiếu của tam giác :math:`ABC` lên mặt phẳng nào đó (:math:`A_1`, :math:`B_1`, :math:`C_1`
lần lượt là hình chiếu của :math:`A`, :math:`B` và :math:`C` lên mặt phẳng đó).
Biết rằng :math:`A_1 B_1 C_1` cũng là tam giác vuông cân. Tìm mọi giá
trị có thể của tỉ số giữa độ dài cạnh góc vuông :math:`AB` và cạnh
góc vuông :math:`A_1 B_1`.

Lời giải
--------

Không mất tính tổng quát, ta chọn :math:`A_1` ở gốc tọa độ :math:`Oxyz`, 
:math:`B_1 = (1, 0, 0)` và :math:`C_1 = (0, 1, 0)`. Khi đó :math:`A_1` là hình
chiếu của :math:`A` lên mặt phẳng :math:`Oxy` nên :math:`A = (0, 0, 1)`. Tương
tự, :math:`B_1` là hình chiếu của :math:`B` lên mặt :math:`Oxy` nên :math:`B` nằm
trên đường thẳng qua :math:`B` song song :math:`Oz`, vậy :math:`B = (1, 0, x)`.
Tương tự :math:`C = (0, 1, y)`.

Từ giả thiết :math:`AB` và :math:`A_1 B_1` là cạnh góc vuông, vậy :math:`\angle A = 90`
hoặc :math:`\angle B = 90`.

Ta có các vector :math:`\overline{AB} = (1, 0, x-1)`, :math:`\overline{AC} = (0, 1, y-1)`, :math:`\overline{BC} = (-1, 1, y-x)`.
Tương tự :math:`\overline{A_1 B_1} = (1, 0, 0)`, :math:`\overline{A_1 C_1} = (0, 1, 0)`, :math:`\overline{B_1 C_1} = (-1, 1, 0)`.

*Trường hợp 1.* Tam giác :math:`ABC` vuông tại :math:`A`. Khi đó
:math:`\overline{AB} \cdot \overline{AC} = 0` và 
:math:`\lvert \overline{AB}\rvert = \lvert \overline{AC} \rvert`. Tương đương với :math:`(x-1)(y-1) = 0`
và :math:`1 + (x-1)^2 = 1 + (y-1)^2`. Suy ra :math:`x = y = 1`. Như vậy 
:math:`\dfrac{AB}{A_1 B_1} = 1`.

*Trường hợp 2.* Tam giác :math:`ABC` vuông tại :math:`B`. Khi đó
:math:`\overline{AB} \cdot \overline{BC} = 0` và :math:`\lvert \overline{AB} \rvert = \lvert \overline{BC} \rvert`. Tương đương với :math:`-1 + (x-1)(y-x) = 0` và :math:`1 + (x-1)^2 = 2 + (y-x)^2`. Ta thấy :math:`x = 1` không là nghiệm của phương trình đầu, nên :math:`y - x = \dfrac{1}{x-1}`. Thay vào phương trình thứ hai và biến đổi ta có

.. math:: 

    \begin{array}{cc}
        & 1 + (x-1)^2 = 2 + \frac{1}{(x-1)^2} \\ 
        \Leftrightarrow & (x-1)^4 - (x-1)^2 - 1 = 0 \\ 
        \Leftrightarrow & (x-1)^2 = \dfrac{1+\sqrt{5}}{2}
    \end{array}

mà 

.. math:: AB = \sqrt{1 + (x-1)^2} = \sqrt{1 + \dfrac{1 + \sqrt{5}}{2}} = \dfrac{1 + \sqrt{5}}{2} \ \text{và} \ A_1 B_1 = 1

nên tỉ số là :math:`\dfrac{AB}{A_1 B_1} = \dfrac{1 + \sqrt{5}}{2}`.

Như vậy có 2 đáp án thỏa mãn là :math:`1` và :math:`\dfrac{1 + \sqrt{5}}{2}`.

Bài 7
=====

Đề bài
------

Cho hai ma trận vuông :math:`A` và :math:`B` sao cho :math:`B^2 = 0` và
:math:`A^2 B + B A^2 = 2A^3`. Chứng minh rằng với mỗi ma trận
:math:`A` như vậy thì :math:`A^{12} = 0`.

Lời giải
--------

Từ giả thiết :math:`A^2 B + B A^2 = 2A^3`, nhân hai vế của phương
trình cho :math:`B` vào bên trái thì ta có :math:`B A^2 B = 2BA^3`. Tương
tự nếu nhân :math:`B` vào bên phải thì :math:`B A^2 B = 2A^3 B`. Như vậy
:math:`BA^3 = A^3 B`.

Tiếp theo nhân hai vế :math:`A^2 B + B A^2 = 2A^3` vào bên trái và bên phải cho :math:`A^2` thì :math:`A^4 B + A^2 B A^2 = 2A^5` và :math:`A^2 B A^2 + BA^4 = 2A^5`. Như vậy :math:`A^4 B = B A^4`.

Khi đó

.. math:: A^5 B & = A \cdot A^4 B = A \cdot BA^4 = A \cdot BA^3 \cdot A \\ & = A \cdot A^3 \cdot A = A^4 B \cdot A = B A^4 A = B A^5.

Như vậy :math:`A^5 B = B A^5`.

Bình phương hai vế :math:`A^2 B + BA^2 = 2A^3` ta có

.. math:: 

    4A^6 & = A^2 B A^2 B + A^2B BA^2 + BA^2 A^2 B + BA^2 BA^2 \\
        & = A^2 B A^2 B + BA^4 B + BA^2 BA^2

mà :math:`BA^4B = A^4 B B = 0` nên :math:`4A^6 = A^2B A^2B + BA^2 BA^2`.

Tiếp theo, từ :math:`A^2 B + BA^2 = 2A^3` ta có

.. math:: 

    A^2B A^2B & = A^2B (2A^3 - BA^2) = 2 A^2 B A^3 - A^2 B \cdot BA^2
            \\ & = 2 A^2 A^3 B - 0 = 2 A^5 B

Tương tự

.. math:: 

    BA^2 BA^2 & = (2A^3 - A^2B) BA^2 = 2A^3 BA^2 - A^2B \cdot BA^2
            \\ & = 2 BA^3 \cdot A^2 - 0 = 2BA^5

Mà :math:`A^5 B = BA^5` nên :math:`4A^6 = 2A^5B + 2BA^5 = 4A^5B`. Suy ra
:math:`A^6 = A^5 B`. Cuối cùng 

.. math:: A^{12} = A^6 \cdot A^6 = A^5B \cdot BA^5 = 0.

Ta có điều phải chứng minh.

Bài 8
=====

Đề bài
------

Cho ba số dương :math:`a`, :math:`b`, :math:`c` sao cho :math:`\sin a \cdot \sin b \cdot \sin c = \dfrac{3}{\pi} \cdot abc`. Chứng minh rằng 
:math:`a + b + c > \dfrac{\pi}{6}`.

Lời giải
--------

Do :math:`a`, :math:`b`, :math:`c` dương nên ta có thể chia 2 vế cho :math:`abc` và có
:math:`\dfrac{\sin a}{a} \cdot \dfrac{\sin b}{b} \cdot \dfrac{\sin c}{c} = \dfrac{3}{\pi}`.

Xét hàm :math:`f(x) = \ln \left(\dfrac{\sin x}{x}\right)`. Do :math:`a`, :math:`b`, :math:`c` dương nên vế trái cũng dương, do đó ta chỉ cần xét các số trong khoảng :math:`\left(0, \frac{\pi}{2}\right)` là đủ. Khi đó, đặt

.. math:: 
    
    f(x) = \begin{cases} \ln\left(\dfrac{\sin x}{x}\right), \quad
    & 0 < x < \frac{\pi}{2} \\
    0, \quad & x = 0
    \end{cases}

Từ giả thiết suy ra:

.. math:: 

    f(a) + f(b) + f(c) & = \ln \left(\frac{\sin a}{a}\right) 
    + \left(\frac{\sin b}{b}\right) + \left(\frac{\sin c}{c}\right) \\
    & = \ln\left(\frac{\sin a}{a} \cdot \frac{\sin b}{b} 
    \cdot \frac{\sin c}{c}\right) \\
    & = \ln\left(\frac{3}{\pi}\right) = f\left(\frac{\pi}{6}\right)

Ta thấy :math:`e^{f(x)} = \dfrac{\sin x}{x}`. Đạo hàm hai vế suy ra

.. math:: e^{f(x)} f'(x) = \left(\dfrac{\cos x}{x} - \dfrac{\sin x}{x^2}\right).

Vậy:

.. math:: f'(x) = \left(\frac{\cos x}{x} - \frac{\sin x}{x^2}\right)\cdot \frac{x}{\sin x} = \cot x - \frac{1}{x}.

Và đạo hàm cấp hai:

.. math:: f''(x) = \frac{-1}{\sin^2 x} + \frac{1}{x^2}

mà trên khoảng :math:`(0, \dfrac{\pi}{2})` thì :math:`\sin x < x`
nên :math:`f''(x) < 0` với mọi :math:`x \in (0, \dfrac{\pi}{2})`.
Do đó :math:`f'(x)` nghịch biến biến trên :math:`(0, \dfrac{\pi}{2})`,
và do :math:`\dfrac{\sin x}{x}` nghịch biến trên :math:`(0, \dfrac{\pi}{2})` nên :math:`f(x)` cũng nghịch biến trên :math:`(0, \dfrac{\pi}{2})`.

Không mất tính tổng quát giả sử :math:`a \leqslant b \leqslant c`.
Theo định lý Lagrange (khúc này hack não lắm!!!) thì
tồn tại số :math:`\xi_1 \in (0, a)` sao cho 

.. math:: f(a) - f(0) = f'(\xi_1) \cdot (a - 0) \Leftrightarrow f(a) - f(0) = f'(\xi_1) \cdot a.

Tương tự tồn tại số :math:`\xi_2 \in (a, a+b)` sao cho

.. math:: f(a+b) - f(b) = f'(\xi_2) \cdot (a + b - b) = f'(\xi_2) \cdot a.

Do :math:`\xi_1 < \xi_2` và :math:`f'(x)` nghịch biến nên :math:`f'(\xi_1) > f'(\xi_2)`.

Suy ra :math:`f(a) - f(0) > f(a+b) - f(b)`, hay :math:`f(a) + f(b) > f(a+b) + f(0).`

Chứng minh tương tự ta cũng có 

.. math:: f(a+b) + f(c) > f(a+b+c) + f(0).

Như vậy 

.. math:: 
    
    f\left(\frac{\pi}{6}\right) = f(a) + f(b) + f(c) & > f(a+b) + f(0) + f(c) \\ & > f(a+b+c) + f(0) + f(0) > f(a + b + c)

Do :math:`f(x)` nghịch biến nên :math:`a + b + c > \dfrac{\pi}{6}` là điều cần chứng minh.

Bài 10
======

Đề bài
------

Cho đa thức với hệ số nguyên

.. math:: P_n(x) = a_n x^n + a_{n-1} x^{n-1} + \ldots + a_1 x + a_0

Biết rằng :math:`a_n` là số lẻ, và :math:`P_n(k)`, :math:`P_n(k+1)` là các số
lẻ với :math:`k` nào đó. Chứng minh rằng đa thức không có nghiệm hữu tỷ.

Lời giải
--------

Giả sử đa thức có nghiệm hữu tỷ :math:`\dfrac{p}{q}` với :math:`p` và :math:`q`
nguyên tố cùng nhau (phân số tối giản). Khi đó 

.. math:: P_n(x) = \left(x - \dfrac{p}{q}\right) \cdot Q_{n-1}(x) = (qx - p) \left(\dfrac{1}{q} Q_{n-1}(x)\right).

Do :math:`p` và :math:`q` nguyên tố cùng nhau nên :math:`\dfrac{1}{q} Q_{n-1}(x)`
cũng là một đa thức hệ số nguyên. Ta nhận thấy rằng

.. math:: 

    P_n(x) & = a_n x^n + a_{n-1} x^{n-1} + \ldots + a_1 x + a_0 \\
    & = (qx - p) \left(\dfrac{a_n}{q} x^{n-1} + \ldots + \dfrac{-a_0}{q}\right).

Ở đây ta có thể xét hệ số bậc cao nhất và thấp nhất, và từ
đó suy ra :math:`\dfrac{a_n}{q}` và :math:`\dfrac{a_0}{q}` là các số nguyên.

Vậy với số nguyên :math:`m` bất kì thì :math:`\dfrac{P_n(m)}{qm - p} = N(m)` cũng là một số nguyên. Mà từ giả thiết :math:`a_n`, :math:`P_n(k)` và :math:`P_n(k+1)` là các số lẻ thì :math:`qk - p = 2m_1 - 1` (số lẻ không thể chia hết cho số chẵn). Tương tự :math:`q(k+1) - p = 2m_2 - 1`.

Trừ vế theo vế ta có 

.. math:: (2m_2 - 1) - (2m_1 - 1) = 2 (m_2 - m_1) = q.

Như vậy :math:`q` là số chẵn, tuy nhiên do :math:`\dfrac{a_n}{q}` là số nguyên và :math:`a_n` là số lẻ nên :math:`q` phải là số lẻ, mâu thuẫn. 

Theo phản chứng, đa thức không có nghiệm hữu tỷ.
