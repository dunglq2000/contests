.. _chap_symmetric_cryptography:

Симметричная криптография
*************************

Lời giải cho quyển sách :cite:`Tokareva1` của Н.Н. Токарева.

Глава 3. Булевы функции. Комбинаторный подход
=============================================

.. admonition:: Câu 16
    
   Chứng minh rằng, hàm Boolean :math:`f` tuyến tính khi và chỉ khi :math:`f(\bm{x} \oplus \bm{y}) = f(\bm{x}) \oplus f(\bm{y})` với mọi :math:`\bm{x}`, :math:`\bm{y}`. Tương tự kiểm tra hàm Boolean là affine khi và chỉ khi :math:`f(\bm{x} \oplus \bm{y}) = f(\bm{x}) \oplus f(\bm{y}) \oplus f(\bm{0})`.

.. admonition:: Chứng minh cho hàm tuyến tính
   :class: danger, dropdown

   **Chiều thuận.** Nếu :math:`f` là hàm tuyến tính thì nó có dạng

   .. math:: f(x_1, \ldots, x_n) = a_n x_n \oplus \cdots \oplus a_1 x_1

   nên ta tính :math:`f(\bm{x} \oplus \bm{y})` như sau

   .. math:: 

      f(\bm{x} \oplus \bm{y}) & = a_n (x_n \oplus y_n) \oplus \cdots \oplus a_1 (x_1 \oplus y_1) \\
      & = (a_n x_n \oplus \cdots \oplus a_1 x_1) \oplus (a_n y_n \oplus \cdots \oplus a_1 y_1) \\
      & = f(\bm{x}) \oplus f(\bm{y}).

   **Chiều nghịch.** Với :math:`f(\bm{x} \oplus \bm{y}) = f(\bm{x}) \oplus f(\bm{y})`, đặt dạng ANF của :math:`f` là

   .. math:: f(x_1, \ldots, x_n) = \left(\bigoplus_{k=1}^n \bigoplus_{i_1, \ldots, i_k} a_{i_1, \ldots, i_k} x_{i_1} \cdots x_{i_k}\right) \oplus a_0.

   Khi đó

   .. math:: f(\bm{x} \oplus \bm{y}) = \left(\bigoplus_{k=1}^n \bigoplus_{i_1, \ldots, i_k} a_{i_1, \ldots, i_k} (x_{i_1} \oplus y_{i_1}) \cdots (x_{i_k} \oplus y_{i_k})\right) \oplus a_0,

   và

   .. math:: 
      
      f(\bm{x}) \oplus f(\bm{y}) & = \left(\bigoplus_{k=1}^n \bigoplus_{i_1, \ldots, i_k} a_{i_1, \ldots, i_k} x_{i_1} \cdots x_{i_k}\right) \oplus a_0 \oplus \left(\bigoplus_{k=1}^n \bigoplus_{i_1, \ldots, i_k} a_{i_1, \ldots, i_k} y_{i_1} \cdots y_{i_k}.\right) \oplus a_0 \\
      & = \bigoplus_{k=1}^n \bigoplus_{i_1, \ldots, i_k} a_{i_1, \ldots, i_k} (x_{i_1} \cdots x_{i_k} \oplus y_{i_1} \cdots y_{i_k}).

   Như vậy, khi đồng nhất hệ số :math:`a_{i_1, \ldots, i_k}` của :math:`f(\bm{x} \oplus \bm{y})` và :math:`f(\bm{x}) \oplus f(\bm{y})` thì ta có

   .. math:: (x_{i_1} \oplus y_{i_1}) \cdots (x_{i_k} \oplus y_{i_k}) = x_{i_1} \cdots x_{i_k} \oplus y_{i_1} \cdots y_{i_k}.

   Ở vế trái khi khai triển ra ta sẽ nhận được các đơn thức dạng :math:`x_{i_1} y_{i_2} y_{i_3} \cdots y_{i_k}` khi :math:`k > 1`, tuy nhiên ở vế phải chỉ có đúng hai đơn thức là :math:`x_{i_1} \cdots x_{i_k}` và :math:`y_{i_1} \cdots y_{i_k}`. Do đó các hệ số :math:`a_{i_1, \ldots, i_k}` với :math:`k > 1` phải bằng :math:`0`. Hay nói cách khác bậc của ANF là :math:`1`. Ngoài ra :math:`f(\bm{x} \oplus \bm{y})` có hệ số tự do :math:`a_0` còn :math:`f(\bm{x}) \oplus f(\bm{y})` thì không có nên khi đồng nhất hệ số cũng cho ta :math:`a_0 = 0`. Như vậy :math:`f` là hàm tuyến tính.

