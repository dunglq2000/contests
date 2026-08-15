Chapter 3. Integer Factorization and RSA
========================================

.. admonition:: Câu 3.4
     

    *Euler's phi function* :math:`\phi(N)` is the function defined by

    .. math:: \phi(N) = \lvert \{ 0 \leqslant k < N: \gcd(k, N)=1\} \rvert.

Chứng minh định lý Euler đã có trong bài viết về hàm Euler.

.. admonition:: Câu 3.5
     

    Properties of Euler's phi function

    If :math:`p` and :math:`q` are distinct primes, how is :math:`\phi(pq)` related to :math:`\phi(p)` and :math:`\phi(q)`?


Chứng minh tính chất nhân tính của hàm Euler đã có ở bài viết về hàm Euler.

.. admonition:: Câu 3.6
     

    Let :math:`N`, :math:`c`, and :math:`e` be positive integers satisfying the conditions :math:`\gcd(N,c)=1` and :math:`\gcd(e,\phi(N))=1`.

    Explain how to solve the congruence :math:`x^e \equiv c \pmod{N}` assuming that you know the value of :math:`\phi(N)`

Vì :math:`\gcd(e, \phi(N)) = 1`, ta có thể tìm số :math:`d \in \mathbb{Z}` sao cho :math:`ed \equiv 1 \pmod{\phi(N)}` với thuật toán Euclid mở rộng.

Khi đó :math:`ed = k\phi(N) + 1` với :math:`k \in \mathbb{Z}`.

Vì :math:`\gcd(N, c)=1` nên :math:`\gcd(N,x)=1`, hay

.. math:: c^d = \left(x^e\right)^d = x^{ed} = x^{k\phi(N) + 1} = (x^k)^{\phi(N)} x,

và ta đã biết :math:`(x^k)^{\phi(N)} \equiv 1 \pmod{N}` từ Câu 3.4.

Như vậy :math:`c^d \equiv x \pmod{N}`.

.. admonition:: Câu 3.11
     

    Alice chooses two large primes :math:`p` and :math:`q` and she publishes :math:`N=pq`. It is assumed that :math:`N` is hard to factor. Alice also chooses three random numbers :math:`g`, :math:`r_1`, and :math:`r_2` modulo :math:`N` and computes

    .. math:: g_1 \equiv g^{r_1(p-1)} \pmod{N} \qquad \text{and} \qquad g_2 \equiv g^{r_2(q-1)} \pmod{N}

    Her public key is the triple :math:`(N, g_1, g_2)` and her private key is the pair of primes :math:`(p, q)`.

    Now Bob wants to send the message :math:`m` to Alice, where :math:`m` is a number modulo :math:`N`. He chooses two random integers :math:`s_1` and :math:`s_2` modulo :math:`N` and computes

    .. math:: c_1 \equiv mg_1^{s_1} \pmod{N} \qquad \text{and} \qquad c_2 \equiv mg_2^{s_2} \pmod{N}

    Bob sends the ciphertext :math:`(c_1, c_2)` to Alice.

    Decryption is extreamly fast and essy. Alice uses the Chinese remainder theorem to solve the pair of congruences

    .. math:: x \equiv c_2 \pmod{p} \qquad \text{and} \qquad x \equiv c_2 \pmod{q}
        
    Prove that Alice's solution :math:`x` is equal to Bob's plaintext :math:`m`.

Ta có

.. math:: c_1 \equiv mg_1^{s_1} \pmod{N} \equiv mg_1^{s_1} \pmod{p} \equiv m \pmod{p}

do :math:`g_1^{s_1} = (g_1^{s_1 r_1})^{(p-1)} \equiv 1 \pmod{p}`.

Tương tự ta có :math:`c_2 \equiv m \pmod{q}`.

Nghiệm của hệ đồng dư là

.. math:: x \equiv c_1 q q' + c_2 p p' \pmod N

với :math:`p p' + q q' = 1`.

.. math:: \Rightarrow x \equiv m p p' + m q q' \equiv m(p p' + q q') \equiv m \pmod N
        
Ta có

.. math:: g_1 \equiv g^{r_1 (p-1)} \pmod N \equiv g^{r_1 (p-1)} \pmod p \equiv 1 \pmod p.

