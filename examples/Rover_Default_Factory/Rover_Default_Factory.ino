#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

// INCLUDE LIBRARIES
#include "Dabble.h"
#include <Makerlabvn_SimpleMotor.h>
#include <MKL_HCSR04.h>  // Thư viện điều khiển cảm biến siêu âm
#include <Servo.h>
// DEFINE
#define MOTOR_SPEED 70   // Tốc độ mặc định của động cơ (0-255)
#define BAUDRATE 115200  // Tốc độ truyền dữ liệu
// Định nghĩa chân kết nối động cơ bên phải
#define MOTOR_B_EN 6
#define MOTOR_B_IN1 9
#define MOTOR_B_IN2 8

// Định nghĩa chân kết nối động cơ bên trái
#define MOTOR_A_EN 5
#define MOTOR_A_IN1 7
#define MOTOR_A_IN2 4

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

#define ANGLE_LEFT 180   // Góc quay sang trái của servo
#define ANGLE_MIDDLE 90  // Góc quay giữa của servo
#define ANGLE_RIGHT 0    // Góc quay sang phải của servo

// Định nghĩa các thông số thời gian và tốc độ
#define MOTOR_SPEED 70              // Tốc độ động cơ (0-100%)
#define DELAY_FOR_SERVO_RUN 1000    // Thời gian chờ servo quay (ms)
#define DELAY_ROTATION 1200         // Thời gian robot quay (ms)
#define DELAY_FOR_GO_BACKWARD 1000  // Thời gian robot lùi lại (ms)

// Định nghĩa chân kết nối cảm biến siêu âm
#define PIN_ULTRASONIC_TRIG 2  // Chân TRIG của cảm biến siêu âm
#define PIN_ULTRASONIC_ECHO 3  // Chân ECHO của cảm biến siêu âm

// Định nghĩa chân kết nối servo motor
#define PIN_SERVO 10  // Chân điều khiển servo
// OBJECT INITIALIZATION

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

// Biến toàn cục
int distance;                 // Lưu khoảng cách đo được từ cảm biến
int threshold_distance = 30;  // Khoảng cách ngưỡng phát hiện vật cản (cm)

// Định nghĩa các trạng thái của robot
#define CAR_STATE_FORWARD 0               // Trạng thái tiến thẳng
#define CAR_STATE_BACKWARD 1              // Trạng thái lùi
#define CAR_STATE_PROCESS_ROTATE_LEFT 2   // Trạng thái quay trái
#define CAR_STATE_PROCESS_ROTATE_RIGHT 3  // Trạng thái quay phải

int ROBOT_STATE = CAR_STATE_FORWARD;  // Khởi tạo trạng thái ban đầu là tiến thẳng

Servo Rotater;  // Servo quay cảm biến
Makerlabvn_SimpleMotor car_control;
MKL_HCSR04 ultrasonic_sensor(PIN_ULTRASONIC_TRIG, PIN_ULTRASONIC_ECHO);  // Cảm biến siêu âm

void _delay(float seconds) {
  long endTime = millis() + seconds;
  while (millis() <= endTime) {
    _loop();
  }
}

void setup() {
  Serial.begin(BAUDRATE);
  Dabble.begin(Serial);
  car_control.setup(MOTOR_A_EN, MOTOR_A_IN1, MOTOR_A_IN2, MOTOR_B_IN1, MOTOR_B_IN2,
                    MOTOR_B_EN);
  car_control.car_stop();
  Rotater.attach(PIN_SERVO);  // Kết nối servo với chân 10
  Rotater.write(ANGLE_MIDDLE);
  last_lost_dir = left_dir;  // Khởi tạo hướng di chuyển ban đầu

  Serial.println("Khởi tạo thành công!");
}
uint8_t state = 1;
void choseMode() {
  if (GamePad.isSquarePressed())
    state = 1;
  if (GamePad.isCirclePressed())
    state = 2;
  if (GamePad.isTrianglePressed())
    state = 3;
}
void loop() {
  _loop();
  // if(GamePad.isSquare)
  // Xử lý các nút bấm từ gamepad
  // choseMode();
  if (state == 1) {
    choseMode();
    if (GamePad.isUpPressed()) {
      // Serial.println("up");
      car_control.car_fw(MOTOR_SPEED, MOTOR_SPEED);  // Di chuyển tiến
    } else if (GamePad.isDownPressed()) {
      // Serial.println("down");
      car_control.car_bw(MOTOR_SPEED, MOTOR_SPEED);  // Di chuyển lùi
    } else if (GamePad.isLeftPressed()) {
      // Serial.println("left");
      car_control.car_rotateL(MOTOR_SPEED);  // Xoay trái
    } else if (GamePad.isRightPressed()) {
      // Serial.println("right");
      car_control.car_rotateR(MOTOR_SPEED);  // Xoay phải
    } else {
      car_control.car_stop();  // Dừng xe khi không có nút nào được bấm
    }
  } else if (state == 2) {
    // choseMode();
    // setupObstacleAvoiding();
    loopObstacleAvoiding();
  } else if (state == 3) {
    // setupLineTracking();
    loopLineTracking();
  }
}

