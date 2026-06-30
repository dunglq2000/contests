## CryptoFox 2025

Olympiad mật mã và bảo mật thông tin CryptoFox 2025.

| Số thứ tự | Tên bài | Tình trạng |
| ---------- | ------- | -------- |
| 0	| Хакерская атака | Chưa giải |
| 1 | Кривизна функции | Giải một phần ý 1 |
| 2 | Странная вселенная | Chưa giải |
| 3 | Магическая шкатулка | Chưa giải |
| 4 | Разности для FOX128 | Hoàn thành ý 1 |
| 5 | Шифрование в RSA | Hoàn thành |
| 6 | Подозрительная фотография | Chưa giải |
| 7 | Замены и перестановки | Hoàn thành |
| 8 | Загадочная ошибка | Chưa giải |
| 9 | Генератор гаммы на основе XSL-схемы | Chưa giải |
| 10 | Регистровое преобразование | Chưa giải |
| 11 | Трудный PBKDF | Chưa giải |

### Giới thiệu

Đầu tiên mình xin phép có một số ý kiến về việc trình bày đề thi. Đề thi có một điểm khá khó chịu là không được biên tập thống nhất. Mình hiểu rằng có nhiều người ra đề nhưng ít nhất cũng phải có người chịu trách nhiệm biên tập lại đề mỗi câu chứ. Kí hiệu ở mỗi câu mỗi khác nhau làm mất tính thống nhất của một cuộc thi. Ví dụ, ở câu 1 dùng $1 \leq \sigma(f)$, còn câu 2 dùng $\alpha, \beta \geqslant 0$, khác cách viết dấu bằng ở bất đẳng thức. Một ví dụ khác là kí hiệu trường hữu hạn, ở câu 1 dùng $\mathbb{Z}_p$ nhưng câu 4 lại dùng $\mathbb{F}_{2^8}$. Trong trường hợp này mình nghĩ nên thống nhất dùng $\mathrm{GF}(p)$ và $\mathrm{GF}(2^8)$, hoặc $\mathbb{F}_p$ và $\mathbb{F}_{2^8}$, sẽ hợp lí hơn. Sự không thống nhất cuối cùng còn ở chỗ mỗi đề có font chữ, cỡ chữ khác nhau, thậm chí có đề đánh số trang nhưng có đề không. Vì lý do trên nên khi viết lại đề, mình sẽ thay đổi kí hiệu cho thống nhất.

Về phần nội dung trong đề thì có 4 câu về reverse engineering (câu 0, câu 3, câu 6 và câu 8), còn lại 7 câu về mật mã. Các câu reverse engineering cũng là những thuật toán mật mã được giấu bên trong chương trình. Với kinh nghiệm hạn hẹp về reverse engineering thì mình không làm được những bài đó 🤣.

### Задача 0. Хакерская атака

Đây là một bài reverse engineering, và mình không biết làm 🤣.

### Задача 1. Кривизна функции

#### Câu hỏi

Đặt :math:`p` là số nguyên tố, $p \geqslant 3$, $\mathbb{F}_p = \{ 0, 1, \ldots, p \}$ là trường hữu hạn modulo :math:`p`, $\gamma = e^{\frac{2\pi i}{p}}$ là nghiệm phức primitive bậc :math:`p` của :math:`1`.

Với ánh xạ $f: \mathbb{F}_p \to \{ 0, 1 \}$ và với phần tử $a \in \mathbb{F}_p$ ta định nghĩa số

$$\nu_f(a) = \frac{1}{p}\sum_{x \in \mathbb{F}_p} (-1)^{f(x)} \gamma^{-ax}.$$

Ta định nghĩa curvature của hàm :math:`f` là đại lượng

$$\sigma(f) = \sum_{a \in \mathbb{F}_p} \lvert \nu_f(a) \rvert.$$

1. Chứng minh rằng

$$1 \leqslant \sigma(f) < \sqrt{p},$$

và chặn dưới đạt dấu bằng khi và chỉ khi :math:`f` là hàm hằng.

2. Chứng minh rằng, nếu $p = 2^{k+1} - 1$ và ánh xạ $f_t$, với $t = 0, 1, \ldots, k$, biến đổi từng phần tử $x \in \mathbb{F}_p$ theo nghĩa $f_t(x) = x_t \in \{ 0, 1 \}$, trong đó $x_t$ là biểu diễn nhị phân của :math:`x`, hay

$$x = x_0 + 2x_1 + \cdots + 2^k x_k,$$

thì ta có bất đẳng thức

$$\sigma(f_t) < \frac{4}{\pi} \ln p + \frac{9}{5}.$$

Gợi ý cho câu 2: sử dụng tổng Vinogradnova I.M. là

$$\sum_{h=0}^{p-1} \left|\sum_{j=0}^{N-1} \gamma^{hj}\right| < \frac{2}{\pi} p \ln p + \frac{2}{5} p + N,$$

với mọi số tự nhiên :math:`p` và :math:`N`.

#### [TODO] Giải

Bài này mình giải được một phần câu 1.

Sử dụng biến đổi Fourier rời rạc, đặt

$$u_x = (-1)^{f(x)}, \quad x \in \mathbb{F}_p.$$

Đặt $U_a = p \cdot \nu_a(f)$ thì ta có

$$U_a = \sum_{x = 0}^{p - 1} u_x e^{-2\pi i\frac{a}{p} x}$$

với $a = 0, 1, \ldots, p - 1$. 

Khi đó, theo biến đổi Fourier rời rạc ngược có thể thấy liên hệ giữa dãy $\{ u_ x \}$ theo $\{ U_ a \}$ là

$$u_x = \frac{1}{p} \sum_{a = 0}^{p - 1} U_a \cdot e^{2\pi i \frac{x}{p} a}$$

với $x = 0, 1, \ldots, p - 1$.

Theo định lí Parceval thì

$$\sum_{x = 0}^{p - 1} \lvert u_x \rvert^2 = \frac{1}{p} \sum_{a = 0}^{p - 1} \lvert U_a \rvert^2,$$

hay

$$\sum_{x = 0}^{p - 1} \left| (-1)^{f(x)} \right|^2 = \frac{1}{p} \sum_{a = 0}^{p - 1} \left|p \cdot \nu_f(a)\right|^2 = \frac{1}{p} \sum_{a = 0}^{p - 1} p^2 \left|\nu_f(a)\right|^2 = p \sum_{a = 0}^{p - 1} \left|\nu_f(a)\right|^2.$$

Sử dụng bất đẳng thức Cauchy, với hai vector bất kì

$$\bm{s} = (s_0, s_1, \ldots, s_{n-1}), \ \bm{t} = (t_0, t_1, \ldots, t_{n-1})$$

ta có

$$(s_0 t_0 + s_1 t_1 + \cdots + s_{n-1} t_{n-1})^2 \leqslant (s_0^2 + s_1^2 + \cdots + s_{n-1}^2)(t_0^2 + t_1^2 + \cdots t_{n-1}^2).$$

Cho $s_i = 1$ và $t_i = \left| \nu_f(i) \right|$ với $i = 0, 1, \ldots, p - 1$ ta có

$$p \sum_{a = 0}^{p - 1} \left|\nu_f(a)\right|^2 = (1 + 1 + \cdots + 1)\left(\sum_{a = 0}^{p - 1} \left|\nu_f(a)\right|^2\right) \geqslant \left(\sum_{a = 0}^{p - 1}\left|\nu_f(a)\right|\right)^2.$$

Do $f: \mathbb{F}_p \to \{ 0, 1 \}$ nên $(-1)^{f(x)} \in \{ -1, 1 \}$, suy ra $\left|(-1)^{f(x)}\right|^2 = 1$ với mọi $x = 0, 1, \ldots, p - 1$.

Như vậy bất đẳng thức trên có thể thu được

$$p = \sum_{x = 0}^{p - 1} \left|(-1)^{f(x)}\right|^2 =p \sum_{a = 0}^{p - 1} \left|\nu_f(a)\right|^2 \geqslant \left(\sum_{a=0}^{p-1} \left| \nu_f(a) \right|\right)^2 = \left(\sigma(f)\right)^2,$$

tương đương với

$$\sigma(f) \leqslant \sqrt{p}.$$

Dấu bằng xảy ra khi và chỉ khi $\left| \nu_f(a) \right|$ là hằng số nhưng dễ thấy điều này không thể xảy ra. Do đó có thể kết luận

$$\boxed{\sigma(f) < \sqrt{p}.}$$

### Задача 2. Странная вселенная

#### Câu hỏi

Trong một vũ trụ lạ thường nọ, gọi là Strange Universe, chúng ta thực hiện các thí nghiệm quantum.

