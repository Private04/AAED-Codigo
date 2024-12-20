#include "lista_ps.h"
#include "oper_lista.h"
void eliminar_ocurr(Lista<char>& l,char c)
{
    Lista<char>::posicion pos=l.primera();//posicion para comprobar
    while (pos!=l.fin())
    {
        if (l.elemento(pos)==c)
        {
            l.eliminar(pos);
        }
        pos=l.siguiente(pos);
    }
}
Lista<int>& concatena_orden(Lista<int> a,Lista<int> b)
{
    Lista<int>::posicion pos_a=a.primera(),pos_b=b.primera();
    Lista<int> resultado;
    while(pos_a!=a.fin()&&pos_b!=b.fin())
    {
        if (a.elemento(pos_a)<=b.elemento(pos_b))
        {
            resultado.insertar(a.elemento(pos_a),resultado.fin());
            pos_a=a.siguiente(pos_a);
        }
        else
        {
            resultado.insertar(a.elemento(pos_b),resultado.fin());
            pos_b=a.siguiente(pos_b);
        }
    }
    while (pos_a!=a.fin())
    {
        resultado.insertar(a.elemento(pos_a),resultado.fin());
        pos_a=a.siguiente(pos_a);
    }
    while (pos_b!=b.fin())
    {
        resultado.insertar(b.elemento(pos_b),resultado.fin());
        pos_b=b.siguiente(pos_b);
    }
}
void invertir_lista(Lista<int> l,Lista<int>::posicion p)
{
    
}