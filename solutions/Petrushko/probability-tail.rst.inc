Задача 6. Пусть :math:`X` - количество бросков чтобы закончить.

(a) (опят закончится до шестого броска).

Первый бросок, какая сторона не важно :math:`\Longrightarrow P(A) = P(X=2) + P(X=3) + P(X=4) + P(X=5)`.

Второй бросок может выпадет *одной и той же* стороной, или *другой*. Оба вероятности равны :math:`\dfrac{1}{2}`.

То :math:`P(X=2) = \dfrac{1}{2}`.

Если :math:`P(X=3)`, третьи бросок будет другой стороной, чем 2 другие. Поэтому вероятность того, что второй бросок выпадает одной стороной: :math:`\dfrac{1}{2}`, а третьи бросок: :math:`\dfrac{1}{2}`.

То :math:`P(X=3) = \dfrac{1}{2} \cdot \dfrac{1}{2} = \dfrac{1}{4}`, :math:`P(X=4) = \dfrac{1}{8}` и :math:`\dfrac{1}{16}`.

Аналогично, :math:`P(X=4) = \dfrac{1}{8}`.

:math:`\Longrightarrow P(A) = \dfrac{1}{2} + \dfrac{1}{4} + \dfrac{1}{8} + \dfrac{1}{16} = \dfrac{15}{16}`.

(б) :math:`B` - { понадобится более четырех бросков }.

:math:`\overline{B}` - { понадобится не более четырех бросков }.

Делаем как (а), мы получим :math:`P(\overline{B}) = \dfrac{1}{2} + \dfrac{1}{4} + \dfrac{1}{8} = \dfrac{7}{8}`.


.. math::

   \Longrightarrow P(B) = 1 - P(\overline{B}) = 1 - \dfrac{7}{8} = \dfrac{1}{8}.


Задача 7. Из колоды карт (36 штук)

(a) Пусть :math:`A` = { Первый тух появится при третьем извлечении карты }.

:math:`\lvert \Omega \rvert = A^3_36`.

Пусть :math:`a_1, a_2, a_3` - карты выбраны.

Тогда :math:`a_3` будет одном из 4 карт, у нас есть 4 вариантов.

Ещё нужно выбрать карты :math:`a_1` и :math:`a_2`, мы не можем выбрать туз, поэтому имеем :math:`A^2_{36-4} = A^2_{32}`.

Ответ: :math:`P(A) = \dfrac{4 \cdot A^2_{32}}{A^3_{36}} = \dfrac{496}{5355} \approx 0,09`.

(б) Пусть :math:`B` = { Первый туз появится не ранее третьего извлечения карты }.

:math:`\Longrightarrow \overline{B}` = { Первый туз появится при первом или втором извлечении карты }.

- Если первый туз появится при первом извлечении, то вероятность равно :math:`\dfrac{4}{36} = \dfrac{1}{9}`
- Если первый туз появится при втором извлечении, то делаем аналогично (а), мы получим :math:`\dfrac{4 \cdot A^1_{32}}{A^2_{36}}`

Поэтому, :math:`P(\overline{B}) = \dfrac{4}{36} + \dfrac{4 \cdot A^1_{32}}{A^2_{26}} = \dfrac{67}{315}`.


.. math::

   \Longrightarrow P(B) = 1 - P(\overline{B}) = \dfrac{248}{315}.


Задача 8. Из колоды карт (36 карт) не более трех карт, пусть

- :math:`A` = { выбрать более трех карт }.
- :math:`\overline{A}` = { выбрать не более трех карт, значит 1, 2 или 3 карт }

Отсюда

1. Если выбрать 1 карту, :math:`| \Omega_1 | = 36`.
   
   Выбрать одну красную карту из 18 красных карт, есть 18 вариантов. То :math:`P(X=1) = \dfrac{18}{36}`.

2. Если выбрать 2 карты, :math:`| \Omega_2 | = A^2_{36}`.

   Выбрать одну красную карту в последнем месте, то есть 18 вариантов. А первое место мы не можем выбрать красную карту, то есть 36-18=18 вариантов. Поэтому :math:`P(X=2) = \dfrac{18 \cdot 18}{A^2_{36}}`

3. Если выбрать 3 карты, :math:`| \Omega_3 | = A^3_{36}`.

   Выбрать одну красную карту в последнем месте, есть 18 вариантов. Другие места мы не можем выбрать красные карты, а 2 черные карты из 18 карт. Поэтому :math:`P(X=3) = \dfrac{18 \cdot A^2_{18}}{A^3_{36}}`


.. math::

   \Longrightarrow P(\overline{A}) = P(X=1) + P(X=2) + P(X=3) = \dfrac{18}{36} + \dfrac{18 \cdot 18}{A^2_{26}} + \dfrac{18 \cdot A^2_{18}}{A^3_{36}} = \dfrac{31}{35}.


.. math::

   \Longrightarrow P(A) = 1 - P(\overline{A}) = \dfrac{4}{35}.


Задача 9. 8 белых, 6 черных и 2 синих

(a) повторный выбор шаров, :math:`\lvert \Omega \rvert = {16}^3`.

Выбрать первый шар, есть 8 вариантов (белых). Выбрать второй шар, есть 6 вариантов (черных). Выбрать третьи шар, есть 2 варианта (синих). Поэтому, вероятность равно :math:`\dfrac{8 \cdot 6 \cdot 2}{{16}^3} = \dfrac{3}{128}`
(б) бесповторный выбор шаров, :math:`\lvert \Omega \rvert = A^3_{16}`.

Делаем аналогично (а), получим вероятность :math:`\dfrac{8 \cdot 6 \cdot 2}{A^3_{16}} = \dfrac{1}{35}`


Задача 10.

Пусть 

- :math:`A` = { шар окажется белым }.
- :math:`B_1` = { Результат монеты - гебр }.
- :math:`B_2` = { Результат монеты - цифра }.

То :math:`B_1` и :math:`B_2` - полная группа событий, и :math:`P(B_1) = P(B_2) = \dfrac{1}{2}`.

1. Если первая урна выбрана, то вероятность того, что шар окажется белым будет :math:`P(A | B_1) = \dfrac{4}{4+2} = \dfrac{4}{6}`.
2. Если вторая урна выбрана, то вероятность того, что шар окажется белым будет :math:`P(A | B_2) = \dfrac{3}{3 + 5} = \dfrac{3}{8}`.

Ответ: :math:`P(A) = P(B_1) \cdot P(A | B_1) + P(B_2) \cdot P(A | B_2) = \dfrac{1}{2} \cdot \dfrac{4}{6} + \dfrac{1}{2} \cdot \dfrac{3}{8} = \dfrac{25}{48}`


Занятия 5
------------------------------------------------------------

Задача 1. Используем пример 5.1 и формулу Байеса:


.. math::

   P(B_i | A) = \dfrac{P(B_i) \cdot P(A | B_i)}{P(A)} = \dfrac{P(B_i) \cdot P(A | B_i)}{\sum_{j=1}^{3} P(B_j) \cdot P(A | B_j)}


- :math:`P(B_1) = \dfrac{\dfrac{1}{4} \cdot \dfrac{1}{4}}{\dfrac{17}{48}} = \dfrac{3}{17}`
- :math:`P(B_2) = \dfrac{\dfrac{1}{4} \cdot \dfrac{1}{2}}{\dfrac{17}{48}} = \dfrac{6}{17}`
- :math:`P(B_3) = \dfrac{\dfrac{1}{4} \cdot \dfrac{2}{3}}{\dfrac{17}{48}} = \dfrac{8}{17}`


Задача 3. Пусть :math:`A_1` = { дефективные } и :math:`A_2` = { не дефективные }.

:math:`B` = { Признан дефективным }.

Мы получим: :math:`P(A_1) = 0,1`, :math:`P(A_2) = 1-0,1=0,9`, :math:`P(B | A_1) = 0,95`, :math:`P(B | A_2) = 0,03`.

:math:`P(B) = P(A_1) P(B | A_1) + P(A_2) P(B | A_2) = 0,1 \cdot 0,95 + 0,9 \cdot 0,03 = 0,122`


Задача 4. Пусть

- :math:`A` = { событие болты производятся из А }.
- :math:`B` = { событие болты производятся из В }.
- :math:`C` = { событие болты производятся из С }.
- :math:`K` = { Болт оказался дефективным }.

У нас есть: :math:`P(A) = 0,25`, :math:`P(B) = 0,35`, :math:`P(C) = 0,4`, :math:`P(K|A) = 0,05`, :math:`P(K|B) = 0,04`, :math:`P(K|C) = 0,02`.

Ответ:.


.. math::

   \begin{align*} P(A|K) & = \dfrac{P(A) P(K|A)}{P(A)P(K|A)+P(B)P(K|B)+P(C)P(K|C)} \\ & = \dfrac{0,25 \cdot 0,05}{0,25 \cdot 0,05 + 0,35 \cdot 0,04 + 0,4 \cdot 0,02} = \dfrac{25}{69} \approx 0,36 \end{align*}


Задача 5. Пусть 

- :math:`A` = { вынуть белый шар из второй урны }
- :math:`B` = { Вынуть два шара из первой урны }.

У нас есть :math:`B = B_1 + B_2 + B_3`, с.

- :math:`B_1` = { вынуть 1 белый и 1 черный }. :math:`P(B_1) = \dfrac{C^1_4 \cdot C^1_2}{C^2_6} = \dfrac{8}{15}`. Теперь в второй урне есть 3 белых шара, поэтому :math:`P(A | B_1) = \dfrac{3}{7}`.
- :math:`B_2` = { вынуть 2 белых }. :math:`P(B_2) = \dfrac{C^2_4}{C^2_6} = \dfrac{2}{5}`. Теперь в второй урне есть 4 белых шара, поэтому :math:`P(A | B_2) = \dfrac{4}{7}`.
- :math:`B_3` = { вынуть 2 черных }. :math:`P(B_3) = \dfrac{C^2_2}{C^2_6} = \dfrac{1}{15}`. Теперь в второй урне есть 2 белых шара, поэтому :math:`P(A | B_3) = \dfrac{2}{7}`.

Ответ:.


.. math::

   \begin{align*} P(A) & = P(B_1) \cdot P(A | B_1) + P(B_2) \cdot P(A | B_2) + P(B_3) \cdot P(A | B_3) \\ & = \dfrac{8}{15} \cdot \dfrac{3}{7} + \dfrac{2}{5} \cdot \dfrac{4}{7} + \dfrac{1}{15} \cdot \dfrac{2}{7} = \dfrac{10}{21} \end{align*}


Задача 6. Пусть :math:`A_1` = { выбрать 2 белых шара }, :math:`A_2` = { выбрать 2 черных шара } и :math:`A_3` = { выбрать 2 шара разного цвета }.

:math:`B` = { третий шар отказался белым }.

У нас есть :math:`P(A_3 | B) = \dfrac{P(A_3) \cdot P(B | A_3)}{P(A_1) + P(B|A_1) + P(A_2) \cdot P(B|A_2) + P(A_3) \cdot P(B | A_3)}` (формула Байеса)

1. C :math:`A_1`, у нас есть :math:`P(A_1) = \dfrac{5 \cdot 4}{8 \cdot 7} = \dfrac{5}{14}`. Значит третий шар имеет 3 варианта, чтобы получить белый шар, :math:`P(B | A_1) = \dfrac{3}{6} = \dfrac{1}{2}`.
2. C :math:`A_2`, у нас есть :math:`P(A_2) = \dfrac{3 \cdot 2}{8 \cdot 7} = \dfrac{3}{28}`. Значит третий шар имеет 5 варианта, чтобы получить белый шар, :math:`P(B | A_2) = \dfrac{5}{6}`.
3. C :math:`A_3`, у нас есть :math:`P(A_3) = \dfrac{2 \cdot 3 \cdot 5}{8 \cdot 7} = \dfrac{15}{28}` (2 значит белый-черный или черный белый). Значит третий шар имеет 4 варианта, чтобы получить белый шар, :math:`P(B | A_3) = \dfrac{4}{6} = \dfrac{2}{3}`.

