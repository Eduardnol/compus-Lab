#include <pic18f4321.h>
#include "TOut.h"

void initOut(void) {
  TRISC = 0x00;  // Definimos el puerto de salida
  LATC = 0X00;   // Ponemos que todas las salidas sean cero
}

void mostraValor(unsigned char valor) {
  // Pre: --
  // Post: Mueve un valor al LATC
  LATC = valor;
}