Kết thúc một thí nghiệm, chúng ta nhận được toán tử quantum :math:`A` và các trạng thái quantum $\lvert x \rangle$ và $\lvert y \rangle$, ở đây

$$A(\alpha \lvert x \rangle + \beta \lvert y \rangle) \neq \alpha A(\lvert x \rangle) + \beta A(\lvert y \rangle)$$

với $\alpha, \beta \geqslant 0$ và $\alpha + \beta = 1$. Chúng ta muốn tiếp tục thí nghiệm nhưng các thiết bị đã hỏng.

Chúng ta sử dụng một kênh truyền quantum để trao đổi thông tin, và chúng ta cần trả lời các câu hỏi sau:

1. Trong Strange Universe, giao thức mật mã BB84 có không an toàn không? Nếu có thì điều kiện nào khiến việc này xảy ra?
2. Trong Strange Universe, giao thức mật mã E91 có không an toàn không? Nếu có thì điều kiện nào khiến việc này xảy ra?
3. Trong Strange Universe có tính chất thú vị nào khác của kênh truyền quantum không?

#### [TODO] Giải

### Задача 3. Магическая шкатулка

Lại một bài reverse engineering khác và mình cũng không làm ra.

### Задача 4. Разности для FOX128

#### Câu hỏi

Grisha phát triển một thuật toán mã khối là FOX128.

Đặt $V_{16}(2^8)$ là không gian vector có số chiều bằng :math:`16` trên trường $\mathbb{F}_{2^8}$.

Đặt $S(X)$ là nhóm symmetric, tác độ lên tập hữu hạn :math:`X`.

**Phép biến đổi không tuyến tính** của FOX128 là hoán vị $\pi'$. Khi đó với

$$\alpha = (\alpha_1, \alpha_2, \ldots, \alpha_{16}) \in V_{16}(2^8)$$

ta sẽ có

$$\pi'(\alpha) = (\pi(\alpha_1), \pi(\alpha_2), \ldots, \pi(\alpha_{16}))$$

với $\pi \in S(\mathbb{F}_{2^8})$.

Hoán vị $\pi$ có thể được viết dưới dạng

$$\pi'' = (\pi(0), \pi(1), \ldots, \pi(255))$$

như sau

| | :math:`0` | :math:`1` | :math:`2` | :math:`3` | :math:`4` | :math:`5` | :math:`6` | :math:`7` | :math:`8` | :math:`9` | :math:`10` | :math:`11` | :math:`12` | :math:`13` | :math:`14` | :math:`15` |
| - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | 
| :math:`0` | $252$ | $238$ | $221$ | :math:`17` | $207$ | $110$ | $49$ | :math:`22` | $251$ | $196$ | $250$ | $218$ | $35$ | $197$ | :math:`4` | $77$ |
| :math:`1` | $233$ | $ 119$ | $240$ | $219$ | $147$ | $46$ | $153$ | $186$ | :math:`23` | $54$ | $241$ | $187$ | :math:`20` | $205$ | $95$ | $193$ |
| :math:`2` | $249$ | :math:`24` | $101$ | $ 90$ | $226$ | $92$ | $239$ | $33$ | $129$ | :math:`28` | $60$ | $66$ | $139$ | :math:`1` | $142$ | $79$ |
| :math:`3` | :math:`5` | $132$ | :math:`2` | $174$ | $227$ | $106$ | $143$ | $ 160$ | :math:`6` | :math:`11` | $237$ | $152$ | $127$ | $212$ | $211$ | :math:`31` |
| :math:`4` | $235$ | $52$ | $44$ | $81$ | $234$ | $200$ | $72$ | $171$ | $242$ | $42$ | $ 104$ | $162$ | $253$ | $58$ | $206$ | $204$ |
| :math:`5` | $181$ | $112$ | :math:`14` | $86$ | :math:`8` | :math:`12` | $118$ | :math:`18` | $191$ | $114$ | :math:`19` | $71$ | $156$ | $ 183$ | $93$ | $135$ |
| :math:`6` | :math:`21` | $161$ | $150$ | $41$ | :math:`16` | $123$ | $154$ | $199$ | $243$ | $145$ | $120$ | $111$ | $157$ | $158$ | $178$ | $ 177$ |
| :math:`7` | $50$ | $117$ | :math:`25` | $61$ | $255$ | $53$ | $138$ | $126$ | $109$ | $84$ | $198$ | :math:`64` | $195$ | $189$ | :math:`13` | $87$ |
| :math:`8` | $223$ | $ 245$ | $36$ | $169$ | $62$ | $168$ | $67$ | $201$ | $215$ | $121$ | $214$ | $246$ | $124$ | $34$ | $185$ | :math:`3` |
| :math:`9` | $224$ | :math:`15` | $236$ | $ 222$ | $122$ | $148$ | $176$ | $188$ | $220$ | $232$ | $40$ | $80$ | $78$ | $51$ | :math:`10` | $74$ |
| :math:`10` | $167$ | $151$ | $96$ | $115$ | :math:`30` | :math:`0` | $ 98$ | $68$ | :math:`26` | $184$ | $56$ | $130$ | $100$ | $159$ | $38$ | $65$ |
| :math:`11` | $173$ | $69$ | $70$ | $146$ | $39$ | $94$ | $85$ | $47$ | $140$ | $163$ | $ 165$ | $125$ | $105$ | $213$ | $149$ | $59$ |
| :math:`12` | :math:`7` | $88$ | $179$ | :math:`64` | $134$ | $172$ | :math:`29` | $247$ | $48$ | $55$ | $107$ | $228$ | $136$ | $ 217$ | $231$ | $137$ |
| :math:`13` | $225$ | :math:`27` | $131$ | $73$ | $76$ | $63$ | $248$ | $254$ | $141$ | $83$ | $170$ | $144$ | $202$ | $216$ | $133$ | $ 97$ |
| :math:`14` | :math:`32` | $113$ | $103$ | $164$ | $45$ | $43$ | :math:`9` | $91$ | $203$ | $155$ | $37$ | $208$ | $190$ | $229$ | $108$ | $82$ |
| :math:`15` | $89$ | $166$ | $ 116$ | $210$ | $230$ | $244$ | $180$ | $192$ | $209$ | $102$ | $175$ | $194$ | $57$ | $75$ | $99$ | $182$ |

Ở bảng trên, phần tử hàng :math:`i` và cột :math:`j` ($0 \leqslant i, j \leqslant 15$) là giá trị $\pi(16 i + j)$.

**Phép biến đổi tuyến tính** của phần tử $\alpha = (\alpha_1, \ldots, \alpha_{16})$ với $\alpha \in V_{16}(2^8)$ được kí hiệu là :math:`h`. Khi đó với phần tử $\alpha = (\alpha_1, \ldots, \alpha_{16})$ ta chuyển thành dạng ma trận

$$A = \begin{pmatrix}
    \alpha_1 & \alpha_2 & \alpha_3 & \alpha_4 \\
    \alpha_5 & \alpha_6 & \alpha_7 & \alpha_8 \\
    \alpha_9 & \alpha_{10} & \alpha_{11} & \alpha_{12} \\
    \alpha_{13} & \alpha_{14} & \alpha_{15} & \alpha_{16} \\
\end{pmatrix}.$$

Khi đó $h(\alpha)$ là ma trận :math:`B`, được tính theo công thức:

$$B = \begin{pmatrix}
    0 & 1 & 1 & 1 \\ 1 & 0 & 1 & 1 \\ 1 & 1 & 0 & 1 \\ 1 & 1 & 1 & 0
\end{pmatrix} \cdot A,$$

với phép cộng và nhân được thực hiện giống phép cộng và nhân trên các phần tử của trường.

**Phép cộng với khóa :math:`k`** là ánh xạ có dạng

$$\nu_k(\alpha) = \alpha \oplus k,$$

với $\oplus$ là toán tử cộng từng bit theo modulo :math:`2` (phép XOR), và $\alpha, k \in V_{16}(2^8)$.

Khi đó, hàm mã hóa đối với bản rõ $\alpha \in V_{16}(2^8)$ có dạng

$$g_{k_1 k_2}(\alpha) = \nu_{k_2} h \pi' v_{k_1} (\alpha).$$

Grisha sử dụng mode ECB để mã hóa từ `ПРИВЕДЕНИЕ`. Ở đây anh ấy dùng bảng sau để encode kí tự tiếng Nga sang phần tử thuộc $\mathbb{F}_{2^8}$ và để gọn mình sẽ viết ở dạng thập phân.

| А | У | О | И | Э | Ы | Я | Ю | Е | Ё | Б | В | Г | Д | Ж | З | Й | К |
| - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | 
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 |

