Abstract Algebra: Theory and Applications
*****************************************

Lời giải cho quyển sách **Abstract Algebra: Theory and Applications** của Thomas W. Judson :cite:`Judson2012`.

Chương 3. Groups
================

.. admonition::  Bài 7
    
    Đặt :math:`S = \mathbb{R} \setminus \{-1\}` và định nghĩa toán tử hai ngôi trên :math:`S` là :math:`a \star b = a + b + ab`. Chứng minh rằng :math:`(S, \star)` là nhóm Abel.

Để chứng minh :math:`(S, \star)` là nhóm Abel ta kiểm tra tính đóng, ba tiên đề của nhóm và tính giao hoán.

0. Tính đóng: :math:`a \star b = a + b + ab = (1+a)(1+b) - 1`. Với :math:`a, b \neq -1` thì :math:`(1+a)(1+b) \neq 0`, nên :math:`a \star b \neq -1`, tức :math:`a \star b \in S`.
1. Giả sử tồn tại phần tử đơn vị :math:`e`, khi đó :math:`e \star s = s \star e = s` với mọi :math:`s \in S`. Nghĩa là :math:`e + s + es = s + e + se = s`. Vậy :math:`e(1 + s) = 0` mà :math:`s \neq -1` nên :math:`e = 0`; ngược lại :math:`0 \star s = s` nên :math:`0` đúng là phần tử đơn vị.
2. Với :math:`e = 0`, giả sử với mọi :math:`s \in S` có nghịch đảo :math:`s'`. Do :math:`s \star s' = s' \star s = e` nên :math:`s + s' + ss' = s' + s + s's = e = 0`, tức là :math:`s'(1 + s) = -s`. Vậy :math:`s' = \dfrac{-s}{1 + s}`. Phần tử này thuộc :math:`S` vì :math:`\dfrac{-s}{1+s} = -1` kéo theo :math:`s = 1 + s`, vô lý.
3. Với mọi :math:`a, b, c \in S`, 

   .. math:: 

       a \star (b \star c) & = a \star (b + c + bc) = a + (b+c+bc) + a (b+c+bc) \\ 
       & = a + b + c + ab + bc + ca + abc

   và

   .. math:: 

       (a \star b) \star c & = (a + b + ab) \star c = a + b + ab + c + c(a+b+ab) \\
        & = a + b + c + ab + bc + ca + abc.

Như vậy :math:`a \star (b \star c) = (a \star b) \star c`, do đó :math:`\star` có tính kết hợp.

Cuối cùng :math:`a \star b = a + b + ab = b + a + ba = b \star a` nên :math:`\star` giao hoán. Vậy :math:`(S, \star)` là nhóm Abel.

.. admonition::  Bài 39

    Gọi :math:`G` là tập các ma trận :math:`2 \times 2` với dạng

    .. math:: 
        
        \begin{pmatrix}
            \cos \theta & -\sin \theta \\ \sin \theta & \cos \theta
        \end{pmatrix}

    với :math:`\theta \in \mathbb{R}`. Chứng minh rằng :math:`G` là subgroup của :math:`SL_2 (\mathbb{R})`.


Với :math:`\theta_1, \theta_2 \in \mathbb{R}`, ta có

.. math:: 

    & \begin{pmatrix}
        \cos \theta_1 & -\sin \theta_1 \\ \sin \theta_1 & \cos \theta_1
    \end{pmatrix} \begin{pmatrix}
        \cos \theta_2 & -\sin \theta_2 \\ \sin \theta_2 & \cos \theta_2
    \end{pmatrix} \\
    = & \ \begin{pmatrix}
        \cos \theta_1 \cos \theta_2 - \sin \theta_1 \sin \theta_2 & -\cos \theta_1 \sin \theta_2 - \sin \theta_1 \cos \theta_2 \\ 
        \sin \theta_1 \cos \theta_2 + \cos \theta_1 \sin \theta_2 & -\sin \theta_1 \sin \theta_2 + \cos \theta_1 \cos \theta_2
    \end{pmatrix} \\
    = & \ \begin{pmatrix}
        \cos (\theta_1 + \theta_2) & -\sin (\theta_1 + \theta_2) \\
        \sin (\theta_1 + \theta_2) & \cos (\theta_1 + \theta_2)
    \end{pmatrix},

