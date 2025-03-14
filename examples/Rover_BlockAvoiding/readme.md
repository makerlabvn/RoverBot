# [MakerEdu Creator] RoverBot - Xe tránh vật cản

![](/image/obstacleAvoiding_cheoTrenPhai.jpg)

## Giới thiệu

![](/image/obstacleAvoiding_cheoTrenTrai.jpg)

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

## Sơ đồ kết nối

![](/image/cirkit_obstacleAvoiding.png)

## Hướng Dẫn  

- Hướng dẫn lắp ráp

### Nguyên lý hoạt động

1. Xe sử dụng cảm biến siêu âm để đo và phát hiện vật cản trong khoảng cách được cho trước
2. Khi phát hiện vật cản trong khoảng cách an toàn (mặc định 20cm):
   1. Dừng lại
   2. Servo quay 90° sang trái để kiểm tra:

      - Nếu không có vật cản: Quay về vị trí giữa (0°), xe rẽ trái 90° và tiếp tục đi thẳng
      - Nếu có vật cản: Servo quay 180° sang phải để kiểm tra
   3. Nếu phải không có vật cản: Quay về vị trí giữa, xe rẽ phải 90° và tiếp tục đi thẳng

   4. Nếu cả 3 hướng đều có vật cản: Xe lùi khoảng 20cm và lặp lại quy trình kiểm tra từ đầu

### Điều chỉnh

- Khoảng cách phát hiện vật cản có thể điều chỉnh trong code
- Tốc độ động cơ và thời gian quay có thể điều chỉnh để phù hợp với điều kiện thực tế

---

![](/image/full_author.jpg)

## Thông tin liên hệ

- Facebook: [MakerLab RnD](https://www.facebook.com/makerlabvn)
- SĐT & Zalo: 0964.787.150
- Giờ làm việc: Thứ 2 - Thứ 7: 9h00 đến 17h00
