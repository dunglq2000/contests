AceBear
*******

Baby RSA
========

Đặt :math:`c1 = (p + q)^{2019}`, :math:`c2 = (p + 2019)^q`, suy ra :math:`(p + 2019)^q - c2` chia hết :math:`n`, mà :math:`n` chia hết :math:`q` nên :math:`(p + 2019)^q - c2` chia hết :math:`q`. Như vậy

.. math:: (p + 2019)^q \equiv c2 \bmod q.

Theo định lý Fermat, :math:`(p + 2019)^q \equiv p + 2019 \bmod q`, hay :math:`p + 2019 \equiv c2 \bmod q`. Như vậy :math:`p + 2019 - c2` chia hết :math:`q`.

Ta cũng có :math:`n` chia hết cho :math:`q` nên :math:`a \cdot n + b \cdot (c2 - p - 2019)` chia hết :math:`q`, với :math:`a`, :math:`b` là các số nguyên nào đó.

Ta có :math:`a \cdot n + b \cdot (c2 - p - 2019) = a \cdot n + b \cdot (c2 - 2019) - b \cdot p` (1) nên ta sẽ tìm số :math:`a`,
:math:`b` để :math:`a \cdot n + b \cdot (c2 - 2019)` trở nên gọn nhất có thể. Bằng thuật toán Euclid ta tìm
được :math:`\gcd(n, c2 - 2019) = 1` nên ta dùng thuật toán Euclid mở rộng để tìm :math:`a`, :math:`b`
để :math:`a \cdot n + b \cdot (c2 - 2019) = 1`.

Thay :math:`a` và :math:`b` vào (1) ta có :math:`1 - b \cdot p` chia hết :math:`q`, hay :math:`b \cdot p - 1 = k \cdot q`. Như vậy :math:`b \cdot p = k \cdot q + 1`. (2)

Ta lại có :math:`(p + q)^{2019} \equiv c1 \bmod n`, suy ra :math:`(p + q)^{2019} \equiv c1 \bmod q`, :math:`(p + q)^{2019} \cdot b^{2019} \equiv c1 \cdot b^{2019} \bmod n`,
:math:`(b \cdot p + b \cdot q)^{2019} \equiv (c1 \cdot b^{2019}) \bmod n`.

Thay (2) vào đây thì :math:`(1 + (k + b) \cdot q)^{2019} \equiv (c1 \cdot b^{2019}) \pmod{n} \bmod q`.

Hơn nữa :math:`1 + (k + b) \cdot q \equiv 1 \mod q` nên suy ra :math:`(c1 \cdot b^{2019}) \bmod n - 1` chia hết :math:`q`. Như vậy

.. math:: \gcd(n, (c1 \cdot b^{2019}) \bmod n - 1) = q
    
vì :math:`(c1 \cdot b^{2019}) \bmod n - 1` không chia hết :math:`n`.

Chiến thuật giải: tìm ước chung lớn nhất giữa :math:`n` và :math:`(c1 \cdot b^{2019}) \bmod n - 1` sẽ được :math:`q`. Từ đó tính
:math:`p` và giải mã được bài toán.
