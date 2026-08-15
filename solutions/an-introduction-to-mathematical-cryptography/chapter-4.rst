Chapter 4. Digital Signatures
=============================

.. admonition:: Câu 4.1
     

    Đáp án: :math:`d = 561517`, :math:`N = 661643`, :math:`sig = 206484`.

.. admonition:: Câu 4.3
     

    Đáp án :math:`p = 212081`, :math:`q=128311` nên

    .. math:: d = 18408628619 \Rightarrow S = D^d \pmod N = 22054770669.

.. admonition:: Câu 4.4
     

    Đáp án: with :math:`c = m^{e_B} \pmod{N_B}` and :math:`s = Hash(m)^{d_A} \pmod{N_A}`

    .. math:: c^{d_B} = m^{e_B\cdot d_B} \pmod{N_B} = m, \ s^{e_A} = Hash(m)^{d_A \cdot e_A} \pmod{N_A} = Hash(m).
        
    Hence this method works.

.. admonition:: Câu 4.5
     

    Đáp án: với :math:`A = g^a \pmod p = 2065`, ta tính

    .. math:: S_1 = g^k \pmod p = 3534, S_2 = (D-a\cdot S_1) k^{-1} \pmod{p-1} = 5888.

    Hence signature is :math:`(S_1, S_2) = (3534, 5888)`

.. admonition:: Câu 4.6
     

    Đáp án: :math:`A^{S_1} \cdot S_1^{S_2} \equiv g^D \pmod p`, so :math:`(S_1^", S_2^")` is valid signature.

.. admonition:: Câu 4.8
     

    Đáp án: :math:`S_1 = S_1' = g^k \pmod p`, from here Eve can know at first glance that the same random element :math:`k` is used
            
    With :math:`S_2 = (D-a S_1) k^{-1} \pmod{p-1}`, :math:`S_2' = (D'-aS_1')k^{-1} \pmod{p-1}`, then

    .. math:: 
        
        S_2 - S_2' \equiv (D - D')k^{-1} \pmod{p-1}` (as :math:`aS_1 = aS_2`)

        k = (D-D')(S_2-S_2')^{-1} \pmod{p-1}.

    Here we get :math:`D - aS_1 = S_2 k \pmod{p-1}`

    .. math:: \Rightarrow \begin{cases} a = (D - S_2 k) S_1{-1} \pmod{p-1} \\ a = (D'-S_2' k) S_1^{-1} \pmod{p-1} \end{cases}.

.. admonition:: Câu 4.9
     

    Đáp án: :math:`p \equiv 1 \pmod q`, :math:`1 \leqslant a \leqslant q-1`, :math:`A=g^a \pmod p`, :math:`S_1 = (g^k \bmod p) \bmod q`, :math:`S_2 = (D + aS_1) k^{-1} \pmod q`

    Verify: :math:`V_1 = D \cdot S_2^{-1} \pmod q`, :math:`V_2 = S_1 S_2^{-1} \pmod q`. We need to prove that :math:`(g^{V_1} \cdot A^{V_2} \bmod p) \bmod q = S_1`

    Here we have

    .. math:: 

        g^{V_1} \cdot A^{V_2} & \equiv g^{D \cdot S_2^{-1}} \cdot g^{aS_1 S_2^{-1}} \pmod p \\ 
        & \equiv g^{(D+aS_1)S_2^{-1}} \pmod p \\ 
        & \equiv g^k \pmod p

    Hence :math:`(g^{V_1} A^{V_2} \bmod p) \bmod q = S_1`.

.. admonition:: Câu 4.10
     

    Đáp án: :math:`(p, q, g) = (22531, 751, 4488)`. Public key :math:`A = 22476` is not valid.


.. admonition:: Câu 4.11
     

    Đáp án: :math:`A = g^a \pmod p`. :math:`A = 31377`, :math:`g = 21947`, :math:`p = 103687`, then
    
    .. math:: a = 602, S_1 = (g^k \bmod p) \bmod q = 439, S_2 = (D + aS_1)k^{-1} \pmod q = 1259.
