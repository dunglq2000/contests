TJCTF 2025
**********

Đề và code giải mình để ở `đây <https://github.com/dunglq2000/CTF/tree/master/2025/TJCTF>`_.

alchemist-recipe
================

Đề bài
------

.. code-block:: python

    import hashlib

    SNEEZE_FORK = "AurumPotabileEtChymicumSecretum"
    WUMBLE_BAG = 8 

    def glorbulate_sprockets_for_bamboozle(blorbo):
        zing = {}
        yarp = hashlib.sha256(blorbo.encode()).digest() 
        zing['flibber'] = list(yarp[:WUMBLE_BAG])
        zing['twizzle'] = list(yarp[WUMBLE_BAG:WUMBLE_BAG+16])
        glimbo = list(yarp[WUMBLE_BAG+16:])
        snorb = list(range(256))
        sploop = 0
        for _ in range(256): 
            for z in glimbo:
                wob = (sploop + z) % 256
                snorb[sploop], snorb[wob] = snorb[wob], snorb[sploop]
                sploop = (sploop + 1) % 256
        zing['drizzle'] = snorb
        return zing

    def scrungle_crank(dingus, sprockets):
        if len(dingus) != WUMBLE_BAG:
            raise ValueError(f"Must be {WUMBLE_BAG} wumps for crankshaft.")
        zonked = bytes([sprockets['drizzle'][x] for x in dingus])
        quix = sprockets['twizzle']
        splatted = bytes([zonked[i] ^ quix[i % len(quix)] for i in range(WUMBLE_BAG)])
        wiggle = sprockets['flibber'] 
        waggly = sorted([(wiggle[i], i) for i in range(WUMBLE_BAG)])
        zort = [oof for _, oof in waggly]
        plunk = [0] * WUMBLE_BAG
        for y in range(WUMBLE_BAG):
            x = zort[y]
            plunk[y] = splatted[x]
        return bytes(plunk)

    def snizzle_bytegum(bubbles, jellybean):
        fuzz = WUMBLE_BAG - (len(bubbles) % WUMBLE_BAG)
        if fuzz == 0: 
            fuzz = WUMBLE_BAG
        bubbles += bytes([fuzz] * fuzz)
        glomp = b""
        for b in range(0, len(bubbles), WUMBLE_BAG):
            splinter = bubbles[b:b+WUMBLE_BAG]
            zap = scrungle_crank(splinter, jellybean)
            glomp += zap
        return glomp

    def main():
        try:
            with open("flag.txt", "rb") as f:
                flag_content = f.read().strip()
        except FileNotFoundError:
            print("Error: flag.txt not found. Create it with the flag content.")
            return

        if not flag_content:
            print("Error: flag.txt is empty.")
            return

        print(f"Original Recipe (for generation only): {flag_content.decode(errors='ignore')}")

        jellybean = glorbulate_sprockets_for_bamboozle(SNEEZE_FORK)
        encrypted_recipe = snizzle_bytegum(flag_content, jellybean)

        with open("encrypted.txt", "w") as f_out:
            f_out.write(encrypted_recipe.hex())

        print(f"\nEncrypted recipe written to encrypted.txt:")
        print(encrypted_recipe.hex())

    if __name__ == "__main__":
        main()

Giải
----

Đây là một bài obfuscate code khiến chúng ta không hiểu được ý nghĩa của từng hàm, từng biến.

Đầu tiên hãy bắt đầu từ hàm ``main``.

.. code-block:: python

    def main():
        try:
            with open("flag.txt", "rb") as f:
                flag_content = f.read().strip()
        except FileNotFoundError:
            print("Error: flag.txt not found. Create it with the flag content.")
            return

        if not flag_content:
            print("Error: flag.txt is empty.")
            return

        print(f"Original Recipe (for generation only): {flag_content.decode(errors='ignore')}")

        jellybean = glorbulate_sprockets_for_bamboozle(SNEEZE_FORK)
        encrypted_recipe = snizzle_bytegum(flag_content, jellybean)

        with open("encrypted.txt", "w") as f_out:
            f_out.write(encrypted_recipe.hex())

        print(f"\nEncrypted recipe written to encrypted.txt:")
        print(encrypted_recipe.hex())

    if __name__ == "__main__":
        main()

