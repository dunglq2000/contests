NSUCRYPTO 2023
**************

Affine cipher
=============

Đây là bài 1 của round 2 và được giải bởi bạn Chương.

Đề bài
--------

Ta xét bảng chữ cái {A, ..., Z, :math:`\alpha`, :math:`\beta`, :math:`\gamma`} có :math:`29` chữ cái. Ta đánh số A, ..., Z từ :math:`0` tới :math:`25`, và :math:`\alpha`, :math:`\beta`, :math:`\gamma` là :math:`26`, :math:`27`, :math:`28`.

Ta sử dụng cryptosystem mã hóa từng khối hai ký tự, gọi là bigram. Với :math:`x` và :math:`y` là hai ký tự của bigram, thì plaintext sẽ là :math:`P = 29 x + y`.

Mã hóa sử dụng biến đổi affine (giống hệ mã affine) là :math:`C = a P + b \pmod{841}`.

Khi phân tích một đoạn văn bản dài, người ta phát hiện ra rằng các bigram sau xuất hiện nhiều nhất ":math:`\beta\gamma`", "UM" và "LC". Đồng thời, trong tiếng Anh thì các bigram "TH", "HE" và "IN" cũng xuất hiện nhiều nhất.

**Q.** Có thể giải mã "KEUDCR" mà không cần khóa hay không? Còn key thì sao?

Giải
--------

Theo thống kê các bigram xuất hiện nhiều nhất trong ciphertext và trong plaintext sẽ khớp nhau. Do đó có thể thấy "TH" mã hóa thành ":math:`\beta\gamma`" và "HE" mã hóa thành "LC". Như vậy ta có hệ phương trình

.. math:: 

    812 = a \cdot 558 + b \pmod{841} \\ 
    321 = a \cdot 207 + b \pmod{841}

Giải hệ ta có :math:`a = 15`, :math:`b = 10`. Đây là key.

Từ đây chúng ta có thể giải mã thành **CRYPTO** là plaintext ban đầu. Bài này ăn trọn 4/4 điểm.

Simple ideas for primes
=======================

Đề bài
--------

Chúng ta xem xét một số dãy số bao gồm các số nguyên tố.

- *Số Fermat*, :math:`F_k = 2^{2^k} + 1`, với :math:`k` bắt đầu từ 0. Ta có các số :math:`F_0, F_1, F_2, F_3, F_4` là các số nguyên tố, còn :math:`F_5` thì không phải.
- *Số Mersenne*, :math:`M_k = 2^k-1`. Ta có :math:`M_2, M_3, M_5, M_7` là các số nguyên tố, trong khi :math:`M_{11}` là hợp số. Các số nguyên tố Mersenne là các số dạng :math:`2^k-1` với :math:`k` là số nguyên tố.
- Dãy số :math:`31`, :math:`331`, :math:`3\,331`, :math:`33\,331`, :math:`333\,331`, :math:`3\,333\,331`, :math:`33\,333\,331` là các số nguyên tố được xây dựng theo quy tắc trên, nhưng số :math:`333\,333\,331` là hợp số chia hết cho 17.

Ta nói dãy Fermat trên có *sequence primality parameter* là 5, dãy Mersenne bằng 4, dãy cuối cùng bằng 7.

**Q.** Xây dựng một dãy bao gồm các số nguyên tố như vậy. Điều kiện quan trọng ở đây là các số hạng được xác định bởi chỉ số của dãy, không phụ thuộc vào các số trước nó.

Giải
--------

Bắt đầu với dãy Euler

.. math:: f(n) = n^2 + n + 41.

Đây là dãy các số nguyên tố với :math:`n=0, 1, \ldots, 39` và :math:`f(40)` là hợp số. Như vậy đây là dãy nguyên tố độ dài 40.

