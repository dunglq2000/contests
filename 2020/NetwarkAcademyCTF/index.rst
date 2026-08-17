Netwark Academy CTF 2020
========================

1. Caesar's Challenge
---------------------

**Mô tả**: Zabelo wrote this message on a note he passed to me. anpgs{q3p1cu3e1at_e0px5!} He also told me his favorite number was 13. What could this mean?

**Lời giải**: Đây là 1 bài ceasar cơ bản. Duyệt vét cạn tất cả key ta có được flag: **nactf{d3c1ph3r1ng_r0ck5!}** với key là 13

2. YASM
-------

**Mô tả**: Instead of turnips, Yavan loves YAMS. Day and night, he sings about YAMS, dreams about YAMS and runs to the store to catch the newest released batch of YAMS. Hes cryptic too. I wonder what this could mean.

Uexummq lm Vuycnqjc. Hqjc ie qmud xjas: fycfx{waY5_sp3_Y0yEw_w9vU91}

**Lời giải**: Ta biết format flag là nactf{....}, vậy thì nactf sẽ được mã hóa thành fycfx. Ta dò bảng Vigenere Cipher như sau: tìm trên cột n vị trí ký tự f, đối chiếu sang hàng ngang để tìm key (làm ngược với mã hóa). Cứ như vậy ta tìm được key là **syam** (từ chữ yasm). Flag là **nactf{yaM5_ar3_Y0mMy_w9jC91}**

3. Error 9
----------

**Mô tả**: Rahul has been trying to send a message to me through a really noisy communication channel. Repeating the message 101 times should do the trick!

**Lời giải**: Đề bài là file `enc.txt <enc.txt>`_. Theo gợi ý thì việc encode được làm 101 lần, nên ta tách chuỗi bit này thành 101 đoạn. Đến đây ta thống kê trên 101 đoạn đó tại mỗi vị trí i, nếu lượng bit 1 lớn hơn thì bit tại vị trí i trong flag là 1, và ngược lại. Mã nguồn thực hiện như sau:

