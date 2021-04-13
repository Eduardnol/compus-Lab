#include "TPromig.h"
#include "TOut.h"
#define MAXMOSTRES 69

unsigned char mostres[MAXMOSTRES];
int acum;
char start;
char index;
char indexEscriptura;

// En els inits podem fer bucles pero en els estats no
void initPromig(void) {
  acum = 0;
  start = 0;
  index = 0;
  indexEscriptura = 0;
  for (int i = 0; i < MAXMOSTRES; i++) {
    mostres[i] = 0;
  }
}

void motorPromig(void) {
  static char estat = 0;
  switch (estat) {
    case 0:
      if (start == 1) {
        index = 0;
        acum = 0;
        start = 0;
        estat = 1;
      }
      break;
    case 1:
      if (index < MAXMOSTRES) {
        acum += mostres[index++];
      } else {
        acum = acum / MAXMOSTRES;
        estat = 2;
      }
      break;
    case 2:
      mostraValor((unsigned char)acum);
      estat = 0;
      break;
  }
}

void guardaMostra(unsigned char mostra) {
  // Pre --
  // Post: guarda el valor de la muestra dentro del array de muestras de forma
  // circular
  mostres[indexEscriptura] = mostra;
  indexEscriptura++;
  if (indexEscriptura == MAXMOSTRES) indexEscriptura = 0;
}

void iniciaPromig(void) {
  // Pre: --
  // Post: el TAD promedio inicia el calculo del promedio
  start = 1;
}