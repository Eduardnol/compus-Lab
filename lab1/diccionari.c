// Diccionari
// Interficies 0 y 1

unsigned char TiGetTimer(void);

// Pre: Hay algun timer libre
// Post:Devuelve el handler de un timer libre y lo marca como ocupado

unsigned int TiGetTics(unsigned char handler);
// Handler ha sido devuelto por TiGetTimer()
// No han pasado mas de MAXTICS des de el último TiResetTics(handler)
// Post: Devuelve el numero de Tics desde el ultimo TiResetTics(handler)

void TiResetTics(unsigned char handler);
// Pre: Handler ha sido devuelto por TiGetTimer().
// Post: Iguala los tics del handler a los tics universales

// Interficie 4 (de pulsador a 7 segments)
void SsincrementaValor(void);
// Pre: --
// Post: incrementa de forma circular el valor que se esta formando en el 7S y
// se actualiza el duty cyle del PWM

// Interficie 6 ( del 7 Segmenta al PWM)
void PwSetDuty(char dutyCycle);
// Pre: 0 <= dutyCucle <= MAXDUTY
// Post: Actualiza el duty cyle del PWM

// Interficie 7 (de 7 segments a Cua)
void CuEncua(char valor);
// Pre: 0 <= valor <= MAXVALUESAMPLE
//Post: Encua el valor de forma circular

//Interficie 5 (de SIO a 7s)
void SsResetejaValor(void);
//Pre: --
//Post: Guardamos el valor actual en la cola y ponemos un '0' en el valor actual y el duty cycle del PWM


//Interficies 3 i 8
char CuDesencua(char quinaPosicio);
//Pre: 0 <= quinaPosicio <= MAXPOSICIONES
//Post: Devuelve quinaPosicio de la cua
//Lectura no destructiva


//Interficie 2
void GeStartAverage(void);
//Pre: --
//Post indica que se debe empezar con una nueva mediana


char GeGetAverage(void);
//Pre: --
//Post: Devuelve la ultima mediana geometrica calculada o -1 si aun esta calculando