Ở dòng tính ``encrypted_recipe``, đầu vào là ``flag_content`` nên chúng ta có thể đoán được ``snizzle_bytegum`` là hàm encrypt và ``jellybean`` khóa vì hàm encrypt luôn có đầu vào là bản rõ và khóa.

Khi đó mình dùng tính năng Rename của IDE để thay ``jellybean`` thành ``key``, và thay ``snizzle_bytegum`` thành ``encrypt``.

Trước đó, ``jellybean`` được tính bởi hàm ``glorbulate_sprockets_for_bamboozle`` nên có thể đoán rằng đây là hàm sinh khóa và mình cũng đổi tên thành ``keygen``.

Như vậy hàm ``main`` của mình có dạng

.. code-block:: python

    def main():
        try:
            with open("flag.txt", "rb") as f:
                flag_content = f.read().strip()
        except FileNotFoundError:
            print("Error: flag.txt not found. Create it with the flag content.")
            return

        if not flag_content:
            print("Error: flag.txt is empty.")
            return

        print(f"Original Recipe (for generation only): {flag_content.decode(errors='ignore')}")

        key = keygen(SNEEZE_FORK)
        encrypted_recipe = encrypt(flag_content, key)

        with open("encrypted.txt", "w") as f_out:
            f_out.write(encrypted_recipe.hex())

        print(f"\nEncrypted recipe written to encrypted.txt:")
        print(encrypted_recipe.hex())

Tiếp theo chúng ta xét hàm ``keygen`` hoặc ``encrypt``.

Hàm ``keygen`` có dạng

.. code-block:: python

    def keygen(blorbo):
        zing = {}
        yarp = hashlib.sha256(blorbo.encode()).digest() 
        zing['flibber'] = list(yarp[:WUMBLE_BAG])
        zing['twizzle'] = list(yarp[WUMBLE_BAG:WUMBLE_BAG+16])
        glimbo = list(yarp[WUMBLE_BAG+16:])
        snorb = list(range(256))
        sploop = 0
        for _ in range(256): 
            for z in glimbo:
                wob = (sploop + z) % 256
                snorb[sploop], snorb[wob] = snorb[wob], snorb[sploop]
                sploop = (sploop + 1) % 256
        zing['drizzle'] = snorb
        return zing

Thông thường đầu vào của hàm sinh khóa là một seed nào đó nên mình sẽ thay ``blorbo`` thành ``seed``.

Hàm ``keygen`` trả về biến ``zing`` nên có thể thay ``zing`` thành ``key``, chính là khóa mã hóa.

Biến ``WUMBLE_BAG`` có độ dài là :math:`8` và 
cũng được sử dụng trong hàm ``encrypt`` nên đó 
chính là ``BLOCK_SIZE``. Ngoài ra chúng ta không 
cần xem xét quá nhiều bên trong hàm ``keygen``, 
chỉ cần biết rằng khóa có ba phần, phần đầu ``key['flibber']`` 
có :math:`8` bytes, phần hai ``key['twizzle']`` 
có :math:`8` bytes, và phần cuối ``key['drizzle']`` 
có :math:`256` bytes. Do ``seed`` cố định nên ``key`` sinh ra cũng cố định. Để dễ nhìn hơn thì mình cũng đổi tên các biến khác nhưng các bạn không làm cũng không sao. Khi đó hàm ``keygen`` có dạng

.. code-block:: python

    def keygen(seed):
        key = {}
        key_hash = hashlib.sha256(seed.encode()).digest() 
        key['flibber'] = list(key_hash[:BLOCK_SIZE])
        key['twizzle'] = list(key_hash[BLOCK_SIZE:BLOCK_SIZE+16])
        glimbo = list(key_hash[BLOCK_SIZE+16:])
        S = list(range(256))
        i = 0
        for _ in range(256): 
            for z in glimbo:
                j = (i + z) % 256
                S[i], S[j] = S[j], S[i]
                i = (i + 1) % 256
        key['drizzle'] = S
        return key