void _loop() {
  Dabble.processInput();  // Xử lý tín hiệu từ ứng dụng Dabble
  choseMode();
  get_distance();
}


void setupObstacleAvoiding() {
  // car_control.setup(MOTOR_A_EN, MOTOR_A_IN1, MOTOR_A_IN2,
  //                     MOTOR_B_IN1, MOTOR_B_IN2, MOTOR_B_EN); // Khởi tạo động cơ
  Rotater.attach(PIN_SERVO);    // Kết nối servo với chân 10
  Rotater.write(ANGLE_MIDDLE);  // Đặt góc quay của trục động cơ servo ở vị trí giữa
  _delay(DELAY_FOR_SERVO_RUN);  // Chờ servo quay xong
  _delay(3000);
}

void setupLineTracking() {
  last_lost_dir = left_dir;  // Khởi tạo hướng di chuyển ban đầu
  // car_control.setup(MOTOR_A_EN, MOTOR_A_IN1, MOTOR_A_IN2,
  //                   MOTOR_B_IN1, MOTOR_B_IN2, MOTOR_B_EN); // Khởi tạo các chân điều khiển động cơ
  // car_control.car_stop();                                  // Dừng xe
  _delay(DELAY_CAR);  // Chờ xe ổn định
}

void loopObstacleAvoiding() {
  _loop();
  if (ROBOT_STATE == CAR_STATE_FORWARD)
    process_go_forward();
  else if (ROBOT_STATE == CAR_STATE_PROCESS_ROTATE_LEFT)
    process_rotate_left();
  else if (ROBOT_STATE == CAR_STATE_PROCESS_ROTATE_RIGHT)
    process_rotate_right();
}

void loopLineTracking() {
  _loop();
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

void process_go_forward() {
  // Đảm bảo góc quay của trục động cơ servo ở vị trí giữa
  if (Rotater.read() != ANGLE_MIDDLE) {
    Rotater.write(ANGLE_MIDDLE);
    _delay(DELAY_FOR_SERVO_RUN);
  }

  // Kiểm tra vật cản
  if (get_distance() < threshold_distance) {
    car_control.car_stop();                       // Dừng xe
    ROBOT_STATE = CAR_STATE_PROCESS_ROTATE_LEFT;  // Chuyển sang quay trái
  } else {
    car_control.car_fw(MOTOR_SPEED, MOTOR_SPEED);  // Tiến thẳng
  }
}

/**
 * Hàm process_rotate_left() - Xử lý trạng thái quay trái
 * 1. Quay servo sang trái để kiểm tra
 * 2. Nếu có vật cản: chuyển sang quay phải
 * 3. Nếu không có vật cản: quay trái và tiếp tục tiến
 */
void process_rotate_left() {
  Rotater.write(ANGLE_LEFT);
  _delay(DELAY_FOR_SERVO_RUN);

  if (get_distance() < threshold_distance) {
    car_control.car_stop();
    ROBOT_STATE = CAR_STATE_PROCESS_ROTATE_RIGHT;
  } else {
    Rotater.write(ANGLE_MIDDLE);
    _delay(DELAY_FOR_SERVO_RUN);
    car_control.car_rotateL(MOTOR_SPEED);
    _delay(DELAY_ROTATION);
    car_control.car_stop();
    ROBOT_STATE = CAR_STATE_FORWARD;
  }
}

/**
 * Hàm process_rotate_right() - Xử lý trạng thái quay phải
 * 1. Quay servo sang phải để kiểm tra
 * 2. Nếu có vật cản: lùi lại và quay trái
 * 3. Nếu không có vật cản: quay phải và tiếp tục tiến
 */
void process_rotate_right() {
  Rotater.write(ANGLE_RIGHT);
  _delay(DELAY_FOR_SERVO_RUN);

  if (get_distance() < threshold_distance) {
    Rotater.write(ANGLE_MIDDLE);
    _delay(DELAY_FOR_SERVO_RUN);
    car_control.car_bw(MOTOR_SPEED, MOTOR_SPEED);
    _delay(DELAY_FOR_GO_BACKWARD);
    car_control.car_stop();
    ROBOT_STATE = CAR_STATE_PROCESS_ROTATE_LEFT;
  } else {
    Rotater.write(ANGLE_MIDDLE);
    _delay(DELAY_FOR_SERVO_RUN);
    car_control.car_rotateR(MOTOR_SPEED);
    _delay(DELAY_ROTATION);
    ROBOT_STATE = CAR_STATE_FORWARD;
  }
}

/**
 * Hàm get_distance() - Đo khoảng cách từ cảm biến
 * @return Khoảng cách đo được (cm)
 */
uint16_t preM = 0;
int get_distance() {
  if (millis() - preM >= 60) {
    preM = millis();
    distance = ultrasonic_sensor.dist();  // Đo khoảng cách
  }
  // _delay(60);                           // Chờ 60ms giữa các lần đo

  return distance;  // Trả về kết quả
}