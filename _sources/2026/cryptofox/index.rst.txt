CryptoFox
*********

+-----------+-----------------------------------------------------------------------+
| № задачи  | Название задачи                                                       |
+===========+=======================================================================+
|  1        | Матрешка (специальный приз «Вычислительные решения»)                  |
+-----------+-----------------------------------------------------------------------+
|  2        | Смарт-контракта для EVM (специальный приз «Вычислительные решения»)   |
+-----------+-----------------------------------------------------------------------+
|  3        | Усложнение линейной рекурренты                                        |
+-----------+-----------------------------------------------------------------------+
|  4        | Решетка с дополнительной структурой                                   |
+-----------+-----------------------------------------------------------------------+
|  5        | Масленица, блинчики и троян-вымогатель (специальный приз Dr Web)      |
+-----------+-----------------------------------------------------------------------+
|  6        | Запутанный белый ящик (специальный приз РеКрипт)                      |
+-----------+-----------------------------------------------------------------------+
|  7        | Внеклассное чтение: Прогрев журналов событий Windows (специальный     |
+-----------+-----------------------------------------------------------------------+
|           | приз «Positive Technologies»)                                         |
+-----------+-----------------------------------------------------------------------+
|  8        | Алгоритм шифрования Незнайки                                          |
+-----------+-----------------------------------------------------------------------+
|  9        | Доверенные токены                                                     |
+-----------+-----------------------------------------------------------------------+
| 10        | Схема цифровой подписи семейства Эль-Гамаля                           |
+-----------+-----------------------------------------------------------------------+
| 11        | Орбиты VULPIS                                                         |
+-----------+-----------------------------------------------------------------------+

01
==

Đề bài
------

Старый мастер-кукольник славился своими матрёшками. Каждая кукла скрывала внутри себя другую, поменьше, а та --- ещё одну. Говорят, в самой маленькой он прятал записку с секретом.

Однажды мастер решил идти в ногу со временем и вырезал свою матрёшку не из липы, а из байтов. Внутри --- слой за слоем, загадка за загадкой. Тот, кто доберётся до самой сердцевины, найдёт его секрет.

Вам достался файл ``Matryoshka.exe``. Программа просит ввести пароль. Найдите его.

Описать полностью ход решения. Приложить код программ, написанных для решения задачи.

Подсказка мастер не любил, когда за ним подглядывали.

02
==

Đề bài
------

Неумелый пользователь создавал очередную версию своего смарт-контракта для EVM (Etherium virtual machine) и случайно загрузил в мэйннет. К тому же при размещении он отправил туда почти все средства со своего личного аккаунта. Байт код смарт-контракта приведен ниже:

.. code-block:: 

   36600080373660006000F0600080808080945AF1600014601B57FD5B3360004780808080945AF100

Придумайте способ, как вернуть свои Ether. Ответ должен содержать значение поля call data спасительной транзакции, а также код вспомогательного смарт-контракта если он необходим.

03
==

Đề bài
------

Пусть :math:`P = \mathrm{GF}(2^n)` --- поле из :math:`2^n` элементов, :math:`u = (u(i))_{i=0}^{\infty}` --- линейная рекуррентная последовательность над полем :math:`P` порядка :math:`m` максимального периода :math:`T(u) = 2^{nm} - 1`, :math:`f : P \to \{ 0, 1 \}` --- сбалансированное отображение, т. е. :math:`\left| \{ x : f(x) = 1 \}\right| = 2^{n-1}` и двоичная последовательность :math:`v` построена по правилу :math:`v(i) = f(u(i))` для всех :math:`i \geqslant 0`.

1. Докажите, что :math:`T(v) = T(u)`.
2. Покажите, что для всех :math:`t`, которые не делятся на число :math:`\dfrac{2^{nm}-1}{2^n-1}`, расстояние Хэмминга :math:`\rho_t` между векторами :math:`(v(0), \ldots , v(T(u) - 1))` и :math:`(v(t), \ldots , v(t + T(u) - 1))` равно :math:`2^{nm-1}`.
3. Опишите все функции :math:`f`, для которых :math:`\rho_t = 2^{nm-1}` при всех :math:`t = 1, 2, \ldots , T(u) - 1`.

Để chứng minh :math:`T(v) = T(u)`, đầu tiên đặt

.. math:: T = T(u) = 2^{nm} - 1

là chu kì của LFSR :math:`u(i)`. Khi đó

.. math:: 

   \begin{array}{ccc}
      \Rightarrow & u(i) = u(i + T) & \text{với mọi} \ i \geqslant 0 \\
      \Rightarrow & f(u(i)) = f(u(i + T)) & \text{với mọi} \ i \geqslant 0 \\
      \Rightarrow & v(i) = v(i + T) & \text{với mọi} \ i \geqslant 0.
   \end{array}

Như vậy chu kì của dãy :math:`v(i)`, tức là :math:`T(v)`, phải chia hết :math:`T = T(u)`.

Giả sử :math:`T(v) = d \mid T(u)`. Khi đó :math:`T` phần tử của dãy :math:`v(i)` sẽ bao gồm :math:`T / d` đoạn phần tử lặp lại của dãy :math:`u(i)` với độ dài :math:`d`.

