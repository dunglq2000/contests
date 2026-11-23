Chapter 7. Lattices and Cryptography
====================================

.. admonition:: Câu 7.43


    Đáp án: :math:`t = \dfrac{\bm{b}_1 \cdot \bm{b}_2}{\lVert \bm{b}_1 \rVert^2}` và :math:`\bm{b}_2^* = \bm{b}_2 - t \bm{b}_1` nên suy ra

    .. math:: \bm{b}_2^* \cdot \bm{b}_1 = \bm{b}_1 (\bm{b}_2 - t \bm{b}_1) = \bm{b}_1 \cdot \bm{b}_2 - t \lVert \bm{b}_1 \rVert^2 = \bm{b}_1 \cdot \bm{b}_2 - \dfrac{\bm{b}_1 \cdot \bm{b}_2}{\lVert \bm{b}_1 \rVert^2} \cdot \lVert \bm{b}_1 \rVert^2 = 0

    Do đó :math:`\bm{b}_2^* \perp \bm{b}_1` và :math:`\bm{b}_2^*` là hình chiếu của :math:`\bm{b}_2` lên orthogonal complement của :math:`\bm{b}_1`.


.. admonition:: Câu 7.44


    Đáp án:

    .. math:: \lVert \bm{a} - t \bm{b} \rVert^2 = (\bm{a} - t \bm{b})^2 = \bm{a}^2 - 2t \bm{a} \cdot \bm{b} + t^2 \bm{b}^2 = \lVert \bm{a} \rVert^2 + t^2 \lVert \bm{b} \rVert^2 - 2t \bm{a} \cdot \bm{b} \geqslant 0

    với mọi :math:`t \in \mathbb{R}`.

    Đây là tam thức bậc hai theo :math:`t` (với :math:`\bm{b} \neq \bm{0}`), đạt cực tiểu tại :math:`t = \dfrac{\bm{a} \cdot \bm{b}}{\lVert \bm{b} \rVert^2}`. Thay giá trị này vào được :math:`\lVert \bm{a} \rVert^2 - \dfrac{(\bm{a} \cdot \bm{b})^2}{\lVert \bm{b} \rVert^2} \geqslant 0`, tức :math:`\lvert \bm{a} \cdot \bm{b} \rvert \leqslant \lVert \bm{a} \rVert \lVert \bm{b} \rVert` (bất đẳng thức Cauchy-Schwarz).

    Với :math:`t` này ta có

    .. math:: (\bm{a} - t \bm{b}) \cdot \bm{b} = \bm{a} \cdot \bm{b} - t \lVert \bm{b} \rVert^2 = \bm{a} \cdot \bm{b} - \dfrac{\bm{a} \cdot \bm{b}}{\lVert \bm{b} \rVert^2} \cdot \lVert \bm{b} \rVert^2 = 0.

    Vì vậy :math:`\bm{a} - t \bm{b}` là hình chiếu của :math:`\bm{a}` lên orthogonal complement của :math:`b` (tương tự 7.43).

.. admonition:: Câu 7.45


    Đáp án ở dưới.

Thuật toán Gauss's lattice reduction.

.. prf:algorithm:: Thuật toán Gauss's latice reduction
    :label: hoff-algo-7-45

    1. While True

       1. If :math:`\lVert \bm{v}_2 \rVert < \lVert \bm{v}_1 \rVert`

          1. swap :math:`\bm{v}_1` and :math:`\bm{v}_2`

       2. EndIf
       3. :math:`m \gets \lfloor \bm{v}_1 \cdot \bm{v}_2 / \lVert \bm{v}_1 \rVert^2 \rceil`
       4. If :math:`m = 0`

          1. return :math:`(\bm{v}_1, \bm{v}_2)`

       5. EndIf
       6. Replace :math:`\bm{v}_2` with :math:`\bm{v}_2 - m\bm{v}_1`

    2. EndWhile

:math:`\bm{v}_1 = (14, -47)`, :math:`\bm{v}_2 = (-362, -131)`, 6 steps.

:math:`\bm{v}_1 = (147, 330)`, :math:`\bm{v}_2 = (690, -207)`, 7 steps.

.. admonition:: Câu 7.46


    Đáp án ở dưới.

Do :math:`W^\perp` là orthogonal complement của :math:`W` trong :math:`V` nên nếu :math:`\bm{z} \in W^\perp` thì :math:`\bm{z} \cdot \bm{y} = 0`, với mọi :math:`\bm{y} \in W`.

