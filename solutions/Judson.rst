Abstract Algebra: Theory and Applications
*****************************************

Lời giải cho quyển sách **Abstract Algebra: Theory and Applications** của Thomas W. Judson :cite:`Judson2012`.

Chương 3. Groups
================

.. admonition::  Bài 7
    
    Đặt :math:`S = \mathbb{R} \setminus \{-1\}` và định nghĩa toán tử hai ngôi trên :math:`S` là :math:`a \star b = a + b + ab`. Chứng minh rằng :math:`(S, \star)` là nhóm Abel.

Để chứng minh :math:`(S, \star)` là nhóm ta chứng minh ba tiên đề của nhóm.

1. Giả sử tồn tại phần tử đơn vị :math:`e`, khi đó :math:`e \star s = s \star e = s` với mọi :math:`s \in S`. Nghĩa là :math:`e + s + es = s + e + se = s`. Vậy :math:`e + se = 0` mà :math:`s \neq -1` nên :math:`e = 0`
2. Với :math:`e = 0`, giả sử với mọi :math:`s \in S` có nghịch đảo :math:`s'`. Do :math:`s \star s' = s' \star s = e` nên :math:`s + s' + ss' = s' + s + s's = e = 0`, tức là :math:`s'(1 + s) = -s`. Vậy :math:`s' = \dfrac{-s}{1 + s}`
3. Với mọi :math:`a, b, c \in S`, 

   .. math:: 

       a \star (b \star c) & = a \star (b + c + bc) = a + (b+c+bc) + a (b+c+bc) \\ 
       & = a + b + c + ab + bc + ca + abc

   và

   .. math:: 

       (a \star b) \star c & = (a + b + ab) \star c = a + b + ab + c + c(a+b+bc) \\
        & = a + b + c + ab + bc + ca + abc.

Như vậy :math:`a \star (b \star c) = (a \star b) \star c`, do đó :math:`\star` có tính kết hợp.

Vậy :math:`(S, \star)` là nhóm.

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

suy ra định thức của tích hai ma trận là

.. math:: 

    \det \left(\begin{pmatrix}
        \cos (\theta_1 + \theta_2) & -\sin (\theta_1 + \theta_2) \\
        \sin (\theta_1 + \theta_2) & \cos (\theta_1 + \theta_2)
    \end{pmatrix}\right)
    = & 1 \cdot 1 = 1.

Như vậy phép nhân hai ma trận có dạng trên đóng trên :math:`SL_2 (\mathbb{R})`.

Phần tử đơn vị là :math:`\begin{pmatrix} 1 & 0 \\ 0 & 1 \end{pmatrix}` tương ứng với :math:`\theta = 0`.

Phần tử nghịch đảo là :math:`\begin{pmatrix} \cos (-\theta) & -\sin (-\theta) \\ \sin (-\theta) & \cos (-\theta) \end{pmatrix}` suy ra từ công thức định thức ban nãy.

Cuối cùng, phép nhân ma trận có tính kết hợp. Như vậy :math:`G` là subgroup của :math:`SL_2 (\mathbb{R})`.      

.. admonition::  Bài 47

    Đặt :math:`G` là nhóm và :math:`g \in G`. Chứng minh rằng

    .. math:: Z(G) = \{ x \in G: gx = xg \; \forall \; g \in G \}

    là subgroup của :math:`G`. Subgroup này gọi là **center** của :math:`G`.

Giả sử trong :math:`G` có hai phần tử là :math:`x_1` và :math:`x_2` thuộc :math:`Z(G)`. Khi đó

.. math:: x_1 g = g x_1 \text{ và } x_2 g = g x_2 \text{ với mọi } g \in G.

Xét phần tử :math:`x_1 x_2`, ta có

.. math:: (x_1 x_2) g = x_1 (x_2 g) = x_1 (g x_2) = (g x_1) x_2 = g (x_1 x_2)

với mọi :math:`g \in G`. Do đó :math:`x_1 x_2 \in Z(G)` nên :math:`Z(G)` là subgroup.

.. admonition::  Bài 49

    Cho ví dụ về nhóm vô hạn mà mọi nhóm con không tầm thường của nó đều vô hạn.

Ví dụ tập :math:`\mathbb{Z}` và phép cộng số nguyên. Khi đó mọi nhóm con của :math:`\mathbb{Z}` có dạng :math:`n\mathbb{Z}` với :math:`n \in \mathbb{Z}`. Ví dụ

* :math:`2\mathbb{Z} = \{\cdots, -4, -2, 0, 2, 4, \cdots\}` với phần tử sinh là :math:`2`;
* :math:`n\mathbb{Z} = \{\cdots, -2n, -n, 0, n, 2n, \cdots\}` với phần tử sinh là :math:`n`.