Ответ: :math:`P(A_3 | B) = \dfrac{15}{28} \cdot \dfrac{2}{3} : \left(\dfrac{5}{14} \cdot \dfrac{1}{2} + \dfrac{3}{28} \cdot \dfrac{5}{6} + \dfrac{15}{28} \cdot \dfrac{2}{3}\right) = \dfrac{4}{7}`.


Задача 7. Пусть

- :math:`A_1` = { выбрать красный шар из первой урны } и :math:`A_2` = { выбрать черный шар из первой урны }.
- :math:`B_1` = { выбрать красный шар из второй урны } и :math:`B_2` = { выбрать черный шар из второй урны }.

У нас есть :math:`P(A_1) = P(A_2) = \dfrac{1}{2}`, :math:`P(B_1 | A_1) = \dfrac{3}{6}`, :math:`P(B_1 | A_2) = \dfrac{2}{6}`, :math:`P(B_2 | A_1) = \dfrac{3}{6}`, :math:`P(B_2 | A_2) = \dfrac{4}{6}`.

(a) Пусть :math:`C` = { вынуты шары одного цвета }.


.. math::

   \begin{align*} \Longrightarrow P(C) & = P(A_1 \cdot B_1 + A_2 \cdot B_2) = & P(A_1) \cdot P(B_1 | A_1) + P(A_2) \cdot P(B_2 | A_2) \\ & = \dfrac{1}{2} \cdot \dfrac{3}{6} + \dfrac{1}{2} \cdot \dfrac{4}{6} = \dfrac{7}{12} \end{align*}


(б) Пусть :math:`D` = { выбрать красный шар из первой урны и черный шар из второй урны }


.. math::

   \begin{align*} P(D) = P(A_2 | B_1) & = \dfrac{P(A_2) \cdot P(B_1 | A_2)}{P(A_1) \cdot P(B_1 | A_1) + P(A_2) \cdot P(B_1 | A_2)} \\ & = \left(\dfrac{1}{2} \cdot \dfrac{2}{6}\right) : \left(\dfrac{1}{2} \cdot \dfrac{2}{6} + \dfrac{1}{2} \cdot \dfrac{3}{6}\right) = \dfrac{2}{5} \end{align*}


Задача 8.


Задача 9. Пусть :math:`A_1` = { первый шар является белым } и :math:`A_2` = { второй шар является черным }.

:math:`B` = { два следующие шары - черные }.

У нас есть, :math:`P(A_1) = \dfrac{4}{7}`, :math:`P(A_2) = \dfrac{3}{7}`

1. Если первый шар является белым, то в урне есть 3 белых и 3 черных, поэтому :math:`P(B | A_1) = \dfrac{C^2_3}{C^2_6} = \dfrac{1}{5}`
2. Если первый шар является черным, то в урне есть 4 белых и 2 черных, поэтому :math:`P(B | A_2) = \dfrac{C^2_2}{C^2_6} = \dfrac{1}{15}`

Мы получим:


.. math::

   \begin{align*} P(A_1 | B) & = \dfrac{P(A_1) \cdot P(B | A_1)}{P(A_1) \cdot P(B | A_1) + P(A_2) \cdot P(B | A_2)} \\ & = \left(\dfrac{4}{7} \cdot \dfrac{1}{5}\right) : \left(\dfrac{4}{7} \cdot \dfrac{1}{5} + \dfrac{3}{7} \cdot \dfrac{1}{15}\right) = \dfrac{4}{5} = 0,8 \end{align*}


Задача 10. Пусть

- :math:`A_1` = { комбинация 11111 передана } и :math:`A_2` = { комбинация 00000 передана }.
- :math:`B` = { комбинация 10110 получена }.

У нас есть: :math:`P(A_1) = 0,7`, :math:`P(A_2) = 0,3`

1. Если комбинация 11111 передана, то первое, третье и пятое цифры правильно, а другие нет, поэтому :math:`P(B | A_1) = 0,6 \cdot 0,4 \cdot 0,6 \cdot 0,6 \cdot 0,4 = 0,6^3 \cdot 0,4^2`
2. Если комбинация 00000 передана, то второе и четвертое цифры правильно, а другие нет, поэтому :math:`P(B | A_2) = 0,4 \cdot 0,6 \cdot 0,4 \cdot 0,4 \cdot 0,6 = 0,4^3 \cdot 0,6^2`

Ответ


.. math::

   \begin{align*} P(A_1 | B) & = \dfrac{P(A_1) \cdot P(B | A_1)}{P(A_1) \cdot P(B | A_1) + P(A_2) \cdot P(B | A_2)} \\ & = \dfrac{0,7 \cdot 0,6^3 \cdot 0,4^2}{0,7 \cdot 0,6^3 \cdot 0,4^2 + 0,3 \cdot 0,4^3 \cdot 0,6^2} = \dfrac{7}{9} \approx 0,78 \end{align*}


Занятия 6
------------------------------------------------------------

Задача 1. Пусть :math:`A` = { Два раза выпадет шесть очков }.

У нас есть :math:`n = 5`, :math:`p = \dfrac{1}{6}`, поэтому :math:`q = 1-p = \dfrac{5}{6}`.

Ответ: :math:`P(A) = P_5(k=2) = C^2_5 \cdot \left(\dfrac{1}{6}\right)^2 \cdot \left(\dfrac{5}{6}\right)^3 = \dfrac{625}{3888} \approx 0,16`.


Задача 2. У нас есть количество детей :math:`n=4`, вероятность рождения мальчика :math:`p = \dfrac{1}{2}`, поэтому вероятность рождения девочки :math:`q = 1-p = \dfrac{1}{2}`.

Ответ :math:`P_4(k=2) = C^2_4 \cdot \left(\dfrac{1}{2}\right)^2 \cdot \left(\dfrac{1}{2}\right)^2 = \dfrac{3}{8}`.


Задача 3. Пусть

- :math:`A` = { первый стрелок попадает в цель дважды }.
- :math:`B` = { второй стрелок попадает в цель дважды }.

У нас есть :math:`n_A = 4`, :math:`p_A = \dfrac{1}{3}`, поэтому :math:`q_A = 1 - p_A = \dfrac{2}{3}`, :math:`n_B = 3`, :math:`p_B = \dfrac{1}{2}`. Отсюда :math:`q_B = 1 - p_B = \dfrac{1}{2}`.

Поэтому, :math:`P(A) = P_4(k=2) = C^2_4 \cdot \left(\dfrac{1}{3}\right)^2 \cdot \left(\dfrac{2}{3}\right)^2 = \dfrac{8}{27}`.

:math:`P(B) = P_3(k=2) = C^2_3 \cdot \left(\dfrac{1}{2}\right)^2 \cdot \left(\dfrac{1}{2}\right) = \dfrac{3}{8}` так как :math:`P(B) > P(A)`, второго стрелка вероятнее.


Задача 4. Здесь у нас есть :math:`n=5`, вероятность узла :math:`p = 1 - 0,9 = 0,1`, и вероятность надежности :math:`q = 0,9`.

(a) :math:`P_5(k=1) = C^1_5 \cdot (0,1)^1 \cdot (0,9)^4 = 0,32805`.

(б) :math:`P_5(k \geqslant 1) = 1 - P_5(k=0) = 1 - C^0_5 \cdot (0,9)^5 \approx 0,4`.

(в) :math:`P_5(k \geqslant 2) = 1 - P_5(k=0) - P_5(k=1) = 1 - C^0_5 \cdot 0,9^5 - C^1_5 \cdot 0,1 \cdot 0,9^4 = 0,08146 \approx 0,08`.


Задача 5. У нас есть :math:`n = 100` и :math:`p=0,02` - мало, поэтому мы можем использовать формулу Пуассона с :math:`\lambda = np = 100 \cdot 0,02 = 2`.

(a) :math:`P_{100} (k=0) = \dfrac{e^{-2} \cdot 2^0}{0!} = e^{-2}`.

(б) :math:`P_{100} (k>2) = 1-P_{100} (k = 0) - P_{100} (k = 1) = 1 - \dfrac{e^{-2} \cdot 2^0}{0!} - \dfrac{e^{-2} \cdot 2^1}{1!} - \dfrac{e^{-2} \cdot 2^2}{2!} = 1 - 5e^{-2}`.

(в) :math:`P_{100} (k = k_0)`, мы используем :math:`k=0, 1, 2, \cdots` и видим, что :math:`k=2` наиболее. Поэтому ответ :math:`k_0 = 2`.


Задача 6. Пусть :math:`n` - количество изделий, чтобы с вероятностью не менее 0,95 обнаружить хотя бы одно изделие низкого качества

Здесь :math:`q = 1 - p = 0,9`, и мы хотем, чтобы :math:`P_n(k \geqslant 1) \geqslant 0,95`.

У нас есть


.. math::

   \begin{align*} P_n(k \geqslant 1) & = 1 - P_n(k = 0) = 1 (0,9)^n \geqslant 0,95 \\ & \Longleftrightarrow (0,9)^n \leqslant 0,05 \\ & \Longleftrightarrow n \ln{0,9} \leqslant \ln{0,05} \\ & \Longleftrightarrow n \geqslant \dfrac{\ln{0,05}}{\ln{0,9}} \\ & \Longleftrightarrow n \geqslant 28,43 \\ & \Longrightarrow n \geqslant 29 \end{align*}


Задача 7. В течение часа поступает в среднем 120 телефонных вызовов, значит в течение минуты :math:`\lambda = \dfrac{1 \cdot 120}{60} = 2` вызовов.

Поэтому ответ: :math:`P(k=3) = \dfrac{e^{-2} \cdot 2^3}{3!} = \dfrac{2e^{-2}}{3} \approx 0,09`


Задача 8. У нас есть :math:`n=400` и :math:`p=0,005` - мало, поэтому мы можем используем формулу Пуассона с :math:`\lambda = np = 2`.

Получим


.. math::

   \begin{align*} P_{400} (k > 2) & = 1 - P_{400}(k=0) - P_{400}(k=1) - P_{400}(k=2) & = 1 - \dfrac{e^{-2} \cdot 2^0}{0!} - \dfrac{e^{-2} \cdot 2^1}{1!} - \dfrac{e^{-2} \cdot 2^2}{2!} & = 1 - 5e^{-2} \approx 0,31
   \end{align*}


Задача 9.
У нас есть :math:`n=800` и :math:`p=0,0025` - вероятность цифра может быть принята неправильно.

Чтобы получить текст, все цифры будут приняты правильно, :math:`k=0` и :math:`\lambda = np = 800 \cdot 0,0025 = 2`.

Ответ: :math:`P_{800}(k=0) = \dfrac{e^{-2} \cdot 2^0}{0!} = e^{-2} \approx 0,136`


Задача 10. Мы знаем только один выстрел из 200 достигает цели, тогда при 100 выстрелах :math:`\lambda = 1 \cdot 100 : 200 = \dfrac{1}{2}`.

Ответ :math:`P_{100}(k \geqslant 1) = 1 - P_{100} (k = 0) = 1 - \dfrac{e^{\dfrac{-1}{2}} \cdot \left(\dfrac{1}{2}\right)^0}{0!} = 1 - e^{\dfrac{-1}{2} \approx 0,4}`


Задача 11. У нас есть :math:`n=50` и :math:`p=0,01` - мало, поэтому мы используем формулу Пуассона с :math:`\lambda = np = 0,5`.

Ответ :math:`P_{50} (k \geqslant 1) = 1 - P_{50} (k = 0) = 1 - \dfrac{e^{-0,5} \cdot (0,5)^0}{0!} = 1 - e^{-0,5} \approx 0,4`


Задача 12. Пусть :math:`A_i` = { монету 1 бросают герб :math:`i` раз }, и :math:`B_i` = { монету 2 бросают герб :math:`i` раз }.

:math:`C` = { у них выпадает одинаковое число гербов }

У нас есть :math:`C = \sum_{i=0}^{5} A_i B_i`

Мы образуем, что :math:`P_{A, 5}(k=k_0)` - вероятность того, что первая монета выпадает :math:`k_0` герб.

:math:`P_{B, 5}(k=k_0)` - вероятность того, что вторая монета выпадает :math:`k_0` герб.

Поэтому,.


