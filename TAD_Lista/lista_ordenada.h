#ifndef LISTA_ORDENADA_H
#define LISTA_ORDENADA_H
#include "lista_c2e.h"
#include <cassert>
template <typename T>
class lista_ordenada{
    public:
        lista_ordenada();
        size_t tama() const;
        bool vacia() const;
        bool esta_en_lista() const;
        const T& inicio() const; //Precondicion, la lista no esta vacia
        const T& ultimo() const; //Preconcicion: La lista no esta vacia
        const T& anterior(const T& elem) const; //Precondcion: La lista no esta vacia. Devuelve NULL si p no esta en la lista
        const T& siguiente(const T& elem) const; //Precondicion: La lista no esta vacia. Devuelve NULL si p no esta en la lista
        void insertar(const T& elem);
        void eliminar(const T& elem); //Precondicion: La lista no esta vacia
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
    assert(!vacia);
    return lista.elemento(lista.primera());
}
template <typename T>
const T& lista_ordenada<T>::ultimo() const
{
    assert(!vacia);
    return lista.elemento(lista.anterior(lista.fin()));
}
template <typename T>
const T& lista_ordenada<T>::anterior(const T& elem) const
{
    Lista<T>::posicion p=lista.primera();
    while (p!=lista.fin()&&lista.elemento(lista.siguiente(p))==elem)
    {
        p=lista.siguiente(p);
    }
    return p==lista.fin()? lista.elemento(p) : NULL;
}
template <typename T>
const T& lista_ordenada<T>::siguiente(const T& elem) const
{
    Lista<T>::posicion p=lista.primera();
    while (p!=lista.anterior(lista.fin())&&lista.elemento(p)==elem)
    {
        p=lista.siguiente(p);
    }
    return lista.elemento(lista.siguiente(p))==elem? lista.elemento(lista.siguiente(p)) : NULL;
}
template <typename T>
void lista_ordenada<T>::insertar(const T& elem)
{
    Lista<T>::posicion p=lista.primera();
    while (p!=lista.fin()&&lista.elemento(p)<elem)
    {
        p=lista.siguiente(p);
    }
    lista.insertar(elem,p);
}
template <typename T>
void lista_ordenada<T>::eliminar(const T& elem)
{
    assert (!vacia);
    Lista<T>::posicion p=lista.primera();
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
bool lista_ordenada<T>::esta_en_lista() const
{
    assert(!vacia)
    Lista<T>::posicion p=lista.primera();
    while (p!=lista.fin()&&elem!=lista.elemento(p))
    {
        p=lista.siguiente();
    }
    return (p!=vacia)
}
#endif