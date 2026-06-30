UTCTF 2023
**********

Đề và bài giải ở `đây <https://github.com/dunglq2000/CTF/tree/master/2023/UTCTF>`_.

Affinity
========

Đề cho mình hai source code: ``aes.py`` và ``encrypt_pub.py``.

Trong bài này có điểm khác thường so với thuật toán AES gốc là **SBOX tuyến tính**. Điều đó có nghĩa là với 2 cặp plaintext-ciphertext bất kì :math:`(P_0, C_0)` và :math:`(P_i, C_i)` thì có một ma trận :math:`A` thỏa :math:`P_0 \oplus P_i = A \cdot (C_0 \oplus C_i)`.

Lưu ý là mỗi block AES có :math:`16` byte tương đương :math:`128` bit, nên :math:`A` là ma trận :math:`128 \times 128` trên :math:`\mathrm{GF}(2)`. Như vậy mình chọn :math:`P_0 = 0^{128}`, và :math:`P_i = (0, \ldots, 1, \ldots 0)` với :math:`1` nằm ở vị trí :math:`i` (:math:`i = 1, \ldots, 128`). Với đủ :math:`128` cặp như vậy mình khôi phục được ma trận :math:`A` từ đó suy ra flag với :math:`P_t = P_0 \oplus A \cdot (C_0 \oplus C_t)`.

Provably Insecure
=================

Ở bài này Alice cho chúng ta public key RSA :math:`(n, e)`, và cặp :math:`(s, m)` với :math:`s = m^d \pmod n`.

Nhiệm vụ là tìm các số :math:`(n', e', d')` sao cho với mỗi số random :math:`x` thì các điều kiện sau thỏa mãn:

* :math:`n' \neq n` và :math:`e' \neq e`;
* :math:`n' > s`;
* :math:`x^{e' d'} = 1 \pmod{n'}`;
* :math:`e' > 1`;
* :math:`s^{e'} = m \pmod{n'}`.

Quan trọng là ở điều kiện cuối, ở hai modulo khác nhau nhưng cho cùng kết quả khi decrypt.

Cách làm của mình là, nếu :math:`s^{e'} = m \pmod{n'}` thì tương đương với :math:`(m^{d'})^{e'} = m \pmod{n'}`. Như vậy mình chọn modulo :math:`n'` và tính discrete log :math:`m^{d'} = s \pmod{n'}` và có :math:`d'`. Sau đó mình tìm nghịch đảo :math:`e'` của :math:`d'` trong :math:`\varphi(n')`.

Cách làm này cần 2 điều kiện:

* tồn tại discrete log :math:`m^{d'}=s` trong modulo :math:`n'`;
* :math:`\gcd(d', \varphi(n')) = 1` để tìm :math:`e'`.

Mình cứ request tới khi có :math:`(s, m)` thỏa mãn thôi. Với cách làm này thì không cần quan tâm :math:`(n, e)`.

Looks Wrong tom E
=================

Bài này có :math:`10` round, mỗi round sẽ sinh một số lượng ma trận trong :math:`\mathrm{GF}(10^9+7)` (tối đa :math:`10` ma trận mỗi round).

Với mỗi ma trận, server tạo random vector :math:`s` và error nhỏ :math:`e`, rồi tính :math:`s \cdot A + e` và gửi ma trận :math:`A` lẫn vector :math:`s \cdot A + e` cho mình.

Nhiệm vụ của mình là chọn ma trận trong số :math:`10` ma trận đó (hoặc ít hơn), và gửi lên vector :math:`s'` sao cho tích :math:`s \cdot A` là vector nhỏ. Cụ thể là :math:`b = s \cdot A = (b_1, b_2, \ldots)` thì :math:`b_i < 4w` hoặc :math:`\mathrm{mod} - b_i < 4 w`.

Sau nhiều nỗ lực nghĩ LLL thì mình phát hiện rằng mình cứ gửi :math:`s = (0, 0, \ldots)` thì kết quả luôn là vector :math:`0` :))))

Bài cuối mình không thấy sự liên quan hay gì từ đề nên ngậm ngùi chịu chết.

Cám ơn các bạn đã đọc writeup của mình.