.. math::

   \begin{align*} P(C) & = \sum_{i=0}^{5} P_{A, 5}(k=i) \cdot P_{B, 5}(k=i) & = \sum_{i=0}^{5} \left[C^i_5 \left(\dfrac{1}{2}\right)^i \cdot \left(\dfrac{1}{2}\right)^{5-i}\right] \cdot \left[C^i_5 \left(\dfrac{1}{2}\right)^i \cdot \left(\dfrac{1}{2}\right)^{5-i}\right] & = \sum_{i=0}^{5} \left[C^i_5 \left(\dfrac{1}{2}\right)^5\right]^2 = \dfrac{63}{256}
   \end{align*}


Задача 13. Пусть :math:`x` - количество раз частица двигается вправо и :math:`y` - количество раз частица двигается влево.

Тогда, место частицы равна :math:`x-y`.

Поэтому у нас есть.


.. math::

   \begin{align*} x - y \in [-2; 0] x + y = 5 x, y \in \mathbb{Z}\end{align*}


Среди { -2, -1, 0 }, мы получим цельные числа только когда -1. Значит
$\begin{cases}
x - y = -1.

x + y = 5
\end{cases}$

Получим :math:`x=2`, :math:`y=3`. Пусть :math:`A` = { через пять секунд частица двигается вправо 2 раза }.

Ответ :math:`P_5 (k = 2) = C^2_5 \left(\dfrac{1}{3}\right)^2 \cdot \left(\dfrac{2}{3}\right)^3 = \dfrac{80}{243}`


Задача 14. В биатлоне на каждом из трех огневых рубежей спортсмен должен поразить пять мишеней в пяти выстрелах. За каждую непораженную мишень спортсмен обязан пробежать штрафной круг. Пусть вероятность поражения мишени при одном выстреле равна 0,95. Какова вероятность того, что спортсмен все три огневых рубежа пройдет без штрафных кругов? какова вероятность того, что после каждого огневого рубежа спортсмен будет пробегать один штрафной круг?

(a) Пусть :math:`A_i` = { спортсмен пройдет без штрафной круг на :math:`i`-ом рубеже }

У нас есть :math:`P(A_1) = P(A_2) = P(A_3)`

.. math::

   \begin{align*}
   	\Longrightarrow P(A_1 A_2 A_3) & = P(A_1) P(A_2) P(A_3) = (P(A_1))^3.
   
   & = (P_5(k=0))^3 = [C^0_5 (0,95)^5]^3.
   
   & \approx 0,46
   \end{align*}

(б) Пусть :math:`B_i` = { спортсмен после :math:`i`-ого огневого рубежа будет пробегать один штрафной круг }.

У нас есть :math:`P(B_1) = P(B_2) = P(B_3)` и :math:`p=1-0,95=0,05`

.. math::

   \begin{align*}
   	\Longrightarrow P(B_1 B_2 B_3) & = P(B_1) P(B_2) P(B_3) = (P(B_1))^3.
   
   & = [P_5 (k=1)]^3 = [C^1_5 (0,05)^1 (0,95)^4]^3.
   
   & \approx 0,008
   \end{align*}


Задача 15.
Пусть :math:`A` = { к этому моменту у стрелка будет два промаха }

Мы знаем, что последний выстрел будет попадание. Среди первые 4 выстрела, там есть два промаха с вероятностью :math:`p=1-\dfrac{1}{3} = \dfrac{2}{3}`.

Поэтому,
.. math::

   \begin{align*}
   P(A) = \dfrac{1}{3} \cdot P_4(k=2) = \dfrac{1}{3} \cdot C^2_4 \cdot \left(\dfrac{2}{3}\right)^2 \cdot \left(\dfrac{1}{3}\right)^2 = \dfrac{8}{81}
   \end{align*}


Занятие 7
------------------------------------------------------------

Задача 1. Если :math:`x_1 = 1`, то только выбрать нужный ключ с вероятностью :math:`p_1 = P(X=1) = \dfrac{1}{5}`.

Если :math:`x_2 = 2`, то :math:`p_2 = P(X=2) = \dfrac{4}{5} \cdot \dfrac{1}{5}`.

Если :math:`x_3 = 3`, то :math:`p_3 = P(X=3) = \left(\dfrac{4}{5}\right)^2 \cdot \dfrac{1}{5}`.

И так далее.

Если :math:`x_n = n`, :math:`p_n = P(X=n) = \left(\dfrac{4}{5}\right)^{n-1} \cdot \dfrac{1}{5}`.

.. code-block:: text

   | :math:`X` | :math:`1` | :math:`2` | :math:`3` | :math:`\cdots` | :math:`n` | :math:`\cdots` |
   |-----|-----|-----|-----|----------|-----|----------|
   | :math:`P` | :math:`1/5` | :math:`(4/5) \cdot (1/5)` | :math:`(4/5)^2 \cdot (1/5)` | :math:`\cdots` | :math:`(4/5)^{n-1} \cdot (1/5)` | :math:`\cdots` |


Значит :math:`M(X) = \sum_{i=1}^{n} i \cdot \left(\dfrac{4}{5}\right)^{i-1} \cdot \dfrac{1}{5}`, когда :math:`n \Longrightarrow \infty`

Смотрим полином :math:`1 + x + x^2 + \cdots + x^n`. У нас есть


.. math::

   \begin{align*} 1 + x + x^2 + x^3 + \cdots + x^n & = \dfrac{x^{n+1} - 1}{x-1} \\ \Longleftrightarrow (1 + x + x^2 + x^3 + \cdots + x^n)' & = \left(\dfrac{x^{n+1} - 1}{x-1}\right)' \\ \Longleftrightarrow 0 + 1 + 2 \cdot x + 3 \cdot x^2 + \cdots + n \cdot x^{n-1} \\ & = \dfrac{(n+1) \cdot x^n \cdot (x-1) (x^{n+1}-1) \cdot 1}{(x-1)^2} \\ \Longleftrightarrow 1 + 2 \cdot x + 3 \cdot x^2 + \cdots + n \cdot x^{n-1} \\ & = \dfrac{n \cdot x^{n+1} (n+1) \cdot x^n + 1}{(x-1)^2} \end{align*}


Пусть :math:`x=4/5` и :math:`n \Longrightarrow \infty`, мы получим


.. math::

   \begin{align*} \lim_{n\to\infty} \sum_{i=1}^{n} i \cdot \left(\dfrac{4}{5}\right)^{i-1} \cdot \dfrac{1}{5} & = \dfrac{1}{5} \lim_{n\to\infty} i \cdot \left(\dfrac{4}{5}\right)^{i-1} \\ & = \dfrac{1}{5} \cdot \lim_{n\to\infty}\dfrac{n \cdot (4/5)^{n+1} (n+1) \cdot (4/5)^n + 1}{(4/5-1)^2} \end{align*}


И у нас есть.


.. math::

   \lim_{n\to\infty} n \cdot (4/5)^{n+1} = \lim_{n\to\infty} (n+1) \cdot (4/5)^n = 0,


поэтому


.. math::

   \dfrac{1}{5} \lim_{n\to\infty} \dfrac{n \cdot (4/5)^{n+1} (n+1) \cdot (4/5)^n + 1}{(4/5-1)^2} = \dfrac{1}{5} \cdot \dfrac{1}{(1/5)^2} = 5


Задача 2. На электронное реле воздействует случайное напряжение, имеющее плотность вероятности :math:`f(x) = \dfrac{x}{\sigma^2} \cdot \exp{ -\dfrac{x^2}{2\sigma^2} }`, :math:`x \geqslant 0`. Реле срабатывает всякий раз, когда напряжение на его входе превышает 3 В. Какова вероятность срабатывания реле?

У нас есть :math:`f(x) = \dfrac{x}{\sigma^2} \cdot \exp{ -\dfrac{x^2}{2\sigma^2} }`.

Поэтому


.. math::

   P(X > 3) = \int\limits_{3}^{+\infty} \dfrac{x}{\sigma^2} \cdot exp{ -\dfrac{x^2}{2\sigma^2} }\,dx.


Пусть :math:`t=\dfrac{x^2}{2\sigma^2} \Longrightarrow \,dt = \dfrac{x}{\sigma^2} \,dx`. Если :math:`x=+\infty \Longrightarrow t = +\infty` и если :math:`x=3 \Longrightarrow t = \dfrac{9}{2\sigma^2}`


.. math::

   \begin{align*}\int\limits_{3}^{+\infty} \dfrac{x}{2\sigma^2} \cdot \exp{ -\dfrac{x^2}{\sigma^2} } \,dt & = \int\limits_{9/(\sigma^2)}^{+\infty} e^{-t} \,dt. \\ & = -e^{-t} |^{+\infty}_{9/(2\sigma^2)}. \\ & = -e^{-\infty} + e^{-9/(2\sigma^2)}. \\ & = 0 + e^{-9/(2\sigma^2)}. \\ & = e^{-9/(2\sigma^2)} \end{align*}


Задача 3. Пусть :math:`x` - число монет по 10 копеек и :math:`y` - число монет по 50 копеек. Отсюда :math:`x + y = 4` и :math:`0 \leqslant x \leqslant 5, 0 \leqslant y \leqslant 3`.

Пусть :math:`X` - сумма вынутых копеек :math:`\Longrightarrow X = 10x + 50y`.

.. code-block:: text

   |   |     |     |    |    |
   |---|-----|-----|----|----|
   | x | 1   | 2   | 3  | 4  |
   | y | 3   | 2   | 1  | 0  |
   | X | 160 | 120 | 80 | 40 |


Отсюда, мы получим закон распределения случайной :math:`X`

.. code-block:: text

   |     |      |      |       |       |
   |-----|:----:|:----:|:-----:|:-----:|
   | :math:`X` | :math:`40` | :math:`80` | :math:`120` | :math:`160` |
   | :math:`P` | :math:`\dfrac{C^4_5 \cdot C^0_3}{C^4_8} = \dfrac{1}{14}` | :math:`\dfrac{C^3_5 \cdot C^1_3}{C^4_8} = \dfrac{3}{7}` | :math:`\dfrac{C^2_5} \cdot C^2_3{C^4_8} = \dfrac{3}{7}` | :math:`\dfrac{C^1_5 \cdot C^3_3}{C^4_8} = \dfrac{1}{14}` |



Задача 4.
:math:`f(x) = 0,002e^{-0,002x}` при :math:`x \geqslant 0`, :math:`f(x) = 0` при :math:`x < 0`

Найти функцию распределения:

1. При :math:`x < 0`

   
.. math::

   F(x) = P(X \leqslant 0) = \int\limits_{-\infty}^{0}f(x)\,dx = \int\limits_{-\infty}^{0}0\,dx = 0


2. При :math:`x \geqslant 0`

   
.. math::

   \begin{align*} F(x) = P(X \leqslant 0) & = \int\limits_{-\infty}^{x}f(x)\,dx. \\ & = \int\limits_{-\infty}^{0}0\,dx + \int\limits_{0}^{x}0,002e^{-0,002x}\,dx. \\ & = 0 + \int\limits_{0}^{x}e^{-0,002x}\,d(0,002x). \\ & = \left.-e^{-0,002x}\right|^{x}_{0}. \\ & = -e^{-0,002x} + e^{0}. \\ & = 1 - e^{-0,002x} \end{align*}


Вероятность того, что предохранитель безотказно проработает 1000 часов


.. math::

   F(x) = P(X \geqslant 1000) = F(+\infty) - F(1000) = 1 (1 - e^{-0,002 \cdot 1000}) = e^{-2}.


Задача 5. Пусть :math:`X` - сумма выпавших очков. Поэтому 


.. math::

   X \in { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }


- :math:`X=2=1+1`, выбрать очку 1 (первый кубик) и очку 1 (второй кубик).

  :math:`P(X=2) = \dfrac{1}{6} \cdot \dfrac{1}{6} = \dfrac{1}{36}`

- :math:`X=3=1+2=2+1`, выбрать очку 1 (первый кубик) и очку 2 (второй кубик), или обратно.

  :math:`P(X=3) = 2 \cdot \dfrac{1}{6} \cdot \dfrac{1}{6} = \dfrac{1}{18}`

