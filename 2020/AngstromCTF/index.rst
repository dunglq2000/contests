angstromCTF 2020
================

Bài viết trình bày lời giải cho angstromCTF 2020.

Keysar
------

**Mô tả**

Hey! My friend sent me a message... He said encrypted it with the key ANGSTROMCTF.

He mumbled what cipher he used, but I think I have a clue.

Gotta go though, I have history homework!!

agqr{yue_stdcgciup_padas}

**Lời giải**

Từ định dạng ``actf{...}`` của cờ, bốn kí tự đầu cho các ánh xạ giải mã
``a -> a``, ``g -> c``, ``q -> t`` và ``r -> f``. Viết bảng chữ cái cùng
khóa ``ANGSTROMCTF`` cho kết quả sau.

.. code-block:: python

   a b c d e f g h i j k l m n o p q r s t u v w x y z

   A N G S T R O M =======> key nè

Ba ánh xạ ``G -> c``, ``A -> a`` và ``R -> f`` phù hợp với các ánh xạ đã
suy ra. Sau khi loại các chữ cái lặp trong ``ANGSTROMCTF``, ta bổ sung những
chữ cái còn thiếu theo thứ tự bảng chữ cái:

.. code-block:: python

   a b c d e f g h i j k l m n o p q r s t u v w x y z

   A N G S T R O M C F B D E H I J K L P Q U V W X Y Z

Tra ngược theo bảng thay thế trên, bản mã
``agqr{yue_stdcgciup_padas}`` được giải thành
``actf{yum_delicious_salad}``.

**Cờ:** actf{yum_delicious_salad}

Confused Streaming
------------------

**Mô tả**
I made a stream cipher!

nc crypto.2020.chall.actf.co 20601

**Lời giải**

.. code-block:: python

   from __future__ import print_function
   import random,os,sys,binascii
   from decimal import *
   try:
   	input = raw_input
   except:
   	pass
   getcontext().prec = 1000
   def keystream(key):
   	random.seed(int(os.environ["seed"]))
   	e = random.randint(100,1000)
   	while 1:
   		d = random.randint(1,100)
   		ret = Decimal('0.'+str(key ** e).split('.')[-1])
   		for i in range(d):
   			ret*=2
   		yield int((ret//1)%2)
   		e+=1
   try:
   	a = int(input("a: "))
   	b = int(input("b: "))
   	c = int(input("c: "))
   	# remove those pesky imaginary numbers, rationals, zeroes, integers, big numbers, etc
   	if b*b < 4*a*c or a==0 or b==0 or c==0 or Decimal(b*b-4*a*c).sqrt().to_integral_value()**2==b*b-4*a*c or abs(a)>1000 or abs(b)>1000 or abs(c)>1000:
   		raise Exception()
   	key = (Decimal(b*b-4*a*c).sqrt() - Decimal(b))/Decimal(a*2)
   except:
   	print("bad key")
   else:
   	flag = binascii.hexlify(os.environ["flag"].encode())
   	flag = bin(int(flag,16))[2:].zfill(len(flag)*4)
   	ret = ""
   	k = keystream(key)
   	for i in flag:
   		ret += str(next(k)^int(i))
   	print(ret)

Chương trình nhận ba số nguyên :math:`a,b,c` và kiểm tra một số điều kiện.
Điều kiện chứa ``to_integral_value`` loại trường hợp
:math:`b^2-4ac` là số chính phương.

Khóa được tính bởi

.. math::

   k=\frac{\sqrt{b^2-4ac}-b}{2a},

tức một nghiệm của phương trình :math:`ax^2+bx+c=0`.

Mỗi bit của cờ được XOR với một bit của dòng khóa. Hàm ``keystream`` chọn
ngẫu nhiên :math:`e\in[100,1000]`; ở mỗi vòng, hàm chọn
:math:`d\in[1,100]`, lấy phần thập phân của :math:`k^e`, nhân với
:math:`2^d`, rồi lấy phần nguyên modulo :math:`2`.

Sau mỗi lần ``yield``, hàm ``keystream`` quay lại vòng lặp ``while 1``, sinh ngẫu nhiên giá trị :math:`d` mới và tính lại ``ret`` trong khi giữ nguyên :math:`e`.

Mặc dù :math:`e` và :math:`d` là ngẫu nhiên, có thể buộc mọi bit dòng khóa
bằng :math:`0` bằng cách chọn :math:`0<k<1/2`. Khi đó
:math:`k^e2^d\leq k^{100}2^{100}<1` với mọi giá trị được phép của
:math:`e` và :math:`d`.

Như vậy chỉ cần chọn :math:`a, b, c` thỏa các điều kiện của chương trình sao cho :math:`0 < k < 1/2`. Khi đó :math:`k^e < 1` nên phần thập phân của :math:`k^e` chính là :math:`k^e`, và mọi bit dòng khóa bằng :math:`0`.

Chọn :math:`a=6`, :math:`b=8` và :math:`c=-3`: :math:`b^2-4ac = 136` không chính phương và :math:`k = (\sqrt{136}-8)/12 \approx 0{,}305`. Khi đó hàm ``keystream`` luôn trả về :math:`0`.

.. code-block:: python

   # p receive from server
   p = '01100001011000110111010001100110011110110110010001101111011101110110111001011111011101000110111101011111011101000110100001100101010111110110010001100101011000110110100101101101011000010110110001111101'
   plain = ''
   for i in p:
   	plain += str(0 ^ int(i))
   from Crypto.Util.number import *
   print(long_to_bytes(int(plain, 2)))

**Cờ:** actf{down_to_the_decimal}
