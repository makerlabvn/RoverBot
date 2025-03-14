// INCLUDE LIBRARIES
#include "Makerlabvn_SimpleMotor.h"

// PIN DEFINITIONS
#define PIN_OUT1 A1  // Cảm biến bên trái
#define PIN_OUT2 A2  // Cảm biến bên phải

// Định nghĩa chân kết nối động cơ bên phải
#define MOTOR_B_EN 6
#define MOTOR_B_IN1 9
#define MOTOR_B_IN2 8

// Định nghĩa chân kết nối động cơ bên trái
#define MOTOR_A_EN 5
#define MOTOR_A_IN1 7
#define MOTOR_A_IN2 4

#define DELAY_CAR 3000  // Thời gian chờ khi khởi động xe (ms)


// OBJECT INITIALIZATION
Makerlabvn_SimpleMotor car_control;

// CẤU HÌNH CẢM BIẾN
// Ngưỡng phát hiện vạch trắng (0-1023)
// Giá trị càng cao thì độ nhạy càng thấp
int threshold_right = 450;  // Ngưỡng cảm biến phải
int threshold_left = 450;   // Ngưỡng cảm biến trái

// BIẾN ĐIỀU KHIỂN XE
int last_lost_dir;       // Hướng di chuyển cuối cùng trước khi mất vạch
int left_dir = 1;        // Trạng thái xe ở bên trái vạch
int right_dir = 0;       // Trạng thái xe ở bên phải vạch
int speed_forward = 70;  // Tốc độ xe khi di chuyển (0-100%)
int speed_stop = 0;      // Tốc độ xe khi dừng

void setup() {
  last_lost_dir = left_dir;  // Khởi tạo hướng di chuyển ban đầu
  car_control.setup(MOTOR_A_EN, MOTOR_A_IN1, MOTOR_A_IN2,
                    MOTOR_B_IN1, MOTOR_B_IN2, MOTOR_B_EN);  // Khởi tạo các chân điều khiển động cơ
  car_control.car_stop();                                   // Dừng xe
  delay(DELAY_CAR);                                         // Chờ xe ổn định
}

void loop() {
  // Đọc giá trị từ cảm biến
  int eye_left_value = analogRead(PIN_OUT1);
  int eye_right_value = analogRead(PIN_OUT2);

  // Xử lý các trường hợp theo giá trị cảm biến
  if ((eye_left_value > threshold_left) && (eye_right_value > threshold_right)) {
    // Trường hợp 1: Cả hai cảm biến đều phát hiện vạch -> xe đi thẳng
    car_control.car_fw(speed_forward, speed_forward);  // Điều khiển cả hai động cơ quay cùng tốc độ
  } else {
    if ((eye_left_value < threshold_left) && (eye_right_value > threshold_right)) {
      // Trường hợp 2: Chỉ cảm biến phải phát hiện vạch -> xe rẽ trái
      last_lost_dir = left_dir;                       // Lưu hướng di chuyển hiện tại
      car_control.car_fw(speed_stop, speed_forward);  // Động cơ phải quay, động cơ trái dừng
    } else {
      if ((eye_left_value > threshold_left) && (eye_right_value < threshold_right)) {
        // Trường hợp 3: Chỉ cảm biến trái phát hiện vạch -> xe rẽ phải
        last_lost_dir = right_dir;                      // Lưu hướng di chuyển hiện tại
        car_control.car_fw(speed_forward, speed_stop);  // Động cơ trái quay, động cơ phải dừng
      } else {
        // Trường hợp 4: Mất vạch -> xe quay theo hướng cuối cùng
        if (last_lost_dir == left_dir) {
          car_control.car_rotateL(speed_forward);  // Quay trái nếu trước đó xe ở bên phải vạch
        } else {
          car_control.car_rotateR(speed_forward);  // Quay phải nếu trước đó xe ở bên trái vạch
        }
      }
    }
  }
}
