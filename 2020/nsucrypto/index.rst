NSUCRYPTO 2020
**************

Problem 1 (R1). 2020
====================

Đề bài
------

Cho dãy :math:`S`, cipher machine có thể thêm vào :math:`S` hoặc xóa khỏi :math:`S` dãy con với dạng :math:`11`, :math:`101`, :math:`1001`, :math:`10\ldots 01`. Machine cũng có thể xóa khỏi :math:`S` hoặc thêm vào :math:`S` một dãy liên tục các số :math:`0`.

Smith biểu diễn số :math:`2020` dưới dạng nhị phân và sử dụng hai cipher machine để biến đổi. Máy đầu tiên trả về dạng nhị phân của số :math:`1984`, máy thứ hai trả về dạng nhị phân của số :math:`2021`.

Smith chắc chắn rằng một trong hai máy đã bị lỗi. Làm sao anh ấy biết được?

Giải
------

Ta viết các số :math:`2020`, :math:`1984` và :math:`2021` dưới dạng nhị phân.

Như vậy

.. math::

    2020 = 11111100100, \ 1984 = 11111000000, \ 2021 = 11111100101.

Đặt :math:`2020 = 11111 \underbrace{1001}_A 00` thì nếu ta xóa dãy :math:`A` khỏi :math:`2020` và thêm vào vị trí đó bốn chữ số :math:`0` thì ta có :math:`1984`. Như vậy máy đầu tiên hoạt động bình thường.

Việc thêm vào hoặc xóa đi :math:`11`, :math:`101`, :math:`1001`, ... thì số lượng bit :math:`1` tăng giảm đi một lượng chẵn còn thêm bớt :math:`0` không ảnh hưởng. Do :math:`2020` và :math:`2021` có số lượng bit :math:`1` khác tính chẵn lẻ nên không thể biến đổi từ :math:`2020` thành :math:`2021`.

Như vậy máy thứ hai bị hỏng.

Problem 4 (R1). RGB
===================

Đề bài
------

Trong một server có hai biến :math:`a` và :math:`b`. Khi server nhận query dạng "RED", "GREEN" hoặc "BLUE" thì giá trị của chúng sẽ thay đổi theo query nhận được.

Cụ thể hơn, cặp :math:`(a, b)` biến thành :math:`(a + 18b, 18a - b)` nếu query là "RED", biến thành :math:`(17a + 6b, -6a + 17b)` nếu query là "GREEN" và biến thành :math:`(-10a-15b, 15a-10b)` nếu là "BLUE".

Khi :math:`a` hoặc :math:`b` trở thành bội của :math:`324` thì nó được reset thành :math:`0`. Khi :math:`(a, b) = (0, 0)` thì server crash.

Ban đầu, :math:`(a, b)` được khai báo là :math:`(20, 20)`. Chứng minh rằng server sẽ không bao giờ crash dù có bao nhiêu query được gửi tới.

Giải
------

Ta xét :math:`a` và :math:`b` theo modulo :math:`3`. Vì :math:`18 \equiv 6 \equiv 15 \equiv 0` và :math:`17 \equiv -10 \equiv -1 \pmod 3` nên

- "RED": :math:`(a, b) \mapsto (a + 18b, 18a - b) \equiv (a, -b) \pmod 3`;
- "GREEN": :math:`(a, b) \mapsto (17a + 6b, -6a + 17b) \equiv (-a, -b) \pmod 3`;
- "BLUE": :math:`(a, b) \mapsto (-10a - 15b, 15a - 10b) \equiv (-a, -b) \pmod 3`.

Như vậy mỗi query chỉ có thể đổi dấu :math:`a` và :math:`b` theo modulo :math:`3`; nói riêng, :math:`a \not\equiv 0 \pmod 3` khi và chỉ khi giá trị mới của :math:`a` cũng vậy, và tương tự với :math:`b`.

Ban đầu :math:`a = b = 20 \equiv 2 \pmod 3`. Một bội của :math:`324 = 4 \cdot 81` luôn chia hết cho :math:`3`, nên bằng quy nạp theo số query, :math:`a` và :math:`b` không bao giờ là bội của :math:`324`: phép reset không bao giờ xảy ra và :math:`a, b \not\equiv 0 \pmod 3` sau mỗi query. Do đó :math:`(a, b)` không bao giờ bằng :math:`(0, 0)`, tức server không bao giờ crash dù có bao nhiêu query được gửi tới.

Problem 1. Poly
===============

Đề bài
------

Bob phát minh một thuật toán tên là *POLY*. Với :math:`x` là plaintext thì ciphertext là :math:`y = p(x)`, với :math:`p(x)` là đa thức với hệ số nguyên.

Đồng nghiệp của Bob muốn kiểm tra thuật toán. Khi encrypt :math:`20` thì Bob nhận được :math:`7`. Sau đó anh đồng nghiệp encrypt :math:`15` thì nhận được :math:`5`. Anh ta kết luận rằng thuật toán đã bị cài đặt sai. Chuyện gì đã xảy ra?

