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
#include "Makerlabvn_SimpleMotor.h"

// DEFINE
// #define PIN_IN1 4
// #define PIN_IN2 7
// #define PIN_IN3 9
// #define PIN_IN4 8
#define SPEED 70

// OBJECT INITIALIZATION

// Makerlabvn_SimpleMotor demoMotor(PIN_IN1, PIN_IN2, PIN_IN3, PIN_IN4);

Motor_lib motor_A;
Motor_lib motor_B;

TwoMotor_lib demoMotor;



void setup() {
  // put your setup code here, to run once:
  demoMotor.car_stop();    // Let the car stop
  Serial.begin(9600);    // Initialize Serial baudrate communication
  Dabble.begin(Serial);  // Initialize Dabble baudrate communication

  motor_A.begin(6, 9, 8);
  motor_B.begin(5, 7, 4);

  demoMotor.begin(motor_A,motor_B);
      Serial.println("run");
}


void loop() {
  // put your main code here, to run repeatedly:
  Dabble.processInput();             // Receive information from Dabble app
  if (GamePad.isUpPressed()) {       // When UP BUTTON is pressed
    Serial.println("up");
    demoMotor.car_fw(SPEED, SPEED);  // Let the car go foward
  } else {
    if (GamePad.isDownPressed()) {     // When DOWN BUTTON is pressed
    Serial.println("down");

      demoMotor.car_bw(SPEED, SPEED);  // Let the car go backward
    } else {
      if (GamePad.isLeftPressed()) {   // When LEFT BUTTON is pressed
    Serial.println("left");

        demoMotor.car_rotateL(SPEED);  // Let the car turn left
      } else {
        if (GamePad.isRightPressed()) {  // When RIGHT BUTTON is pressed
    Serial.println("right");
          demoMotor.car_rotateR(SPEED);  // Let the car turn right
        } else {                         // When no button is pressed
          demoMotor.car_stop();          // Let the car stop
        }
      }
    }
  }
}