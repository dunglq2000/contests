CryptoFox 2025
**************

Olympiad mật mã và bảo mật thông tin CryptoFox 2025.

+-----------+-------------------------------------+-------------------+
| Số thứ tự | Tên bài                             | Tình trạng        |
+===========+=====================================+===================+
| 0         | Хакерская атака                     | Chưa giải         |
+-----------+-------------------------------------+-------------------+
| 1         | Кривизна функции                    | Giải một phần ý 1 |
+-----------+-------------------------------------+-------------------+
| 2         | Странная вселенная                  | Chưa giải         |
+-----------+-------------------------------------+-------------------+
| 3         | Магическая шкатулка                 | Chưa giải         |
+-----------+-------------------------------------+-------------------+
| 4         | Разности для FOX128                 | Hoàn thành ý 1    |
+-----------+-------------------------------------+-------------------+
| 5         | Шифрование в RSA                    | Hoàn thành        |
+-----------+-------------------------------------+-------------------+
| 6         | Подозрительная фотография           | Chưa giải         |
+-----------+-------------------------------------+-------------------+
| 7         | Замены и перестановки               | Hoàn thành        |
+-----------+-------------------------------------+-------------------+
| 8         | Загадочная ошибка                   | Chưa giải         |
+-----------+-------------------------------------+-------------------+
| 9         | Генератор гаммы на основе XSL-схемы | Chưa giải         |
+-----------+-------------------------------------+-------------------+
| 10        | Регистровое преобразование          | Chưa giải         |
+-----------+-------------------------------------+-------------------+
| 11        | Трудный PBKDF                       | Chưa giải         |
+-----------+-------------------------------------+-------------------+

Giới thiệu
==========

Đầu tiên mình xin phép có một số ý kiến về việc trình bày đề thi. Đề thi có một điểm khá khó chịu là không được biên tập thống nhất. Mình hiểu rằng có nhiều người ra đề nhưng ít nhất cũng phải có người chịu trách nhiệm biên tập lại đề mỗi câu chứ. Kí hiệu ở mỗi câu mỗi khác nhau làm mất tính thống nhất của một cuộc thi. Ví dụ, ở câu 1 dùng :math:`1 \leq \sigma(f)`, còn câu 2 dùng :math:`\alpha, \beta \geqslant 0`, khác cách viết dấu bằng ở bất đẳng thức. Một ví dụ khác là kí hiệu trường hữu hạn, ở câu 1 dùng :math:`\mathbb{Z}_p` nhưng câu 4 lại dùng :math:`\mathbb{F}_{2^8}`. Trong trường hợp này mình nghĩ nên thống nhất dùng :math:`\mathrm{GF}(p)` và :math:`\mathrm{GF}(2^8)`, hoặc :math:`\mathbb{F}_p` và :math:`\mathbb{F}_{2^8}`, sẽ hợp lí hơn. Sự không thống nhất cuối cùng còn ở chỗ mỗi đề có font chữ, cỡ chữ khác nhau, thậm chí có đề đánh số trang nhưng có đề không. Vì lý do trên nên khi viết lại đề, mình sẽ thay đổi kí hiệu cho thống nhất.

Về phần nội dung trong đề thì có 4 câu về reverse engineering (câu 0, câu 3, câu 6 và câu 8), còn lại 7 câu về mật mã. Các câu reverse engineering cũng là những thuật toán mật mã được giấu bên trong chương trình. Với kinh nghiệm hạn hẹp về reverse engineering thì mình không làm được những bài đó. =)))

Задача 0. Хакерская атака
=========================

Đây là một bài reverse engineering, và mình không biết làm. :)

Задача 1. Кривизна функции
==========================

Câu hỏi
-------

Đặt :math:`p` là số nguyên tố, :math:`p \geqslant 3`, :math:`\mathbb{F}_p = \{ 0, 1, \ldots, p \}` là trường hữu hạn modulo :math:`p`, :math:`\gamma = e^{\frac{2\pi i}{p}}` là nghiệm phức primitive bậc :math:`p` của :math:`1`.

Với ánh xạ :math:`f: \mathbb{F}_p \to \{ 0, 1 \}` và với phần tử :math:`a \in \mathbb{F}_p` ta định nghĩa số

.. math:: \nu_f(a) = \frac{1}{p}\sum_{x \in \mathbb{F}_p} (-1)^{f(x)} \gamma^{-ax}.

Ta định nghĩa curvature của hàm :math:`f` là đại lượng

.. math:: \sigma(f) = \sum_{a \in \mathbb{F}_p} \lvert \nu_f(a) \rvert.

1. Chứng minh rằng

.. math:: 1 \leqslant \sigma(f) < \sqrt{p},

và chặn dưới đạt dấu bằng khi và chỉ khi :math:`f` là hàm hằng.

2. Chứng minh rằng, nếu :math:`p = 2^{k+1} - 1` và ánh xạ :math:`f_t`, với :math:`t = 0, 1, \ldots, k`, biến đổi từng phần tử :math:`x \in \mathbb{F}_p` theo nghĩa :math:`f_t(x) = x_t \in \{ 0, 1 \}`, trong đó :math:`x_t` là biểu diễn nhị phân của :math:`x`, hay

.. math:: x = x_0 + 2x_1 + \cdots + 2^k x_k,

thì ta có bất đẳng thức

.. math:: \sigma(f_t) < \frac{4}{\pi} \ln p + \frac{9}{5}.

Gợi ý cho câu 2: sử dụng tổng Vinogradnova I.M. là

.. math:: \sum_{h=0}^{p-1} \left|\sum_{j=0}^{N-1} \gamma^{hj}\right| < \frac{2}{\pi} p \ln p + \frac{2}{5} p + N,

với mọi số tự nhiên :math:`p` và :math:`N`.

[TODO] Giải
-----------

Bài này mình giải được một phần câu 1.

Sử dụng biến đổi Fourier rời rạc, đặt

.. math:: u_x = (-1)^{f(x)}, \quad x \in \mathbb{F}_p.

Đặt :math:`U_a = p \cdot \nu_a(f)` thì ta có

.. math:: U_a = \sum_{x = 0}^{p - 1} u_x e^{-2\pi i\frac{a}{p} x}

với :math:`a = 0, 1, \ldots, p - 1`. 

Khi đó, theo biến đổi Fourier rời rạc ngược có thể thấy liên hệ giữa dãy :math:`\{ u_ x \}` theo :math:`\{ U_ a \}` là

.. math:: u_x = \frac{1}{p} \sum_{a = 0}^{p - 1} U_a \cdot e^{2\pi i \frac{x}{p} a}

với :math:`x = 0, 1, \ldots, p - 1`.

Theo định lí Parceval thì

.. math:: \sum_{x = 0}^{p - 1} \lvert u_x \rvert^2 = \frac{1}{p} \sum_{a = 0}^{p - 1} \lvert U_a \rvert^2,

hay

.. math:: \sum_{x = 0}^{p - 1} \left| (-1)^{f(x)} \right|^2 = \frac{1}{p} \sum_{a = 0}^{p - 1} \left|p \cdot \nu_f(a)\right|^2 = \frac{1}{p} \sum_{a = 0}^{p - 1} p^2 \left|\nu_f(a)\right|^2 = p \sum_{a = 0}^{p - 1} \left|\nu_f(a)\right|^2.

