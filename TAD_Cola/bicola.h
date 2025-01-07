//Una bicola es una secuencia de elementos del mismo tipo. Las operaciones de una bicola se hacen por los elementos extremos, es decir,
//el primer elemento o frente, y el último elemento o final
//En cada extremo se puede insertar (push), observar o extraer (pop) dicho elemento.
//Operaciones
#ifndef BICOLA_H
#define BICOLA_H
#include <cstddef>
#include <cassert>
#include <utility>
template <typename T>
class Bicola{
    public:
        //Funciones constructoras
        Bicola();//Crea una bicola vacía, es decir, de 0 elementos
        Bicola(const Bicola& b);//Constructor por copia: Crea una bicola con una copia de los elementos de la Bicola entrada
        //Funciones observadoras
        size_t tama() const;//Devuelve el número de elementos de la bicola
        const T& frente() const;//Precondición: el tamaño de la bicola es mayor que 0. Devuelve el valor del primer elemento
        const T& fin() const;//Precondición: el tamaño de la bicola es mayor que 0. Devuelve el valor del último elemento
        //Funciones modificadoras
        void push_frente(const T& elem);//Introduce en la bicola el elemento, convirtiéndose en el nuevo frente
        void push_final(const T& elem);//Introduce en la bicola el elemento, convirtiéndose en el nuevo final
        void pop_frente();//Precondición: el tamaño de la bicola es mayor que 0. Elimina el elemento frente de la bicola. El elemento siguiente, si hay, es el nuevo frente
        void pop_final();//Precondición: el tamaño de la bicola es mayor que 0. Elimina el elemento final de la bicola. El elemento anterior, si hay, es el nuevo final
        Bicola& operator =(const Bicola& b);
        //Función destructora
        ~Bicola();//Libera la memoria ocupada por la bicola inicialmente
    private:
        struct nodo{
            T valor;
            nodo *siguiente;
            nodo *anterior;
            nodo(nodo *a=nullptr,const T& v=T(),nodo *b=nullptr) : siguiente(b),valor(v),anterior(a) {};
        };
        nodo *inicio;
        nodo *final;
        size_t n_elementos;
};
template <typename T>
Bicola<T>::Bicola() :
inicio(nullptr),
final(nullptr),
n_elementos(0)
{}

template <typename T>
Bicola<T>::Bicola(const Bicola& B)
{
    inicio=final=nullptr;
    n_elementos=0;
    if (B.final)
    {
        nodo *aux=B.final;
        push_frente(aux->valor);
        aux=aux->anterior;
    }
}
template <typename T>
size_t Bicola<T>::tama() const
{
    return n_elementos;
}
template <typename T>
const T& Bicola<T>::fin() const
{
    return final->valor;
}
template <typename T>
const T& Bicola<T>::frente() const
{
    return inicio->valor;
}
template <typename T>
void Bicola<T>::push_frente(const T& elem)
{
    if(inicio)
        inicio=inicio->anterior=new nodo(elem,inicio);
    else
        final=inicio=new nodo(elem);
    n_elementos++;
}
template <typename T>
void Bicola<T>::pop_frente()
{
    assert(n_elementos);
    nodo *aux=inicio;
    inicio=inicio->siguiente;
    if (inicio)//Si no es el último
        inicio->anterior=nullptr;
    else
        final=nullptr;
    delete aux;
    n_elementos--;
}
template <typename T>
void Bicola<T>::push_final(const T& elem)
{
    if(final)
        final=final->siguiente=new nodo(final,elem);
    else
        final=inicio=new nodo(nullptr,elem);
    n_elementos++;
}
template <typename T>
void Bicola<T>::pop_final()
{
    assert(n_elementos);
    nodo *aux=final;
    final=final->anterior;
    if (final)
        final->siguiente=nullptr;
    else
        inicio=nullptr;
    delete aux;
    n_elementos--;
}
template <typename T>
Bicola<T>& Bicola<T>::operator=(const Bicola<T>& B)
{
    Bicola aux(B);
    std::swap(inicio,aux.inicio);
    std::swap(final,aux.final);
    std::swap(n_elementos,aux.n_elementos);
    return *this;
}
template <typename T>
Bicola<T>::~Bicola()
{
    while (inicio)
    {
        pop_frente();
    }
} 
#endif