Trước hết mỗi ma trận trong :math:`G` có định thức :math:`\cos^2\theta + \sin^2\theta = 1` nên :math:`G \subseteq SL_2(\mathbb{R})`. Tích của hai phần tử của :math:`G` lại có dạng trên (với góc :math:`\theta_1 + \theta_2`), và định thức của nó là

.. math:: 

    \det \left(\begin{pmatrix}
        \cos (\theta_1 + \theta_2) & -\sin (\theta_1 + \theta_2) \\
        \sin (\theta_1 + \theta_2) & \cos (\theta_1 + \theta_2)
    \end{pmatrix}\right)
    = & 1 \cdot 1 = 1.

Như vậy phép nhân hai ma trận có dạng trên đóng trên :math:`SL_2 (\mathbb{R})`.

Phần tử đơn vị là :math:`\begin{pmatrix} 1 & 0 \\ 0 & 1 \end{pmatrix}` tương ứng với :math:`\theta = 0`.

Phần tử nghịch đảo là :math:`\begin{pmatrix} \cos (-\theta) & -\sin (-\theta) \\ \sin (-\theta) & \cos (-\theta) \end{pmatrix}`, suy ra từ công thức tích ở trên với :math:`\theta_2 = -\theta_1`, và nó cũng thuộc :math:`G`.

Cuối cùng, phép nhân ma trận có tính kết hợp. Như vậy :math:`G` là subgroup của :math:`SL_2 (\mathbb{R})`.      

.. admonition::  Bài 47

    Đặt :math:`G` là nhóm và :math:`g \in G`. Chứng minh rằng

    .. math:: Z(G) = \{ x \in G: gx = xg \; \forall \; g \in G \}

    là subgroup của :math:`G`. Subgroup này gọi là **center** của :math:`G`.

Giả sử trong :math:`G` có hai phần tử là :math:`x_1` và :math:`x_2` thuộc :math:`Z(G)`. Khi đó

.. math:: x_1 g = g x_1 \text{ và } x_2 g = g x_2 \text{ với mọi } g \in G.

Xét phần tử :math:`x_1 x_2`, ta có

.. math:: (x_1 x_2) g = x_1 (x_2 g) = x_1 (g x_2) = (g x_1) x_2 = g (x_1 x_2)

với mọi :math:`g \in G`. Do đó :math:`x_1 x_2 \in Z(G)`. Ngoài ra :math:`eg = g = ge` nên :math:`e \in Z(G)`, và nếu :math:`x \in Z(G)` thì nhân hai vế của :math:`xg = gx` với :math:`x^{-1}` ở bên trái và bên phải được :math:`g x^{-1} = x^{-1} g`, tức :math:`x^{-1} \in Z(G)`. Vậy :math:`Z(G)` là subgroup.

.. admonition::  Bài 49

    Cho ví dụ về nhóm vô hạn mà mọi nhóm con không tầm thường của nó đều vô hạn.

Ví dụ tập :math:`\mathbb{Z}` và phép cộng số nguyên. Khi đó mọi nhóm con của :math:`\mathbb{Z}` có dạng :math:`n\mathbb{Z}` với :math:`n \in \mathbb{Z}`, và nhóm con không tầm thường ứng với :math:`n \neq 0` luôn vô hạn. Ví dụ

* :math:`2\mathbb{Z} = \{\cdots, -4, -2, 0, 2, 4, \cdots\}` với phần tử sinh là :math:`2`;
* :math:`n\mathbb{Z} = \{\cdots, -2n, -n, 0, n, 2n, \cdots\}` với phần tử sinh là :math:`n`.

.. admonition::  Bài 54

    Cho :math:`H` là subgroup của :math:`G` và

    .. math:: C(H) = \{g \in G: gh = hg \; \forall \; h \in H\}.

    Chứng minh rằng :math:`C(H)` là subgroup của :math:`G`. Subgroup này được gọi là **centralizer** của :math:`H` trong :math:`G`.

Gọi :math:`g_1` và :math:`g_2` thuộc :math:`C(H)`. Khi đó :math:`g_1 h = h g_1` và :math:`g_2 h = h g_2` với mọi :math:`h \in H`.

Xét phần tử :math:`g_1 g_2`, với mọi :math:`h \in H` ta có

.. math:: (g_1 g_2) h = g_1 (g_2 h) = g_1 (h g_2) = (g_1 h) g_2 = (h g_1) g_2 = h (g_1 g_2).

