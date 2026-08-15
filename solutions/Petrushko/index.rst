Курс высшей математики: Теория вероятностей
*******************************************

Lời giải cho quyển sách :cite:`Pet08`. Đây là quyển mình được học trên trường.

Xác suất không liên tục
=======================

**Bài 1.** Có :math:`10` đội được chia ngẫu nhiên làm hai nhóm. Tính xác xuất để hai đội mạnh nhất vào hai nhóm khác nhau? ... cùng một nhóm? ... cùng vào nhóm thứ nhất?

**Giải.**

1. Một đội mạnh có :math:`C^1_2` cách chọn, đội còn lại 
   sẽ vào nhóm còn lại. Tiếp theo, chọn :math:`4` đội cho 
   nhóm đầu có :math:`C^4_8` cách, :math:`4` đội cho nhóm 
   còn lại có :math:`C^4_4` cách. Không gian mẫu là 
   :math:`C^5_{10} \cdot C^5_5`. Vậy đáp án là :math:`\dfrac{5}{9}`.
2. Hai đội mạnh vào cùng một nhóm, có :math:`C^1_2` cách. 
   Chọn :math:`3` đội cho nhóm đó có :math:`C^3_8` cách. 
   Nhóm còn lại sẽ có :math:`C^5_5` cách. Không gian mẫu 
   là :math:`C^5_{10} \cdot C^5_5`. Vậy đáp án là :math:`\dfrac{4}{9}`.
3. Hai đội mạnh đều vào nhóm đầu nên chỉ có :math:`1` 
   cách chọn. Chọn :math:`3` đội còn lại của nhóm đầu 
   có :math:`C^3_8` cách. Chọn :math:`5` đội cho nhóm 
   còn lại có :math:`C^5_5` cách. Không gian mẫu là 
   :math:`C^5_{10} \cdot C^5_5`. Vậy đáp án là :math:`\dfrac{2}{9}`.

**Bài 2.** Một bộ bài đầy đủ có :math:`52` lá. Lấy ngẫu nhiên 
ra ba lá. Tính xác suất để ba lá đó là :math:`3`, :math:`7` và át? 
Tính xác suất để ba lá đó được lấy theo thứ tự trên?

**Giải.**

1. Không gian mẫu là :math:`C^3_{52}`. Lấy một trong bốn 
   con :math:`3` có :math:`C^1_4` cách, tương tự cho lấy 
   con :math:`7` có :math:`C^1_4` cách và lấy con át 
   có :math:`C^1_4` cách. Vậy đáp án là 
   :math:`\dfrac{4 \cdot 4 \cdot 4}{C^3_{52}} = \dfrac{16}{5525}`.
2. Không gian mẫu là :math:`A^3_{52}` vì có xét thứ tự. 
   Cách chọn ba lá bài vẫn như trước. Vậy đáp án là 
   :math:`\dfrac{4 \cdot 4 \cdot 4}{A^3_{52}} = \dfrac{8}{16575}`.

**Bài 3.** Trên đoạn thẳng :math:`OA` độ dài :math:`L` chọn 
ngẫu nhiên hai điểm :math:`B` và :math:`C`, điều kiện là :math:`C` 
nằm bên phải so với :math:`B`. Tính xác suất để độ dài :math:`BC` 
nhỏ hơn độ dài :math:`OB`.

**Giải.**

.. figure:: figures/ch01-ex03.*

Gọi :math:`L` là độ dài đoạn :math:`OA`. Đặt :math:`x` là 
độ dài :math:`OB` và :math:`y` là độ dài :math:`BC`. Khi đó 
các độ dài này phải thỏa mãn các phương trình

.. math:: 

    \begin{cases}
        y < x \\
        0 < x + y < L \\
        x > 0, y > 0
    \end{cases}


Xác suất trên tương ứng biểu diễn hình học. Khi đó 
xác suất là tỉ lệ diện tích:

1. Không gian mẫu là tam giác vuông nên diện tích 
   là :math:`\dfrac{L^2}{2}`.
2. Vùng giới hạn bởi các đường thẳng :math:`y = 0`, 
   :math:`y = x` và :math:`x + y = L` là tam giác 
   với diện tích là :math:`\dfrac{L \cdot \dfrac{L}{2}}{2} = \dfrac{L^2}{4}`.

Đáp án: :math:`\dfrac{1}{2}`.

**Bài 4.** Có :math:`10` bilet nằm trên bàn giám thị 
được đánh số từ :math:`1` tới :math:`10`. Tính xác suất 
để các sinh viên lấy bilet theo thứ tự từ :math:`1` tới 
:math:`10`.

