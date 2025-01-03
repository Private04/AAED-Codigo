#ifndef JUEGO_ALEATORIO_H
#define JUEGO_ALEATORIO_H
//Ejercicio 9
struct jugador{
    std::string nombre;
    int numero;
    jugador(std::string str,int num) : nombre(str),numero(num) {}
};
//Precondicion: numero de cada jugador debe ser entre 1 y 6 inclusivos Y jugadores.tama()>=1
std::string juego_aleatorio(const Lista<jugador>& jugadores,Lista<jugador>::posicion j_inicial);
#endif