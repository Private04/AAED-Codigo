#include <cstddef>
#include "cola_ce.h"
#include "..\TAD_Pila\pila_ce.h"
#include "oper_cola.h"
inline size_t numero_par(size_t tama)
{
    return tama/2;
}
inline size_t numero_impar(size_t tama)
{
    return (tama+1)/2;
}
bool pila_isomorfica(Pila<char> p,Cola_ce<char> c)
{
    bool resultado=false;
    if(numero_par(p.tama())==numero_impar(c.tama()))
    {
        p.pop();
        while (!p.vacia() && !c.vacia() && p.tope()==c.frente())
        {
            p.pop();
            p.pop();
            c.pop();
            c.pop();
        }
        if (p.vacia() || c.vacia())
            resultado=true;
    }
    return resultado;
}
void invertir_cola_ab(Cola_ce<char> &c,char a,char b)
{
    Pila<char> aux;
    size_t cont=0;
    for (cont;cont<=c.tama()&&c.frente()!=a;cont++)//Buscar el elemento de a
    {
        c.push(c.frente());
        c.pop();
    }
    if(!c.vacia())
    {
        aux.push(c.frente());
        c.pop();
        cont++;
        for(cont;cont<=c.tama()&&aux.tope()!=b;cont++)
        {
            aux.push(c.frente());
            c.pop();
        }
        while (!aux.vacia())
        {
            c.push(aux.tope());
            aux.pop();
        }
        for (cont;cont<=c.tama();cont++)
        {
            c.push(c.frente());
            c.pop();
        }
    }
}