**Giải.** Không gian mẫu là :math:`10!` cách lấy :math:`10` 
bilet theo tứ tự bất kì.

Để lấy :math:`10` bilet theo thứ tự, chỉ có 
duy nhất một cách lấy lần lượt :math:`1`, :math:`2`, ...

Đáp án: :math:`\dfrac{1}{10!}`.

**Bài 5.** Bốn người vào thang máy ở tầng :math:`1` của 
tòa nhà :math:`9` tầng. Biết rằng xác suất mỗi người 
rời khỏi thang máy là như nhau cho các tầng từ :math:`2` 
tới :math:`9`. Tính xác suất để: a) mọi người rời thang máy 
ở các tầng khác nhau; b) mọi người rời thang máy cao hơn 
tầng :math:`5`; c) ở tầng :math:`3` không ai rời thang máy.

**Giải.** Không gian mẫu là :math:`8^4` vì mỗi người 
đều có :math:`8` cách chọn ra các tầng từ :math:`2` 
tới :math:`9`.

a) Chọn :math:`4` tầng mà mỗi người sẽ ra, có :math:`A^4_8` 
   cách vì thứ tự có thể khác nhau. Đáp án là 
   :math:`\dfrac{A^4_8}{8^4} = \dfrac{105}{256}`.

b) Tầng cao hơn :math:`5` có :math:`4` phương án :math:`6`, 
   :math:`7`, :math:`8`, :math:`9`. Khi đó mỗi người có 
   :math:`4` cách chọn nên bốn người có :math:`4^4` cách chọn. 
   Đáp án là :math:`\dfrac{4^4}{8^4} = \dfrac{1}{16}`.

c) Do không ai rời thang máy tầng :math:`3` nên mỗi người 
   có :math:`7` cách chọn là :math:`2`, :math:`4`, :math:`5`, 
   :math:`6`, :math:`7`, :math:`8` và :math:`9`. Do đó 
   số cách chọn của bốn người là :math:`7^4`. Đáp án là 
   :math:`\dfrac{7^4}{8^4} = \dfrac{2401}{4096}`.

**Bài 6.** Lấy ngẫu nhiên bốn chữ số và xếp chúng theo vị trí 
bất kì. Tính xác suất để thu được số có :math:`4` chữ số? Tính 
xác suất để thu được số có :math:`4` chữ số chia hết cho :math:`5`?

**Giải.** Không gian mẫu là :math:`10^4` vì có :math:`10` 
chữ số từ :math:`0` tới :math:`9`.

1. Để tạo thành số có :math:`4` chữ số thì chữ số đầu phải 
   khác :math:`0` nên có :math:`9` cách chọn. Ba vị trí 
   còn lại mỗi vị trí :math:`10` cách chọn. Như vậy số 
   cách chọn là :math:`9 \cdot 10^3` nên đáp án là 
   :math:`\dfrac{9}{10}`.
2. Tương tự, để tạo thành số có :math:`4` chữ số thì chữ số 
   đầu có :math:`9` cách chọn. Vị trí cuối phải là :math:`0` 
   hoặc :math:`5` để chia hết cho :math:`5`. Hai chữ số ở 
   giữa tùy ý nên có :math:`10^2` cách. Như vậy số cách chọn 
   là :math:`9 \cdot 2 \cdot 10^2`, nên đáp án là 
   :math:`\dfrac{9}{50}`.

**Bài 7.** Có :math:`20` bilet exam trên bàn giám thị theo 
thứ tự ngẫu nhiên. :math:`10` sinh viên lần lượt bốc bilet 
ngẫu nhiên. Tính xác suất để bilet số :math:`1` và :math:`2` 
không được chọn.

**Giải.** Không gian mẫu là :math:`A^{10}_{20}` do các sinh viên 
bốc lần lượt nên sẽ có thứ tự.

Biến cố bilet số :math:`1` và :math:`2` không được chọn, như vậy 
sẽ còn :math:`18` trường hợp và :math:`10` sinh viên sẽ bốc 
ngẫu nhiên :math:`10` bilet trong này. Do đó có :math:`A^{10}_{18}` cách.

Đáp án: :math:`\dfrac{A^{10}_{18}}{A^{10}_{20}} = \dfrac{9}{38}`.

**Bài 8.** Trong hộp có :math:`6` quả bóng trắng, :math:`4` quả bóng 
đen và :math:`2` quả bóng đỏ. Lấy ngẫu nhiên :math:`4` quả bóng. Tính 
xác suất để trong số :math:`4` quả đó chỉ có bóng đen và bóng đỏ.

