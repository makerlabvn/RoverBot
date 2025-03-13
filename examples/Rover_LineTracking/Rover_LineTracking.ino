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
#define PIN_OUT1 A1     //! A1
#define PIN_OUT2 A2     //! A2
#define DELAY_CAR 1000  //! Define the delaytime of the car when it's turned on

// OBJECT INITIALIZATION
Makerlabvn_SimpleMotor car_control;
// VARIABLE
int threshold_right = 450;  // Threshold of the right sensor
int threshold_left = 450;   // Threshold of the left sensor
int last_lost_dir;          // The variable stores the value of the vehicle's state before losing the line
int left_dir = 1;           // The variable stores the states that the vehicle is on the left side of the line
int right_dir = 0;          // The variable stores the states that the vehicle is on the right side of the line
int speed_forward = 70;     // The variable stores the vehicle's speed value when run
int speed_stop = 0;         // The variable stores the vehicle's speed value when stop

void setup() {
  last_lost_dir = left_dir;  // Set the state variable before losing the line
  car_control.setup(6, 9, 8, 7, 4, 5);
  car_control.car_stop();
  // Let the car stop about DELAY_CAR
  delay(DELAY_CAR);
}

void loop() {
  // Store the value read from the sensor into a variable
  int eye_left_value = analogRead(PIN_OUT1);
  int eye_right_value = analogRead(PIN_OUT2);

  // When 2 sensor read the line
  if ((eye_left_value > threshold_left) && (eye_right_value > threshold_right)) {
    // Let the car go forward
    car_control.car_fw(speed_forward, speed_forward);
  } else {
    // When the Right sensor read the line, but not the Left
    if ((eye_left_value < threshold_left) && (eye_right_value > threshold_right)) {
      last_lost_dir = left_dir;                       // Set the variable to find the line if it lost
      car_control.car_fw(speed_forward, speed_stop);  // Let the car go forward
    } else {
      // When the Left sensor read the line, but not the Right
      if ((eye_left_value > threshold_left) && (eye_right_value < threshold_right)) {
        last_lost_dir = right_dir;                      // Set the variable to find the line if it lost
        car_control.car_fw(speed_stop, speed_forward);  // Let the car go left
      } else {
        // When the car lost the line
        if (last_lost_dir == left_dir) {
          // if the vehicle's last direction of travel was to the left
          car_control.car_rotateR(speed_forward);  // Let the car turn RIGHT
        } else {
          // if the vehicle's last direction of travel was to the right
          car_control.car_rotateL(speed_forward);  // Let the car turn LEFT
        }
      }
    }
  }
}