.. admonition:: Chứng minh cho hàm affine
   :class: danger, dropdown

   **Chiều thuận.** Nếu :math:`f` là hàm tuyến tính thì nó có dạng

   .. math:: f(x_1, \ldots, x_n) = a_n x_n \oplus \cdots \oplus a_1 x_1 \oplus a_0

   và ta chứng minh tương tự cho trường hợp hàm tuyến tính với lưu ý :math:`f(\bm{0}) = a_0`.

   **Chiều nghịch.** Chứng minh tương tự cho trường hợp hàm tuyến tính.

.. admonition:: Câu 17
    
   Tìm số đỉnh và số cạnh của đồ thị :math:`E^n`. Có bao nhiêu vector :math:`\bm{x}, \bm{y} \in E^n` sao cho :math:`d(\bm{x}, \bm{y}) = k`?

Mỗi đỉnh của :math:`E^n` biểu diễn một vector dạng

.. math:: (z_1, \ldots, z_n), \quad z_i \in \{ 0, 1 \}

nên :math:`E^n` có :math:`2^n` đỉnh. Mỗi đỉnh nối với :math:`n` đỉnh khác (khác nhau chỉ ở vị trí :math:`z_i`) nên :math:`\deg v_i = n` với :math:`i = \overline{1, 2^n}`. Theo bổ đề bắt tay, tổng bậc của các đỉnh bằng hai lần số cạnh, vì thế

.. math:: \text{số cạnh} = \dfrac{1}{2} \sum_{i=1}^{2^n} \deg v_i = \dfrac{1}{2} \cdot n \cdot 2^n = n \cdot 2^{n-1}.

Để :math:`d(\bm{x}, \bm{y}) = k` thì đầu tiên ta chọn :math:`k` vị trí khác nhau với :math:`C_n^k` cách. Với mỗi vị trí khác nhau ta có hai cách chọn :math:`x_i` và :math:`y_i` là

.. math:: \begin{cases} x_i = 1 \\ y_i = 0 \end{cases}, \quad \text{hoặc} \ \begin{cases} x_i = 0 \\ y_i = 1 \end{cases}.

Do đó có :math:`2^k` cách chọn cho các vị trí khác nhau, còn :math:`n - k` vị trí còn lại thì chọn tùy ý nên có :math:`2^{n-k}` cách.

Đáp án là :math:`C_n^k \cdot 2^k \cdot 2^{n-k} = C_n^k \cdot 2^n`.

.. admonition:: Câu 18
    
   Tìm lực lượng của *mặt cầu* :math:`S_r(\bm{x}) = \{ \bm{y} : d(\bm{x}, \bm{y}) = r \}` và *hình cầu* :math:`B_r(\bm{x}) = \{ \bm{y} : d(\bm{x}, \bm{y}) \leqslant r \}`.

Đối với mặt cầu thì đáp án chính là bài 17, nghĩa là :math:`\lvert S_r(\bm{x}) \rvert = 2^r \cdot C_n^r`.

Đối với hình cầu :math:`B_r(\bm{x})` ta xét tất cả giá trị từ :math:`0` tới :math:`r`:

- khi :math:`d(\bm{x}, \bm{y}) = 0` thì có :math:`2^n \cdot C_n^0` cách chọn;
- khi :math:`d(\bm{x}, \bm{y}) = 1` thì có :math:`2^n \cdot C_n^1` cách chọn;
- tương tự, khi :math:`d(\bm{x}, \bm{y}) = i` thì có :math:`2^n \cdot C_n^i` cách chọn;
- cho tới khi :math:`d(\bm{x}, \bm{y}) = r` thì có :math:`2^n \cdot C_n^r` cách chọn.

Như vậy lực lượng của hình cầu là tổng tất cả giá trị trên:

