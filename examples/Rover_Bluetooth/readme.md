# RoverBot - Điều khiển không dây qua Bluetooth

## Giới thiệu

![](/image/bluetooth_trenCheoPhai.jpg)

Điều khiển RoverBot dễ dàng bằng Smartphone hoặc máy tính bảng thông qua kết nối Bluetooth, tạo cảm giác điều khiển robot như chơi một chiếc xe thông minh. Sử dụng module Bluetooth MKE-M15 hỗ trợ kết nối với cả 2 hệ điều hành là Android và IOS.

## Phần Cứng

| STT | Tên                                                                     | SL |
|:---:|-------------------------------------------------------------------------|:--:|
|  1  | Khung xe RoverBot                                                    |  1 |
|  2  | Mạch MakerEdu Creator with 2 X DC Motor Driver (Arduino Uno Compatible) |  1 |
|  3  | Module MKE-M15 Bluetooth 3.0 SPP / BLE 4.2 Dual Mode                    |  1 |
|  4  | Cáp Kết Nối MakerEdu XH2.54 4Wires 20cm Cable                           |  1 |
|  5  | Dây điện đỏ đen                                                         |  1 |
|  6  | Pin Dự Phòng USB-C 5VDC 2A 5000mAh Mini Power Bank                      |  1 |

## Sơ đồ kết nối

<div align="center">
    <img src="../../image/cirkit_Roverbot_bluetooth.png" alt="">
</div>

## Hướng dẫn sử dụng

1. Tải và cài đặt ứng dụng Dabble trên điện thoại.

- <a href="https://play.google.com/store/apps/details?id=io.dabbleapp&hl=vi&gl=US">Android</a>

- [IOS](https://apps.apple.com/us/app/dabble-bluetooth-controller/id1472734455)  

<div align="center">
   <img src="../../image/dabbleicon.png" alt="">  
</div>

2. Kết nối Bluetooth với MKE-M15.
(Thêm hình minh hoạ)
4. Mở ứng dụng Dabble, chọn chế độ GamePad.

<div align="center">
<img src="../../image/gamepad.png">
</div>

5. Sử dụng các nút điều hướng để điều khiển xe:
   - Nút Lên: Xe đi thẳng
   - Nút Xuống: Xe đi lùi
   - Nút Trái: Xe quay trái
   - Nút Phải: Xe quay phải

## Hướng dẫn nạp code

- [Tải repositories tại đây.](https://github.com/makerlabvn/RoverBot/archive/refs/heads/main.zip)
- Sau khi tải về, giải nén file .zip để lấy thư mục **"RoverBot-main"**

### Arduino

- Thay đổi đường dẫn Sketchbook Location thành đường dẫn chỉ tới thư mục **"RoverBot-main"**

<div align="center">
    <img src="../../image/sketchBookLoc.png" alt="sketchBookLocation">
</div>

- Chọn file "Rover_Bluetooth.ino" từ File / Sketchbook / examples / Rover_Bluetooth

<div align="center">
    <img src="../../image/bluetoothExample.png" alt="">
</div>

- Chọn PORT tương ứng, Board chọn Arduino Uno

<div align="center">
    <img src="../../image/boardArduinoUno.png" alt="">
</div>

- Nhấn Upload.

### mBlock

- Mở file ["bluetooth.mblock"](../../mBlock5/mblockExampleCode/bluetooth.mblock) tại folder "mBlock5 / mblockExampleCode"

<div align="center">
    <img src="../../image/bluetoothExampleMblock.png" alt="">
</div>

- Tại phần Devices, nhấn Connect

<div align="center">
    <img src="../../image/mblockConnect.png" alt="">
</div>

- Tích vào ô "Show all connectable devices", chọn COM tương ứng rồi nhấn "Connect"

<div align="center">
    <img src="../../image/mblockShowAllConnectAble.png" alt="">
</div>

- Nhấn "Upload Code"

<div align="center">
    <img src="../../image/mblockUpload.png" alt="">
</div>

## Tốc độ động cơ

- Tốc độ mặc định: 70 (có thể điều chỉnh mã trong code chương trình).
  
## Pages

- [RoverBot](/README.md)
- [RoverBot - Line Tracking](/examples/Rover_LineTracking/readme.md)
- [RoverBot - Obstacle Avoiding](/examples/Rover_BlockAvoiding/readme.md)
- [RoverBot - All Factory](/examples/Rover_All_Factory/readme.md)