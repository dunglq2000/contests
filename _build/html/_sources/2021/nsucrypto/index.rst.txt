NSUCRYPTO 2021
**************

Elliptic curve points
=====================

Đề bài
------

Đặt :math:`E / \mathbb{F}_p` là đường cong elliptic với dạng Weiertrass. Đường cong này có phương trình :math:`y^2 = x^3 + ax + b`, với :math:`a, b \in \mathbb{F}_p` và :math:`4a^3 + 27a^2 \neq 0`. Các điểm affine trong :math:`E` và điểm vô cực :math:`\mathcal{O}` tạo thành một nhóm Abel, đặt

.. math:: E(\mathbb{F}_p) = \{ (x, y) \in \mathbb{F}_p^2 : y^2 = x^3 + ax + b \} \cup \{ \mathcal{O} \}

Giả sử :math:`b = 0`. Gọi :math:`R \in E(\mathbb{F}_p)` là điểm với order lẻ và :math:`R \neq \mathcal{O}`. Xét :math:`H = \langle R \rangle` là nhóm con sinh bởi :math:`R`.

Giúp Alice chứng minh rằng nếu :math:`(u, v) \in H` thì :math:`u` là số chính phương modulo :math:`p`.

Giải
----

Gọi :math:`Q = (x', y') \in H`. Do :math:`R` có order lẻ nên :math:`Q` cũng có order lẻ (order của phần tử trong nhóm con chia hết order của nhóm con đó).

Giả sử order của :math:`Q` là :math:`n` lẻ. Xét điểm :math:`P = \dfrac{n+1}{2} Q`, do :math:`n` lẻ nên dễ thấy :math:`P \in H`. Đặt :math:`P = (x, y)`.

Do :math:`2P = (n+1) Q = Q` (do :math:`Q` có order là :math:`n`) nên theo công thức cộng hai điểm trên elliptic ta có

.. math:: 

   x' & = \left(\frac{3x^2 + a}{2y}\right) - 2x \\
      & = \frac{9x^4 + 6x^2 a + a^2 - 8x(x^3 + ax)}{(2y)^2} \\
      & = \frac{x^4 - 2x^2 a + a^2}{(2y)^2} \\
      & = \left(\frac{x^2-a}{2y}\right).

Biểu thức cuối cho thấy rằng :math:`x'` là số chính phương modulo :math:`p`.

2021-bit key
============

Đề bài
------

Một generator dùng pseudo-random để sinh ra một dãy bit (:math:`0` hoặc :math:`1`) từng bước một. Để bắt đầu generator, một người phải trả :math:`1` *nsucoin* và generator sẽ sinh ngẫu nhiên một bit (dãy bit độ dài bằng :math:`1`). Khi đó, với một dãy :math:`S` được sinh có độ dài :math:`l`, :math:`l \geqslant 1`, một trong các động tác sau được thực hiện:

1. Một dãy ngẫu nhiên độ dài :math:`4` được thêm vào :math:`S`, khi đó dãy :math:`S'` có độ dài :math:`l + 4`. Việc này tốn :math:`2` *nsucoin*.
2. Một dãy ngẫu nhiên độ dài :math:`2l` được thêm vào :math:`S`, khi đó dãy :math:`S'` có độ dài :math:`3l`. Việc này tốn :math:`5` *nsucoin*.

Bob cần sinh độ dài chính xác :math:`2021` bit. Số lượng *nsucoin* nhỏ nhất để thực hiện việc này là bao nhiêu?

Giải
----

Dễ thấy rằng khi :math:`l > 2` thì sử dụng động tác thứ hai khiến độ dài dãy tăng lên rất nhanh như lại tốn thêm coin.

Như vậy khi :math:`l > 6` mình sẽ chứng minh rằng động tác thứ hai hiệu quả hơn.

Để ý rằng nếu mình sử dụng động tác thứ nhất ba lần liên tiếp, khi đó từ dãy có độ dài :math:`l` mình thu được dãy mới độ dài :math:`l + 4 + 4 + 4 = l + 12` và việc này tốn :math:`6` *nsucoin*.

Trong khi đó, nếu mình dùng động tác thứ hai một lần thì từ dãy độ dài :math:`l` mình thu được dãy độ dài :math:`3l` và tốn :math:`5` *nsucoin*.

Mình muốn :math:`3l > l + 12` vì mình đã có :math:`3l` tương ứng :math:`5` *nsucoin* và :math:`l + 12` tương ứng :math:`6` *nsucoin*. Như vậy :math:`l > 6`.

Chiến thuật lúc này là mình sẽ dùng động tác thứ hai để triple độ dài bất cứ lúc nào có thể. Nói cách khác là khi đi ngược từ :math:`2021` về :math:`0` thì khi nào số chia hết cho :math:`3`, mình sẽ dùng động tác thứ hai, không thì dùng động tác thứ nhất.

Quá trình sẽ diễn ra theo bảng sau.

.. only:: html

   .. table:: 
      :class: centered-table

      .. include:: bitkey.rst.inc
        
.. only:: latex

   .. tabularcolumns:: |c|c|

   .. include:: bitkey.rst.inc

Từ :math:`21` trở đi không thể áp dụng quy tắc trên nữa vì theo chứng minh trên chiến thuật chỉ hiệu quả với :math:`l > 6`.

Mình khai triển :math:`21 = 1 + 4 + 4 + 4 + 4 + 4`, thực hiện :math:`4` phép trừ (động tác đầu) tốn :math:`5 \cdot 2 = 10` *nsucoin* và trừ :math:`1` tốn :math:`1` *nsucoin*.

Như vậy tổng số *nsucoin* nhỏ nhất cần là :math:`47`.
