# [MakerEdu Creator] RoverBot - Xe tránh vật cản

<img src=../../image/RoverBot_BlockAvoiding.png>

## Giới thiệu:

- Là tính năng thứ 3 của RoverBot. RoverBot_BlockAvoiding tập trung đến việc né tránh vật cản dựa trên khoảng cách đo được của cảm biến siêu âm. Khi gặp phải vật cản, xe sẽ dừng lại và quay cảm biến siêu âm để nhận biết được vị trí không có vật cản và rẽ sang hướng đó.  

- Để thực hiện chức năng né tránh vật cản, xe cần phải có motor RC Servo và cảm biến siêu âm.

## Phần Cứng:

| STT | Tên                                                                     | SL |
|:---:|-------------------------------------------------------------------------|:--:|
|  1  | Khung xe gỗ RoverBot                                                    |  1 |
|  2  | Mạch MakerEdu Creator With 2 X DC Motor Driver (Arduino Uno Compatible) |  1 |
|  3  | Module MKE-M15 Bluetooth 3.0 SPP / BLE 4.2 Dual Mode                    |  1 |
|  4  | Cáp Kết Nối MakerEdu XH2.54 4Wires 20cm Cable                           |  2 |
|  5  | Dây điện đỏ đen                                                         |  1 |
|  6  | Pin Dự Phòng USB-C 5VDC 2A 5000mAh Mini Power Bank                      |  1 |
|  7  | Cảm Biến Siêu Âm MKE-S01 Ultrasonic Distance Sensor                     |  1 |

## Hướng Dẫn:  

- Hướng dẫn lắp ráp

- Hướng dẫn lập trình

## Sơ đồ kết nối

### Kết nối động cơ:
- Motor A:
  - PWM: Pin 6
  - IN1: Pin 9
  - IN2: Pin 8
- Motor B:
  - PWM: Pin 5
  - IN1: Pin 7
  - IN2: Pin 4

### Kết nối cảm biến siêu âm HC-SR04:
- Trig: Pin 12
- Echo: Pin 11
- VCC -> 5V
- GND -> GND

## Nguyên lý hoạt động:
1. Xe sử dụng cảm biến siêu âm để phát hiện vật cản phía trước
2. Khi phát hiện vật cản trong khoảng cách an toàn (mặc định 20cm):
   - Xe sẽ dừng lại
   - Quay sang một hướng, trái trước rồi sau đó tới phải
   - Tiếp tục di chuyển theo hướng mới
3. Nếu không có vật cản, xe sẽ di chuyển thẳng

## Điều chỉnh:
- Khoảng cách phát hiện vật cản có thể điều chỉnh trong code
- Tốc độ động cơ và thời gian quay có thể điều chỉnh để phù hợp với điều kiện thực tế