Suy ra :math:`p = \gcd(g_1-1, N)`. Tương tự, :math:`q = \gcd(g_2-1, N)`.

Như vậy ta đã khôi phục lại private key.

.. admonition:: Câu 3.13
     

    Find :math:`x`, :math:`y` such that :math:`x e_1 + y e_2 = 1 = \gcd(e_1,e_2)`.

.. math:: \Rightarrow m = c_1^x c_2^y = m^{e_1 x + e_2 y} = m \pmod{N}

.. admonition:: Câu 3.14.
     

    [Exercise]

Because 3, 11 and 17 are primes number, :math:`a \equiv a^3 \pmod 3`, :math:`a \equiv a^{11} \pmod{11}`, :math:`a \equiv a^{17} \pmod{17}`. We have system congruence

.. math:: 

    a & \equiv a^3 \pmod 3 \\ a & \equiv a^{11} \pmod{11} \\ a & \equiv a^{17} \pmod{17}

Consider that :math:`a^3 \equiv a \pmod 3`, :math:`a^{3^2} \equiv a^3 \equiv a \pmod 3`, :math:`\cdots`, :math:`a^{3^i} \equiv a \pmod 3`. And :math:`561 = 2 \cdot 3^5 + 2 \cdot 3^3 + 2 \cdot 3^2 + 3^1`, :math:`a^{561} \equiv a^2 \cdot a^2 \cdot a^2 \cdot a \equiv a^9 \equiv a \pmod 3`.

Similarly, :math:`a^{561} \equiv a \pmod{11}`, :math:`a^{561} \equiv a \pmod{17}`. From system congruence:

.. math:: 

    a^{561} & \equiv a \pmod 3 \\ a^{561} & \equiv a \pmod{11} \\ a^{561} & \equiv a \pmod{17}

Using CRT, :math:`a^{561} = (187 \cdot 1 \cdot a + 51 \cdot 8 \cdot a + 33 \cdot 16 \cdot a) \pmod{561} = a \pmod{561}`

Suppose that :math:`n` is even (:math:`n \geqslant 4`), we have 

.. math:: (n-1)^{n-1} = (-1)^{n-1} = -1 \pmod n,

but :math:`a^{n-1} \equiv 1 \pmod n` for all :math:`a`, which is contrary. So :math:`n` must be odd.

Suppose that :math:`n = p_1^{e_1} p_2^{e_2} \cdots p_r^{e_r}` (:math:`p_i` is odd prime). Because :math:`a^{p^{e-1} (p-1)} \equiv 1 \pmod{p^e}` and :math:`a^{n-1} \equiv 1 \pmod n`, we have :math:`a^{n-1} \equiv 1 \pmod{p^e}`.

:math:`\Rightarrow p^{e-1}(p-1) \mid (n-1) \Rightarrow p^{e-1} \mid (n-1)`, but :math:`p^{e-1} \mid n`, which is contrary if :math:`e \geqslant 2`. Hence :math:`e` must be 1.

Therefore :math:`n = p_1 p_2 \cdots p_r` 

.. admonition:: Câu 3.37
     

    [EXERCISE]

.. math:: 
    
    \left(a^{\frac{p-1}{2}}\right)^2 \equiv a^{p-1} \equiv 1 \pmod p

    \Rightarrow \binom{a}{p} = \pm 1

    \Rightarrow \left(a^{\frac{p-1}{2}} - 1\right)\left(a^{\frac{p-1}{2}} + 1\right) \equiv 0 \pmod p

    \Rightarrow a^{\frac{p-1}{2}} \equiv \pm 1 \pmod p.
    
If :math:`a` is quadratic residue, then :math:`a \equiv b^2 \pmod p` 

:math:`\Rightarrow a^{\frac{p-1}{2}} \equiv (b^2)^{\frac{p-1}{2}} = b^{p-1} \equiv 1 \pmod p`

If :math:`a^{\frac{p-1}{2}} \equiv 1 \pmod p`

Let :math:`g` be generator modulo :math:`p`, then :math:`a \equiv g^m \pmod p`

