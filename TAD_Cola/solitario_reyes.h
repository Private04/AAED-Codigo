#ifndef SOLITARIO_REYES_H
#define SOLITARIO_REYES_H
#include "cola_ps.h"
struct tCarta{
    enum figura{AS=0,DOS,TRES,CUATRO,CINCO,SEIS,SIETE,SOTA,CABALLO,REY};
    enum palo{COPAS,BASTOS,ESPADAS,OROS};
    figura fig;
    palo pal;
    tCarta(figura f,palo p) : fig(f), pal(p) {}
};

typedef Cola_ps<tCarta> tMonton; //Monton debe ser una cola de tamamax 5 y con 4 elementos tCarta
bool solitario_reyes(tMonton montones[],tCarta::figura fig_inicial,tMonton& resultado);
#endif