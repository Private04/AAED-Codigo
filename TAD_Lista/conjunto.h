#ifndef CONJUNTO_H
#define CONJUNTO_H
#include "lista_c2e.h"
#include "lista_ordenada.h"

/*
Un Conjunto es una agrupación de varios elementos del mismo tipo pero con distinto valor.
Los conjuntos pueden insertar o eliminar elementos de el, al igual que hacer operaciones de 
union interseccion y diferencia.

Un Conjunto puede ser de aquellos tipos que tengan operaciones de asignación y de comparación (=,<,>,== y !=).
OPERACIONES
    Conjunto() Crea un Conjunto vacio
    size_t cardinal() const devuelve el numero de elementos (cardinal del Conjunto)
    bool vacio() const devuelve si es un Conjunto vacio
    bool esta_en_conjunto(const T& elem) const PRECONDICION: El conjunto no esta vacio. Devuelve si el elemento esta en el Conjunto
    const Lista<T>& elementos() const devuelve una lista de los elementos de la cola
    void insertar(const T& elem) PRECONDICION: El elemento no esta en el Conjunto. Inserta el elemento en el Conjunto
    void eliminar(const T& elem) PRECONDICION: El elemento esta en el Conjunto. Elimina el elemento del Conjunto.
    Conjunto& operator &(const Conjunto& b) Devuelve la interseccion de ambos conjuntos, es decir, un Conjunto que contenga los elementos comunes en ambos conjuntos
    Conjunto& operator |(const Conjunto& b) Devuelve la union de ambos conjuntos, es decir, un Conjunto que contiene elementos comunes y no comunes de ambos conjuntos
    Conjunto& operator -(const Conjunto& b) Devuelve la diferencia del primero sobre el segundo Conjunto, es decir, un Conjunto con los elementos de a que no estan contenidos en b
*/
template <typename T>
class Conjunto{
    public:
        Conjunto();
        size_t cardinal() const;
        bool vacio() const;
        bool esta_en_conjunto(const T& elem) const;
        const Lista<T>& lista_elementos() const;
        void insertar(const T& elem);
        void eliminar(const T& elem);
        friend Conjunto<T>& operator &(const Conjunto<T>& a,const Conjunto<T>& b);
        friend Conjunto<T>& operator |(const Conjunto<T>& a,const Conjunto<T>& b);
        friend Conjunto<T>& operator -(const Conjunto<T>& a,const Conjunto<T>& b);
    private:
        lista_ordenada<T> elementos;
};

template <typename T>
Conjunto<T>::Conjunto() : elementos()
{}
template <typename T>
size_t Conjunto<T>::cardinal() const
{
    return elementos.tama();
}
template <typename T>
bool Conjunto<T>::vacio() const
{
    return elementos.vacia()
}
template <typename T>
bool Conjunto<T>::esta_en_conjunto(const T& elem) const
{
    return elementos.esta_en_lista(elem);
}
template <typename T>
const Lista<T>& Conjunto<T>::lista_elementos() const
{
    return elementos.elementos();
}
template <typename T>
void Conjunto<T>::insertar(const T& elem)
{
    elementos.insertar(elem);//No hago assert porque esta_en_conjunto es de orden (n)
}
template <typename T>
void Conjunto<T>::eliminar(const T& elem)
{
    elementos.eliminar(elem);//No hago assert porque esta_en_conjunto es de orden (n)
}
template <typename T>
Conjunto<T>& operator &(const Conjunto<T>& a,const Conjunto<T>& b)
{
    Conjunto<T> res(b);
    if (!b.vacio())
    {
        T aux(b.elementos.inicio());
        while (aux!=b.final())
        {
            if (!a.esta_en_conjunto(aux))
            {
                res.eliminar(aux);
            }
            aux=b.elementos.siguiente(aux);
        }
        if (!a.esta_en_conjunto(aux))
            {
                res.eliminar(aux);
            }
    }
    return res;
}
template <typename T>
Conjunto<T>& operator |(const Conjunto<T>& a,const Conjunto<T>& b)
{
    Conjunto<T> res(b);
    if (!a.vacio) {
        T aux(a.elementos.inicio());
        while (aux!=a.final())
        {
            if (!b.esta_en_conjunto(aux))
            {
                res.insertar(aux);
            }
            aux=a.elementos.siguiente(aux);
        }
        if (!b.esta_en_conjunto(aux))
            {
                res.insertar(aux);
            }
    }
    return res;
}
template <typename T>
Conjunto<T>& operator -(const Conjunto<T>& a,const Conjunto<T>& b)
{
    Conjunto<T> res(a);
    if (!a.vacio)
    {
        T aux(a.elementos.inicio());
        while (aux!=a.final())
        {
            if (b.esta_en_conjunto(aux))
            {
                res.eliminar(aux);
            }
            aux=a.elementos.siguiente(aux);
        }
        if (b.esta_en_conjunto(aux))
            {
                res.eliminar(aux);
            }
    }
    return res;
}
#endif