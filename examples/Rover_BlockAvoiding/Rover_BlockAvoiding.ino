// Include libraries
#include <MKL_HCSR04.h>
#include <Makerlabvn_SimpleMotor.h>
#include <Servo.h>

// Define
#define ANGLE_LEFT 180   // The left side of the car for rc servo motor rotate
#define ANGLE_MIDDLE 90  // The middle side of the car for rc servo motor rotate
#define ANGLE_RIGHT 0    // The right side of the car for rc servo motor rotate

#define DELAY_FOR_SERVO_RUN 1000    // Define the servo's delay time
#define MOTOR_SPEED 100             // Define the car's speed
#define DELAY_ROTATION 2000         // Define the delaytime for the car rotates
#define DELAY_FOR_GO_BACKWARD 1000  // Define the delaytime for the car goes back

#define PIN_TRIG 2
#define PING_ECHO 3

// Object initialization
Makerlabvn_SimpleMotor motor_control(6, 9, 8, 7, 4, 5);
MKL_HCSR04 ultrasonic_sensor(2, 3);
Servo Rotater;

// Variable
int distance;                 // The variable stores the distance value
int threshold_distance = 30;  // Variable that specifies the distance threshold to the obstacle
                              // Specifies 4 car's states
#define CAR_STATE_FOWARD 0
#define CAR_STATE_BACKWARD 1
#define CAR_STATE_proccess_rotate_leftEFT 2
#define CAR_STATE_proccess_rotate_rightIGHT 3

int ROBOT_STATE = CAR_STATE_FOWARD;  // Specifies the fist car's state is going forward

void setup() {
  // put your setup code here, to run once:
  Rotater.attach(10);           // Initialize the control pin of rc servo
  Rotater.write(ANGLE_MIDDLE);  // For the ultrasonic sensor to look forward
  delay(DELAY_FOR_SERVO_RUN);   // Wait for the motor to rotate for about DELAY_FOR_SERVO_RUN
}

void loop() {
  // put your main code here, to run repeatedly:
  /**
   * Consider variable ROBOT_STATE:
   * - CAR_STATE_FOWARD: go foward
   * - CAR_STATE_proccess_rotate_leftEFT: turn left
   * - CAR_STATE_proccess_rotate_rightIGHT: turn right
   */
  if (ROBOT_STATE == CAR_STATE_FOWARD) proccess_go_foward();
  else if (ROBOT_STATE == CAR_STATE_proccess_rotate_leftEFT) proccess_rotate_left();
  else if (ROBOT_STATE == CAR_STATE_proccess_rotate_rightIGHT) proccess_rotate_right();
}

// Function
void proccess_go_foward() {
  // In case the ultrasonic sensor is at an angle that does not look straight ahead of the car
  if (Rotater.read() != ANGLE_MIDDLE) {
    // Return the ultrasonic sensor to the middle
    Rotater.write(ANGLE_MIDDLE);
    // Wait for the rc servo to rotate
    delay(DELAY_FOR_SERVO_RUN);
  }
  // In case of encountering obstacles
  if (get_distance() < threshold_distance) {
    motor_control.car_stop();         // Let the car stop
    ROBOT_STATE = CAR_STATE_proccess_rotate_leftEFT;  // Change the vehicle's status to turn left
    // And if there are no obstacles
  } else {
    motor_control.car_fw(MOTOR_SPEED, MOTOR_SPEED);  // Let the car run straight
  }
}

void proccess_rotate_left() {
  // Turn the rc servo to the left side of the car
  Rotater.write(ANGLE_LEFT);
  // Wait for the rc servo to rotate
  delay(DELAY_FOR_SERVO_RUN);
  // In case of encountering obstacles
  if (get_distance() < threshold_distance) {
    motor_control.car_stop();          // Let the car stop
    ROBOT_STATE = CAR_STATE_proccess_rotate_rightIGHT;  // Change the vehicle's status to turn left
    // And if there are no obstacles
  } else {
    Rotater.write(ANGLE_MIDDLE);              // Turn the rc servo to the middle side of the car
    delay(DELAY_FOR_SERVO_RUN);               // Wait for the rc servo to rotate
    motor_control.car_rotateL(MOTOR_SPEED);  // Let the car turn left
    delay(DELAY_ROTATION);                    // Wait for the car to rotate
    motor_control.car_stop();                // Let the car stop
    ROBOT_STATE = CAR_STATE_FOWARD;              // Change the vehicle's status to go forward
  }
}

void proccess_rotate_right() {
  // Turn the rc servo to the left side of the car
  Rotater.write(ANGLE_RIGHT);
  // Wait for the rc servo to rotate
  delay(DELAY_FOR_SERVO_RUN);

  // In case of encountering obstacles
  if (get_distance() < threshold_distance) {
    Rotater.write(ANGLE_MIDDLE);                      // Turn the rc servo to the middle side of the car
    delay(DELAY_FOR_SERVO_RUN);                       // Wait for the rc servo to rotate
    motor_control.car_bw(MOTOR_SPEED, MOTOR_SPEED);  // Let the car go backward
    delay(DELAY_FOR_GO_BACKWARD);                     // Wait for the car to go backward
    motor_control.car_stop();                        // Let the car stop
    ROBOT_STATE = CAR_STATE_proccess_rotate_leftEFT;                 // Change the vehicle's status to turn left

    // And if there are no obstacles
  } else {
    Rotater.write(ANGLE_MIDDLE);              // Turn the rc servo to the middle side of the car
    delay(DELAY_FOR_SERVO_RUN);               // Wait for the rc servo to rotate
    motor_control.car_rotateR(MOTOR_SPEED);  // Let the car turn right
    delay(DELAY_ROTATION);                    // Wait for the car to rotate
    ROBOT_STATE = CAR_STATE_FOWARD;              // Change the vehicle's status to go foward
  }
}

int get_distance() {
  distance = ultrasonic_sensor.dist();  // Store the measured value in the distance variable
  delay(60);                            // Scanning interval
  return distance;                      // Returns the value of the distance variable
}