Đặt :math:`k` là số phần tử đơn vị (:math:`1`) trong một chu kì của dãy :math:`v(i)`, ví dụ như từ :math:`v(0)` tới :math:`v(d-1)`. Khi đó số lượng phần tử đơn vị trong một chu kì của dãy :math:`u(i)` là

.. math:: N = \frac{T}{d} \cdot k.

Bây giờ ta sẽ tính :math:`N` dựa trên sự phân bố phần tử trong dãy :math:`u`.

Giả sử LFSR :math:`u` có dạng

.. math:: u(i + m) = c_0 u(i) + c_1 u(i+1) + \cdots + c_{m-1} u(i + m - 1).

Khi đó mỗi trạng thái khác không

.. math:: S_i = (u(i), u(i+1), \ldots, u(i+m-1)) \in P^m

xuất hiện một lần trong một chu kì.

.. prf:lemma::
   :label: lem-cryptofox-26-exercise-3-1

   Với mối phần từ :math:`x \in P`, số lượng chỉ số :math:`i` sao cho :math:`u(i) = x` là

   .. math:: N_x = \begin{cases} 2^{n(m-1)}, & \text{khi} \ x \neq 0, \\ 2^{n(m-1)} - 1, & \text{khi} \ x = 0. \end{cases}

.. admonition:: Chứng minh
   :class: danger, dropdown

   Một tính chất của LFSR là trạng thái :math:`(0, 0, \ldots, 0)` không được phép xuất hiện trong LFSR vì LFSR là hàm Boolean tuyến tính, do đó :math:`(0, 0, \ldots, 0)` luôn biến thành chính nó. Như vậy với mỗi trạng thái của LFSR

   .. math:: S_i = (u(i), u(i+1), \ldots, u(i+m-1)) \in P^m,

   - nếu :math:`u(i) = x \neq 0`, :math:`m-1` phần tử còn lại nhận giá trị bất kì trong :math:`P`, do đó có :math:`(2^n)^{m-1}` cách chọn;
   - nếu :math:`u(i) = x = 0`, trạng thái phải khác không nên :math:`m-1` phần tử còn lại không được phép đồng thời bằng không, do đó có :math:`(2^n)^{m-1} - 1 = 2^{n(m-1)} - 1` cách chọn.

   Bổ đề được chứng minh xong.

Bây giờ, vì :math:`N` là số lượng phần tử đơn vị trong một chu trình của dãy :math:`u` nên

.. math:: 

   N & = \sum_{i=0}^{T-1} f(u(i)) \\
      & = \lvert \{ i : f(u(i)) = 1 \} \rvert \\
      & = \sum_{x \in P} \lvert \{ i : u(i) = x, f(u(i)) = 1 \} \rvert \\
      & = \sum_{x \in P} \sum_{\substack{i, \\ u(i) = x}} f(x) \\
      & = \sum_{x \in P} f(x) \left(\sum_{\substack{i, \\ u(i) = x}} 1\right) \\
      & = \sum_{x \in P} f(x) \cdot N_x.

Bởi vì :math:`f` là hàm cân bằng nên :math:`\sum\limits_{x \in P} f(x) = 2^{n-1}` và

.. math:: 

   N & = \sum_{x \in P} f(x) \cdot N_x \\
      & = f(0) \cdot N_0 + \sum_{x \neq 0} f(x) \cdot N_x \\
      & = f(0) \cdot (2^{n(m-1)} - 1) + \sum_{x \neq 0} f(x) \cdot 2^{n(m-1)} \\
      & = f(0) \cdot (2^{n(m-1)} - 1) + 2^{n(m-1)} \sum_{x \neq 0} f(x) \\
      & = f(0) \cdot (2^{n(m-1)} - 1) + 2^{n(m-1)} (2^{n-1} - f(0)) \\
      & = 2^{n(m-1)} \cdot 2^{n-1} - f(0) \\
      & = 2^{nm-1} - f(0).

Bây giờ ta chứng minh :math:`N` và :math:`T` nguyên tố cùng nhau.

**Trường hợp 1:** :math:`f(0) = 0`, khi đó :math:`N` là số chẵn, mà :math:`T` là số lẻ nên :math:`\gcd(T, N) = 1`.

**Trường hợp 2:** :math:`f(0) = 1`, khi đó :math:`N = 2^{nm-1} - 1`. Ta có

.. math:: 

   T = 2^{nm} - 1 = (2^{nm} - 1) \cdot 2 + 1 = 2N + 1,

như vậy

.. math:: T \bmod N = 1 \Rightarrow \gcd(T, N) = \gcd(T \bmod N, N) = 1.

Trong mọi trường hợp ta đều có

.. math:: \boxed{\gcd(T, N) = 1}.

Vì :math:`N = (T / d) \cdot k`, tương đương với :math:`T \cdot k = N \cdot d`, nhưng vì :math:`\gcd(T, N) = 1` nên ta phải có :math:`T = d`, hay

.. math:: \boxed{T(u) = T(v)}.

Tiếp theo ta chứng minh ý 2: với mọi :math:`t` mà không chia hết cho :math:`(2^{nm} - 1) / (2^n - 1)` thì khoảng cách Hamming :math:`\rho_t` giữa vector :math:`(v(0), v(1), \ldots, v(T(u) - 1)` và :math:`v(t), v(t+1), \ldots, v(t+T(u)-1)` bằng :math:`2^{nm}-1`.