- :math:`X=4=2+2=1+3=(3+1)`.

  :math:`P(X=4) = \dfrac{1}{6} \cdot \dfrac{1}{6} + 2 \cdot \dfrac{1}{6} \cdot \dfrac{1}{6} = \dfrac{1}{12}`

- :math:`X=5=2+3=(3+2)=1+4=(4+1)`.

  :math:`P(X=5) = \dfrac{1}{9}`

- И далее :math:`\cdots`

.. code-block:: text

   |     |     |     |     |     |     |     |     |     |      |      |        |
   |-----|-----|-----|-----|-----|-----|-----|-----|-----|------|------|------|
   | :math:`X` | :math:`2` | :math:`3` | :math:`4` | :math:`5` | :math:`6` | :math:`7` | :math:`8` | :math:`9` | :math:`10` | :math:`11` | :math:`12` |
   | :math:`P` | :math:`\dfrac{1}{36}` | :math:`\dfrac{1}{18}` | :math:`\dfrac{1}{12}` | :math:`\dfrac{1}{9}` | :math:`\dfrac{5}{36}` | :math:`\dfrac{1}{6}` | :math:`\dfrac{5}{36}` | :math:`\dfrac{1}{9}` | :math:`\dfrac{1}{12}` | :math:`\dfrac{1}{18}` | :math:`\dfrac{1}{36}` |


Математическое ожидание


.. math::

   M(\xi) & = 2 \cdot \dfrac{1}{36} + 3 \cdot \dfrac{1}{18} + \cdots + 12 \cdot \dfrac{1}{36} \\ & = 14 \cdot \left(\dfrac{1}{36} + \dfrac{1}{18} + \dfrac{1}{12} + \dfrac{1}{9} + \dfrac{5}{16}\right) + 7 \cdot \dfrac{1}{6} = 7.


Задача 6.
Чтобы выбирать шары до тех пор, пока не будет вынут черный шар, у нас есть 4 способа

- :math:`0` белых шара: :math:`A^0_3 C^1_2`;
- :math:`1` белый шар: :math:`A^1_3 C^1_2`;
- :math:`2` белых шара: :math:`A^2_3 C^1_2`;
- :math:`3` белых шара: :math:`A^3_3 C^1_2`.

Мы получим :math:`\lvert \Omega \rvert = A^0_3 C^1_2 + A^1_3 C^1_2 + A^2_3 C^1_2 + A^3_3 C^1_2 = 32`, и закон распределения с :math:`X` - количество белых шара

.. code-block:: text

   | :math:`X` | :math:`0` | :math:`1` | :math:`2` | :math:`3` |
   |-----|-----|-----|-----|-----|
   | :math:`P` | :math:`\dfrac{A^0_3 C^1_2}{32} = \dfrac{1}{16}` | :math:`\dfrac{A^1_3 C^1_2}{32} = \dfrac{3}{16}` | :math:`\dfrac{A^2_3 C^1_2}{32} = \dfrac{3}{8}` | :math:`\dfrac{A^3_3 C^1_2}{32} = \dfrac{3}{8}` |


Поэтому


.. math::

   M(\xi) = 0 \cdot \dfrac{1}{16} + 1 \cdot \dfrac{3}{16} + 2 \cdot \dfrac{3}{8} + 3 \cdot \dfrac{3}{8} = \dfrac{33}{16} \approx 2


Задача 7.

(a) Функция распределения величины :math:`X`

1. При :math:`x < 0`

   
.. math::

   F(x) = P(X \leqslant x) = \int\limits_{-\infty}^{x}0\,dx = 0

	
2. При :math:`x \in [0,\pi]`

   
.. math::

   \begin{align*} F(x) = P(X \leqslant x) & = \int\limits_{-\infty}^{x}f(x)\,dx. \\ & = \int\limits_{-\infty}^{0}0\,dx + \int\limits_{0}^{x}0,5\sin x\,dx. \\ & = 0 - 0,5\cos x\Big|^x_0 = -0,5(\cos x-\cos 0). \\ & = 0,5(1-\cos x) \end{align*}


3. При :math:`x > \pi`
	
   
.. math::

   \begin{align*} F(x) = P(X \leqslant x) & = \int\limits_{-\infty}^{x}f(x) \,dx. \\ & = \int\limits_{-\infty}^{0}0\,dx + \int\limits_{0}^{\pi}0,5\sin x\,dx + \int\limits_{\pi}^{x}0\,dx. \\ & = 0 + \int\limits_{0}^{\pi}0,5\sin x\,dx. \\ & = -0,5 \cos x \Big|^{\pi}_0. \\ & = -0,5(\cos \pi - \cos 0) = -0,5 (-1 - 1) = 1 \end{align*}


(б) математическое ожидание этой величины.

Так как :math:`f(x) = 0` при :math:`x \not\in [0, \pi]`, мы получим математическое ожидание :math:`M(\xi) = \int\limits_{0}^{\pi}x \cdot 0,5\sin x\,dx = 0,5 \int\limits_{0}^{\pi} x \sin x\,dx`.

Пусть :math:`u = x` и :math:`\sin x \,dx = \,dv \Longrightarrow \,du = \,dx` и :math:`-\cos x = v`. Поэтому


.. math::

   \begin{align*} \int\limits_{0}^{\pi} x \sin x\,dx & = -x \cos x \Big|^{\pi}_{0} - \int\limits_{0}^{\pi} -\cos x \,dx. \\ & = -(\pi \cos \pi - 0 \cos 0) + \int\limits_{0}^{\pi}\cos x\,dx. \\ & = \pi + \sin x \Big|^{\pi}_{0} = \pi
   \end{align*}


.. math::

   \Longrightarrow 0,5 \int\limits_{0}^{\pi}x \sin x\,dx = 0,5 \pi = \pi/2


(в) Вероятность попадания в интервал :math:`[0, \pi/3]`.

:math:`P(0 \leqslant \xi \leqslant \pi/3) = F(\pi/3) - F(0) = 0,5(1-\cos \dfrac{\pi}{3}) - 0,5(1-\cos 0) = \dfrac{1}{4}`


Задача 8. Пусть :math:`X` - количество раз бросают монету. У нас есть:

- :math:`X=1`: выпадение герба. :math:`P(X=1) = \dfrac{1}{2}`
- :math:`X=2`: цифр - герб. :math:`P(X=2) = \dfrac{1}{2^2}`
- :math:`X=3`: цифр - цифр - герб. :math:`P(X=3) = \dfrac{1}{2^3}`
- :math:`X=4`: цифр - цифр - цифр - герб, либо цифр четыре раза ...

:math:`P(X=4) = 2 \cdot \dfrac{1}{2^4} = \dfrac{1}{2^3}`

:math:`M(\xi) = 1 \cdot \dfrac{1}{2} + 2 \cdot \dfrac{1}{2^2} + 3 \cdot \dfrac{1}{2^3} + 4 \cdot \dfrac{1}{2^3} = \dfrac{15}{8}`


Задача 9. :math:`f(x) = \dfrac{1}{\pi} \cdot \dfrac{1}{1+x^2}`. За один раз


.. math::

   \begin{align*} P(-1 < x < 1) & = \int\limits_{-1}^{1}f(x)\,dx = \int\limits_{-1}^{1}\dfrac{1}{\pi} \cdot \dfrac{1}{1+x^2} \,dx. \\ & = \dfrac{1}{\pi} \cdot \arctan x\Big|^{1}_{-1} = \dfrac{1}{\pi} \cdot \left(\dfrac{\pi}{4} - \dfrac{-\pi}{4}\right) = \dfrac{1}{2} \end{align*}


Отсюда, вероятность того, что при трех независимых наблюдения этой случайной величины


.. math::

   P = \left(\dfrac{1}{2}\right)^3 = \dfrac{1}{8}.


Задача 10. Случайная величина :math:`X` - погрешность измерительного прибора распределена по нормальному закону распределения с дисперсией :math:`\sigma^2 = 25` м:math:`B^2`. Систематическая погрешность прибора отсутствует. Найдите вероятность того, что при пяти независимых измерениях ошибка измерения хотя бы один раз превзойдет по модулю 10 мВ

Пусть :math:`A` = { при пяти независимых измерениях ошибка измерения хотя бы один раз превзойдет по модулю 10 мВ }.

:math:`\Longrightarrow \overline{A}` = { при пяти раз нет ошибки }

Используем :math:`P(|X - m| < \alpha) = 2 \Phi\left(\dfrac{\alpha}{\sigma}\right)`. Здесь :math:`\alpha=10` и :math:`\sigma^2 = 25`.

:math:`\Longrightarrow P(|X-m| < 10) = 2 \Phi \left(\dfrac{10}{5}\right) = 2 \cdot 0,4773 = 0,9546`

Отсюда :math:`P(A) = 1 - P(\overline{A}) = 1 - 0,9546^5 \approx 0,21`.


Задача 11. :math:`\sigma = 20`, :math:`\alpha=50`.


.. math::

   P(|X - m| < 50) = 2 \cdot \Phi \left(\dfrac{50}{20}\right) = 2 \cdot 0,4938 = 0,9876.


Задача 12. :math:`\varphi(z) = M[\cos(zX) + i\sin(zX)]`.

У нас есть :math:`P(X=1) = \dfrac{1}{2}` и :math:`P(X=-1) = \dfrac{1}{2}`.


.. math::

   \Longrightarrow \varphi(z) = \dfrac{1}{2} \cdot [\cos(z \cdot 1) + i \sin(z \cdot 1)] + \dfrac{1}{2} \cdot [\cos(z \cdot (-1)) + i\sin(z \cdot (-1))] = \dfrac{1}{2} \cdot (\cos z + \cos(-z) + i[\sin z + \sin(-z)]).


Но :math:`\cos(z) = \cos(-z)` и :math:`\sin(-z) = -\sin(z)`.


.. math::

   \Longrightarrow \varphi(z) = \dfrac{1}{2} \cdot (\cos z + \cos z) = \cos z.


Задача 13. Так как случайная величина равномерно распределена отрезке :math:`[a, b]`, у нас есть её функция плотности вероятности :math:`f(x) = \dfrac{1}{b-a}`.

Поэтому, характеристическая функция


.. math::

   \begin{align*} \varphi(z) & = \int\limits_{a}^{b} e^{izx}\,dF(x). \\ & = \int\limits_{a}^{b} e^{izx} \cdot f(x) \,dx. \\ & = \dfrac{1}{b-a} \int\limits_{a}^{b} e^{izx} \,dx. \\ & = \dfrac{1}{b-a} \cdot \left.\dfrac{e^{izx}}{iz}\right|^{b}_{a}. \\ & = \dfrac{1}{b-a} \cdot \dfrac{e^{biz} - e^{aiz}}{iz} \end{align*}


Задача 14. :math:`P(X=k) = \dfrac{\lambda^k \cdot e^{-\lambda}}{k!}` , :math:`k=0,1,2,\cdots`.

У нас есть :math:`\psi(z) = M(z^X)=\sum_{k=0}^{\infty}p_k x^k = \sum_{k=0}^{\infty} \dfrac{e^{-\lambda} \cdot \lambda^k \cdot z^k}{k!}`,


.. math::

   \begin{align*} \Longrightarrow \psi'(z) & = e^{-\lambda} \left[\dfrac{\lambda^k \cdot k z^{k-1}}{k!} + \dfrac{\lambda^{k-1} \cdot (k-1) z^{k-2}}{(k-1)!} + \cdots + \dfrac{\lambda^1 \cdot 1 \cdot z^0}{1!} + 0\right] \\ & = e^{-\lambda} \cdot \lambda \left[\dfrac{(\lambda z)^{k-1}}{(k-1)!} + \dfrac{(\lambda z)^{k-2}}{(k-2)!} + \cdots + \dfrac{(\lambda z)^0}{0!}\right] \\ & = e^{-\lambda} \cdot \lambda \cdot e^{\lambda z}. \end{align*}


:math:`\Longrightarrow M(X) = \psi'(1) = e^{-\lambda} \cdot \lambda \cdot e^{\lambda} = \lambda`

Аналогично, мы получим :math:`\psi''(1)= \lambda^2` и :math:`D(X) = \psi''(1) + \psi'(1) (\psi'(1))^2 = \lambda^2 + \lambda - \lambda^2 = \lambda`


