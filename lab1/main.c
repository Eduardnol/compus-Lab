#include <pic18f4321.h>
#include <xc.h>

#include "TOut.h"
#include "TPWM.h"
#include "TPolsador.h"
#include "TSsegments.h"
#include "titimer.h"

#pragma config OSC = HS  // INTIO2
#pragma config PBADEN = DIG
#pragma config MCLRE = OFF
#pragma config DEBUG = OFF
#pragma config PWRT = OFF
#pragma config BOR = OFF
#pragma config WDT = OFF
#pragma config LVP = OFF

//#define u 1
//#define zero 0

void HighInterruptRSI(void);
void main(void);
void Initports(void);

int tick_count;
// Important: NO es poden cridar les funcions d'interrupcions des del codi
// ja que les seves funcions de retorn en asm són diferents.
// Definició d'una interrupció d'alta prioritat.
void __interrupt(high_priority) RSI_High(void) {
  if (INTCONbits.TMR0IF == 1) RSI_Timer0();
}
// Definició d'una interrupció de baixa prioritat.
void __interrupt(low_priority) RSI_Low(void) {}

void main(void) {
  TiInit();
  initPWM();
  Initports();
  initSsegments();
  initPolsador();
  while (1) {
    motorPWM();
    motorPolsador();
  }
}

void Initports(void) { INTCONbits.GIE = 1; }
