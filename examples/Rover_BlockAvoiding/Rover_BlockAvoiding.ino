// Thư viện cần thiết
#include <MKL_HCSR04.h>              // Thư viện điều khiển cảm biến siêu âm 
#include <Makerlabvn_SimpleMotor.h>  // Thư viện điều khiển động cơ
#include <Servo.h>                   // Thư viện điều khiển servo motor

// Định nghĩa các góc quay của servo
#define ANGLE_LEFT 180   // Góc quay sang trái của servo
#define ANGLE_MIDDLE 90  // Góc quay giữa của servo
#define ANGLE_RIGHT 0    // Góc quay sang phải của servo

// Định nghĩa các thông số thời gian và tốc độ
#define DELAY_FOR_SERVO_RUN 1000    // Thời gian chờ servo quay (ms)
#define MOTOR_SPEED 100             // Tốc độ động cơ (0-100%)
#define DELAY_ROTATION 2000         // Thời gian robot quay (ms)
#define DELAY_FOR_GO_BACKWARD 1000  // Thời gian robot lùi lại (ms)

// Định nghĩa chân kết nối cảm biến siêu âm
#define PIN_ULTRASONIC_TRIG 2  // Chân TRIG của cảm biến siêu âm
#define PIN_ULTRASONIC_ECHO 3  // Chân ECHO của cảm biến siêu âm

// Định nghĩa chân kết nối servo motor
#define PIN_SERVO 10  // Chân điều khiển servo

// Định nghĩa chân kết nối động cơ bên trái
#define PIN_MOTOR_LEFT_EN 6   // Chân enable động cơ trái (ENA)
#define PIN_MOTOR_LEFT_IN1 9  // Chân input 1 động cơ trái (IN1)
#define PIN_MOTOR_LEFT_IN2 8  // Chân input 2 động cơ trái (IN2)

// Định nghĩa chân kết nối động cơ bên phải
#define PIN_MOTOR_RIGHT_EN 5   // Chân enable động cơ phải (ENB)
#define PIN_MOTOR_RIGHT_IN1 4  // Chân input 1 động cơ phải (IN3)
#define PIN_MOTOR_RIGHT_IN2 7  // Chân input 2 động cơ phải (IN4)

// Khởi tạo các đối tượng
Makerlabvn_SimpleMotor motor_control;                                    // Điều khiển động cơ
MKL_HCSR04 ultrasonic_sensor(PIN_ULTRASONIC_TRIG, PIN_ULTRASONIC_ECHO);  // Cảm biến siêu âm
Servo Rotater;                                                           // Servo quay cảm biến

// Biến toàn cục
int distance;                 // Lưu khoảng cách đo được từ cảm biến
int threshold_distance = 30;  // Khoảng cách ngưỡng phát hiện vật cản (cm)

// Định nghĩa các trạng thái của robot
#define CAR_STATE_FORWARD 0               // Trạng thái tiến thẳng
#define CAR_STATE_BACKWARD 1              // Trạng thái lùi
#define CAR_STATE_PROCESS_ROTATE_LEFT 2   // Trạng thái quay trái
#define CAR_STATE_PROCESS_ROTATE_RIGHT 3  // Trạng thái quay phải

int ROBOT_STATE = CAR_STATE_FORWARD;  // Khởi tạo trạng thái ban đầu là tiến thẳng

/**
 * Hàm setup() - Khởi tạo các thiết bị
 * - Kết nối servo với chân 10
 * - Đặt servo ở vị trí giữa
 * - Chờ servo quay xong
 */
void setup() {
  motor_control.setup(PIN_MOTOR_LEFT_EN, PIN_MOTOR_LEFT_IN1, PIN_MOTOR_LEFT_IN2,
                      PIN_MOTOR_RIGHT_IN1, PIN_MOTOR_RIGHT_IN2, PIN_MOTOR_RIGHT_EN);  // Khởi tạo động cơ
  Rotater.attach(PIN_SERVO);    // Kết nối servo với chân 10
  Rotater.write(ANGLE_MIDDLE);  // Đặt góc quay của trục động cơ servo ở vị trí giữa
  delay(DELAY_FOR_SERVO_RUN);   // Chờ servo quay xong
}

/**
 * Hàm loop() - Vòng lặp chính
 * Xử lý các trạng thái của robot:
 * - Tiến thẳng: kiểm tra vật cản phía trước
 * - Quay trái: kiểm tra vật cản bên trái
 * - Quay phải: kiểm tra vật cản bên phải
 */
void loop() {
  if (ROBOT_STATE == CAR_STATE_FORWARD) process_go_forward();
  else if (ROBOT_STATE == CAR_STATE_PROCESS_ROTATE_LEFT) process_rotate_left();
  else if (ROBOT_STATE == CAR_STATE_PROCESS_ROTATE_RIGHT) process_rotate_right();
}

/**
 * Hàm process_go_forward() - Xử lý trạng thái tiến thẳng
 * 1. Kiểm tra và đặt servo ở vị trí giữa
 * 2. Đo khoảng cách phía trước
 * 3. Nếu gặp vật cản: dừng và chuyển sang quay trái
 * 4. Nếu không có vật cản: tiếp tục tiến
 */
void process_go_forward() {
  // Đảm bảo góc quay của trục động cơ servo ở vị trí giữa
  if (Rotater.read() != ANGLE_MIDDLE) {
    Rotater.write(ANGLE_MIDDLE);
    delay(DELAY_FOR_SERVO_RUN);
  }

  // Kiểm tra vật cản
  if (get_distance() < threshold_distance) {
    motor_control.car_stop();                     // Dừng xe
    ROBOT_STATE = CAR_STATE_PROCESS_ROTATE_LEFT;  // Chuyển sang quay trái
  } else {
    motor_control.car_fw(MOTOR_SPEED, MOTOR_SPEED);  // Tiến thẳng
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
  delay(DELAY_FOR_SERVO_RUN);

  if (get_distance() < threshold_distance) {
    motor_control.car_stop();
    ROBOT_STATE = CAR_STATE_PROCESS_ROTATE_RIGHT;
  } else {
    Rotater.write(ANGLE_MIDDLE);
    delay(DELAY_FOR_SERVO_RUN);
    motor_control.car_rotateL(MOTOR_SPEED);
    delay(DELAY_ROTATION);
    motor_control.car_stop();
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
  delay(DELAY_FOR_SERVO_RUN);

  if (get_distance() < threshold_distance) {
    Rotater.write(ANGLE_MIDDLE);
    delay(DELAY_FOR_SERVO_RUN);
    motor_control.car_bw(MOTOR_SPEED, MOTOR_SPEED);
    delay(DELAY_FOR_GO_BACKWARD);
    motor_control.car_stop();
    ROBOT_STATE = CAR_STATE_PROCESS_ROTATE_LEFT;
  } else {
    Rotater.write(ANGLE_MIDDLE);
    delay(DELAY_FOR_SERVO_RUN);
    motor_control.car_rotateR(MOTOR_SPEED);
    delay(DELAY_ROTATION);
    ROBOT_STATE = CAR_STATE_FORWARD;
  }
}

/**
 * Hàm get_distance() - Đo khoảng cách từ cảm biến
 * @return Khoảng cách đo được (cm)
 */
int get_distance() {
  distance = ultrasonic_sensor.dist();  // Đo khoảng cách
  delay(60);                            // Chờ 60ms giữa các lần đo
  return distance;                      // Trả về kết quả
}