Tiếp theo, xét hàm ``encrypt``.

.. code-block:: python

    def encrypt(bubbles, jellybean):
        fuzz = BLOCK_SIZE - (len(bubbles) % BLOCK_SIZE)
        if fuzz == 0: 
            fuzz = BLOCK_SIZE
        bubbles += bytes([fuzz] * fuzz)
        glomp = b""
        for b in range(0, len(bubbles), BLOCK_SIZE):
            splinter = bubbles[b:b+BLOCK_SIZE]
            zap = scrungle_crank(splinter, jellybean)
            glomp += zap
        return glomp

Như đã phân tích ở hàm ``main``, tham số đầu của ``encrypt`` là bản rõ và tham số thứ hai là khóa. Như vậy mình đổi tên ``bubbles`` thành ``plaintext`` và ``jellybean`` thành ``key``.

Chúng ta có thể đoán rằng ``fuzz`` là padding (PKCS7) vì ``plaintext`` được thêm vào các bytes cho đủ độ dài ``BLOCK_SIZE`` (trước là ``WUMBLE_BAG``).

Sau đó ``splinter`` là các khối bản rõ (độ dài :math:`8`) nên có thể đoán rằng ``scrungle_crank`` là hàm mã hóa từng khối, mình đổi tên thành ``encrypt_block``.

Như vậy hàm ``encrypt`` của mình có dạng

.. code-block:: python

    def encrypt(plaintext, key):
        pad = BLOCK_SIZE - (len(plaintext) % BLOCK_SIZE)
        if pad == 0: 
            pad = BLOCK_SIZE
        plaintext += bytes([pad] * pad)
        ciphertext = b""
        for b in range(0, len(plaintext), BLOCK_SIZE):
            block = plaintext[b:b+BLOCK_SIZE]
            zap = encrypt_block(block, key)
            ciphertext += zap
        return ciphertext   

Cuối cùng, xét hàm ``encrypt_block``.

.. code-block:: python

    def encrypt_block(dingus, sprockets):
        if len(dingus) != BLOCK_SIZE:
            raise ValueError(f"Must be {BLOCK_SIZE} wumps for crankshaft.")
        zonked = bytes([sprockets['drizzle'][x] for x in dingus])
        quix = sprockets['twizzle']
        splatted = bytes([zonked[i] ^ quix[i % len(quix)] for i in range(BLOCK_SIZE)])
        wiggle = sprockets['flibber']
        waggly = sorted([(wiggle[i], i) for i in range(BLOCK_SIZE)])
        zort = [oof for _, oof in waggly]
        plunk = [0] * BLOCK_SIZE
        for y in range(BLOCK_SIZE):
            x = zort[y]
            plunk[y] = splatted[x]
        return bytes(plunk)

Tham số thứ nhất của ``encrypt_block`` chính là bản rõ nên mình đổi tên ``dingus`` thành ``plaintext``, tương tự tham số thứ hai là khóa nên mình đổi ``sprockets`` thành ``key``.

Như mình đã nói ở trên, ``key`` gồm ba phần.

1. Phần cuối ``key['drizzle']`` của khóa có độ dài :math:`256` bytes nên có thể thấy ``zonked`` là S-box, mình đổi tên thành ``Sbox_key_third``.
2. Phần thứ hai ``key['twizzle']`` của khóa có :math:`8` bytes nên mình đổi tên ``quix`` thành ``key_second``.
3. Tiếp theo, ``splatted`` là XOR của phần cuối và phần thứ hai nên mình đổi tên thành ``third_X_second``.
4. Phần đầu ``key['flibber']`` có :math:`8` bytes nên mình đổi tên ``wiggle`` thành ``key_first``.
5. Tiếp theo, ``waggly`` là sắp xếp lại giá trị của ``key_first`` nên mình đổi tên thành ``key_first_srt``.
6. Mình bỏ qua ``zort``
7. Nhìn xuống một chút mình thấy hàm ``encrypt_block`` return ``bytes(plunk)`` nên có thể đoán ``plunk`` là bản mã, mình đổi tên thành ``ct``.

Như vậy hàm ``encrypt_block`` có dạng

