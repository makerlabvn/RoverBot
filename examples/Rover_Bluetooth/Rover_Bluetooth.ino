/**
 * Tilte: Bluetooth Car R1
 * Author: Mika
 * Date: 05/23/2024
 * Version: v1.0
 * Purpose: This code is for reference
 */

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

// INCLUDE LIBRARIES
#include "Dabble.h"
#include <Makerlabvn_SimpleMotor.h>

// DEFINE
#define MOTOR_SPEED 70

// OBJECT INITIALIZATION

Makerlabvn_SimpleMotor car_control;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);    // Initialize Serial baudrate communication
  Dabble.begin(Serial);  // Initialize Dabble baudrate communication
  car_control.setup(6, 9, 8, 7, 4, 5);
  car_control.car_stop();  // Let the car stop
  Serial.println("run");
}

void loop() {
  // put your main code here, to run repeatedly:
  Dabble.processInput();        // Receive information from Dabble app
  if (GamePad.isUpPressed()) {  // When UP BUTTON is pressed
    Serial.println("up");
    car_control.car_fw(MOTOR_SPEED, MOTOR_SPEED);  // Let the car go foward
  } else {
    if (GamePad.isDownPressed()) {  // When DOWN BUTTON is pressed
      Serial.println("down");
      car_control.car_bw(MOTOR_SPEED, MOTOR_SPEED);  // Let the car go backward
    } else {
      if (GamePad.isLeftPressed()) {  // When LEFT BUTTON is pressed
        Serial.println("left");

        car_control.car_rotateL(MOTOR_SPEED);  // Let the car turn left
      } else {
        if (GamePad.isRightPressed()) {  // When RIGHT BUTTON is pressed
          Serial.println("right");
          car_control.car_rotateR(MOTOR_SPEED);  // Let the car turn right
        } else {                                 // When no button is pressed
          car_control.car_stop();                // Let the car stop
        }
      }
    }
  }
}