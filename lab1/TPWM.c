#include "TPWM.h"
#define HZ50 20

static char timer;
static char duty;

void initPWM(void) {
    TRISAbits.TRISA3 = 0;
    timer = TiGetTimer();
    TiResetTics(timer);
    duty = 10;
}

void motorPWM(void) {
    static char estat = 0; // Le ponemos static para evitar que cada vez que
    // hacemos la llamada a PWM nos ponga la variable a 0.
    // De este modo solamente lo va a hacer la primera vez

    switch (estat) {
        case 0:
            if (TiGetTics(timer) >= duty) {
                LATAbits.LATA3 = 0;
                estat = 1;
            }
            break;
        case 1:
            if (TiGetTics(timer) >= HZ50) {
                TiResetTics(timer);
                LATAbits.LATA3 = 1;
                estat = 0;
            }
            break;
        default:
            break;
    }
}

void PwSetDuty(char dutyCycle){
    duty = dutyCycle;
}
