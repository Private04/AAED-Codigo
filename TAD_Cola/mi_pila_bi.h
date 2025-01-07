#ifndef MI_PILA_BI_H
#define MI_PILA_BI_H
#include "bicola.h"
template <typename T>
class pila_bi 
{
    public:
         //Funciones constructoras
        pila_bi ();    //Constructor por defecto, crea una pila vacia.
        //Funciones observadoras
        bool vacia() const; //Devuelve true si la pila esta vacia y false si hay al menos un elemento
        T tope() const;   //Devuelve el tope de la pila. 
                    //Precondicion: La pila no esta vacia.
        size_t tama() const;    //Devuelve el numero de elementos contenido en la pila

        //Funciones modificadoras
        void push(const T& valor);    //Almacena el dato en la pila, convirtiendose en el tope.
                                    //Precondicion: T debe ser asignable
        void pop(); //Remueve el dato de la pila, haciendo que el introducido previamente sea el tope, si lo hay.
                    //Precondicion: La pila no esta vacia (tama>0)
        
    private:
        Bicola<T> bi;
};

template <typename T>
pila_bi<T>::pila_bi() : bi()
{}

template <typename T>
bool pila_bi<T>::vacia() const
{
    return bi.vacia();
}

template <typename T>
T pila_bi<T>::tope() const
{
    return bi.frente();
}

template <typename T>
size_t pila_bi<T>::tama() const
{
    return bi.tama();
}

template <typename T>
void pila_bi<T>::push(const T& valor)
{
    bi.push_frente();
}

template <typename T>
void pila_bi<T>::pop()
{
    bi.pop_frente();
}
#endif