/**
 * Tilte: Line Tracking Car R1 With 2 Sensor
 * Author: Mika
 * Date: 05/23/2024
 * Version: v1.0
 * Purpose: This code is for reference
 */

// INCLUDE LIBRARIES
#include "Makerlabvn_SimpleMotor.h"

// DEFINE
#define PIN_OUT1 A1 //! A1
#define PIN_OUT2 A2 //! A2
// #define PIN_IN1 4       //! D4
// #define PIN_IN2 7       //! D7
// #define PIN_IN3 9       //! D9
// #define PIN_IN4 8       //! D8
#define DELAY_CAR 1000 //! Define the delaytime of the car when it's turned on

// OBJECT INITIALIZATION
// Makerlabvn_SimpleMotor demoMotor(PIN_IN1, PIN_IN2, PIN_IN3, PIN_IN4);
Motor_lib motor_A;
Motor_lib motor_B;
TwoMotor_lib demoMotor;
// VARIABLE
const float threshold_right = 450; // Threshold of the right sensor
const float threshold_left = 450;  // Threshold of the left sensor
int last_lost_dir;                 // The variable stores the value of the vehicle's state before losing the line
const int left_dir = 1;            // The variable stores the states that the vehicle is on the left side of the line
const int right_dir = 0;           // The variable stores the states that the vehicle is on the right side of the line
const int speedForward = 70;       // The variable stores the vehicle's speed value when run
const int speedStop = 0;           // The variable stores the vehicle's speed value when stop

void setup()
{
  last_lost_dir = left_dir; // Set the state variable before losing the line
  // Let the car stop about DELAY_CAR
  motor_A.begin(6, 9, 8);
  motor_B.begin(5, 7, 4);
  demoMotor.begin(motor_A,motor_B);
  demoMotor.car_stop();
  delay(DELAY_CAR);
}

void loop()
{
  // Store the value read from the sensor into a variable
  int eye_Left_Value = analogRead(PIN_OUT1);
  int eye_Right_Value = analogRead(PIN_OUT2);

  // When 2 sensor read the line
  if ((eye_Left_Value > threshold_left) && (eye_Right_Value > threshold_right))
  {
    // Let the car go forward
    demoMotor.car_fw(speedForward, speedForward);
  }
  else
  {
    // When the Right sensor read the line, but not the Left
    if ((eye_Left_Value < threshold_left) && (eye_Right_Value > threshold_right))
    {
      last_lost_dir = left_dir;                  // Set the variable to find the line if it lost
      demoMotor.car_fw(speedForward, speedStop); // Let the car go forward
    }
    else
    {
      // When the Left sensor read the line, but not the Right
      if ((eye_Left_Value > threshold_left) && (eye_Right_Value < threshold_right))
      {
        last_lost_dir = right_dir;                 // Set the variable to find the line if it lost
        demoMotor.car_fw(speedStop, speedForward); // Let the car go left
      }
      else
      {
        // When the car lost the line
        if (last_lost_dir == left_dir)
        {
          // if the vehicle's last direction of travel was to the left
          demoMotor.car_rotateR(speedForward); // Let the car turn RIGHT
        }
        else
        {
          // if the vehicle's last direction of travel was to the right
          demoMotor.car_rotateL(speedForward); // Let the car turn LEFT
        }
      }
    }
  }
}
