#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

// INCLUDE LIBRARIES
#include "Dabble.h"
#include <Makerlabvn_SimpleMotor.h>

// DEFINE
#define MOTOR_SPEED 70  // Tốc độ mặc định của động cơ (0-255)
#define BAUDRATE 115200 // Tốc độ truyền dữ liệu
// Định nghĩa chân kết nối động cơ bên phải
#define MOTOR_B_EN 6
#define MOTOR_B_IN1 9
#define MOTOR_B_IN2 8

// Định nghĩa chân kết nối động cơ bên trái
#define MOTOR_A_EN 5
#define MOTOR_A_IN1 7
#define MOTOR_A_IN2 4
// OBJECT INITIALIZATION

Makerlabvn_SimpleMotor car_control;

void setup()
{
  Serial.begin(BAUDRATE);
  Dabble.begin(Serial);
  car_control.setup(MOTOR_A_EN, MOTOR_A_IN1, MOTOR_A_IN2, MOTOR_B_IN1, MOTOR_B_IN2, 
                   MOTOR_B_EN);
  car_control.car_stop();
  Serial.println("Khởi tạo thành công!");
}

void loop()
{
  Dabble.processInput(); // Xử lý tín hiệu từ ứng dụng Dabble

  // Xử lý các nút bấm từ gamepad
  if (GamePad.isUpPressed()) {
    Serial.println("up");
    car_control.car_fw(MOTOR_SPEED, MOTOR_SPEED); // Di chuyển tiến
  }
  else if (GamePad.isDownPressed()) {
    Serial.println("down");
    car_control.car_bw(MOTOR_SPEED, MOTOR_SPEED); // Di chuyển lùi
  }
  else if (GamePad.isLeftPressed()) {
    Serial.println("left");
    car_control.car_rotateL(MOTOR_SPEED); // Xoay trái
  }
  else if (GamePad.isRightPressed()) {
    Serial.println("right");
    car_control.car_rotateR(MOTOR_SPEED); // Xoay phải
  }
  else {
    car_control.car_stop(); // Dừng xe khi không có nút nào được bấm
  }
}