Như vậy :math:`g_1 g_2 \in C(H)`. Hiển nhiên :math:`e \in C(H)`, và từ :math:`gh = hg` suy ra :math:`h g^{-1} = g^{-1} h` (nhân :math:`g^{-1}` vào hai phía), nên :math:`g^{-1} \in C(H)`. Từ đó :math:`C(H)` là subgroup của :math:`G`.

Chương 5. Permutation Groups
============================

.. admonition::  Bài 13

    Đặt :math:`\sigma = \sigma_1 \cdots \sigma_m \in S_n` là tích của các cycle độc lập. Chứng minh rằng order của :math:`\sigma` là LCM của độ dài các cycle :math:`\sigma_1, \cdots, \sigma_m`.

Đặt :math:`l_i` là độ dài cycle :math:`\sigma_i` (:math:`i = 1, \ldots, m`). Một cycle độ dài :math:`l_i` có order :math:`l_i`, nên :math:`\sigma_i^l = \mathrm{id}` khi và chỉ khi :math:`l_i \mid l`.

Các cycle độc lập giao hoán với nhau nên :math:`\sigma^l = \sigma_1^l \cdots \sigma_m^l`. Hơn nữa :math:`\sigma_i^l` chỉ di chuyển các phần tử trong cycle :math:`\sigma_i`, và các tập này rời nhau, nên :math:`\sigma^l = \mathrm{id}` khi và chỉ khi :math:`\sigma_i^l = \mathrm{id}` với mọi :math:`i`, tức :math:`l_i \mid l` với mọi :math:`i`. Số :math:`l` dương nhỏ nhất thỏa mãn điều kiện này là :math:`\text{lcm} (l_1, \ldots, l_m)` (đpcm).

.. admonition::  Bài 23

    Nếu :math:`\sigma` là chu trình với độ dài lẻ, chứng minh rằng :math:`\sigma^2` cũng là chu trình.

Giả sử :math:`\sigma = (g_1, g_2, \cdots, g_{n-1}, g_n)` với :math:`n` lẻ.

Khi đó

.. math:: \sigma^2 = (g_1, g_3, \cdots, g_n, g_2, g_4, \cdots, g_{n-1})

cũng là chu trình.

.. admonition::  Bài 30

    Cho :math:`\tau = (a_1, a_2, \cdots, a_k)` là chu trình độ dài :math:`k`.

    1. Chứng minh rằng với mọi hoán vị :math:`\sigma` thì

    .. math:: \sigma \tau \sigma^{-1} = (\sigma(a_1), \sigma(a_2), \cdots, \sigma(a_k))

    là chu trình độ dài :math:`k`.

    2. Gọi :math:`\mu` là chu trình độ dài :math:`k`. Chứng minh rằng tồn tại hoán vị :math:`\sigma` sao cho :math:`\sigma \tau \sigma^{-1} = \mu`.

Để chứng minh hai mệnh đề trên ta cần chú ý một số điều.

1. Với :math:`x = \sigma(a_i)` ta có :math:`\sigma \tau \sigma^{-1}(x) = \sigma(\tau(a_i)) = \sigma(a_{i+1})` (chỉ số lấy theo modulo :math:`k`). Nếu :math:`x` không thuộc :math:`\{\sigma(a_1), \ldots, \sigma(a_k)\}` thì :math:`\sigma^{-1}(x)` không thuộc :math:`\{a_1, \ldots, a_k\}`, nên :math:`\tau` giữ nguyên nó và :math:`\sigma \tau \sigma^{-1}(x) = \sigma \sigma^{-1}(x) = x`. Vậy :math:`\sigma \tau \sigma^{-1} = (\sigma(a_1), \sigma(a_2), \ldots, \sigma(a_k))`, là chu trình độ dài :math:`k` vì :math:`\sigma` là song ánh.
2. Từ câu 1, với :math:`\mu = (b_1, b_2, \ldots, b_k)` thì ta chọn hoán vị :math:`\sigma` bất kỳ sao cho :math:`\sigma(a_i) = b_i` với :math:`i = 1, \ldots, k` (luôn tồn tại vì hai tập :math:`\{a_i\}` và :math:`\{b_i\}` có cùng số phần tử, nên có thể mở rộng thành song ánh trên toàn tập).

Chương 6. Cosets
================

