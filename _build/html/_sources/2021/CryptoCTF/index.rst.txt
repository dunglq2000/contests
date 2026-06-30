Crypto CTF 2021
***************

Chào mọi người, lại một mùa Crypto CTF nữa đã qua và lần này mình có khá khẩm hơn năm ngoái một chút, và sau đây là writeup các challenge mình đã làm được

Source code đề và bài giải của mình ở `đây <https://github.com/dunglq2000/CTF/tree/master/2021/CryptoCTF>`_.

Farm
====
		
Đề bài cho mình ``F`` tạo các đa thức trên :math:`\mathrm{GF}(2^6)`, ``maptofarm`` để lấy đa thức tương ứng với chỉ số của ký tự trong alphabet, và ``encrypt`` để mã hóa chuỗi base64, bằng cách là ký tự base64 ``m`` sẽ thành ``ALPHABET[F.index(pkey * maptofarm(chr(m)))]``.

Ok, vì ``key`` chỉ nằm trong :math:`\mathrm{GF}(2^6)`, mình chỉ việc bruteforce thôi (nằm trong :math:`\mathrm{GF}(2^6)` nên độ dài là :math:`14` hay bao nhiêu cũng không quan trọng). Làm ngược lại quá trình mã hóa mình có flag.

.. Flag: ``CCTF{EnCrYp7I0n_4nD_5u8STitUtIn9_iN_Fi3Ld!}``.

KeyBase
=======

Bài này cho mình một hệ thống sử dụng AES mode CBC (key và iv giống nhau suốt một phiên kết nối) để làm hai việc:

* đưa flag đã bị mã hóa;
* mã hóa một đoạn input :math:`32` byte bất kì và trả lại key (dạng hex) với :math:`2` byte cuối bị ẩn, và ciphertext với :math:`14` byte ở giữa bị ẩn.

Do mode CBC có tính chất :math:`C_{i+1} = E_k(C_i \oplus P_{i+1})`, với :math:`P_0 = iv`. Do đó nếu mình chọn :math:`P` và :math:`P'` là hai plaintext có :math:`16` bytes đầu giống nhau còn :math:`16` bytes cuối khác nhau thì mình có :math:`C_1 = C_1' = E_k(iv \oplus P_1)` còn :math:`C_2 = E_k(C_1 \oplus P_2)` và :math:`C_2' = E_k(C_1' \oplus P_2')`.

Từ đây mình có :math:`C_1 \oplus P_2 \oplus C_1' \oplus P_2' = D_k(C_2) \oplus D_k(C_2')`, mà :math:`C_1 = C_1'` rồi nên mình cần lấy ciphertext nào mà :math:`16` bytes cuối không bị ẩn đi để có thể bruteforce :math:`2` byte cuối của key và decrypt, tức là mình phải có :math:`P_2 \oplus P_2' = D_k(C_2) \oplus D_k(C_2')`.

Bây giờ tìm iv, mình chỉ cần đưa lên server :math:`32` bytes ``\0`` là xong và cũng tương tự trên, chỉ lấy ciphertext nào mà :math:`16` bytes cuối không bị ẩn. Vì :math:`C_2 = E_k(C_1) = E_k(E_k(iv))` (do xor với dãy toàn ``0``). Decrypt mình có lại iv.

Giờ thì giải mã flag thôi.

.. Flag: ``CCTF{h0W_R3cOVER_7He_5eCrET_1V?}``.

Rima
====

Bài này không dùng biến chữ để chạy loop và dùng dấu gạch dưới của python nên lúc đầu mình thấy hơi rắc rối.

Đầu tiên flag được chuyển sang dạng nhị phân và thêm 1 bit ``0`` ở đầu được dãy :math:`f`. Kế tiếp với mỗi :math:`i = 0, \ldots, \mathrm{len}(f) - 2` thì :math:`f_i = f_i + f_{i+1}`.

Kế tiếp hai số :math:`a` và :math:`b` được tạo là hai số nguyên tố kế tiếp tính từ :math:`\mathrm{len}(f)` là độ dài :math:`f`.

Sau đó, :math:`g` và :math:`h` là hai list tạo ra từ việc lặp :math:`f` lần lượt với :math:`a` và :math:`b` lần. Như vậy độ dài của :math:`g` là :math:`a \cdot \mathrm{len}(f)` và độ dài của :math:`h` là :math:`b \cdot \mathrm{len}(f)`.

