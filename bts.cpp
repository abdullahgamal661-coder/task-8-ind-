#include "BTS.h"

void BTS_init(int RPWM, int LPWM) {
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);

  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);
}

void BTS_drive(int RPWM, int LPWM, int speed_in_pwm) {
  if (speed_in_pwm > 0) {

    analogWrite(LPWM, 0);
    analogWrite(RPWM, speed_in_pwm);
  } else if (speed_in_pwm < 0) {

    analogWrite(RPWM, 0);
    analogWrite(LPWM, -speed_in_pwm);
  } else {

    analogWrite(RPWM, 0);
    analogWrite(LPWM, 0);
  }
}