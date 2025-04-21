# RoverBot - Dò line chính xác – Theo vạch không lệch hướng

## Giới thiệu

![](/image/lineTracking_duoiCheo.jpg)

- Hệ thống cảm biến dò line giúp RoverBot dễ dàng bám theo vạch kẻ, phù hợp cho các bài học lập trình điều hướng hoặc các cuộc thi robot dò line tự hành. Cảm biến dò line  MKE-S10 CNY70 Line Follower Sensor cho khả năng nhận biết tốt giữ line đen và line trắng, ngoài ra còn có khả năng chống nhiễu môi trường tốt, giúp xe có thể hoạt động được trong điều kiện ánh sáng ngoài trời mà không bị ảnh hưởng.

- Tín hiệu trả về của cảm biến là analog nên người dùng cần điều chỉnh ngưỡng nhận biết line đen và line trắng phù hợp, tùy vào điều kiện ánh sáng môi trường.

## Phần Cứng

| STT | Tên                                                                     | SL |
|:---:|-------------------------------------------------------------------------|:--:|
|  1  | Khung xe RoverBot                                                       |  1 |
|  2  | Mạch MakerEdu Creator with 2 X DC Motor Driver (Arduino Uno Compatible) |  1 |
|  3  | Cảm Biến dò line MKE-S10 CNY70 Line Follower Sensor                     |  2 | 
|  4  | Cáp Kết Nối MakerEdu XH2.54 4Wires 20cm Cable                           |  1 |
|  5  | Cáp Kết Nối MakerEdu XH2.54 3Wires 20cm Cable                           |  2 |
|  6  | Pin Dự Phòng USB-C 5VDC 2A 5000mAh Mini Power Bank                      |  1 |

## Sơ đồ kết nối

<img src="/image/cirkit_Roverbot_lineTracking.png" alt="">

## Nguyên lý hoạt động

- Robot dựa vào giá trị đọc được từ 2 cảm biến dò line để thực hiện việc điều chỉnh tốc độ động cơ 2 bên sao cho robot luôn hoạt động giữa line.

- Giá trị ngưỡng phát hiện line của cảm biến dò line được đặt mặc định là 450 (có thể điều chỉnh trong code theo điều kiện ánh sáng môi trường).

- Robot sẽ hoạt động theo các trường hợp sau:

    - Đi thẳng: Khi 2 cảm biến đều phát hiện line.

    - Xoay phải: Khi cảm biến bên trái không phát hiện line (robot đang bị lệch sang bên trái).

    - Xoay trái: Khi cảm biến bên phải không phát hiện line (robot đang bị lệch sang bên phải).

    - Tìm line: Khi ra khỏi line sẽ xoay để tìm lại line dựa vào trạng thái đã nhớ trước đó.


## Hướng dẫn nạp code

- [Tải repositories tại đây.](https://github.com/makerlabvn/RoverBot/archive/refs/heads/main.zip)
- Sau khi tải về, giải nén file .zip để lấy thư mục **"RoverBot-main"**

### Arduino

- Trong **File/Preferences** Thay đổi đường dẫn **Sketchbook Location** thành đường dẫn chỉ tới thư mục **"RoverBot-main"**

<img src="/image/sketch3.png" alt="sketchBookLocation">

- Chọn file **"Rover_LineTracking.ino"** từ **File/Sketchbook/examples/**
  
<img src="/image/lineTrackingExample.png" alt="">

- Board chọn **Arduino Uno**, Chọn PORT tương ứng với cổng COM của mạch Arduino

<img src="/image/boardArduinoUno.png" alt="">

- Nhấn **Upload** để nạp code vào mạch Arduino

<img src="/image/sketch1.png" alt="">

### mBlock

- - Mở file **"line_tracking.mblock"** tại folder **[mBlock5/](https://github.com/makerlabvn/RoverBot/tree/main/mBlock5)**

- Chọn Device là mạch **MakerEdu Creator** và tiến hành kết nối, tích vào ô **"Show all connectable devices"**, chọn COM tương ứng của mạch MakerEdu Creator rồi nhấn **"Connect"**

<img src="/image/Mblock1.png" alt="">

- Nhấn **"Upload Code"** và chờ đến khi có thông báo hoàn tất

<img src="/image/Mblock2.png" alt="">

## Điều chỉnh

- Có thể điều chỉnh độ nhạy của cảm biến thông qua ngưỡng so sánh trong code (mặc định là 450).
- Tốc độ động cơ có thể được điều chỉnh để phù hợp với điều kiện thực tế.

---

## Pages

- [RoverBot](/README.md)
- [RoverBot - Bluetooth](/examples/Rover_Bluetooth/readme.md)
- [RoverBot - Obstacle Avoiding](/examples/Rover_BlockAvoiding/readme.md)
- [RoverBot - All Factory](/examples/Rover_All_Factory/readme.md)
