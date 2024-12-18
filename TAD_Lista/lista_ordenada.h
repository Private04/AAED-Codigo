#ifndef LISTA_ORDENADA_H
#define LISTA_ORDENADA_H
#include "lista_c2e.h"
template <typename T>
class lista_ordenada{
    public:
        lista();
        typedef lista<T>::posicion posicion;
        size_t tama() const;
        bool vacia() const;
        posicion inicio() const;
        posicion fin() const;
        posicion anterior(posicion p) const;
        posicion siguiente(posicion p) const;
        void insertar(const T& elem,posicion p);
        void eliminar(posicion p);
    private:
        Lista<T> lista;
};
#endif