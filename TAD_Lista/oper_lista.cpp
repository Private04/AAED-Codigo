#include "lista_c2e.h"
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
    static Lista<int> resultado;
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
    return resultado;
}
void invertir_lista(Lista<int>& l,Lista<int>::posicion p)
{
    Lista<int>::posicion pos_a_insertar=l.fin();//Posicion de donde vamos a empezar a insertar
    Lista<int>::posicion aux;
    while (l.siguiente(p)!=pos_a_insertar)
    {
        l.insertar(l.elemento(p),pos_a_insertar);
        
        l.eliminar(p);
    }
}
Lista<char>& concatena_lista(const Lista<Lista<char>>& l)
{
    static Lista<char> resultado;
    Lista<Lista<char>>::posicion pos_ext=l.primera();
    Lista<char>::posicion pos_int;
    while(pos_ext!=l.fin())
    {
        pos_int=l.elemento(pos_ext).primera();
        while(pos_int!=l.elemento(pos_ext).fin())
        {
            resultado.insertar(l.elemento(pos_ext).elemento(pos_int),resultado.fin());
            pos_int=l.elemento(pos_ext).siguiente(pos_int);
        }
        pos_ext=l.siguiente(pos_ext);
    }
    return resultado;
}