.. admonition::  Bài 54

    Cho :math:`H` là subgroup của :math:`G` và

    .. math:: C(H) = \{g \in G: gh = hg \; \forall \; h \in H\}.

    Chứng minh rằng :math:`C(H)` là subgroup của :math:`G`. Subgroup này được gọi là **centralizer** của :math:`H` trong :math:`G`.

Gọi :math:`g_1` và :math:`g_2` thuộc :math:`C(H)`. Khi đó :math:`g_1 h = h g_1` và :math:`g_2 h = h g_2` với mọi :math:`h \in H`.

Xét phần tử :math:`g_1 g_2`, với mọi :math:`h \in H` ta có

.. math:: (g_1 g_2) h = g_1 (g_2 h) = g_1 (h g_2) = (g_1 h) g_2 = (h g_1) g_2 = h (g_1 g_2).

Như vậy :math:`g_1 g_2 \in C(H)`, từ đó :math:`C(H)` là subgroup của :math:`G`

Chương 5. Permutation Groups
============================

.. admonition::  Bài 13

    Đặt :math:`\sigma = \sigma_1 \cdots \sigma_m \in S_n` là tích của các cycle độc lập. Chứng minh rằng order của :math:`\sigma` là LCM của độ dài các cycle :math:`\sigma_1, \cdots, \sigma_m`.

Đặt :math:`l_i` là độ dài cycle :math:`\sigma_i` (:math:`i = 1, \cdots m`). Khi đó :math:`\sigma_i^{k_i l_i}` sẽ ở dạng các cycle độ dài :math:`1` (:math:`k_i \in \mathbb{Z}`).

Từ đó, :math:`\sigma^l = \sigma_1^l \cdots \sigma_m^l = (1)\cdots(n)` nếu :math:`l = k_1 l_1 = \cdots k_m l_m`. Số :math:`l` nhỏ nhất thỏa mãn điều kiện này là :math:`\text{lcm} (l_1, \cdots, l_m)` (đpcm).

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

1. Ta thấy rằng bất kì phần tử nào khác :math:`a_1, a_2, \cdots, a_k` thì khi qua :math:`\tau` không đổi, do đó khi đi qua :math:`\sigma \tau \sigma^{-1}` thì chỉ đi qua :math:`\sigma \sigma^{-1}` và cũng không đổi. Nói cách khác các phần tử :math:`a_1, a_2, \cdots, a_k` vẫn nằm trong chu trình nên ta có đpcm.
2. Từ câu (a), với :math:`\mu = (b_1, b_2, \cdots, b_k)` thì ta chọn :math:`\sigma` sao cho :math:`b_i = \sigma(a_i)`.

Chương 6. Cosets
================

.. admonition::  Bài 11

    Gọi :math:`H` là subgroup của nhóm :math:`G` và giả sử :math:`g_1, g_2 \in G`. Chứng minh các mệnh đề sau là tương đương:

    1. :math:`g_1 H = g_2 H`
    2. :math:`H g_1^{-1} = H g_2^{-1}`
    3. :math:`g_1 H \subseteq g_2 H`
    4. :math:`g_2 \in g_1 H`
    5. :math:`g_1^{-1} g_2 \in H` 


Từ (1) ra (2): Ta đã biết các coset là rời nhau hoặc trùng nhau, do đó với mọi :math:`g_1 h \in g_1 H`, tồn tại :math:`g_2 h' \in g_2 H` mà :math:`g_1 h = g_2 h'`, suy ra :math:`(g_1 h)^{-1} = (g_2 h')^{-1}` hay :math:`h^{-1} g_1^{-1} = h'^{_1} g_2^{-1}` (đpcm).

Từ (1) ra (3): Hiển nhiên.

Từ (1) ra (4): Với mọi :math:`g_1 h \in g_1 H`, tồn tại :math:`g_2 h' \in g_2 H` sao cho :math:`g_1 h = g_2 h'`, hay :math:`g_2 = g_1 h h'^{-1}`, đặt :math:`h'' = h h'^{-1}` thì :math:`h'' \in H` (:math:`H` là nhóm con) nên :math:`g_1 h'' \in g_1 H`, suy ra :math:`g_2 \in g_1 H`.

Từ (1) ra (5): Tương tự, ta có :math:`g_1 h = g_2 h'`, suy ra :math:`h h'^{-1}= g_1^{-1} g_2 \in H`.

.. admonition::  Bài 16

    Nếu :math:`g h g^{-1} \in H` với mọi :math:`g \in G` và :math:`h \in H`, chứng minh rằng right coset trùng với left coset.

Do :math:`g h g^{-1} \in H` nên tồn tại :math:`h' \in H` sao cho :math:`g h g^{-1} = h'`. Tương đương :math:`g h = h' g` với mọi :math:`h \in H` nên :math:`g H = H g`. Điều này đúng với mọi :math:`g \in G` nên các right coset trùng left coset.

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