.. admonition::  Bài 11

    Gọi :math:`H` là subgroup của nhóm :math:`G` và giả sử :math:`g_1, g_2 \in G`. Chứng minh các mệnh đề sau là tương đương:

    1. :math:`g_1 H = g_2 H`
    2. :math:`H g_1^{-1} = H g_2^{-1}`
    3. :math:`g_1 H \subseteq g_2 H`
    4. :math:`g_2 \in g_1 H`
    5. :math:`g_1^{-1} g_2 \in H` 


Ta chứng minh theo vòng :math:`(1) \Rightarrow (3) \Rightarrow (4) \Rightarrow (5) \Rightarrow (1)`, sau đó chứng minh :math:`(1) \Leftrightarrow (2)`.

* :math:`(1) \Rightarrow (3)`: hiển nhiên.
* :math:`(3) \Rightarrow (4)`: :math:`g_1 = g_1 e \in g_1 H \subseteq g_2 H`, nên :math:`g_1 = g_2 h` với :math:`h \in H`. Suy ra :math:`g_2 = g_1 h^{-1} \in g_1 H`.
* :math:`(4) \Rightarrow (5)`: :math:`g_2 = g_1 h` với :math:`h \in H`, nên :math:`g_1^{-1} g_2 = h \in H`.
* :math:`(5) \Rightarrow (1)`: đặt :math:`h_0 = g_1^{-1} g_2 \in H`. Khi đó :math:`g_2 H = g_1 h_0 H = g_1 H` vì :math:`h_0 H = H`.
* :math:`(1) \Leftrightarrow (2)`: ánh xạ :math:`x \mapsto x^{-1}` biến :math:`gH` thành :math:`(gH)^{-1} = H^{-1} g^{-1} = H g^{-1}`, và là song ánh. Do đó :math:`g_1 H = g_2 H` khi và chỉ khi :math:`H g_1^{-1} = H g_2^{-1}`.

.. admonition::  Bài 16

    Nếu :math:`g h g^{-1} \in H` với mọi :math:`g \in G` và :math:`h \in H`, chứng minh rằng right coset trùng với left coset.

Do :math:`g h g^{-1} \in H` nên tồn tại :math:`h' \in H` sao cho :math:`g h g^{-1} = h'`. Tương đương :math:`g h = h' g` với mọi :math:`h \in H`, nên :math:`g H \subseteq H g`. Áp dụng giả thiết cho :math:`g^{-1}` thì :math:`g^{-1} h g \in H`, tức :math:`h g = g h''` với :math:`h'' \in H`, nên :math:`H g \subseteq g H`. Vậy :math:`g H = H g` với mọi :math:`g \in G`, tức các right coset trùng left coset.

.. admonition::  Bài 17

    Giả sử :math:`[G:H]=2`. Chứng minh rằng nếu :math:`a, b` không thuộc :math:`H` thì :math:`ab \in H`.

Ta biết rằng 2 coset ứng với 2 phần tử :math:`g_1, g_2` bất kì là trùng nhau hoặc rời nhau.

Do đó với :math:`eH = H`, ta suy ra 2 coset của :math:`G` là :math:`H` và :math:`G \setminus H`.

Vì :math:`a, b \not\in H` nên coset của chúng trùng nhau. Và nghịch đảo của :math:`a` cũng nằm trong :math:`G \setminus H` vì nếu nghịch đảo của :math:`a` nằm trong :math:`H` thì :math:`a` cũng phải nằm trong :math:`H`.

Từ đó suy ra :math:`a^{-1} H = b H`, nghĩa là tồn tại hai phần tử :math:`h_1, h_2 \in H` sao cho :math:`a^{-1} h_1 = b h_2`, tương đương :math:`h_1 h_2^{-1} = a b \in H` (đpcm).

.. admonition::  Bài 21
    
    Gọi :math:`G` là cyclic group với order :math:`n`. Chứng minh rằng có đúng :math:`\phi(n)` phần tử sinh của :math:`G`.

Gọi :math:`g` là một phần tử sinh của :math:`G`. Khi đó :math:`g` sinh ra tất cả phần tử trong :math:`G`, hay nói cách khác các phần tử trong :math:`G` có dạng :math:`g^i` với :math:`0 \leq i < n`.

Như vậy một phần tử :math:`h = g^i` cũng là phần tử sinh của :math:`G` khi và chỉ khi :math:`\gcd(i, n) = 1` và có :math:`\phi(n)` số :math:`i` như vậy (đpcm).

Chương 9. Isomorphism
=====================