Sử dụng bất đẳng thức Cauchy, với hai vector bất kì

.. math:: \bm{s} = (s_0, s_1, \ldots, s_{n-1}), \ \bm{t} = (t_0, t_1, \ldots, t_{n-1})

ta có

.. math:: (s_0 t_0 + s_1 t_1 + \cdots + s_{n-1} t_{n-1})^2 \leqslant (s_0^2 + s_1^2 + \cdots + s_{n-1}^2)(t_0^2 + t_1^2 + \cdots t_{n-1}^2).

Cho :math:`s_i = 1` và :math:`t_i = \left| \nu_f(i) \right|` với :math:`i = 0, 1, \ldots, p - 1` ta có

.. math:: p \sum_{a = 0}^{p - 1} \left|\nu_f(a)\right|^2 = (1 + 1 + \cdots + 1)\left(\sum_{a = 0}^{p - 1} \left|\nu_f(a)\right|^2\right) \geqslant \left(\sum_{a = 0}^{p - 1}\left|\nu_f(a)\right|\right)^2.

Do :math:`f: \mathbb{F}_p \to \{ 0, 1 \}` nên :math:`(-1)^{f(x)} \in \{ -1, 1 \}`, suy ra :math:`\left|(-1)^{f(x)}\right|^2 = 1` với mọi :math:`x = 0, 1, \ldots, p - 1`.

Như vậy bất đẳng thức trên có thể thu được

.. math:: p = \sum_{x = 0}^{p - 1} \left|(-1)^{f(x)}\right|^2 =p \sum_{a = 0}^{p - 1} \left|\nu_f(a)\right|^2 \geqslant \left(\sum_{a=0}^{p-1} \left| \nu_f(a) \right|\right)^2 = \left(\sigma(f)\right)^2,

tương đương với

.. math:: \sigma(f) \leqslant \sqrt{p}.

Dấu bằng xảy ra khi và chỉ khi :math:`\left| \nu_f(a) \right|` là hằng số nhưng dễ thấy điều này không thể xảy ra. Do đó có thể kết luận

.. math:: \boxed{\sigma(f) < \sqrt{p}.}

Задача 2. Странная вселенная
============================

Câu hỏi
-------

Trong một vũ trụ lạ thường nọ, gọi là Strange Universe, chúng ta thực hiện các thí nghiệm quantum.

Kết thúc một thí nghiệm, chúng ta nhận được toán tử quantum :math:`A` và các trạng thái quantum :math:`\lvert x \rangle` và :math:`\lvert y \rangle`, ở đây

.. math:: A(\alpha \lvert x \rangle + \beta \lvert y \rangle) \neq \alpha A(\lvert x \rangle) + \beta A(\lvert y \rangle)

với :math:`\alpha, \beta \geqslant 0` và :math:`\alpha + \beta = 1`. Chúng ta muốn tiếp tục thí nghiệm nhưng các thiết bị đã hỏng.

Chúng ta sử dụng một kênh truyền quantum để trao đổi thông tin, và chúng ta cần trả lời các câu hỏi sau:

1. Trong Strange Universe, giao thức mật mã BB84 có không an toàn không? Nếu có thì điều kiện nào khiến việc này xảy ra?
2. Trong Strange Universe, giao thức mật mã E91 có không an toàn không? Nếu có thì điều kiện nào khiến việc này xảy ra?
3. Trong Strange Universe có tính chất thú vị nào khác của kênh truyền quantum không?

[TODO] Giải
-----------

Задача 3. Магическая шкатулка
=============================

Lại một bài reverse engineering khác và mình cũng không làm ra.

Задача 4. Разности для FOX128
=============================

Câu hỏi
-------

Grisha phát triển một thuật toán mã khối là FOX128.

Đặt :math:`V_{16}(2^8)` là không gian vector có số chiều bằng :math:`16` trên trường :math:`\mathbb{F}_{2^8}`.

Đặt :math:`S(X)` là nhóm symmetric, tác độ lên tập hữu hạn :math:`X`.

**Phép biến đổi không tuyến tính** của FOX128 là hoán vị :math:`\pi'`. Khi đó với

.. math:: \alpha = (\alpha_1, \alpha_2, \ldots, \alpha_{16}) \in V_{16}(2^8)

ta sẽ có

.. math:: \pi'(\alpha) = (\pi(\alpha_1), \pi(\alpha_2), \ldots, \pi(\alpha_{16}))

với :math:`\pi \in S(\mathbb{F}_{2^8})`.

Hoán vị :math:`\pi` có thể được viết dưới dạng

.. math:: \pi'' = (\pi(0), \pi(1), \ldots, \pi(255))

như sau