| Л | М | Н | П | Р | С | Т | Ф | Х | Ц | Ч | Ш | Щ | Ъ | Ь | ... |
| - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | 
| 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 | 32 | ... |

Khi sử dụng FOX128 cipher thì chúng ta sẽ thêm vào phía trước các số :math:`0` cho đủ vector gồm :math:`16` phần tử. Ví dụ sau khi encode thông điệp chúng ta có vector $(25, 2, 17, 23)$ thì chúng ta pad thành

$$\alpha = (0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 2, 17, 23).$$

Chúng ta biết rằng khi mã hóa thông điệp `ПРИВЕДЕНИЕ`, ta thu được bản mã

$$\beta_1 = (216, 121, 18, 144, 93, 121, 17, 11, 114, 81, 251, 135, 200, 53, 54, 79)$$

Sau đó Grisha mã hóa một thông điệp khác với cùng khóa con $k_1$, $k_2$ như trên với những thông điệp có nghĩa khác nhau nhằm mục đích nghiên cứu sự phụ thuộc giữa các bản rõ với nhau và với bản mã. Khi đó, với một bản rõ nào đó Grisha đã mã hóa thành

$$\beta_2 = (216, 121, 230, 68, 93, 121, 229, 223, 114, 81, 251, 83, 200, 53, 194, 79).$$

Grisha đã làm mất thí nghiệm của mình và không còn thông tin về khóa, cũng như bản rõ tương ứng với $\beta_2$. Hãy giúp anh ấy.

1. Khôi phục bản rõ tương ứng bản mã $\beta_2$.
2. Đưa ra thuật toán tối ưu khôi phục lại $k_2$ hoặc một phần của nó, nếu biết rằng khi tạo khóa con $k_2$ chỉ sử dụng các nguyên âm.

#### [TODO] Giải

Mình giải được câu 1 và chưa kịp làm câu 2.

Giả sử chúng ta mã hóa hai bản rõ $\bm{a}, \bm{a}' \in V_{16}(2^8)$ với cùng khóa $\bm{k}_1$ và $\bm{k}_2$.

Đặt

$$\bm{a} = (a_1, a_2 \ldots, a_{16}), \ \bm{a}' = (a_1', a_2', \ldots, a_{16}'),$$

với $a_i$ và $a_i' \in \mathbb{F}_{2^8}$, $i = 1, 2, \ldots, 16$.

Đặt

$$\bm{k}_1 = (k_{1, 1}, k_{1, 2}, \ldots, k_{1, 16}), \ \bm{k}_2 = (k_{2,1}, k_{2,2}, \ldots, k_{2, 16}),$$

với $k_{1, i}$ và $k_{2, i} \in \mathbb{F}_{2^8}$, $i = 1, \ldots, 16$.

Sau phép biến đổi $\nu_{\bm{k}_1}$ ta được

$$
    \nu_{\bm{k}_1}(\bm{a}) = (a_1 \oplus k_{1,1}, \ldots, a_{16} \oplus k_{1, 16}) = (b_1, \ldots, b_{16}), \\
    \nu_{\bm{k}_1}(\bm{a}') = (a_1' \oplus k_{1,1}, \ldots, a_{16}' \oplus k_{1, 16}) = (b_1', \ldots, b_{16}'),
$$

ở đây đặt $b_i = a_i \oplus k_{1, i}$, tương tụ $b_i' = a_i' \oplus k_{1, i}$.

Sau phép biến đổi thứ hai $\pi'$ ta có

$$
    \pi'(b_1, \ldots, b_{16}) = (c_1, \ldots, c_{16}), \\
    \pi'(b_1', \ldots, b_{16}') = (c_1', \ldots, c_{16}'),
$$

với $c_i = \pi(b_i)$ và $c_i' = \pi(b_i')$.

Sau phép biến đổi tuyến tính :math:`h` ta có

$$h(c_1, \ldots, c_{16}) = (d_1, \ldots, d_{16}), \quad h(c_1', \ldots, c_{16}') = (d_1', \ldots, d_{16}').$$

Cuối cùng, phép biến đổi $\nu_{\bm{k}_2}$:

$$
    \nu_{\bm{k}_2}(d_1, \ldots, d_{16}) = (d_1 \oplus k_{2, 1}, \ldots, d_{16} \oplus k_{2, 16}) = (e_1, \ldots, e_{16}), \\
    \nu_{\bm{k}_2}(d_1', \ldots, d_{16}') = (d_1' \oplus k_{2, 1}, \ldots, d_{16}' \oplus k_{2, 16}) = (e_1', \ldots, e_{16}').
$$

Lúc này bản mã chính là các vector $(e_1, \ldots, e_{16})$ và $(e_1', \ldots, e_{16}')$.

Nếu XOR hai bản mã với nhau thì

$$(e_1 \oplus e_1', \ldots, e_{16} \oplus e_{16}') = (e_1, \ldots, e_{16}) \oplus (e_1', \ldots, e_{16}') = (d_1 \oplus d_1', \ldots, d_{16} \oplus d_{16}'),$$

nhưng :math:`h` là phép biến đổi tuyến tính nên

$$(d_1 \oplus d_1', \ldots, d_{16} \oplus d_{16}') = h(c_1, \ldots, c_{16}) \oplus h(c_1', \ldots, c_{16}') = h(c_1 \oplus c_1', \ldots, c_{16} \oplus c_{16}').$$

Như vậy có thể nói rằng

$$(e_1 \oplus e_1', \ldots, e_{16} \oplus e_{16}') = h(c_1 \oplus c_1', \ldots, c_{16} \oplus c_{16}').$$

Ma trận :math:`H` và nghịch đảo của nó là như nhau, do đó có thể viết lại biểu thức trên thành

$$h(e_1 \oplus e_1', \ldots, e_{16} \oplus e_{16}') = (c_1 \oplus c_1', \ldots, c_{16} \oplus c_{16}').$$

Vì $c_i = \pi(a_i \oplus k_{1, i})$ và $c_i' = \pi(a_i' \oplus k_{1, i})$, và ta tính được $h(e_1 \oplus e_1', \ldots, e_{16} \oplus e_{16}')$ nên sẽ tìm được các phần tử $c_1 \oplus c_1'$, ..., $c_{16} \oplus c_{16}'$.

Lúc này ta thử các $k_{1, i}$ với $i = 1, 2, \ldots, 16$ để xem $k_{1, i}$ nào thỏa mãn

$$c_i \oplus c_i' = \pi(a_i \oplus k_{1, i}) \oplus \pi(a_i' \oplus k_{1, i})$$

với điều kiện là $0 \leqslant a_i' \leqslant 32$ (theo bảng code bên trên).

.. admonition:: solve.py
:class: dropdown
```python
from sage.all import GF, matrix, vector

alphabet = "АУОИЭЫЯЮЕЁБВГДЖЗЙКЛМНПРСТФХЦЧШЩЪЬ"
char_to_int = dict(zip(alphabet, range(33)))
int_to_char = dict(zip(range(33), alphabet))
assert len(alphabet) == 33

PI = (
    252, 238, 221, 17, 207, 110, 49, 22, 251, 196, 250, 218, 35, 197, 4, 77, 
    233, 119, 240, 219, 147, 46, 153, 186, 23, 54, 241, 187, 20, 205, 95, 193, 
    249, 24, 101, 90, 226, 92, 239, 33, 129, 28, 60, 66, 139, 1, 142, 79, 
    5, 132, 2, 174, 227, 106, 143, 160, 6, 11, 237, 152, 127, 212, 211, 31, 
    235, 52, 44, 81, 234, 200, 72, 171, 242, 42, 104, 162, 253, 58, 206, 204, 
    181, 112, 14, 86, 8, 12, 118, 18, 191, 114, 19, 71, 156, 183, 93, 135, 
    21, 161, 150, 41, 16, 123, 154, 199, 243, 145, 120, 111, 157, 158, 178, 177, 
    50, 117, 25, 61, 255, 53, 138, 126, 109, 84, 198, 128, 195, 189, 13, 87, 
    223, 245, 36, 169, 62, 168, 67, 201, 215, 121, 214, 246, 124, 34, 185, 3, 
    224, 15, 236, 222, 122, 148, 176, 188, 220, 232, 40, 80, 78, 51, 10, 74, 
    167, 151, 96, 115, 30, 0, 98, 68, 26, 184, 56, 130, 100, 159, 38, 65, 
    173, 69, 70, 146, 39, 94, 85, 47, 140, 163, 165, 125, 105, 213, 149, 59, 
    7, 88, 179, 64, 134, 172, 29, 247, 48, 55, 107, 228, 136, 217, 231, 137, 
    225, 27, 131, 73, 76, 63, 248, 254, 141, 83, 170, 144, 202, 216, 133, 97, 
    32, 113, 103, 164, 45, 43, 9, 91, 203, 155, 37, 208, 190, 229, 108, 82, 
    89, 166, 116, 210, 230, 244, 180, 192, 209, 102, 175, 194, 57, 75, 99, 182)
PI_inv = [PI.index(i) for i in range(256)]

assert all(PI[PI_inv[i]] == i for i in range(256))

def P(f):
    return F8.from_integer(PI[f.to_integer()])

def P_inv(f):
    return F8.from_integer(PI_inv[f.to_integer()])

F = GF(2, 'x')
x = F.gen()
F8 = GF(2**8, name='x', modulus='random')

pa = [21, 22, 3, 11, 8, 13, 8, 20, 3, 8] # ПРИВЕДЕНИЕ
assert len(pa) == 10
pa = [0] * 6 + pa

ca = (216, 121, 18, 144, 93, 121, 17, 11, 114, 81, 251, 135, 200, 53, 54, 79)
cb = (216, 121, 230, 68, 93, 121, 229, 223, 114, 81, 251, 83, 200, 53, 194, 79)

H = matrix(F8, [[0, 1, 1, 1], [1, 0, 1, 1], [1, 1, 0, 1], [1, 1, 1, 0]])

for i in range(4):
    va = vector(F8, [F8.from_integer(pa[i+4*j]) for j in range(4)])
    Ca = vector(F8, [F8.from_integer(ca[i+4*j]) for j in range(4)])
    Cb = vector(F8, [F8.from_integer(cb[i+4*j]) for j in range(4)])
    Cc = H*(Ca + Cb)
    for j in range(4):
        pt, k = [], []
        for K in range(2**8):
            key = F8.from_integer(K)
            guess = P_inv(P(va[j] + key) + Cc[j]) + key
            guess = guess.to_integer()
            if 0 <= guess and guess <= 32:
                pt.append(guess)
                k.append(K)
        print(i + 4 * j, set(pt))
```
````