Занятие 8
------------------------------------------------------------

Задача 1. :math:`Y=(X-1)^2`

- :math:`X=-1 \Longrightarrow Y=4`;
- :math:`X=0 \Longrightarrow Y=1`;
- :math:`X=2 \Longrightarrow Y=1`;
- :math:`X=3 \Longrightarrow Y=4`.

:math:`\Longrightarrow P(Y=1) = P(X=0)+P(X=2)=0,4+0,3=0,7`.

:math:`P(Y=4) = P(X=-1) + P(X=3)=0,1+0,2=0,3`

Мы получим закон распределения

.. code-block:: text

   | :math:`Y` | :math:`1`   | :math:`4`   |
   |-----|-------|-------|
   | :math:`P` | :math:`0,7` | :math:`0,3` |



Задача 2. :math:`f(x) = \dfrac{1}{b-a}`, :math:`0 < a \leqslant x \leqslant b` и :math:`Y=X^2`.


.. math::

   \Longrightarrow x=\sqrt{y}, a^2 \leqslant y \leqslant b^2.


Плотность вероятности случайной величины :math:`Y`:


.. math::

   g(y) = \dfrac{1}{b-a} \cdot \left|(\sqrt{y})'\right| = \dfrac{1}{2(b-a)\cdot \sqrt{y}}, a^2 \leqslant y \leqslant b^2.


Задача 3. :math:`f(x) = \dfrac{x}{\sigma^2} \exp{-\dfrac{x^2}{2\sigma^2}}`, :math:`x \geqslant 0` и :math:`Y=\sigma/X`.

:math:`\Longrightarrow x=\sigma/y` и :math:`y > 0`. Поэтому плотность распределения случайной величины :math:`Y`:


.. math::

   g(y) = \dfrac{\sigma}{y\sigma^2} \exp\left(-\dfrac{\sigma^2}{y^2 \cdot 2 \sigma^2}\right) \left|\left(\dfrac{\sigma}{y}\right)'\right| = \dfrac{1}{y \sigma} \exp\left(-\dfrac{1}{2y^2}\right) \cdot \dfrac{\sigma}{y^2} = y^{-3} \exp\left(-\dfrac{1}{2y^2}\right).


Задача 4. Мы обозначим через :math:`X` угол между осью абсцисс и направлением из начала координат на точку касания. Мы получим длину от точки касания до точки ее пересечения с осью :math:`Ox`: :math:`H=AC=\tg X`, :math:`x \in [0, \pi/2]`

.. figure:: probability/exercise4-8.png

У нас есть :math:`H = \tg X`, :math:`x \in [0, \pi/2]`. Следовательно, :math:`X` имеет равномерное на :math:`[0, \pi/2]` распределения с функцией плотности вероятности :math:`f(x)=\dfrac{2}{\pi}`. Поэтому :math:`x = \arctg h`, :math:`h \geqslant 0`.

Мы получим :math:`g(h)=\dfrac{2}{\pi} \cdot \left|(\arctg h)'\right| = \dfrac{2}{\pi \sqrt{1+h^2}}`, :math:`h > 0`.

При :math:`h \leqslant 0`, :math:`F(h) = \int\limits_{-\infty}^{h}0\,dh = 0`.

При :math:`h > 0`, :math:`F(h) = \int\limits_{-\infty}^{h}g(h)\,dh = \int\limits_{0}^{h}\dfrac{2}{\pi \sqrt{1+h^2}}\,dh = \dfrac{2}{\pi} \cdot \arctg h`.


Задача 5. Случайная величина :math:`X` равномерно распределения на отрезке :math:`[0, 1]`, поэтому функция плотности вероятности :math:`f(x) = 1`.

У нас есть :math:`Y=\ln(1/X) \Longrightarrow y=\varphi(x)=\ln(1/x) \Longrightarrow e^y = 1/x \Longrightarrow x = 1/e^y`, :math:`y \geqslant 0`.

Функция плотности вероятности случайной величины :math:`Y`:


.. math::

   g(h) = 1 \cdot \left|(1/e^y)'\right| = 1/e^y.


Тогда функция распределения:

При :math:`y<0`, :math:`F(y)=0`.

При :math:`y \geqslant 0`, :math:`F(y) = \int\limits_{-\infty}^{y}\,dy = \int\limits_{0}^{y}1/e^y\,dy = -e^{-y}\left.\right|^y_0=-e^{-y} + e^0 = 1 - e^{-y}`.


Задача 6. :math:`Y = X^2-X+1`.

- :math:`X=1`, :math:`Y=1^2-1+1=1`
- :math:`X=2`, :math:`Y=2^2-2+1=3`
- :math:`X=4`, :math:`Y=4^2-4+1=13`

.. code-block:: text

   | :math:`Y` | :math:`1`   | :math:`3`   | :math:`13`  |
   |-----|-------|-------|-------|
   | :math:`P` | :math:`0,3` | :math:`0,5` | :math:`0,2` |


Математическое ожидание :math:`M\xi = 1 \cdot 0,3 + 3 \cdot 0,5 + 13 \cdot 0,2 = 4,4`.


Задача 7. Так как :math:`X` - число выпавших гербов при трех подбрасываниях монеты, вероятность равна по формуле Бернулли с :math:`n=3`, :math:`p=1/2`

- :math:`X=0`, :math:`P_3(X=0) = C^0_3 (1/2)^0 \cdot (1/2)^3=1/8` и :math:`Y=X^2=0`;
- :math:`X=1`, :math:`P_3(X=1) = C^1_3 (1/2)^1 \cdot (1/2)^2 = 3/8` и :math:`Y=X^2=1`;
- :math:`X=2`, :math:`P_3(X=2) = C^2_3 (1/2)^2 \cdot (1/2)^1 = 3/8` и :math:`Y=X^2=4`;
- :math:`X=3`, :math:`P_3(X=3) = C^1_3 (1/2)^3 \cdot (1/2)^0 = 1/8` и :math:`Y=X^2=9`.

Математическое ожидание случайной величины :math:`Y`


.. math::

   M\xi = 0 \cdot (1/8) + 1 \cdot (3/8) + 4 \cdot (3/8) + 9 \cdot (1/8) = 3


Задача 8. Случайная величина :math:`X` равномерно распределения на отрезке :math:`[0, 1] \Longrightarrow` функция распределения :math:`f(x)=1`

Мы найдем область значений :math:`y=\varphi(x)`

:math:`Y=\sin(\pi X) \Longrightarrow y = \varphi(x) = \sin(\pi x) \Longrightarrow y' = \pi\cos(\pi x)`

Если :math:`y'=0 \Longleftrightarrow \pi\cos(\pi x)=0 \Longleftrightarrow \pi x = \pi/2 \Longleftrightarrow x = 1/2`

.. figure:: probability/prac08-exec08.svg

Поэтому :math:`y \in [0,1]` и.


.. math::

   x = \begin{cases} \dfrac{\arcsin y}{\pi} & \text{, при } x \in [0,1/2] \\ \dfrac{\pi - \arcsin y}{\pi} & \text{, при } x \in [1/2, 1] \end{cases}


Функция плотности вероятности случайной величины :math:`Y`:

.. math::

   g(y) = 1 \cdot \left|\left(\dfrac{\arcsin y}{\pi}\right)'\right| + 1 \cdot \left|\left(\dfrac{\pi - \arcsin y}{\pi}\right)'\right| = \dfrac{2}{\pi \sqrt{1-y^2}}.


Математическое ожидание


.. math::

   M\xi = \int\limits_{0}^{1}y \cdot \dfrac{2}{\pi \sqrt{1-y^2}} \,dy = \int\limits_{0}^{1} \dfrac{-1}{\pi \sqrt{1-y^2}}\,d(1-y^2) = \left.\dfrac{-2\sqrt{1-y^2}}{\pi}\right|^1_0 = \dfrac{2}{\pi}.


Задача 9. :math:`f(x)=0,5\sin x` при :math:`x \in [0, \pi]` и :math:`f(x)=0` при остальных :math:`x`.

У нас есть :math:`Y = 2X \Longrightarrow y = \varphi(x) = 2x \Longrightarrow x = y/2` при :math:`y \in [0, 2\pi]`.

Функция плотности вероятности равна

:math:`g(y) = 0,5\sin (y/2) \cdot \left|(y/2)'\right|=0,25 \sin(y/2)` при :math:`y \in [0, 2\pi]` и :math:`f(y)=0` при остальных :math:`y`.

Математическое ожидание.


.. math::

   \begin{align*} M\xi & = \int\limits_{-\infty}^{+\infty}y \cdot g(y)\,dy \\ & = \int\limits_{0}^{2\pi} 0,25 y\sin(y/2)\,dy \\ & = 0,25 \int\limits_{0}^{2\pi} y (-2\cos(y/2))' \,dy \\ & = 0,25 \left(\left.-2y \cos(y/2)\right|^{2\pi}_0 - \int\limits_{0}^{2\pi}1 \cdot (-2\cos(y/2)\,dy)\right) \\ & = 0,25\left(4\pi + \left. 4\sin(y/2) \right|^{2\pi}_0\right) \\ & = 0,25\left(4\pi + 0\right) = \pi \end{align*}


Задача 10. :math:`f(x)=\dfrac{1}{\sqrt{2\pi}} e^{-x^2/2}`, при :math:`x \in \mathbb{R}`.

У нас есть :math:`Y=\dfrac{1}{2} X^2 \Longrightarrow |x|=\sqrt{2y}` и :math:`y \geqslant 0`.

1. При :math:`x<0`, :math:`x = x_1(y) = -\sqrt{2y}`
2. при :math:`x\geqslant 0`, :math:`x = x_2(y) = \sqrt{2y}`

Функция плотности вероятности


.. math::

   \begin{align*} g(y) & = f(x_1(y))\cdot \left|(-\sqrt{2y})'\right| + f(x_2(y)) \cdot \left|(\sqrt{2y})'\right|. \\ & = \dfrac{1}{\sqrt{2\pi}}e^{-y} \cdot \left|\dfrac{-1}{\sqrt{2y}}\right| + \dfrac{1}{\sqrt{2\pi}}e^{-y} \cdot \left|\dfrac{1}{\sqrt{2y}}\right|. \\ & = \dfrac{2}{\sqrt{2\pi} \cdot \sqrt{2y}} e^{-y} = \dfrac{1}{\sqrt{\pi y}} e^{-y} \end{align*}


Задача 11. :math:`f(x) = \lambda e^{-\lambda x}`, :math:`\lambda > 0`, :math:`x \geqslant 0`.

У нас есть :math:`Y=\varphi(x)`, где :math:`\varphi (x)=0,5x` при :math:`x \in [0,4]` и :math:`\varphi \equiv 2` при :math:`x \in (4, +\infty)`.

1. При :math:`x \in [0, 4]`, :math:`x=x(y)=2y`, :math:`y \in [0,2]`
2. При :math:`x \in (4, +\infty)`, :math:`y \equiv 2`

Поэтому :math:`y=0` при :math:`y \not\in [0, 2]` и если :math:`y=2 \Longrightarrow x=4`.


.. math::

   \Longrightarrow P(Y=2) = \int\limits_{4}^{+\infty} \lambda e^{-\lambda x}\,dx = -e^{-\lambda x}\Big|^{+\infty}_4 = 0 + e^{-4\lambda}.


.. math::

   g(y) = f(x(y)) \left|(2y)'\right| + P(Y=2) \cdot \delta(y-2) = 2 \lambda e^{-2\lambda y} + e^{-4\lambda}\delta(y-2).


Задача 12. :math:`f(x)=\dfrac{1}{\sqrt{2\pi}}\exp\left(-\dfrac{x^2}{2}\right)`.

У нас есть :math:`Y=\varphi(X)`, где :math:`\varphi(x)=0` при :math:`x<0` и :math:`\varphi(x) = 2x` при :math:`x \geqslant 0`.

:math:`P(Y=0) = P(-\infty < X < 0) = \dfrac{1}{2}` (свойства стандартного нормального распределения).

У нас также есть: при :math:`x \geqslant 0`, :math:`x = \dfrac{y}{2}`

