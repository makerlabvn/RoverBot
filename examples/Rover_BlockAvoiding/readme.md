# RoverBot - Xe tránh vật cản

![](/image/obstacleAvoiding_logoW.png)

## Giới thiệu

![](/image/obstacleAvoiding_truocCheoTrai_logo.png)

- Là tính năng thứ 3 của RoverBot. RoverBot_BlockAvoiding tập trung đến việc né tránh vật cản dựa trên khoảng cách đo được của cảm biến siêu âm. Khi gặp phải vật cản, xe sẽ dừng lại và quay cảm biến siêu âm để nhận biết được vị trí không có vật cản và rẽ sang hướng đó.  

- Để thực hiện chức năng né tránh vật cản, xe cần phải có motor RC Servo và cảm biến siêu âm.

## Phần Cứng

| STT | Tên                                                                     | SL |
|:---:|-------------------------------------------------------------------------|:--:|
|  1  | Khung xe gỗ RoverBot                                                    |  1 |
|  2  | Mạch MakerEdu Creator With 2 X DC Motor Driver (Arduino Uno Compatible) |  1 |
|  3  | Cáp Kết Nối MakerEdu XH2.54 4Wires 20cm Cable                           |  2 |
|  4  | Dây điện đỏ đen                                                         |  1 |
|  5  | Pin Dự Phòng USB-C 5VDC 2A 5000mAh Mini Power Bank                      |  1 |
|  6  | Cảm Biến Siêu Âm MKE-S01 Ultrasonic Distance Sensor                     |  1 |
| 7 | Động cơ RC Servo 9G                     |  1 |

## Sơ đồ kết nối

![](/image/cirkit_obstacleAvoiding.png)

## Hướng Dẫn  

- Hướng dẫn lắp ráp

### Nguyên lý hoạt động

- Robot sử dụng cảm biến siêu âm để đo và phát hiện vật cản trong khoảng cách đo được.

- Mặc định xe chạy tiến về phía trước và cảm biến siêu âm sẽ quét vật cản ở phía trước.

  - Khi phát hiện vật cản trong khoảng cách được cài đặt trước (mặc định là 20cm) thì xe sẽ dừng lại.

  - Tiếp theo, servo quay sang trái đưa cảm biến siêu âm quay theo để kiểm tra xem bên trái robot có vật cản hay không.

    - Nếu không có vật cản thì xe sẽ xoay sang phải và tiếp tục đi thẳng.

    - Nếu có thì sẽ quay servo sang bên phải và cảm biến siêu âm tiếp tục quét vật cản bên phải để kiểm tra xem có vật cản bên phải xe không.

      - Nếu không có thì xe xoay phải và tiếp tục đi thẳng về phía trước.

- Nếu hai bên trái và phải đều có vật cản thì xe sẽ lùi lại và tiếp tục thực hiện quá trình quét vật cản xung quanh.

### Điều chỉnh

- Khoảng cách phát hiện vật cản có thể điều chỉnh trong code
- Tốc độ động cơ và thời gian quay có thể điều chỉnh để phù hợp với điều kiện thực tế

---

![](/image/full_author.jpg)

## Thông tin liên hệ

- Facebook: [MakerLab RnD](https://www.facebook.com/makerlabvn)
- SĐT & Zalo: 0964.787.150
- Giờ làm việc: Thứ 2 - Thứ 7: 9h00 đến 17h00