**Giải.** Có tất cả :math:`6+4+2 = 12` quả bóng. Không gian mẫu 
là :math:`C^4_{12}`.

Bóng đen và bóng đỏ có tất cả :math:`4+2 = 6` quả. Lấy :math:`4` trong số 
đó có :math:`C^4_6` cách.

Đáp án: :math:`\dfrac{C^4_6}{C^4_{12}} = \dfrac{1}{33}`.

**Bài 9.** Có :math:`10` quyển sách, trong đó có :math:`3` quyển màu đỏ, 
được xếp theo thứ tự ngẫu nhiên trên kệ. Tính xác suất để :math:`3` 
quyển màu đỏ nằm liền kề nhau.

**Giải.** Không gian mẫu là :math:`10!`.

Nếu xem :math:`3` quyển đỏ là cùng một khối thì lúc này trên kệ 
có :math:`8` quyển. Số cách chọn là :math:`8!`. Bên trong khối đó, 
:math:`3` quyển màu đỏ có thể xếp theo thứ tự bất kì nên có :math:`3!` 
hoán vị. Như vậy tổng số cách xếp là :math:`8! \cdot 3!`.

Đáp án là :math:`\dfrac{8! \cdot 3!}{10!} = \dfrac{1}{15}`.

**Bài 10.** Gieo ba con súc sắc. Tính xác suất các biến cố: :math:`A` - 
các súc sắc cho các số khác nhau; :math:`B` - các súc sắc ra cùng số.

**Giải.** Không gian mẫu là :math:`6^3`.

1. Các súc sắc cho số khác nhau nên có :math:`A^3_6` cách chọn 
   vì có tính hoán vị. Đáp án là :math:`P(A) = \dfrac{A^3_6}{6^3} = \dfrac{5}{9}`.
2. Các súc sắc ra cùng số có :math:`6` trường hợp. Đáp án 
   là :math:`P(B) = \dfrac{6}{6^3} = \dfrac{1}{36}`.

**Bài 11.** Trong tủ có :math:`5` đôi tất. Lấy ngẫu nhiên :math:`2` 
chiếc tất. Tính xác suất để :math:`2` chiếc tất đó cùng đôi.

**Giải.** Không gian mẫu :math:`C^2_{10}`.

Lấy :math:`2` chiếc cùng đôi nghĩa là lấy một trong :math:`5` 
đôi. Vậy có :math:`5` cách chọn.

Đáp án: :math:`\dfrac{5}{C^2_{10}} = \dfrac{1}{9}`.

**Bài 13.** Trong nhóm có :math:`4` nam và :math:`4` nữ được chia thành 
hai nhóm nhỏ, mỗi nhóm :math:`4` người. Tính xác suất để ở mỗi nhóm nhỏ 
có :math:`2` nam và :math:`2` nữ.

**Giải.** Do có tất cả :math:`8` người nên để chia thành hai nhóm nhỏ 
thì ta chọn :math:`4` người cho nhóm đầu, có :math:`C^4_8` cách. Nhóm thứ hai 
có :math:`C^4_4` cách. Tuy nhiên có khả năng bị lặp (chọn A-B rồi C-D hoàn toàn 
giống chọn C-D rồi A-B). Do đó không gian mẫu cần chia :math:`2!`, nên suy ra 
:math:`\lvert \Omega \rvert = \dfrac{C^4_8 \cdot C^4_4}{2!} = 35` cách.

Tương tự, ta chọn :math:`2` nam cho nhóm đầu thì có :math:`C^2_4` cách 
và cho nhóm thứ hai có :math:`C^2_2` cách. Như vậy có :math:`6` cách 
chia :math:`4` nam vào :math:`2` nhóm. Nữ cũng vậy, có :math:`6` cách. 
Theo bên trên, hai nhóm này có thể bị lặp nên cần phải chia :math:`2!`, 
suy ra số cách chia mỗi nhóm :math:`2` nam :math:`2` nữ 
là :math:`\dfrac{6 \cdot 6}{2!} = 18`.

Đáp án: :math:`\dfrac{18}{35}`.

**Bài 14.** Bên trong hình tròn bán kính :math:`R` chọn ngẫu nhiên một điểm. 
Tính xác suất để điểm đó: a) nằm bên trong hình vuông nội tiếp; b) nằm bên 
trong tam giác đều nội tiếp.

**Giải.** Bài này sử dụng xác suất hình học. Khi đó không gian mẫu là 
diện tích hình tròn bán kính :math:`R`, hay :math:`\lvert \Omega \rvert = \pi R^2`.