If :math:`m` is even :math:`\Rightarrow a \equiv g^{2k} \pmod p \Rightarrow a^{\frac{p-1}{2}} \equiv 1 \pmod p`

If :math:`m` is odd :math:`\Rightarrow a = g^{2k+1} \pmod p \Rightarrow a^{\frac{p-1}{2}} \equiv g^{(2k+1)\frac{p-1}{2}} \equiv g^{p-1} g^{\frac{p-1}{2}} \equiv g^{\frac{p-1}{2}}\not\equiv 1 \pmod p`, because :math:`p-1` is smallest number that :math:`g^{p-1} \equiv 1 \pmod p`

From (a) and (b) :math:`\binom{-1}{p} \equiv (-1)^{\frac{p-1}{2}} \pmod p`, if :math:`p=4k+1 \Rightarrow (-1)^{\frac{p-1}{2}} \equiv (-1)^{2k} \equiv 1 \pmod p` \\ If :math:`p=4k+3 \Rightarrow (-1)^{\frac{p-1}{2}} \equiv (-1)^{2k+1} \equiv -1 \pmod p` 

.. admonition:: Câu 3.38
     

    Prove that the three parts of the quadratic reciprocity theorem are equivalent to the following three concise formulas, where :math:`p` and :math:`q` are odd primes.

    :math:`\left(\frac{-1}{p}\right) = (-1)^{\frac{p-1}{2}}`.

    With :math:`p \equiv 1 \pmod 4 \Rightarrow \left(\frac{-1}{p}\right) = 1 = (-1)^{\frac{p-1}{2}} \pmod p`.

    Similarly with :math:`p \equiv 3 \pmod 4` :math:`\left(\frac{2}{p}\right) = (-1)^{\frac{p^2-1}{8}}`.

First we need a lemma (**Gauss lemma**): suppose :math:`p` is an odd prime, and :math:`a \in \mathbb{Z}`, :math:`\gcd(a, p) = 1`. Consider the set

.. math:: a, 2a, 3a, \cdots, \frac{p-1}{2} a.

If :math:`s` of those residues are greater than :math:`\frac{p}{2}`, then :math:`\binom{a}{p} = (-1)^s`

.. admonition:: Proof of lemma
    :class: danger, dropdown

    Among smallest residues of :math:`a`, :math:`2a`, :math:`3a`, 
    ..., :math:`\dfrac{p-1}{2}a`, suppose that :math:`u_1`, :math:`u_2`, 
    ..., :math:`u_s` are residues greater than :math:`\dfrac{p}{2}`, and 
    :math:`v_1`, :math:`v_2`, ..., :math:`v_t` are residues smaller than 
    :math:`\frac{p}{2}`.

    Because :math:`\gcd(ja, p) = 1` for all :math:`j`, where 
    :math:`1 \leqslant j \leqslant \dfrac{p-1}{2}`, all 
    :math:`u_i, v_j \neq 0`, then
    
    .. math:: u_i, v_j \in \{1 , 2,\cdots,p-1\}.
        
    We will prove that, the set 
    
    .. math:: \{p-u_1, p-u_2, \cdots, p-u_s, v_1, v_2, \cdots, v_t\}
    
    is a permutation of :math:`\{1,2,\cdots,\frac{p-1}{2}\}`

    It is clear that there are no :math:`2` numbers :math:`u_i` or :math:`2` 
    numbers :math:`v_j` simultaneously congruent modulo :math:`p`. Because 
    if :math:`ma \equiv na \pmod p` and :math:`\gcd(a, p) = 1`, then 
    :math:`m\equiv n \pmod p` and it is contrast with :math:`m, n \leqslant \dfrac{p-1}{2}`.

    Similarly, we see that there are no numbers :math:`p-u_i` congruent with :math:`v_j`, so

    .. math:: (p-u_1)(p-u_2)\cdots(p-u_s)v_1 v_2 \cdots v_t \equiv \left(\frac{p-1}{2}\right)! \pmod p.

    On the other hand, :math:`u_1`, :math:`u_2`, ..., :math:`u_s`, :math:`v_1`, 
    :math:`v_2`, ..., :math:`v_t` are smallest residues of :math:`a`, :math:`2a`, 
    :math:`3a`, ..., :math:`\dfrac{p-1}{2}`, so 
    
    .. math:: u_1 u_2 \cdots u_s v_1 v_2 \cdots v_t \equiv a^{\frac{p-1}{2}} \left(\frac{p-1}{2}\right)! \pmod p.

    Therefore
    
    .. math:: (-1)^s a^{\frac{p-1}{2}} \left(\frac{p-1}{2}\right)! \equiv \left(\frac{p-1}{2}\right)! \pmod p

    And because 
    
    .. math:: \gcd(p, \left(\frac{p-1}{2}\right)!) = 1 \Rightarrow (-1)^s a^{\frac{p-1}{2}} \equiv 1 \pmod p,

    then

    .. math:: 
        
        a^{\frac{p-1}{2}} \equiv (-1)^s \pmod p, \ \binom{a}{p} = a^{\frac{p-1}{2}},

    and :math:`\binom{a}{p} = (-1)^s \pmod p`.

