#ifndef PILA_CE_H
#define PILA_CE_H
#include <cstddef>
#include <cassert>
template <typename T>
class pila_ce //Pila de celdas enlazadas
{
    public:
         //Funciones constructoras
        pila_ce ();    //Constructor por defecto, crea una pila vacia.
    
        pila_ce (const pila_ce& p); //Constructor de copia.
                                    //Precondicion: Las pilas tienen que ser del mismo tipo
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
        pila_ce& operator =(const pila_ce& p);    //Asignacion de copia. Tienen que ser del mismo tipo
        //Funcion destructora
        ~pila_ce();
    private:
        struct nodo{
            T dato;
            nodo *nodo_siguiente;
            nodo(T elem,nodo *sig=nullptr) : dato=elem,nodo_siguiente=sig {}//Constructor de la estructura
        };
        nodo *nodo_tope;
        size_t n_elementos;
};
template <typename T>
pila_ce<T>::pila_ce() : n_elementos=0,tope=nullptr
{}
template <typename T>
bool pila_ce<T>::vacia() const
{
    return (tope==0);
}
template <typename T>
T pila_ce<T>::tope() const
{
    assert(!vacia);
    return nodo_tope->dato;
}
template <typename T>
size_t pila_ce<T>::tama() const
{
    return n_elementos;
}
template <typename T>
void pila_ce<T>::push(const T& valor)
{
    nodo *aux;
    aux=new nodo(valor,nodo_tope);
    nodo_tope=aux;
    n_elementos++
}
template <typename T>
void pila_ce<T>::pop()
{
    assert (!vacia);
    nodo *aux=nodo_tope;
    nodo_tope=nodo_tope->nodo_siguiente;
    delete aux;
    n_elementos--;
}
template <typename T>
pila_ce<T>::pila_ce(const pila_ce& p) : pila_ce()
{
    nodo *aux=p.nodo_tope;//puntero que recorre los nodos de p
    n_elementos=p.n_elementos;
    while (aux!=nullptr)//"push" por cada nodo de p
    {
        nodo_tope=new nodo(aux->dato,nodo_tope);
        aux=aux->nodo_siguiente;
    }
}
template <typename T>
pila_ce<T>& pila_ce<T>::operator =(const pila_ce& p)
{
    pila_ce aux(p);//Constructor de copia de la pila auxiliar donde se va a guardar la antigua pila para destruirla
    //Intercambio de valores entre aux y this
    nodo *n_aux=nodo_tope;
    nodo_tope=aux.nodo_tope;
    aux.nodo_tope=n_aux;
    size_t n=n_elementos;
    n_elementos=aux.n_elementos;
    aux.n_elementos=n;
    return *this; //Destruye aux
}
template <typename T>
pila_ce<T>::~pila_ce()
{
    nodo *aux;
    while (aux!=nullptr)
    {
        aux=nodo_tope->siguiente;
        delete nodo_tope;
        nodo_tope=aux;
    }
}
#endif