Поэтому


.. math::

   \begin{align*} g(y) & = \dfrac{1}{\sqrt{2\pi}}\exp\left(-\dfrac{y^2}{4 \cdot 2}\right) \cdot \left|\left(\dfrac{y}{2}\right)'\right| + P(Y=0) \cdot \delta(y-0). \\ & = \dfrac{1}{2\sqrt{2\pi}} \exp\left(-\dfrac{y^2}{8}\right) + \dfrac{1}{2} \delta(y) \end{align*}


Занятие 9
------------------------------------------------------------

Задача 1.

.. code-block:: text

   | :math:`X` | :math:`Y` | :math:`Z` | :math:`P` |
   |-----|-----|-----|-----|
   | :math:`2` | :math:`4` | :math:`6` | :math:`0,3 \cdot 0,4 = 0,12` |
   | :math:`2` | :math:`5` | :math:`7` | \multirow{2}{*}{:math:`0,3 \cdot 0,4 + 0,7 \cdot 0,4 = 0,46`} |
   | :math:`3` | :math:`4` | :math:`7` |     |
   | :math:`3` | :math:`5` | :math:`8` | :math:`0,7 \cdot 0,6 = 0,42` |


.. code-block:: text

   | :math:`Z` | :math:`6`    | :math:`7`    | :math:`8`    |
   |-----|--------|--------|--------|
   | :math:`P` | :math:`0,12` | :math:`0,46` | :math:`0,42` |



.. math::

   \Longrightarrow M(Z) = 6 \cdot 0,12 + 7 \cdot 0,46 + 8 \cdot 0,42 = 7,3.


Задача 2.


.. math::

   f(x) = \begin{cases} \lambda e^{-\lambda x} \text{ при } x \geqslant 0 \\ 0 \text{ при } x < 0 \end{cases}.


.. math::

   Z = X+Y \Longrightarrow f(z) = \int\limits_{-\infty}^{+\infty}f_1(x) f_2(z-x)\,dx.


При :math:`z \geqslant 0 \Longrightarrow f(z) = \int\limits_{0}^{z}\lambda e^{-\lambda x} \cdot \lambda e^{-\lambda (z-x)}\,dx = \int\limits_{0}^{z}\lambda^2 e^{-\lambda z}\,dx = \lambda^2 e^{-\lambda z}` \\

При :math:`z < 0`, :math:`f(z) = 0`.


Задача 3.

:math:`Z=2X-Y+5`, :math:`M(X)=3`, :math:`M(Y)=5`, :math:`D(X)=2`, :math:`D(Y)=1`

:math:`M(Z)=2M(X)-M(Y)+5=6`

:math:`D(Z)=D(2X)+D(Y)=4D(X)+D(Y)=9=\sigma^2 \Longrightarrow \sigma=3`


Задача 4. :math:`X` и :math:`Y` независимы. :math:`f_1(x) = f_2(y) = \dfrac{1}{2}`. :math:`X, Y \sim U(0, 2)`. :math:`Z=X+Y`.

При :math:`0 \leqslant z < 2`, :math:`f(z) = \int\limits_{0}^{z}\dfrac{1}{2} \cdot \dfrac{1}{2}\,dx = \dfrac{z}{4}`.

При :math:`2 \leqslant z < 4`, :math:`f(z) = \int\limits_{z-2}^{2}\dfrac{1}{2} \cdot \dfrac{1}{2}\,dx = \dfrac{1}{4}(2-z+2) = 1-0,25z`.

При остальных :math:`z`, :math:`f(z) = 0`.


Задача 6. Св :math:`X` и :math:`Y` независимы, равномерно на :math:`(0, 1)`. :math:`Z=Y/X^2`

У нас есть :math:`F(z) = P(Z \leqslant z) = P(Y/X^2 \leqslant z)`, :math:`y/x^2\leqslant z \Longleftrightarrow y \leqslant zx^2`.

1. При :math:`z \leqslant 0`, :math:`f(z)=0`
2. При :math:`0 < z \leqslant 1`, :math:`F(z) = \int\limits_{0}^{1}\,dx\int\limits_{0}^{zx^2}\,dy = \int\limits_{0}^{1}zx^2\,dx = \dfrac{z}{3}`.

   
.. math::

   \Longrightarrow f(z) = \dfrac{1}{3}.


3. При :math:`z > 1`, :math:`y \leqslant zx^2 \Longrightarrow x \geqslant \sqrt{\dfrac{y}{z}}`.

   
.. math::

   \Longrightarrow F(z) = \int\limits_{0}^{1}\,dy \int\limits_{\sqrt{y/z}}^{1}\,dx = \int\limits_{0}^{1}(1 - \sqrt{\dfrac{y}{z}})\,dy=1-\dfrac{2}{3\sqrt{z}}.


   :math:`\Longrightarrow f(z) = 1/(3z^{1,5})`


Задача 7. :math:`U = min(X, Y)`.

1. При :math:`u < 0`, :math:`F(u)=0`
2. При :math:`0 \leqslant u < 1`, :math:`F(u) = P(min(X, Y) \leqslant u) = 1 - P(min(X, Y) > u) = 1 - \int\limits_{u}^{1}\int\limits_{u}^{1}\,dx\,dy = 2u-u^2`
3. При :math:`u>1`, :math:`F(u)=1`

:math:`\Longrightarrow M(U) = \int\limits_{0}^{1}u(2-2u)\,du=1/3`

:math:`\Longrightarrow D(U) = \int\limits_{0}^{1}(u-\dfrac{1}{3})^2(2-2u)\,du = 1/18`

:math:`V=max(X, Y)`

1. При :math:`v < 0`, :math:`F(v) = 0`.
2. При :math:`0 \leqslant v < 1`, :math:`F(v) = P(max(X, Y) \leqslant v) = \int\limits_{0}^{v}\int\limits_{0}^{v}\,dx\,dy = v^2 \Longrightarrow f(v) = 2v`.
3. При :math:`v > 1`, :math:`F(v)=1`

:math:`\Longrightarrow M(v) = \int\limits_{0}^{1}v\cdot 2v\,dv = 2/3`

:math:`\Longrightarrow D(v) = \int\limits_{0}^{1}(v-\dfrac{2}{3})^2\cdot 2v\,dv = 1/18`


Задача 9. Площадь треугольника :math:`ABC` равна 1 :math:`\Longrightarrow f(x, y) = 1`.

Так как :math:`y \leqslant \dfrac{x}{2}`,


.. math::

   0 \leqslant y \leqslant \dfrac{x}{2} \ \text{и} \ 2y \leqslant x \leqslant 2.


.. math::

   f_1(x) = \int\limits_{0}^{x/2}1\,dy = \dfrac{2}{x}, f_2(y) = \int\limits_{2y}^{2}1\,dx = 2-2y.


.. math::

   \begin{array}{ccl} M(X) & = & \int\limits_{0}^{2}x \cdot \dfrac{x}{2}\,dx = \dfrac{4}{3} \\ M(X^2) & = & \int\limits_{0}^{2}x^2 \cdot \dfrac{x}{2}\,dx = 2 \\ M(Y) & = & \int\limits_{0}^{1}y(2-2y)\,dy = \dfrac{1}{3} \\ M(Y^2) & = & \int\limits_{0}^{1}y^2(2-2y)\,dy = \dfrac{1}{6} \\ M(\overset{\circ}{X} \cdot \overset{\circ}{Y}) & = & \int\limits_{0}^{2}\,dx\int\limits_{0}^{x/2}(x-\dfrac{4}{3})(y-\dfrac{1}{3})\,dy = \cdots = \dfrac{1}{18} \\ \sigma_x^2 & = & M(X^2)-M(X)^2=2-\dfrac{16}{9}=\dfrac{2}{9} \\ \sigma_y^2 & = & M(Y^2)-M(Y)^2=\dfrac{1}{6} - \dfrac{1}{9} = \dfrac{1}{18}.\end{array}


Отсюда :math:`r_{xy} = \dfrac{1}{2}`.

Линия регрессии: :math:`\dfrac{y-1/3}{\sigma_y} = r_{xy}\dfrac{x-4/3}{\sigma_x}`, или :math:`y = \dfrac{x}{4}`.


Задача 11. :math:`f(x) \Longrightarrow g(y)`, :math:`Y = min(X, X^2)`. У нас есть

1. При :math:`x<0` или :math:`x \geqslant 1`, :math:`min(X, X^2)=X`
2. При :math:`0 \leqslant x < 1`, :math:`min(X, X^2)=X^2`

Поэтому


.. math::

   G(y) = P(Y \leqslant y) = P(min(X, X^2) \leqslant y).


1. При :math:`y < 0`, :math:`G(y) = P(X \leqslant y) = \int\limits_{-\infty}^{y}f(x)\,dx = F(y) \Longrightarrow g(y)=f(y)`
2. При :math:`0 \leqslant y < 1`, :math:`G(y) = P(X^2 \leqslant y) = P(X \leqslant \sqrt{Y}) = \int\limits_{0}^{\sqrt{y}}f(x)\,dx = F(\sqrt{y}) \Longrightarrow g(y) = f(\sqrt{y})(\sqrt{y})'=\dfrac{f(\sqrt{y})}{2\sqrt{y}}`
3. При :math:`y \geqslant 1`, :math:`G(y) = P(X \leqslant y) = \int\limits_{1}^{y}f(x)\,dx = F(y) \Longrightarrow g(y)=f(y)`


Задача 12. :math:`X_1, X_2 \Longrightarrow f(x_1, x_2) = \dfrac{2}{\pi^2(x_1^2+1)(x_2^2+4)}`, :math:`g(y_1, y_2) \Longrightarrow Y_1, Y_2`, :math:`X_1 = \tg(Y_1)`, :math:`X_2 = 2 \tg(Y_2)`, :math:`| Y_1 | < \pi / 2`, :math:`|Y_2| < \pi/2`

При :math:`|y_1| < \pi/2`, :math:`|y_2| < \pi/2`


.. math::

   G(y_1, y_2) & = P(Y_1 \leqslant y_1, Y_2 \leqslant y_2) \\ & = P(\arctg(X_1) \leqslant y_1, \arctg\left(X_2 / 2\right) \leqslant y_2) \\ & = P(X_1 \leqslant \tg(y_1), X_2 \leqslant 2 \tg(y_2)) \\ & = \int\limits_{-\infty}^{\tg y_1}\int\limits_{-\infty}^{2\tg y_2}\dfrac{2\,dx_1\,dx_2}{\pi^2(x_1^2+1)(x_2^2+4)} \\ & = \int\limits_{-\infty}^{\tg y_1}\,dx_1 \cdot \dfrac{2}{\pi^2(x_1^2+1)} \cdot \dfrac{1}{2} \left.\arctg\left(\dfrac{x_2}{2}\right)\right|^{2\tg y_2}_{-\infty} \\ & = \int\limits_{-\infty}^{\tg y_1}\left(y_2 + \dfrac{\pi}{2}\right)\dfrac{\,dx_1}{\pi^2(x_1^2+1)} \\ & = \dfrac{1}{\pi^2}\left(y_1 + \dfrac{\pi}{2}\right)\left(y_2 + \dfrac{\pi}{2}\right).


Отсюда


.. math::

   g(y_1, y_2) = \dfrac{\partial^2G(y_1, y_2)}{\partial y_1 \partial y_2} = \dfrac{1}{\pi^2}.


При остальных :math:`y_1`, :math:`y_2`, :math:`g(y_1, y_2) = 0`.


Занятие 10
------------------------------------------------------------

Задача 3.

(a) У нас есть :math:`0,4 < k/n < 0,6 \Longrightarrow |k/n-0,5| < 0,1 \Longrightarrow P(|k/n-0,5|<0,1) > 0,9`.

:math:`\Longrightarrow 2\Phi_0\left(\dfrac{0,1}{\sqrt{0,5 \cdot 0,5/n}}\right) > 0,9`.

:math:`\Longleftrightarrow \Phi_0\left(\dfrac{0,1\sqrt{n}}{0,5}\right) > 0,45`.

:math:`\Longleftrightarrow 0,2\sqrt{n} > 1,65 \Longrightarrow n > 68,0625`. Значит больше :math:`68`.