a) Biến cố điểm nằm trong hình vuông nội tiếp có xác suất bằng diện tích 
   hình vuông chia diện tích hình tròn. Hình vuông nội tiếp đường tròn 
   bán kính :math:`R` có đường chéo bằng :math:`2R` nên cạnh là :math:`R \sqrt{2}`. 
   Đáp án là :math:`\dfrac{2R^2}{\pi R^2} = \dfrac{2}{\pi}`.

b) Tương tự, tam giác nội tiếp thì cạnh nối từ tâm tới đỉnh là :math:`R`, 
   bằng :math:`2R/3` độ dài đường cao nên suy ra đường cao là :math:`3R/2`, 
   suy ra cạnh là :math:`R \sqrt{3}`. Diện tích tam giác nội tiếp là 
   :math:`\dfrac{R \sqrt{3} \cdot 3R/2}{2} = \dfrac{3\sqrt{3} \cdot R^2}{4}` 
   nên đáp án là :math:`\dfrac{3\sqrt{3}}{4 \pi}`.

**Bài 15.** Trong một ngày có hai chuyến tàu cập cảng để dỡ hàng. 
Chuyến tàu thứ nhất cần :math:`6` tiếng để dỡ hàng, trong khi chuyến tàu 
thứ hai cần :math:`8` tiếng. Hai chuyến tàu đến cảng không phụ thuộc 
vào nhau. Tính xác suất để không chuyến tàu nào phải chờ chuyến tàu kia 
dỡ hàng xong mới được cập cảng.

**Giải.** Gọi :math:`x` là thời gian chuyến tàu đầu cập cảng. Do mất :math:`6` 
giờ để dỡ hàng nên tàu phải cập cảng trước :math:`18` giờ. Như vậy :math:`0 \leqslant x \leqslant 18`.

Tương tự, gọi :math:`y` là thời gian chuyến tàu thứ hai cập cảng, suy 
ra :math:`0 \leqslant y \leqslant 16`.

Đến đây ta có hai trường hợp:

1. Chuyến tàu đầu cập cảng trước. Khi đó chuyến tàu thứ hai phải đến 
   sau khi chuyến tàu đầu dỡ hàng xong. Do đó :math:`y \geqslant x + 6`.
2. Chuyến tàu thứ hai cập cảng trước. Tương tự, chuyến tàu đầu phải 
   cập cảng sau khi chuyến thứ hai dỡ hàng xong. Do đó :math:`x \geqslant y + 8`.

Không gian mẫu là diện tích hình chữ nhật giới hạn bởi :math:`x=0`, 
:math:`x=18`, :math:`y=0` và :math:`y=16`.

Không gian biến cố nằm trong hình giới hạn bởi các đường thẳng :math:`x=0`, 
:math:`x=18`, :math:`y=0`, :math:`y=16`, :math:`x+6=y` và :math:`x-8=y`.

Đáp án: :math:`\dfrac{25}{72}`.

Quy tắc cộng và nhân xác suất
=============================

**Bài 1.** Xác suất bóng đèn hoạt động tốt trong khoảng thời gian xác định 
của mỗi phần tử là :math:`0,8`. Một hệ thống có ba phần tử như hình. Tính độ 
hoạt động tốt trong mỗi phần tử.

**Giải.** Nào vẽ hình rồi giải sau :)))

**Bài 2.** Trong hộp có :math:`7` quả bóng trắng và :math:`3` quả bóng đen. 
Lấy ngẫu nhiên lần lượt từng quả đến khi lấy được bóng đen. Tính xác suất 
đến khi dừng lại lấy được :math:`4` quả bóng nếu: a) lấy có trả lại; b) lấy 
không trả lại.

**Giải.** Không gian mẫu gồm các cách lấy ra :math:`4` quả bóng.

a) Khi lấy có trả lại, ở mỗi lần lấy có 10 cách chọn nên không gian mẫu 
   :math:`\lvert \Omega \rvert = 10^4`. Theo đề bài, nếu lấy có trả lại 
   :math:`4` quả bóng, :math:`3` quả đầu là bóng trắng và có :math:`7^3` 
   cách chọn. Quả bóng cuối màu đen, có :math:`3` cách chọn. Như vậy có 
   :math:`7^3 \cdot 3` cách chọn. Đáp án là :math:`\dfrac{1029}{10000}`.

b) Khi lấy không trả lại, không gian mẫu là số cách lấy :math:`4` quả bóng 
   từ :math:`10` quả bóng có thứ tự nên :math:`\lvert \Omega \rvert = A^4_{10}`. 
   Số cách chọn :math:`4` quả sao cho :math:`3` quả đầu màu trắng là 
   :math:`A^3_7`, và quả cuối màu đen là :math:`A^1_3`. Đáp án là 
   :math:`\dfrac{A^3_7 \cdot A^1_3}{A^4_{10}} = \dfrac{1}{8}`.