Return to problem: using theorem above, we need to find the number of residues, which are greater than :math:`\frac{p}{2}` among :math:`1 \cdot 2`, :math:`2 \cdot 2`, :math:`\cdots`, :math:`\frac{p-1}{2} \cdot 2`. Therefore we only need to know which numbers are greater than :math:`\frac{p}{2}`

:math:`\Rightarrow` there are :math:`s = \frac{p-1}{2} - \left[\frac{p}{4}\right] \Rightarrow \left(\frac{2}{p}\right) = (-1)^{\frac{p-1}{2} - \left[\frac{p}{4}\right] }`

With :math:`p \equiv 1, 3, 5, 7 \pmod 8`, we have 

.. math:: 
    
    \frac{p-1}{2} - \left[\frac{p}{4}\right] \equiv \frac{p^2-1}{8} \pmod 2

    \Rightarrow \left(\frac{2}{p}\right) = (-1)^{\frac{p^2-1}{8}}

.. math:: \left(\frac{p}{q}\right)\left(\frac{q}{p}\right) = (-1)^{\frac{p-1}{2} \cdot \frac{q-1}{2}}

We need a lemma: Suppose :math:`p` is an odd prime, :math:`a` is odd and :math:`\gcd(a, p) = 1`, then :math:`\left(\frac{a}{p}\right) = (-1)^{T(a, p)}`, with 

.. math:: T(a, p) = \sum_{j=1}^{\frac{p-1}{2}}\left[\frac{ja}{p}\right].

.. admonition:: Proof of lemma
    :class: danger, dropdown
    
    Consider smallest residues of :math:`a`, :math:`2a`, :math:`3a`, :math:`\cdots`, :math:`\frac{p-1}{2} \cdot a`. As Gauss's lemma, :math:`u_1`, :math:`u_2`, :math:`\cdots`, :math:`u_s`, :math:`v_1`, :math:`v_2`, :math:`\cdots`, :math:`v_t` are residues greater and less than :math:`\frac{p}{2}` respectively. According to Euclidean divisor:

    .. math:: ja = p \left[\frac{ja}{p}\right] + \text{remainder},
        
    remainder is :math:`u_i` or :math:`v_j`. We have such :math:`\frac{p-1}{2}` equations and add them together

    .. math:: \Rightarrow \sum_{j=1}^{\frac{p-1}{2}}ja = \sum_{j=1}^{\frac{p-1}{2}}p\left[\frac{ja}{p}\right] + \sum_{i=1}^{s}u_i + \sum_{j=1}^{t}v_j

    As we pointed out in Gauss's lemma, the set :math:`p-u_1`, :math:`p-u_2`, :math:`\cdots`, :math:`p-u_s`, :math:`v_1`, :math:`v_2`, :math:`\cdots`, :math:`v_t` is a permutation of the set 1, 2, :math:`\cdots`, :math:`\frac{p-1}{2}`

    .. math:: \sum_{j=1}^{\frac{p-1}{2}}j = \sum_{i=1}^{s}(p-u_i) + \sum_{j=1}^{t}v_t = ps - \sum_{i=1}^{s}u_i + \sum_{j=1}^{t}v_t

    .. math:: \Rightarrow \sum_{j=1}^{\frac{p-1}{2}}ja - \sum_{j=1}^{\frac{p-1}{2}}j = \sum_{j=1}^{\frac{p-1}{2}}p\left[\frac{ja}{p}\right] - ps + 2\sum_{i=1}^{s}u_i

    From formula of :math:`T(a, p)`, :math:`(a-1)\sum_{j=1}^{\frac{p-1}{2}}j = pT(a, p) - ps + 2 \sum_{i=1}^{s}u_i`

    Because :math:`a`, :math:`p` are odd, :math:`T(a, p) \equiv s \pmod 2`. From Gauss's lemma we finish.

