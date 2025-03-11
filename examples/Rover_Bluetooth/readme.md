# [MakerEdu Creator] RoverBot - Xe điều khiển từ xa bằng smartphone

<img src=../../image/RoverBot_Bluetooth.png>

## Giới thiệu:

- Là một trong ba chức năng của RoverBot, RoverBot_Bluetooth là một dạng xe sử dụng truyền động bánh đai và động cơ Xanh TT V1 Metal Geared 1:90 cho khả năng khởi động và leo dốc tiết kiệm năng lượng hơn động cơ Vàng TT V1 Plastic Geared 1:48 và được điều khiển bằng điện thoại thông minh qua ứng dụng Dabble có sẵn trên hai nền tảng là Android và IOS.

- Xe sử dụng module Bluetooth MKE-M15 hỗ trợ kết nối với cả 2 hệ điều hành là Android và IOS  

## Phần Cứng:
| STT | Tên                                                                     | SL |
|:---:|-------------------------------------------------------------------------|:--:|
|  1  | Khung xe gỗ RoverBot                                                    |  1 |
|  2  | Mạch MakerEdu Creator With 2 X DC Motor Driver (Arduino Uno Compatible) |  1 |
|  3  | Module MKE-M15 Bluetooth 3.0 SPP / BLE 4.2 Dual Mode                    |  1 |
|  4  | Cáp Kết Nối MakerEdu XH2.54 4Wires 20cm Cable                           |  1 |
|  5  | Dây điện đỏ đen                                                         |  1 |
|  6  | Pin Dự Phòng USB-C 5VDC 2A 5000mAh Mini Power Bank                      |  1 |
## Hướng Dẫn:
- Hướng dẫn lắp ráp  

- Hướng dẫn lập trình  

# RoverBot Bluetooth Control

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

### Kết nối Bluetooth:
- Module Bluetooth HC-05/HC-06:
  - TX -> Pin 0 (RX của Arduino)
  - RX -> Pin 1 (TX của Arduino)
  - VCC -> 5V
  - GND -> GND

## Hướng dẫn sử dụng:
1. Tải và cài đặt ứng dụng Dabble trên điện thoại
2. Kết nối Bluetooth với module HC-05/HC-06
3. Mở ứng dụng Dabble, chọn chế độ GamePad
4. Sử dụng các nút điều hướng để điều khiển xe:
   - Nút Lên: Xe đi thẳng
   - Nút Xuống: Xe đi lùi
   - Nút Trái: Xe quay trái
   - Nút Phải: Xe quay phải

## Tốc độ động cơ:
- Tốc độ mặc định: 70 (có thể điều chỉnh thông qua biến SPEED)