**Bài 3.** Trong một bộ domino có :math:`28` quân lấy ngẫu nhiên :math:`7` 
quân. Tính xác suất có ít nhất một quân có nút :math:`6`.

**Giải.** Gọi :math:`A` là biến cố ít nhất một quân có nút :math:`6`. 
Khi đó :math:`\bar{A}` là biến cố không có quân nào có nút :math:`6`.

Không gian mẫu là :math:`A^7_{28}`.

Do :math:`\bar{A}` không chứa các quân có nút :math:`6` nên sẽ có 
:math:`28-7 = 21` quân (bỏ các cặp :math:`0`-:math:`6`, 
:math:`1`-:math:`6`, ..., :math:`6`-:math:`6`).

Suy ra :math:`P(\bar{A}) = \dfrac{A^7_{21}}{A^7_{28}} = \dfrac{323}{3289}`.

Đáp án: :math:`P(A) = 1 - P(\bar{A}) = \dfrac{2966}{3289}`.

**Bài 4.** Tung :math:`4` cục súc sắc. Tính xác suất để chúng ra các mặt khác nhau.

**Giải.** Đáp án: :math:`\dfrac{A^4_6}{6^4} = \dfrac{5}{18}`.

**Bài 5.** Trong hộp có :math:`5` quả bóng trắng, :math:`7` quả bóng đỏ 
và :math:`8` quả bóng xanh. Lấy ngẫu nhiên ra :math:`2` quả. Tính xác suất 
để hai quả đó cùng màu.

**Giải.** Gọi :math:`A` - biến cố lấy hai quả bóng cùng màu.

Gọi :math:`A_1, A_2, A_3` lần lượt là biến cố lấy hai quả bóng trắng, 
hai quả bóng đỏ và hai quả bóng xanh.

Khi đó :math:`A = A_1 \cup A_2 \cup A_3`.

Đáp án:

.. math:: P(A) = P(A_1) + P(A_2) + P(A_3) = \dfrac{C^2_5 + C^2_7 + C^2_8}{C^2_{5+7+8}} = \dfrac{59}{190}.

**Bài 6.** Hai cung thủ bắn tên đồng thời độc lập nhau. Xác suất mỗi người 
bắn trúng là :math:`0,2`. Tính xác suất để chỉ một người bắn trúng.

**Giải.** Chọn một trong hai người bắn trúng, có :math:`2` cách.

Nếu một người bắn trúng thì xác suất là :math:`0,2`. Người còn lại sẽ 
bắn trượt với xác suất :math:`0,8`.

Đáp án: :math:`2 \cdot 0,2 \cdot 0,8 = 0,32`.

**Bài 7.** :math:`20` đội bóng tham gia giải đấu. Trong giải đấu có 
:math:`4` giải thưởng sẽ được trao cho :math:`4` đội xuất sắc nhất. 
Giả sử :math:`20` đội được chia thành :math:`4` nhóm được đánh số, 
mỗi nhóm :math:`5` đội. Tính xác suất để mỗi nhóm có một đội đạt 
giải? Tính xác suất để nhóm đầu không có đội nào đạt giải.

**Giải.** Số cách chọn :math:`5` đội cho nhóm đầu là :math:`C^5_{20}`, 
cho nhóm thứ hai là :math:`C^5_{15}`, cho nhóm thứ ba là :math:`C^5_{10}` 
và nhóm cuối là :math:`C^5_5`. Do có xét thứ tự nhóm nên vẫn tính các 
hoán vị. Ta suy ra

.. math:: \lvert \Omega \rvert = C^5_{20} \cdot C^5_{15} \cdot C^5_{10} \cdot C^5_5.

Trong :math:`4` đội đạt giải, chọn một đội cho vào nhóm :math:`1` thì 
có :math:`4` cách chọn. Tiếp theo chọn :math:`4` đội trong :math:`16` 
đội không đạt giải vào nhóm :math:`1` thì có :math:`C^4_{16}` cách. 
Tương tự cho các nhóm :math:`2`, :math:`3`, :math:`4` nên đáp án là

.. math:: P(A) = \dfrac{4 \cdot C^4_{16} \cdot 3 \cdot C^4_{12} \cdot 2 \cdot C^4_8 \cdot 1 \cdot C^4_4}{C^5_{20} \cdot C^5_{15} \cdot C^5_{10} \cdot C^5_5} = \dfrac{125}{969}

