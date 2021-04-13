#ifndef T_PWM_H
#define T_PWM_H

#include "titimer.h"
#include <pic18f4321.h>

void initPWM(void);
void motorPWM(void);

void PwSetDuty(char dutyCycle);

#endif