.. code-block:: python

   c = "chuỗi bit"
   blocks = [c[i:i+len(c)//101] for i in range(0, len(c), len(c)//101)]
   f = ""
   flag = ""
   for i in range(len(blocks[0])):
       c0, c1 = 0, 0
       for b in blocks:
           if b[i] == "0":
               c0 += 1
           else:
               c1 += 1
       if c0 >= c1:
           f += "0"
       else:
           f += "1"
   for i in range(0, len(f), 8):
       flag += chr(int(f[i:i+8], 2))
   print(flag)

Kết quả thu được là **nactf{n01sy_n013j_|\|()|$'/}**; chuỗi này được hệ thống chấp nhận.

4. Oligar's Tricky RSA
----------------------

**Mô tả**: The crypto master Oligar just sent this file with three numbers. What do they mean?

**Lời giải**: Đề cho ta file rsa.txt

Đây là 1 bài rsa cơ bản, dùng các tool factor n thành p và q. Rồi decrypt như rsa bình thường

Flag: **nactf{sn3aky_c1ph3r}**

5. Error 1
----------

**Mô tả**: Pranay has decided that the previous error detection scheme is a little bit too inefficient... While eating his delicious HAM-filled Italian Sub at lunch, he came up with a new idea. Fortunately, he has also invested in a less noisy communication channel.

**Lời giải**: Đề cho ta 2 file: `enc.txt <enc1.txt>`_ và error1.py

.. code-block:: python

   import random
   from functools import reduce

   with open("flag.txt", "r") as fin:
       flag = fin.read()

   flag = "".join(str(format(ord(c), '08b')) for c in flag)  # converts flag to 8 bit ascii representation
   flag = [[int(j) for j in flag[i:i + 11]] for i in range(0, len(flag), 11)]  # separates into 11 bit groups
   code = []
   for i in flag:
       for j in range(4):
           i.insert(2 ** j - 1, 0)
       parity = reduce(lambda a, b: a ^ b, [j + 1 for j, bit in enumerate(i) if bit])
       parity = list(reversed(list(str(format(parity, "04b"))))) # separates number into individual binary bits

       for j in range(4):
           if parity[j] == "1":
               i[2 ** j - 1] = 1

       ind = random.randint(0, len(i) - 1)
       i[ind] = int(not i[ind]) # simulates a one bit error
       code.extend(i)

   enc = "".join([str(i) for i in code])
   with open("enc.txt", "w") as fout:
       fout.write(enc)

Giải này comment đầy đủ nên cũng dễ hiểu code. Đầu tiên ciphertext được chuyển thành chuỗi bit, với mỗi ký tự ascii đủ 8 bit. Sau đó chuỗi bit này được tách thành từng đoạn 11 bit. Sau đó từng đoạn sẽ được xử lý như sau: bit 0 sẽ được chèn vào các vị trí 0, 1, 3, 7 (2^j-1). Parity là kết quả của phép xor các chỉ số + 1 (j+1) nếu bit của đoạn tại vị trí j là 1. Sau đó parity được chuyển thành dạng 4 bit và đảo ngược chuỗi bit này. Vòng lặp kế tiếp biến đổi mỗi i[2^j-1] thành 1, nếu bit tại vị trí j của parity là "1". Cuối cùng 1 bit ngẫu nhiên trong i sẽ bị đổi dấu.

Ý tưởng của ta: Đầu tiên ta chia ciphertext thành các đoạn 15 bit (11 bit và thêm 4 bit dc chèn vào). Đối với mỗi đoạn, ta duyệt vét cạn vị trí bit bị đổi dấu. Ta tạo mảng parity = ["0", "0", "0", "0"], nếu i[2^j-1] = 1 thì parity[j]="1" (ngược lại với vòng lặp

.. code-block:: python

   for j in range(4):
           if parity[j] == "1":
               i[2 ** j - 1] = 1

và đổi tất cả bit ở vị trí i[2^j-1] thành 0. Tiếp đó, ta tính p (parity khác) bằng cách tận dụng lại câu lệnh của đề

.. code-block:: python

   p = reduce(lambda a, b: a ^ b, [j + 1 for j, bit in enumerate(i) if bit])
   p = list(reversed(list(str(format(p, "04b"))))) # separates number into individual binary bits

So sánh p với parity, nếu bằng nhau thì chính bit đó bị đổi dấu. Chỉ việc loại bỏ khỏi đoạn i tại các vị trí 0, 1, 3, 7 là ta có lại đoạn 11 bit ban đầu. Và code của ta: `error1dec.py <error1dec.py>`_

Flag: **nactf{hamm1ng_cod3s_546mv3q9a0te}** (oke Hamming code)

6. Error 2
==========

**Mô tả**: Kayla decided she wants to use the previous error detection scheme for cryptography! After computing the normal error bits, she switched them around according to a secret key.

Note: enc.txt has been reuploaded. Please redownload the file if you downloaded before 12:00 am 10/31

**Lời giải**: Lần này đề cũng có `enc.txt <enc2.txt>`_ và error2.py

.. code-block:: python

   import random
   from functools import reduce

   with open("flag.txt", "r") as fin:
       flag = fin.read()

   with open("pos.txt", "r") as fin:
       parity_pos = [int(i) for i in fin.read().split()]


   flag = "".join(str(format(ord(c), '08b')) for c in flag)  # converts flag to 8 bit ascii representation
   flag = [[int(j) for j in flag[i:i + 11]] for i in range(0, len(flag), 11)]  # separates into 11 bit groups

   code = []
   for i in flag:
       for j in range(4):
           i.insert(2 ** j - 1, 0)
       parity = reduce(lambda a, b: a ^ b, [j + 1 for j, bit in enumerate(i) if bit])
       parity = list(reversed(list(str(format(parity, "04b"))))) # separates number into individual binary bits

       i = [k for j, k in enumerate(i) if j not in (0, 1, 3, 7)]

       for j in range(4):
           if parity[j] == "1":
               i.insert(parity_pos[j], 1)
           else:
               i.insert(parity_pos[j], 0)

       ind = random.randint(0, len(i) - 1)
       i[ind] = int(not i[ind]) # simulates a one bit error
       code.extend(i)

   enc = "".join([str(i) for i in code])
   with open("enc.txt", "w") as fout:
       fout.write(enc)

Lần này khá tương tự trước, cũng chèn 0 vào các vị trí 0, 1, 3, 7, rồi tính nghịch đảo parity. Nhưng có 1 điểm khó là các vị trí đã chèn trước đó (0, 1, 3, 7) bị bỏ đi, thay vào đó bit parity[j] sẽ được chèn vào vị trí parity_pos[j]. Và parity_pos thì ta không biết.

Cách giải của ta là duyệt vét cạn để tìm parity_pos ta biết format flag là nactf, nếu ta chuyển từng ký tự thành 8 bit rồi gom các đoạn 11 bit thì ta lấy 2 đoạn đầu: "01101110011" và "00001011000". Ví dụ như này:

.. code-block:: python

   i = [int(j) for j in list("01101110011")]
   # i = [int(j) for j in list("00001011000")]
   start = 0
   for j in range(4):
       i.insert(2 ** j - 1, 0)

   parity = reduce(lambda a, b: a ^ b, [j + 1 for j, bit in enumerate(i) if bit])
   parity = list(reversed(list(str(format(parity, "04b"))))) # separates number into individual binary bits

   i = [k for j, k in enumerate(i) if j not in (0, 1, 3, 7)]
   for j in range(4):
       print(parity[j])
   test = [int(j) for j in list(c[15*start: 15*(start+1)])]
   summ = 0
   for j in i:
       if j == 1:
           summ += 1
   print(i)
   temp = []
   for ind in range(15):
       tmp = [j for j in test]
       tmp[ind] = int(not tmp[ind])

       s = 0
       for t in tmp:
           if t == 1:
               s += 1
       if s - summ == 2:
           # print(ind, tmp)
           temp.append(tmp)
   maxval = 11
   haha = []
   for tmp in temp:
       t = [j for j in i]
       for i1 in range(maxval):
           t.insert(i1, 1)
           for i2 in range(maxval):
               t.insert(i2, 0)
               for i3 in range(maxval):
                   t.insert(i3, 1)
                   for i4 in range(maxval):
                       t.insert(i4, 0)
                       if t == tmp:
                           print(i1, i2, i3, i4, tmp)
                           haha.append((i1, i2, i3, i4))
                       del t[i4]
                   del t[i3]
               del t[i2]
           del t[i1]
   print(haha)

**c** là chuỗi bit ciphertext, dài quá nên ta không chép lên đây. Ý tưởng cơ bản là, ta đếm số lượng bit 1 trong mảng i, và duyệt vét cạn từ ciphertext (là mảng **test**) và kiểm tra xem, nếu ta đổi dấu bit j thì số bit 1 có tăng so với i một lượng k hay không (k là số bit 1 trong parity vì theo đề thì số lượng bit 1 trong i sẽ tăng theo số lượng bit 1 của parity) và lưu vào temp. Sau đó ta brutefoce các vị trí nếu chèn 1, 0, 0, 1 (vì parity là 0 1 0 1 nên ta phải insert ngược lại nếu không sẽ có vấn đề về index) mà cho kết quả giống với 1 trong các phần tử trong temp hay không.

Ta có khoảng 6 trường hợp, thử từng cái thì ta có vị trí parity_pos là 5, 7, 8, 13. Tới đây làm tương tự bài **Error 1** là có flag (người đọc thử sức xem).

Mã nguồn được lưu tại `error2dec.py <error2dec.py>`_

Bài **Random Number Generator** chưa có lời giải.