Theo kết quả chạy chương trình thì các vị trí :math:`i` sau cho $a_i = a_i'$:

$$i \in \{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14 \}.$$

Như vậy từ tiếng Nga chúng ta cần tìm có dạng `ПРИВ_ДЕНИ_`. Lưu ý rằng chúng ta đã bỏ các số :math:`0` đứng trước trong quá trình decode.

Ở đây, dễ thấy sau kí tự `В` phải là nguyên âm, tức là vị trí $i = 10$. Có hai ứng cử viên cho vị trí này là kí tự `О` (encode thành :math:`2`) và `И` (encode thành :math:`3`). Trong tiếng Nga có từ "привидение" nên ta sẽ chọn kí tự `И` cho $i = 10$.

Vì "привидение" là từ giống trung nên kết thúc của nó (trong 6 cách) là "е", "я", "и" và "й". Từ chương trình giải bên trên chỉ có kí tự `Я` là được chấp nhận.

Như vậy, kết quả là `ПРИВИДЕНИЯ`.

### Задача 5. Шифрование в RSA

#### Câu hỏi

Ta sử dụng thuật toán RSA để mã hóa với tham số sau

```python
n = 0x45f9a1a7b27926c4310c4aec745f069487cb4ae65c717d43014012ba3520008a5fae47d12490c9349b49a50737ae8225271ed1f64d2c8bffe7f4c5022e188316ab96eada430e47af5a4ab879a211d3077f7f1dc230e15f7a6f531eb8a2c97a5ec0f070ea1e2425e27db89eb70e7c03387ecf51736aef8ef0b0c389781728bd3
e = 5
```

Ta chặn được hai bản rõ:

```python
c1 = 0x525a04be10f92bc34e0f3fb9990a324a4519b946182e1530b827160b379d073f8556df0b7c778ebde881eb6b55e33ef8e5ec9d9e8fed7661f224090dfbf81838729ceb7bc9fc9109528551ecc28abcb0228e3a40d47f48f15b
c2 = 0x525a04be10f92bc34e0f3fb9990a324a451fd7512f0acce5fda8514c0fd461676b0d6b946a3ed1375a7b5981d64ecbda4699a7133886af3163570d9ddf8580986048393f13b274c2967ae1d4386d8ce41731e343964ce00c00
```

Hãy giải mã các thông điệp, biết rằng bản rõ $m_1$ và $m_2$ có liên hệ $m_2 = m_1 + 1$.

#### Giải

Sử dụng Coppersmith attack.

.. admonition:: solve.py
:class: dropdown
```python
from sage.all import *


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


n = """45f9a1a7b27926c4310c4aec745f069487cb4ae65c717d43014012ba3520008a
5fae47d12490c9349b49a50737ae8225271ed1f64d2c8bffe7f4c5022e188316
ab96eada430e47af5a4ab879a211d3077f7f1dc230e15f7a6f531eb8a2c97a5e
c0f070ea1e2425e27db89eb70e7c03387ecf51736aef8ef0b0c389781728bd3"""

n = int(n.replace("\n", ""), 16)

e = 5

c1 = """525a04be10f92bc34e0f3fb9990a324a4519b946182e1530b827160b379d073f
8556df0b7c778ebde881eb6b55e33ef8e5ec9d9e8fed7661f224090dfbf81838
729ceb7bc9fc9109528551ecc28abcb0228e3a40d47f48f15b"""
c2 = """525a04be10f92bc34e0f3fb9990a324a451fd7512f0acce5fda8514c0fd46167
6b0d6b946a3ed1375a7b5981d64ecbda4699a7133886af3163570d9ddf858098
6048393f13b274c2967ae1d4386d8ce41731e343964ce00c00"""

c1 = int(c1.replace("\n", ""), 16)
c2 = int(c2.replace("\n", ""), 16)

PR = PolynomialRing(Zmod(n), 'x')
x = PR.gen()
f = x**e - c1
g = (x+1)**e - c2
res = Integer(-gcd(f, g).monic()[0])
print(res.to_bytes(res.nbits() // 8 + 1, 'big'))
```
````

### Задача 6. Подозрительная фотография

Thêm một bài reverse engineering và lần này là Android. Mình chịu chết.

### Задача 7. Замены и перестановки

#### Câu hỏi

Chúng ta chặn được một thông điệp mã hóa được truyền qua radio và lưu vào file `ct.txt`. Chúng ta cần biết thông điệp ban đầu là gì.

Biết rằng thông điệp được mã hóa bằng mã dòng (stream cipher). Khóa là một dãy $\gamma_1$, $\gamma_2$, ... được sinh ra từ một khóa ban đầu và đi qua thuật toán sinh khóa.

Thuật toán sinh khóa nhận đầu vào là khóa :math:`256` bits.

:math:`256` bits đầu tiên nhận được từ việc mã hóa dãy các bytes `\0` bằng thuật toán Skipjack với khóa $K_{root}$ ($80$ bits) và $IV$ (:math:`64` bits) là

$$IV = \{ 0x43,0x72,0x79,0x70,0x74,0x46,0x6f, 0x78 \}.$$

Việc mã hóa được thực hiện bằng mode CFB, nghĩa là

$$K_0 = \mathsf{Encrypt}_{cfb}(K_{root}, IV, [0x00] \cdot 32),$$

trong đó $K_{root} \in \{ 0, 1 \}^{80}$, $IV \in \{ 0, 1 \}^{64}$, và bản mã là $K_0 \in \{ 0, 1 \}^{256}$.

:math:`256` bits tiếp theo được sinh bởi kết quả mã hóa bên trên, tức là

$$K_1 = \mathsf{Encrypt}_{cfb}(K_{root}, IV, K_0).$$

Thực hiện tương tự như vậy ta có công thức tổng quát là

$$K_i = \mathsf{Encrypt}_{cfb}(K_{root}, IV, K_{i-1}),$$

với $i \in \mathbb{N}$, $K_i \in \{ 0, 1 \}^{256}$.

Dãy $\{ \gamma_n \}$ nhận được từ các giá trị $K_i$ và $K_0$. Ở đây, :math:`4` bits đầu tiên của dãy $\{ \gamma_n \}$ nhận được từ $K_0$ theo quy tắc

$$\gamma_j = \begin{cases}
    0 \ \text{nếu} \ K_0[j] = 0, \\
    1 \ \text{trong trường hợp khác},
\end{cases}$$

trong đó $K_0[j]$ là khối :math:`64` bits thứ :math:`i` của $K_0$, $\gamma_j \in \{ 0, 1 \}$ với $j = 0, 1, 2, 3$.

Các bit tiếp theo được sinh tương tự theo quy tắc

$$\gamma_j = \begin{cases}
    0 \ \text{nếu} \ K_{j / 4}[j \% 4] = 0, \\
    1 \ \text{trong trường hợp khác},
