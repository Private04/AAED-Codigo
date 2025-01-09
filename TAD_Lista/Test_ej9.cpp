#include <iostream>
#include <cstdlib>
#include <string>
#include "juego_aleatorio.h"
int rand_rango(int a,int b)
{
    return (rand() % (b-a+1)) + a;
}
int main (int argc,char **argv)
{
    listaCir<jugador> jugadores;
    listaCir<jugador>::posicion p;
    jugadores.insertar(jugador(argv[1],1),listaCir<jugador>::POS_NULA);
    p=jugadores.inipos();
    std::cout << "jugador "<< 1 << ": " << (jugadores.elemento(p)).nombre << " numero: " << (jugadores.elemento(p)).numero <<std::endl;
   
    for (int i=2;i<argc;i++)
    {
        jugadores.insertar(jugador(argv[i],1),p);
        std::cout << "jugador "<< i << ": " << (jugadores.elemento(p)).nombre << " numero: " << (jugadores.elemento(p)).numero <<std::endl;
        p=jugadores.siguiente(p);
    }
    std::cout << "Comienza el jugador " << jugadores.elemento(p).nombre << std::endl;
    std::cout << "El ganador es: " << juego_aleatorio(jugadores,p) << std::endl;

    return 0;
}