+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
|            | :math:`0`   | :math:`1`   | :math:`2`   | :math:`3`   | :math:`4`   | :math:`5`   | :math:`6`   | :math:`7`   | :math:`8`   | :math:`9`   | :math:`10`  | :math:`11`  | :math:`12`  | :math:`13`  | :math:`14`  | :math:`15`  |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`0`  | :math:`252` | :math:`238` | :math:`221` | :math:`17`  | :math:`207` | :math:`110` | :math:`49`  | :math:`22`  | :math:`251` | :math:`196` | :math:`250` | :math:`218` | :math:`35`  | :math:`197` | :math:`4`   | :math:`77`  |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`1`  | :math:`233` | :math:`119` | :math:`240` | :math:`219` | :math:`147` | :math:`46`  | :math:`153` | :math:`186` | :math:`23`  | :math:`54`  | :math:`241` | :math:`187` | :math:`20`  | :math:`205` | :math:`95`  | :math:`193` |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`2`  | :math:`249` | :math:`24`  | :math:`101` | :math:`90`  | :math:`226` | :math:`92`  | :math:`239` | :math:`33`  | :math:`129` | :math:`28`  | :math:`60`  | :math:`66`  | :math:`139` | :math:`1`   | :math:`142` | :math:`79`  |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`3`  | :math:`5`   | :math:`132` | :math:`2`   | :math:`174` | :math:`227` | :math:`106` | :math:`143` | :math:`160` | :math:`6`   | :math:`11`  | :math:`237` | :math:`152` | :math:`127` | :math:`212` | :math:`211` | :math:`31`  |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`4`  | :math:`235` | :math:`52`  | :math:`44`  | :math:`81`  | :math:`234` | :math:`200` | :math:`72`  | :math:`171` | :math:`242` | :math:`42`  | :math:`104` | :math:`162` | :math:`253` | :math:`58`  | :math:`206` | :math:`204` |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`5`  | :math:`181` | :math:`112` | :math:`14`  | :math:`86`  | :math:`8`   | :math:`12`  | :math:`118` | :math:`18`  | :math:`191` | :math:`114` | :math:`19`  | :math:`71`  | :math:`156` | :math:`183` | :math:`93`  | :math:`135` |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`6`  | :math:`21`  | :math:`161` | :math:`150` | :math:`41`  | :math:`16`  | :math:`123` | :math:`154` | :math:`199` | :math:`243` | :math:`145` | :math:`120` | :math:`111` | :math:`157` | :math:`158` | :math:`178` | :math:`177` |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`7`  | :math:`50`  | :math:`117` | :math:`25`  | :math:`61`  | :math:`255` | :math:`53`  | :math:`138` | :math:`126` | :math:`109` | :math:`84`  | :math:`198` | :math:`128` | :math:`195` | :math:`189` | :math:`13`  | :math:`87`  |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`8`  | :math:`223` | :math:`245` | :math:`36`  | :math:`169` | :math:`62`  | :math:`168` | :math:`67`  | :math:`201` | :math:`215` | :math:`121` | :math:`214` | :math:`246` | :math:`124` | :math:`34`  | :math:`185` | :math:`3`   |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`9`  | :math:`224` | :math:`15`  | :math:`236` | :math:`222` | :math:`122` | :math:`148` | :math:`176` | :math:`188` | :math:`220` | :math:`232` | :math:`40`  | :math:`80`  | :math:`78`  | :math:`51`  | :math:`10`  | :math:`74`  |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`10` | :math:`167` | :math:`151` | :math:`96`  | :math:`115` | :math:`30`  | :math:`0`   | :math:`98`  | :math:`68`  | :math:`26`  | :math:`184` | :math:`56`  | :math:`130` | :math:`100` | :math:`159` | :math:`38`  | :math:`65`  |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`11` | :math:`173` | :math:`69`  | :math:`70`  | :math:`146` | :math:`39`  | :math:`94`  | :math:`85`  | :math:`47`  | :math:`140` | :math:`163` | :math:`165` | :math:`125` | :math:`105` | :math:`213` | :math:`149` | :math:`59`  |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`12` | :math:`7`   | :math:`88`  | :math:`179` | :math:`64`  | :math:`134` | :math:`172` | :math:`29`  | :math:`247` | :math:`48`  | :math:`55`  | :math:`107` | :math:`228` | :math:`136` | :math:`217` | :math:`231` | :math:`137` |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`13` | :math:`225` | :math:`27`  | :math:`131` | :math:`73`  | :math:`76`  | :math:`63`  | :math:`248` | :math:`254` | :math:`141` | :math:`83`  | :math:`170` | :math:`144` | :math:`202` | :math:`216` | :math:`133` | :math:`97`  |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`14` | :math:`32`  | :math:`113` | :math:`103` | :math:`164` | :math:`45`  | :math:`43`  | :math:`9`   | :math:`91`  | :math:`203` | :math:`155` | :math:`37`  | :math:`208` | :math:`190` | :math:`229` | :math:`108` | :math:`82`  |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`15` | :math:`89`  | :math:`166` | :math:`116` | :math:`210` | :math:`230` | :math:`244` | :math:`180` | :math:`192` | :math:`209` | :math:`102` | :math:`175` | :math:`194` | :math:`57`  | :math:`75`  | :math:`99`  | :math:`182` |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+

Ở bảng trên, phần tử hàng :math:`i` và cột :math:`j` (:math:`0 \leqslant i, j \leqslant 15`) là giá trị :math:`\pi(16 i + j)`.

**Phép biến đổi tuyến tính** của phần tử :math:`\alpha = (\alpha_1, \ldots, \alpha_{16})` với :math:`\alpha \in V_{16}(2^8)` được kí hiệu là :math:`h`. Khi đó với phần tử :math:`\alpha = (\alpha_1, \ldots, \alpha_{16})` ta chuyển thành dạng ma trận

.. math:: 
    
    A = \begin{pmatrix}
        \alpha_1 & \alpha_2 & \alpha_3 & \alpha_4 \\
        \alpha_5 & \alpha_6 & \alpha_7 & \alpha_8 \\
        \alpha_9 & \alpha_{10} & \alpha_{11} & \alpha_{12} \\
        \alpha_{13} & \alpha_{14} & \alpha_{15} & \alpha_{16} \\
    \end{pmatrix}.

Khi đó :math:`h(\alpha)` là ma trận :math:`B`, được tính theo công thức:

.. math:: 
    
    B = \begin{pmatrix}
        0 & 1 & 1 & 1 \\ 1 & 0 & 1 & 1 \\ 1 & 1 & 0 & 1 \\ 1 & 1 & 1 & 0
    \end{pmatrix} \cdot A,

với phép cộng và nhân được thực hiện giống phép cộng và nhân trên các phần tử của trường.

**Phép cộng với khóa** :math:`k` là ánh xạ có dạng

.. math:: \nu_k(\alpha) = \alpha \oplus k,

với :math:`\oplus` là toán tử cộng từng bit theo modulo :math:`2` (phép XOR), và :math:`\alpha, k \in V_{16}(2^8)`.

Khi đó, hàm mã hóa đối với bản rõ :math:`\alpha \in V_{16}(2^8)` có dạng

.. math:: g_{k_1 k_2}(\alpha) = \nu_{k_2} h \pi' v_{k_1} (\alpha).

Grisha sử dụng mode ECB để mã hóa từ `ПРИВЕДЕНИЕ`. Ở đây anh ấy dùng bảng sau để encode kí tự tiếng Nga sang phần tử thuộc :math:`\mathbb{F}_{2^8}` và để gọn mình sẽ viết ở dạng thập phân.

+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+
| А          | У          | О          | И          | Э          | Ы          | Я          | Ю          | Е          | Ё          | Б          | В          | Г          | Д          | Ж          | З          | Й          |
+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+
| :math:`0`  | :math:`1`  | :math:`2`  | :math:`3`  | :math:`4`  | :math:`5`  | :math:`6`  | :math:`7`  | :math:`8`  | :math:`9`  | :math:`10` | :math:`11` | :math:`12` | :math:`13` | :math:`14` | :math:`15` | :math:`16` |
+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+
| К          | Л          | М          | Н          | П          | Р          | С          | Т          | Ф          | Х          | Ц          | Ч          | Ш          | Щ          | Ъ          | Ь          | ...        |
+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+
| :math:`17` | :math:`18` | :math:`19` | :math:`20` | :math:`21` | :math:`22` | :math:`23` | :math:`24` | :math:`25` | :math:`26` | :math:`27` | :math:`28` | :math:`29` | :math:`30` | :math:`31` | :math:`32` | ...        |
+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+------------+

Khi sử dụng FOX128 cipher thì chúng ta sẽ thêm vào phía trước các số :math:`0` cho đủ vector gồm :math:`16` phần tử. Ví dụ sau khi encode thông điệp chúng ta có vector :math:`(25, 2, 17, 23)` thì chúng ta pad thành

.. math:: \alpha = (0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 2, 17, 23).

Chúng ta biết rằng khi mã hóa thông điệp `ПРИВЕДЕНИЕ`, ta thu được bản mã

.. math:: \beta_1 = (216, 121, 18, 144, 93, 121, 17, 11, 114, 81, 251, 135, 200, 53, 54, 79)

Sau đó Grisha mã hóa một thông điệp khác với cùng khóa con :math:`k_1`, :math:`k_2` như trên với những thông điệp có nghĩa khác nhau nhằm mục đích nghiên cứu sự phụ thuộc giữa các bản rõ với nhau và với bản mã. Khi đó, với một bản rõ nào đó Grisha đã mã hóa thành

