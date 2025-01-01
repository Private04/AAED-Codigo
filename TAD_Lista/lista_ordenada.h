#ifndef LISTA_ORDENADA_H
#define LISTA_ORDENADA_H
#include "lista_c2e.h"
#include <cassert>
//Se define como lista ordenada a una secuencia de elementos del mismo tipo en orden ascendente.
//Cada elemento tiene un elemento que le procede, menos el primer elemento y un elemento que le sigue, menos el último elemento
template <typename T>
class lista_ordenada{
    public:
        lista_ordenada();
        size_t tama() const;
        const Lista<T>& elementos() const;
        bool vacia() const;
        bool esta_en_lista(const T& elem) const; //Precondición: La lista no esta vacía
        const T& inicio() const; //Precondicion: la lista no esta vacia
        const T& ultimo() const; //Preconcicion: La lista no esta vacia
        const T& anterior(const T& elem) const; //Precondcion: El elemento está en la lista y NO es el primero. Devuelve el elemento que precede a la primera ocurrencia del elemento elem.
        const T& siguiente(const T& elem) const; //Precondcion: El elemento está en la lista y NO es el último. Devuelve el elemento que sigue a la última ocurrencia de elem.
        void insertar(const T& elem); //Inserta elem en la lista en la posicion anterior al primer elemento de la lista mayor que elem. Si la lista está vacía, se sitúa en la primera y última posición.
        void eliminar(const T& elem); //Precondicion: La lista no esta vacia. Elimina la primera ocurrencia del elemento en la lista
    private:
        Lista<T> lista;
};
template <typename T>
lista_ordenada<T>::lista_ordenada() : lista()
{}
template <typename T>
size_t lista_ordenada<T>::tama() const
{
    return lista.tama();
}
template <typename T>
bool lista_ordenada<T>::vacia() const
{
    return lista.vacia();
}
template <typename T>
const T& lista_ordenada<T>::inicio() const
{
    assert(!vacia());
    return lista.elemento(lista.primera());
}
template <typename T>
const T& lista_ordenada<T>::ultimo() const
{
    assert(!vacia());
    return lista.elemento(lista.anterior(lista.fin()));
}
template <typename T>
const T& lista_ordenada<T>::anterior(const T& elem) const
{
    assert(elem!=lista.elemento(lista.primera()));
    typename Lista<T>::posicion p=lista.primera();
    while (p!=lista.anterior(lista.fin())&&lista.elemento(lista.siguiente(p))==elem)
    {
        p=lista.siguiente(p);
    }
    return lista.elemento(p);
}
template <typename T>
const T& lista_ordenada<T>::siguiente(const T& elem) const
{
    assert(elem!=lista.elemento(lista.anterior(lista.fin())));
    typename Lista<T>::posicion p=lista.primera();
    while ((lista.elemento(p)!=elem||elem==lista.elemento(lista.siguiente(p)))&&p!=lista.anterior(lista.fin()))//Recorrer la lista hasta hallar la ultima posicion de elem
    {
        p=lista.siguiente(p);
    }

    return lista.elemento(lista.siguiente(p));
}
template <typename T>
void lista_ordenada<T>::insertar(const T& elem)
{
    typename Lista<T>::posicion p=lista.primera();
    if (!lista.vacia())
    {
        while (p!=lista.fin()&&lista.elemento(p)<elem)
        {
            p=lista.siguiente(p);
        }
        lista.insertar(elem,p);
    }
    else
        lista.insertar(elem,lista.fin());
}
template <typename T>
void lista_ordenada<T>::eliminar(const T& elem)
{
    assert (!vacia());
    typename Lista<T>::posicion p=lista.primera();
    while (p!=lista.fin()&&lista.elemento(p)!=elem)
    {
        p=lista.siguiente(p);
    }
    if (p!=lista.fin())
    {
        lista.eliminar(p);
    }
}
template <typename T>
bool lista_ordenada<T>::esta_en_lista(const T& elem) const
{
    assert(!vacia());
    typename Lista<T>::posicion p=lista.primera();
    while (lista.siguiente(p)!=lista.fin()&&elem>lista.elemento(p))
    {
        p=lista.siguiente(p);
    }
    return (elem==lista.elemento(p));
}
template <typename T>
const Lista<T>& lista_ordenada<T>::elementos() const
{
    return lista;
}
#endif