#ifndef E_S_LISTA
#define E_S_LISTA
#include <iostream>
template <typename T>
void insertar_vector_en_lista(const T *str,Lista<T>& list,size_t tama)
{
    for(size_t i=0;i<tama;i++)
    {
        list.insertar(str[i],list.fin());
    }
}
template <typename T>
void imprimir_lista(const Lista<T>& l)
{ 
    typename Lista<T>::posicion p=l.primera();
    while (p!=l.fin())
    {
        std::cout << T(l.elemento(p));
        p=l.siguiente(p);
    }
    std::cout << std::endl;
}
#endif