/**
 * Tilte: Block Avoiding Car R1
 * Author: Mika
 * Date: 05/21/2024
 * Version: v1.0
 * Purpose: This code is for reference
 */

// Include libraries
#include <HCSR04.h>
#include <Makerlabvn_SimpleMotor.h>
#include <Servo.h>

// Define
#define ANGLE_L 180 // The left side of the car for rc servo motor rotate
#define ANGLE_C 90  // The middle side of the car for rc servo motor rotate
#define ANGLE_R 0   // The right side of the car for rc servo motor rotate

#define DELAYSERVO 1000  // Define the servo's delay time
#define MOTORSPEED 100   // Define the car's speed
#define DELAYROTATE 2000 // Define the delaytime for the car rotates
#define DELAYBW 1000     // Define the delaytime for the car goes back
// #define PIN_IN1 4       //! D4
// #define PIN_IN2 7       //! D7
// #define PIN_IN3 9       //! D9
// #define PIN_IN4 8       //! D8
#define PIN_TRIG 2
#define PING_ECHO 3

// Object initialization
// Makerlabvn_SimpleMotor Driver(PIN_IN1, PIN_IN2, PIN_IN3, PIN_IN4);
HCSR04 Scaner(2, 3);
Servo Rotater;
Motor_lib motor_A;
Motor_lib motor_B;
TwoMotor_lib Driver;

// Variable
int distance;                      // The variable stores the distance value
const int threshold_distance = 30; // Variable that specifies the distance threshold to the obstacle
enum
{ // Specifies 4 car's states
  RB_FF,
  RB_BB,
  RB_RL,
  RB_RR,
};
int RB_state = RB_FF; // Specifies the fist car's state is going forward

void setup()
{
  // put your setup code here, to run once:
  Rotater.attach(10);     // Initialize the control pin of rc servo
  Rotater.write(ANGLE_C); // For the ultrasonic sensor to look forward
  delay(DELAYSERVO);      // Wait for the motor to rotate for about DELAYSERVO
  motor_A.begin(6, 9, 8);
  motor_B.begin(5, 7, 4);
  Driver.begin(motor_A, motor_B);
}

void loop()
{
  // put your main code here, to run repeatedly:
  switch (RB_state)
  {
  /**
   * Consider variable RB_state:
   * - RB_FF: go foward
   * - RB_RL: turn left
   * - RB_RR: turn right
   */
  case RB_FF:
    go_F();
    break;
  case RB_RL:
    rotate_L();
    break;
  case RB_RR:
    rotate_R();
    break;
  }
}

// Function
void go_F()
{
  // In case the ultrasonic sensor is at an angle that does not look straight ahead of the car
  if (Rotater.read() != ANGLE_C)
  {
    // Return the ultrasonic sensor to the middle
    Rotater.write(ANGLE_C);
    // Wait for the rc servo to rotate
    delay(DELAYSERVO);
  }
  // In case of encountering obstacles
  if (Ultradistance_Scan() < threshold_distance)
  {
    Driver.car_stop(); // Let the car stop
    RB_state = RB_RL;  // Change the vehicle's status to turn left
    // And if there are no obstacles
  }
  else
  {
    Driver.car_fw(MOTORSPEED, MOTORSPEED); // Let the car run straight
  }
}

void rotate_L()
{
  // Turn the rc servo to the left side of the car
  Rotater.write(ANGLE_L);
  // Wait for the rc servo to rotate
  delay(DELAYSERVO);
  // In case of encountering obstacles
  if (Ultradistance_Scan() < threshold_distance)
  {
    Driver.car_stop(); // Let the car stop
    RB_state = RB_RR;  // Change the vehicle's status to turn left
    // And if there are no obstacles
  }
  else
  {
    Rotater.write(ANGLE_C);         // Turn the rc servo to the middle side of the car
    delay(DELAYSERVO);              // Wait for the rc servo to rotate
    Driver.car_rotateL(MOTORSPEED); // Let the car turn left
    delay(DELAYROTATE);             // Wait for the car to rotate
    Driver.car_stop();              // Let the car stop
    RB_state = RB_FF;               // Change the vehicle's status to go forward
  }
}

void rotate_R()
{
  // Turn the rc servo to the left side of the car
  Rotater.write(ANGLE_R);
  // Wait for the rc servo to rotate
  delay(DELAYSERVO);

  // In case of encountering obstacles
  if (Ultradistance_Scan() < threshold_distance)
  {
    Rotater.write(ANGLE_C);                // Turn the rc servo to the middle side of the car
    delay(DELAYSERVO);                     // Wait for the rc servo to rotate
    Driver.car_bw(MOTORSPEED, MOTORSPEED); // Let the car go backward
    delay(DELAYBW);                        // Wait for the car to go backward
    Driver.car_stop();                     // Let the car stop
    RB_state = RB_RL;                      // Change the vehicle's status to turn left

    // And if there are no obstacles
  }
  else
  {
    Rotater.write(ANGLE_C);         // Turn the rc servo to the middle side of the car
    delay(DELAYSERVO);              // Wait for the rc servo to rotate
    Driver.car_rotateR(MOTORSPEED); // Let the car turn right
    delay(DELAYROTATE);             // Wait for the car to rotate
    RB_state = RB_FF;               // Change the vehicle's status to go foward
  }
}

int Ultradistance_Scan()
{
  distance = Scaner.dist(); // Store the measured value in the distance variable
  delay(60);                // Scanning interval
  return distance;          // Returns the value of the distance variable
}