.. code-block:: python

    def encrypt_block(block, key):
        if len(block) != BLOCK_SIZE:
            raise ValueError(f"Must be {BLOCK_SIZE} wumps for crankshaft.")
        Sbox_key_third = bytes([key['drizzle'][x] for x in block])
        key_second = key['twizzle']
        third_X_second = bytes([Sbox_key_third[i] ^ key_second[i % len(key_second)] for i in range(BLOCK_SIZE)])
        key_first = key['flibber'] 
        key_first_srt = sorted([(key_first[i], i) for i in range(BLOCK_SIZE)])
        zort = [oof for _, oof in key_first_srt]
        ct = [0] * BLOCK_SIZE
        for y in range(BLOCK_SIZE):
            x = zort[y]
            ct[y] = third_X_second[x]
        return bytes(ct)

Khi đã viết lại tên biến thì chúng ta thực hiện ngược lại là giải mã được.

bacon-bits
==========

Đề bài
------

.. code-block:: python

    with open('flag.txt') as f: flag = f.read().strip()
    with open('text.txt') as t: text = t.read().strip()

    baconian = {
    'a': '00000',	'b': '00001',
    'c': '00010',	'd': '00011',
    'e': '00100',	'f': '00101',
    'g': '00110',	'h': '00111',
    'i': '01000',    'j': '01000',
    'k': '01001',    'l': '01010',
    'm': '01011',    'n': '01100',
    'o': '01101',    'p': '01110',
    'q': '01111',    'r': '10000',
    's': '10001',    't': '10010',
    'u': '10011',    'v': '10011',
    'w': '10100',	'x': '10101',
    'y': '10110',	'z': '10111'}

    text = [*text]
    ciphertext = ""
    for i,l in enumerate(flag):
        if not l.isalpha(): continue
        change = baconian[l]
        ciphertext += "".join([ts for ix, lt in enumerate(text[i*5:(i+1)*5]) if int(change[ix]) and (ts:=lt.upper()) or (ts:=lt.lower())]) #python lazy boolean evaluation + walrus operator

    with open('out.txt', 'w') as e:
        e.write(''.join([chr(ord(i)-13) for i in ciphertext]))

Giải
----

Đề bài chuyển các kí tự của flag thành dãy :math:`5` bit. Xét dãy bit song song với chuỗi ``text``, nếu là bit :math:`1` thì kí tự ở vị trí tương ứng của ``text`` là chữ hoa, ngược lại là chữ thường.

Một điều cần lưu ý là kí tự ``i`` và ``j`` đều được chuyển thành chuỗi bit :math:`01000`, tương tự, kí tự ``u`` và ``v`` đều được chuyển thành cùng chuỗi bit :math:`10011`. Do đó khi tìm ngược lại plaintext cần xét cả hai trường hợp.

close-secrets
================

Đề bài
------

Đề bài sử dụng Diffie-Hellman với các số nguyên tố :math:`p` và :math:`g`. Chọn :math:`a \in [p - 10, p]` và :math:`b \in [g - 10, g]`.

Đề bài tính :math:`u = g^a \bmod p` và :math:`v = g^b \bmod p` để trao đổi khóa. Khóa chung là :math:`u^b \equiv v^a \bmod p`.

Khi đó ``xor_key_str`` là SHA256 của khóa chung và được dùng trong ``dynamic_xor_encrypt``, cụ thể là xor từng bytes của flag với ``xor_key_bytes``.

Tiếp theo, hàm ``encrypt_outer`` lấy ASCII của từng kí tự, cộng với ``key_offset`` và nhân với ``key``. Do ``key`` cố định (khóa chung) nên ``key_offset`` cũng cố định.

Giải
----

Chúng ta chỉ cần bruteforce :math:`a` và :math:`b` rồi làm ngược lại hai hàm trên.

dotdotdotv2
================

Đề bài
------

Đề bài chuyển một chuỗi dài ơi là dài thành dãy bit (mỗi kí tự tương ứng :math:`8` bits) và lập ma trận có :math:`64` cột, còn số hàng tùy thuộc độ dài cuối cùng. Ta gọi ma trận này là :math:`\mathsf{flag}`.