.. math:: \lvert B_r(\bm{x}) \rvert = 2^n \cdot (C_n^0 + C_n^1 + \cdots + C_n^r).

Глава 5. Криптографические свойства булевых функций
===================================================

.. admonition:: [TODO] Câu 31
    
   Chứng minh rằng khoảng cách từ hàm Boolean :math:`f` với :math:`n` biến tới hàm Boolean affine

   .. math:: l_{\bm{a}, b}(\bm{x}) = a_1 x_1 \oplus \ldots \oplus a_n x_n \oplus b
   
   với :math:`\bm{a} = (a_1, \ldots, a_n) \in \mathbb{F}_2^n` và :math:`b \in \mathbb{F}_2` được tính theo công thức:

   .. math::

      d(f, l_{\bm{a}, 0} (\bm{x})) & = 2^{n-1} - \frac{1}{2} W_f(\bm{a}), \\
      d(f, l_{\bm{a}, 1} (\bm{x})) & = 2^{n-1} + \frac{1}{2} W_f (\bm{a}).

.. admonition:: [TODO] Câu 32

   Chứng minh rằng nonlinearity của hàm Boolean :math:`f` bất kì được tính bởi công thức

   .. math:: N_f = 2^{n-1} - \frac{1}{2} \max_{\bm{y}} \lvert W_f (\bm{y}) \rvert.

.. admonition:: Câu 33

   Chứng minh rằng hàm Boolean :math:`f` là hàm bent khi và chỉ khi :math:`W_f(\bm{y}) = \pm 2^{n/2}` với mọi vector :math:`\bm{y}`.

.. admonition:: Câu 34

   Có bao nhiêu hàm Boolean cân bằng :math:`n` biến?

Trong :math:`2^n` vector, ta chọn :math:`2^{n-1}` vector khiến hàm Boolean có giá trị :math:`1` nên đáp án là

.. math:: C_{2^n}^{2^{n-1}}.

.. admonition:: [TODO] Câu 35
   
   Chứng minh rằng hàm Boolean :math:`f` là :math:`r`-resillient khi và chỉ khi nó cân bằng và correlation immune bậc :math:`r`.

.. admonition:: [TODO] Câu 36 (**Định lí Siegenthaler I**, 1984)
   
   Chứng minh rằng nếu hàm Boolean :math:`f` là correlation immune bậc :math:`r` thì :math:`\deg f + r \leqslant n`.

.. admonition:: [TODO] Câu 37 (**Định lí Siegenthaler II**)
   
   Chứng minh rằng nếu hàm Boolean :math:`f` là :math:`r`-resillient và :math:`r \leqslant n - 2` thì :math:`\deg f + r \leqslant n - 1`.

Chứng minh cho các định lí Siegenthaler có thể tìm ở :cite:`Agibalov`.

.. admonition:: Câu 38

   Chứng minh rằng hàm Boolean :math:`f` là correlation immune bậc :math:`r` khi và chỉ khi :math:`W_f(\bm{y}) = 0` với mọi vector :math:`\bm{y}` thỏa :math:`1 \leqslant \mathrm{wt} (\bm{y}) \leqslant r`.

Đầu tiên ta chứng minh bổ đề sau.

.. prf:lemma:: 
   :label: lem-cor-immune-r-1

   Nếu hàm Boolean :math:`f` là correlation immune bậc :math:`r` thì nó cũng là correlation immune với mọi bậc :math:`s`, :math:`1 \leqslant s \leqslant r`.

.. admonition:: Chứng minh bổ đề
   :class: danger, dropdown

   Để chứng minh bổ đề trên ta chỉ cần chứng minh :math:`f` là correlation immune bậc :math:`r - 1` là đủ, từ đó quy nạp xuống tới :math:`1`. Gọi :math:`g` là hàm con bất kì của :math:`f` với :math:`n - r + 1` biến (cố định :math:`r - 1` biến). Khi đó khai triển :math:`g` theo bất kì biến :math:`x_i` nào của nó ta được

   .. math:: g = x_i g_1 \oplus (x_i \oplus 1) g_2,

   trong đó :math:`g_1` và :math:`g_2` là các hàm con :math:`n - r` biến. Vì :math:`f` là correlation immune bậc :math:`r` nên :math:`\operatorname{wt}(g_1) = \operatorname{wt}(g_2) = \operatorname{wt}(f)/2^r`. Do hai hệ số khai triển ứng với :math:`x_i=0` và :math:`x_i=1` có miền xác định rời nhau, trọng số của :math:`g` bằng tổng trọng số của chúng. Vì vậy

   .. math:: \operatorname{wt}(g) = \operatorname{wt}(g_1) + \operatorname{wt}(g_2) = \frac{\operatorname{wt}(f)}{2^{r-1}},

   suy ra :math:`f` là correlation bậc :math:`r - 1`.