.. admonition::  Bài 18

    Chứng minh rằng subgroup của :math:`\mathbb{Q}^*` gồm các phần tử có dạng :math:`2^m 3^n` với :math:`m, n \in \mathbb{Z}` là internal direct product tới :math:`\mathbb{Z} \times \mathbb{Z}`

Gọi :math:`H = \{2^m 3^n : m, n \in \mathbb{Z}\}` và xét ánh xạ :math:`\varphi: H \rightarrow \mathbb{Z} \times \mathbb{Z}`, :math:`\varphi(2^m 3^n) = (m, n)`.

Hàm này là well-defined vì theo định lý cơ bản của số học (phân tích duy nhất ra thừa số nguyên tố, mở rộng cho số hữu tỉ), mỗi phần tử của :math:`H` viết được duy nhất dưới dạng :math:`2^m 3^n`.

Hàm này là đơn ánh (one-to-one) vì nếu :math:`\varphi(2^{m_1} 3^{n_1}) = \varphi(2^{m_2} 3^{n_2})` thì :math:`m_1 = m_2` và :math:`n_1 = n_2`, nên :math:`2^{m_1} 3^{n_1} = 2^{m_2} 3^{n_2}`.

Hàm này cũng là toàn ánh vì với mỗi cặp :math:`(m, n)` ta đều tính được :math:`2^m 3^n`.

Vậy hàm :math:`\varphi` là song ánh.

Thêm nữa,

.. math:: 

    \varphi(2^{m_1} 3^{n_1} \cdot 2^{m_2} 3^{n_2})& = \varphi(2^{m_1 + m_2} 3^{n_1 + n_2}) \\
    & = (m_1 + m_2, n_1 + n_2) = (m_1, n_1) + (m_2, n_2) \\
    & = \varphi(2^{m_1} 3^{n_1}) \varphi(2^{m_2} 3^{n_2}).

Vậy :math:`\varphi` là homomorphism, và là song ánh nên là isomorphism. Nói cách khác, :math:`H` là internal direct product của hai nhóm con cyclic :math:`\langle 2 \rangle` và :math:`\langle 3 \rangle`: chúng giao hoán với nhau, :math:`H = \langle 2 \rangle \langle 3 \rangle` và :math:`\langle 2 \rangle \cap \langle 3 \rangle = \{1\}`, và mỗi nhóm đẳng cấu với :math:`\mathbb{Z}`.

.. admonition::  Bài 20

    Chứng minh hoặc bác bỏ: mọi nhóm Abel có order chia hết bởi :math:`3` chứa một subgroup có order là :math:`3`.

Mệnh đề đúng (đây là trường hợp riêng của định lý Cauchy). Lưu ý rằng nhóm Abel không nhất thiết là nhóm cyclic nên không thể lấy một phần tử sinh của cả nhóm. Ta chứng minh quy nạp theo :math:`|G|`. Chỉ cần tìm một phần tử :math:`h` có order :math:`3`; khi đó :math:`\langle h \rangle` là subgroup có order :math:`3`.

Lấy :math:`g \neq e` bất kỳ, gọi :math:`m` là order của :math:`g`.

* Nếu :math:`3 \mid m` thì :math:`h = g^{m/3}` có order :math:`3`.
* Nếu :math:`3 \nmid m` thì nhóm thương :math:`G / \langle g \rangle` (tồn tại vì :math:`G` Abel) có order :math:`|G| / m` chia hết cho :math:`3` và nhỏ hơn :math:`|G|`. Theo giả thiết quy nạp, có lớp :math:`x \langle g \rangle` có order :math:`3` trong nhóm thương. Gọi :math:`t` là order của :math:`x` trong :math:`G`. Vì :math:`(x \langle g \rangle)^t = \langle g \rangle` nên :math:`3 \mid t`, do đó :math:`h = x^{t/3}` có order :math:`3`.

.. admonition::  Bài 21

    Chứng minh hoặc bác bỏ: mọi nhóm không phải Abel có order chia hết bởi :math:`6` chứa một subgroup có order :math:`6`.

Mệnh đề sai. Lưu ý :math:`S_3` không phải phản ví dụ vì bản thân nó là subgroup order :math:`6` của chính nó. Phản ví dụ là nhóm thay phiên :math:`A_4` có order :math:`12`, không Abel, nhưng không có subgroup order :math:`6`.

