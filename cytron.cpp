#include "Cytron.h"

void Cytron_init(int DIR, int PWM) {
  pinMode(DIR, OUTPUT);
  pinMode(PWM, OUTPUT);
  digitalWrite(DIR, LOW);
  analogWrite(PWM, 0);
}

void Cytron_drive(int DIR, int PWM, int speed_in_pwm) {
  if (speed_in_pwm > 0) {
    digitalWrite(DIR, HIGH);
    analogWrite(PWM, speed_in_pwm);
  } else if (speed_in_pwm < 0) {
    digitalWrite(DIR, LOW);
    analogWrite(PWM, -speed_in_pwm);
  } else {
    analogWrite(PWM, 0);
  }
}