Đối với điều kiện cần, Xiao và Massey :cite:`Xiao88` có một chứng minh năm 1988. Ta cần bổ đề sau.

.. prf:lemma:: 
   :label: lem-random-var-sum-1

   Biến ngẫu nhiên rời rạc :math:`Z` độc lập với họ :math:`r` biến ngẫu nhiên nhị phân rời rạc độc lập nhau :math:`Y_1`, :math:`Y_2`, ..., :math:`Y_r` khi và chỉ khi :math:`Z` độc lập với tổng :math:`\lambda_1 Y_1 + \lambda_2 Y_2 + \cdots + \lambda_r Y_r \in \mathbb{F}_2` với mọi :math:`\lambda_1`, :math:`\lambda_2`, ..., :math:`\lambda_r` không đồng thời bằng :math:`0` và thuộc :math:`\mathbb{F}_2`.

.. admonition:: Chứng minh bổ đề
   :class: danger, dropdown

   **Điều kiện đủ.** Giả sử với hai biến ngẫu nhiên độc lập (BNN) :math:`Y_1` và :math:`Y_2`, vì BNN :math:`Z` độc lập với :math:`Y_1` và :math:`Y_2` nên

   .. math:: 
      
      P(Y_1 = 0, Y_2 = 0, Z = 0) + P(Y_1 = 1, Y_2 = 1, Z = 0) & = P(Y_1 = 0) \cdot P(Y_2 = 0) \cdot P(Z = 0) + P(Y_1 = 1) \cdot P(Y_2 = 1) \cdot P(Z = 0) \\ 
      & = \frac{1}{2} \cdot \frac{1}{2} \cdot \frac{1}{2} + \frac{1}{2} \cdot \frac{1}{2} \cdot \frac{1}{2} \\ 
      & = \frac{1}{4} = P(Y_1 + Y_2 = 0) \cdot P(Z = 0) = P(Y_1 + Y_2 = 0, Z = 0).

   Chứng minh tương tự cho :math:`Y_1 + Y_2 = 1` ta có 
   
   .. math:: P(Y_1 + Y_2 = y, Z = z) = P(Y_1 + Y_2 = y) \cdot P(Z = z) \ \text{với mọi} \ y, z \in \mathbb{F}_2,

   như vậy :math:`Z` độc lập với :math:`Y_1 + Y_2`, và vì :math:`Z` đã độc lập với :math:`Y_1` và :math:`Y_2` nên ta có điều phải chứng minh. Sử dụng quy nạp ta dễ dàng chứng minh :math:`Z` độc lập với hệ độc lập :math:`m` BNN bất kì.

   **Điều kiện cần.** BNN rời rạc :math:`Z` độc lập với tổng :math:`\lambda_1 Y_1 + \lambda_2 Y_2 + \cdots + \lambda_r Y_r` với mọi :math:`\lambda_1`, :math:`\lambda_2`, ..., :math:`\lambda_r` không đồng thời bằng :math:`0` và thuộc :math:`\mathbb{F}_2`. Ta sẽ chứng minh :math:`Z` độc lập với hệ độc lập :math:`Y_1`, :math:`Y_2`, ..., :math:`Y_r`.

   Với :math:`m = 1` thì điều này hiển nhiên. Với :math:`m = 2`, vì :math:`Z` độc lập với :math:`Y_1`, :math:`Y_2` và :math:`Y_1 + Y_2` nên ta có phân bố xác suất sau với mọi giá trị :math:`z \in Z`: với mọi :math:`P(Z = z) > 0` ta có

   .. math:: 
      :label: eqs-y1-y2-z-cond

      P((Y_1 = 1, Y_2 = 1) \mid Z = z) & + P((Y_1 = 1, Y_2 = 0) \mid Z = z) \\
         & = P(Y_1 = 1 \mid Z = z) = p_1, \\
      P((Y_1 = 1, Y_2 = 1) \mid Z = z) & + P((Y_1 = 0, Y_2 = 1) \mid Z = z) \\ 
         & = P(Y_2 = 1 \mid Z = z) = p_2, \\
      P((Y_1 = 1, Y_2 = 0) \mid Z = z) & + P((Y_1 = 0, Y_2 = 1) \mid Z = z) \\ 
         & = P((Y_1 + Y_2 = 1) \mid Z = z) \\ 
         & = p_1 (1 - p_2) + (1 - p_1) p_2, \\
      P((Y_1 = 1, Y_2 = 0) \mid Z = z) & + P((Y_1 = 0, Y_2 = 0) \mid Z = z) \\
         & = P(Y_2 = 0 \mid Z = z) = 1 - p_2,

   với :math:`p_1 = P(Y_1 = 1)` và :math:`p_2 = P(Y_2 = 1)`. Cụ thể hơn, ở phương trình đầu tiên, vì :math:`P(Y_1 = 1 \mid Z = z)` không phụ thuộc :math:`Y_2` nên nó là tổng khi :math:`Y_2 = 0` và :math:`Y_2 = 1`. Tương tự cho phương trình thứ hai và thứ tư; phương trình thứ ba là khi tổng :math:`Y_1 + Y_2 = 1`.

   Nếu xem :math:`4` phương trình trên là hệ phương trình với các biến :math:`P((Y_1 = y_1, Y_2 = y_2) \mid Z = z)` thì ta giải ra được

   .. math:: 
      :label: eqs-y1-y2-z-result

      P((Y_1 = 0, Y_2 = 1) \mid Z = z) & = (1 - p_1) p_2 \\
      P((Y_1 = 1, Y_2 = 0) \mid Z = z) & = p_1 (1 - p_2) \\
      P((Y_1 = 0, Y_2 = 0) \mid Z = z) & = (1 - p_1) (1 - p_2) \\ 
      P((Y_1 = 1, Y_2 = 1) \mid Z = z) & = p_1 p_2.

   Vì :math:`P((Y_1 = y_1, Y_2 = y_2) \mid Z) = P(Y_1 = y_1, Y_2 = y_2)` với mọi :math:`y_1, y_2 \in \mathbb{F}_2` nên :math:`Z` độc lập với họ :math:`Y_1`, :math:`Y_2`.

   Giả thiết quy nạp: giả sử điều kiện đúng với mọi :math:`r < R`. Ta chứng minh khi :math:`r = R`.

   Giả sử :math:`Z` độc lập với tổng :math:`\lambda_1 Y_1 + \cdots \lambda_r Y_r` với mọi :math:`\lambda_1`, ..., :math:`\lambda_r` không đồng thời bằng :math:`0`.

   Chọn :math:`\lambda_1 = \lambda_2 = 0`, theo giả thiết quy nạp :math:`Y_3`, ..., :math:`Y_r`, :math:`Z` độc lập.

   Tương tự, chọn :math:`\lambda_1 = 0` thì :math:`Y_2` độc lập với :math:`Y_3`, ..., :math:`Y_r`, :math:`Z`. Nếu chọn :math:`\lambda_1 = \lambda_2` thì :math:`Y_1 + Y_2` độc lập với :math:`Y_3`, ..., :math:`Y_r`, :math:`Z`.

   Như vậy, với mọi cách chọn :math:`y_3`, ..., :math:`y_R`, :math:`z`, các phương trình :eq:`eqs-y1-y2-z-cond` và :eq:`eqs-y1-y2-z-result` giữ nguyên sau khi đổi

   .. math:: P((Y_1 = y_1, Y_2 = y_2) \mid Z = z)

   thành 

   .. math:: P((Y_1 = y_1, Y_2 = y_2) \mid (Y_3 = y_3, \ldots, Y_R = y_R, Z = z)),

   khi đó :eq:`eqs-y1-y2-z-result` được viết lại thành :math:`Y_1`, :math:`Y_2` độc lập với :math:`Y_3`, ..., :math:`Y_m`, :math:`Z`. Như vậy :math:`Y_1`, :math:`Y_2`, ..., :math:`Y_m`, :math:`Z` độc lập.