Đề bài sinh khóa là ma trận :math:`64 \times 64` với các phần tử thuộc đoạn :math:`[0, 0xdeadbeef]`. Ta gọi ma trận này là :math:`\mathsf{key}`.

Như vậy kết quả là phép nhân ma trận :math:`\mathsf{res} = \mathsf{flag} \cdot \mathsf{key}`.

Giải
----

Độ dài của ``filler`` là :math:`500` bytes, tương ứng :math:`4000` bits. Ma trận :math:`64 \times 64` sẽ cần :math:`4096` bits. Chúng ta biết format flag là ``tjctf{`` nên thêm vào :math:`4` bytes nữa là đủ để có ma trận :math:`63 \times 64`.

Chúng ta sẽ chuyển tất cả tính toán sang :math:`\mathbb{F}_2` thay vì để nguyên các số lớn kia.

Khi đó ta gọi ma trận :math:`63 \times 64` là :math:`\mathsf{ff}`, và dùng :math:`63` dòng đầu của ma trận kết quả :math:`\mathsf{res}` ta sẽ tìm được ma trận :math:`\mathsf{key}`.

Ở đây :math:`\mathsf{ff}` có hạng là :math:`55` nên ma trận :math:`\mathsf{key}` tìm được không phải duy nhất, tệ hơn nữa là :math:`\mathsf{key}` không khả nghịch. Do đó chúng ta sẽ dùng giả nghịch đảo (pseudo inverse) của :math:`\mathsf{key}` để tính flag.

.. code-block:: python

    from sage.all import *
    import itertools

    n = 64

    filler = "..."

    flag = "tjctf{"
    flag = filler + flag

    with open("encoded.txt") as f:
        lines = [line.strip() for line in f.readlines()]
        
        ff = flag[:504]
        ff = "".join(["".join(bin(ord(i))[2:].zfill(8)) for i in ff])
        ff = matrix(GF(2), [list(map(int,list(ff[i:i+n]))) for i in range(0, len(ff), n)])
        
        res = list(list(map(int, line.split())) for line in lines)
        res = matrix(GF(2), [list(map(int, line.split(' '))) for line in lines])

        sol = ff.solve_right(res[:63, :])

        rr = res * sol.pseudoinverse()
        result = b''
        for r in rr:
            row = ''.join(map(str, r))
            result += bytes([int(row[i:i+8], 2) for i in range(0, 64, 8)])
        print(result)

Kết quả khá bất ngờ, mình nhận được chuỗi ``b'In cybeRsecuritY``. Như vậy mình chỉ cần sửa kí tự ``R`` thành ``r`` nữa là xong. Để ý rằng nếu xét :math:`8` kí tự, tương ứng :math:`64` bit, thì chỉ cần cộng :math:`1` vào bit thứ :math:`58`.

double-trouble
================

Đề bài
------

Mã hóa AES hai lần, mỗi lần mã hóa với nửa khóa cố định và nửa khóa còn lại là một trong :math:`4^8 = 65536` trường hợp.

Giải
----

Mình sử dụng OpenMP và tối ưu ``-O2`` để bruteforce khóa tương ứng.

pseudo-secure
================

Đề bài
------

Sinh số ngẫu nhiên.

Giải
----

Sử dụng module ``extend_mt19937_predictor`` ở `ExtendMT19937Predictor <https://github.com/NonupleBroken/ExtendMT19937Predictor>`_.

seeds
================

Đề bài
------

Sử dụng seed để sinh ra khóa cho thuật toán AES.

Giải
----

Seed "có vẻ" cố định và luôn cho ra cùng khóa, bất kể thời gian.

theartofwar
================

Đề bài
------

Đề bài sinh :math:`e` modulus :math:`n_i` và mã hóa cùng bản rõ :math:`m` với :math:`c_i = m^e \bmod n_i`.

Giải
----

Sử dụng định lí số dư Trung Hoa (broadcast attack) và tính căn bậc :math:`e` để tìm lại :math:`m`.

Writeup tới đây là hết. Cám ơn các bạn đã đọc.

