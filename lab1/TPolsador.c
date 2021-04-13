#include "TPolsador.h"
#define PREMUT 0
#define TREBOT 20

static char timer;
void initPolsador(void) {
  timer = TiGetTimer();
  TRISBbits.TRISB0 = 1;
  INTCON2bits.RBPU = 0;
}

void motorPolsador(void) {
  static char estat = 0;
  switch (estat) {
    case 0:
      if (PORTBbits.RB0 == PREMUT) {
        TiResetTics(timer);
        estat = 1;
      }
      break;
    case 1:
      if (TiGetTics(timer) >= TREBOT){
          if (PORTBbits.RB0 == PREMUT) {
            estat = 2;
            SsIncrementaValor();
          } else {
            estat = 0;
          }
        }
      break;
    case 2:
      if (PORTBbits.RB0 != PREMUT) {
        TiResetTics(timer);
        estat = 3;
      }
      break;
    case 3:
      if (TiGetTics(timer) >= TREBOT) {
        estat = 0;
      }
      break;
  }}