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