Đặt :math:`Q = \FF_{2^{nm}}` là trường với :math:`2^{nm}` phần tử. Đặt

.. math:: \mathrm{tr}_{Q / P}: Q \to P, \alpha \mapsto \alpha + \alpha^{2^n} + \alpha^{2^{2n}} + \cdots + \alpha^{2^{n(m-1}}

là vết (trace) của trường.

Vì :math:`u` là LFSR bậc :math:`m` trên trường :math:`P` với chu kì cực đại :math:`2^{nm} - 1` nên tồn tại phần tử primitive :math:`\alpha \in Q^*` và phần tử khác không :math:`\beta \in Q` sao cho

.. math:: u(i) = \mathrm{tr}_{Q / P} (\beta \cdot \alpha^i).

Ta có :math:`u(i+t) = \mathrm{tr}_{Q / P} (\beta \cdot \alpha^{i+t}) = \mathrm{tr}_{Q / P}((\beta \alpha^i) \cdot \alpha^t)`.

Vì :math:`\alpha` là phần tử primitive của nhóm nhân :math:`Q^*` nên :math:`\alpha^t` là phần tử nào đó trong :math:`Q^*`. Bậc của nhóm nhân :math:`Q^*` là :math:`2^{nm} - 1 = T`.

Ngoài ra, nhóm con :math:`P^*` của nhóm :math:`Q^*` có bậc là :math:`2^n - 1`. Như vậy mọi phần tử của nhóm con :math:`P^*` có dạng

.. math:: \alpha^{k \cdot \frac{T}{2^n - 1}}

với mọi :math:`k = 0, 1 \ldots, 2^n - 2`. Nói cách khác, :math:`\alpha^t \in P^*` khi và chỉ khi :math:`t = k \cdot T / (2^n - 1)` với :math:`k = 0, 1, \ldots, 2^n - 2`.

Với những số :math:`t` như vậy, vì tính tuyến tính của vết:

.. math:: u(i+t) = \mathrm{tr}_{Q / P}((\beta \alpha^i) \cdot \alpha^t) = \mathrm{tr}_{Q / P} (\beta \alpha^i) \cdot \alpha^t = c \cdot u(i),

với :math:`c = \alpha^t \in P`.

Ở đây:

- nếu :math:`t` là bội của :math:`T / (2^n - 1)` thì :math:`u(i+t) = c \cdot u(i)` với số :math:`c \in P` nào đó;
- nếu :math:`t` không là bội của :math:`T / (2^n - 1)` thì cặp :math:`(u(i+t), u(i))` có thể chọn tùy ý từ :math:`P^2`.

Ở đây, khoảng cách Hamming :math:`\rho_t` là 

.. math:: 

   \rho_t & = \lvert \{ i: v(i) \neq v(i+t), 0 \leqslant i \leqslant T - 1 \} \rvert \\
        & = T - \lvert \{ i: v(i) = v(i+t), 0 \leqslant i \leqslant T - 1 \} \rvert.

Khi :math:`v(i) = v(i+t)` thì :math:`f(u(i)) = f(u(i+t))`. Ta cần chứng minh bổ đề sau.

.. prf:lemma:: 
   :label: lem-cryptofox-26-exercise-3-2

   Đặt :math:`W(a, b) = \{ i: u(i) = a, u(i+t) = b, 0 \leqslant i \leqslant T - 1 \}`. Khi đó

   .. math:: \lvert W(a, b) \rvert = \begin{cases} 2^{n(m-2)}, & \text{khi} \ (a, b) \neq (0, 0), \\ 2^{n(m-2)} - 1, & \text{nếu} \ (a, b) = (0, 0). \end{cases}

.. admonition:: Chứng minh
   :class: danger, dropdown

   Ta có :math:`u(i) = \mathrm{tr}(\beta \alpha^i)` với :math:`i = 0`, :math:`1`, ... với phần tử primitive :math:`\alpha` nào đó của nhóm :math:`Q^*` và phần tử khác không :math:`\beta \in Q`. Khi đó

   .. math:: 

      u(i+t) = \mathrm{tr}(\beta \cdot \alpha^{i+t}) = \mathrm{tr}(\beta \cdot \alpha^i \cdot \alpha^t) \\
        & = \mathrm{tr}(\gamma \cdot \alpha^i), \ \text{với} \ \gamma = \beta \cdot \alpha^t \in Q.

   Như vậy cặp :math:`(u(i), u(i+t)) = (\mathrm{tr}(\beta x), \mathrm{tr}(\gamma x))`, với :math:`x = \alpha^i \in Q` và :math:`i = 0, 1, \ldots, T-1` và :math:`x \neq 0`.

   Đặt :math:`L` là ánh xạ :math:`Q \to P^2`, :math:`x \mapsto (\mathrm{tr}(\beta x), \mathrm{tr}(\gamma x))`.

   Vì :math:`\mathrm{tr}` là ánh xạ tuyến tính nên :math:`L` cũng tuyến tính. Ở trên ta đã chứng minh rằng nếu :math:`t` không là bội của :math:`T / (2^n - 1)` thì :math:`\alpha^i \not\in P`. Khi đó :math:`\beta` và :math:`\gamma` độc lập tuyến tính trên :math:`P`.

   Từ đó, :math:`\mathrm{tr}(\beta x)` và :math:`\mathrm{tr}(\gamma x)` độc lập tuyến tính, suy ra :math:`L` là không gian vector con trên :math:`P^2` và có số chiều là :math:`2`. Dễ thấy :math:`L` là toàn ánh nên :math:`\dim \ker(L) = m - 2`, như vậy :math:`\lvert \ker(L) \rvert = (2^n)^{m-2} = 2^{n(m-2)}`.

   Ta có mỗi cặp :math:`(a, b) \in P^2` thì tập các nghiệm :math:`x \in Q` trong :math:`L(x) = (a, b)` là coset của nhân :math:`\ker(L)`. Như vậy tập nghiệm này có :math:`\lvert \ker(L) \rvert` phần tử.

   Ta có hai trường hợp:

   1. Nếu :math:`(a, b) = (0, 0)` thì coset và :math:`\ker(L)` trùng nhau. Vì :math:`x = \alpha^i \neq 0` nên số phần tử khác không :math:`x` sao cho :math:`L(x) = (0, 0)` là :math:`\lvert \ker(L) \rvert - 1`.
   2. Nếu :math:`(a, b) \neq (0, 0)` thì coset không có phần tử không (vì :math:`L(0) = (0, 0)`) nên coset có :math:`\lvert \ker(L) \rvert` phần tử.

   Từ đây suy ra

   .. math:: \lvert W(a, b) \rvert = \begin{cases} 2^{n(m-2)} - 1, & \text{khi} \ (a, b) = (0, 0) \\ 2^{n(m-2)}, & \text{khi} \ (a, b) \neq (0, 0) \end{cases}

Vì :math:`f` là hàm cân bằng nên:

- số lượng :math:`a \in P` sao cho :math:`f(a) = 0` bằng :math:`2^n / 2 = 2^{n-1}`;
- số lượng :math:`a \in P` sao cho :math:`f(a) = 1` bằng :math:`2^n / 2 = 2^{n-1}`.

Khi đó

.. math:: \lvert \{ (a, b) \in P^2 : f(a) = f(b) \} \rvert = \underbrace{\left(2^{n-1}\right)^2}_{f(a) = 0} + \underbrace{\left(2^{n-1}\right)^2}_{f(a) = 1} = 2^{2n-1}.

Ở đây

.. math:: 

   \{ i: v(i) = v(i+t), 0 \leqslant i \leqslant T - 1 \} = \{ i: f(u(i)) = f(u(i+t)), 0 \leqslant i \leqslant T-1 \}.

Đặt :math:`g(x) = (-1)^{f(x)}` với :math:`x \in P`. Khi đó

.. math:: \frac{1 + g(u) g(v)}{2} = \begin{cases} 1, & \text{khi} \ f(u) = f(v) \\ 0, & \text{khi} \ f(u) \neq f(v) \end{cases}

Từ đó

.. math:: 

   I & = \lvert \{ i: f(u(i)) = f(u(i+t)), 0 \leqslant i \leqslant T-1  \} \rvert \\
   & = \sum_{i=0}^{T-1} \frac{1 + g(u(i)) \cdot g(u(i+t))}{2} \\
   & = \frac{T}{2} + \frac{1}{2} \sum_{i=0}^{T-1} g(u(i)) \cdot g(u(i+t)).

Đặt

.. math:: J = \sum_{i=0}^{T-1} g(u(i)) \cdot g(u(i+t)) = \sum_{a \in P} \sum_{b \in P} g(a) \cdot g(b) \cdot W(a, b).

Khi đó:

1. Nếu :math:`(a, b) = (0, 0)` thì :math:`g(a) \cdot g(b) \cdot W(a, b) = 1 \cdot (2^{n(m-2)} - 1) = 2^{n(m-2)} - 1`.
2. Nếu :math:`(a, b) \neq (0, 0)` thì ta có hai trường hợp:

   - nếu :math:`f(a) = f(b)` thì :math:`g(a) \cdot g(b) \cdot W(a, b) = 1 \cdot 2^{n(m-2)} = 2^{n(m-2)}` và tồn tại :math:`2^{2n-1} - 1` cặp :math:`(a, b)` như vậy (không tính cặp :math:`(0, 0)`);
   - nếu :math:`f(a) \neq f(b)` thì :math:`g(a) \cdot g(b) \cdot W(a, b) = -1 \cdot 2^{n(m-2)} = -2^{n(m-2)}` và tồn tại :math:`2^{2n-1}` cặp :math:`(a, b)` như vậy.

Tổng kết lại

.. math:: J = 2^{n(m-2)} - 1 + 1 \cdot (2^{2n-1} - 1) \cdot 2^{n(m-2)} + (-1) \cdot 2^{2n-1} = -1.

Từ đó suy ra

.. math:: I = \frac{T}{2} - \frac{1}{2} = \frac{T - 1}{2},

và kết quả cuối cùng là

.. math:: \rho_t = T - I = T - \frac{T-1}{2} = \frac{T+1}{2} = \frac{2^{nm} - 1 + 1}{2} = 2^{nm-1}.

04
==

Đề bài
------

В настоящее время криптография на решетках по целому ряду причин является одним из наиболее перспективных направлений в постквантовой криптографии. Пусть задано Евклидово пространство :math:`\RR^n` и :math:`m \leqslant n` линейно независимых векторов :math:`\bm{b}_0`, :math:`\bm{b}_1`, ... , :math:`\bm{b}_{m - 1} \in \RR^n`. Тогда решеткой :math:`\Lambda` с базисом :math:`\bm{b}_0`, :math:`\bm{b}_1`, ... , :math:`\bm{b}_{m-1}` будем называть множество

.. math:: \Lambda = \left\{ \sum_{i=0}^{m-1} x_i \cdot \bm{b}_i : x_i \in \ZZ \right\} \in \RR^n.

Базис решетки :math:`\Lambda` принято записывать в виде матрицы :math:`\bm{B} \in \RR^{n \times m}`, столбцами которой являются базисные векторы bi. При этом число базисных векторов :math:`m` называется рангом решетки :math:`\Lambda`. Кроме того, если :math:`m = n`, то решетка называется полной. У одной и той же решетки ранга :math:`m > 1` бесконечно много различных базисов. Определителем полной решетки :math:`\Lambda` называется абсолютное значение определителя любой ее базисной матрицы: :math:`\left| \det \bm{B} \right|`. Определитель решетки является ее инвариантом, то есть не зависит от выбранного базиса.

Длиной вектора :math:`\bm{v} \in \Lambda` будем называть его евклидову норму :math:`\lVert \bm{v} \rVert_2`. Стойкость постквантовых криптосистем на решетках основывается на вычислительной сложности некоторых геометрических задач на решетках. Для решения таких задач, как правило, достаточно найти несколько «коротких» векторов решетки. Однако наилучшие современные алгоритмы справляются с таким поиском за экспоненциальное от ранга решетки время (в худшем случае). Более того, в общем случае неизвестны эффективные алгоритмы, позволяющие оценить длину кратчайшего ненулевого вектора решетки. Пусть :math:`\Lambda` --- полная решетка в пространстве :math:`\RR^n`, ее :math:`i`-ым последовательным минимумом :math:`\lambda_i(\Lambda)` называется минимальное число, при котором в :math:`\Lambda` можно найти :math:`i` линейно независимых векторов, длина которых не превосходит это число. Величину :math:`\lambda_i(\Lambda)` можно также интерпретировать как минимальный радиус :math:`r`, при котором шар с радиусом :math:`r` и с центром в нуле содержит :math:`i` линейно независимых векторов :math:`\Lambda`. Например, :math:`\lambda_1(\Lambda)` равен длине кратчайшего ненулевого вектора :math:`\Lambda`.

В общем случае неизвестны эффективные алгоритмы, позволяющие определить точное значение любого из последовательных минимумов решетки. Однако в криптографии часто прибегают к использованию решеток, обладающих некоторой дополнительной структурой. Введение дополнительной структуры позволяет улучшить эксплуатационные характеристики криптосистемы, но в то же время может упростить задачи, на сложности которых основывается стойкость этой криптосистемы. В приведенной ниже задаче предлагается изучить одну решетку, обладающую дополнительной структурой.

Пусть задано кольцо :math:`R = \ZZ[x] / (x^n + 1)`, где :math:`n = 1024`, и отображение :math:`\sigma: R \to \RR^n`, ставящее в соответствие многочлену :math:`a(x) = \sum_{k=0}^{n-1} a_k x^k \in R` вектор :math:`\bm{a} = (_a0, a_1, \ldots , a_{n-1})` Евклидова пространства :math:`\RR^n`. Пусть также :math:`g(x) = 1 + x + x^2 + \cdots + x^{n-1} \in R`. Рассмотрим главный идеал :math:`\mathcal{I} = (g) \subset R`, порожденный многочленом :math:`g(x)`.

1. Докажите, что множество :math:`\Lambda = \sigma(\mathcal{I})` является полной решеткой в :math:`\RR^n`.
2. Найдите определитель решетки :math:`\Lambda`.
3. Найдите (или приведите оценки) последовательные минимумы :math:`\lambda_1(\Lambda)` и :math:`\lambda_n(\Lambda)` решетки :math:`\Lambda`.

05
==

Đề bài
------

В первый же день масленицы один из серверов в ЦОДе пострадал от атаки хакеров. Админ во второй половине дня так увлекся уничтожением блинчиков, что пропустил запуск трояна-вымогателя. Все данные оказались зашифрованы, а backup'ов нет. Помогите системному администратору не потерять работу: расшифруйте самый важный файл.

Описать полностью ход решения. Приложить код программ, написанных для решения задачи.

06
==

Đề bài
------

Любитель линейности, матриц и подстановок положил письмо с текстом в запутанный белый ящик. 

Достань его, прочитай текст и получи приз!

Дано 3 файла:

- ``encr.py``: код шифрования
- ``encr.evh``: открытый ключ
- ``encrypted.bin``: шифртекст

Сам алгоритм шифрования заключается в следующем. Каждые 4 бита входной последовательности преобразуются с помощью сгенерированной генератором песевдослучайных чисел (ГПСЧ) подстановки ( S-бокса). Для каждых 4-х бит входной последовательности генерируется свой  S-бокс, преобразующая 4 бита входной последовательности в 4 бита выходной последовательности. Таким образом входная последовательность, состоящая из 32-х байт (или 64-х 4-битовых последовательностей), преобразуется с помощью 64-х различных S-боксов (каждые 4 бита обрабатываюются своим S-боксом). Полученная в результате последовательнось из 32-х байт дополняется двумя нулевыми байтами (в итоге получается 34 байта). Эти 34 байта могут быть представлены как 272-битовый вектор-столбец. На этот вектор-столбец умножается сгенерированная с помощью ГПСЧ несингулярная матрица размером 272x272 бит. Результат содержится в файле encrypted.bin. 32-х битная реализация AES подсказывает нам, что преобразование с помощью S-боксов и умножение на матрицу можно объединить, получив в результате набор таблично заданных преобразований - T-боксов. Такие T-боксы представлены в файле encr.evh. Следует обратить внимание, что эти T-боксы принимают на вход 8 бит, а не 4. 

Задача: Имея на руках файлы ``encr.py``, ``encr.evh``, ``encrypted.bin``, необходимо из шифртекста восстановить исходный текст (MSG в encr.py).

Описать полностью ход решения. Приложить код программ, написанных для решения задачи.

Giải
----

Xét ánh xạ affine

.. math:: 

   \begin{array}{ccc}
      T: & \FF_{2}^8 & \to & \FF_{2}^8 \\
      & \bm{x} & \mapsto & \bm{x} \cdot \bm{A} \oplus \bm{b},
   \end{array}

trong đó :math:`\bm{A}` là ma trận khả nghịch trên :math:`\FF_2` cỡ :math:`8 \times 8` và :math:`\bm{b}` là vector độ dài :math:`8` trên :math:`\FF_2`.

Ta xem vector :math:`\bm{x} = (x_0, x_1, \ldots, x_7)` tương ứng với số nguyên :math:`x = x_0 + 2 x_1 + \cdots + 2^7 x_7`, do đó ta viết

.. math:: 
   
   T(x) & = T(x_0, x_1, \ldots, x_7) = (x_0, x_1, \ldots, x_7) \cdot \bm{A} \oplus \bm{b} \\
      & = [x_0 \cdot (1, 0, \ldots, 0) \oplus x_1 \cdot (0, 1, \ldots, 0) \oplus \cdots \oplus x_7 \cdot (0, 0, \ldots, 1)] \cdot \bm{A} \oplus \bm{b} \\
      & = x_0 \cdot (1, 0, \ldots, 0) \cdot \bm{A} \oplus x_1 \cdot (0, 1, \ldots, 0) \cdot \bm{A} \oplus \cdots \oplus x_7 \cdot (0, 0, \ldots, 1) \cdot \bm{A} \oplus \bm{b}.

Để ý rằng :math:`T(0) = \bm{b}`, và 

.. math:: 
   
   T(2^k) & = \underbrace{(0, \ldots, 1, \ldots, 0)}_{\text{vị trí thứ} \ k} \cdot \bm{A} \oplus \bm{b} \\
      & = (0, \ldots, 1, \ldots, 0) \cdot \bm{A} \oplus T(0),

tương đương với

.. math:: x_k \cdot (0, \ldots, 1, \ldots, 0) \cdot \bm{A} = x_k \cdot \left(T(2^k) \oplus T(0)\right).

Thay vào :math:`T(x)` bên trên ta có

.. math:: T(x) = \left[\bigoplus_{k=0}^7 x_k \cdot \left(T(2^k) \oplus T(0)\right)\right] \oplus T(0).

Quá trình mã hóa có thể được viết dưới dạng

.. math:: y_j = \bigoplus_{i=0}^{31} T[i, m_i, j], \quad j = 0, 1, \ldots, 31,

với:

- :math:`T` là khóa công khai cho bởi đề bài, là một mảng 3D;
- :math:`m_i` là thông điệp cần phục hồi;
- :math:`y_j` là bản mã được cho.

Giả sử mỗi bảng :math:`T[\cdot, \cdot, \cdot]` là một biến đổi affine. Nếu :math:`x = x_0 + 2 x_1 + \cdots 2^7 x_7`, như ta đã chứng minh trên thì

.. math:: T[i, x, j] = \left(\bigoplus_{k=0}^{7} x_k \cdot T[i, 2^k, j] \oplus T[i, 0, j]\right) \oplus T[i, 0, j].

Đặt hằng số

.. math:: C_j = \bigoplus_{i=0}^{31} T[i, 0, j],

và đặt

.. math:: 

   y'_j & = y_j \oplus C_j \\
      & = \left(\bigoplus_{i=0}^{31} T[i, m_i, j]\right) \oplus \left(\bigoplus_{i=0}^{31} T[i, 0, j]\right) \\
      & = \left(\bigoplus_{i=0}^{31}\left(\bigoplus_{k=0}^7 x_{i, k} \cdot \left(T[i, 2^k, j] \oplus T[i, 0, j]\right)\right) \oplus \cancel{T[i, 0, j]}\right) \oplus \left(\bigoplus_{i=0}^{31} \cancel{T[i, 0, j]}\right) \\
      & = \bigoplus_{i=0}^{31} \bigoplus_{k=0}^{7} \left(x_{i, k} \cdot \left(T[i, 2^k, j] \oplus T[i, 0, j]\right)\right),

trong đó :math:`m_i = x_{i, 0} + 2 x_{i, 1} + \cdots + 2^7 x_{i, 7}`, :math:`x_{i, k} \in \{ 0, 1 \}`.

Cuối cùng, ta phân tích byte thành bit. Với mỗi vị trị :math:`j`, mỗi vị trí bit :math:`b`, :math:`0 \leqslant b \leqslant 7`, được tính bởi

.. math:: a_{ijk}^{(b)} = \left[\left(T[i, 2^k, j] \oplus T[i, 0, j]\right) \gg b\right] \bmod 2.

Lúc này ta chỉ việc giải hệ phương trình tuyến tính trên :math:`\FF_2`

.. math:: \bigoplus_{i=0}^{31} \bigoplus_{k=0}^7 a_{ijk}^{(b)} \cdot x_{i, k} = (y'_j \gg b) \bmod 2,

với :math:`j = \overline{0, 33}` và :math:`b = \overline{0, 7}`.

Ta có :math:`34 \cdot 8 = 272` phương trình và :math:`32 \cdot 8 = 256` biến :math:`x_{i, k}` nên phương trình có nghiệm duy nhất. Giải phương trình ta được kết quả.

07
==

Đề bài
------

Шифр задания: «Внеклассное чтение»: Прогрев журналов событий Windows.

Контекст операции:

Агент под прикрытием Алиса Акулова («Отличница») получает спецсообщение из Центра: немедленно вылететь в Вашингтон для выполнения нового задания. По легенде она --- международный независимый журналист и фотограф с многолетним стажем работы на Ближнем Востоке и в Азии. Её реальная миссия --- секретная разведывательная операция.

Проблема:

После недавнего крупного шпионского скандала в США службы безопасности ужесточили досмотр техники на границе: сотрудники Таможенно‑пограничной службы тщательно просматривают содержимое устройств и, среди прочего, проверяют журналы событий Windows (Event Viewer). Алиса успела «прогреть» телефон --- наполнила его старыми чатовыми переписками и фотографиями, создающими правдоподобную историю поездок. Но с ноутбуком всё сложнее: его удалось купить только сегодня, и свежая установка новой Windows 11 никак не соответствует легенде о многолетней активной работе. Пустые и краткие журналы вызовут подозрения, что недопустимо.

По данным агентурной разведки, пограничные эксперты обращают обращают особое внимание на историю в системных журналах, особенно за последние 2–3 года:

- Event ID 6005, 6006, 6008 --- события загрузки и выключения ОС.
- Event ID 4624 --- успешный вход пользователя в систему.

Маскировка через перехват API не подходит --- эксперты копируют и анализируют сами файлы .evtx в изолированной среде. Изменять системное время тоже неприемлимо: такие действия оставляют собственные следы в журналах, которые легко обнаружить. Скрипт должен быть написан на языке PowerShell, поскольку передача исполнимого кода или запароленного архива может вызвать подозрения у местных органов контрразведки.

Ваша миссия:

Вы --- сотрудник российской оперативно-технической службы, сегодня на дежурстве. Вам поручено создать и протестировать инструмент для Алисы.

Цель: Разработать скрипт на PowerShell, который модифицирует непосредственно файлы журналов событий (EVTX), создавая в них правдоподобную историю использования ноутбука за последние 3 года. Скрипт должен быть самодостаточным, не требовать установки дополнительного ПО и оставлять минимум собственных следов.

Ожидаемые результаты:

- исходный листинг на PowerShell для запуска на Windows 11.
- скриншоты экрана с демонстрацией результата до и после запуска инструмента.

Время на выполнение ограничено. Удачи, оперативник. От вашего кода зависит успех миссии!

08
==

Đề bài
------

Незнайка решил создать свой алгоритм шифрования (файлы ``cipher.c``, ``reg.c``, ``reg.h``). Он зашифровал очень для себя важный файл (``open.txt``), убедился, что получил зашифрованный файл (``out.txt``), и удалил изначальный файл. Потом при попытке восстановить изначальный файл он обнаружил, что забыл записать ключ, и теперь не знает как файл восстановить. Но Незнайка сохранил имотозащиту ключа (``keymac.txt``) для того, чтобы дать ее Знайке на проверку статистическим свойствам, чтобы убедиться что алгоритм хороший. Сможете ли вы восстановить изначальный файл (или его часть), и найти недочет в алгоритме Незнайки? Или алгоритм Незнайки достаточно хороший, чтобы стать стандартом шифрования Цветочного города?

09
==

Đề bài
------

Описать полностью ход решения. Приложить код программ, нВам доверили в использование систему, которая, для проверки прав пользователя, вызывает подпрограмму, принимающую на вход его токен, и возвращающую список его ролей в квадратных скобках, например ``[user,moderator]`` значит, что у пользователя есть права ``user`` и ``moderator``. В случае неуспеха программа возвращает строку ``[]``.

Проблема заключается в том, что метод генерации доверенных токенов утерян, а в настоящее время нет доступа ни к исходному коду системы ни к её развёртке (то есть заменить её на другую нет возможности), потому что единственный разработчик уехал на автобусе в отпуск.

Единственное, что доступно — это ранее выгруженные сегменты программы (директория ``./app-bin``): их состав полон (их конкатенация составляет рабочую программу), однако взаимный порядок неизвестен.

Требуется определить, как сформировать токен, который будет принят программой, то есть такой, для которого она выведет значение желаемых владельцем токена ролей.

В решении необходимо:

1. Привести ход действий, по которому осуществлялся разбор программы.
2. Пример токена, успешно предоставляющего роли ``user`` и ``admin``.
3. Общий алгоритм генерации токена для произвольных ролей (на языке программирования).

Дополнительные баллы можно получить за:

* Обеспечение поддержки произвольных дополнительных данных в токене.
* Автоматизацию процесса запуска и тестирования программы локально.
* Приведение архитектурных проблем в программе написанных для решения задачи.

10
==

Đề bài
------

Алиса реализовала схему цифровой подписи из семейства подписей Эль-Гамаля. Программная реализация находится в файле ``sig.py``.

Алиса подписывала сообщения из массива messages. Некоторые сообщения она подписывала с помощью своего секретного ключа d (некоторая осмысленное сообщение в виде массива байт), а для некоторых сообщений она имитировала подпись случайной генерацией значения подписи. Результаты работы программы расположены в файле ``out.txt``.

Определите какие именно сообщения из массива messages были подписаны Алисой с помощью своего секретного ключа? Определите значение секретного ключа Алисы.

11
==

Đề bài
------

Игорь уже продолжительное время исследует криптографические свойства преобразования шифрмашины VULPIS. Суть преобразований состоит в разбиении открытого текста :math:`\alpha = (\alpha_1, \ldots , \alpha_{n / 2}, \alpha_{n/2+1}, \ldots, \alpha_n) \in V_n(2^m)` на два полублока равной длины, которые подаются на вход 1 и 2 цепочки преобразований в соответствии со схемой

.. figure:: 11/scheme.*
   :width: 50%

В рамках указанной схемы операция «+» определяется соответствующей операцией в аддитивной группе векторного пространства :math:`V_{n/2}(2)`, а преобразование :math:`: V_{n/2}(2^m) \to V_{n/2}(2^m)`, :math:`s(\alpha) = (s'(\alpha_1), \ldots, s'(\alpha_{n/2}))`, :math:`\alpha = (\alpha_1, \ldots, \alpha_{n/2}) \in V_{n/2}(2^m)` задается ключевым параметром :math:`s' \in S(\mathbb{F}_{2^m})`.

В настоящий момент Игоря интересует ответ на вопрос: «существуют ли пары открытый текст-шифртекст, которые нельзя получить, используя преобразование шифрмашины VULPIS» для произвольного значения ключа :math:`s'` и четного :math:`n \in \NN`.

Помогите Игорю ответить на интересующей его вопрос! В случае положительного ответа, также приведите пример хотя бы одной такой пары.

Giải
----

Gọi :math:`\alpha = (\alpha_1, \ldots, \alpha_{n/2}, \alpha_{n/2+1}, \ldots, \alpha_n)` là bản rõ đầu vào, :math:`\beta = (\beta_1, \ldots, \beta_{n/2}, \beta_{n/2+1}, \ldots, \beta_n)` là bản mã đầu ra.

Khi đó ta có

.. math:: 

   (\beta_1, \ldots, \beta_{n/2})   & = (s'(\alpha_1 \oplus s'(\alpha_{n/2+1})), \ldots, s'(\alpha_{n/2} \oplus s'(\alpha_n))), \\
   (\beta_{n/2+1}, \ldots, \beta_n) & = (s'(\alpha_{n/2+1} \oplus s'(\alpha_1 \oplus s'(\alpha_{n/2+1}))), \ldots, s'(\alpha_n \oplus s'(\alpha_{n/2} \oplus s'(\alpha_n)))).