Ta quay lại chứng minh điều kiện cần và đủ của câu 38.

.. admonition:: Chứng minh điều kiện đủ
   :class: danger, dropdown
   
   Ta chứng minh: nếu :math:`f` là correlation immune bậc :math:`r` thì :math:`W_f(\bm{y}) = 0` với mọi :math:`\bm{y}` thỏa :math:`1 \leqslant \operatorname{wt}(\bm{y}) \leqslant r`.

   Với mọi vector :math:`\bm{y} = (y_1, y_2, \ldots, y_n) \in \mathbb{F}_2^n`, đặt

   .. math:: S = \operatorname{supp}(\bm{y}) = \{ i : y_i = 1 \}.

   Khi đó :math:`\lvert S \rvert = \operatorname{wt}(\bm{y}) = s` với :math:`1 \leqslant s \leqslant r`.
      
   Ta có 

   .. math:: 

      W_f(\bm{y}) & = \sum_{\bm{x} \in \mathbb{F}_2^n} (-1)^{f(\bm{x}) \oplus \langle \bm{x}, \bm{y} \rangle} \\
         & = \sum_{\bm{x} \in \mathbb{F}_2^n} (-1)^{f(\bm{x}) \oplus \sum\limits_{i \in S} x_{i}}.

   Với mọi vector :math:`\bm{a} = (a_i)_{i \in S} \in \mathbb{F}_2^s`, đặt

   .. math:: E_{\bm{a}} = \{ \bm{x} \in \mathbb{F}_2^n : x_i = a_i \ \text{với mọi} \ i \in S \}.

   Vì các vector :math:`\bm{x}` trong :math:`E_{\bm{a}}` được cố định :math:`s` vị trí, còn :math:`n - s` vị trí được chọn tùy ý, nên :math:`\lvert E_{\bm{a}} = 2^{n - s}`. Khi đó

   .. math:: 

      W_f(\bm{y}) & = \sum_{\bm{x} \in \mathbb{F}_2^n} (-1)^{f(\bm{x}) \oplus \sum\limits_{i \in S} x_{i}} \\
         & = \sum_{\bm{a} \in \mathbb{F}_2^s} \sum_{\bm{x} \in E_{\bm{a}}} (-1)^{f(\bm{x}) \oplus \sum\limits_{i \in S} a_i} \\
         & = \sum_{\bm{a} \in \mathbb{F}_2^s} (-1)^{\sum\limits_{i \in S} a_i} \sum_{\bm{x} \in E_{\bm{a}}} (-1)^{f(\bm{x})}.

   Đặt 

   .. math:: 

      N_{\bm{a}} = \lvert \{ \bm{x} \in E_{\bm{a}} : f(\bm{x}) = 1 \} \rvert \Longrightarrow \sum_{\bm{x} \in E_{\bm{a}}} (-1)^{f(\bm{x})} = \lvert E_\bm{a} \rvert - 2 N_{\bm{a}},

   vì :math:`(-1)^0 = 1` và :math:`(-1)^1 = -1`. Hơn nữa :math:`N_{\bm{a}}` là số lượng các vector :math:`\bm{x} \in \mathbb{F}_2^n` mà được cố định :math:`s` biến, và khiến :math:`f(\bm{x}) = 1`, nói cách khác là correlation immune bậc :math:`s`. Do đó ta có

   .. math:: N_{\bm{a}} = \frac{\operatorname{wt}(f)}{2^s} \Longrightarrow \sum_{\bm{x} \in E_{\bm{a}}} (-1)^{f(\bm{x})} = 2^{n-s} - 2 \cdot \frac{\operatorname{wt}(f)}{2^s} = 2^{n-s} - \frac{\operatorname{wt}(f)}{2^{s-1}}.

   Đại lượng trên không phụ thuộc vào :math:`a`, ta gọi là :math:`C`. Khi đó

   .. math:: W_f(\bm{y}) = \sum_{\bm{a} \in \mathbb{F}_2^s} (-1)^{\sum\limits_{i \in S} a_i} \cdot C = C \cdot \sum_{\bm{a} \in \mathbb{F}_2^s} (-1)^{\sum\limits_{i \in S} a_i}.

   Sử dụng tính trực giao của các kí tự trên :math:`\mathbb{F}_2^s`: với vector :math:`\bm{z}` cố định thì

   .. math:: \sum_{\bm{a} \in \mathbb{F}_2^s} (-1)^{\langle \bm{a}, \bm{z} \rangle} = \begin{cases} 0, & \quad \text{nếu} \ \bm{z} \neq \bm{0} \\ 2^s, & \quad \text{nếu} \ \bm{z} = \bm{0}. \end{cases}

   Trong trường hợp của chúng ta là :math:`\bm{z} = (1, 1, \ldots, 1) \in \mathbb{F}_2^s` nên 

   .. math:: \sum_{\bm{a} \in \mathbb{F}_2^s} (-1)^{\sum\limits_{i \in S} a_i} = 0 \Longrightarrow W_f(\bm{y}) = 0.