Nếu nhóm đầu không có đội nào đạt giải, chọn :math:`5` trong số :math:`16` 
đội không đạt giải thì có :math:`C^5_{16}` cách. Lúc này còn lại :math:`15` đội. 
Chọn :math:`5` đội cho nhóm thứ :math:`2`, :math:`5` đội cho nhóm thứ :math:`3` 
và :math:`5` đội cho nhóm thứ :math:`4` có :math:`C^5_{15} \cdot C^5_{10} \cdot C^5_5` 
cách. Đáp án câu (b) là

.. math:: P(B) = \dfrac{C^5_{16} \cdot C^5_{15} \cdot C^5_{10} \cdot C^5_{5}}{C^5_{20} \cdot C^5_{15} \cdot C^5_{10} \cdot C^5_5} = \dfrac{91}{323}

**Bài 8.** Trong hộp đầu có :math:`2` quả bóng trắng và :math:`3` quả bóng đen, 
trong hộp thứ hai có :math:`1` trắng và :math:`2` xanh, trong hộp thứ ba có :math:`3` 
trắng và :math:`1` đỏ. Từ mỗi hộp lấy ngẫu nhiên một quả bóng. Tính xác suất 
các biến số sau: :math:`A` - { chỉ lấy ra một bóng trắng }; :math:`B` - { lấy ít nhất 
một bóng trắng }; :math:`C` - { lấy ra các màu khác nhau }.

**Giải.** Không gian mẫu là :math:`\lvert \Omega \rvert = (2 + 3) \cdot (1 + 2) \cdot (3 + 1) = 60`.

Đặt :math:`A_1, A_2, A_3` lần lượt là biến cố quả bóng trắng lấy từ hộp :math:`1`, 
:math:`2` và :math:`3`. Khi đó :math:`A = A_1 \cup A_2 \cup A_3`.

- Nếu quả bóng trắng lấy từ hộp :math:`1` thì có :math:`2` cách chọn. Ở hộp 
  thứ hai và thứ ba phải lấy ra quả khác màu trắng nên có :math:`2 \cdot 1` 
  cách chọn. Suy ra :math:`P(A_1) = \dfrac{2 \cdot 2 \cdot 1}{60} = \dfrac{1}{15}`.
- Nếu quả bóng trắng lấy từ hộp :math:`2` thì có :math:`1` cách chọn. Ở hộp 
  đầu và hộp thứ ba phải lấy ra quả khác màu trắng nên có :math:`3 \cdot 1` 
  cách. Vậy :math:`P(A_2) = \dfrac{1 \cdot 3 \cdot 1}{60} = \dfrac{1}{20}`.
- Nếu quả bóng trắng lấy từ hộp :math:`3` thì có :math:`3` cách chọn. Ở hộp đầu 
  và hộp thứ hai lấy ra quả khác màu trắng có :math:`3 \cdot 2` cách chọn. 
  Vậy :math:`P(A_3) = \dfrac{3 \cdot 3 \cdot 2}{60} = \dfrac{3}{10}`.

Như vậy

.. math:: P(A) = P(A_1) + P(A_2) + P(A_3) = \dfrac{1}{15} + \dfrac{1}{20} + \dfrac{3}{10} = \dfrac{5}{12}.

Do :math:`B` là biến cố lấy ít nhất một bóng trắng nên :math:`\bar{B}` là biến cố 
không lấy ra bóng trắng nào. Khi đó ở hộp :math:`1` có :math:`3` cách chọn (đen), 
hộp :math:`2` có :math:`2` cách chọn (xanh) và hộp :math:`3` có :math:`1` cách chọn 
(đỏ), suy ra :math:`P(\bar{B}) = \dfrac{3 \cdot 2 \cdot 1}{60} = \dfrac{1}{10}`.

Như vậy :math:`P(B) = 1 - P(\bar{B}) = \dfrac{9}{10}`.

Khi lấy ra ba quả bóng khác màu nhau có các trường hợp theo thứ tự hộp là:

- trắng-xanh-đỏ: có :math:`2 \cdot 2 \cdot 1` cách chọn
- đen-trắng-đỏ: có :math:`3 \cdot 1 \cdot 1` cách chọn
- đen-xanh-trắng: có :math:`3 \cdot 2 \cdot 3` cách chọn
- đen-xanh-đỏ: có :math:`3 \cdot 2 \cdot 1` cách chọn

Như vậy

.. math:: P(C) = \dfrac{2 \cdot 2 \cdot 1 + 3 \cdot 1 \cdot 1 + 3 \cdot 2 \cdot 3 + 3 \cdot 2 \cdot 1}{60} = \dfrac{31}{60}.

