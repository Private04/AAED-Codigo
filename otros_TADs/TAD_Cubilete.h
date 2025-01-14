#ifndef CUBILETE_H
#define CUBILETE_H
#include "..\TAD_Pila\pila_ps.h"
struct tCubo {
    int tama;
    enum eEstado{BOCA_ABAJO,BOCA_ARRIBA} estado;
    tCubo(int t=0,eEstado est=BOCA_ABAJO) : tama(t), estado(est) {}
};
Pila<tCubo> apilacion(Pila<tCubo> base);
#endif