.. admonition:: Chứng minh điều kiện cần (Xiao, Massey)
   :class: danger, dropdown

   Đặt

   .. math:: 

      N_{f, 0}(\bm{a}) = \lvert \{ \bm{x} \in \mathbb{F}_2^n : f(\bm{x}) = 1, \langle \bm{a}, \bm{x} \rangle = 0 \} \rvert \\ 
      N_{f, 1}(\bm{a}) = \lvert \{ \bm{x} \in \mathbb{F}_2^n : f(\bm{x}) = 1, \langle \bm{a}, \bm{x} \rangle = 1 \} \rvert

   Tính chất của biến đổi Walsh-Hadamard cho ta đẳng thức

   .. math:: F(\bm{a}) = N_{f, 0}(\bm{a}) - N_{f, 1}(\bm{a}), \quad \bm{a} \in \mathbb{F}_2^n.

   Đặt :math:`\bm{w} \in \mathbb{F}_2^n` và :math:`\bm{X}` là :math:`n` BNN :math:`X_1`, :math:`X_2`, ..., :math:`X_n`. Khi đó với mọi :math:`\bm{w} \neq \bm{0}` thì 

   .. math:: \langle \bm{w}, \bm{X} \rangle = w_1 X_1 + w_2 X_2 + \cdots + w_n X_n

   là tổng gồm :math:`\operatorname{wt}(\bm{w})` BNN trong số :math:`X_1`, :math:`X_2`, ..., :math:`X_n`.

   Vì tất cả :math:`2^{n-1}` giá trị :math:`\bm{x}` của :math:`\bm{X}` mà :math:`\langle \bm{x}, \bm{w} \rangle = b` bằng nhau, ta có

   .. math:: 
      :label: eq-z-to-nfb

      P(Z = 1, \langle \bm{w}, \bm{X} \rangle = b) = 2^{-n+1} N_{f, b}(\bm{w}), \ \text{với} \ \bm{w} \neq \bm{0}

   với :math:`b \in \{ 0, 1 \}`.

   Quay lại bài toán, ta chứng minh nếu :math:`W_f(\bm{y}) = 0` với mọi :math:`\bm{y}` thỏa mãn :math:`1 \leqslant \operatorname{wt}(\bm{y}) \leqslant r` thì hàm Boolean :math:`f(\bm{x})` là correlation immune bậc :math:`r`.

   Theo định nghĩa, vì :math:`f` là correlation immune bậc :math:`r` nên :math:`Z` độc lập với mọi tập con có :math:`r` phần tử hoặc ít hơn trong các BNN :math:`X_1`, :math:`X_2`, ..., :math:`X_n`. Khi đó, từ bổ đề trên, điều cần chứng minh tương đương với :math:`f` là correlation immune bậc :math:`r` khi và chỉ khi :math:`Z` độc lập với mọi BNN :math:`\langle \bm{w}, \bm{X} \rangle` với :math:`1 \leqslant \wt(\bm{w}) \leqslant r`. Từ :eq:`eq-z-to-nfb`, :math:`Z` độc lập với :math:`\langle \bm{w}, \bm{X} \rangle` khi và chỉ khi :math:`N_{f, 0}(\bm{w}) = N_{f, 1}(\bm{w})` với :math:`1 \leqslant \wt(\bm{w}) \leqslant r`. Như vậy :math:`W_f(\bm{w}) = 0` với :math:`1 \leqslant \wt(\bm{w}) \leqslant r`. Ta có điều phải chứng minh.

