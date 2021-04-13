#ifndef _T_PROMIG_H_
#define _T_PROMIG_H_

void initPromig(void);
// Pre: --
// Post inicializamos el array de muestras a 0
void motorPromig(void);
void guardaMostra(unsigned char mostra);
// pre: --
// Post: guarda el valor de la muestra dentro del array de muestras de forma
// circular
void iniciaPromig(void);
// Pre: --
// Post: El TAD promedio inicia el calculo del promedio

#endif