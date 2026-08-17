Chapter 2. Discrete Logarithms and Diffie-Hellman
=================================================

.. admonition:: Câu 2.3

    Let :math:`g` be a primitive root of :math:`\mathbb{F}_p`.

    (a) Suppose that :math:`x = a` and :math:`x = b` are both integer solutions to the congruence :math:`g^x \equiv h` (mod :math:`p`). Prove that :math:`a \equiv b` (mod :math:`p-1`). Explain why this implies that the map (2.1) on page 64 is well-defined

    (b) Prove that :math:`\log_g(h_1 h_2) = \log_g(h_1) + \log_g(h_2)` for all :math:`h_1, h_2 \in \mathbb{F}^*_p`

    (c) Prove that :math:`\log_g(h^n) = n\log_g(h)` for all :math:`h \in \mathbb{F}^{*}_p` and :math:`n \in \mathbb{Z}`

Các tính chất cơ bản của hàm Euler.

(a) Cả :math:`a` and :math:`b` là nghiệm của đồng dư :math:`g^x \equiv h` (mod :math:`p`) nên :math:`g^a \equiv h \pmod p` và :math:`g^b \equiv h \pmod p`.

Suy ra ta có :math:`g^{-b} \equiv h^{-1} \pmod p`.

Ta nhân kết quả với đồng dư đầu thì được :math:`g^a g^{-b} \equiv h h^{-1} \equiv 1 \pmod p`, hay :math:`g^{a-b} \equiv 1 \pmod p`.

Do :math:`g` là primitive root of :math:`\mathbb{F}_p` tên ta có :math:`\phi(p) \mid (a-b)`, tương đương với :math:`(p-1) \mid (a-b)`.

Như vậy :math:`a - b \equiv 0 \pmod{p-1}` hay :math:`a \equiv b \pmod {p-1}` (đpcm).

(b) Giả sử :math:`h_1 \equiv g^{x_1} \pmod p` và :math:`h_2 \equiv g^{x_2} \pmod p`.

Suy ra :math:`x_1 = \log_g h_1` và :math:`x_2 = \log_g h_2` (1).

Do :math:`h_1 h_2 \equiv g^{x_1 + x_2} \pmod p` nên :math:`x_1 + x_2 = \log_g(h_1 h_2)` (2).

Từ (1) và (2), :math:`\log_g h_1 + \log_g h_2 = \log_g (h_1 h_2)`.

(c) tương tự (b).

.. admonition:: Câu 2.5

    Let :math:`p` be an odd prime and let :math:`g` be a primitive root modulo :math:`p`.

    Prove that :math:`a` has a square root modulo :math:`p` if and only if its discrete logarithm :math:`\log_g(a)` modulo :math:`p-1` is even.

Ta có :math:`g^{p-1} \equiv 1 \pmod p` do :math:`g` là primitive root modulo :math:`p`.

**Điều kiện đủ.** Nếu  :math:`a` là số chính phương modulo :math:`p` thì tồn tại số :math:`b` sao cho :math:`b \equiv a^2 \pmod p`, suy ra

.. math:: \log_g a = \log_g(b^2) = 2 \log_g b \pmod{p-1},

như vậy :math:`\log_ga` chẵn.

**Điều kiện cần.** Nếu :math:`\log_g a` modulo :math:`p-1` chẵn.

Điều này xảy ra khi

.. math:: \log_ga = 2\log_g b \pmod{p-1}

với số :math:`b \in \mathbb{F}_p` nào đó, suy ra

.. math:: \log_ga = \log_g (b^2) \pmod{p-1},

hay :math:`a \equiv b^2 \pmod{p-1}`.

Như vậy :math:`a` có căn bậc hai modulo :math:`p-1`.

.. admonition:: Câu 2.10

    The exercise describes a public key cryptosystem that requires Bob and Alice to exchange several messages. We illustrate the system with an example.

    Bob and Alice fix a publicly known prime :math:`p=32611`, and all of other numbers used are private.

    Alice takes her message :math:`m=11111`, chooses a random exponent :math:`a=3589`, and sends the number :math:`u=m^a` (mod :math:`p`) :math:`=15950` to Bob.

    Bob chooses a random exponent :math:`b=4037` and sends :math:`v=u^b` (mod :math:`p`) :math:`=15422` back to Alice.

    Alice then computes :math:`w=v^{15619} \equiv 27257` (mod :math:`32611`) and sends :math:`w=27257` to Bob.

    Finally, Bob computes :math:`w^{31883}` (mod :math:`32611`) and recovers the value :math:`11111` of Alice's message.

    (a) Explain why this algorithm works. In particular, Alice uses the numbers :math:`a=3589` and 15619 as exponents. How are they related? Similarly, how are Bob's exponents :math:`b=4037` and 31883 related?

    (b) Formulate a general version of this cryptosystem, i.e., using variables, and show how it works in general.

    (c) What is the disadvantage of this cryptosystem over Elgamal? (*Hint.* How many times must Alice and Bob exchange data?)

    (d) Are there any advantages of this cryptosystem over Elgamal? In particular, can Eve break it if she can solve the discrete logarithm problem? Can Eve break it if she can solve the Diffie-Hellman problem?

(a) Ta có

.. math:: 3589 \cdot 15619 \equiv 4073 \cdot 31883 \equiv 1 \pmod{p-1}.

(b) Alice chọn :math:`a` và :math:`a'` sao cho :math:`aa' \equiv 1 \pmod{p-1}`.

Tương tự, Bob chọn :math:`b` và :math:`b'` sao cho :math:`bb' \equiv 1 \pmod{p-1}`.

Do đó ta có :math:`aa' = k(p-1)+1` và :math:`bb' = l(p-1) + 1`.