Xét ánh xạ :math:`\varphi: \mathbb{Q}^* \rightarrow \mathbb{Z~} \times \mathbb{Z}`, :math:`\varphi(2^m 3^n) = (m, n)`.

Hàm này là well-defined vì với :math:`m` cố định thì mỗi phần tử :math:`2^m 3^n` chỉ cho ra một phần tử :math:`(m, n)`. Tương tự với cố định :math:`n`.

Hàm này là đơn ánh (one-to-one) vì với :math:`m_1 = m_2` và :math:`n_1 = n_2` thì :math:`2^{m_1} 3^{n_1} = 2^{m_2} 3^{n_2}`.

Hàm này cũng là toàn ánh vì với mỗi cặp :math:`(m, n)` ta đều tính được :math:`2^m 3^n`.

Vậy hàm :math:`\varphi` là song ánh.

Thêm nữa,

.. math:: 

    \varphi(2^{m_1} 3^{n_1} \cdot 2^{m_2} 3^{n_2})& = \varphi(2^{m_1 + m_2} 3^{n_1 + n_2}) \\
    & = (m_1 + m_2, n_1 + n_2) = (m_1, n_1) + (m_2, n_2) \\
    & = \varphi(2^{m_1} 3^{n_1}) \varphi(2^{m_2} 3^{n_2}).

Vậy :math:`\varphi` là homomorphism, và là song ánh nên là isomorphism.

.. admonition::  Bài 20

    Chứng minh hoặc bác bỏ: mọi nhóm Abel có order chia hết bởi :math:`3` chứa một subgroup có order là :math:`3`.

Gọi order của nhóm Abel là :math:`n = 3k`, và :math:`g` là phần tử sinh của nhóm Abel đó. Như vậy :math:`g^n = g^{3k} = e`.

Nếu ta chọn :math:`h = g^k` thì :math:`h^3 = e`, khi đó subgroup được sinh bởi :math:`h` có order :math:`3` (đpcm).

.. admonition::  Bài 21

    Chứng minh hoặc bác bỏ: mọi nhóm không phải Abel có order chia hết bởi :math:`6` chứa một subgroup có order :math:`6`.

Với :math:`\mathcal{S}_3` có order là :math:`6` nhưng không có nhóm con nào order :math:`6` (nhóm con chỉ có order :math:`1`, :math:`2` hoặc :math:`3`) (bác bỏ).

.. admonition::  Bài 22

    Gọi :math:`G` là group với order :math:`20`. Nếu :math:`G` có các subgroup :math:`H` và :math:`K` với order :math:`4` và :math:`5` mà :math:`hk = kh` với mọi :math:`h \in H` và :math:`k \in K`, chứng minh rằng

Ta chứng minh :math:`H \cap K = \{ e \}`. Giả sử tồn tại phần tử :math:`m \in H \cap K`, khi đó do :math:`m \in H` nên :math:`mk = km` với mọi :math:`k \in K`. Tuy nhiên :math:`m \in K` do đó điều này xảy ra khi và chỉ khi :math:`m = e`.

Như vậy :math:`H \cap K = \{ e \}`.

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

Tương tự câu 9.

.. admonition::  Bài 20

    Cho homomorphism :math:`\phi : G \to H` và định nghĩa quan hệ :math:`\sim` trên :math:`G` theo quy tắc :math:`a, b \in G` có quan hệ với nhau nếu :math:`\phi(a) = \phi(b)` và kí hiệu là :math:`a \sim b`. Chứng minh đây là quan hệ tương đương và mô tả cách xây dựng các lớp tương đương.

Do :math:`\phi` là ánh xạ nên :math:`\phi(a) = \phi(a)` với mọi :math:`a \in G`, suy ra :math:`\sim` có tính phản xạ.

Nếu :math:`a \sim b` thì :math:`\phi(a) = \phi(b)`. Tương đương với :math:`\phi(b) = \phi(a)` nên :math:`b \sim a`. Như vậy quan hệ trên có tính đối xứng.

Nếu :math:`a \sim b` thì :math:`\phi(a) = \phi(b)`, và nếu :math:`b \sim c` thì :math:`\phi(b) = \phi(c)`. Suy ra :math:`\phi(a) = \phi(b) = \phi(c)` nên :math:`a \sim c`. Như vậy quan hệ có tính bắc cầu.

Kết luận: quan hệ :math:`\sim` xác định như trên là quan hệ tương đương.

Để xây dựng các lớp tương đương, đặt :math:`I = \{ i_1, i_2, \ldots, i_m \}` là ảnh của homomorphism :math:`\phi`. Rõ ràng :math:`I \subset H`. Khi đó các lớp tương đương ứng với các phần tử :math:`i_1, i_2, \ldots, i_m`, hay

.. math:: \bar{i}_j = \{ g \in G : \phi(g) = i_j \}, \quad 1 \leqslant i \leqslant m.