.. math:: \beta_2 = (216, 121, 230, 68, 93, 121, 229, 223, 114, 81, 251, 83, 200, 53, 194, 79).

Grisha đã làm mất thí nghiệm của mình và không còn thông tin về khóa, cũng như bản rõ tương ứng với :math:`\beta_2`. Hãy giúp anh ấy.

1. Khôi phục bản rõ tương ứng bản mã :math:`\beta_2`.
2. Đưa ra thuật toán tối ưu khôi phục lại :math:`k_2` hoặc một phần của nó, nếu biết rằng khi tạo khóa con :math:`k_2` chỉ sử dụng các nguyên âm.

[TODO] Giải
-----------

Mình giải được câu 1 và chưa kịp làm câu 2.

Giả sử chúng ta mã hóa hai bản rõ :math:`\bm{a}, \bm{a}' \in V_{16}(2^8)` với cùng khóa :math:`\bm{k}_1` và :math:`\bm{k}_2`.

Đặt

.. math:: \bm{a} = (a_1, a_2 \ldots, a_{16}), \ \bm{a}' = (a_1', a_2', \ldots, a_{16}'),

với :math:`a_i` và :math:`a_i' \in \mathbb{F}_{2^8}`, :math:`i = 1, 2, \ldots, 16`.

Đặt

.. math:: \bm{k}_1 = (k_{1, 1}, k_{1, 2}, \ldots, k_{1, 16}), \ \bm{k}_2 = (k_{2,1}, k_{2,2}, \ldots, k_{2, 16}),

với :math:`k_{1, i}` và :math:`k_{2, i} \in \mathbb{F}_{2^8}`, :math:`i = 1, \ldots, 16`.

Sau phép biến đổi :math:`\nu_{\bm{k}_1}` ta được

.. math:: 

    \nu_{\bm{k}_1}(\bm{a}) = (a_1 \oplus k_{1,1}, \ldots, a_{16} \oplus k_{1, 16}) = (b_1, \ldots, b_{16}), \\
    \nu_{\bm{k}_1}(\bm{a}') = (a_1' \oplus k_{1,1}, \ldots, a_{16}' \oplus k_{1, 16}) = (b_1', \ldots, b_{16}'),

ở đây đặt :math:`b_i = a_i \oplus k_{1, i}`, tương tụ :math:`b_i' = a_i' \oplus k_{1, i}`.

Sau phép biến đổi thứ hai :math:`\pi'` ta có

.. math:: 

    \pi'(b_1, \ldots, b_{16}) = (c_1, \ldots, c_{16}), \\
    \pi'(b_1', \ldots, b_{16}') = (c_1', \ldots, c_{16}'),

với :math:`c_i = \pi(b_i)` và :math:`c_i' = \pi(b_i')`.

Sau phép biến đổi tuyến tính :math:`h` ta có

.. math:: h(c_1, \ldots, c_{16}) = (d_1, \ldots, d_{16}), \quad h(c_1', \ldots, c_{16}') = (d_1', \ldots, d_{16}').

Cuối cùng, phép biến đổi :math:`\nu_{\bm{k}_2}`:

.. math:: 

    \nu_{\bm{k}_2}(d_1, \ldots, d_{16}) = (d_1 \oplus k_{2, 1}, \ldots, d_{16} \oplus k_{2, 16}) = (e_1, \ldots, e_{16}), \\
    \nu_{\bm{k}_2}(d_1', \ldots, d_{16}') = (d_1' \oplus k_{2, 1}, \ldots, d_{16}' \oplus k_{2, 16}) = (e_1', \ldots, e_{16}').

Lúc này bản mã chính là các vector :math:`(e_1, \ldots, e_{16})` và :math:`(e_1', \ldots, e_{16}')`.

Nếu XOR hai bản mã với nhau thì

.. math:: (e_1 \oplus e_1', \ldots, e_{16} \oplus e_{16}') = (e_1, \ldots, e_{16}) \oplus (e_1', \ldots, e_{16}') = (d_1 \oplus d_1', \ldots, d_{16} \oplus d_{16}'),

nhưng :math:`h` là phép biến đổi tuyến tính nên

.. math:: (d_1 \oplus d_1', \ldots, d_{16} \oplus d_{16}') = h(c_1, \ldots, c_{16}) \oplus h(c_1', \ldots, c_{16}') = h(c_1 \oplus c_1', \ldots, c_{16} \oplus c_{16}').

Như vậy có thể nói rằng

.. math:: (e_1 \oplus e_1', \ldots, e_{16} \oplus e_{16}') = h(c_1 \oplus c_1', \ldots, c_{16} \oplus c_{16}').

Ma trận :math:`H` và nghịch đảo của nó là như nhau, do đó có thể viết lại biểu thức trên thành

.. math:: h(e_1 \oplus e_1', \ldots, e_{16} \oplus e_{16}') = (c_1 \oplus c_1', \ldots, c_{16} \oplus c_{16}').

Vì :math:`c_i = \pi(a_i \oplus k_{1, i})` và :math:`c_i' = \pi(a_i' \oplus k_{1, i})`, và ta tính được :math:`h(e_1 \oplus e_1', \ldots, e_{16} \oplus e_{16}')` nên sẽ tìm được các phần tử :math:`c_1 \oplus c_1'`, ..., :math:`c_{16} \oplus c_{16}'`.

Lúc này ta thử các :math:`k_{1, i}` với :math:`i = 1, 2, \ldots, 16` để xem :math:`k_{1, i}` nào thỏa mãn

.. math:: c_i \oplus c_i' = \pi(a_i \oplus k_{1, i}) \oplus \pi(a_i' \oplus k_{1, i})

với điều kiện là :math:`0 \leqslant a_i' \leqslant 32` (theo bảng code bên trên).

Chương trình giải mình để ở :download:`đây <solve_fox128_1.py>`.

Theo kết quả chạy chương trình thì các vị trí :math:`i` sau cho :math:`a_i = a_i'`:

.. math:: i \in \{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14 \}.

Như vậy từ tiếng Nga chúng ta cần tìm có dạng `ПРИВ_ДЕНИ_`. Lưu ý rằng chúng ta đã bỏ các số :math:`0` đứng trước trong quá trình decode.

Ở đây, dễ thấy sau kí tự `В` phải là nguyên âm, tức là vị trí :math:`i = 10`. Có hai ứng cử viên cho vị trí này là kí tự `О` (encode thành :math:`2`) và `И` (encode thành :math:`3`). Trong tiếng Nga có từ "привидение" nên ta sẽ chọn kí tự `И` cho :math:`i = 10`.

Vì "привидение" là từ giống trung nên kết thúc của nó (trong 6 cách) là "е", "я", "и" và "й". Từ chương trình giải bên trên chỉ có kí tự `Я` là được chấp nhận.

Như vậy, kết quả là `ПРИВИДЕНИЯ`.

Задача 5. Шифрование в RSA
==========================

Câu hỏi
-------

Ta sử dụng thuật toán RSA để mã hóa với tham số sau

.. math:: 

    \begin{array}{cl}
        n = & 307113764813174451979648861837374183706400686964058131652523053759767112686 \\
            & 921105760986215994148574439656212523327564727423276973650662361700716117034 \\
            & 585310519473492500005549242633169443931102631059829073180528952729440631440 \\
            & 857431430574567858285873536218804878054530675205445624011186425555088867207 \\
            & 5353043 \\
        e = & 5.
    \end{array}

