# RoverBot - Xe dò line

![](/image/lineTracking_logoW.png)

## Giới thiệu

![](/image/lineTracking_duoiCheo.jpg)

- Là chức năng tiếp theo của bộ kit RoverBot RoverBot_LineTracking, với việc sử dụng cảm biến dò line  MKE-S10 CNY70 line follower sensor cho khả năng nhận biết tốt giữ line đen và line trắng, ngoài ra còn có khả năng chống nhiễu môi trường tốt. giúp xe có thể hoạt động được trong điều kiện ánh sáng ngoài trời mà không bị ảnh hưởng.

- Tín hiệu trả về của cảm biến là analog nên người dùng cần điều chỉnh ngưỡng nhận biết line đen và line trắng phù hợp, tùy vào điều kiện ánh sáng môi trường. cách tùy chỉnh vui lòng xem video hướng dẫn để làm theo.

## Phần Cứng

| STT | Tên                                                                     | SL |
|:---:|-------------------------------------------------------------------------|:--:|
|  1  | Khung xe gỗ RoverBot                                                    |  1 |
|  2  | Mạch MakerEdu Creator With 2 X DC Motor Driver (Arduino Uno Compatible) |  1 |
|  3  | Cáp Kết Nối MakerEdu XH2.54 4Wires 20cm Cable                           |  1 |
|  4  | Cáp Kết Nối MakerEdu XH2.54 3Wires 20cm Cable                           |  2 |
|  5  | Dây điện đỏ đen                                                         |  1 |
|  6  | Pin Dự Phòng USB-C 5VDC 2A 5000mAh Mini Power Bank                      |  1 |
|  7  | Cảm Biến Dò Đường MKE-S10 CNY70 Line Follower Sensor                    |  2 |  

## Sơ đồ kết nối

![](/image/cirkit_Roverbot_lineTracking.png)

## Hướng Dẫn

- Hướng dẫn lắp ráp  

### Nguyên lý hoạt động

Robot dựa vào giá trị đọc được từ 2 cảm biến dò line để thực hiện việc điều chỉnh tốc độ động cơ 2 bên sao cho robot luôn hoạt động giữa line.

Giá trị ngưỡng phát hiện line của cảm biến dò line được đặt mặc định là 450 (có thể điều chỉnh theo điều kiện ánh sáng môi trường).

Robot sẽ hoạt động theo các trường hợp sau:

- Đi thẳng: Khi 2 cảm biến đều phát hiện line

- Xoay phải: Khi cảm biến bên trái không phát hiện line (robot đang bị lệch sang bên trái)

- Xoay trái: Khi cảm biến bên phải không phát hiện line (robot đang bị lệch sang bên phải) 

- Tìm line: Khi ra khỏi line sẽ xoay để tìm lại line dựa vào trạng thái đã nhớ trước đó

### Điều chỉnh

- Có thể điều chỉnh độ nhạy của cảm biến thông qua ngưỡng so sánh trong code
- Tốc độ động cơ có thể được điều chỉnh để phù hợp với điều kiện thực tế

---

![](/image/full_author.jpg)

## Thông tin liên hệ

- Facebook: [MakerLab RnD](https://www.facebook.com/makerlabvn)
- SĐT & Zalo: 0964.787.150
- Giờ làm việc: Thứ 2 - Thứ 7: 9h00 đến 17h00