**Bài 9.** Một bộ bài gồm :math:`36` lá. Lấy ngẫu nhiên hai lá. Tính xác suất 
để hai lá đó có màu đỏ.

**Giải.** Không gian mẫu :math:`\lvert \Omega \rvert = C^2_{26}`.

Lấy hai trong :math:`36/2=18` lá đỏ có :math:`C^2_{18}` cách.

Đáp án: :math:`\dfrac{C^2_{18}}{C^2_{26}} = \dfrac{17}{70}`.

**Bài 10.** Trong thùng có :math:`3` bóng đèn hỏng và :math:`7` bóng đèn tốt. 
Lấy ngẫu nhiên các bóng lần lượt đến khi lấy được :math:`2` bóng tốt thì dừng. 
Tính xác suất để lấy một nửa số bóng đèn.

**Giải.** Không gian mẫu là :math:`A^5_{10}`.

Trong số bốn bóng đèn đầu sẽ có một bóng tốt và :math:`3` bóng hỏng. Bóng đèn 
thứ :math:`5` sẽ là bóng tốt. Như vậy ta chọn vị trí cho bóng tốt trong :math:`4` 
vị trí đầu, có :math:`4` cách chọn. Chọn bóng tốt cho vị trí đó có :math:`7` 
cách chọn. Chọn :math:`3` bóng hỏng cho :math:`3` vị trí còn lại có thứ tự, 
có :math:`A^3_3` cách.

Chọn bóng đèn tốt cho vị trí thứ :math:`5` có :math:`6` cách chọn.

Đáp án: :math:`\dfrac{4 \cdot 7 \cdot A^3_3 \cdot 6}{A^5_{10}} = \dfrac{1}{30}`.

Quy tắc cộng và nhân xác suất (tiếp theo)
=========================================

**Bài 1.** Từ một bộ bài lấy ngẫu nhiên lần lượt bốn lá. Tính xác suất 
để tất cả các lá khác chất nhau? Tính xác suất để tất cả các lá khác số nhau?

**Giải.** Bộ bài có :math:`36` lá (bài Nga) nên có không gian 
mẫu :math:`\lvert \Omega \rvert = A^4_{36}`.

Gọi :math:`A` là biến cố tất cả các lá khác chất nhau.

- Chọn chất cho lá thứ nhất có :math:`4` cách chọn. Chọn lá thứ nhất 
  có :math:`9` cách chọn (trong chất đó).
- Chọn chất cho lá thứ hai có :math:`4` cách chọn. Chọn lá thứ hai 
  có :math:`9` cách chọn (trong chất đó).
- Tương tự cho lá thứ ba và thứ tư.

Như vậy :math:`\lvert \Omega_A \rvert = 4! \cdot 9^4`. 

Đáp án là :math:`P(A) = \dfrac{\lvert \Omega_A \rvert}{\lvert \Omega \rvert} = \dfrac{729}{6545}`.

Gọi :math:`B` là biến cố tất cả các lá có số khác nhau.

- Chọn số cho lá thứ nhất có :math:`9` cách chọn. Chọn chất cho lá đó có :math:`4` cách chọn.
- Chọn số cho lá thứ hai có :math:`8` cách chọn. Chọn chất cho lá đó có :math:`4` cách chọn.
- Tương tự cho lá thứ ba và thứ tư.

Như vậy :math:`\lvert \Omega_B \rvert = A^4_9 \cdot 4^4`.

Đáp án là :math:`P(B) = \dfrac{\lvert \Omega_B \rvert}{\lvert \Omega \rvert} = \dfrac{512}{935}`.

**Bài 2.** Trong rổ có :math:`10` quả bóng tennis, :math:`7` quả mới 
và :math:`3` quả đã qua sử dụng. Lấy ngẫu nhiên :math:`2` quả từ rổ 
cho trận đấu rồi trả lại. Tới trận đấu thứ hai cũng lấy ngẫu nhiên 
:math:`2` quả. Tính xác suất để ở trận thứ hai lấy được :math:`2` quả mới.

**Giải.** Sau khi chơi xong trận đầu thì những quả bóng mới sẽ 
trở thành bóng đã qua sử dụng.

Đặt :math:`B` là biến cố trận thứ hai lấy được :math:`2` quả mới.

Đặt :math:`A_1`, :math:`A_2` và :math:`A_3` lần lượt là biến cố 
trận đầu lấy được :math:`2` quả bóng mới, :math:`1` mới :math:`1` 
đã qua sử dụng, và :math:`2` quả đã qua sử dụng. Ba biến cố này 
hợp thành biến cố đầy đủ cho việc lấy :math:`2` quả ở trận đầu.