Tiếp theo, :math:`c` là số nguyên tố kế tiếp tính từ :math:`\mathrm{len}(f) \gg 2`. Thêm :math:`c` bit ``0`` vào đầu :math:`g` và thực hiện :math:`g_i = g_i + g_{i+c}` với :math:`i = 0, 1, \ldots, \mathrm{len}(f) - c - 1`. Làm tương tự với :math:`h`.

Cuối cùng là chuyển :math:`g` và :math:`h` sang số int base :math:`5` và viết lên file dưới dạng byte. Nên đầu tiên mình sẽ làm ngược lại và tìm được :math:`g` và :math:`h`, sau đó mình bruteforce :math:`\mathrm{len}(f)` để tìm :math:`a`, :math:`b` và :math:`c` và xem thử bộ nào thỏa :math:`a \cdot \mathrm{len}(f) + c = \mathrm{len}(g)` và :math:`b \cdot \mathrm{len}(f) + c = \mathrm{len}(h)`.

Sau đó là làm ngược lại quá trình, với :math:`i = \mathrm{len}(f) - c - 1, \ldots, 0` thì :math:`g_i = g_i - g_{i+c}`. Tương tự với :math:`h`. Có thể kiểm chứng cách đúng nếu đầu :math:`g` có đúng :math:`c` số ``0``. :)))

Giờ thì, lấy :math:`\mathrm{len}(f)` số đầu của :math:`g` và tiếp tục làm ngược lại sẽ ra các bit của flag.

.. Flag: ``CCTF{_how_finD_7h1s_1z_s3cr3T?!}``.

Maid
====

Ở bài này server cung cấp cho mình các chứng năng sau:

* encrypt một số bất kì không vượt quá :math:`2^{2048 - 2}` bits;
* decrypt một số bất kì (hàm decrypt bị giấu đi);
* lấy flag bị mã hóa.

Key là một cặp khóa công khai-bí mật :math:`(pubkey, privkey)`, trong đó :math:`pubkey = p^2q` còn :math:`privkey = p^2`, với :math:`p` và :math:`q` là hai số nguyên tố :math:`1024` bits và đồng dư :math:`3` modulo :math:`4`.

Hàm ``encrypt`` thực hiện mã hóa số :math:`m` bằng cách trả về :math:`m^2 \pmod{pubkey}`. Còn hàm ``decrypt`` thực hiện giải mã chỉ cần :math:`privkey`.

Kì cục ..............

Thế quái nào ..............

Mà ``encrypt`` cần cả :math:`p` và :math:`q` còn ``decrypt`` chỉ cần :math:`p`?

Thật ra là vì nếu :math:`c \equiv m^2 \pmod{pubkey}` thì :math:`c \equiv m^2 \pmod{p^2}`, như vậy giải thích cho việc :math:`m` không được vượt quá :math:`2048-2` bits và việc giải mã chỉ cần :math:`p`. Như vậy cách attack của mình như sau:

1. Chọn ngẫu nhiên các ciphertext, gửi lên để server decrypt và nhận lại các plaintext tương ứng. Ta biết rằng :math:`c \equiv m^2 \pmod{p^2}` nên :math:`p^2 = \gcd(m_1^2 - c_1, m_2^2 - c_2)`, từ đó lấy căn bậc hai là có :math:`p`.
2. Tiếp theo, chọn ngẫu nhiên các plaintext, gửi lên server encrypt và nhận lại ciphertext tươngg ứng. Do

.. math:: 
	
	c \equiv m^2 \pmod{pubkey} \equiv m^2 \pmod{p^2q},

* khi đó :math:`p^2q = \gcd(m_1^2 - c_1, m_2^2 - c_2)`. Việc này ngược lại quá trình trên vì như nãy mình đã nói, ``encrypt`` sử dụng :math:`p^2q` còn ``decrypt`` thì chỉ cần :math:`p^2`;
* và bây giờ :math:`p` và :math:`q` đã có đủ, ta decrypt và có flag thôi.

.. Flag: ``CCTF{___Ra8!N_H_Cryp70_5YsT3M___}``.

Tuti
====

Ở đây :math:`x` và :math:`y` là nửa đầu và nửa sau của flag, :math:`k` là một số cho trước thỏa mãn

.. math:: 
	
	(x^2+1)(y^2+1)-2(x-y)(xy-1) = 4(k+xy).

Biến đổi một tí mình có

