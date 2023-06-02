#include "motor_driver.h"

void initMotorController(){
    digitalWrite(RIGHT_MOTOR_ENABLE, HIGH);
    digitalWrite(LEFT_MOTOR_ENABLE, HIGH);
}

void setMotorSpeed(side motor_side, int speed){
    if (speed >= 0) {
        if (motor_side == LEFT) {
            analogWrite(LEFT_MOTOR_FORWARD, speed);
            analogWrite(LEFT_MOTOR_BACKWARD, 0);
        }
        else if (motor_side == RIGHT) {
            analogWrite(RIGHT_MOTOR_FORWARD, speed);
            analogWrite(RIGHT_MOTOR_BACKWARD, 0);
        }
        else {
            analogWrite(RIGHT_MOTOR_FORWARD, 0);
            analogWrite(RIGHT_MOTOR_BACKWARD, 0);
            analogWrite(LEFT_MOTOR_FORWARD, 0);
            analogWrite(LEFT_MOTOR_BACKWARD, 0);
        }
    }
    else {
        speed = -speed;
        if (motor_side == LEFT) {
            analogWrite(LEFT_MOTOR_FORWARD, 0);
            analogWrite(LEFT_MOTOR_BACKWARD, speed);
        }
        else if (motor_side = RIGHT)
        {
            analogWrite(RIGHT_MOTOR_FORWARD, 0);
            analogWrite(RIGHT_MOTOR_BACKWARD, speed);
        }
    }
}

void setMotorSpeeds(int left_speed, int right_speed){
    setMotorSpeed(LEFT,left_speed);
    setMoterSpeed(RIGHT,right_speed);
}