Với hai vector :math:`\bm{z}_1, \bm{z}_2 \in W^\perp` ta có :math:`\bm{z}_1 \cdot \bm{y} = \bm{z}_2 \cdot \bm{y} = 0`, với mọi :math:`\bm{y} \in W`.

Như vậy :math:`(\bm{z}_1 + \bm{z}_2) \cdot \bm{y} = 0 \Rightarrow \bm{z}_1 + \bm{z}_2 \in W^\perp`.

Ta lại có :math:`\alpha \bm{z}_1 \cdot \bm{y} = \alpha \cdot 0 = 0 \Rightarrow \alpha\bm{z}_1 \in W^\perp` với mọi :math:`\alpha \in \mathbb{R}`.

Tới đây ta có hai cách giải.

**Cách 1.** Ta có :math:`W \cap W^\perp = \{\bm{0}\}`. Nếu :math:`\bm{u}` thuộc cả hai tập :math:`W` và :math:`W^\perp` thì :math:`\bm{u} \cdot \bm{u} = 0 \Rightarrow \bm{u} = \bm{0}`.

Kí hiệu :math:`U = W + W^\perp`, ta chứng minh :math:`U = V`.

Ta có thể chọn một cơ sở trực chuẩn (orthonormal basis) trong :math:`U` và mở rộng nó thành cơ sở trực chuẩn trong :math:`V`.

Khi đó, nếu :math:`U \neq V` thì có một phần tử :math:`\bm{e}` trong cơ sở của :math:`V` vuông góc với :math:`U`. Do :math:`U` chứa :math:`W` và :math:`\bm{e}` vuông góc với :math:`U` nên :math:`\bm{e} \in W^\perp`.

Nhưng :math:`W^\perp \subseteq U`, nên :math:`\bm{e} \in U`. Vì :math:`\bm{e}` vừa thuộc :math:`U` vừa vuông góc với :math:`U` nên :math:`\bm{e} \cdot \bm{e} = 0`, tức :math:`\bm{e} = \bm{0}`, mâu thuẫn với việc :math:`\bm{e}` là vector đơn vị.

**Cách 2.** Đặt :math:`\{ \bm{e}_1, \bm{e}_2, \cdots, \bm{e}_k \}` là cơ sở trực chuẩn của không gian con :math:`W`. Với mỗi :math:`\bm{v} \in V`, đặt

.. math:: P(\bm{v}) = \sum_{j=1}^{k} (\bm{v} \cdot \bm{e}_j)  \cdot \bm{e}_j

Khi đó với mọi :math:`\bm{v} \in V` thì :math:`\bm{v} = \underbrace{P(\bm{v})}_{\in W} + \underbrace{(\bm{v} - P(\bm{v}))}_{\in W^\perp}`.

Ở đây :math:`\bm{v} - P(\bm{v}) \in W^\perp` là vì nếu :math:`j \in \{ 1, 2, \cdots, k \}` thì

.. math::

    (\bm{v} - P(\bm{v})) \cdot e_j & = \left(\bm{v} - \sum_{l=1}^{k} (\bm{v} \cdot \bm{e}_l) \cdot \bm{e}_l \right) \cdot \bm{e}_j \\
        & = \bm{v} \cdot \bm{e}_j - \bm{v} \cdot \bm{e}_j = 0.

Do :math:`\{ \bm{e}_1, \cdots, \bm{e}_k \}` là cơ sở của :math:`W`, điều này cho ta :math:`\bm{v} - P(\bm{v}) \in W^\perp`.

Như vậy :math:`V = W + W^\perp`, và tổng này là tổng trực tiếp vì :math:`W \cap W^\perp = \{\bm{0}\}`. Hơn nữa, nếu :math:`\bm{v} = a\bm{w} + b\bm{w}'` với :math:`\bm{w} \in W` và :math:`\bm{w}' \in W^\perp` thì

.. math::

    \lVert \bm{v} \rVert^2 & = (a \bm{w} + b \bm{w}')^2 = a^2 \bm{w}^2 + 2ab \bm{w} \bm{w}' + b^2 \bm{w}'^2 \\
    & = a^2 \lVert \bm{w} \rVert^2 + 0 + b^2 \lVert \bm{w}' \rVert^2 = a^2 \lVert \bm{w} \rVert^2 + b^2 \lVert \bm{w}' \rVert^2.
