#include "TADC.h"
#include <xc.h>
#include <pic18f4321.h>
#define MS10 10

void initADC(void) {
  ADCON0 = 0x01;
  ADCON1 = 0x0E;
  ADCON2bits.ADFM = 0;
  TiResetTics(TiGetTimer());
}

void motorADC(void) {
  static char estat = 0;
  switch (estat) {
    case 0:
      if (TiGetTics(TiGetTimer()) >= MS10) {
        TiResetTics(TiGetTimer());
        ADCON0bits.GO_DONE = 1;
        estat = 1;
      }
      break;
    case 1:
      if (ADCON0bits.GO_DONE == 0) {
        guardaMostra(ADRESH);
        iniciaPromig();
        estat = 0;
      }
  }
}