Return to problem: Consider pairs :math:`(x, y)`, where :math:`1 \leqslant x \leqslant \frac{p-1}{2}` and :math:`1 \leqslant y \leqslant \frac{q-1}{2}`, there are :math:`\frac{p-1}{2}\cdot\frac{q-1}{2}` pairs. We divide those pairs into 2 groups, depending on the magnitude of :math:`px` and :math:`qy`.

Because :math:`p`, :math:`q` are two different primes, :math:`px \neq qy`, :math:`\forall (x, y)`.

We consider pairs with :math:`qx > py`. With every fixed element of :math:`x` (:math:`1 \leqslant x \leqslant \frac{p-1}{2}`), exist :math:`\left[\frac{qx}{p}\right]` elements :math:`y` satisfying :math:`1 \leqslant y \leqslant \frac{qx}{p}`. Therefore, there are :math:`\sum_{i=1}^{\frac{p-1}{2}}\left[\frac{iq}{p}\right]` pairs. When :math:`qx < py`, similarly, there are :math:`\sum_{j=1}^{\frac{q-1}{2}}\left[\frac{jp}{q}\right]` pairs. Because there are :math:`\frac{p-1}{2} \cdot \frac{q-1}{2}` pairs, we have equation

.. math:: \sum_{i=1}^{\frac{p-1}{2}}\left[\frac{iq}{p}\right] + \sum_{j=1}^{\frac{q-1}{2}}\left[\frac{jp}{q}\right] = \frac{p-1}{2} \cdot \frac{q-1}{2}

From definition of :math:`T(p, q)`, we have result

.. math:: (-1)^{T(p, q) + T(q, p)} = (-1)^{\frac{p-1}{2} \cdot \frac{q-1}{2}} 

.. admonition:: Câu 3.39
     

    Let :math:`p` be a prime satisfying :math:`p \equiv 3 \pmod 4`.

    Let :math:`a` be a quadratic residue modulo :math:`p`. Prove that the number

    .. math:: b \equiv a^{\frac{p+1}{4}} \pmod p

    has the property that :math:`b^2 \equiv a \pmod p`. (*Hint.* Write :math:`\dfrac{p+1}{2}` as :math:`1+\dfrac{p-1}{2}` and use Exercise 3.37.) This gives an easy way to take square roots modulo :math:`p` for primes that are congruent to 3 modulo 4.

Dùng Câu 3.37, :math:`a^{\frac{p-1}{2}} \equiv 1 \pmod p` vì :math:`a` là thặng dư chính phương modulo :math:`p`.

Khi đó

.. math:: b^2 \equiv a^{\frac{p+1}{2}} \equiv a^{1+\frac{p-1}{2}} \equiv a \cdot a^{\frac{p-1}{2}} \equiv a \cdot 1 \equiv 1 \pmod p

.. admonition:: Câu 3.40
     

    Let :math:`p` be and odd prime, let :math:`g \in \mathbb{F}^{*}_p` be a primitive root, and let :math:`h \in \mathbb{F}^{*}_p`. Write :math:`p - 1 = 2^sm` with :math:`m` odd and :math:`s \geqslant 1`, and write the binary expansion of :math:`\log_g(h)` as

    .. math:: log_g(h) = \varepsilon_0 + 2\varepsilon_1 + 4\varepsilon_2 + 8\varepsilon_3 + \cdots \quad \text{with} \quad \varepsilon_0, \varepsilon_1, \cdots \in \{0, 1\}

    Give an algorithm that generalizes Example 3.69 and allows you to rapidly compute :math:`\varepsilon_0, \varepsilon_1, \cdots, \varepsilon_{s-1}`, thereby proving that the first :math:`s` bits of the discrete logarithm are insecure.

