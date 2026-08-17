Efiens CTF 2020
===============

Crypto
------

1. BabyRSA
~~~~~~~~~~

Người đọc xem đề bài ở `đây <babysra.py>`_

Ở đây người ra đề cho RSA với e=65537, n=p * q với p, q là số nguyên tố 512 bit và ẩn đi 45% số bit đó bằng hàm **leak**. Ta dựa trên các bit không bị ẩn đi để tìm lại p và q.

Nhận xét rằng k bits thấp nhất của n (LSB) sẽ chỉ bị ảnh hưởng bởi k bits thấp nhất của p và q. Từ đó ta viết hàm duyệt vét cạn các bit của p và q từ thấp lên cao cho tới khi nhận được tích pq đúng bằng n.

Mã nguồn được lưu tại `đây <babyrsa_solve.py>`_

Flag: **EFIENSCTF{\_\_\_Basic_RSA_chall____}**

2. ECBC
~~~~~~~

Người đọc xem đề bài ở `đây <ecbc.py>`_

Hàm **encrypt** sẽ theo biểu diễn nhị phân của flag mà mã hóa input của ta. Với mỗi bit của flag, nếu là 0 thì sẽ mã hóa input bằng AES với mode là CBC, nếu là 1 sẽ mã hóa bằng AES với mode ECB. Mỗi lần như vậy key random. Tuy nhiên, nếu ta truyền vào 2 blocks plaintext P1 và P2 giống nhau (P1 và P2 là các block 16 bytes) thì AES sẽ cho 2 ciphertext C1 và C2 giống nhau, còn CBC thì không. Vì vậy ta gửi lên server 32 ký tự giống nhau Ở đây ta truyền b'a' * 32.

Dựa vào nhận xét trên, ta recover được flag

Mã nguồn được lưu tại `đây <ecbc_solve.py>`_

Flag: **EFIENSCTF{Now_you_know_ECB_is_weak_;)_}**

3. Four Time Pad
~~~~~~~~~~~~~~~~

Người đọc xem đề ở `đây <fourtimepad.py>`_

Đề bài sử dụng 4 seed bị giấu để sinh ra 4 số random a, b, c, d và cho chúng ta biết *magic number* là \~(a)^(b&c)^(c|d) và *ciphertext* là ct=flag^a^b^c^d. Ở đây ta duyệt vét cạn b, c, d và dựa trên hàm **twist** để tìm lại a. Tức là a=\~(magic_number ^ (b&c) ^ (c|d))

Mã nguồn được lưu tại `đây <fourtimepad_solve.py>`_

Flag: **EFIENSCTF{Kowalski_Analy5isss!!}**

4. ROT1000
~~~~~~~~~~

Người đọc xem đề ở `đây <rot1000.py>`_

Đề bài mã hóa flag như sau:

- Mã hóa Caesar flag x lần (x random từ 1 tới 1000). Mỗi lần rotate 1 số random từ 1 tới 26. Kết quả cuối cùng vẫn là rotate flag 1 số nào đó từ 1 tới 26.

- Encode base64 chuỗi vừa nhận được và lưu thành biến **cipher**

- Biến kết quả **l** được tạo ra từ công thức l[i]=cipher[i]^cipher[(i+1)%len(cipher)]

- Trả về base64 của **l**

Đầu tiên ta decode base64 của ciphertext. Ta duyệt vét cạn để xem ký tự cuối của biến **cipher** ở trên là gì. Do đó là ký tự in được nên ta cho từ 32 tới 128, từ đó dựa vào **l** ta khôi phục lại biến **cipher** và thử decode và tìm được flag

Mã nguồn được lưu tại `đây <rot1000_solve.py>`_

Flag: **EFIENSCTF{\_WARMUP_BABE_\_ENJOY_THE_CTF_}**