Ta chặn được hai bản mã:

.. math:: 

    \begin{array}{cl}
        c1 = & 693089265758848025485688850665080349728312487495309688707596506807354538873 \\
            & 067996032536142769206361054315964464537700685311216289298705857554525830204 \\
            & 6252205886190035304282857903311014974554686997348541958002897243 \\
        c2 = & 693089265758848025485688850665080349728313078514173314915077310887781132564 \\
            & 247507141242724120234983668164062692763390490140270935400218398173406875322 \\
            & 8613850558221595769683504261263861404892836544032097068963073024.
    \end{array}

Hãy giải mã các thông điệp, biết rằng bản rõ :math:`m_1` và :math:`m_2` có liên hệ :math:`m_2 = m_1 + 1`.

Giải
----

Sử dụng Coppersmith attack ở file :download:`solve_rsa.py`.

Задача 6. Подозрительная фотография
===================================

Thêm một bài reverse engineering và lần này là Android. Mình chịu chết.

Задача 7. Замены и перестановки
===============================

Câu hỏi
-------

Chúng ta chặn được một thông điệp mã hóa được truyền qua radio và lưu vào file `ct.txt`. Chúng ta cần biết thông điệp ban đầu là gì.

Biết rằng thông điệp được mã hóa bằng mã dòng (stream cipher). Khóa là một dãy :math:`\gamma_1`, :math:`\gamma_2`, ... được sinh ra từ một khóa ban đầu và đi qua thuật toán sinh khóa.

Thuật toán sinh khóa nhận đầu vào là khóa :math:`256` bits.

:math:`256` bits đầu tiên nhận được từ việc mã hóa dãy các bytes `\0` bằng thuật toán Skipjack với khóa :math:`K_{root}` (:math:`80` bits) và :math:`IV` (:math:`64` bits) là

.. math:: IV = \{ 0x43, 0x72, 0x79, 0x70, 0x74, 0x46, 0x6f, 0x78 \}.

Việc mã hóa được thực hiện bằng mode CFB, nghĩa là

.. math:: K_0 = \mathsf{Encrypt}_{cfb}(K_{root}, IV, [0x00] \cdot 32),

trong đó :math:`K_{root} \in \{ 0, 1 \}^{80}`, :math:`IV \in \{ 0, 1 \}^{64}`, và bản mã là :math:`K_0 \in \{ 0, 1 \}^{256}`.

:math:`256` bits tiếp theo được sinh bởi kết quả mã hóa bên trên, tức là

.. math:: K_1 = \mathsf{Encrypt}_{cfb}(K_{root}, IV, K_0).

Thực hiện tương tự như vậy ta có công thức tổng quát là

.. math:: K_i = \mathsf{Encrypt}_{cfb}(K_{root}, IV, K_{i-1}),

với :math:`i \in \mathbb{N}`, :math:`K_i \in \{ 0, 1 \}^{256}`.

Dãy :math:`\{ \gamma_n \}` nhận được từ các giá trị :math:`K_i` và :math:`K_0`. Ở đây, :math:`4` bits đầu tiên của dãy :math:`\{ \gamma_n \}` nhận được từ :math:`K_0` theo quy tắc

.. math:: 
    
    \gamma_j = \begin{cases}
        0 \ \text{nếu} \ K_0[j] = 0, \\
        1 \ \text{trong trường hợp khác},
    \end{cases}

trong đó :math:`K_0[j]` là khối :math:`64` bits thứ :math:`i` của :math:`K_0`, :math:`\gamma_j \in \{ 0, 1 \}` với :math:`j = 0, 1, 2, 3`.

Các bit tiếp theo được sinh tương tự theo quy tắc

.. math:: 
    
    \gamma_j = \begin{cases}
        0 \ \text{nếu} \ K_{j / 4}[j \% 4] = 0, \\
        1 \ \text{trong trường hợp khác},
    \end{cases}

với :math:`a \% b` là số dư khi chia :math:`a` cho :math:`b`, :math:`j \in \mathbb{N}`.

Ví dụ ta có khóa

.. math:: 

    K_j = \{ \mathrm{0x0c}, \mathrm{0xea}, \mathrm{0x66}, \mathrm{0xe0}, \mathrm{0x96}, \mathrm{0xbd}, \mathrm{0xf1}, \mathrm{0xc0}, \\
    \mathrm{0x9c}, \mathrm{0xc2}, \mathrm{0xf1}, \mathrm{0x62}, \mathrm{0xa5}, \mathrm{0x44} ,\mathrm{0x1f}, \mathrm{0xb7}, \\
    \mathrm{0xdd}, \mathrm{0x4b}, \mathrm{0x2b}, \mathrm{0xbf}, \mathrm{0xd6}, \mathrm{0xd9}, \mathrm{0x64}, \mathrm{0x73}, \\
    \mathrm{0xb4}, \mathrm{0x97}, \mathrm{0x7b}, \mathrm{0x39}, \mathrm{0x06}, \mathrm{0x02}, \mathrm{0x4c}, \mathrm{0xb8} \}

thì ta sẽ chia được thành :math:`4` đoạn, mỗi đoạn :math:`64` bits (hay :math:`8` bytes) như sau

.. math:: 

    K_j[0] & = \{ \mathrm{0x0c}, \mathrm{0xea}, \mathrm{0x66}, \mathrm{0xe0}, \mathrm{0x96}, \mathrm{0xbd}, \mathrm{0xf1}, \mathrm{0xc0} \}, \\
    K_j[1] & = \{ \mathrm{0x9c}, \mathrm{0xc2}, \mathrm{0xf1}, \mathrm{0x62}, \mathrm{0xa5}, \mathrm{0x44}, \mathrm{0x1f}, \mathrm{0xb7} \}, \\
    K_j[2] & = \{ \mathrm{0xdd}, \mathrm{0x4b}, \mathrm{0x2b}, \mathrm{0xbf}, \mathrm{0xd6}, \mathrm{0xd9}, \mathrm{0x64}, \mathrm{0x73} \}, \\
    K_j[3] & = \{ \mathrm{0xb4}, \mathrm{0x97}, \mathrm{0x7b}, \mathrm{0x39}, \mathrm{0x06}, \mathrm{0x02}, \mathrm{0x4c}, \mathrm{0xb8} \}.

Bản mã nhận được theo công thức

.. math:: c_i = p_i \oplus \gamma_i

với :math:`c_i, p_i \in \{ 0, 1 \}` và :math:`i = 0, 1, 2, \ldots`

Hãy phân tích và khôi phục thông điệp ban đầu, và xác định họ của tác giả nếu biết file được encode bằng cp1251.

Giải
----

Thuật toán sinh khóa nhận đầu vào là khóa :math:`256` bits.

:math:`256` bits đầu tiên nhận được từ việc mã hóa dãy các bytes `\0` bằng thuật toán Skipjack với khóa :math:`K_{root}` (:math:`80` bits) và :math:`IV` (:math:`64` bits) là

.. math:: IV = \{ 0x43,0x72,0x79,0x70,0x74,0x46,0x6f, 0x78 \}.