\end{cases}$$

với $a \% b$ là số dư khi chia :math:`a` cho :math:`b`, $j \in \mathbb{N}$.

Ví dụ ta có khóa

$$
K_j = \{ \mathrm{0x0c}, \mathrm{0xea}, \mathrm{0x66}, \mathrm{0xe0}, \mathrm{0x96}, \mathrm{0xbd}, \mathrm{0xf1}, \mathrm{0xc0}, \\
\mathrm{0x9c}, \mathrm{0xc2}, \mathrm{0xf1}, \mathrm{0x62}, \mathrm{0xa5}, \mathrm{0x44} ,\mathrm{0x1f}, \mathrm{0xb7}, \\
\mathrm{0xdd}, \mathrm{0x4b}, \mathrm{0x2b}, \mathrm{0xbf}, \mathrm{0xd6}, \mathrm{0xd9}, \mathrm{0x64}, \mathrm{0x73}, \\
\mathrm{0xb4}, \mathrm{0x97}, \mathrm{0x7b}, \mathrm{0x39}, \mathrm{0x06}, \mathrm{0x02}, \mathrm{0x4c}, \mathrm{0xb8} \}
$$

thì ta sẽ chia được thành :math:`4` đoạn, mỗi đoạn :math:`64` bits (hay :math:`8` bytes) như sau

$$
K_j[0] & = \{ \mathrm{0x0c}, \mathrm{0xea}, \mathrm{0x66}, \mathrm{0xe0}, \mathrm{0x96}, \mathrm{0xbd}, \mathrm{0xf1}, \mathrm{0xc0} \}, \\
K_j[1] & = \{ \mathrm{0x9c}, \mathrm{0xc2}, \mathrm{0xf1}, \mathrm{0x62}, \mathrm{0xa5}, \mathrm{0x44}, \mathrm{0x1f}, \mathrm{0xb7} \}, \\
K_j[2] & = \{ \mathrm{0xdd}, \mathrm{0x4b}, \mathrm{0x2b}, \mathrm{0xbf}, \mathrm{0xd6}, \mathrm{0xd9}, \mathrm{0x64}, \mathrm{0x73} \}, \\
K_j[3] & = \{ \mathrm{0xb4}, \mathrm{0x97}, \mathrm{0x7b}, \mathrm{0x39}, \mathrm{0x06}, \mathrm{0x02}, \mathrm{0x4c}, \mathrm{0xb8} \}.
$$

Bản mã nhận được theo công thức

$$c_i = p_i \oplus \gamma_i$$

với $c_i, p_i \in \{ 0, 1 \}$ và $i = 0, 1, 2, \ldots$

Hãy phân tích và khôi phục thông điệp ban đầu, và xác định họ của tác giả nếu biết file được encode bằng cp1251.

#### Giải

Thuật toán sinh khóa nhận đầu vào là khóa :math:`256` bits.

:math:`256` bits đầu tiên nhận được từ việc mã hóa dãy các bytes `\0` bằng thuật toán Skipjack với khóa $K_{root}$ ($80$ bits) và $IV$ (:math:`64` bits) là

$$IV = \{ 0x43,0x72,0x79,0x70,0x74,0x46,0x6f, 0x78 \}.$$

Việc mã hóa được thực hiện bằng mode CFB, nghĩa là

$$K_0 = \mathsf{Encrypt}_{cfb}(K_{root}, IV, [0x00] \cdot 32),$$

trong đó $K_{root} \in \{ 0, 1 \}^{80}$, $IV \in \{ 0, 1 \}^{64}$, và bản mã là $K_0 \in \{ 0, 1 \}^{256}$.

Đặt $\mathsf{Enc}(P)$ là hàm mã hóa bản rõ :math:`P` :math:`64` bits bằng thuật toán Skipjack với khóa $K_{root}$ $80$ bits.

Giả sử $K_0 = (K_0[0], K_0[1], K_0[2], K_0[3]) \in \{ 0, 1 \}^{256}$, với $K_0[j] \in \{ 0, 1 \}^{64}$, $j = 0, 1, 2, 3$. Theo mode CFB thì

$$
    K_0[0] & = \mathsf{Enc}(IV) \oplus ([0x00] \cdot 8) = \mathsf{Enc}(IV), \\
    K_0[1] & = \mathsf{Enc}(K_0[0]) \oplus ([0x00] \cdot 8) = \mathsf{Enc}(K_0[0]), \\
    K_0[2] & = \mathsf{Enc}(K_0[1]) \oplus ([0x00] \cdot 8) = \mathsf{Enc}(K_0[1]), \\
    K_0[3] & = \mathsf{Enc}(K_0[2]) \oplus ([0x00] \cdot 8) = \mathsf{Enc}(K_0[2]).
$$

:math:`256` bits tiếp theo được tạo với cơ chế tương tự:

$$K_1 = \mathsf{Encrypt}_{cfb}(K_{root}, IV, K_0).$$

Giả sử $K_1 = (K_1[0], K_1[1], K_1[2], K_1[3]) \in \{ 0, 1 \}^{256}$ với $K_1[j] \in \{ 0, 1 \}^{64}$, $j = 0, 1, 2, 3$. Tương tự, theo mode CFB thì

$$
    K_1[0] & = \mathsf{Enc}(IV) \oplus K_0[0], \\
    K_1[1] & = \mathsf{Enc}(K_0[0]) \oplus K_0[1], \\
    K_1[2] & = \mathsf{Enc}(K_0[1]) \oplus K_0[2], \\
    K_1[3] & = \mathsf{Enc}(K_0[2]) \oplus K_0[3].
$$

Tổng quát:

$$K_i = \mathsf{Encrypt}_{cfb}(K_{root}, IV, K_{i-1}),$$

với $i \in \mathbb{N}$ và $K_i \in \{ 0, 1 \}^{256}$.

Giả sử

$$K_i = (K_i[0], K_i[1], K_i[2], K_i[3]) \in \{ 0, 1 \}^{256}$$

với $K_i[j] \in \{ 0, 1 \}^{64}$, $j = 0, 1, 2, 3$.

Theo mode CFB thì

$$
    K_i[0] & = \mathsf{Enc}(IV) \oplus K_{i-1}[0], \\
    K_i[1] & = \mathsf{Enc}(K_0[0]) \oplus K_{i-1}[1], \\
    K_i[2] & = \mathsf{Enc}(K_0[1]) \oplus K_{i-1}[2], \\
    K_i[3] & = \mathsf{Enc}(K_0[2]) \oplus K_{i-1}[3].
$$

Dãy $\{ \gamma_n \}$ nhận được từ các giá trị $K_i$ và $K_0$. Ở đây, :math:`4` bits đầu tiên của dãy $\{ \gamma_n \}$ nhận được từ $K_0$ theo quy tắc

$$\gamma_j = \begin{cases}
    0 \ \text{nếu} \ K_0[j] = 0, \\
    1 \ \text{trong trường hợp khác},
\end{cases}$$

trong đó $K_0[j]$ là khối :math:`64` bits thứ :math:`i` của $K_0$, $\gamma_j \in \{ 0, 1 \}$ với $j = 0, 1, 2, 3$.

Các bit tiếp theo được sinh tương tự theo quy tắc

$$\gamma_j = \begin{cases}
    0 \ \text{nếu} \ K_{j / 4}[j \% 4] = 0, \\
    1 \ \text{trong trường hợp khác},
\end{cases}$$

với $a \% b$ là số dư khi chia :math:`a` cho :math:`b`, $j \in \mathbb{N}$.

Chúng ta sẽ tìm quy luật đối với dãy $\{ \gamma_n \}$.