.. prf:algorithm:: Thuật toán tìm :math:`s` least significant bit (LSB) của :math:`x` trong :math:`g^x \equiv h \pmod p`
    :label: hoff-algo-3-40

    **Input:** :math:`g`, :math:`h`, :math:`p` (:math:`p-1=2^s m`)

    **Output:** :math:`s` least significant bits của :math:`x` trong :math:`g^x \equiv h \pmod p`

    1. Ta sẽ tìm mảng :math:`\varepsilon_0, \varepsilon_1, \cdots, \varepsilon_{s-1}`
    2. For :math:`i = 0, \ldots, s-1`
        
       1. If :math:`h` là thặng dư chính phương
        
          1. :math:`\varepsilon_i = 0`, :math:`h = \sqrt{h} \pmod p`
        
       2. ElseIf :math:`\varepsilon_i = 1`
        
          1. :math:`h = \sqrt{g^{-1}h} \pmod p`
        
       3. EndIf

    3. EndFor

.. admonition:: Câu 3.41
     

    Let :math:`p` be a prime satisfying :math:`p \equiv 1 \pmod 3`. We say that :math:`a` is a *cubic residue modulo :math:`p`* if :math:`p \nmid a` and there is an integer :math:`c` satisfying :math:`a \equiv c^3 \pmod p`.

    (a) Let :math:`a` and :math:`b` be cubic residues modulo :math:`p`. Prove that :math:`ab` is a cubic residue modulo :math:`p`.

    (b) Give an example to show that (unlike the case with quadratic residues) it is possible for none of :math:`a`, :math:`b` and :math:`ab` to the a cubic residue modulo :math:`p`

    (c) Let :math:`g` be a primitive root modulo :math:`p`. Prove that :math:`a` is a cubic residue modulo :math:`p` if and only if :math:`3 \mid \log_g(a)`, where :math:`\log_g(a)` is the discrete logarithm of :math:`a` to the base :math:`g`.

    (d) Suppose instead that :math:`p \equiv 2 \pmod 3`. Prove that for every integer :math:`a` there is an integerr :math:`c` satisfying :math:`a \equiv c^3 \pmod p`. In other words, if :math:`p \equiv 2 \pmod 3`, show that every number is a cube modulo :math:`p`.

(a) Ta có :math:`a \equiv x^3 \pmod p` và :math:`y \equiv y^3 \pmod p` với :math:`x` và :math:`y` nào đó thuộc :math:`\mathbb{F}_p`.

Suy ra :math:`ab \equiv x^3 y^3 = (xy)^3 \pmod p` cũng là thặng dư bậc ba.

(b) Gọi :math:`g` là primitive root modulo :math:`p`.

Ta chọn :math:`a \equiv g^{3k+1} \pmod p` và :math:`b \equiv g^{3k'+1} \pmod p`.

Khi đó :math:`ab \equiv g^{(3k+1)+(3k'+1)} \equiv g^{3(k+k')+2} \pmod p` không phải thặng dư bậc ba.

(c) Quên làm.

**Điều kiện đủ**. Nếu :math:`a` là thặng dư bậc ba modulo :math:`p`, giả sử :math:`a \equiv c^3 \pmod 3` và :math:`c \equiv g^u = \pmod p`.

Khi đó :math:`a = g^{3u} \pmod p` và theo định lý Lagrange thì :math:`3 \mid \log_g(a)`.

**Điều kiện cần.** Nếu :math:`3 \mid \log_g(a)` thì làm ngược lại bước chứng minh điều kiện đủ.

(d) Vì :math:`p \equiv 2 \pmod 3` nên :math:`\gcd(p-1, 3) = 1`. Khi đó tồn tại phần tử :math:`d` là nghịch đảo của :math:`3` modulo :math:`p-1`.

Suy ra phương trình :math:`x^3 \equiv a \pmod p` có nghiệm :math:`a^d = x \pmod p`.

Nói cách khác mọi phần tử đều là số bậc ba modulo :math:`p`.