Như vậy công thức chung là với mọi :math:`i` sao cho :math:`1 \leqslant i \leqslant n/2` thì

.. math:: 

   \beta_i        & = s'(\alpha_i \oplus s'(\alpha_{n/2+i})), \\
   \beta_{n/2+i}  & = s'(\alpha_{n/2+i} \oplus s'(\alpha_i \oplus s'(\alpha_{n/2+i}))) = s'(\alpha_{n/2+i} \oplus \beta_i).

Ta sẽ chứng minh tồn tại các phần tử :math:`\alpha_i`, :math:`\alpha_{n/2+i}`, :math:`\beta_i` và :math:`\beta_{n/2+i}` sao cho không thỏa hai đẳng thức trên với mọi hoán vị :math:`s'`.

Ta chọn :math:`\alpha_i = 1`, :math:`\alpha_{n/2+1} = 0`, :math:`\beta = 0`, :math:`\beta_{n/2+1} = 1` và thay vào hai đẳng thức trên được

.. math:: 

   0 = s'(1 \oplus s'(0)), \quad 1 = s'(0 \oplus 0) = s'(0),

thay :math:`s'(0) = 1` vào biểu thức phía trước :math:`0 = s'(1 \oplus 1) = s'(0)`. Điều này là vô lý vì :math:`s'(0)` không thể cùng lúc nhận hai giá trị :math:`0` và :math:`1`.

Như vậy với mọi vị trí :math:`i`, :math:`1 \leqslant i \leqslant n/2`, chọn :math:`\alpha_i = 1`, :math:`\alpha_{n/2+1} = 0`, :math:`\beta = 0`, :math:`\beta_{n/2+1} = 1` sẽ cho ta cặp bản rõ và bản mã không thỏa mãn mô hình mã hóa với mọi hoán vị :math:`s' \in S(\mathbb{F}_{2^m})`.