Việc mã hóa được thực hiện bằng mode CFB, nghĩa là

.. math:: K_0 = \mathsf{Encrypt}_{cfb}(K_{root}, IV, [0x00] \cdot 32),

trong đó :math:`K_{root} \in \{ 0, 1 \}^{80}`, :math:`IV \in \{ 0, 1 \}^{64}`, và bản mã là :math:`K_0 \in \{ 0, 1 \}^{256}`.

Đặt :math:`\mathsf{Enc}(P)` là hàm mã hóa bản rõ :math:`P` :math:`64` bits bằng thuật toán Skipjack với khóa :math:`K_{root}` :math:`80` bits.

Giả sử :math:`K_0 = (K_0[0], K_0[1], K_0[2], K_0[3]) \in \{ 0, 1 \}^{256}`, với :math:`K_0[j] \in \{ 0, 1 \}^{64}`, :math:`j = 0, 1, 2, 3`. Theo mode CFB thì

.. math:: 

    K_0[0] & = \mathsf{Enc}(IV) \oplus ([0x00] \cdot 8) = \mathsf{Enc}(IV), \\
    K_0[1] & = \mathsf{Enc}(K_0[0]) \oplus ([0x00] \cdot 8) = \mathsf{Enc}(K_0[0]), \\
    K_0[2] & = \mathsf{Enc}(K_0[1]) \oplus ([0x00] \cdot 8) = \mathsf{Enc}(K_0[1]), \\
    K_0[3] & = \mathsf{Enc}(K_0[2]) \oplus ([0x00] \cdot 8) = \mathsf{Enc}(K_0[2]).

:math:`256` bits tiếp theo được tạo với cơ chế tương tự:

.. math:: K_1 = \mathsf{Encrypt}_{cfb}(K_{root}, IV, K_0).

Giả sử :math:`K_1 = (K_1[0], K_1[1], K_1[2], K_1[3]) \in \{ 0, 1 \}^{256}` với :math:`K_1[j] \in \{ 0, 1 \}^{64}`, :math:`j = 0, 1, 2, 3`. Tương tự, theo mode CFB thì

.. math:: 

    K_1[0] & = \mathsf{Enc}(IV) \oplus K_0[0], \\
    K_1[1] & = \mathsf{Enc}(K_0[0]) \oplus K_0[1], \\
    K_1[2] & = \mathsf{Enc}(K_0[1]) \oplus K_0[2], \\
    K_1[3] & = \mathsf{Enc}(K_0[2]) \oplus K_0[3].

Tổng quát:

.. math:: K_i = \mathsf{Encrypt}_{cfb}(K_{root}, IV, K_{i-1}),

với :math:`i \in \mathbb{N}` và :math:`K_i \in \{ 0, 1 \}^{256}`.

Giả sử

.. math:: K_i = (K_i[0], K_i[1], K_i[2], K_i[3]) \in \{ 0, 1 \}^{256}

với :math:`K_i[j] \in \{ 0, 1 \}^{64}`, :math:`j = 0, 1, 2, 3`.

Theo mode CFB thì

.. math:: 

    K_i[0] & = \mathsf{Enc}(IV) \oplus K_{i-1}[0], \\
    K_i[1] & = \mathsf{Enc}(K_0[0]) \oplus K_{i-1}[1], \\
    K_i[2] & = \mathsf{Enc}(K_0[1]) \oplus K_{i-1}[2], \\
    K_i[3] & = \mathsf{Enc}(K_0[2]) \oplus K_{i-1}[3].

Dãy :math:`\{ \gamma_n \}` nhận được từ các giá trị :math:`K_i` và :math:`K_0`. Ở đây, :math:`4` bits đầu tiên của dãy :math:`\{ \gamma_n \}` nhận được từ :math:`K_0` theo quy tắc

.. math:: 
    
    \gamma_j = \begin{cases}
        0 \ \text{nếu} \ K_0[j] = 0, \\
        1 \ \text{trong trường hợp khác},
    \end{cases}

trong đó :math:`K_0[j]` là khối :math:`64` bits thứ :math:`i` của :math:`K_0`, :math:`\gamma_j \in \{ 0, 1 \}` với :math:`j = 0, 1, 2, 3`.

Các bit tiếp theo được sinh tương tự theo quy tắc

.. math:: 
    
    \gamma_j = \begin{cases}
        0 \ \text{nếu} \ K_{j / 4}[j \% 4] = 0, \\
        1 \ \text{trong trường hợp khác},
    \end{cases}

với :math:`a \% b` là số dư khi chia :math:`a` cho :math:`b`, :math:`j \in \mathbb{N}`.

Chúng ta sẽ tìm quy luật đối với dãy :math:`\{ \gamma_n \}`:

Ta cần file :download:`problem-7/skipjack.py` để thực hiện thuật toán Skipjack.

Tiếp theo, chúng ta thử mã hóa với :math:`K_{root}` bất kì để quan sát xem có quy luật nào cho :math:`K_i` không với file :download:`problem-7/find_rules.py`.

Dễ thấy bản mã (dạng hex) có dạng sau:

.. code-block:: 

    0d16dceddfc805c1 47122ce9d3b7983a 02fd48e270666df7 28a8d35b20fbd167
    0000000000000000 c4a1be9a50040a49 a266cc2ec5ada370 59c24fdb72f24d49
    0d16dceddfc805c1 83b3927383b39273 1374429b74bf2dc5 b2e5c38addfd9bbc
    0000000000000000 0000000000000000 90c7d0e8f70cbfb6 b4975af551b93659
    0d16dceddfc805c1 47122ce9d3b7983a 923a980a876ad241 f786cb6cd09fa275
    0000000000000000 c4a1be9a50040a49 32a11cc632a11cc6 a16a8af18673e3e8
    0d16dceddfc805c1 83b3927383b39273 83b3927383b39273 1078044437616d5d
    0000000000000000 0000000000000000 0000000000000000 93cb9637b4d2ff2e
    0d16dceddfc805c1 47122ce9d3b7983a 02fd48e270666df7 bb63456c94292e49
    0000000000000000 c4a1be9a50040a49 a266cc2ec5ada370 ca09d9ecc620b267
    0d16dceddfc805c1 83b3927383b39273 1374429b74bf2dc5 212e55bd692f6492
    0000000000000000 0000000000000000 90c7d0e8f70cbfb6 275cccc2e56bc977
    0d16dceddfc805c1 47122ce9d3b7983a 923a980a876ad241 644d5d5b644d5d5b
    0000000000000000 c4a1be9a50040a49 32a11cc632a11cc6 32a11cc632a11cc6
    0d16dceddfc805c1 83b3927383b39273 83b3927383b39273 83b3927383b39273
    0000000000000000 0000000000000000 0000000000000000 0000000000000000

Ta chỉ quan tâm các khối :math:`64` bits toàn các byte `\0` nên bản mã dạng hex trên tương đương với

