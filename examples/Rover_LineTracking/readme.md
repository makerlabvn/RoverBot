# [MakerEdu Creator] RoverBot - Xe dò line

<img src= ../../image/RoverBot_LineTracking.png>

## Giới thiệu:

- Là chức năng tiếp theo của RoverBot. RoverBot_LineTracking tập trung đến việc di chuyển theo đường line và việc xử lý thuật toán để cho xe đạt được tốc độ cao nhất mà vẫn có thể bám được những đường line khó.  

- Xe sử dụng cảm biến dò line với ngõ ra là tính hiệu tương tự. Vì vậy, người sử dụng cần điều chỉnh ngưỡng hoạt động dựa trên tín hiệu trả lại của cảm biến để xe có thể hoạt động như ý muốn.  

## Phần Cứng:
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

### Kết nối động cơ:
- Motor A:
  - PWM: Pin 6
  - IN1: Pin 9
  - IN2: Pin 8
- Motor B:
  - PWM: Pin 5
  - IN1: Pin 7
  - IN2: Pin 4

### Kết nối cảm biến dò line:
- Cảm biến trái: Pin A0
- Cảm biến giữa: Pin A1
- Cảm biến phải: Pin A2
- VCC -> 5V
- GND -> GND

## Nguyên lý hoạt động:
1. Xe sử dụng 3 cảm biến dò line để phát hiện đường đi
2. Dựa vào giá trị đọc được từ các cảm biến, xe sẽ:
   - Đi thẳng khi cảm biến giữa phát hiện line
   - Rẽ trái khi cảm biến trái phát hiện line
   - Rẽ phải khi cảm biến phải phát hiện line
   - Dừng lại khi không phát hiện line

## Điều chỉnh:
- Có thể điều chỉnh độ nhạy của cảm biến thông qua ngưỡng so sánh trong code
- Tốc độ động cơ có thể được điều chỉnh để phù hợp với điều kiện thực tế

## Hướng Dẫn:
- Hướng dẫn lắp ráp  



