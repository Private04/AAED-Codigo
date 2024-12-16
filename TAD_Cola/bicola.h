//Una bicola es una secuencia de elementos del mismo tipo. Las operaciones de una bicola se hacen por los elementos extremos, es decir,
//el primer elemento o frente, y el último elemento o final
//En cada extremo se puede insertar (push), observar o extraer (pop) dicho elemento.
//Operaciones
#ifndef BICOLA_H
#define BICOLA_H
#include <cstddef>
template <typename T>
class Bicola{
    public:
        //Funciones constructoras
        Bicola();//Crea una bicola vacía, es decir, de 0 elementos
        Bicola(const Bicola& b);//Constructor por copia: Crea una bicola con una copia de los elementos de la Bicola entrada
        //Funciones observadoras
        size_t tama() const;//Devuelve el número de elementos de la bicola
        const T& frente() const;//Precondición: el tamaño de la bicola es mayor que 0. Devuelve el valor del primer elemento
        const T& final() const;//Precondición: el tamaño de la bicola es mayor que 0. Devuelve el valor del último elemento
        //Funciones modificadoras
        void push_frente(const T& elem);//Introduce en la bicola el elemento, convirtiéndose en el nuevo frente
        void push_final(const T& elem);//Introduce en la bicola el elemento, convirtiéndose en el nuevo final
        void pop_frente();//Precondición: el tamaño de la bicola es mayor que 0. Elimina el elemento frente de la bicola. El elemento siguiente, si hay, es el nuevo frente
        void pop_final();//Precondición: el tamaño de la bicola es mayor que 0. Elimina el elemento final de la bicola. El elemento anterior, si hay, es el nuevo final
        Bicola operator =(const Bicola& b);
        //Función destructora
        ~Bicola();//Libera la memoria ocupada por la bicola inicialmente
    private:
        struct nodo{
            T valor;
            nodo *siguiente;
        };
        nodo *inicio;
        nodo *final;
        size_t n_elementos;
};
#endif