.. admonition:: skipjack.py
:class: dropdown
```python
# skipjack.py
class SkipJack:
    def __init__(self):
        # F is an 8-bit S-box
        self.F = []
        self.defineF()
        # w1, w2, w3, w4 are 16-bit integers
        self.w1 = 0
        self.w2 = 0
        self.w3 = 0
        self.w4 = 0

    # plaintext is a 64-bit integer
    # key is a list of 10-bytes
    def encrypt(self, plaintext, key):
        self.splitWord(plaintext)

        for round in range(1, 33):
            if (1 <= round <= 8) or (17 <= round <= 24):
                self.A(round, key)
                self.printStatus(round)
            if (9 <= round <= 16) or (25 <= round <= 32):
                self.B(round, key)
                self.printStatus(round)

        return self.appendWords()

    # ciphertext is a 64-bit integer
    # key is a list of 10-bytes
    def decrypt(self, ciphertext, key):
        self.splitWord(ciphertext)

        for round in reversed(range(1, 33)):
            if (25 <= round <= 32) or (9 <= round <= 16):
                self.Binv(round, key)
            if (17 <= round <= 24) or (1 <= round <= 8):
                self.Ainv(round, key)

        return self.appendWords()

    def A(self, round, key):
        c1 = self.w1
        c2 = self.w2
        c3 = self.w3
        self.w1 = self.G(round, key, c1) ^ self.w4 ^ round
        self.w2 = self.G(round, key, c1)
        self.w3 = c2
        self.w4 = c3

    def Ainv(self, round, key):
        c1 = self.w1
        c2 = self.w2
        self.w1 = self.Ginv(round, key, c2)
        self.w2 = self.w3
        self.w3 = self.w4
        self.w4 = c1 ^ c2 ^ round

    def B(self, round, key):
        c1 = self.w1
        c2 = self.w2
        c3 = self.w3
        self.w1 = self.w4
        self.w2 = self.G(round, key, c1)
        self.w3 = c1 ^ c2 ^ round
        self.w4 = c3

    def Binv(self, round, key):
        c1 = self.w1
        self.w1 = self.Ginv(round, key, self.w2)
        self.w2 = self.Ginv(round, key, self.w2) ^ self.w3 ^ round
        self.w3 = self.w4
        self.w4 = c1

    # w is a 16-bit integer
    def G(self, round, key, w):
        g = [0] * 6
        g[0] = (w >> 8) & 0xff
        g[1] = w & 0xff
        j = (4 * (round - 1)) % 10

        for i in range(2, 6): # gives i = 2,3,4,5
            g[i] = self.F[g[i - 1] ^ key[j]] ^ g[i - 2]
            j = (j + 1) % 10

        return (g[4] << 8) | g[5]

    # w is a 16-bit integer
    def Ginv(self, round, key, w):
        g = [0] * 6
        g[4] = (w >> 8) & 0xff
        g[5] = w & 0xff
        j = (4 * (round - 1) + 3) % 10

        for i in reversed(range(4)): # gives i=3,2,1,0
            g[i] = self.F[g[i + 1] ^ key[j]] ^ g[i + 2]
            j = (j - 1) % 10

        return (g[0] << 8) | g[1]

    # append the four 16-bit words w1,w2,w3,w4 to return a 64-bit word
    def appendWords(self):
        x1 = self.w1 << 3 * 16
        x2 = self.w2 << 2 * 16
        x3 = self.w3 << 1 * 16
        x4 = self.w4
        return x1 | x2 | x3 | x4

    # w is a 64-bit word. This function splits w into
    # four 16-bit words which are stored in w1, w2, w3, w4
    def splitWord(self, w):
        self.w1 = (w >> (16 * 3)) & 0xffff
        self.w2 = (w >> (16 * 2)) & 0xffff
        self.w3 = (w >> (16 * 1)) & 0xffff
        self.w4 = w & 0xffff

    # print the round number and the current values of w1,w2,w3,w4
    def printStatus(self, round):
        w = self.appendWords()
        # print("round=" + str(round) + " " + hex(w))

    def defineF(self):
        self.F = [0xa3, 0xd7, 0x09, 0x83, 0xf8, 0x48, 0xf6, 0xf4, 
                  0xb3, 0x21, 0x15, 0x78, 0x99, 0xb1, 0xaf, 0xf9,
                  0xe7, 0x2d, 0x4d, 0x8a, 0xce, 0x4c, 0xca, 0x2e, 
                  0x52, 0x95, 0xd9, 0x1e, 0x4e, 0x38, 0x44, 0x28,
                  0x0a, 0xdf, 0x02, 0xa0, 0x17, 0xf1, 0x60, 0x68, 
                  0x12, 0xb7, 0x7a, 0xc3, 0xc9, 0xfa, 0x3d, 0x53,
                  0x96, 0x84, 0x6b, 0xba, 0xf2, 0x63, 0x9a, 0x19, 
                  0x7c, 0xae, 0xe5, 0xf5, 0xf7, 0x16, 0x6a, 0xa2,
                  0x39, 0xb6, 0x7b, 0x0f, 0xc1, 0x93, 0x81, 0x1b,
                  0xee, 0xb4, 0x1a, 0xea, 0xd0, 0x91, 0x2f, 0xb8,
                  0x55, 0xb9, 0xda, 0x85, 0x3f, 0x41, 0xbf, 0xe0,
                  0x5a, 0x58, 0x80, 0x5f, 0x66, 0x0b, 0xd8, 0x90,
                  0x35, 0xd5, 0xc0, 0xa7, 0x33, 0x06, 0x65, 0x69,
                  0x45, 0x00, 0x94, 0x56, 0x6d, 0x98, 0x9b, 0x76,
                  0x97, 0xfc, 0xb2, 0xc2, 0xb0, 0xfe, 0xdb, 0x20,
                  0xe1, 0xeb, 0xd6, 0xe4, 0xdd, 0x47, 0x4a, 0x1d,
                  0x42, 0xed, 0x9e, 0x6e, 0x49, 0x3c, 0xcd, 0x43,
                  0x27, 0xd2, 0x07, 0xd4, 0xde, 0xc7, 0x67, 0x18,
                  0x89, 0xcb, 0x30, 0x1f, 0x8d, 0xc6, 0x8f, 0xaa,
                  0xc8, 0x74, 0xdc, 0xc9, 0x5d, 0x5c, 0x31, 0xa4,
                  0x70, 0x88, 0x61, 0x2c, 0x9f, 0x0d, 0x2b, 0x87,
                  0x50, 0x82, 0x54, 0x64, 0x26, 0x7d, 0x03, 0x40,
                  0x34, 0x4b, 0x1c, 0x73, 0xd1, 0xc4, 0xfd, 0x3b,
                  0xcc, 0xfb, 0x7f, 0xab, 0xe6, 0x3e, 0x5b, 0xa5,
                  0xad, 0x04, 0x23, 0x9c, 0x14, 0x51, 0x22, 0xf0,
                  0x29, 0x79, 0x71, 0x7e, 0xff, 0x8c, 0x0e, 0xe2,
                  0x0c, 0xef, 0xbc, 0x72, 0x75, 0x6f, 0x37, 0xa1,
                  0xec, 0xd3, 0x8e, 0x62, 0x8b, 0x86, 0x10, 0xe8,
                  0x08, 0x77, 0x11, 0xbe, 0x92, 0x4f, 0x24, 0xc5,
                  0x32, 0x36, 0x9d, 0xcf, 0xf3, 0xa6, 0xbb, 0xac,
                  0x5e, 0x6c, 0xa9, 0x13, 0x57, 0x25, 0xb5, 0xe3,
                  0xbd, 0xa8, 0x3a, 0x01, 0x05, 0x59, 0x2a, 0x46]

    def encrypt_string(self, input_string, key):
        # Check if the input string length is 8
        if len(input_string) != 8:
            print("Input string must be 8 characters long.")
            return None

        # Convert the input string into a numerical representation
        numerical_input = 0
        for char in input_string:
            numerical_input <<= 8  # Shift left by 8 bits
            numerical_input |= ord(char)  # Add ASCII value of the character

        # Encrypt the numerical input using SkipJack algorithm
        ciphertext = self.encrypt(numerical_input, key)

        return ciphertext


def xor(a, b):
    return [x^y for x, y in zip(a, b)]


def encrypt_cfb(Kroot: list[int], IV: list[int], Kprev: list[int]):
    K = [iv for iv in IV]
    for i in range(0, 32, 4):
        sj = SkipJack()
        Kj = int.from_bytes(bytes(K[i:i+4]), 'big')
        Kj = sj.encrypt(Kj, Kroot)
        Kj = list(Kj.to_bytes(8, 'big'))
        Kj = xor(Kj, Kprev[i:i+4])
        K.extend(Kj)
    return K[8:]
```
````

Tiếp theo, chúng ta thử mã hóa với $K_{root}$ bất kì để quan sát xem có quy luật nào cho $K_i$ không.

.. admonition:: find_rules.py
:class: dropdown
```python
# find_rules.py
import random
from skipjack import *

Kroot = list(random.randbytes(10))
IV = [0x43,0x72,0x79,0x70,0x74,0x46,0x6f, 0x78]
Kprev = [0] * 32

for _ in range(16):
    # Encrypt with CFB
    Kprev = encrypt_cfb(Kroot, IV, Kprev)
    # Split K_i into 4 chunks
    s = [bytes(Kprev[i:i+8]).hex() for i in range(0, len(Kprev), 8)]
    # Print K_i as 4 chunks
    print(" ".join(s))
```
````

Dễ thấy bản mã (dạng hex) có dạng sau:

