#ifndef BTS_H
#define BTS_H

void BTS_init(int RPWM, int LPWM);
void BTS_drive(int RPWM, int LPWM, int speed_in_pwm);

#endif