(б) :math:`P(|k/n<0,5|<0,1) \geqslant 1 - \dfrac{0,25}{0,1^2 n} = 0,9 \Longleftrightarrow n \geqslant 250`. Значит больше :math:`250`.


Задача 4. Пусть :math:`X_i` - время :math:`i`-го.

:math:`\sum_{i=1}^{20}X_i` - сумма времени

:math:`y = \dfrac{1}{20} \sum_{i=1}^{20}X_i`.

:math:`M\left(\dfrac{1}{20}\sum_{i=1}^{20}X_i\right)=\dfrac{1}{20}\cdot 20 \cdot \dfrac{1}{\lambda} = 100`.

:math:`D\left(\dfrac{1}{20}\sum_{i=1}^{20}X_i\right) = \dfrac{1}{20^2} \cdot 20 \cdot \dfrac{1}{\lambda^2} = 500`.

:math:`\dfrac{1}{20}\sum_{i=1}^{20}X_i \geqslant 2500/20 = 125`.

:math:`P\left(y \geqslant \dfrac{125-100}{\sqrt{500}}\right) = P(y \geqslant 1,12) = 0,5 - \Phi_0(1,12) = 0,1314`


Задача 5.
:math:`p=0,1`, :math:`n=50`, :math:`q=0,9`.

:math:`P(X \leqslant 3) = P(0 \leqslant X \leqslant 3) = \Phi_0(\dfrac{3-50 \cdot 0,1}{\sqrt{50 \cdot 0,1 \cdot 0,9}}) - \Phi_0(\dfrac{0-50 \cdot 0,1}{\sqrt{50 \cdot 0,1 \cdot 0,9}}) = \Phi_0(-0,94) - \Phi_0(-2,36) = 0,1645 \approx 0,16`


Задача 6. :math:`p=0,8`, :math:`q=0,2`, :math:`n=100`

(a) :math:`P_{100}(75 \leqslant k \leqslant 100) = \Phi_0\left(\dfrac{100-100\cdot 0,8}{\sqrt{100\cdot 0,8\cdot 0,2}}\right)-\Phi_0\left(\dfrac{75-100\cdot 0,8}{\sqrt{100\cdot 0,8\cdot 0,2}}\right) = \Phi_0(5)-\Phi_0(-1,25) = 0,8944`.

(б) :math:`P_{100}(70 \leqslant k \leqslant 90) = \Phi_0(2,5) - \Phi_0(-2,5) = 0,9876`.

(в) :math:`P_{100}(0 \leqslant k \leqslant 82) = \Phi_0(0,5) - \Phi_0(-20) = 0,1915 + 0,5 = 0,6915`.


Занятие 11
------------------------------------------------------------

Задача 1. :math:`M(X) = 5,5`, :math:`D(X) = 6,3`.


Задача 2. :math:`M(X) = 12`, :math:`D(X) = 12,97`.


Задача 3.


.. math::

   L & = \dfrac{x_1^{m-1}\lambda^m}{(m-1)!}\cdot e^{-\lambda x_1} \cdot \dfrac{x_2^{m-1}\lambda^m}{(m-1)!}\cdot e^{-\lambda x_2} \cdots \dfrac{x_n^{m-1}\lambda^m}{(m-1)!}\cdot e^{-\lambda x_n} \\ & = \prod_{i=1}^{n}x_i^{m-1}\dfrac{\lambda^{mn}}{[(m-1)!]^n} \cdot e^{-\lambda(x_1 + x_2 + \cdots + x_n)} \\ & \Longrightarrow \ln L = \ln \left(\prod_{i=1}^{n}x_i^{m-1}\right) + mn\ln \lambda - \lambda\sum_{i=1}^{n}x_i - n\ln (m-1)! \\ & \Longrightarrow \dfrac{\partial \ln L}{\partial \lambda} = \dfrac{mn}{\lambda} - \sum_{i=1}^{n}x_i = 0 \Longrightarrow \lambda = \dfrac{mn}{\sum_{i=1}^{n}x_i}.


Задача 4. :math:`f(x) = F'(x) = \lambda e^{-\lambda x}`.

Здесь


.. math::

   L & = \lambda^{10} e^{-\lambda\sum_{i=1}^{10}x_i} = \lambda^{10} e^{-3000\lambda} \\ \ln L & = 10 \ln \lambda - 3000 \lambda \\ \dfrac{\partial \ln L}{\partial \lambda} & = \dfrac{10}{\lambda} - 3000 = 0 \\ \lambda & = 1/300.


Задача 5.


.. math::

   L & = \dfrac{x_1 x_2 x_3}{\sigma^6}\exp{ -\dfrac{x_1^2+x_2^2+x_3^2}{2\sigma^2} } = \dfrac{1,98}{\sigma^6}exp{ -\dfrac{4,9}{\sigma^2} } \\  \ln L & = \ln 1,98 - 6\ln \sigma - \dfrac{4,9}{2\sigma^2} \\ \dfrac{\partial\ln L}{\partial \sigma} & = -\dfrac{6}{\sigma}+\dfrac{4,9}{\sigma^3} = 0 \sigma^2 & = \dfrac{49}{60} \approx 0,82.


Задача 6. :math:`L = C^1_k p (1-p)^{k-1} = kp(1-p)^{k-1}`.

:math:`\Longrightarrow \ln L = \ln k + \ln p + (k-1)\ln(1-p)`.

:math:`\Longrightarrow \dfrac{\partial \ln L}{\partial p} = \dfrac{1}{p} - \dfrac{k-1}{1-p} = 0`.

:math:`\Longrightarrow \dfrac{1-p-p(k-1)}{p(p-1)} = 0 \Longleftrightarrow pk = 1 \Longleftrightarrow p = 1/k`


Занятие 12
------------------------------------------------------------

Задача 1. Пусть :math:`Y = pX + b`, у нас есть


.. math::

   F(p, b) & = \sum_{k=1}^{n}(pX_k + b - Y_k)^2 \\ \dfrac{\partial F}{\partial p} & = \sum_{k=1}^{n}2X_k(pX_k + b - Y_k) = 0, \dfrac{\partial F}{\partial b} = \sum_{k=1}^{n} 2(pX_k + b - Y_k) = 0.


Откуда


.. math::

   p\sum_{k=1}^{n} X_k^2 + b \sum_{k=1}^{n} X_k = \sum_{k=1}^{n} X_k Y_k \Longleftrightarrow p \sum_{k=1}^{n} X_k + nb = \sum_{k=1}^{n} Y_k.


Мы вычисляем

:math:`\sum_{k=1}^{n}X_k^2 = 6^2 + 10^2 + \cdots + 35^2 + 38^2 = 6463`.

:math:`\sum_{k=1}^{n}X_k = 6 + 10 + \cdots + 35 + 38 = 233`.

:math:`\sum_{k=1}^{n}X_k Y_k = 6 \cdot 0 + 10 \cdot 18 + \cdots + 38 \cdot 30 = 5133`.

:math:`\sum_{k=1}^{n}Y_k = 0 + 18 + \cdots + 30 = 185`.

:math:`\Longrightarrow \tilde{p} \approx 0,8` и :math:`\tilde{b} \approx -0,03`

Так как :math:`\overline{X} = \dfrac{233}{10} = 23,3`,


.. math::

   s_x^2 = \dfrac{(6-23,3)^2 + (10 - 23,3)^2 + \cdots + (38 - 23,3)^2}{9} = 114,9 \\ \Longrightarrow s_x = \sqrt{114,9} \approx 10,72.


Аналогично, :math:`s_y = 11,47`. Поэтому коэффициент корреляции будет


.. math::

   \tilde{r}_{xy} = 0,8 \dfrac{10,72}{11,47} = 0,74.


Занятие 13
------------------------------------------------------------

Задача 1. :math:`k=20`, :math:`n=100`, :math:`\gamma=0,90 \Longrightarrow k/n = 1/5`.

У нас есть :math:`2\Phi_0(1,65)=0,9 \Longrightarrow t_\gamma=1,65`.

:math:`\Longrightarrow \dfrac{k}{n} - t_\gamma \sqrt{\dfrac{\dfrac{k}{n} \cdot \left(1-\dfrac{k}{n}\right)}{n}} < p < \dfrac{k}{n} + t_\gamma \sqrt{\dfrac{\dfrac{k}{n} \cdot \left(1-\dfrac{k}{n}\right)}{n}}`.

:math:`\Longrightarrow \dfrac{1}{5} - 1,65 \sqrt{\dfrac{1/5 \cdot 4/5}{100}} < p < \dfrac{1}{5} + 1,65 \sqrt{\dfrac{1/5 \cdot 4/5}{100}}`.

:math:`\Longrightarrow 0,134 < p < 0,266`


Задача 2. :math:`k=810`, :math:`n=900`, :math:`\gamma=0,95 \Longrightarrow k/n = 9/10`.

:math:`2\Phi_0(1,96)=0,95 \Longrightarrow t_\gamma = 1,96`.

:math:`\Longrightarrow \dfrac{k}{n} - t_\gamma \sqrt{\dfrac{\dfrac{k}{n} \cdot \left(1-\dfrac{k}{n}\right)}{n}} < p < \dfrac{k}{n} + t_\gamma \sqrt{\dfrac{\dfrac{k}{n} \cdot \left(1-\dfrac{k}{n}\right)}{n}}`.

:math:`\Longrightarrow 0,8804 < p < 0,9196`


Задача 3. :math:`0,73 < p < 0,77`


Задача 4. :math:`k=1200`, :math:`\overline{X} = 15,6`, :math:`s=0,4`, :math:`\gamma=0,95 \Longrightarrow t_\gamma=1,96`.

:math:`\overline{X} - t_\gamma \dfrac{s}{\sqrt{n}} < M < \overline{X} + t_\gamma \dfrac{s}{\sqrt{n}}`.

:math:`\Longrightarrow 15,3869 < M < 15,8131`


Задача 5. По таблице 2, :math:`t_\gamma = 1,96`, :math:`8,363 < M(X) < 8,437`


Задача 6. :math:`\Longrightarrow \dfrac{k}{n} - t_\gamma \sqrt{\dfrac{\dfrac{k}{n} \cdot \left(1-\dfrac{k}{n}\right)}{n}} < p < \dfrac{k}{n} + t_\gamma \sqrt{\dfrac{\dfrac{k}{n} \cdot \left(1-\dfrac{k}{n}\right)}{n}}`.

:math:`\Longrightarrow 0,26592 < p < 0,45408`


**CHƯA GIẢI**:

1. Занятие 3: 7б, 10
2. Занятие 5: 2, 8
3. Занятие 8: 13
4. Занятие 9: 5


КМ 2 - 07/04/2021
------------------------------------------------------------


Вариант 1
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Задача 1. Вероятность того, что радиоприемник проработает гарантийный срок без отказов равна 0,9. Какова вероятность того, что из данных пяти радиоприемников три проработают гарантийный срок без отказов?

Здесь :math:`n = 5`, :math:`p = 0,9 \Longrightarrow q = 1 - p=0,1`. Мы получим


.. math::

   P_5(3) = C^3_5 p^3 q^2 = C^3_5 \cdot (0,9)^3 \cdot (0,1)^2 = 0,0729.


Задача 2. Студент знает 20 из 25 вопросов программы. Студенту предлагается три вопроса. Какова вероятность того, что студент знает только один из предложенных ему вопросов? Какова вероятность того, что студент знает ответы на все три предложенных ему вопроса?

У нас есть :math:`\lvert \Omega \rvert = C^3_{25}`.

Пусть :math:`A` = { студент знает только один из предложенных }.

Выбрать 1 вопрос, который студент знает :math:`\Longrightarrow C^1_{20}` вариантов.

Выбрать 2 вопрос, которые студент не знает :math:`\Longrightarrow C^2_5` вариантов.


.. math::

   \Longrightarrow P(A) = \dfrac{C^1_{20} C^2_5}{C^3_{25}} = \dfrac{2}{23}.


:math:`B` = { студент знает все 3 вопроса }.


.. math::

   P(B) = \dfrac{C^3_{20}}{C^3_{25}} = \dfrac{57}{115}.


