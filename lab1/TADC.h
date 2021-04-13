#ifndef _TADC_H_
#define _TADC_H_

#include "TPromig.h"
#include "titimer.h"

//Pre: TAD timer debe haber sido inicializado
//Post: Inicializa el ADC con justificacion a la izquierda canal 0
void initADC(void);
void motorADC(void);
#endif