```
0d16dceddfc805c1 47122ce9d3b7983a 02fd48e270666df7 28a8d35b20fbd167
0000000000000000 c4a1be9a50040a49 a266cc2ec5ada370 59c24fdb72f24d49
0d16dceddfc805c1 83b3927383b39273 1374429b74bf2dc5 b2e5c38addfd9bbc
0000000000000000 0000000000000000 90c7d0e8f70cbfb6 b4975af551b93659
0d16dceddfc805c1 47122ce9d3b7983a 923a980a876ad241 f786cb6cd09fa275
0000000000000000 c4a1be9a50040a49 32a11cc632a11cc6 a16a8af18673e3e8
0d16dceddfc805c1 83b3927383b39273 83b3927383b39273 1078044437616d5d
0000000000000000 0000000000000000 0000000000000000 93cb9637b4d2ff2e
0d16dceddfc805c1 47122ce9d3b7983a 02fd48e270666df7 bb63456c94292e49
0000000000000000 c4a1be9a50040a49 a266cc2ec5ada370 ca09d9ecc620b267
0d16dceddfc805c1 83b3927383b39273 1374429b74bf2dc5 212e55bd692f6492
0000000000000000 0000000000000000 90c7d0e8f70cbfb6 275cccc2e56bc977
0d16dceddfc805c1 47122ce9d3b7983a 923a980a876ad241 644d5d5b644d5d5b
0000000000000000 c4a1be9a50040a49 32a11cc632a11cc6 32a11cc632a11cc6
0d16dceddfc805c1 83b3927383b39273 83b3927383b39273 83b3927383b39273
0000000000000000 0000000000000000 0000000000000000 0000000000000000
```

Ta chỉ quan tâm các khối :math:`64` bits toàn các byte `\0` nên bản mã dạng hex trên tương đương với

```
---------------- ---------------- ---------------- ----------------
0000000000000000 ---------------- ---------------- ----------------
---------------- ---------------- ---------------- ----------------
0000000000000000 0000000000000000 ---------------- ----------------
---------------- ---------------- ---------------- ----------------
0000000000000000 ---------------- ---------------- ----------------
---------------- ---------------- ---------------- ----------------
0000000000000000 0000000000000000 0000000000000000 ----------------
---------------- ---------------- ---------------- ----------------
0000000000000000 ---------------- ---------------- ----------------
---------------- ---------------- ---------------- ----------------
0000000000000000 0000000000000000 ---------------- ----------------
---------------- ---------------- ---------------- ----------------
0000000000000000 ---------------- ---------------- ----------------
---------------- ---------------- ---------------- ----------------
0000000000000000 0000000000000000 0000000000000000 0000000000000000
```

Ở đây, `----------------` là khối khác :math:`0`. Thử mã hóa nhiều lần vói $K_{root}$ khác nhau thì ta thấy bản rõ đều có dạng chung như trên.

Từ đó có thể nói dãy $\{ \gamma_n \}$ không phụ thuộc vào khóa. Lúc này ta có thể sử dụng $K_{root}$ tùy ý và sinh ra dãy $\{ \gamma_n \}$.

.. admonition:: solve.py
:class: dropdown
```python
# solve.py
import random
from skipjack import *

with open("ct.txt", encoding="cp1251") as f:
    data = f.read()
    dd = [ord(d.encode("cp1251")) for d in data]

    Kroot = list(random.randbytes(10))
    IV = [0x43,0x72,0x79,0x70,0x74,0x46,0x6f, 0x78]
    Kprev = [0] * 32
    flag = ""
    # Generate K_i with random K_{root}
    for _ in range(len(data) * 2):
        # Calculate K_i from K_{i-1} with CFB
        Kprev = encrypt_cfb(Kroot, IV, Kprev)

        F = bytes(Kprev).hex()
        for i in range(0, len(F), 16):
            if F[i:i+16] == "0" *  16: # Check K_i[j] == 0 for j = 0, 1, 2, 3
                flag += "0"
            else:
                flag += "1"

    gamma = [int(flag[i:i+8], 2) for i in range(0, len(flag), 8)]

    pt = [g ^ d for g, d in zip(gamma, dd)]
    print(bytes(pt))
```
````

Kết quả giải mã là

```
EVALUATION OF THE SITUATION UNTIL NOW IT HAD TO BE EXPECTED THAT THE ENEMY WOULD TRY TO CROSS THE DANUBE WITH THE TROOPS ASSEMBLING AT VIDIN LOMPALANKA AND NEAR DRUTSCHUK WITH THE GOAL TO CUT OFF THE RAILWAYS BETWEEN ORSOVA AND CRAIOVA AND TO PUSH FORWARD TO BUCHAREST SINCE NOVEMBER 1 1918 IT APPEARS THAT THE SERBIAN ARMIES TOGETHER WITH THREE FRENCH DIVISIONS AREENGAGED IN AN ADVANCE TOWARD BELGRADE SEMENDRIA AND THE INTENDED ATTACK AT VIDI AND LOM PALANKA SEEMS TO HAVE BEEN ABANDONED IT HAS TO BE EXPECTED THE DEPLOYMENT OF STRONGER FORCES AT THE DANUBE SOUTH OF SVISTOVRUSTSCHUK SPECIALLY AFTER THE PEACE AGREEMENT OF TURKEY HENCE IT IS MOST LIKELY THAT THE SERBIAN ARMIES REINFORCED BY THE FRENCH INTEND TO CROSS THE DANUBE NEAR BELGRADE SEMENDIA AND THE INTO SOUTHERN REPEAT SOUTHERN HUNGARY WHILE THE TASK OF THE FRENCH ARMY MARCHING SOUTH OF SVISTOV RUTSCHUK REMAINS THE OFFENSIVE TOWARD BUCHAREST IN CONJUNCTION WITH THIS OPERATION IT CANNOT BE RULED OUT THAT THE ROMANIAN FORCES COMING FROM MOLDAVIA OVER THE PASSES OF TOELGYESGIMES AND OITOS WILL INVADE TRANSYLVANIA THUS THE LINES OF COMMUNICATIONS IN THE REAR OF THE OCCUPATION ARMY WHICH HAVE UP TO NOW AS A RESULT OF IS THREATENED WITH ATTACK AND THE FURTHER OCCUPATION OF THE WALL ACHIAAS LAID DOWN IN ORDER FROM OKHEAD QUARTERS 2RMNR11161 WITHOUT DOUBT AND WITH REGARD TO THE AMMUNITION FOOD AND THE COAL STOCK SIT IS UNFEASIBLE IF THE GENERAL ARM ISTICE DOES NOT BECOME EFFECTIVE IN THE FORESEEABLE FUTURE IT IS SUGGESTED THAT THE OCCUPATION ARMY BE WITHDRAWN ATONCE FROM ROMANIA AND TOGETHER WITH THE GERMAN UNITS OF THE FIRST ARMY TO START THE MARCH TOUPPERSILES IA THROUGH HUNGARY APPROVAL IS REQUESTED SIGNED KMIAGROP
```

Ở cuối đoạn có ghi `SIGNED KMIAGROP` nên họ của tác giả là `KMIAGROP`.

### Задача 8. Загадочная ошибка

Thêm một bài reverse engineering C++. Bài này có dùng thêm OpenSSL nhưng mình vẫn không biết làm.

### Задача 9. Генератор гаммы на основе XSL-схемы

#### Câu hỏi

Chúng ta tạo thuật toán sinh khóa cho mã dòng

1. Hàm sinh của khóa là ánh xạ $F: \mathbb{F}_2^{64} \to \mathbb{F}_2^{64}$, được xây dựng dựa trên mô hình XSL, rất phổ biến trong việc thiết kế mã khối.
2. Phép biến đổi không tuyến tính là S-box, dựa trên ánh xạ $S: \mathbb{F}_2^8 \to \mathbb{F}_2^8$. S-box có thể biểu diễn qua hoán vị sau