.. code-block:: 

    ---------------- ---------------- ---------------- ----------------
    0000000000000000 ---------------- ---------------- ----------------
    ---------------- ---------------- ---------------- ----------------
    0000000000000000 0000000000000000 ---------------- ----------------
    ---------------- ---------------- ---------------- ----------------
    0000000000000000 ---------------- ---------------- ----------------
    ---------------- ---------------- ---------------- ----------------
    0000000000000000 0000000000000000 0000000000000000 ----------------
    ---------------- ---------------- ---------------- ----------------
    0000000000000000 ---------------- ---------------- ----------------
    ---------------- ---------------- ---------------- ----------------
    0000000000000000 0000000000000000 ---------------- ----------------
    ---------------- ---------------- ---------------- ----------------
    0000000000000000 ---------------- ---------------- ----------------
    ---------------- ---------------- ---------------- ----------------
    0000000000000000 0000000000000000 0000000000000000 0000000000000000

Ở đây, ``----------------`` là khối khác :math:`0`. Thử mã hóa nhiều lần vói :math:`K_{root}` khác nhau thì ta thấy bản mã đều có dạng chung như trên.

Từ đó có thể nói dãy :math:`\{ \gamma_n \}` không phụ thuộc vào khóa. Lúc này ta có thể sử dụng :math:`K_{root}` tùy ý và sinh ra dãy :math:`\{ \gamma_n \}`.

File giải mã là :download:`problem-7/solve.py`.

Kết quả giải mã là

    EVALUATION OF THE SITUATION UNTIL NOW IT HAD TO BE EXPECTED THAT THE ENEMY WOULD TRY TO CROSS THE DANUBE WITH THE TROOPS ASSEMBLING AT VIDIN LOMPALANKA AND NEAR DRUTSCHUK WITH THE GOAL TO CUT OFF THE RAILWAYS BETWEEN ORSOVA AND CRAIOVA AND TO PUSH FORWARD TO BUCHAREST SINCE NOVEMBER 1 1918 IT APPEARS THAT THE SERBIAN ARMIES TOGETHER WITH THREE FRENCH DIVISIONS AREENGAGED IN AN ADVANCE TOWARD BELGRADE SEMENDRIA AND THE INTENDED ATTACK AT VIDI AND LOM PALANKA SEEMS TO HAVE BEEN ABANDONED IT HAS TO BE EXPECTED THE DEPLOYMENT OF STRONGER FORCES AT THE DANUBE SOUTH OF SVISTOVRUSTSCHUK SPECIALLY AFTER THE PEACE AGREEMENT OF TURKEY HENCE IT IS MOST LIKELY THAT THE SERBIAN ARMIES REINFORCED BY THE FRENCH INTEND TO CROSS THE DANUBE NEAR BELGRADE SEMENDIA AND THE INTO SOUTHERN REPEAT SOUTHERN HUNGARY WHILE THE TASK OF THE FRENCH ARMY MARCHING SOUTH OF SVISTOV RUTSCHUK REMAINS THE OFFENSIVE TOWARD BUCHAREST IN CONJUNCTION WITH THIS OPERATION IT CANNOT BE RULED OUT THAT THE ROMANIAN FORCES COMING FROM MOLDAVIA OVER THE PASSES OF TOELGYESGIMES AND OITOS WILL INVADE TRANSYLVANIA THUS THE LINES OF COMMUNICATIONS IN THE REAR OF THE OCCUPATION ARMY WHICH HAVE UP TO NOW AS A RESULT OF IS THREATENED WITH ATTACK AND THE FURTHER OCCUPATION OF THE WALL ACHIAAS LAID DOWN IN ORDER FROM OKHEAD QUARTERS 2RMNR11161 WITHOUT DOUBT AND WITH REGARD TO THE AMMUNITION FOOD AND THE COAL STOCK SIT IS UNFEASIBLE IF THE GENERAL ARM ISTICE DOES NOT BECOME EFFECTIVE IN THE FORESEEABLE FUTURE IT IS SUGGESTED THAT THE OCCUPATION ARMY BE WITHDRAWN ATONCE FROM ROMANIA AND TOGETHER WITH THE GERMAN UNITS OF THE FIRST ARMY TO START THE MARCH TOUPPERSILES IA THROUGH HUNGARY APPROVAL IS REQUESTED SIGNED KMIAGROP

Задача 8. Загадочная ошибка
===========================

Thêm một bài reverse engineering C++. Bài này có dùng thêm OpenSSL nhưng mình vẫn không biết làm.

Задача 9. Генератор гаммы на основе XSL-схемы
=============================================

Câu hỏi
-------

Chúng ta tạo thuật toán sinh khóa cho mã dòng

1. Hàm sinh của khóa là ánh xạ :math:`F: \mathbb{F}_2^{64} \to \mathbb{F}_2^{64}`, được xây dựng dựa trên mô hình XSL, rất phổ biến trong việc thiết kế mã khối.
2. Phép biến đổi không tuyến tính là S-box, dựa trên ánh xạ :math:`S: \mathbb{F}_2^8 \to \mathbb{F}_2^8`. S-box có thể biểu diễn qua hoán vị sau

