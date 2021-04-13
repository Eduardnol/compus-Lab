#include "TSsegments.h"
#define TAULA7S 10

static char valor;
const char taula[TAULA7S] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};

void initSsegments(void) {
  TRISD = 0x00;
  valor = 0;
  LATD = taula[valor];
}

void SsIncrementaValor(void) {
  //valor = (valor + 1) % (TAULA7S - 1); //EL -1 HACE FALTA? --> Cuenta hasta 8 y luego el 0
   valor = (valor + 1) % (TAULA7S); //Cuenta hasta 9 y luego 0
  LATD = taula[valor];
  PwSetDuty(valor * 2);
  // es lo mismo que decir (valor << 1) & 0xFE
}

void SsResetejaValor(void) {
  valor = 0;
  LATD = taula[valor];
  PwSetDuty(0);
}