.. math::

    & \Rightarrow v \equiv u^b \equiv (m^a)^b \equiv m^{ab} \pmod p \\
    & \Rightarrow w \equiv v^{a'} \equiv (m^{ab})^{a'} \equiv m^{aa'b} \pmod p \\
    & \Rightarrow w^{b'} \equiv m^{aa'bb'} \equiv m^{[k(p-1)+1]x[l(p-1)+1]} \equiv m^{D(p-1)+1} \equiv m \pmod p.

.. admonition:: Câu 2.11

    The group :math:`S_3` consists of the following six distinct elements

    .. math:: e, \sigma, \sigma^2, \tau, \sigma\tau, \sigma^2\tau

    where :math:`e` is the identity element and multiplication is performed using the rules

    .. math:: \sigma^3 = e, \quad \tau^2 = e, \quad \tau\sigma = \sigma^2\tau

    Compute the following values in the group :math:`S_3`:

    (a)  :math:`\tau\sigma^2`

    (b)  :math:`\tau(\sigma\tau)`

    (c)  :math:`(\sigma\tau)(\sigma\tau)`

    (d)  :math:`(\sigma\tau)(\sigma^2\tau)`

    Is :math:`S_3` a commutative group?

(a)

.. math:: \tau\sigma^2 = \tau\sigma\sigma = \sigma^2\tau\sigma = \sigma\sigma^2\tau = \sigma^3\tau = e\tau = \tau.

(b)

.. math:: \tau(\sigma\tau)=(\tau\sigma)\tau = \sigma^2\tau\tau = \sigma^2\tau^2 = \sigma^2e = \sigma^2.

(c)

.. math:: (\sigma\tau)(\sigma\tau) = \sigma(\tau\sigma)\tau = \sigma(\sigma^2\tau)\tau = \sigma^3\tau^2 = ee = e.

(d)

.. math:: (\sigma\tau)(\sigma^2\tau) = (\sigma\tau)(\tau\sigma) = \sigma\tau^2\sigma=\sigma e \sigma = \sigma^2.

:math:`S_3` không là nhóm giao hoán vì:

.. math:: \sigma\tau = \sigma\tau, \quad \tau\sigma = \sigma^2\tau,

đây là hai phần tử phân biệt trong :math:`S_3`.

.. admonition:: Câu 2.12

    Let :math:`G` be a group, let :math:`d \geqslant 1` be an integer, and define a subset of :math:`G` by

    .. math:: G[d] = \{g \in G: g^d = e\}

    (a) Prove that if :math:`g` is in :math:`G[d]`, then :math:`g^{-1}` is in :math:`G[d]`

    (b) Suppose that :math:`G` is commutative. Prove that is :math:`g_1` and :math:`g_2` are in :math:`G[d]`, then their product :math:`g_1 \star g_2` is in :math:`G[d]`

    (c) Deduce that if :math:`G` is commutative, then :math:`G[d]` is a group.

    (d) Show by an example that is :math:`G` is not a commutative group, then :math:`G[d]` need not be a group. (*Hint.* Use Exercise 2.11.)

(a) Vì :math:`g \star g^{-1} = e` nên

.. math::

    & g \star e \star g^{-1} = e \\
    \Rightarrow & g \star g \star g^{-1} \star g^{-1} = e \\
    \Rightarrow & g^2 \star (g^{-1})^2 = e.

Thực hiện thêm :math:`d-2` lần nữa và ta nhận được

.. math::

    & g^d \star (g^{-1})^d = e \\
    \Rightarrow & e \star (g^{-1})^2 = e \\
    \Rightarrow & (g^{-1})^2 = e \\
    \Rightarrow & g^{-1} \in G[d]

(b) Ta có :math:`g_1^d = e` and :math:`g_2^d = e`.

Do :math:`G` là nhóm hoán vị nên :math:`g_1^d \star g_2^d = (g_1 \star g_2)^d`, suy ra :math:`(g_1 \star g_2)^d = e \star e = e`.

Như vậy :math:`g_1 \star g_2 \in G[d]`.

(c) Từ câu (b), ta có với mọi :math:`g_1, g_2 \in G[d]`, thì :math:`g_1 \star g_2 \in G[d]`.

Do :math:`e` là phần tử đơn vị của :math:`G` nên cũng là phần tử đơn vị của :math:`G[d]`.

Từ câu (a) ta chứng minh được sự tồn tại của phần tử nghịch đảo.

Với :math:`a, b, c \in G[d]` thì :math:`a^d = b^d = c^d = e`.

Ta có :math:`b^d \star c^d = (b \star c)^d` do tính giao hoán, suy ra

.. math::

    a^d \star (b^d \star c^d) & = a^d \star (b \star c)^d = (a \star b \star c)^d \\
    & = (a \star b)^d \star c^d = (a^d \star b^d) \star c^d.

Như vậy ta chứng minh được tính kết hợp. Và từ đó :math:`G[d]` là nhóm.

(d) Sử dụng kết quả câu 2.11

.. math:: S_3[2] = \{\tau, \sigma\tau, \sigma^2, \tau, e \}.

Vì

.. math:: (\sigma\tau)\tau = \sigma\tau^2 = \sigma \notin S_3[2]

nên :math:`S_3[2]` không là nhóm.

.. admonition:: Câu 2.13

    Let :math:`G` and :math:`H` be groups. A function :math:`\phi: G \rightarrow H` is called a (*group*) *homomorphism* if it satisfies

    .. math:: \phi(g_1 \star g_2) = \phi(g_1) \star \phi(g_2) \quad \text{for all} \ g_1, g_2 \in G

    (Note that the product :math:`g_1 \star g_2` uses the group law in the group :math:`G`, while the product :math:`\phi(g_1) \star \phi(g_2)` uses the group law in the group :math:`H`.)

    (a) Let :math:`e_G` be the identity element of :math:`G`, let :math:`e_H` be identity element of :math:`H`, and the :math:`g \in G`. Prove that

    .. math:: \phi(e_G) = e_H \quad\quad \text{and} \quad\quad \phi(g^{-1}) = \phi(g)^{-1}

    (b) Let :math:`G` be a commutative group. Prove that the map :math:`\phi: G \rightarrow G` defined by :math:`\phi(g)=g^2` is a homomorphism. Give an example of a noncommutative group for which this map is not a homomorphism.

    (c) Same question as (b) for the map :math:`\phi(g)=g^{-1}`.


(a) Với mọi :math:`g \in G` thì :math:`g = g \star e = e \star g`. Suy ra

.. math::

    & \phi(g) = \phi(g \star e_G) = \phi(e_G \star g) \\
    \Longleftrightarrow \ & \phi(g) = \phi(g) \star \phi(e_G) = \phi(e_G) \star \phi(g)

Do :math:`\phi(g) \in H`, :math:`\phi(e_G)` là phần tử đơn vị của :math:`H`, nói cách khác là :math:`\phi(e_G) = e_H`.

Trong nhóm :math:`G`, :math:`g \star g^{-1} = e_G`. Suy ra

.. math::

    & \phi(g \star g^{-1}) = \phi(e_G) \\
    \Longleftrightarrow \ & \phi(g) \star \phi(g^{-1}) = \phi(e_G) \\
    \Longleftrightarrow \ & \phi(g) \star \phi(g^{-1}) = e_H \\
    \Longleftrightarrow \ & \phi(g^{-1}) = \phi(g)^{-1}

(b) :math:`\phi: G \rightarrow G`, :math:`\phi(g) = g^2`. Với mọi :math:`g_1, g_2 \in G`, do :math:`G` là nhóm giao hoán nên

.. math:: \phi(g_1 \star g_2) = (g_1 \star g_2)^2 = g_1^2 \star g_2^2

Ta có :math:`g_1^2 \star g_2^2 = \phi(g_1) \star \phi(g_2)` nên :math:`\phi(g_1 \star g_2) = \phi(g_1) \star \phi(g_2)`. Như vậy :math:`G` là homomorphism.

Xét nhóm ở Câu 2.11 và ánh xạ :math:`\phi: G \rightarrow G`, :math:`\phi(g)=g^2`.

Khi đó

.. math::

    \phi(e) = e^2 = e, & \quad \phi(\sigma) = \sigma^2, \\
    \phi(\tau) = \tau^2 = e, & \quad \phi(\sigma\tau) = (\sigma\tau)^2 = e.

Vì

.. math:: \phi(\sigma\tau) = e \neq \sigma^2 = \phi(\sigma)\phi(\tau),

nên :math:`G` không là homomorphism.

(c) :math:`\phi: G \rightarrow G`, :math:`\phi(g) = g^{-1}`.

Với mọi :math:`g_1, g_2 \in G` thì :math:`g_1 g_1^{-1} = e` và :math:`g_2 g_2^{-1} = e`

Do đó :math:`g_1 g_1^{-1} g_2 g_2^{-1} = e`, mà :math:`G` là nhóm hoán vị nên :math:`(g_1 g_2)(g_1^{-1} g_2^{-1}) = e`, tương đương với :math:`g_1^{-1} g_2^{-1} = (g_1 g_2)^{-1}`. Như vậy

.. math:: \phi(g_1 g_2) = (g_1 g_2)^{-1} = g_1^{-1} g_2^{-1} = \phi(g_1) \phi(g_2)

Kết luận: :math:`G` là homomorphism.

Xét nhóm ở Câu 2.11 và ánh xạ :math:`\phi: G \rightarrow G`, :math:`\phi(g) = g^{-1}`. Ta có

.. math::

    \sigma\sigma^2 = e = \sigma^2\sigma = e, \quad \tau^2 = e, \quad (\sigma\tau)^2 = e, \quad (\sigma^2\tau)^2 = e,

suy ra

.. math:: \phi(\sigma\tau) = \sigma\tau, \quad \phi(\sigma) = \sigma^2, \quad \phi(\tau) = \tau

Vì :math:`\phi(\sigma\tau) = \sigma\tau \neq \sigma^2\tau = \phi(\sigma)\phi(\tau)` nên :math:`G` không là homomorphism.

.. admonition:: Câu 2.14

    Prove that each of the following maps is a group homomophism.

    (a) The map :math:`\phi: \mathbb{Z} \rightarrow \mathbb{Z}/N\mathbb{Z}` that sends :math:`a \in Z` to :math:`a` mod :math:`N` in :math:`\mathbb{Z}/N\mathbb{Z}`.

    (b) The map :math:`\phi: \mathbb{R}^* \to GL_2(\mathbb{R})` defined by :math:`\phi(a) = \begin{pmatrix}a & 0 \\ 0 & a^{-1}\end{pmatrix}`.

    (c) The discrete logarithm map :math:`\log_g: \mathbb{F}_p^* \rightarrow \mathbb{Z}/(p-1)\mathbb{Z}`, where :math:`g` is a primitive root modulo :math:`p`.

(a) Với mọi :math:`a, b \in \mathbb{Z}`,

.. math::

    \phi(ab) & = (ab) \pmod N \\
    & = (a \bmod N) \ (b \bmod N) \pmod N \\
    & = \phi(a) \phi(b) \\

Do đó :math:`\phi` là homomorphism.

(b) Với mọi :math:`a, b \in \mathbb{R}^*` thì

.. math:: \phi(ab)=\begin{pmatrix}ab & 0 \\ 0 & (ab)^{-1}\end{pmatrix}

Ta có

.. math::

    \phi(a)\phi(b) = \begin{pmatrix}a & 0 \\ 0 & a^{-1}\end{pmatrix}
    \begin{pmatrix}b & 0 \\ 0 & b^{-1}\end{pmatrix} =
    \begin{pmatrix}ab & 0 \\ 0 & a^{-1}b^{-1}\end{pmatrix}

Trong :math:`\mathbb{R}^*` ta có tính chất :math:`(ab)^{-1} = a^{-1}b^{-1}`, do đó :math:`\phi(ab) = \phi(a)\phi(b)`. Suy ra :math:`\phi` là homomorphism.

(c) Ta chọn ánh xạ :math:`\phi(a) = x` thỏa mãn :math:`g^x \equiv a \pmod p`.

Khi đó, với mọi :math:`a, b \in \mathbb{F}_p^*`, :math:`\phi(a) = x`, hay :math:`g^x \equiv a \pmod p`, và :math:`\phi(b) = y`, hay :math:`g^y \equiv b \pmod p`.

Ta có :math:`\phi(a) \phi(b) = x+y` vì :math:`x`, :math:`y \in \mathbb{Z}/(p-1)\mathbb{Z}`, đây là phép cộng trong modulo :math:`p-1`.

Ta lại có :math:`g^{x+y} \equiv ab \pmod p`, suy ra :math:`\phi(ab) = x + y`. Như vậy :math:`\phi(a)\phi(b) = \phi(ab)` và :math:`\phi` là homomorphism.

.. admonition:: Câu 2.15

    (a) Prove that :math:`\mathrm{GL}_2(\mathbb{F}_p)` is a group.

    (b) Show that :math:`\mathrm{GL}_2(\mathbb{F}_p)` is a noncommutative group for every prime :math:`p`.

    (c) Describe :math:`\mathrm{GL}_2(\mathbb{F}_p)` completely. That is, list its elements and describe the multiplication table.

    (d) How many elements are there in the group :math:`\mathrm{GL}_2(\mathbb{F}_p)`?

    (e) How many elements are there in the group :math:`\mathrm{GL}_n(\mathbb{F}_p)`?

(a) Nếu :math:`A` và :math:`B` là hai ma trận thuộc :math:`\mathrm{GL}_2(\mathbb{F}_p)` thì :math:`AB` cũng thuộc :math:`GL_2(\mathbb{F}_p)` do :math:`\det(AB) = \det(A) \cdot \det(B)` khác :math:`0`.

Phần tử đơn vị là :math:`E = \begin{pmatrix} 1 & 0 \\ 0 & 1 \end{pmatrix}`.

Với mọi :math:`A \in GL_2(\mathbb{F}_p)`, do :math:`\det A \neq 0` nên luôn tồn tại nghịch đảo của :math:`A` trong :math:`GL_2(\mathbb{F}_p)`.

Với mọi :math:`A, B, C \in GL_2(\mathbb{F}_p)` ta đều có :math:`(AB)C=A(BC)` vì phép nhân ma trận có tính kết hợp.

Kết luận: :math:`GL_2(\mathbb{F}_p)` là nhóm.

Giả sử ta có :math:`A = \begin{pmatrix}a_{11} & a_{12} \\ a_{21} & a_{22}\end{pmatrix}` và :math:`B=\begin{pmatrix}b_{11} & b_{12} \\ b_{21} & b_{22}\end{pmatrix}` với :math:`A, B \in GL_2(\mathbb{F}_p)`.

Phần tử ở hàng :math:`1` và cột :math:`1` của tích :math:`AB` là :math:`(a_{11}b_{11}+a_{12}b_{21}) \pmod p`.

Phần tử ở hàng :math:`1` và cột :math:`1` của tích :math:`BA` là :math:`(b_{11}a_{11} + b_{12}a_{21}) \pmod p`.

Nếu ta chọn :math:`a_{12} \not\equiv b_{21}^{-1}a_{21}b_{21} \pmod p` thì :math:`AB \neq BA`, do đó nhóm không có tính giao hoán.

(c) Ta liệt kê tất cả ma trận:

.. math::

    A_1 = \begin{pmatrix}0 & 1\\1 & 0\end{pmatrix}, \quad A_2 = \begin{pmatrix}0 & 1\\1 & 1\end{pmatrix}, \quad A_3 = \begin{pmatrix}1 & 0\\0 & 1\end{pmatrix}, \\
    A_4 = \begin{pmatrix}1 & 0\\1 & 1\end{pmatrix}, \quad A_5 = \begin{pmatrix}1 & 1\\0 & 1\end{pmatrix}, \quad A_6 = \begin{pmatrix}1 & 1\\1 & 0\end{pmatrix}.

Bảng phép nhân sẽ như sau:

+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
|             | :math:`A_1` | :math:`A_2` | :math:`A_3` | :math:`A_4` | :math:`A_5` | :math:`A_6` |
+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`A_1` | :math:`A_3` | :math:`A_5` | :math:`A_1` | :math:`A_6` | :math:`A_2` | :math:`A_4` |
+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`A_2` | :math:`A_4` | :math:`A_6` | :math:`A_2` | :math:`A_5` | :math:`A_1` | :math:`A_3` |
+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`A_3` | :math:`A_1` | :math:`A_2` | :math:`A_3` | :math:`A_4` | :math:`A_5` | :math:`A_6` |
+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`A_4` | :math:`A_2` | :math:`A_1` | :math:`A_4` | :math:`A_3` | :math:`A_6` | :math:`A_5` |
+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`A_5` | :math:`A_6` | :math:`A_4` | :math:`A_5` | :math:`A_2` | :math:`A_3` | :math:`A_1` |
+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`A_6` | :math:`A_5` | :math:`A_3` | :math:`A_6` | :math:`A_1` | :math:`A_4` | :math:`A_2` |
+-------------+-------------+-------------+-------------+-------------+-------------+-------------+

(d) Hàng đầu :math:`\bm{u}_1` là vector bất kì thuộc :math:`\mathbb{F}_p^2` ngoại trừ :math:`(0, 0)`. Do đó ta có :math:`p^2-1` cách chọn.

Hàng thứ hai :math:`\bm{u}_2` là vector bất kì ngoại trừ một bội của hàng đầu. Do đó ta có :math:`p^2-p` cách (loại các cách chọn :math:`i \cdot \bm{u}_1` với :math:`i = 0, 1, \ldots, p-1`).

Kết luận: có :math:`(p^2-1)(p^2-p)` phần tử trong :math:`GL_2(\mathbb{F}_p)`.

(e) Tương tự (d), ta chọn hàng đầu :math:`\bm{u}_1` là bất kì vector nào ngoại từ :math:`(0,0)`. Ta có :math:`p^n-1` cách chọn.

Hàng thứ hai :math:`\bm{u}_2` là bất kì vector nào ngoại trừ bội của hàng đầu, nghĩa là loại các tổ hợp :math:`i \cdot \bm{u}_1` với :math:`i = 0, 1, \ldots, p-1`. Ta có :math:`p^n-p` cách chọn.

Hàng thứ ba :math:`\bm{u}_3` là bất kì vector nào ngoại trừ các tổ hợp tuyến tính của :math:`\bm{u}_1` và :math:`\bm{u}_2`. Số lượng tổ hợp tuyến tính :math:`a_1 \cdot \bm{u}_1 + a_2 \cdot \bm{u}_2` chính là số lượng cặp :math:`(a_1, a_2)` và ta có :math:`p^2` trường hợp (vì :math:`a_1, a_2 \in \mathbb{F}_p`). Như vậy hàng thứ ba có :math:`p^n-p^2` cách chọn.

Tổng quát, vector thứ :math:`n` (hàng thứ :math:`n`) là bất kì vector nào ngoại trừ tổ hợp tuyến tính của các vector trước đó :math:`\bm{u}_1`, :math:`\bm{u}_2`, ..., :math:`\bm{u}_{n-1}`. Như vậy ta có :math:`p^n-p^{n-1}` cách chọn.

Kết luận: có tất cả :math:`(p^n-1)(p^n-p) \cdots (p^n-p^{n-1})` phần tử trong :math:`GL_n(\mathbb{F}_p)`.

.. admonition:: Câu 2.18

    Solve each of the following simultaneous systems of congruences (or explain why no solutions exists).

    (a) :math:`x \equiv 3 \pmod 7` and :math:`x \equiv 4 \pmod 9`

    (b) :math:`x \equiv 137 \pmod {423}` and :math:`x \equiv 87 \pmod {191}`

    (d) :math:`x \equiv 5 \pmod 9`, :math:`x \equiv 6 \pmod {10}` and :math:`x \equiv 7 \pmod {11}`

    (e) :math:`x \equiv 37 \pmod {43}`, :math:`x \equiv 22 \pmod {49}` and :math:`x \equiv 18 \pmod {71}`

(a) Vì :math:`N = 7 \cdot 9 = 63`, đặt :math:`T_1 = 63/7 = 9`, :math:`T_1^{-1} \bmod 7 = 4`, :math:`T_2 = 63/9 = 7`, :math:`T_2^{-1} \bmod 9 = 4`.

.. math:: \Rightarrow x \equiv 3 \cdot 9 \cdot 4 + 4 \cdot 7 \cdot 4 \equiv 220 \equiv 31 \pmod {63}

(b) Vì :math:`N=423 \cdot 191=90793`, đặt :math:`T_1=N/423=191`, :math:`T_1^{-1} \bmod 423 = 392`, :math:`T_2=N/191=423`, :math:`T_2^{-1} \bmod 191 = 14`.

.. math:: \Rightarrow x \equiv 137 \cdot 191 \cdot 392 + 87 \cdot 423 \cdot 14 \equiv 27209 \pmod N

(c) Không thể tính vì :math:`\gcd(451, 697) = 41 \neq 1`.

(d) Vì :math:`N = 9 \cdot 10 \cdot 11 = 990`, đặt :math:`T_1=N / 9=110`, :math:`T_1^{-1} \bmod 9 = 5`, :math:`T_2=N/10=99`, :math:`T_2^{-1} \bmod 10=9`, :math:`T_3=N/11=90`, :math:`T_3^{-1} \bmod 11 = 6`

.. math:: \Rightarrow x \equiv 5 \cdot 110 \cdot 5 + 6 \cdot 99 \cdot 9 + 7 \cdot 90 \cdot 6 \equiv 986 \pmod N

(e) Vì :math:`N=43 \cdot 49 \cdot 71=149597`, đặt :math:`T_1=N/43=3479`, :math:`T_1^{-1} \bmod 43 = 32`, :math:`T_2=N/49=3053`, :math:`T_2^{-1} \bmod 49=36`, :math:`T_3=N/71=2107`, :math:`T_3^{-1} \bmod 71 = 37`

.. math:: \Rightarrow x \equiv 37 \cdot 3479 \cdot 32 + 22 \cdot 3053 \cdot 36 + 18 \cdot 2107 \cdot 37 \equiv 11733 \pmod N

.. admonition:: Câu 2.19

    Solve the 1700-year-old Chinese remainder problem from the *Sun Tzu Suan Ching* stated on page 84.

    .. math::

        \begin{cases}
            x \equiv 2 \pmod 3 \\
            x \equiv 3 \pmod 5 \\
            x \equiv 2 \pmod 7
        \end{cases}.

Đáp án: :math:`x \equiv 23 \pmod {105}`.

.. admonition:: Câu 2.21.

    (a) Let :math:`a,b,c` be positive integers and suppose that

    .. math:: a \mid c, \quad b \mid c, \quad \text{and} \quad \gcd(a,b)=1

    Prove that :math:`ab \mid c`

    (b) Let :math:`x=c` and :math:`x=c'` be two solutions to the system of simultaneous congruences in the Chinese remainder theorem. Prove that

    .. math:: c \equiv c' \pmod{m_1m_2...m_k}

(a) Do :math:`a \mid c` nên tồn tại :math:`k \in \mathbb{Z}` sao cho :math:`c = ka`.

Do :math:`b \mid c` nên tồn tại :math:`l \in \mathbb{Z}` sao cho :math:`c = lb`.

Như vậy :math:`ka = lb`.

Tuy nhiên do :math:`\gcd(a,b) = 1` nên :math:`a \mid l`, hay :math:`l = ma` với :math:`m \in \mathbb{Z}`

Như vậy :math:`c=lb=lma`, hay :math:`ab \mid c`.

(b) Nếu :math:`c \equiv c' (\equiv a_i) \pmod m_i` thì :math:`c \equiv c' \pmod{m_1 m_2 \cdots m_k}`.

.. admonition:: Câu 2.24

    Let :math:`p` be an odd prime, let :math:`a` be an integer that is not divisible by :math:`p`, and let :math:`b` is a square root of :math:`a` modulo :math:`p`. This exercise investigates the square root of :math:`a` modulo powers of :math:`p`

    (a) Prove that for some choise of :math:`k`, the number :math:`b+kp` is a square root of :math:`a` modulo :math:`p^2`, i.e., :math:`(b+kp)^2 \equiv a \pmod{p^2}`

    (b) The number :math:`b=537` is a square root of :math:`a=476` modulo the prime :math:`p=1291`. Use the idea in (a) to compute a square root of 476 modulo :math:`p^2`

    (c) Suppose that :math:`b` is a square root of :math:`a` modulo :math:`p^n`. Prove that for some choice of :math:`j`, the number :math:`b+jp^n` is a square root of :math:`a` modulo :math:`p^{n+1}`

    (d) Explain why (c) implies the following statements: If :math:`p` is an odd prime and if :math:`a` has a square root modulo :math:`p`, then :math:`a` has a square root modulo :math:`p^n` for every power of :math:`p`. Is this true if :math:`p=2`?

    (e) Use the method in (c) to compute the square root of 3 modulo :math:`13^3`, given that :math:`9^2\equiv 3 \pmod{13}`

(a) Đặt :math:`f(b_n)=b_n^2-a \pmod{p^n}` với :math:`b_1 = b`. Suy ra :math:`f(b_1) = b^2-a \equiv 0 \pmod p`.

Ta cần tìm :math:`b_2` thỏa :math:`f(b_2)=b_2^2-a \equiv 0 \pmod{p^2}`.

Nói cách khác, :math:`b_2 = b_1 + kp` nên suy ra

.. math:: f(b_1 + kp) = (b_1 + kp)^2 - a = b_1^2 + 2 b_1 kp + (kp)^2 - a \equiv 0 \pmod{p^2}

Tương đương với

.. math:: 2b_1k \equiv -(b_1^2-a)/p \pmod{p^2},

vì :math:`b_1^2-a \equiv 0 \pmod p`.

Do :math:`2b_1 \not\equiv 0 \pmod{p^2}` nên tồn tại :math:`k` thỏa mãn đẳng thức.

(b) Ta có công thức

.. math:: k = -(b^2-a)/p \times (2b)^{-1} \pmod{p^2}

(c) Ta chứng minh theo quy nạp với mọi :math:`n \geqslant 1`, tồn tại :math:`b_n \in \mathbb{Z}` sao cho

.. math::

    f(b_n) & = b_n^2-a \equiv 0 \pmod{p^n} \\
    b_n & = b \pmod{p^n}

Trường hợp :math:`n = 1` là điều kiện ban đầu với :math:`b_1 = b`. Giả sử mệnh đề đúng tới :math:`n`, nghĩa là:

.. math::

    f(b_n) & = b_n^2 - a \pmod{p^n} \\
    b_n & = b \pmod{p^n}

Xét :math:`b_{n+1}`

.. math:: f(b_{n+1}) = b_{n+1}^2-a \equiv 0 \pmod{p^{n+1}}.

Ta viết :math:`b_{n+1}=b_n+p^nt_n`.

.. math::

    \Rightarrow f(b_{n+1})=b_n^2+2b_np^nt_n+p^{2n}t_n^2 - a \equiv 0 \pmod{p^{n+1}}

    \Rightarrow b_n^2+2b_np^nt_n-a \equiv 0 \pmod{p^{n+1}} \ (\text{vì} \ 2n \geqslant n+1)

    \Rightarrow 2 b_n t_n \equiv -(b_n^2-a)/p^n \pmod{p^{n+1}} \ \text{từ} \ (2)

Nghiệm :math:`t_n` tồn tại vì ta đã giả sử :math:`2b_n \equiv 0 \pmod{p^{n}}`. Như vậy

.. math:: f(b_{n+1}) \equiv 0 \pmod{p^{n+1}}, \quad \text{và} \quad b_{n+1} \equiv b_n \pmod{p^n}.

Chứng minh này dùng cho :math:`b+jp^n` modulo :math:`p^n`, không phải cho :math:`p^{n+1}`.

(d) Sử dụng quy nạp. Đặc biệt, nếu :math:`p=2` thì mọi số nguyên đều thỏa.

.. admonition:: Câu 2.31

    Let :math:`R` and :math:`S` be rings. A functions :math:`\phi: R \rightarrow S` is called a (*ring*) *homomorphism* if it satisfies

    .. math:: \phi(a+b)=\phi(a) + \phi(b) \quad \text{and} \quad \phi(a \star b) = \phi(a) \star \phi(b)

    for all :math:`a, b \in R`.

    (a) Let :math:`0_R`, :math:`0_S`, :math:`1_R` and :math:`1_S` denote the additive and multiplicative identities of :math:`R` and :math:`S`, respectively. Prove that

    .. math:: \phi(0_R)=0_S, \, \phi(1_R)=1_S, \, \phi(-a)=-\phi(a), \, \phi(a^{-1})=\phi(a)^{-1}

    where the last equality holds for those :math:`a \in R` that have a multiplicative inverse.

    (b) Let :math:`p` be a prime, and let :math:`R` be a ring with the property that :math:`pa = 0` for every :math:`a \in R`. (Here :math:`pa` means to add :math:`a` to itself :math:`p` times.) Prove that the map

    .. math:: \phi: R \rightarrow R, \quad \phi(a)=a^p

    is a ring homomorphism. It is called the *Frobenius homomorphism*.

Điều kiện đề bài là :math:`\phi(a+b)=\phi(a)+\phi(b)` và :math:`\phi(a \star b) = \phi(a) \star \phi(b)` với mọi :math:`a, b \in R`.

(a) Trong :math:`R`, với mọi :math:`a \in R` ta có

.. math:: a + 0_R = 0_R + a = a.

Suy ra

.. math:: \phi(a) = \phi(a + 0_R) = \phi(0_R + a),

hay

.. math:: \phi(a) = \phi(a) + \phi(0_R) = \phi(0_R) + \phi(a).

Đặt :math:`\phi(a)=b \in S`. Khi đó

.. math:: b = b + \phi(0_R) = \phi(0_R) + b

nên suy ra :math:`\phi(0_R) = 0_S`.

Trong :math:`R`, với mọi :math:`a \in R` thì

.. math:: a \star 1_R = 1_R \star a = a.

Khi đó

.. math:: \phi(a \star 1_R) = \phi(1_R \star a) = \phi(a)

nên suy ra

.. math:: \phi(a) \star \phi(1_R) = \phi(1_R) \star \phi(a) = \phi(a),

hay :math:`\phi(1_R) = 1_S`.

Với :math:`\phi(-a) = -\phi(a)`, trong :math:`R` ta có

.. math:: a + (-a) = (-a) + a = 0_R,

suy ra

.. math:: \phi(a + (-a)) = \phi((-a) + a) = \phi(0_R),

tương đương với

.. math:: \phi(a) + \phi(-a) = \phi(-a) + \phi(a) = \phi(0_R) = 0_S.

Như vậy :math:`\phi(-a) = -\phi(a)`.

Với :math:`\phi(a^{-1}) = \phi(a)^{-1}`, trong :math:`R` ta có

.. math:: a \star a^{-1} = a^{-1} \star a = 1_R,

suy ra

.. math:: \phi(a \star a^{-1}) = \phi(a^{-1} \star a) = \phi(1_R),

tương đương với

.. math:: \phi(a) \star \phi(a^{-1}) = \phi(a^{-1}) \star \phi(a) = \phi(1_R) = 1_S.

Như vậy :math:`\phi(a^{-1})=\phi(a)^{-1}`.

(b) Ánh xạ :math:`\phi: R \rightarrow R` cho bởi :math:`\phi(a)=a^p`, suy ra

.. math:: \phi(a+b) = (a+b)^p = \sum_{i=0}^{p} \binom{p}{i} a^i b^{p-1}.

Vì :math:`p \mid \displaystyle{\binom{p}{i}} = \dfrac{p!}{(p-i)! \cdot i!}` (:math:`p` là số nguyên tố) nên suy ra với mọi :math:`1 \leqslant i \leqslant p-1`, ta có :math:`\displaystyle{\binom{p}{i}} = 0` (do :math:`pa=0`).

:math:`\Rightarrow \phi(a+b)=a^p+b^p=\phi(a)+\phi(b)` (1)

:math:`\Rightarrow \phi(ab)=(ab)^p=a^p b^p = \phi(a) \phi(b)` (2)

Từ (1) và (2) ta thu được ring homomorphism.


.. admonition:: Câu 2.32

    Prove Proposition 2.41

Vì :math:`a_1 \equiv a_2 \pmod m` nên :math:`m \mid (a_1 - a_2)`.

Nói cách khác là tồn tại :math:`k \in R` sao cho :math:`a_1 - a_2 = k \star m`.

Tương tự, tồn tại :math:`l \in R` sao cho :math:`b_1 - b_2 = l \star m`.

Từ đó

.. math:: a_1 - a_2 + b_1 - b_2 = (k+l) \star m,

tương đương với

.. math:: m \mid (a_1 + b_1 - (a_2 + b_2)),

hay

.. math:: a_1 + b_1 \equiv a_2 + b_2 \pmod m.

Tương tự cho :math:`a_1-b_1 \equiv a_2-b_2 \pmod m`.

Đối với phép nhân, do

.. math::

    \begin{cases}
        a_1 = a_2 + k \star m \\ b_1 = b_2 + l \star m
    \end{cases}

ta có

.. math::

    a_1 \star b_1 & = (a_2 + k \star m)(b_2 + l \star m) \\
    & = a_2 \star b_2 + a_2 \star l \star m + k \star b_2 \star m + k \star l \star m^2,

suy ra :math:`m \mid (a_1 \star b_1 - a_2 \star b_2)` hay nói cách khác là

.. math:: a_1 \star b_1 \equiv a_2 \star b_2 \pmod m.

.. admonition:: Câu 2.33

    Prove Proposition 2.43

Theo Câu 2.32, nếu ta có :math:`a' \in \bar{a}` thì tương đương :math:`a' \equiv a \pmod m`.

Tương tự, nếu ta có :math:`b' \in \bar{b}` thì tương đương :math:`b' \equiv b \pmod m`.

Như vậy, theo Câu 2.32 thì

.. math:: a' + b' \equiv a+b \pmod m, \quad a' \star b' \equiv a \star b \pmod m

Nói cách khác

.. math:: a'+b' \in \overline{a+b} \quad \text{và} \quad a' \star b' \in \overline{a \star b},

nói cách khác phép tính cộng và nhân đóng trên :math:`R` (closed).

Với mọi :math:`a \in R` ta có

.. math:: \overline{a} + \overline{0} = \overline{a+0} = \overline{a} = \overline{0+a} = \overline{0} + \overline{a}

Như vậy phần tử trung hòa của phép cộng là :math:`\overline{0}`.

Với mọi :math:`a \in R` thì

.. math:: \overline{a} + \overline{m-a} = \overline{a + m - a} = \overline{0} = \overline{m-a} + \overline{a},

suy ra :math:`\overline{m-a}` là phần tử đối của phần tử :math:`a` trong phép cộng.

Phép cộng trong modulo cũng có tính kết hợp

.. math:: \overline{a} + (\overline{b}+\overline{c}) = \overline{a} + \overline{b+c} = \overline{a+b+c} = \overline{a+b} + \overline{c} = (\overline{a}+\overline{b})+\overline{c}

Với mọi :math:`a, b \in R`

.. math:: \overline{a}+\overline{b}=\overline{a+b}=\overline{b+a}=\overline{b}+\overline{a}

nên phép cộng modulo có tính giao hoán.

Vì :math:`a \star 1 \equiv a \pmod m` với mọi :math:`a \in R` nên

.. math:: \overline{a} \star \overline{1} = \overline{a \star 1} = \overline{a} = \overline{1 \star a} = \overline{1} \star \overline{a}.

Suy ra phần tử đơn vị của phép nhân là :math:`\overline{1}`.

Với mọi :math:`a, b, c \in R` ta có :math:`a(bc)=(ab)c \pmod m`. Suy ra tính kết hợp của phép nhân

.. math:: \overline{a} \star (\overline{b} \star \overline{c}) = \overline{a} \star \overline{bc} = \overline{abc} = \overline{ab} \star \overline{c} = (\overline{a} \star \overline{b}) \star \overline{c}.

Vì

.. math:: \overline{a} \star \overline{b} = \overline{a \star b} = \overline{b \star a} = \overline{b} \star \overline{a}

ta có tính giao hoán của phép nhân.

Tính phân phối giữa phép nhân và phép cộng:

.. math:: \overline{a} \star (\overline{b} + \overline{c}) = \overline{a} \star \overline{b + c} = \overline{a(b+c)} = \overline{ab + ac} = \overline{ab} + \overline{ac} = \overline{a} \star \overline{b} + \overline{a} \star \overline{c}.

Như vậy, :math:`R/(m)` là vành (cụ thể vừa là vành với đơn vị vừa là vành giao hoán).

.. admonition:: Câu 2.34

    Let :math:`\mathbb{F}` be a field and let :math:`\mathbf{a}` and :math:`\mathbf{b}` be nonzero polynomials in :math:`\mathbb{F}[x]`

    (a) Prove that :math:`\deg(\mathbf{a} \cdot \mathbf{b}) = \deg(\mathbf{a}) + \deg(\mathbf{b})`

    (b) Prove that :math:`\mathbf{a}` has a multiplicative inverse in :math:`\mathbb{F}[x]` if and only if :math:`\mathbb{a}` is in :math:`\mathbb{F}`, i.e., if and only if :math:`\mathbb{a}` is a constant polynomial

    (c) Prove that every nonzero element of :math:`\mathbb{F}[x]` can be factored into a product of irreducible polynomials. (*Hint.* Use (a), (b) and induction on the degree of the polynomial.)

    (d) Let :math:`R` be ring :math:`\mathbb{Z}/6\mathbb{Z}`. Give an example to show that (a) is false for some polynomials :math:`\mathbf{a}` and :math:`\mathbf{b}` in :math:`R[x]`.

(a) Đặt

.. math:: \mathbf{a} = a_n x^n + a_{n-1} x^{n-1} + \cdots + a_1 x + a_0,

với :math:`a_i \in \mathbb{F}` và :math:`\deg(\mathbf{a}) = n`.

Đặt

.. math:: b = b_m x^m + b_{m-1} x^{m-1} + \cdots + b_1 x + b_0,

với :math:`b_i \in \mathbb{F}` và :math:`\deg(\mathbf{b}) = m`.

Hạng tử với bậc cao nhất trong phép nhân :math:`\mathbf{a} \cdot \mathbf{b}` là :math:`x^{n+m}`, do đó

.. math:: \deg(\mathbf{a} \cdot \mathbf{b}) = n + m = \deg(\mathbf{a}) + \deg(\mathbf{b}).

(b) Với

.. math:: \mathbf{a} = a_n x^n + a_{n-1} x^{n-1} + \cdots + a_1 x + a_0

Giả sử :math:`\mathbf{a}` có nghịch đảo trong :math:`\mathbb{F}[x]` là đa thức

.. math:: \mathbf{b}=b_m x^m + b_{m-1} x^{m-1} + \cdots + b_1 x + b_0.

Vì

.. math:: \mathbf{ab} =\sum_{i=0}^n a_i x_i \sum_{j=0}^m b_j x^j = \sum_{i=0}^n \sum_{j=0}^m a_i b_j x^{i+j} = 1.

Đồng nhất hệ số ta có :math:`a_0 b_0 = 1`, các tích khác bằng :math:`0`. Như vậy :math:`\mathbf{a}` là đa thức hằng.

(d) :math:`\mathbf{a} = 2x^2 + 3x + 1`, :math:`\mathbf{b} = 3x + 2`.

Trong :math:`\mathbb{Z}/6\mathbb{Z}` các hệ số được modulo cho :math:`6` và ta có

.. math:: \mathbf{a} \mathbf{b} = x^2 + 3x + 2

Như vậy :math:`\deg(\mathbf{a} \mathbf{b}) = 2 < 3 = \deg(\mathbf{a}) + \deg(\mathbf{b})`

.. admonition:: Câu 2.37

    Prove that the polynomial :math:`x^3+x+1` is irreducible in :math:`\mathbb{F}_2[x]`

Nếu :math:`f(x) = x^3+x+1` có nhân tử nào khác :math:`1` và chính nó thì đa thức đó phải có bậc nhỏ hơn :math:`3`.

Các đa thức như vậy trong :math:`\mathbb{F}_2[x]` là

.. math:: 0, x+1, x^2, x^2+1, x^2+x, x^2+x+1, x.

Tuy nhiên :math:`f(x)` không chia hết cho bất kì đa thức nào kể trên nên :math:`f(x)` là đa thức tối giản.

.. admonition:: Câu 2.39

    The field :math:`\mathbb{F}_7[x]/(x^2+1)` is a field with :math:`49` elements, which for the moment we donote by :math:`\mathbb{F}_{49}`

    Using example **2.58**, every element in :math:`\mathbb{F}_7[x]/(x^2+1)` has form :math:`f(x)=a+bx`, so in :math:`\mathbb{F}_{49}` it has form :math:`a+bi` (here :math:`i^2=-1`)

    (a) Is :math:`2+5x` is a primitive root in :math:`\mathbb{F}_{49}`? No because :math:`(2+5x)^8=1`

    (b) Is :math:`2+x` is a primitive root in :math:`\mathbb{F}_{49}`? Yes

    (c) Is :math:`1+x` is a primitive root in :math:`\mathbb{F}_{49}`? No because :math:`(1+x)^{24} = 1`


.. .. admonition:: Câu 2.41.
..

.. Let :math:`\mathbb{F}` is a finite field.

.. (a) Prove that there is an integer :math:`m \geqslant 1` such that if we add 1 to itself :math:`m` times,

.. .. math:: \underbrace{1+1+\cdots+1}_{m \text{ ones}}

.. then we get 0. Note that here 1 and 0 are the multiplicative and additive identity elements of the field :math:`\mathbb{F}`.

.. Because 1 is element of :math:`\mathbb{F}`, then :math:`\underbrace{1+1+\cdots+1}_{n \text{ times}}` always is an element of :math:`\mathbb{F}`. And :math:`\mathbb{F}` is finite field, so there is :math:`m \geqslant 1` such that :math:`\underbrace{1+1+\cdots+1}_{m \text{ times}}` equals to 0 (1, 1+1, 1+1+1, ... cannot all be different)

.. (b) Let :math:`m` be the smallest positive integer with the property described in (a). Prove that :math:`m` is prime. This prime is called the *characteristic of the field :math:`\mathbb{F}`*.

..  Suppose that :math:`m` can be factor, so :math:`m=pq` (:math:`1 < p, q < m`) and then

.. :math:`\Rightarrow \underbrace{1+1+\cdots+1}_{m \text{ times}} = 0`. Therefore we can write as \[ \overbrace{\underbrace{(1+1+\cdots+1)}_{p \text{ times}} + \underbrace{(1+1+\cdots+1)}_{p \text{ times}} + \cdots + \underbrace{(1+1+\cdots+1)}_{p \text{ times}}}^{q \text{ times}}\]

.. Because :math:`\mathbb{F}` is a finite field, :math:`\underbrace{1+1+\cdots+1}_{p \text{ times}} = a \in \mathbb{F}`

.. :math:`\Rightarrow q \cdot a = 0` (:math:`q > 1` and :math:`a` cannot be 0 because :math:`m` is the smallest number that satisfies :math:`1+1+\cdots+1=0`

.. :math:`\Rightarrow` contraction :math:`\Rightarrow \mathbb{F}` cannot be a field.

.. So :math:`m` is a prime
