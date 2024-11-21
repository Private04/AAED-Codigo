#ifndef PILA_PS_H
#define PILA_PS_H
#include <cassert>
#include <cstddef>
template <typename T> 
class pila_ps //Definicion de pila pseudoestatica
{
    public:
        //Funciones constructoras
        pila_ps (size_t tama_max);    //Constructor por defecto, crea una pila vacia que puede almacenar hasta el valor de tama_max.
    
        pila_ps (const pila_ps& p); //Constructor de copia.
                                    //Precondicion: Las pilas tienen que ser del mismo tipo
        //Funciones observadoras
        bool vacia() const; //Devuelve true si la pila esta vacia y false si hay al menos un elemento
        T tope() const;   //Devuelve el tope de la pila. 
                    //Precondicion: La pila no esta vacia.
        size_t tama() const;    //Devuelve el numero de elementos contenido en la pila
        size_t tamamax() const; //Devuelve el numero maximo de elementos que puede contener la pila

        //Funciones modificadoras
        void push(const T dato);    //Almacena el dato en la pila, convirtiendose en el tope.
                                    //Precondicion: tama()<tamamax() y T debe ser asignable
        void pop(); //Remueve el dato de la pila, haciendo que el introducido previamente sea el tope, si lo hay.
                    //Precondicion: La pila no esta vacia (tama>0)
        pila_ps& operator =(const pila_ps& p);    //Asignacion de copia. Tienen que ser del mismo tipo
        //Funcion destructora
        ~pila_ps();
    private:
       T *elementos; //Vector que contendra los elementos de la pila
       size_t n_elementos; //Numero de elementos en la pila. n_elementos - 1 es el indice del tope
       size_t t_max; //Numero de elementos maximos que la pila puede almacenar
};

//
//      IMPLEMENTACION DE LAS FUNCIONES DE LA PILA
//

template <typename T>
pila_ps<T>::pila_ps(size_t tama_max) : 
    elementos(new T[tama_max]),
    n_elementos=0,
    t_max=tama_max
{}
template <typename T>
pila_ps<T>::pila_ps(const pila_ps& p) : pila_ps(p.t_max)
{
    if (!p.vacia)
    {
        for (int i=0;i<p.n_elementos;i++)
        {
            elementos[i]=p.elementos[i];
        }
        n_elementos=p.n_elementos;
    }
}
template <typename T>
bool pila_ps<T>::vacia() const
{
    return n_elementos==0;
}
template <typename T>
T pila_ps<T>::tope() const
{
    assert(n_elementos!=0);
    return elementos[n_elementos-1];
}
template <typename T>
size_t pila_ps<T>::tama() const
{
    return n_elementos;
}
template <typename T>
size_t pila_ps<T>::tamamax() const
{
    return t_max;
}
template <typename T>
void pila_ps<T>::push(T dato)
{
    elementos[n_elementos]=dato;
    n_elementos++;
}
template <typename T>
void pila_ps<T>::pop()
{
    assert(!vacia())
    n_elementos--;
}
template <typename T>
pila_ps<T>& pila_ps<T>::operator =(const pila_ps& p)
{
    if (this!=&p)//Evitar autoasignacion
    {
        T *aux=elementos;
        elementos=new T[p.t_max];
        t_max=p.t_max;
        n_elementos=p.n_elementos;
        for (size_t i=0;i<n_elementos;i++)
        {
            elementos[i]=p.elementos[i];
        }
        delete aux;3
    }
}
#endif