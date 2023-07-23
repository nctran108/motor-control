#include "motor_driver.h"

#define BAUDRATE      57600
#define MAX_PWM       255
#define PID_RATE      30

int left_speed;
int right_speed;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(BAUDRATE);
  
  while (!Serial) {
    ; // wait for serial port connect. Needed for native USB port only
  }
  // init all pins
  initMotorController();
}

// the loop routine runs over and over again forever:
void loop() {
  // if get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // enable both motors
    enableMotors();

    // read speeds from serial port
    left_speed = Serial.parseInt();
    right_speed = Serial.parseInt();
    left_speed = constrain(left_speed,-MAX_PWM,MAX_PWM);
    right_speed = constrain(right_speed,-MAX_PWM,MAX_PWM);

    // set motor speed

    setMotorSpeeds(left_speed,right_speed);
  }
}