Задача 3. В двух урнах находятся шары отличающиеся только цветом причем в первой урне 5 белых, 11 черных и 6 красных шаров, а во второй соответственно 10, 8, 6. Из каждой урны извлекли по одному шару. Какова вероятность того, что оба шара одного цвета?


.. math::

   \lvert \Omega \rvert = C^1_{5+11+6} C^1_{10 + 8 + 6} = C^1_{22} C^1_{24}.


Пусть :math:`A` = { оба шара одного цвета }. У нас есть 3 случая

- белый: :math:`C^1_5 C^1_{10}` вариантов;
- черный: :math:`C^1_{11} C^1_8` вариантов;
- красный: :math:`C^1_6 C^1_6` вариантов.

Ответ


.. math::

   P(A) = \dfrac{C^1_5 C^1_{10} + C^1_{11} C^1_8 + C^1_6 C^1_6}{C^1_{22} C^1_{24}} = \dfrac{29}{88}.


Задача 4. В одном из двух ящиков лежит  3  белых и  7  черных шаров, а в другом лежит 5  белых  и   4   черных шара. Наугад выбирается один из ящиков и вынимается из него шар, который оказался белым. Найти вероятность того, что следующий извлеченный из этого же ящика шар тоже белый.

Пусть

- :math:`A_1` = { первый ящик выбирается };
- :math:`A_2` = { второй ящик выбирается };
- :math:`A` = { первый шар - белый }.

У нас есть


.. math::

   P(A) = P(A_1) P(A | A_1) + P(A_2) P(A | A_2) = \dfrac{1}{2} \cdot \dfrac{3}{10} + \dfrac{1}{2} \cdot \dfrac{5}{9} = \dfrac{77}{180}.


Отсюда, если пусть

- :math:`B_1` = { первый белый шар из первого ящика };
- :math:`B_2` = { первый белый шар из второго ящика };
- :math:`B` = { второй шар - белый };

мы получим


.. math::

   \begin{align*} P(B_1) & = P(A_1 | A) = \dfrac{1/2 \cdot 3/10}{77/180} = \dfrac{27}{77} \\ P(B_2) & = P(A_2 | A) = \dfrac{1/2 \cdot 5/9}{77/180} = \dfrac{50}{77} \end{align*}


Если первый ящик выбирается, после мы взяли один белый шар, еще 8 белых, тогда :math:`P(B | B_1) = \dfrac{2}{9}`. Аналогично, :math:`P(B | B_2) = \dfrac{4}{8}`.

Отсюда


.. math::

   P(B) = P(B_1) P(B | B_1) + P(B_2) P(B | B_2) = \dfrac{27}{77} \cdot \dfrac{2}{9} + \dfrac{50}{77} \cdot \dfrac{4}{8} = \dfrac{31}{77}.


Задача 5. Имеется  5 ящиков, в каждом из которых   10  белых  и  30  черных шаров. Из первого ящика во второй перекладывается один шар, затем из второго в третий перекладывается один шар  и т.д. После чего из последнего ящика извлекается один шар. Найти вероятность того, что он белый.

Пусть

- :math:`A_1` = { белый шар из 1-ого ящика } :math:`\Longrightarrow \overline{A}_1` = { черный шар из 1-ого ящика };
- :math:`A_2` = { белый шар из 2-ого ящика } :math:`\Longrightarrow \overline{A}_2` = { черный шар из 2-ого ящика };
- :math:`A_3` = { белый шар из 3-ого ящика } :math:`\Longrightarrow \overline{A}_3` = { черный шар из 3-ого ящика };
- :math:`A_4` = { белый шар из 4-ого ящика } :math:`\Longrightarrow \overline{A}_4` = { черный шар из 4-ого ящика };
- :math:`A_5` = { белый шар из 5-ого ящика } :math:`\Longrightarrow \overline{A}_5` = { черный шар из 5-ого ящика }.

Если мы выбираем белый шар из :math:`i`-ого ящика, тогда в :math:`(i+1)`-ом ящике есть :math:`8 + 1 = 9` белых ящиков. Значит :math:`P(A_{i+1} | A_i) = \dfrac{11}{41}`. Аналогично, если мы выбираем черный шар из :math:`i`-ого ящика, :math:`P(A_{i+1} | \overline{A}_i) = \dfrac{10}{41}` и 


.. math::

   P(A_{i+1}) = P(A_i) P(A_{i+1} | A_i) + P(\overline{A}_i) P(A_{i+1} | \overline{A}_i).


По условию


.. math::

   P(A_1) = \dfrac{10}{40} = \dfrac{1}{4}, P(\overline{A}_1) = \dfrac{30}{40} = \dfrac{3}{4},


у нас есть


.. math::

   P(A_2) = P(A_1) P(A_2 | A_1) + P(\overline{A}_1) P(A_2 | \overline{A}_1) = \dfrac{1}{4} \cdot \dfrac{11}{41} + \dfrac{3}{4} \cdot \dfrac{10}{41} = \dfrac{1}{4}, \\ P(\overline{A}_2) = 1 - \dfrac{1}{4} = \dfrac{3}{4}.


Аналогично, :math:`P(A_2) = P(A_3) = P(A_4) = P(A_5) = \dfrac{1}{4}`.

Ответ: :math:`\dfrac{1}{4}`.


Вариант 22
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Задача 1. Из колоды карт (36 штук) выбирают наугад две карты. Какова вероятность того, что обе они окажутся пиковой масти?

У нас есть 36 карт и выбирать 2 карты :math:`\Longrightarrow \lvert \Omega \rvert = C^2_{36}`.

Пусть :math:`A` = { обе они окажутся пиковой масти }.

В колоде карт есть 9 пиковых мастей, поэтому :math:`\lvert \Omega_A \rvert = C^2_9`.


.. math::

   \Longrightarrow P(A) = \dfrac{C^2_9}{C^2_{36}} = \dfrac{2}{35}.


Задача 2. Из урны, содержащей пять белых и четыре черных шара, извлекают шары по одному без возвращения, пока не будет извлечен белый шар. Какова вероятность того, что придется извлечь четыре шара?

Пусть

- :math:`A_i` = { выбрать :math:`i` черных шаров, пока не будет извлечен белый шар }. Поэтому :math:`i \in { 0, 1, 2, 3, 4 }`;
- :math:`B` = { выбрать белый шар в последний раз }.

У нас есть :math:`P(B|A_0) = P(B|A_1) = \cdots = P(B|A_4) = \dfrac{1}{5}`


.. math::

   P(A_0) = \dfrac{A^0_4}{A^0_9} = 1, P(A_1) = \dfrac{A^1_4}{A^1_9} = \dfrac{4}{9}, P(A_2) = \dfrac{A^2_4}{A^2_9} = \dfrac{1}{6}, P(A_3) = \dfrac{A^3_4}{A^3_9} = \dfrac{1}{21}, P(A_4) = \dfrac{A^4_4}{A^4_9} = \dfrac{1}{126}.


Мы можем вычислять


.. math::

   \begin{align*} P(A_3 | B) & = \dfrac{P(B|A_3)P(A_3)}{\sum\limits_{i=0}^{4}P(B|A_i) P(A_i)} \\ & = \dfrac{1/5 \cdot 1/21}{1/5 \cdot (1 + 4/9 + 1/6 + 1/21 + 1/126)} = \dfrac{1}{35}.\end{align*}


Задача 3. Для каждого из чисел :math:`X` и :math:`Y` равновозможно любое значение из отрезка :math:`[0;2]`. Какова вероятность того, что разность :math:`X - Y` превосходит единицу?

У нас есть :math:`X-Y \geqslant 1` и :math:`X, Y \in [0,2]`. Значит


.. math::

   \begin{cases} X - Y \geqslant 1 \\ 0 \leqslant X, Y \leqslant 2 \end{cases}


Отсюда мы получим вероятность равно :math:`P = \dfrac{S_{\triangle AB}}{S_{OBMN}} = \dfrac{1/2}{4} = \dfrac{1}{8}`.


Задача 4. В одном из двух ящиков лежит 9 белых и 3 черных шара, а в другом лежит 6 белых и 3 черных шара. Наугад выбирается один из ящиков и вынимается из него шар, который оказался белым. Найти вероятность того, что следующий извлеченный из этого же ящика шар тоже белый.

Пусть

- :math:`A_1` = { первый ящик выбирается };
- :math:`A_2` = { второй ящик выбирается };
- :math:`A` = { первый шар - белый }.

Отсюда


.. math::

   P(A) = P(A_1) P(A | A_1) + P(A_2) P(A | A_2) = \dfrac{1}{2} \cdot \dfrac{9}{12} + \dfrac{1}{2} \cdot \dfrac{6}{9} = \dfrac{17}{24}.


Далее, если пусть

- :math:`B_1` = { первый белый шар из первого ящика };
- :math:`B_2` = { первый белый шар из второго ящика };
- :math:`B` = { второй шар - белый };

мы получим


.. math::

   P(B_1) = P(A_1 | A) = \dfrac{1/2 \cdot 9/12}{17/24} = \dfrac{9}{17}, P(B_2) = P(A_2 | A) = \dfrac{1/2 \cdot 6/9}{17/24} = \dfrac{8}{17}.


Если первый ящик выбирается, после мы взяли один белый шар, еще 8 белых, тогда :math:`P(B | B_1) = \dfrac{8}{11}`. Аналогично, :math:`P(B | B_2) = \dfrac{5}{8}`.

Поэтому


.. math::

   P(B) = P(B_1) P(B | B_1) + P(B_2) P(B | B_2) = \dfrac{9}{17} \cdot \dfrac{8}{11} + \dfrac{8}{17} \cdot \dfrac{5}{8} = \dfrac{127}{187}.


Задача 5. Имеется  5 ящиков, в каждом из которых   8  белых  и  16  черных шаров. Из первого ящика во второй перекладывается один шар, затем из второго в третий перекладывается один шар  и т.д. После чего из последнего ящика извлекается один шар. Найти вероятность того, что он белый.

Пусть 

- :math:`A_1` = { белый шар из 1-ого ящика } :math:`\Longrightarrow \overline{A}_1` = { черный шар из 1-ого ящика };
- :math:`A_2` = { белый шар из 2-ого ящика } :math:`\Longrightarrow \overline{A}_2` = { черный шар из 2-ого ящика };
- :math:`A_3` = { белый шар из 3-ого ящика } :math:`\Longrightarrow \overline{A}_3` = { черный шар из 3-ого ящика };
- :math:`A_4` = { белый шар из 4-ого ящика } :math:`\Longrightarrow \overline{A}_4` = { черный шар из 4-ого ящика };
- :math:`A_5` = { белый шар из 5-ого ящика } :math:`\Longrightarrow \overline{A}_5` = { черный шар из 5-ого ящика }.

Если мы выбираем белый шар из :math:`i`-ого ящика, тогда в :math:`(i+1)`-ом ящике есть :math:`8 + 1 = 9` белых ящиков. Значит :math:`P(A_{i+1} | A_i) = \dfrac{9}{25}`. Аналогично, если мы выбираем черный шар из :math:`i`-ого ящика, :math:`P(A_{i+1} | \overline{A}_i) = \dfrac{8}{25}` и 


.. math::

   P(A_{i+1}) = P(A_i) P(A_{i+1} | A_i) + P(\overline{A}_i) P(A_{i+1} | \overline{A}_i).


По условию


.. math::

   P(A_1) = \dfrac{8}{24} = \dfrac{1}{3}, P(\overline{A}_1) = \dfrac{16}{24} = \dfrac{2}{3}.


Отсюда


.. math::

   \Longrightarrow P(A_2) = P(A_1) P(A_2 | A_1) + P(\overline{A}_1) P(A_2 | \overline{A}_1) = \dfrac{1}{3} \cdot \dfrac{9}{25} + \dfrac{2}{3} \cdot \dfrac{8}{25} = \dfrac{1}{3},


или


.. math::

   P(\overline{A}_2) = 1 - 1/3 = 2/3.


Аналогично, :math:`P(A_2) = P(A_3) = P(A_4) = P(A_5) = \dfrac{1}{3}`.

Ответ: :math:`\dfrac{1}{3}`.