Giải
------

Giả sử đa thức là

.. math::

    p(x) = a_n x^n + a_{n-1} x^{n-1} + \cdots + a_1 x + a_0.

Khi đó

.. math::

    p(20) = a_n 20^n + a_{n-1} 20^{n-1} + \cdots + a_1 \cdot 20 + a_0 = 7.

Tương tự

.. math::

    p(15) = a_n 15^n + a_{n-1} 15^{n-1} + \cdots + a_1 \cdot 15 + a_0 = 5.

Suy ra :math:`p(20) - p(15) = 2` mà :math:`p(20) - p(15)` chia hết cho :math:`20 - 15 = 5` nên vô lý vì :math:`2` không chia hết cho :math:`5`. Như vậy thuật toán đã bị cài đặt sai.

.. _problem-3-hidden-rsa:

Problem 3. Hidden RSA
=====================

Đề bài
------

Bob học về mật mã khóa công khai và bây giờ mọi người đều có thể gửi message cho anh ta. Message được biểu diễn thành số nguyên không âm :math:`x` và chứa tối đa :math:`70` chữ số trong biểu diễn thập phân. Để gửi message cho Bob, chúng ta nhập :math:`x` vào trang web và kết quả được trả về ở dạng

.. math::

    \mathtt{Encr}(x) = x^e \pmod n,

với :math:`n` là modulus (biết rằng :math:`n` là tích của hai số nguyên tố phân biệt :math:`p` và :math:`q`) và :math:`e` là số mũ công khai (nguyên tố cùng nhau với :math:`p-1` và :math:`q-1`). Bob sợ bị hacker tấn công nên giấu đi :math:`n` và :math:`e`.

Victor bắt được một encrypted message

.. math::

    y = 71511896681324833458361392885184344933333159830863878600189212073777582178173,

được Alice gửi cho Bob.

Hãy giúp Victor giải mã nó.

Giải
------

Gọi :math:`f_2`, :math:`f_3` và :math:`f_6` là kết quả trả về khi nhập :math:`2`, :math:`3` và :math:`6` lên trang web. Ta nhận được

.. math::

    f_2 & = 50154912289039335014669339773308393642658123228965873078737860474494117389068 \\
    f_3 & = 74177167678866806519929337366689313939300015489238864541679630476008627210599 \\
    f_6 & = 69732835711852253044075185248502970714729629373386336194927784886349053828079.

Vì

.. math::

    \begin{array}{cccc}
        f_6 & \equiv & 6^e & \pmod n \\
        & \equiv & (2^e) \cdot (3^e) & \pmod n \\
        & \equiv & f_2 \cdot f_3 & \pmod n
    \end{array}

nên suy ra :math:`n \mid (f_2 \cdot f_3 - f_6)`.

Tương tự, gọi :math:`f_5`, :math:`f_7` và :math:`f_{35}` là kết quả trả về khi nhập :math:`5`, :math:`7` và :math:`35`. Ta nhận được

.. math::

    f_5 & = 66788051164865948223783605396869677445056352267867968640234839015540677264876 \\
    f_7 & = 25469333231403648059708659888338792850140504272696299331424365245642760908571 \\
    f_{35} & = 25850860693609575302160565920815769473222469094759983686766869114847002714718.

Tương tự, vì :math:`35 = 5 \cdot 7` nên :math:`n \mid (f_5 \cdot f_7 - f_{35})`.

Như vậy :math:`n` là ước của

.. math::

    \gcd(f_2 \cdot f_3 - f_6, f_5 \cdot f_7 - f_{35}).

Nói chung ước chung lớn nhất này có thể là một bội nhỏ của :math:`n`, nhưng ở đây ta thu được đúng

.. math::

    n = 76200708443433250012501342992033571586971760218934756930058661627867825188509.

Sử dụng factordb ta tìm được

.. math::

    p = 232086664036792751646261018215123451301, \quad q = 328328681700354546732404725320581286809.

Với số :math:`e` ta chọn :math:`e = 65537` là public exponent được dùng nhiều nhất trên thực tế và kiểm tra :math:`2^e \pmod n` có khớp với :math:`f_2` không, tương tự với :math:`3^e \pmod n` với :math:`f_3`, ... và hoàn toàn trùng kết quả.

Như vậy :math:`e = 65537` và tính

.. math:: d = e^{-1} \pmod{(p-1) \cdot (q-1)},

từ đó decrypt ra được message ban đầu (theo RSA)

.. math:: m = 202010181600.

Sau này đọc bài giải của anh Hiếu (ndh) thì ta mới biết ý nghĩa của plaintext là ``2020-10-18-16-00`` là năm, tháng, ngày, giờ bắt đầu round 2 (múi giờ Novosibirsk, UTC+7).
