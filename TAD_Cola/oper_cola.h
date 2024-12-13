#ifndef OPER_COLA_H
#define OPER_COLA_H
bool pila_isomorfica(Pila<char> p,Cola_ce<char> c);//Ejercicio 1 
void invertir_cola_ab(Cola_ce<char> &c,char a,char b);//Ejercicio 2 //Idea: Con una pila auxiliar, insertar el tope hasta encontrar a, guardar en una pila hasta encontrar b y luego guardar en la cola
#endif