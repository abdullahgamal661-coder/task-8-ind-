#include "L298.h"
#include "Cytron.h"
#include "BTS.h"

#define IN1 PA0
#define IN2 PA1
#define ENA PA2 // must be a pwm pin
#define DIR PA4
#define PWM PA3 // must be a pwm pin
#define RPWM PA6 // must be a pwm pin
#define LPWM PA7 // must be a pwm pin


void setup()
{
   // define the pin mode for each driver
    L298N_init(IN1, IN2, ENA);
    Cytron_init(DIR, PWM);
    BTS_init(RPWM, LPWM);
}

void loop()
{
  // enter the speed in pwm (0->255)
  // --------L298N-------------------
    L298N_drive(IN1, IN2, ENA, 200); // move forward 
    delay(2000);
    L298N_drive(IN1, IN2, ENA, -150);// move backward
    delay(2000);
    L298N_drive(IN1, IN2, ENA, 0); // stop
    delay(2000);

//-----------cytron--------------
    Cytron_drive(DIR, PWM, 200); // forward
    delay(2000);
    Cytron_drive(DIR, PWM, -150);// move backward
    delay(2000);
    Cytron_drive(DIR, PWM, 0);// stop
    delay(2000);

// -----------bts-----------------
    BTS_drive(RPWM, LPWM, 200);// forward
    delay(2000);
    BTS_drive(RPWM, LPWM, -150);// move backward
    delay(2000);
    BTS_drive(RPWM, LPWM, 0);// stop
    delay(2000);
}
}