Thật vậy, giả sử :math:`H \leqslant A_4` có order :math:`6`. Khi đó :math:`[A_4 : H] = 2` nên :math:`H` chuẩn tắc và :math:`g^2 \in H` với mọi :math:`g \in A_4` (vì :math:`A_4/H` có order :math:`2`). Mọi 3-cycle :math:`c` thỏa :math:`c = (c^2)^2`, nên :math:`c = (c^2)^2 \in H`. Nhưng :math:`A_4` có :math:`8` phần tử là 3-cycle, nhiều hơn :math:`|H| = 6`, mâu thuẫn.

.. admonition::  Bài 22

    Gọi :math:`G` là group với order :math:`20`. Nếu :math:`G` có các subgroup :math:`H` và :math:`K` với order :math:`4` và :math:`5` mà :math:`hk = kh` với mọi :math:`h \in H` và :math:`k \in K`, chứng minh rằng :math:`G` là internal direct product của :math:`H` và :math:`K`.

Ta cần kiểm tra ba điều kiện: :math:`hk = kh` (đã có theo giả thiết), :math:`H \cap K = \{e\}` và :math:`G = HK`.

:math:`H \cap K` là subgroup của cả :math:`H` và :math:`K`, nên theo định lý Lagrange, order của nó chia hết cả :math:`4` và :math:`5`, tức bằng :math:`1`. Như vậy :math:`H \cap K = \{ e \}`.

Ánh xạ :math:`H \times K \to G`, :math:`(h, k) \mapsto hk` là đơn ánh: nếu :math:`h_1 k_1 = h_2 k_2` thì :math:`h_2^{-1} h_1 = k_2 k_1^{-1} \in H \cap K = \{e\}`. Do đó :math:`|HK| = 4 \cdot 5 = 20 = |G|`, tức :math:`G = HK`. Vậy :math:`G` là internal direct product của :math:`H` và :math:`K`.

Chương 11. Homomorphism
=======================

.. admonition::  Bài 1

    Chứng minh rằng

    .. math:: \det(AB) = \det(A) \det(B)

    với :math:`A, B \in GL_2(\mathbb{R})`. Điều này chứng tỏ rằng định thức là homomorphism từ :math:`GL_2(\mathbb{R})` tới :math:`\mathbb{R}^*`.

Đặt :math:`A = \begin{pmatrix} a_{11} & a_{12} \\ a_{21} & a_{22} \end{pmatrix}` và :math:`B = \begin{pmatrix} b_{11} & b_{12} \\ b_{21} & b_{22} \end{pmatrix}`. Khi đó

.. math:: 

    A B = \begin{pmatrix}
        a_{11} b_{11} + a_{12} b_{21} & a_{11} b_{12} + a_{12} b_{22} \\
        a_{21} b_{11} + a_{22} b_{21} & a_{21} b_{12} + a_{22} b_{22}
    \end{pmatrix}
    
Như vậy ta có 

.. math:: 

    \det (AB) = & (a_{11} b_{11} + a_{12} b_{21}) (a_{21} b_{12} + a_{22} b_{22}) \\
            - & (a_{11} b_{12} + a_{12} b_{22}) (a_{21} b_{11} + a_{22} b_{21}) \\ 
            = & \cancel{a_{11} a_{21} b_{11} b_{12}} + a_{11} a_{22} b_{11} b_{22} + a_{12} a_{21} b_{12} b_{21} + \bcancel{a_{12} a_{22} b_{21} b_{22}} \\ 
            - & \cancel{a_{11} a_{21} b_{11} b_{12}} - a_{11} a_{22} b_{12} b_{21} - a_{12} a_{21} b_{11} b_{22} - \bcancel{a_{12} a_{22} b_{21} b_{22}}.

Tương tự,

.. math:: \det (A) \det (B) = & (a_{11} a_{22} - a_{12} a_{21}) (b_{11} b_{22} - b_{12} b_{21}) \\ = & a_{11} a_{22} b_{11} b_{22} - a_{11} a_{22} b_{12} b_{21} \\ - & a_{12} a_{21} b_{11} b_{22} + a_{12} a_{21} b_{12} b_{21}.

Như vậy :math:`\det (AB) = \det (A) \det (B)` và do đó ánh xạ :math:`\det` từ :math:`GL_2(\mathbb{R})` tới :math:`\mathbb{R}^*` là homomorphism.

