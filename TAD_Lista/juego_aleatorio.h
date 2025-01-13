#ifndef JUEGO_ALEATORIO_H
#define JUEGO_ALEATORIO_H
#include "lista_circular.h"
//Ejercicio 9
struct jugador{
    char * nombre;
    int numero;
    jugador(char * str,int num) : numero(num) {
        
        int i=0;
        while (str[i]!='\0') i++;
        nombre=new char[i];
        memcpy(nombre,str,i*sizeof(int));
    }
    ~jugador()
    {
        delete nombre;
        numero=0;
    }
};
//Precondicion: numero de cada jugador debe ser entre 1 y 6 inclusivos, jugadores.tama()>=1 y j_inicial==jugadores.elemento(p), siendo p una posicion dentro de jugadores
char *juego_aleatorio(const listaCir<jugador>& jugadores,char * j_inicial);
#endif