.. math:: 
	
	\begin{array}{cccc}
    & x^2 y^2 + x^2 + y^2 + 1 - 2(x-y)xy+2(x-y)-4xy & = & 4k \\
    \Leftrightarrow & x^2 y^2 + (x^2 + y^2 + 1 + 2(x-y) - 2xy) - 2(x-y+1)xy & = & 4k \\
    \Leftrightarrow & x^2 y^2 + (x-y+1)^2 - 2(x-y+1)xy & = & 4k \\
    \Leftrightarrow & (xy - x + y - 1)^2 & = & 4k.
	\end{array}

Như vậy :math:`xy-x+y-1=\sqrt{4k}` mà :math:`xy-x+y-1=(x+1)(y-1)` nên mình chỉ cần factor số này là tìm được :math:`x` và :math:`y`. Do có thể có nhiều cách chọn nên mình tìm cái "hợp lí" nhất.

Flag: ``CCTF{S1mPL3_4Nd_N!cE_Diophantine_EqUa7I0nS!}``.

Improve
=======

Ở bài này khá có khá nhiều thứ linh tinh nhưng chung quy lại là mình cần nhập vào hai số khác nhau :math:`m_1` và :math:`m_2` khác :math:`n` sao cho kết quả hàm ``improve`` với hai số này là giống nhau.

Các tham số sẽ là :math:`n` làm chặn trên cho hai số nhập vào (không vượt quá :math:`n^2`, và :math:`f` có tính chất quan trọng là luôn chẵn, đây là tiền đề để mình giải bài này.

Hàm ``improve`` mình để ý rằng :math:`L` được tạo ra sau vài biến đổi từ :math:`e = m^f \pmod{n^2}`, mà mình cần hai số :math:`m` cho cùng :math:`L`, vậy chỉ cần cho ra cùng :math:`e` là xong. Như hồi nãy mình có đề cập là :math:`f` luôn chẵn, vậy chỉ cần chọn :math:`m` và :math:`n^2-m` là xong. :))

Flag: ``CCTF{Phillip_N0W_4_pr0b4b1liStiC__aSymM3Tr1C__AlGOrithM!!}``.

Onlude
=======

Bài này mình giải trước khi hết thời gian 1 tiếng và là bài cuối cùng mình giải được. Hàm ``prepare`` chuyển flag thành ma trận :math:`A`, ``key`` là bộ ba ma trận :math:`R`, :math:`L` và :math:`U`. Ma trận :math:`S=L U`.

Việc mã hóa như sau:

* với :math:`R`, :math:`L` và :math:`U` như trên, tính :math:`S = LU`;
* tính :math:`X = A + R`, :math:`Y = S X` và ciphertext là :math:`E = L^{-1} Y`.

Đề cho mình bốn ma trận:

* :math:`E` là ciphertext, với một chút biến đổi mình có :math:`E = U (A+R)`;
* ma trận :math:`L U L`;
* ma trận 

.. math:: 
	
	L^{-1} S^2 L = L^{-1} (LU)^2 L = L^{-1}LULUL=(UL)^2,

mình đặt là :math:`T`;

* ma trận :math:`R^{-1}S^8`, mình đặt là :math:`W`.

Lấy :math:`LUL` nhân với :math:`T` mình có :math:`LUL \cdot (UL)^2 = L(UL)^3`. 

Khi đó

.. math:: 
	
	T^2 [L(UL)^3]^{-1} = (UL)^4 \cdot (UL)^{-3} \cdot L^{-1} = UL \cdot L^{-1} = U.

Vậy là mình có :math:`U` rồi. :))

Quay lại :math:`E = U (A + R)`, khi đó :math:`R = U^{-1} E - A`, nhân bên phải của hai vế với :math:`W` thì 

.. math:: 
	
	R \cdot R^{-1} S^8 = (U^{-1} E - A) W = S^8 = (LU)^8.

Quay lại một chút, 

.. math:: 
	
	(LUL) \cdot T^3 = (LUL) \cdot (L^{-1}S^6L) = (LU)^7 \cdot L,

suy ra :math:`(LUL) \cdot T^3 \cdot U = (LU)^8`.

Từ đó mình dễ dàng tìm lại được :math:`A = U^{-1}E - (LU)^8 W^{-1}`.

Thực hiện tương tự hàm ``prepare`` mình có được flag.

.. Flag: ``CCTF{LU__D3c0mpO517Ion__4L90?}``.