Năm 2007 Д. Г. Фон–Дер–Флаасс tìm được chặn trên cho correlation immune của hàm Boolean không cân bằng.

.. admonition:: [TODO] Câu 39 (**Định lí Д. Г. Фон–Дер–Флаасс**, :cite:`Flaass`)
   
   Gọi :math:`f` là hàm Boolean không cân bằng có correlation immune bậc :math:`r` khác :math:`0`. Chứng minh rằng :math:`r \leqslant (2n/3) - 1`.

.. admonition:: [TODO] Câu 40
   
   Chứng minh rằng với hàm Boolean :math:`r`-resillient :math:`f` sao cho :math:`r \leqslant n-2` thì ta có bất đẳng thức :math:`N_f \leqslant 2^{n-1} - 2^{r+1}` :cite:`Cusick`.

.. admonition:: [TODO] Câu 41 (Chặn của algebraic immune) 
   
   Chứng minh rằng algebraic immune của hàm Boolean :math:`f` bất kì với :math:`n` biến không vượt quá giá trị :math:`\lceil n/2 \rceil`.

.. admonition:: [TODO] Câu 42
   
   Chứng minh một số tính chất cơ bản của algebraic immune với mọi hàm Boolean :math:`f`, :math:`g` trên :math:`n` biến:
   
   - :math:`\mathsf{AI}(f) \leqslant \deg f`;
   - :math:`\mathsf{AI}(f \cdot g) \leqslant \mathsf{AI}(f) + \mathsf{AI}(g)`;
   - :math:`\mathsf{AI}(f \oplus g) \leqslant \mathsf{AI}(f) + \mathsf{AI}(g)`;
   - :math:`\mathsf{AI}(f) = \mathsf{AI}(g)` nếu :math:`g` nhận được từ :math:`f` qua một biến đổi affine trên các biến, nghĩa là :math:`g(\bm{x}) = f(\bm{A} \bm{x} \oplus \bm{b})` với :math:`\bm{A}` là ma trận khả nghịch bậc :math:`n` và :math:`\bm{b}` là vector.
 