Theo công thức xác suất toàn phần:

.. math:: P(B) = P(A_1) P(B \vert A_1) + P(A_2) P(B \vert A_2) + P(A_3) P(B \vert A_3).

Nếu ở trận đầu lấy :math:`2` quả mới, ta có :math:`P(A_1) = \dfrac{C^2_7}{C^2_{10}} = \dfrac{7}{15}`. 
Sau khi trận đầu kết thúc, số bóng mới là :math:`7-2=5` và số bóng đã qua sử dụng là :math:`3+2=5` 
nên :math:`P(B \vert A_1) = \dfrac{C^2_5}{C^2_{10}} = \dfrac{2}{9}`.

Nếu ở trận đầu lấy :math:`1` quả mới và :math:`1` quả đã qua sử dụng, ta có 
:math:`P(A_2) = \dfrac{C^1_7 \cdot C^1_3}{C^2_{10}} = \dfrac{7}{15}`. Sau khi trận đầu 
kết thúc, số bóng mới là :math:`6` và số bóng đã qua sử dụng là :math:`4` nên 
:math:`P(B \vert A_2) = \dfrac{C^2_6}{C^2_{10}} = \dfrac{1}{3}`.

Nếu ở trận đầu lấy :math:`2` quả đã qua sử dụng thì :math:`P(A_3) = \dfrac{C^2_3}{C^2_{10}} = \dfrac{1}{15}`. 
Sau khi trận đầu kết thúc, số bóng mới vẫn là :math:`7` và số bóng đã qua sử dụng vẫn là :math:`3` 
nên :math:`P(B \vert A_3) = \dfrac{C^2_7}{C^2_{10}} = \dfrac{7}{15}`.

Đáp án:

.. math:: P(B) = \dfrac{7}{15} \cdot \dfrac{2}{9} + \dfrac{7}{15} \cdot \dfrac{1}{3} + \dfrac{1}{15} \cdot \dfrac{7}{15} = \dfrac{196}{675} \approx 0,29.

**Bài 3.** Trên mỗi cánh máy bay có :math:`2` động cơ. Xác suất bị lỗi của 
mỗi động cơ trong một chuyến bay là :math:`p`. Chuyến bay sẽ thành công nếu 
ở mỗi cánh có ít nhất một động cơ hoạt động bình thường. Tính xác suất chuyến 
bay thành công.

**Giải.** Gọi :math:`A` là biến cố ở một cánh có ít nhất một động cơ hoạt động, 
suy ra :math:`\bar{A}` là biến cố không động cơ nào hoạt động ở cả một cánh.

Như vậy :math:`P(\bar{A}) = p^2` nên :math:`P(A) = 1-p^2`. Áp dụng cho hai bên 
cánh (theo quy tắc nhân) ta có đáp án là :math:`(1-p^2)^2`.

**Bài 4.** Sinh viên biết :math:`20` trong :math:`30` câu hỏi. Để qua bài thi 
cần trả lời đúng :math:`2` câu hỏi bắt buộc hoặc trả lời đúng :math:`1` trong 
:math:`2` câu bắt buộc cộng thêm :math:`1` câu hỏi phụ. Tính xác suất để 
sinh viên vượt qua bài thi?

**Giải.** Ở đây cần hiểu là sinh viên biết :math:`20` câu trong số :math:`30` câu, 
:math:`10` câu kia là câu hỏi phụ. Khi đó có hai trường hợp:

Trường hợp 1 là sinh viên trả lời đúng :math:`2` câu trong số :math:`20` câu 
sinh viên biết nên xác suất là :math:`\dfrac{A^2_{20}}{A^2_{30}}`.

Trường hợp 2 là sinh viên trả lời đúng :math:`1` trong :math:`2` câu bắt buộc 
(có :math:`A^2_{20} \cdot 2` cách chọn) và :math:`1` câu hỏi phụ (:math:`10` cách chọn) 
nên xác suất là :math:`\dfrac{A^2_{20} \cdot 2 \cdot 10}{A^3_{30}}`. Tổng số 
câu sinh viên trả lời là :math:`3`.

Đáp án: :math:`\dfrac{A^2_{20}}{A^2_{30}} + \dfrac{A^2_{20} \cdot 2 \cdot 10}{A^3_{30}} = \dfrac{152}{203}`.

Các buổi còn lại và bài kiểm tra
================================

Phần dưới đây tiếp tục từ Bài 6 của buổi 4, sau đó gồm các buổi 5--13 và
hai đề kiểm tra.

.. include:: probability-tail.rst.inc
