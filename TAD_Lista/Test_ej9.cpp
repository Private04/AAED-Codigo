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
    jugador aux();
    listaCir<jugador> jugadores;
    listaCir<jugador>::posicion p;

    jugadores.insertar(jugador(argv[1],rand_rango(1,6)),jugadores.inipos());
    p=jugadores.inipos();
    std::cout << "jugador 1: " << (jugadores.elemento(p)).nombre << " numero: " << (jugadores.elemento(p)).numero <<std::endl;
    for (int i=2;i<argc;i++)
    {
        jugadores.insertar(jugador(argv[i],rand_rango(1,6)),p);
        p=jugadores.siguiente(p);
        std::cout << "jugador 1: " << (jugadores.elemento(p)).nombre << " numero: " << (jugadores.elemento(p)).numero <<std::endl;
    }

    std::cout << "El ganador es: " << juego_aleatorio(jugadores,p) << std::endl;

    return 0;
}