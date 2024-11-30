#include <iostream>
#include <string>
#include "pila_ce.h"
#include "e_s_pila.h"
using namespace std;
void pila_leer(Pila<char> p)
{
    while (!p.vacia())
    {
        cout << p.tope();
        p.pop();
    }
    cout << endl;
}
void pila_escribir(Pila<char>& p)
{
    string cadena_pila;
    size_t indice;
    cout << "Escribe la cadena a situar en la pila" << endl;
    cin >> cadena_pila;
    
    for (indice=cadena_pila.length()-1;int(indice)>=0;indice--) 
    {p.push(cadena_pila[indice]);}
}