.. admonition:: [TODO] Câu 43
   
   Xác định giá trị của :math:`\mathsf{AI}(f)` với các hàm Boolean sau và tìm hàm :math:`g` tương ứng:
    
   - :math:`f(\bm{x}) = x_1 x_2 x_4 \oplus x_1 x_2 \oplus 1`;
   - :math:`f(\bm{x}) = 0`;
   - :math:`f(\bm{x}) = 1`;
   - :math:`f(\bm{x}) = x_1 \cdots x_k` với :math:`k = 1, 2, \ldots, n`;
   - :math:`f(\bm{x}) = x_1 \oplus \ldots \oplus x_n`;
   - :math:`f(\bm{x}) = x_1 x_2 \oplus \ldots \oplus x_{n-1} x_n` (tổng tất cả cặp tích);
   - :math:`f(\bm{x}) = x_1 x_2 x_3 x_4 \oplus x_5 x_6`.

.. admonition:: [TODO] Câu 44
   
   Cho ví dụ hàm Boolean :math:`f` với giá trị algebraic immune nhỏ nhất, nghĩa là :math:`\mathsf{AI}(f) = d` với :math:`d = 1, 2, \ldots, k`.

.. admonition:: Câu 45

   Chứng minh hàm :math:`S : \mathbb{F}_2^8 \to \mathbb{F}_2^8` của S-box trong thuật toán AES là differentially :math:`4`-uniform.

Bài tập này cho thấy rằng S-box tốt thì :math:`\delta` sẽ nhỏ nhất có thể nhằm kháng phá mã vi sai, và có thể dễ dàng chứng minh kết quả là :math:`4` bằng việc vét cạn số nghiệm của phương trình :math:`S(\bm{x} + \bm{a}) \oplus S(\bm{x}) = \bm{b}` với mọi :math:`\bm{a} \in \mathbb{F}_2^8` khác không và với mọi :math:`\bm{b} \in \mathbb{F}_2^8`.
