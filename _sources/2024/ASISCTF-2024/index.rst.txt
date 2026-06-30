ASIS CTF 2024
*************

Bài này mình làm sau khi giải kết thúc.

Clement
=======

Đề bài ở file :download:`source.py <Clement/source.py>`.

Ở bài này chúng ta cần nhập vào số :math:`n`. Chương trình sẽ tính :math:`k = n^2 + 4 n + 3`.

Hàm `factoreal` sẽ kiểm tra :math:`4 \cdot n! + n + 5 \equiv 0 \pmod k` hay không.

Để giải bài này mình cần định lý Wilson:

.. admonition:: Định lý Wilson
		
	Nếu :math:`p` là số nguyên tố thì

	.. math:: (p-1)! \equiv -1 \pmod p

Do :math:`k = n^2 + 4n + 3 = (n + 1) \cdot (n + 3)`, mình mong muốn tìm số :math:`n` thỏa mãn hai phương trình

.. math:: 

    4 \cdot n! + n + 5 \equiv 0 \pmod{n+1} \\ 
    4 \cdot n! + n + 5 \equiv 0 \pmod{n+3}


trong đó :math:`n+1` và :math:`n+3` là các số nguyên tố. Khi đó nghiệm trong modulo :math:`k` theo CRT sẽ là :math:`0`.

Nếu :math:`n + 1` là số nguyên tố, theo định lý Wilson thì :math:`n! \equiv -1 \pmod{n+1}`. Như vậy

.. math:: 4 \cdot n! + n + 5 \equiv 4 \cdot (-1) + (n + 1) + 4 \equiv -4 + 4 \equiv 0 \pmod{n+1}

Nếu :math:`n + 3` là số nguyên tố thì :math:`(n+2)! \equiv -1 \pmod{n+3}`. Khi đó

.. math:: 

    4 \cdot n! + n + 5 & \equiv 4 \cdot \dfrac{(n+3)!}{(n+2) \cdot (n+1)} + (n + 3) + 2 \pmod{n+3} \\
    & \equiv 4 \cdot \dfrac{(-1)}{(n + 2) \cdot (n + 1)} + 2 \equiv 0 \pmod{n+3}.

Như vậy nếu điều kiện cuối là :math:`4 \cdot \dfrac{-1}{(n+2) \cdot (n+1)} + 2 \equiv 0 \pmod{n+3}` thỏa mãn thì mình đã tìm được số :math:`n` cần thiết.

Đây là bài toán về coding với timeout nên chúng ta có thể lưu các số nguyên tố :math:`t` bit vào file trước khi remote tới server (precompute).