.. admonition::  Bài 4

    Xét :math:`\phi : \mathbb{Z} \to \mathbb{Z}` cho bởi :math:`\phi(n) = 7n`. Chứng minh rằng :math:`\phi` là homomorphism. Tìm hạt nhân và ảnh của :math:`\phi`.

Ta có

.. math:: \phi(a+b) = 7(a+b) = 7a + 7b = \phi(a) + \phi(b)

với mọi :math:`a, b \in \mathbb{Z}`. Do đó :math:`\phi` là homomorphism. 
    
Hạt nhân của :math:`\phi` là tập hợp các số :math:`n` để :math:`\phi(n) = 0`, hay :math:`7 n = 0`. Như vậy :math:`n=0` nên :math:`\ker \phi = \{ 0 \}`.

Ảnh của :math:`\phi` là tập :math:`\{ \ldots, -2 \cdot 7, -7, 0, 7, 2 \cdot 7, \ldots \}`.

.. admonition::  Bài 8

    Nếu :math:`G` là nhóm Abel và :math:`n \in \mathbb{N}`, chứng minh rằng :math:`\phi : G \to G` xác định bởi :math:`g \mapsto g^n` là homomorphism.

Với mọi :math:`g, h \in G` thì :math:`\phi(gh) = (gh)^n`. Do :math:`G` là nhóm Abel nên ta có :math:`(gh)^n = g^n h^n = \phi(g) \phi(h)`. Như vậy :math:`\phi` là đồng cấu nhóm.

.. admonition::  Bài 9

    Nếu :math:`\phi : G \to H` là homomorphism và :math:`G` là nhóm Abel, chứng minh rằng :math:`\phi(G)` cũng là nhóm Abel.

Với mọi :math:`g, h \in G`, do :math:`\phi` là homomorphism nên :math:`\phi(gh) = \phi(g) \phi(h)`. Do :math:`G` là nhóm Abel nên :math:`gh = hg` với mọi :math:`g, h \in G`, suy ra :math:`\phi(gh) = \phi(hg)`. Tương đương với :math:`\phi(g) \phi(h) = \phi(h) \phi(g)` nên :math:`\phi(G)` cũng là nhóm Abel.

.. admonition::  Bài 10

    Nếu :math:`\phi : G \to H` là homomorphism và :math:`G` là nhóm cyclic, chứng minh rằng :math:`\phi(G)` cũng là nhóm cyclic.

Nếu :math:`G = \langle g \rangle` thì mọi phần tử của :math:`G` có dạng :math:`g^k`, và :math:`\phi(g^k) = \phi(g)^k`. Do đó :math:`\phi(G) = \langle \phi(g) \rangle` là nhóm cyclic.

.. admonition::  Bài 20

    Cho homomorphism :math:`\phi : G \to H` và định nghĩa quan hệ :math:`\sim` trên :math:`G` theo quy tắc :math:`a, b \in G` có quan hệ với nhau nếu :math:`\phi(a) = \phi(b)` và kí hiệu là :math:`a \sim b`. Chứng minh đây là quan hệ tương đương và mô tả cách xây dựng các lớp tương đương.

Do :math:`\phi` là ánh xạ nên :math:`\phi(a) = \phi(a)` với mọi :math:`a \in G`, suy ra :math:`\sim` có tính phản xạ.

Nếu :math:`a \sim b` thì :math:`\phi(a) = \phi(b)`. Tương đương với :math:`\phi(b) = \phi(a)` nên :math:`b \sim a`. Như vậy quan hệ trên có tính đối xứng.

Nếu :math:`a \sim b` thì :math:`\phi(a) = \phi(b)`, và nếu :math:`b \sim c` thì :math:`\phi(b) = \phi(c)`. Suy ra :math:`\phi(a) = \phi(b) = \phi(c)` nên :math:`a \sim c`. Như vậy quan hệ có tính bắc cầu.

Kết luận: quan hệ :math:`\sim` xác định như trên là quan hệ tương đương.

Các lớp tương đương ứng một-một với các phần tử của ảnh :math:`\phi(G) \subseteq H`: với mỗi :math:`y \in \phi(G)`, lớp tương ứng là

.. math:: \phi^{-1}(y) = \{ g \in G : \phi(g) = y \}.

Hơn nữa :math:`\phi(a) = \phi(b)` khi và chỉ khi :math:`\phi(a^{-1} b) = e`, tức :math:`a^{-1} b \in \ker \phi`. Do đó lớp tương đương chứa :math:`a` chính là coset :math:`a \ker \phi`.