+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
|            | :math:`0`   | :math:`1`   | :math:`2`   | :math:`3`   | :math:`4`   | :math:`5`   | :math:`6`   | :math:`7`   | :math:`8`   | :math:`9`   | :math:`10`  | :math:`11`  | :math:`12`  | :math:`13`  | :math:`14`  | :math:`15`  |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`0`  | :math:`208` | :math:`5`   | :math:`11`  | :math:`222` | :math:`234` | :math:`63`  | :math:`49`  | :math:`228` | :math:`31`  | :math:`202` | :math:`196` | :math:`17`  | :math:`37`  | :math:`240` | :math:`254` | :math:`43`  |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`1`  | :math:`117` | :math:`160` | :math:`174` | :math:`123` | :math:`79`  | :math:`154` | :math:`148` | :math:`65`  | :math:`186` | :math:`111` | :math:`97`  | :math:`180` | :math:`128` | :math:`85`  | :math:`91`  | :math:`142` |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`2`  | :math:`239` | :math:`58`  | :math:`52`  | :math:`225` | :math:`213` | :math:`0`   | :math:`14`  | :math:`219` | :math:`32`  | :math:`245` | :math:`251` | :math:`46`  | :math:`26`  | :math:`207` | :math:`193` | :math:`20`  |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`3`  | :math:`74`  | :math:`159` | :math:`145` | :math:`68`  | :math:`112` | :math:`165` | :math:`171` | :math:`126` | :math:`133` | :math:`80`  | :math:`94`  | :math:`139` | :math:`191` | :math:`106` | :math:`100` | :math:`177` |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`4`  | :math:`242` | :math:`39`  | :math:`41`  | :math:`252` | :math:`200` | :math:`29`  | :math:`19`  | :math:`198` | :math:`61`  | :math:`232` | :math:`230` | :math:`51`  | :math:`7`   | :math:`210` | :math:`220` | :math:`9`   |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`5`  | :math:`87`  | :math:`130` | :math:`140` | :math:`89`  | :math:`109` | :math:`184` | :math:`182` | :math:`99`  | :math:`152` | :math:`77`  | :math:`67`  | :math:`150` | :math:`162` | :math:`119` | :math:`121` | :math:`172` |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`6`  | :math:`205` | :math:`24`  | :math:`22`  | :math:`195` | :math:`247` | :math:`34`  | :math:`44`  | :math:`249` | :math:`2`   | :math:`215` | :math:`217` | :math:`12`  | :math:`56`  | :math:`237` | :math:`227` | :math:`54`  |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`7`  | :math:`104` | :math:`189` | :math:`179` | :math:`102` | :math:`82`  | :math:`135` | :math:`137` | :math:`92`  | :math:`167` | :math:`114` | :math:`124` | :math:`169` | :math:`157` | :math:`72`  | :math:`70`  | :math:`147` |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`8`  | :math:`188` | :math:`105` | :math:`103` | :math:`178` | :math:`134` | :math:`83`  | :math:`93`  | :math:`136` | :math:`115` | :math:`166` | :math:`168` | :math:`125` | :math:`73`  | :math:`156` | :math:`146` | :math:`71`  |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`9`  | :math:`25`  | :math:`204` | :math:`194` | :math:`23`  | :math:`35`  | :math:`246` | :math:`248` | :math:`45`  | :math:`214` | :math:`3`   | :math:`13`  | :math:`216` | :math:`236` | :math:`57`  | :math:`55`  | :math:`226` |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`10` | :math:`131` | :math:`86`  | :math:`88`  | :math:`141` | :math:`185` | :math:`108` | :math:`98`  | :math:`183` | :math:`76`  | :math:`153` | :math:`151` | :math:`66`  | :math:`118` | :math:`163` | :math:`173` | :math:`120` |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`11` | :math:`38`  | :math:`243` | :math:`253` | :math:`40`  | :math:`28`  | :math:`201` | :math:`199` | :math:`18`  | :math:`233` | :math:`60`  | :math:`50`  | :math:`231` | :math:`211` | :math:`6`   | :math:`8`   | :math:`221` |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`12` | :math:`158` | :math:`75`  | :math:`69`  | :math:`144` | :math:`164` | :math:`113` | :math:`127` | :math:`170` | :math:`81`  | :math:`132` | :math:`138` | :math:`95`  | :math:`107` | :math:`190` | :math:`176` | :math:`101` |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`13` | :math:`59`  | :math:`238` | :math:`224` | :math:`53`  | :math:`1`   | :math:`212` | :math:`218` | :math:`15`  | :math:`244` | :math:`33`  | :math:`47`  | :math:`250` | :math:`206` | :math:`27`  | :math:`21`  | :math:`192` |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`14` | :math:`161` | :math:`116` | :math:`122` | :math:`175` | :math:`155` | :math:`78`  | :math:`64`  | :math:`149` | :math:`110` | :math:`187` | :math:`181` | :math:`96`  | :math:`84`  | :math:`129` | :math:`143` | :math:`90`  |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
| :math:`15` | :math:`4`   | :math:`209` | :math:`223` | :math:`10`  | :math:`62`  | :math:`235` | :math:`229` | :math:`48`  | :math:`203` | :math:`30`  | :math:`16`  | :math:`197` | :math:`241` | :math:`36`  | :math:`42`  | :math:`255` |
+------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+

Ở bảng trên, phần tử ở hàng :math:`i` và cột :math:`j` (:math:`0 \leqslant i, j \leqslant 15`) là giá trị S-box của :math:`16i + j`.

1. Biến đổi tuyến tính :math:`L` dựa trên LFSR, nghĩa là :math:`L: \mathbb{F}_2^{64} \to \mathbb{F}_2^{64}` với hệ số của đa thức đặc trưng được viết dưới dạng `0x12a9d9b8c0edf6e79` (ở đây bit cao là hệ số của hạng tử bậc cao, most significant bit). Ở mỗi vòng, thanh ghi sẽ được khai báo bởi một trong các hằng số của vòng và đi qua :math:`64` vòng.

Như vậy, quá trình sinh khóa có dạng

.. math:: k^{(i)} = S(k^{(i-1)}) \oplus L^{64}(C^{(i)}),

với :math:`k^{(i - 1)}` là khóa được sinh trước đó, :math:`k^{(0)}` là khóa đầu vào để sinh toàn bộ dãy khóa, và :math:`C^{(i)}` là hằng số của vòng, gồm

- ``0x6ea276726c487ab8``,
- ``0x5d27bd10dd849401``,
- ``0xdc87ece4d890f4b3``,
- ``0xba4eb92079cbeb02``,
- ``0xb2259a96b4d88e0b``,
- ``0xe7690430a44f7f03``,
- ``0x7bcd1b0b73e32ba5``,
- ``0xb79cb140f2551504``,
- ``0x156f6d791fab511d``,
- ``0xeabb0c502fd18105``,
- ``0xa74af7efab73df16``,
- ``0x0dd208608b9efe06``,
- ``0xc9e8819dc73ba5ae``,
- ``0x50f5b570561a6a07``,
- ``0xf6593616e6055689``,
- ``0xadfba18027aa2a08``.

Phương trình mã hóa có dạng

.. math:: y^{(i)} = x^{(i)} \oplus k^{(i)}

với :math:`y^{(i)}, x^{(i)} \in \mathbb{F}_2^{64}`.

Người truyền tin muốn kiểm tra độ an toàn của thuật toán sinh khóa. Anh ta mã hóa một phần của đoạn văn đầu trong tiểu thuyết "Alice in Wonderland" (tiếng Anh) và thu được bản mã là

.. code-block:: 

    3291999942924df2eb53323558623a949f5d90c4ba2cf0d9883c21ee0fcd8e5348de9d8fecee8b55693a5682396c33b57cdcaa6946fdfe5c50660656cfb03fbfa682db7f20837e3d406340ebf301b8223a7ada2820b5e15756ab0f54e2af8008f181e474757afbdfaf65525e88dadce723653bfc35398852d3e82cfb4815f3f6

Nhiệm vụ của bạn là phân tích thuật toán mã hóa và nếu có lỗ hổng, hãy khai thác nó và tìm khóa mã hóa.

[TODO] Giải
-----------

Задача 10. Регистровое преобразование
=====================================

Câu hỏi
-------

Eva chặn được một đoạn gamma được sinh dựa trên shift register (xem chi tiết ở file :download:`problem-10/PQR.py`):

.. math:: \gamma = 01000000000000010100100001101000111101100010001111.

Hãy tìm giá trị register ban đầu.

[TODO] Giải
-----------

Задача 11. Трудный PBKDF
========================

Câu hỏi
-------

Việc trao đổi file diễn ra trên kênh truyền. Để mã hóa file chúng ta dùng thuật toán sau dựa trên mật khẩu.

Đầu vào là mật khẩu :math:`password` gồm :math:`4` chữ số thập phân, và thông điệp :math:`pt`.

Ta tính khóa :math:`key = \mathsf{SHA256}(password)` và initial vector là

.. math:: IV = \mathsf{PBKDF-HMAC-SHA256}(salt, 2^{30}, 128).

Sử dụng thuật toán mã khối AES256 với mode CBC và khóa :math:`key`, initial vector :math:`IV`, và padding bằng PKCS#7.

Chúng ta có một số file đã bị mã hóa. Biết rằng, qua kênh truyền có thể có nhiễu nên file có thể chứa một số bytes đã bị hỏng. Một trong số đó chứa flag, hãy tìm nó.

[TODO] Giải
-----------

Kết luận
=========

Để viết sau.

