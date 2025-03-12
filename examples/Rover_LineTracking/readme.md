# [MakerEdu Creator] RoverBot - Xe dò line

![](/image/lineTracking_duoiCheo.jpg)

## Giới thiệu

![](/image/lineTracking_fullTrenCheo.jpg)

- Là chức năng tiếp theo của RoverBot. RoverBot_LineTracking tập trung đến việc di chuyển theo đường line và việc xử lý thuật toán để cho xe đạt được tốc độ cao nhất mà vẫn có thể bám được những đường line khó.  

- Xe sử dụng cảm biến dò line với ngõ ra là tính hiệu tương tự. Vì vậy, người sử dụng cần điều chỉnh ngưỡng hoạt động dựa trên tín hiệu trả lại của cảm biến để xe có thể hoạt động như ý muốn.  

## Phần Cứng

| STT | Tên                                                                     | SL |
|:---:|-------------------------------------------------------------------------|:--:|
|  1  | Khung xe gỗ RoverBot                                                    |  1 |
|  2  | Mạch MakerEdu Creator With 2 X DC Motor Driver (Arduino Uno Compatible) |  1 |
|  3  | Module MKE-M15 Bluetooth 3.0 SPP / BLE 4.2 Dual Mode                    |  1 |
|  4  | Cáp Kết Nối MakerEdu XH2.54 4Wires 20cm Cable                           |  1 |
|  5  | Cáp Kết Nối MakerEdu XH2.54 3Wires 20cm Cable                           |  2 |
|  6  | Dây điện đỏ đen                                                         |  1 |
|  7  | Pin Dự Phòng USB-C 5VDC 2A 5000mAh Mini Power Bank                      |  1 |
|  8  | Cảm Biến Dò Đường MKE-S10 CNY70 Line Follower Sensor                    |  2 |  

## Sơ đồ kết nối

![](/image/cirkit_Roverbot_lineTracking.png)

## Hướng Dẫn

- Hướng dẫn lắp ráp  

### Nguyên lý hoạt động

1. Xe sử dụng 3 cảm biến dò line để phát hiện đường đi
2. Dựa vào giá trị đọc được từ các cảm biến, xe sẽ:
   - Đi thẳng khi cảm biến giữa phát hiện line
   - Rẽ trái khi cảm biến trái phát hiện line
   - Rẽ phải khi cảm biến phải phát hiện line
   - Dừng lại khi không phát hiện line

### Điều chỉnh

- Có thể điều chỉnh độ nhạy của cảm biến thông qua ngưỡng so sánh trong code
- Tốc độ động cơ có thể được điều chỉnh để phù hợp với điều kiện thực tế

---

![](/image/full_author.jpg)

## Thông tin liên hệ

- Facebook: [MakerLab RnD](https://www.facebook.com/makerlabvn)
- SĐT & Zalo: 0964.787.150
- Giờ làm việc: Thứ 2 - Thứ 7: 9h00 đến 17h00