| | :math:`0` | :math:`1` | :math:`2` | :math:`3` | :math:`4` | :math:`5` | :math:`6` | :math:`7` | :math:`8` | :math:`9` | :math:`10` | :math:`11` | :math:`12` | :math:`13` | :math:`14` | :math:`15` |
| - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | 
| :math:`0` | $208$ | :math:`5` | :math:`11` | $222$ | $234$ | $63$ | $49$ | $228$ | :math:`31` | $202$ | $196$ | :math:`17` | $37$ | $240$ | $254$ | $43$ |
| :math:`1` | $117$ | $160$ | $174$ | $123$ | $79$ | $154$ | $148$ | $65$ | $186$ | $111$ | $97$ | $180$ | :math:`64` | $85$ | $91$ | $142$ |
| :math:`2` | $239$ | $58$ | $52$ | $225$ | $213$ | :math:`0` | :math:`14` | $219$ | :math:`32` | $245$ | $251$ | $46$ | :math:`26` | $207$ | $193$ | :math:`20` |
| :math:`3` | $74$ | $159$ | $145$ | $68$ | $112$ | $165$ | $171$ | $126$ | $133$ | $80$ | $94$ | $139$ | $191$ | $106$ | $100$ | $177$ |
| :math:`4` | $242$ | $39$ | $41$ | $252$ | $200$ | :math:`29` | :math:`19` | $198$ | $61$ | $232$ | $230$ | $51$ | :math:`7` | $210$ | $220$ | :math:`9` |
| :math:`5` | $87$ | $130$ | $140$ | $89$ | $109$ | $184$ | $182$ | $99$ | $152$ | $77$ | $67$ | $150$ | $162$ | $119$ | $121$ | $172$ |
| :math:`6` | $205$ | :math:`24` | :math:`22` | $195$ | $247$ | $34$ | $44$ | $249$ | :math:`2` | $215$ | $217$ | :math:`12` | $56$ | $237$ | $227$ | $54$ |
| :math:`7` | $104$ | $189$ | $179$ | $102$ | $82$ | $135$ | $137$ | $92$ | $167$ | $114$ | $124$ | $169$ | $157$ | $72$ | $70$ | $147$ |
| :math:`8` | $188$ | $105$ | $103$ | $178$ | $134$ | $83$ | $93$ | $136$ | $115$ | $166$ | $168$ | $125$ | $73$ | $156$ | $146$ | $71$ |
| :math:`9` | :math:`25` | $204$ | $194$ | :math:`23` | $35$ | $246$ | $248$ | $45$ | $214$ | :math:`3` | :math:`13` | $216$ | $236$ | $57$ | $55$ | $226$ |
| :math:`10` | $131$ | $86$ | $88$ | $141$ | $185$ | $108$ | $98$ | $183$ | $76$ | $153$ | $151$ | $66$ | $118$ | $163$ | $173$ | $120$ |
| :math:`11` | $38$ | $243$ | $253$ | $40$ | :math:`28` | $201$ | $199$ | :math:`18` | $233$ | $60$ | $50$ | $231$ | $211$ | :math:`6` | :math:`8` | $221$ |
| :math:`12` | $158$ | $75$ | $69$ | $144$ | $164$ | $113$ | $127$ | $170$ | $81$ | $132$ | $138$ | $95$ | $107$ | $190$ | $176$ | $101$ |
| :math:`13` | $59$ | $238$ | $224$ | $53$ | :math:`1` | $212$ | $218$ | :math:`15` | $244$ | $33$ | $47$ | $250$ | $206$ | :math:`27` | :math:`21` | $192$ |
| :math:`14` | $161$ | $116$ | $122$ | $175$ | $155$ | $78$ | :math:`64` | $149$ | $110$ | $187$ | $181$ | $96$ | $84$ | $129$ | $143$ | $90$ |
| :math:`15` | :math:`4` | $209$ | $223$ | :math:`10` | $62$ | $235$ | $229$ | $48$ | $203$ | :math:`30` | :math:`16` | $197$ | $241$ | $36$ | $42$ | $255$ |

Ở bảng trên, phần tử ở hàng :math:`i` và cột :math:`j` ($0 \leqslant i, j \leqslant 15$) là giá trị S-box của $16i + j$.

3. Biến đổi tuyến tính :math:`L` dựa trên LFSR, nghĩa là $L: \mathbb{F}_2^{64} \to \mathbb{F}_2^{64}$ với hệ số của đa thức đặc trưng được viết dưới dạng `0x12a9d9b8c0edf6e79` (ở đây bit cao là hệ số của hạng tử bậc cao, most significant bit). Ở mỗi vòng, thanh ghi sẽ được khai báo bởi một trong các hằng số của vòng và đi qua :math:`64` vòng.

Như vậy, quá trình sinh khóa có dạng

$$k^{(i)} = S(k^{(i-1)}) \oplus L^{64}(C^{(i)}),$$

với $k^{(i - 1)}$ là khóa được sinh trước đó, $k^{(0)}$ là khóa đầu vào để sinh toàn bộ dãy khóa, và $C^{(i)}$ là hằng số của vòng, gồm

- 0x6ea276726c487ab8,
- 0x5d27bd10dd849401,
- 0xdc87ece4d890f4b3,
- 0xba4eb92079cbeb02,
- 0xb2259a96b4d88e0b,
- 0xe7690430a44f7f03,
- 0x7bcd1b0b73e32ba5,
- 0xb79cb140f2551504,
- 0x156f6d791fab511d,
- 0xeabb0c502fd18105,
- 0xa74af7efab73df16,
- 0x0dd208608b9efe06,
- 0xc9e8819dc73ba5ae,
- 0x50f5b570561a6a07,
- 0xf6593616e6055689,
- 0xadfba18027aa2a08.

Phương trình mã hóa có dạng

$$y^{(i)} = x^{(i)} \oplus k^{(i)}$$

với $y^{(i)}, x^{(i)} \in \mathbb{F}_2^{64}$.

Người truyền tin muốn kiểm tra độ an toàn của thuật toán sinh khóa. Anh ta mã hóa một phần của đoạn văn đầu trong tiểu thuyết "Alice in Wonderland" (tiếng Anh) và thu được bản mã là

```
3291999942924df2eb53323558623a949f5d90c4ba2cf0d9883c21ee0fcd8e5348de9d8fecee8b55693a5682396c33b57cdcaa6946fdfe5c50660656cfb03fbfa682db7f20837e3d406340ebf301b8223a7ada2820b5e15756ab0f54e2af8008f181e474757afbdfaf65525e88dadce723653bfc35398852d3e82cfb4815f3f6
```

Nhiệm vụ của bạn là phân tích thuật toán mã hóa và nếu có lỗ hổng, hãy khai thác nó và tìm khóa mã hóa.

#### [TODO] Giải

### Задача 10. Регистровое преобразование

#### Câu hỏi

Eva chặn được một đoạn gamma được sinh dựa trên shift register (xem chi tiết ở file `PQR.py` bên dưới):

$$\gamma = 01000000000000010100100001101000111101100010001111.$$

Hãy tìm giá trị register ban đầu.

.. admonition:: PQR.py
```python
def maj(x1,x2,x3):
    return (x1*x2+x1*x3+x2*x3) % 2
   
def P(state):
    next_state = []
    for i in range(1, len(state)):
        next_state.append(state[i])
    next_state.append((state[0]+state[1]+state[2]+state[5]) % 2)
    return next_state   
    
def Q(state):
    next_state = []
    for i in range(1, len(state)):
        next_state.append(state[i])
    next_state.append((state[0]+state[1]) % 2)
    return next_state
    
    
def R(state):
    next_state = []
    for i in range(1, len(state)):
        next_state.append(state[i])
    next_state.append((state[0]+state[3]) % 2)
    return next_state
    
def get_gamma(stateP, stateQ, stateR, gamma_len):
    gamma_bits = []
    for i in range(gamma_len):
        gamma_bits.append((maj(stateP[3],stateP[4],stateP[6])+maj(stateQ[5],stateQ[8],stateQ[12])) % 2)
        if stateR[4] == maj(stateR[2], stateR[3], stateR[4]):
            stateP = P(stateP)
        if stateR[2] == maj(stateR[2], stateR[3], stateR[4]):
            stateQ = Q(stateQ)
        stateR = R(stateR)
    return gamma_bits  
    
    
def get_gamma_from_password(password_bytes, n):
    key = [int(x) for x in bin(int.from_bytes(password_bytes, "big"))[2:].zfill(46)]
    print(key)
    stateP = key[0:19]
    stateQ = key[19:19+22]
    stateR = key[19+22:19+22+5]
    return get_gamma(stateP, stateQ, stateR, n)

get_gamma_from_password(b'ahihi', 4)
```
````

#### [TODO] Giải

### Задача 11. Трудный PBKDF

#### Câu hỏi

Việc trao đổi file diễn ra trên kênh truyền. Để mã hóa file chúng ta dùng thuật toán sau dựa trên mật khẩu.

Đầu vào là mật khẩu $password$ gồm :math:`4` chữ số thập phân, và thông điệp $pt$.

Ta tính khóa $key = \mathsf{SHA256}(password)$ và initial vector là

$$IV = \mathsf{PBKDF-HMAC-SHA256}(salt, 2^{30}, 128).$$

Sử dụng thuật toán mã khối AES256 với mode CBC và khóa $key$, initial vector $IV$, và padding bằng PKCS#7.

Chúng ta có một số file đã bị mã hóa. Biết rằng, qua kênh truyền có thể có nhiễu nên file có thể chứa một số bytes đã bị hỏng. Một trong số đó chứa flag, hãy tìm nó.

#### [TODO] Giải