Và tất nhiên, dãy "ai cũng biết" thì chỉ được 2 điểm thôi. =(((

.. [#wolfram] https://mathworld.wolfram.com/Prime-GeneratingPolynomial.html

Sau khi tham khảo những thí sinh khác thì có một số cách xây dựng nhằm cải tiến điều này, tham khảo từ [#wolfram]_.

Nếu ta chuyển dãy trên thành

.. math:: g(n) = f(n-40) = (n-40)^2 + (n-40) + 41 = n^2 - 79 n + 1601

thì thu được dãy số nguyên tố với độ dài 80. Các nhà toán học thế kỉ 20 đã chứng minh được rằng, nếu :math:`p(x)` là một đa thức sinh ra dãy số nguyên tố với :math:`0 \leqslant x \leqslant n` thì đa thức :math:`p(n-x)` cũng vậy.

Trong bảng, dãy nguyên tố có độ dài lớn nhất là 56 được biểu diễn bởi đa thức

.. math:: \frac{1}{4} \left( n^5 - 133 n^4 + 6729 n^3 - 158379 n^2 + 1720294 n - 6823316 \right).

Dựa theo lời giải của team Himanshu Sheoran, Yo Iida và Pranshu Kumar chúng ta có thể sinh một dãy có độ dài bất kì.

.. [#aw] https://awwalker.com/2017/02/27/prime-generating-polynomials/

Lời giải dựa trên bài blog của A. W. Walker [#aw]_. Bài blog này phân tích về một bài báo năm 1977 bởi Chang và Lih với tiêu đề *Polynomial Representation of Primes* nhưng hiện tại không có bản online.

Bài báo này đưa ra một phương pháp xây dựng đa thức :math:`F(n)` bậc :math:`n` mà với mọi :math:`x \in [0, n]` thì :math:`F(n)` đều là số nguyên tố.

Bài báo có thể được tóm gọn như sau. Xét đa thức

.. math:: F(x) = 1 + \left| \sum_{n=0}^{M} \frac{a_n}{x - n} \prod_{j = 0}^{M} (x - j) \right|

sẽ sinh ra các số nguyên tố với mọi :math:`x \in [0, M]` nếu và chỉ nếu :math:`a_n` phân biệt và :math:`(a_n \cdot M! + 1)` là các số nguyên tố. Như vậy ta có một thuật toán đơn giản để bruteforce các đa thức trên.

.. prf:algorithm:: Thuật toán sinh dãy nguyên tố độ dài :math:`M`
    :label: nsu23-algo-primes

    **Input:** Độ dài dãy nguyên tố :math:`M`

    **Output:** Đa thức :math:`F(x)` cho kết quả là số nguyên tố với mọi :math:`x \in [0, M]`

    1. coeffs = [ ] chứa các số hạng :math:`a_n`
    2. :math:`an \gets 1`
    3. While chưa đủ :math:`M+1` số hạng trong coeffs
    
       1. If :math:`(an \cdot M! + 1)` là số nguyên tố
       
          1. kết nạp :math:`an` vào dãy coeffs
       
       2. EndIf
       3. :math:`an \gets an + 1`
    
    4. EndWhile

Mixed hashes
=======================

Đề bài
--------

Alice và Bob trao đổi các thông điệp mã hóa. Họ dùng thuật toán mã hóa khối PRESENT với key 80-bit và ECB mode. Ở đây, thông tin được lưu dạng ảnh .ppm.

Header của file .ppm gồm 3 dòng theo dạng ``P6\nX\nY\n255``. Trong đó X và Y là kích thước của ảnh theo chiều ngang và dọc.

Để đảm bảo an toàn, header sẽ được loại bỏ trước khi encrypt. Để có thể khôi phục header, hash của header sẽ được gửi đi thay vì header. Khi đó 3 phần của header sẽ được ngăn cách bởi dấu cách (space) thay vì newline như trên, nghĩa là ``P6 X Y 255``.

Bob chuẩn bị :math:`8` ảnh (trong file đính kèm) mà không có header. Bob encrypt :math:`8` ảnh đó với cùng một key theo thuật toán PRESENT và ECB mode. Bob cũng gửi hash của :math:`8` headers đi kèm. Tuy nhiên các hash đã bị trộn lẫn với nhau. Liệu chúng ta có thể khôi phục thông điệp mà Bob muốn gửi Alice?

Giải
--------

Bài này là bài 3 ở round 1 và round 2. Trong thời gian 2 round mình đều giải ra (round 2 chi tiết hơn và trình bày đẹp hơn :v).

Đề cho một file mẫu là mikky.ppm. Khi phân tích file này mình thấy rằng, nếu gọi :math:`w` và :math:`h` là độ rộng và độ cao của ảnh (lấy từ header) thì độ dài file không có header là :math:`3 \cdot w \cdot h`.

Sau khi encrypt bằng thuật toán mã hóa khối với ECB mode, độ dài sẽ là :math:`3 \cdot w \cdot h + pd`, trong đó :math:`pd` là padding. Theo thuật toán PRESENT thì :math:`0 \leqslant pd \leqslant 8`.

Với dự đoán rằng :math:`w \approx h`, mình lấy căn bậc hai của độ dài các filel đề cho, và đưa ra dự đoán :math:`w, h \in [400, 600]`. Nếu sai thì mình tăng độ rộng khoảng này thôi.

Tiếp theo, bruteforce :math:`w` và :math:`h` trong khoảng này, cho tới khi hash "P6 :math:`x` :math:`y` 255" xuất hiện trong số các hash trên, và

.. math:: 0 \leqslant \text{len} (ciphertext) - 3 * w * h \leqslant 8

thì mình lấy :math:`w` và :math:`h` này. Thế là mình có header.

Do cả :math:`8` file được encrypt bởi cùng một key PRESENT, và key có :math:`80` bit tương ứng :math:`10` bytes, hay :math:`10` ký tự, nhìn đề mình nhận thấy có chuỗi ``P6 X Y 255`` là hợp lý. Như vậy key cho PRESENT là chuỗi ``P6 X Y 255``.

Cuối cùng, mình giải mã lần lượt từng file với key trên, ghép header tương ứng vào, như vậy là mình giải mã được tất cả file rồi.

Bài này được 5/6 điểm vì không nộp code tính toán header, mất điểm vì chủ quan.

Column functions
=======================

Đề bài
--------

Alice muốn xây dựng mã đối xứng mạnh bằng việc giải một số bài toán khó.

Xét :math:`2^n` hàm vectorial one-to-one đôi một khác nhau, :math:`G_i \ : \ \mathbb{F}_2^n \to \mathbb{F}_2^n`, với :math:`i = 1, \ldots, 2^n`. Sử dụng các hàm này, chúng ta xây dựng một ma trận binary đặc biệt và xác định một số tính chất của nó.

Với :math:`n=2^m`, :math:`m \geqslant 5`, ta định nghĩa ma trận :math:`M` kích thước :math:`2^n \times n 2^n` theo quy tắc sau. Hàm thứ :math:`i`, :math:`i = 1, \ldots, 2^n`, là ghép của các giá trị :math:`G_i(0, 0, \ldots, 0, 0)`, :math:`G_i(0, 0, \ldots, 0, 1)`, ..., :math:`G_i(1, 1, \ldots, 1, 1)`. Các cột của :math:`M` có thể được xem như các vector của :math:`n 2^n` hàm boolean, mỗi hàm :math:`n` biến. Ta gọi chúng là *column functions*.

Chứng minh hoặc phản bác giả thuyết sau cho ít nhất một giá trị :math:`m \geqslant 5`: với mọi cách xây dựng ma trận như trên, tồn tại :math:`2^{n/2}` columns functions :math:`f_1, \ldots, f_{2^{n/2}}` sao cho tồn tại một hàm boolean nonzero :math:`f: \mathbb{F}_2^{2^{n/2}} \to \mathbb{F}_2` thỏa mãn các điều kiện sau:

- với mọi :math:`\bm{x} \in \mathbb{F}_2^n`

.. math:: 

    f(f_1(\bm{x}), f_2(\bm{x}), \ldots, f_{2^{n/2}}(\bm{x})) = 0;

- với mọi :math:`\bm{y} \in \mathbb{F}_2^{2^{n/2}}`, giá trị :math:`f(\bm{y})` có thể tính với không quá :math:`2^{n/2}` phép cộng và phép nhân modulo 2.

.. prf:example:: 
    :label: nsu23-col-funcs

    Với :math:`m=1` thì :math:`n=2` và ta xây dựng ma trận :math:`4 \times 8`. Xét các hàm boolean vectorial one-to-one :math:`G_1, G_2, G_3, G_4` từ :math:`\mathbb{F}_2^n` tới :math:`\mathbb{F}_2^n` xác định bởi các giá trị :math:`(0, 1, 2, 3)`, :math:`(0, 2, 1, 3)`, :math:`(0, 3, 1, 2)` và :math:`(3, 2, 1, 0)`. Khi đó ma trận là

    .. math:: 

        \begin{pmatrix}
            0 & 0 & 0 & 1 & 1 & 0 & 1 & 1 \\
            0 & 0 & 1 & 0 & 0 & 1 & 1 & 1 \\
            0 & 0 & 1 & 1 & 0 & 1 & 1 & 0 \\
            1 & 1 & 1 & 0 & 0 & 1 & 0 & 0
        \end{pmatrix}

    Ta cần tìm :math:`2^{n/2} = 2` column functions. Gọi :math:`f_1` và :math:`f_2` là hàm bool ứng với cột đầu và cột thứ hai của ma trận, và :math:`f(x_1, x_2) = x_1 \oplus x_2`. Khi đó :math:`f(f_1(\bm{x}), f_2(\bm{x})) \equiv 0` vì :math:`f_1(\bm{x}) = f_2(\bm{x}) = 0` với mọi :math:`\bm{x} \in \mathbb{F}_2^n`.

    Ta cũng thấy rằng có thể chọn :math:`f_1` và :math:`f_2` là cột 5 và 6 của ma trận. Khi đó, đặt :math:`f(x_1, x_2) = x_1 x_2` thì :math:`f(f_1(\bm{x}), f_2(\bm{x})) \equiv 0` vì :math:`f_1(\bm{x}) \neq f_2(\bm{x})` với mọi :math:`\bm{x} \in \mathbb{F}_2^n`.

    Trong cả hai trường hợp ta chỉ cần đúng một phép tính. Lưu ý rằng hàm :math:`f` thỏa :math:`f_1` và :math:`f_2` được gọi là *algebraically dependent*.

Giải
--------

Cách giải của mình không đúng hoàn toàn nên chỉ được 1/8. Dưới đây trình bày cách giải của đội Robin Jadoul, Jack Pope và Esrever Yu được 8/8 điểm.

Giả thuyết trong đề bài đúng với :math:`m` lớn. Ý tưởng chính là chúng ta cố định các cột sẽ chọn, có một số lượng lũy thừa các hàm :math:`f` (rất rất lớn) nhưng chỉ có số lượng đa thức các hàng (ít lớn hơn), do đó chúng ta có thể chọn hàm :math:`f` triệt tiêu tất cả hàng.

.. prf:theorem:: 
    :label: nsu23-thm-col-funcs

    Cho ma trận binary :math:`M` kích thước :math:`2^n \times n 2^n`. Với :math:`n+1` column functions bất kì, tồn tại một hàm nonzero :math:`f: \mathbb{F}_2^{n+1} \to \mathbb{F}_2` triệt tiêu trên các column functions và sử dụng nhiều nhất :math:`2n + 1` toán tử cộng và nhân.

.. admonition:: Chứng minh
    :class: danger, dropdown

    Gọi :math:`f_1, f_2, \ldots, f_{n+1}` là các column functions. Đặt

    .. math:: 
        S = \{ (f_1(\bm{x}), f_2(\bm{x}), \ldots, f_{n+1}(\bm{x})) \in \mathbb{F}_2^{n+1} : \bm{x} \in \mathbb{F}_2^n \}


    là tập hợp các bộ giá trị từ các column functions. Vì :math:`\lvert S \rvert < \lvert \mathbb{F}_2^{n+1} \rvert`, ta có thể chọn vector :math:`\bm{z} = (z_1, \ldots, z_{n+1}) \in \mathbb{F}_2^{n+1} \setminus S`. Từ đây ta định nghĩa hàm :math:`f` là

    .. math:: 
        f(x_1, \ldots, x_{n+1}) = (x_1 \oplus (z_1 \oplus 1)) \cdot (x_2 \oplus (z_2 \oplus 1)) \cdots (x_{n+1} \oplus (z_{n+1} \oplus 1))


    Lúc này, :math:`f` cho output là 1 chỉ khi :math:`z` là input (?), do đó với mọi :math:`\bm{y} \in S` thì :math:`f(\bm{y}) = 0`.

    Đối với số lượng phép tính, với mọi :math:`i`, :math:`z_i \oplus 1` là hằng số nên ta không xét đến khi tính số lượng phép tính cho hàm :math:`f`. Dựa trên vector :math:`\bm{z}`, có tối đa :math:`n+1` phép cộng (tương ứng :math:`x_i \oplus (z_i \oplus 1)`) và :math:`n` phép nhân :math:`n+1` hạng tử với nhau. Vì vậy số phép tính tối đa là :math:`2n+1`.

.. prf:corollary:: 
    :label: nsu23-cor-col-funcs
    
    Giả thuyết trên đúng với mọi :math:`m \geqslant 4`.

.. admonition:: Chứng minh
    :class: danger, dropdown

    Theo định lý trên ta có :math:`f` (bài toán yêu cầu hàm :math:`f` lấy :math:`2^{n/2}` input. Tuy nhiên chúng ta có thể thêm các dummy input miễn là số lượng cột không lớn hơn :math:`n+1` - mục tiêu ban đầu). Bây giờ ta chỉ cần chặn lại số lượng cột mà ta cần và số lượng phép tính.

    Với số lượng cột, ta cần :math:`n + 1 \leqslant 2^{n/2}`. Với số lượng phép tính, ta cần :math:`2n + 1 \leqslant 2^{n/2}`. Kết hợp cả hai ta có :math:`n \geqslant 9`, tương đương với :math:`m \geqslant 4`.

Bình luận
----------

Về tổng thể cách giải của team kia hợp lý trừ phần mình đánh dấu, chưa hiểu lắm khi :math:`\bm{z}` là input nghĩa là sao.

Thêm nữa, chưa có cơ sở để nghĩ ra bài giải này. Có vẻ như Esrever đã rất căng não để giải ra. :)))

**UPDATE.** Ý nghĩa của phần đánh dấu (?) là do phép tính

.. math:: f(x_1, \ldots, x_{n+1}) = (x_1 \oplus (z_1 \oplus 1)) \cdot (x_2 \oplus (z_2 \oplus 1)) \cdots (x_{n+1} \cdot (z_{n+1} \oplus 1))

Kết quả phép tính ra 1 khi vì chỉ khi tất cả hạng tử bằng 1. Nói cách khác :math:`x_i \oplus (z_i \oplus 1) = 1` với mọi :math:`1 \leqslant i \leqslant n+1`.

Điều này tương đương với :math:`x_i = z_i` với mọi :math:`1 \leqslant i \leqslant n+1`. Nhưng điều này vô lý vì khi đó :math:`\bm{x} \equiv \bm{z}` mà hai vector này nằm ở hai tập rời nhau.

Do đó kết quả hàm :math:`f` luôn là :math:`0`. Ta có điều phải chứng minh.

Primes
======

Đây là bài 5 của round 2 và được giải bởi bạn Uyên.

Đề bài
--------

Marcus chọn hai số nguyên tố lớn :math:`p` và :math:`q` rồi tính :math:`n = p \cdot q` và :math:`m = p + q`. Sau đó số :math:`n \cdot m` được sử dụng trong cryptosystem.

Khi test Marcus thấy các số :math:`p` và :math:`q` cho tích :math:`n \cdot m` kết thúc bởi 2023. Điều đó khả thi không?

Giải
--------

Do :math:`p` và :math:`q` là các số nguyên tố lớn nên chúng lẻ. Suy ra :math:`m = p + q` là số chẵn, nên tích :math:`n \cdot m` cũng là số chẵn.

Số chẵn kết thúc bởi :math:`0`, :math:`2`, :math:`4`, :math:`6`, :math:`8` nên không thể kết thúc bởi :math:`3`. Do đó điều này không thể xảy ra.

An aggregated signature
=======================

Bài này không biết làm. :(((

Đề bài
--------

Trong một tổ chức quốc tế lớn, gọi là **NSUCRYPTO association**, mọi người quyết định tổ chức một tờ báo thông tin (news journal) trong lĩnh vực mật mã. Tổ chức muốn rằng, tin tức chỉ được công bố khi đã được kiểm duyệt bởi một nhóm lớn các nhà mật mã. Vì vậy, 10 000 chuyên gia mật mã đã được mời tới làm biên tập cho tờ báo.

Quy định công bố như sau. Tin tức được công bố khi nó được ký bởi tất cả các thành viên biên tập. Tuy nhiên các nhà mật mã không rảnh để thu thập 10 000 chữ ký cá nhân. Do đó mọi người muốn một chữ ký postquantum dùng chung mà không thể chia nhỏ ra các chữ ký cá nhân.

Yêu cầu là cần xây dựng mô hình chữ ký thỏa mãn các yêu cầu sau:

1. kích thước chữ ký không quá lớn, có thể hơn vài kilobytes;
2. kích thước public key (để kiểm tra chữ ký) là nhỏ. Kích thước của key nên là cố định (hoặc gần cố định) kể cả khi số lượng chuyên gia tăng lên, ví dụ 20 000;
3. việc kiểm tra chữ ký tốn không quá 2 phút;
4. chữ ký có thể chống lại các tấn công trên máy tính lượng tử.

A unique coding
=======================

Bài này khi nhìn đề thì "có vẻ" câu hỏi Q2 là trường hợp nhỏ hơn của Q1. Mình giải Q2 (không chắc đúng hoàn toàn) nên lời giải sau đây áp dụng cho cả Q1 và Q2.

Đề bài
--------

Xét binary error-correcting code :math:`\mathcal{C}` với độ dài :math:`n`. Code này chỉ đơn giản là tập con của :math:`\mathbb{F}_2^n` thôi và ta truyền một phần tử của code này qua các kênh truyền.

Khi đi qua các kênh truyền các bit có thể bị sai, dẫn tới bị đảo bit. Khi nhận được vector :math:`\bm{y} \in \mathbb{F}_2^n`, ta sẽ decode thành một phần tử thuộc :math:`\mathcal{C}` mà có khoảng cách gần :math:`\bm{y}` nhất, nói cách khác là Hamming weight ngắn nhất.

Xét cơ chế decode maximal-likelihood. Giả sử ta nhận được :math:`\bm{y} \in \mathbb{F}_2^n`, ta muốn xét các trường hợp lỗi xảy ra ít nhất, gọi là :math:`d_{\bm{y}}`, nghĩa là

.. math:: d_{\bm{y}} = \min_{\bm{x} \in \mathcal{C}} wt(\bm{x}, \bm{y}).

Tiếp theo, đặt

.. math:: \mathcal{D} (\bm{y}) = \{ \bm{x} \in \mathcal{C} : wt(\bm{x}, \bm{y}) = d_{\bm{y}} \}.

Cuối cùng ta decode :math:`\bm{y}` thành phần tử :math:`\bm{x}` nào đó trong :math:`\mathcal{D}(\bm{y})`.

Chúng ta quan tâm tới các trường hợp code :math:`\mathcal{C}` khiến :math:`\lvert \mathcal{D}(\bm{y}) \rvert = 1` với mọi :math:`\bm{y} \in \mathbb{F}_2^n`. Nói cách khác khi nhận được :math:`\bm{y}` bất kì của :math:`\mathbb{F}_2^n` ta có thể decode thành một dạng duy nhất.

**Q1.** Code :math:`\mathcal{C}` như nào thì thỏa mãn tính chất này?

**Q2.** Code :math:`\mathcal{C}` như nào thỏa mãn tính chất này và là không gian tuyến tính con của :math:`\mathbb{F}_2^n`?

Giải
--------

Đầu tiên mình có nhận xét (khá rõ ràng) sau đây:

.. prf:remark:: 
    :label: nsu23-rmk-code
    
    Với mọi :math:`n`, code :math:`\mathcal{C} \equiv \mathbb{F}_2^n` thỏa mãn tính chất trên.

Chúng ta có thể thấy rằng với mọi :math:`\bm{y} \in \mathbb{F}_2^n` nhận được thì sẽ decode thành chính nó trong :math:`\mathcal{C}`.

Tiếp theo, ta xét nửa trên của :math:`\mathbb{F}_2^n`. Trong hệ thập phân thì đó là các số từ :math:`0` tới :math:`2^{n-1} - 1` và có dạng

.. math:: \bm{x} = (0, x_1, x_2, \ldots, x_{n-1}).

Nói cách khác, code :math:`\mathcal{C}` là tập hợp

.. math:: \mathcal{C} = \{ \bm{x} = (0, x_1, x_2, \ldots, x_{n-1}): x_i \in \mathbb{F}_2 \}.

Code :math:`\mathcal{C}` này thỏa mãn tính chất trên và mình sẽ chứng minh ngay sau đây.

.. admonition:: Chứng minh
    :class: danger, dropdown

    Giả sử ta nhận được :math:`\bm{y} \in \mathbb{F}_2^n`. Ta có hai trường hợp:

    - nếu :math:`\bm{y} = (0, y_1, y_2, \ldots, y_{n-1})`, hay nói cách khác biểu diễn thập phân của :math:`\bm{y}` là từ :math:`0` tới :math:`2^{n-1} - 1`, thì :math:`\bm{y}` được decode thành chính nó trong :math:`\mathcal{C}`. Khi này :math:`d_{\bm{y}} = 0` nhỏ nhất và không có vector nào khác cho Hamming weight bằng :math:`0` trừ chính nó.
    - nếu :math:`\bm{y} = (1, y_1, y_2, \ldots, y_{n-1})`, hay nói cách khác biểu diễn thập phân của :math:`\bm{y}` là từ :math:`2^{n-1}` tới :math:`2^n - 1`, thì :math:`\bm{y}` được decode thành :math:`\bm{x} = (0, y_1, y_2, \ldots, y_{n-1})` trong :math:`\mathcal{C}`. Khi này :math:`d_{\bm{y}} = 1` nhỏ nhất vì khác mỗi bit đầu tiên và cũng không có vector nào khác cho Hamming weight bằng :math:`1`.

Tiếp theo, mình viết các vector trong :math:`\mathcal{C}` thành các hàng của 1 ma trận :math:`2^{n-1} \times n`. Gọi :math:`A` là ma trận hoán vị các cột của ma trận :math:`2^{n-1} \times n` đó. Khi đó :math:`A` là ma trận có tính chất: trên mỗi hàng và trên mỗi cột có đúng một phần tử (bằng 1) và ma trận :math:`A` khả nghịch. Ví dụ, với :math:`n=4`, ma trận để hoán vị cột 2 với cột 4 là :math:`\begin{pmatrix}1 & 0 & 0 & 0 \\ 0 & 0 & 0 & 1 \\ 0 & 0 & 1 & 0 \\ 0 & 1 & 0 & 0 \end{pmatrix}`.

Khi đó, nếu mình nhân ma trận :math:`2^{n-1} \times n` của code :math:`\mathcal{C}` với bất kì ma trận :math:`A` nào như vậy thì code :math:`\mathcal{C}'` nhận được cũng thỏa mãn tính chất trên.

.. prf:example::
    :label: nsu23-exp-code

    Với :math:`n=4` thì code :math:`\mathcal{C}` gồm các vector
        
    .. math:: \mathcal{C} = \{ 0000, 0001, 0010, 0011, 0100, 0101, 0110, 0111 \}.

Với ma trận :math:`A` hoán vị cột 2 và 4 như trên ta có

.. math:: 

    \begin{pmatrix}
        0 & 0 & 0 & 0 \\
        0 & 0 & 0 & 1 \\
        0 & 0 & 1 & 0 \\
        0 & 0 & 1 & 1 \\
        0 & 1 & 0 & 0 \\
        0 & 1 & 0 & 1 \\
        0 & 1 & 1 & 0 \\
        0 & 1 & 1 & 1 
    \end{pmatrix} \cdot 
    \begin{pmatrix}
        1 & 0 & 0 & 0 \\
        0 & 0 & 0 & 1 \\ 
        0 & 0 & 1 & 0 \\ 
        0 & 1 & 0 & 0 
    \end{pmatrix} = 
    \begin{pmatrix} 
        0 & 0 & 0 & 0 \\ 
        0 & 1 & 0 & 0 \\ 
        0 & 0 & 1 & 0 \\ 
        0 & 1 & 1 & 0 \\ 
        0 & 0 & 0 & 1 \\ 
        0 & 1 & 0 & 1 \\ 
        0 & 0 & 1 & 1 \\ 
        0 & 1 & 1 & 1
    \end{pmatrix} = \mathcal{C}'.

Bây giờ mình sẽ chứng minh rằng với mọi ma trận :math:`A` hoán vị các cột như vậy thì code :math:`\mathcal{C}'` cũng thỏa mãn tính chất.

.. admonition:: Chứng minh
    :class: danger, dropdown

    Đặt

    .. math:: 
        \mathcal{C} = \{ (0, x_1, x_2, \ldots, x_{n-1}), x_i \in \mathbb{F}_2 \}.

    Gọi :math:`A` là ma trận hoán vị cột kích thước :math:`n \times n`. Khi đó ánh xạ

    .. math:: 
        A: \mathbb{F}_2^n \to \mathbb{F}_2^n, \quad \bm{y} \to \bm{y} \cdot A

    là song ánh do :math:`A` là ma trận khả nghịch. Khi đó xét code

    .. math:: \mathcal{C}' = \{ \bm{x} \cdot A: \bm{x} \in \mathcal{C} \}.

    Mình vẫn có hai trường hợp.

    **Trường hợp 1.** Với :math:`\bm{y} = (0, y_1, y_2, \ldots, y_{n-1}) \in \mathbb{F}_2^n` từ :math:`0` tới :math:`2^{n-1}-1` như trên. Xét :math:`\bm{y}' = \bm{y} \cdot A`.

    Khi đó, với :math:`\bm{x} = (0, y_1, y_2, \ldots, y_{n-1}) \in \mathcal{C}`, ta có :math:`\bm{x}' = \bm{x} \cdot A \in \mathcal{C}'`. Từ đây suy ra

    .. math:: wt(\bm{x}' \oplus \bm{y}') = wt((\bm{x} \cdot A) \oplus (\bm{y} \cdot A)) = wt((\bm{x} \oplus \bm{y}) \cdot A) = wt(\bm{0} \cdot A) = 0

    Ở đây :math:`\bm{0} = (0, 0, \ldots, 0) \in \mathbb{F}_2^n`.

    Nói cách khác :math:`d_{\bm{y}'} = 0` và có duy nhất một vector :math:`\bm{x}'` được định nghĩa như trên thỏa mãn. Do đó :math:`\lvert \mathcal{D}(\bm{y}') \rvert = 1`.

    **Trường hợp 2.** Với :math:`\bm{y} = (1, y_1, y_2, \ldots, y_{n-1}) \in \mathbb{F}_2^n` từ :math:`2^{n-1}` tới :math:`2^n-1` như trên. Ta cũng xét :math:`\bm{y}' = \bm{y} \cdot A`.

    Khi đó, với :math:`\bm{x} = (0, y_1, y_2, \ldots, y_{n-1}) \in \mathcal{C}`, ta cũng có :math:`\bm{x}' = \bm{x} \cdot \in \mathcal{C}'`. Từ đây ta có

    .. math:: wt(\bm{x}' \oplus \bm{y}') = wt((\bm{x} \cdot A) \oplus (\bm{y} \cdot A)) = wt((\bm{x} \oplus \bm{y}) \cdot A) = wt((1, 0, 0, \ldots, 0) \cdot A) = 1

    Ở phép nhân vector :math:`(1, 0, \ldots, 0)` với ma trận :math:`A`, vì ma trận :math:`A` chỉ có duy nhất một cột có dạng :math:`(1, 0, \ldots, 0)^T` nên kết quả phép nhân là một vector có đúng một phần tử 1, còn lại là 0.

    Nói cách khác :math:`d_{\bm{y}'} = 1` và có duy nhất một vector :math:`\bm{x}'` được định nghĩa như trên thỏa mãn. Do đó :math:`\lvert \mathcal{D}(\bm{y}') \rvert = 1`.

    Như vậy ta đã chứng minh xong.

Hoàn toàn tương tự, khi code :math:`\mathcal{C}` là các vector bắt đầu với hai số 0 thì ta lần lượt xét :math:`\bm{y}` trong các khoảng :math:`[0, 2^{n-2}-1]`, :math:`[2^{n-2}, 2^{n-1}-1]`, :math:`[2^{n-1}, 2^{n-1} + 2^{n-2}-1]`, :math:`[2^{n-1} + 2^{n-2} - 1, 2^n-1]`. Nghĩa là

.. math:: \mathcal{C} = \{ \bm{x} = (0, 0, x_1, x_2, \ldots, x_{n-2}: x_i \in \mathbb{F}_2^n) \}.

Khi đó ta xét các vector :math:`\bm{y}` có dạng:

- :math:`\bm{y} = (0, 0, y_1, y_2, \ldots, y_{n-2})`;
- :math:`\bm{y} = (0, 1, y_1, y_2, \ldots, y_{n-2})`;
- :math:`\bm{y} = (1, 0, y_1, y_2, \ldots, y_{n-2})`;
- :math:`\bm{y} = (1, 1, y_1, y_2, \ldots, y_{n-2})`.

Theo quy nạp thì code :math:`C` bắt đầu với :math:`i` số 0 đều đúng, :math:`0 \leqslant i \leqslant n`. Nghĩa là

.. math:: \mathcal{C} = \{ \bm{x} = (0, \ldots, 0, x_1, x_2, \ldots, x_{n-i}): x_i \in \mathbb{F}_2 \}.

Sau đó chúng ta lại áp dụng phép nhân với ma trận hoán vị cột :math:`A` như bên trên thì các code :math:`\mathcal{C}'` cũng thỏa mãn.

Vấn đề ở đây là, những code :math:`\mathcal{C}` như vậy là không gian vector sinh bởi :math:`i` vector (:math:`0 \leqslant i \leqslant n`) trong các vector sau:

.. math:: 

    \bm{v}_1 & = (1, 0, 0, \ldots, 0, 0) \\ 
    \bm{v}_2 & = (0, 1, 0, \ldots, 0, 0) \\ 
    \bm{v}_3 & = (0, 0, 1, \ldots, 0, 0) \\ 
    \cdots & = \cdots \\ 
    \bm{v}_n & = (0, 0, 0, \ldots, 0, 1).

Số cách chọn :math:`i` vector từ :math:`n` vector là

.. math:: C_n^0 + C_n^1 + \ldots + C_n^n = 2^n \, \text{cách}.

Nói cách khác có :math:`2^n` code :math:`\mathcal{C}` thỏa tính chất đề bài và là không gian tuyến tính của :math:`\mathbb{F}_2^n`.

.. prf:example::
    :label: nsu23-exp-code-2

    Với :math:`n=3` thì các code sau thỏa mãn tính chất

    .. math:: 
        
        & \mathcal{C}_1 = \{ 000 \}, \\
        & \mathcal{C}_2 = \{ 000, 001 \}, \\
        & \mathcal{C}_3 = \{ 000, 010 \}, \\
        & \mathcal{C}_4 = \{ 000, 100 \}, \\
        & \mathcal{C}_5 = \{ 000, 001, 010, 011 \}, \\
        & \mathcal{C}_6 = \{ 000, 001, 100, 101 \}, \\
        & \mathcal{C}_7 = \{ 000, 010, 100, 110 \}, \\
        & \mathcal{C}_8 = \{ 000, 001, 010, 011, 100, 101, 110, 111 \}.

Bình luận
----------

Đối với Q1 có thể thấy rằng bất cứ code nào chỉ chứa đúng một vector sẽ thỏa mãn điều kiện. Lý do là vì bất cứ :math:`\bm{y}` nào được gửi tới cũng sẽ decode ra vector đó.

Bài này mình được 6/12 điểm vì đưa ra cách xây dựng tốt, trình bày đẹp.

Algebraic cryptanalysis
=======================

Bài này là bài 7 ở round 1 và là bài 8 ở round 2. Bài này mình giải khá qua loa ở round 1 và được giải đầy đủ, rõ ràng hơn bởi người đồng đội vip pro Chương ở round 2.

Đề bài
--------

Bob muốn xây dựng stream cipher **BOB-0.1**.

Bob sử dụng một binary key độ dài :math:`8` là :math:`K = (k_1, \ldots, k_8)`. Sau đó anh ấy sinh ra dãy nhị phân :math:`\beta` theo quy tắc:

- :math:`\beta_n = k_n` khi :math:`n = 1, 2, \ldots, 8`;
- :math:`\beta_n = \beta_{n-1} \oplus \beta_{n-8}` khi :math:`n \geqslant 9`.

Sau đó Bob sinh dãy nhị phân :math:`\gamma` dùng trong phép XOR với plaintext. Dãy :math:`\gamma` được tạo bởi quy tắc :math:`\gamma_n = \beta_n \cdot \beta_{n+2} \oplus \beta_{n+7}` với :math:`n \geqslant 1`.

Alice chặn được :math:`8` bit của :math:`\gamma` sau khi để lỡ :math:`1200` bit. Các bit đó là `00100001`. Liệu Alice có thể tìm lại được key :math:`K` ban đầu không?

Giải
--------

Độ dài :math:`K` là :math:`8` bit, nếu chúng ta brutefore :math:`K = (k_1, \ldots, k_8)` rồi sinh ra 1208 bit :math:`\gamma` theo quy tắc trên và so sánh xem :math:`\gamma_{1201}, \ldots, \gamma_{1208}` nào khớp với :math:`8` bit trên thì ta có thể biết được :math:`K` ban đầu là gì.

Và, bất ngờ chưa, có tới hai trường hợp :math:`K` thỏa mãn :v :v

Bây giờ thì chúng ta cần xem xem tại sao lại có hai trường hợp thỏa mãn.

Cùng nhau khai triển :math:`\beta_{n+1}, \ldots, \beta_{n+8}` theo :math:`(\beta_{n-7}, \ldots, \beta_n)` nào.

.. math:: 

    & \beta_{n+1} = \beta_{n} \oplus \beta_{n-7} \\
    & \beta_{n+2} = \beta_{n+1} \oplus \beta_{n-6} = \beta_n \oplus \beta_{n-7} \oplus \beta_{n-6} \\
    & \beta_{n+3} = \beta_{n+2} \oplus \beta_{n-5} = \beta_n \oplus \beta_{n-7} \oplus \beta_{n-6} \oplus \beta_{n-5} \\
    & \beta_{n+4} = \beta_{n+3} \oplus \beta_{n-4} = \beta_n \oplus \beta_{n-7} \oplus \beta_{n-6} \oplus \beta_{n-5} \oplus \beta_{n-4} \\
    & \beta_{n+5} = \beta_{n+4} \oplus \beta_{n-3} = \beta_n \oplus \beta_{n-7} \oplus \beta_{n-6} \oplus \beta_{n-5} \oplus \beta_{n-4} \oplus \beta_{n-3} \\
    & \beta_{n+6} = \beta_{n+5} \oplus \beta_{n-2} = \beta_n \oplus \beta_{n-7} \oplus \beta_{n-6} \oplus \beta_{n-5} \oplus \beta_{n-4} \oplus \beta_{n-3} \oplus \beta_{n-2} \\
    & \beta_{n+7} = \beta_{n+6} \oplus \beta_{n-1} = \beta_n \oplus \beta_{n-7} \oplus \beta_{n-6} \oplus \beta_{n-5} \oplus \beta_{n-4} \oplus \beta_{n-3} \oplus \beta_{n-2} \oplus \beta_{n-1} \\
    & \beta_{n+8} = \beta_{n+7} \oplus \beta_n = \beta_{n-7} \oplus \beta_{n-6} \oplus \beta_{n-5} \oplus \beta_{n-4} \oplus \beta_{n-3} \oplus \beta_{n-2} \oplus \beta_{n-1}

Nếu viết ở dạng phép nhân ma trận modulo 2 ta có

.. math:: 

    \begin{pmatrix}
        \beta_{n+1} \\ \beta_{n+2} \\ \beta_{n+3} \\ \beta_{n+4} \\ \beta_{n+5} \\ \beta_{n+6} \\ \beta_{n+7} \\ \beta_{n+8}
    \end{pmatrix} = \begin{pmatrix}
        1 & 0 & 0 & 0 & 0 & 0 & 0 & 1 \\
        1 & 1 & 0 & 0 & 0 & 0 & 0 & 1 \\
        1 & 1 & 1 & 0 & 0 & 0 & 0 & 1 \\
        1 & 1 & 1 & 1 & 0 & 0 & 0 & 1 \\
        1 & 1 & 1 & 1 & 1 & 0 & 0 & 1 \\
        1 & 1 & 1 & 1 & 1 & 1 & 0 & 1 \\
        1 & 1 & 1 & 1 & 1 & 1 & 1 & 1 \\
        1 & 1 & 1 & 1 & 1 & 1 & 1 & 0
    \end{pmatrix} \begin{pmatrix}
        \beta_{n-7} \\ \beta_{n-6} \\ \beta_{n-5} \\ \beta_{n-4} \\ \beta_{n-3} \\ \beta_{n-2} \\ \beta_{n-1} \\ \beta_n
    \end{pmatrix}

Ma trận to to kia là ma trận khả nghịch. Do đó, nếu chúng ta có các :math:`\beta_{n+1}, \ldots, \beta_{n+8}` thì chúng ta có thể tìm ngược lại :math:`\beta_{n-7}, \ldots, \beta_n`. Tiếp tục quá trình này cuối cùng ta có thể tìm lại :math:`(\beta_1, \ldots, \beta_8) = K`.

Tiếp theo, cũng tương tự, chúng ta biểu diễn dãy :math:`\gamma` theo :math:`\beta`..

.. math:: 

    & \gamma_{n+1} = \beta_{n+1} \cdot \beta_{n+3} \oplus \beta_{n+8} \\
    & \gamma_{n+2} = \beta_{n+2} \cdot \beta_{n+4} \oplus \beta_{n+1} \oplus \beta_{n+8} \\
    & \gamma_{n+3} = \beta_{n+3} \cdot \beta_{n+5} \oplus \beta_{n+1} \oplus \beta_{n+2} \oplus \beta_{n+8} \\
    & \gamma_{n+4} = \beta_{n+4} \cdot \beta_{n+6} \oplus \beta_{n+1} \oplus \beta_{n+2} \oplus \beta_{n+3} \oplus \beta_{n+8} \\
    & \gamma_{n+5} = \beta_{n+5} \cdot \beta_{n+7} \oplus \beta_{n+1} \oplus \beta_{n+2} \oplus \beta_{n+3} \oplus \beta_{n+4} \oplus \beta_{n+8} \\
    & \gamma_{n+6} = \beta_{n+6} \cdot \beta_{n+8} \oplus \beta_{n+1} \oplus \beta_{n+2} \oplus \beta_{n+3} \oplus \beta_{n+4} \oplus \beta_{n+5} \oplus \beta_{n+8} \\
    & \gamma_{n+7} = \beta_{n+7} \cdot \beta_{n+1} \oplus \beta_{n+7} \cdot \beta_{n+8} \oplus \beta_{n+1} \oplus \beta_{n+2} \oplus \beta_{n+3} \oplus \beta_{n+4} \oplus \beta_{n+5} \oplus \beta_{n+6} \oplus \beta_{n+8} \\
    & \gamma_{n+8} = \beta_{n+8} \cdot \beta_{n+1} \oplus \beta_{n+8} \cdot \beta_{n+2} \oplus \beta_{n+1} \oplus \beta_{n+2} \oplus \beta_{n+3} \oplus \beta_{n+4} \oplus \beta_{n+5} \oplus \beta_{n+6} \oplus \beta_{n+7}

**Trường hợp 1.** :math:`\beta_{n+1} = 0`. Khi đó từ :math:`\gamma_{1201}` tới :math:`\gamma_{1208}` tương đương với hệ phương trình

.. math:: 

    0 & = \beta_{n+8} \\
    0 & = \beta_{n+2} \cdot \beta_{n+4} \\
    1 & = \beta_{n+3} \cdot \beta_{n+5} \oplus \beta_{n+2} \\
    0 & = \beta_{n+4} \cdot \beta_{n+6} \oplus \beta_{n+2} \oplus \beta_{n+3} \\
    0 & = \beta_{n+5} \cdot \beta_{n+7} \oplus \beta_{n+2} \oplus \beta_{n+3} \cdot \beta_{n+4} \\
    0 & = \beta_{n+2} \oplus \beta_{n+3} \oplus \beta_{n+4} \oplus \beta_{n+5} \\
    0 & = \beta_{n+2} \oplus \beta_{n+3} \oplus \beta_{n+4} \oplus \beta_{n+5} \oplus \beta_{n+6} \\
    1 & = \beta_{n+2} \oplus \beta_{n+3} \oplus \beta_{n+4} \oplus \beta_{n+5} \oplus \beta_{n+6} \oplus \beta_{n+7} \\

Hệ phương trình trên có nghiệm duy nhất :math:`(\beta_{i}) = (0, 1, 1, 0, 0, 0, 1, 0)`.

**Trường hợp 2.** :math:`\beta_{n+1} = 1`. Tương tự hệ phương trình cũng có nghiệm duy nhất :math:`(\beta_i) = (1, 1, 1, 0, 0, 0, 0, 1)`.

Như vậy ta có hai nghiệm thỏa mãn chuỗi :math:`8` bit :math:`\gamma_{1201}, \ldots, \gamma_{1208}`. Do không có điều kiện nào thêm, ta không thể xác định đâu là khóa trong hai trường hợp trên.

Bài này bạn Chương được 4/4 điểm. Good job nigga. ^)^

Finite-state machines
=======================

Bài này không biết làm!!!

Đề bài
--------

Alice muốn tạo một generator để sinh một dãy số với độ dài chu kỳ lớn nhất có thể. Vì cô ấy biết về finite-state machine, generator :math:`G` sẽ được xây dựng bởi hai machine :math:`A_1` và :math:`A_2` sao cho:

- :math:`A_1 = (\mathbb{F}_2^n, \mathbb{F}_2, g_1, f_1)` với hàm state-transition (hàm chuyển trạng thái) :math:`g_1 : \mathbb{F}_2^n \to \mathbb{F}_2^n` và hàm output :math:`f_1: \mathbb{F}_2^n \to \mathbb{F}_2`, :math:`n \geqslant 1`;
- :math:`A_2 = (\mathbb{F}_2, \mathbb{F}_2^m, \mathbb{F}_2, g_2, f_2)` với hàm state-transition :math:`g_2 : \mathbb{F}_2 \times \mathbb{F}_2^m \to \mathbb{F}_2^n` và hàm output :math:`f_2 : \mathbb{F}_2 \times \mathbb{F}_2^m \to \mathbb{F}_2`, :math:`m \geqslant 1`.

.. figure:: prob-09.*

Với mỗi :math:`t=1, 2, \ldots`, đặt

1. :math:`x(t)` và :math:`y(t)` là trạng thái của :math:`A_1` và :math:`A_2`, :math:`x(1)` và :math:`y(1)` là các giá trị khởi tạo;
2. :math:`x(t+1) = g_1 (t)` là trạng thái tiếp theo của :math:`A_1` và :math:`u(t) = f_1 (x(t))` là output bit của :math:`A_1`;
3. :math:`y(t+1) = g_2(u(t), y(t))` là trạng thái tiếp theo của :math:`A_2` và :math:`z(t) = f_2(u(t), y(t))` là output bit của :math:`A_2`.

Dãy :math:`z(1), z(2), z(3), \ldots` là output của generator :math:`G`. Dễ thấy rằng dãy sinh bởi :math:`G` có chu kỳ nhỏ nhất không vượt quá :math:`2^{n+m}`.

Theo thí nghiệm Alice thấy rằng, dãy output của :math:`G` sẽ có chu kỳ nhỏ nhất nhỏ hơn :math:`2^{n+m}` nếu Hamming weight của :math:`f_1` là chẵn. Hãy chứng minh hoặc phủ định nhận xét của Alice.

Giải
--------

Note theo gợi ý của thầy Kolomeec, chưa hiểu hết.

Dễ thấy rằng nếu :math:`z(t)` có chu kỳ tối đa thì các máy trạng thái :math:`A_1` và :math:`A_2` phải có chu kỳ tối đa lần lượt là :math:`2^n` và :math:`2^m`.

Các giá trị của :math:`g_2` có thể chia ra hai phần là :math:`g_2(0, \bm{x})` và :math:`g_2(1, \bm{x})` với :math:`\bm{x} \in \mathbb{F}_2^m`. Trong đó 0 và 1 xác định từ :math:`f_1`.

Nếu :math:`g_2` có chu kỳ cực đại thì trọng số phải là :math:`2^{m}`, nói cách khác là hàm cân bằng, suy ra :math:`g_2(0, \bm{x})` và :math:`g_2(1, \bm{x})` đều có số chẵn phần tử.

Điều này có nghĩa là :math:`g_2` sẽ sinh ra dãy có chu kỳ tạo thành hoán vị chẵn.

Tuy nhiên nếu :math:`g_2` có chu kỳ cực đại thì chu kỳ đó phải tạo thành hoán vị lẻ vì khi đó hoán vị

.. math:: 1 \to 2 \to \cdots \to t \to 1 = (1, 2) (1, 3) \cdots (1, t)

có :math:`t - 1` tranposition. Nói cách khác đây là hoán vị lẻ vì :math:`t=2^{m}` chẵn.

Như vậy để chu trình đạt chu kỳ tối đa thì nó phải là hoán vị lẻ, mâu thuẫn với phân tích ở trên :math:`g_2` sẽ sinh ra dãy là hoán vị chẵn.

Trong cách giải này có hai chỗ mình không biết thầy lấy đâu ra: tại sao :math:`g_2` cân bằng thì cả :math:`g_2(0, \bm{x})` và :math:`g_2(1, \bm{x})` đều phải có số chẵn phần tử mà không phải là đều có số lẻ? Liên hệ giữa trọng số hàm bool và hoán vị chẵn/lẻ là gì?

Quantum encryption
=======================

Đây là bài 8 của round 1 và bài 10 của round 2. Bài này sai gần bước cuối mới cay.

Đề bài
--------

Bob tạo một thuật toán mã hóa encrypt 4 bit :math:`(x_1, x_2, x_3, x_4)` bằng key cũng 4 bit :math:`(k_1, k_2, k_3, k_4)` với mạch sau:

.. figure:: prob-10-1.*

Plaintext 4 bit :math:`(x_1, x_2, x_3, x_4)` được biểu diễn ở dạng 4-qubit "plainstate" :math:`\lvert x1, x2, x3, x4 \rangle`. Quantum state này là input cho mạch ở dạng qubit đơn đi qua các cổng.

Ở đây hai loại cổng được sửa dụng là CNOT và Hadamard.

Kí hiệu :math:`H^b` với :math:`b \in \{ 0, 1 \}` có nghĩa là, nếu :math:`b = 0` thì cổng đồng nhất :math:`I` được sử dụng (không thay đổi), còn nếu :math:`b = 1` thì cổng Hadamard sẽ được sử dụng.

Kết quả sau khi qua mạch là "cipherstate" :math:`\lvert \psi \rangle`.

Bob có nhiệm vụ tăng số qubit đầu vào lên nhằm giảm các sai số khi tính toán và truyền dữ liệu trên kênh quantum. Do đó Bob biến đổi thành mạch sau:

.. figure:: prob-10-2.*

Alice nói rằng cô ấy có thể tìm lại được key nếu biết :math:`N` amplitude của kết quả :math:`\lvert \psi \rangle`. Do có :math:`8` qubits ở kết quả nên số lượng amplitude tối đa là :math:`2^8 = 256`, nói cách khác :math:`N \leqslant 256`. Vậy Alice cần ít nhất bao nhiêu amplitude là đủ để tìm lại key?

Giải
--------

Đầu tiên xét 4 dây trên, 4 dây dưới tương tự.

.. figure:: prob-10-3.*

Chúng ta xét dây 1 và 4 của mạch (tương tự cho dây 2 và 3). Áp dụng cổng CNOT liên tiếp 3 lần ta có

.. math:: \lvert x_1 \rangle \otimes \lvert x_2 \rangle \to \lvert x_1 \oplus x_2 \rangle \otimes \lvert x_2 \rangle \to \lvert x_1 \oplus x_2 \rangle \otimes \lvert x_1 \rangle \to \lvert x_2 \rangle \otimes \lvert x_1 \rangle

.. figure:: prob-10-4.*

    Dây 1 và dây 4

.. figure:: prob-10-5.*

    Dây 2 và dây 3

Nói cách khác là đảo bit. :v

Tương tự cho các cặp dây (5, 8) và (6, 7). Do đó khi tới trước các cổng Hadamard thì thứ tự các qubit từ trên xuống dưới là hình sau.

.. figure:: prob-10-6.*

    Qubits trước Hadamard

Mạch ở dây 1 và 2 đều có dạng :math:`\lvert x_2 \rangle` đi qua :math:`H^{k_1}` nên sau khi qua cổng mình đặt :math:`\lvert z_2 \rangle = H^{k_1} \lvert x_2 \rangle`.

Tương tự, :math:`\lvert z_1 \rangle = H^{k_2} \lvert x_1 \rangle` cho dây 3 và 4, :math:`\lvert z_4 \rangle = H^{k_3} \lvert x_4 \rangle` cho dây 5 và 6, :math:`\lvert z_3 \rangle = H^{k_4} \lvert x_3 \rangle` cho dây 7 và 8.

Mạch sau khi đi qua Hadamard có dạng

.. figure:: prob-10-7.*

    Qubits sau Hadamard

Ở đây chúng ta có một lưu ý nhỏ có thể giúp ích trong việc giới hạn số lượng amplitude theo đề bài. Nếu :math:`k_1 = 0` thì :math:`\lvert z_2 \rangle = \lvert x_2 \rangle`. Nếu :math:`k_1 = 1` thì :math:`\lvert z_2 \rangle = \dfrac{\lvert 0 \rangle + (-1)^{x_2} \lvert 1 \rangle}{\sqrt{2}}`. Như vậy, hệ số trước :math:`\lvert 0 \rangle` của :math:`\lvert z_2 \rangle` có thể là :math:`0, 1, \dfrac{1}{\sqrt{2}}` đều không âm.

Bây giờ chúng ta quay lại toán tử CNOT. Ma trận tương ứng của toán tử CNOT là :math:`\begin{pmatrix} 1 & 0 & 0 & 0 \\ 0 & 1 & 0 & 0 \\ 0 & 0 & 0 & 1 \\ 0 & 0 & 1 & 0 \end{pmatrix}`. Kết quả sau khi thực hiện toán tử CNOT là hệ số trước :math:`\lvert 00 \rangle` và :math:`\lvert 01 \rangle` giữ nguyên, còn hệ số trước :math:`\lvert 10 \rangle` và :math:`\lvert 11 \rangle` đổi chỗ cho nhau.

Đối với 3 qubit, mình **dự đoán** tương tự. 

Ở cổng CNOT đầu tiên, dây 1 control dây 3. Nếu mình chỉ xét 3 dây đầu thì tích các qubit gồm :math:`\lvert 000 \rangle`, :math:`\lvert 001 \rangle`, :math:`\lvert 010 \rangle`, :math:`\lvert 011 \rangle`, :math:`\lvert 100 \rangle`, :math:`\lvert 101 \rangle`, :math:`\lvert 110 \rangle`, :math:`\lvert 111 \rangle`. 

Áp dụng "chiến thuật" tương tự, mình chỉ quan tâm vị trí 1 và 3. Nghĩa là hệ số của :math:`\lvert 0 x 0 \rangle` và :math:`\lvert 0 x 1 \rangle` giữ nguyên, còn hệ số trước :math:`\lvert 1 x 0 \rangle` và :math:`\lvert 1 x 1 \rangle` đổi chỗ cho nhau, với :math:`x \in \{ 0, 1 \}`. Nói cách khác, :math:`8` hệ số trước amplitude chỉ thay đổi vị trí chứ không nhiều hơn hay ít đi, hay tập hợp hệ số giữ nguyên.

.. figure:: prob-10-8.*

Như vậy, giả sử :math:`\lvert z_2 \rangle = a \lvert 0 \rangle + b \lvert 1 \rangle`, :math:`\lvert z_1 \rangle = c \lvert 0 \rangle + \lvert 1 \rangle`, :math:`\lvert z_4 \rangle = e \lvert 0 \rangle + f \lvert 1 \rangle`, :math:`\lvert z_3 \rangle = g \lvert 0 \rangle + h \lvert 1 \rangle`. Khi đó kết quả cipherstate là

.. math:: \lvert \psi \rangle = \lvert z_2 \rangle \otimes \lvert z_2 \rangle \otimes \lvert z_1 \rangle \otimes \lvert z_1 \rangle \otimes \lvert z_4 \rangle \otimes \lvert z_4 \rangle \otimes \lvert z_3 \rangle \otimes \lvert z_3 \rangle

Xét

.. math:: \lvert z_2 \rangle \otimes \lvert z_2 \rangle = a^2 \lvert 00 \rangle + ab \lvert 01 \rangle + ab \lvert 10 \rangle + b^2 \lvert 11 \rangle.

Ở đây có 3 hệ số khác nhau là :math:`(a^2, ab, b^2)`. Với lưu ý bên trên :math:`a \geqslant 0` nên từ :math:`a^2` tính được :math:`a`. Từ :math:`a`, ta cần thêm :math:`ab` để xác định :math:`b`.

Như vậy mình cần :math:`2^4 = 16` hệ số để tìm lại các key ban đầu.

Bình luận
----------

Thế éo nào mình lại nhầm khúc cuối mà lấy cả :math:`a^2`, :math:`ab` và :math:`b^2` nên kết quả ra :math:`3^4 = 81`. Tất nhiên là **SAI BÉT** nên chỉ được 2/8. :(((

AntCipher
==========

Bài này là bài số 2 ở round 1 và là bài số 11 ở round 2. Lúc thi round 1 mình không biết giải, còn ở round 2 thì mình đã giải theo cách như sau.

Đề bài
--------

Đặt

.. math:: 

    f = (x_1 \lor x_2 \lor x_9) \land (\lnot x_1 \lor \lnot x_2 \lor \lnot x_9) \land (\lnot x_1 \lor x_2 \lnot x_9) \land (x_1 \lor \lnot x_2 \lor x_9) \land \\
    (x_1 \lor x_2 \lor x_3) \land (\lnot x_9 \lor \lnot x_{10} \lor \lnot x_3) \land (x_1 \lor \lnot x_2 \lor x_4) \land (\lnot x_9 \lor x_{10} \lor \lnot x_4) \land \\
    (\lnot x_1 \lor x_2 \lor x_5) \land (x_9 \lor \lnot x_{10} \lor \lnot x_5) \land (\lnot x_1 \lor \lnot x_2 \lor x_6) \land (x_9 \lor x_{10} \lor \lnot x_6) \land \\
    (x_1 \lor x_2 \lor x_3 \lor x_4 \lor \lnot x_7) \land (x_2 \lor x_3 \lor x_4 \lor \lnot x_7 \lor \lnot x_8).

Hàm :math:`f` gồm 10 biến được viết dưới dạng CNF (conjunctive normal form). Thuật toán mã hóa dựa trên hàm :math:`f` biến đối hai bit plaintext :math:`(x_1, x_2)` thành hai bit ciphertext :math:`(x_9, x_{10})` khi giá trị hàm :math:`f = True`. Hàm :math:`f` này có 10 biến :math:`x_1, x_2, \ldots, x_{10}` và 46 literals, là các hạng tử trong biểu diễn CNF của hàm. Ví dụ với dấu ngoặc thứ hai có 3 literals là :math:`\lnot x_1`, :math:`\lnot x_2` và :math:`\lnot x_9`.

**Q.** Vì các giới hạn tính toán nên chúng ta chỉ có thể sử dụng tối đa 16 biến với 20 literals. Nhắc lại rằng hàm :math:`f` ở trên có 10 biến và 46 literals. Hãy tìm cách biểu diễn tương đương của thuật toán mã hóa trên với giới hạn đã cho.

Giải
--------

Khi mình code hàm để tính giá trị hàm :math:`f` và xem xét những vector

.. math:: \bm{x} = (x_1, \ldots, x_{10})

mà :math:`f = True`, mình nhận thấy rằng:

- nếu :math:`(x_1, x_2) = (0, 0)` thì :math:`(x_9, x_{10}) = (1, 0)`
- nếu :math:`(x_1, x_2) = (0, 1)` thì :math:`(x_9, x_{10}) = (1, 1)`
- nếu :math:`(x_1, x_2) = (1, 0)` thì :math:`(x_9, x_{10}) = (0, 0)`
- nếu :math:`(x_1, x_2) = (1, 1)` thì :math:`(x_9, x_{10}) = (0, 1)`

Mình nhận ra rằng các biến :math:`x_3, x_4, \ldots, x_7, x_8` hoàn toàn không tác động lên việc mã hóa từ :math:`(x_1, x_2)` thành :math:`(x_9, x_{10})` (ít nhất là ở những chỗ :math:`f = True` :v).

Như vậy bài toán được rút gọn thành hàm boolean 4 biến :math:`x_1`, :math:`x_2`, :math:`x_9` và :math:`x_{10}`. Ở đó

.. math:: f(0010) = f(0111) = f(1000) = f(1101) = 1.

Các vector còn lại thì :math:`f=0`. Ở dưới là bảng chân trị.

+-------------+-------------+-------------+----------------+-----------+
| :math:`x_1` | :math:`x_2` | :math:`x_9` | :math:`x_{10}` | :math:`f` |
+=============+=============+=============+================+===========+
| :math:`0`   | :math:`0`   | :math:`0`   | :math:`0`      | :math:`0` |
+-------------+-------------+-------------+----------------+-----------+
| :math:`0`   | :math:`0`   | :math:`0`   | :math:`1`      | :math:`0` |
+-------------+-------------+-------------+----------------+-----------+
| :math:`0`   | :math:`0`   | :math:`1`   | :math:`0`      | :math:`1` |
+-------------+-------------+-------------+----------------+-----------+
| :math:`0`   | :math:`0`   | :math:`1`   | :math:`1`      | :math:`0` |
+-------------+-------------+-------------+----------------+-----------+
| :math:`0`   | :math:`1`   | :math:`0`   | :math:`0`      | :math:`0` |
+-------------+-------------+-------------+----------------+-----------+
| :math:`0`   | :math:`1`   | :math:`0`   | :math:`1`      | :math:`0` |
+-------------+-------------+-------------+----------------+-----------+
| :math:`0`   | :math:`1`   | :math:`1`   | :math:`0`      | :math:`0` |
+-------------+-------------+-------------+----------------+-----------+
| :math:`0`   | :math:`1`   | :math:`1`   | :math:`1`      | :math:`1` |
+-------------+-------------+-------------+----------------+-----------+
| :math:`1`   | :math:`0`   | :math:`0`   | :math:`0`      | :math:`1` |
+-------------+-------------+-------------+----------------+-----------+
| :math:`1`   | :math:`0`   | :math:`0`   | :math:`1`      | :math:`0` |
+-------------+-------------+-------------+----------------+-----------+
| :math:`1`   | :math:`0`   | :math:`1`   | :math:`0`      | :math:`0` |
+-------------+-------------+-------------+----------------+-----------+
| :math:`1`   | :math:`0`   | :math:`1`   | :math:`1`      | :math:`0` |
+-------------+-------------+-------------+----------------+-----------+
| :math:`1`   | :math:`1`   | :math:`0`   | :math:`0`      | :math:`0` |
+-------------+-------------+-------------+----------------+-----------+
| :math:`1`   | :math:`1`   | :math:`0`   | :math:`1`      | :math:`1` |
+-------------+-------------+-------------+----------------+-----------+
| :math:`1`   | :math:`1`   | :math:`1`   | :math:`0`      | :math:`0` |
+-------------+-------------+-------------+----------------+-----------+
| :math:`1`   | :math:`1`   | :math:`1`   | :math:`1`      | :math:`0` |
+-------------+-------------+-------------+----------------+-----------+

Từ bảng chân trị trên, sử dụng phương pháp bìa Karnaugh mình rút gọn được thành

.. math:: 

    f(x_1, x_2, x_9, x_{10}) = & (\lnot x_1 \lor \lnot x_9) \land (x_1 \lor x_9) \land \\ 
    & (\lnot x_1 \lor \lnot x_2 \lor x_{10}) \land (x_1 \lor x_2 \lor \lnot x_{10}) \land \\
    & (\lnot x_1 \lor x_2 \lor \lnot x_{10}) \land (x_1 \lor \lnot x_2 \lor x_{10}).

CNF này có 4 biến và 16 literals, thỏa mãn yêu cầu đề bài và ăn trọn 6/6 điểm.

Kết luận
=======================

Năm 2023 khá chill :))) học được nhiều điều :))) không hối hận vì đã liều :)))

Xin chân thành cám ơn bạn Chương và bạn Uyên đã đồng hành cùng mình trong kì NSUCRYPTO 2023.
