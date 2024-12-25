#include "lista_c2e.h"
#include "lista_ordenada.h"
#include <iostream>
#include <cstddef>
void insertar_vector_en_lorden(lista_ordenada<int>& l,int *vec,size_t n);
void imprimir_lorden(const lista_ordenada<int>& l);
lista_ordenada<int>& concatena_lista(const lista_ordenada<int>& a,const lista_ordenada<int>& b);
int main(){
    lista_ordenada<int> lista_a;
    lista_ordenada<int> lista_b;
    lista_ordenada<int> lista_resultado;
    int vector_a[10]={2,4,6,8,0,1,3,5,7,9};
    int vector_b[10]={1,33,11,21,41,6,8,19,321,4};
    insertar_vector_en_lorden(lista_a,vector_a,10);
    insertar_vector_en_lorden(lista_b,vector_b,10);
    imprimir_lorden(lista_a);
    imprimir_lorden(lista_b);
    lista_resultado=concatena_lista(lista_a,lista_b);
    imprimir_lorden(lista_resultado);
}
void insertar_vector_en_lorden(lista_ordenada<int>& l,int *vec,size_t n)
{
    for (int i=0;i<n;i++)
    {
        l.insertar(vec[i]);
    }
}
void imprimir_lorden(const lista_ordenada<int>& l)
{
    int elem=l.inicio();
    std::cout << std::endl;
    while (elem!=l.ultimo())
    {
        std::cout << elem << ' ';
        elem=l.siguiente(elem);
    }
    std::cout << elem << ' ';
    std::cout << std::endl;
}
lista_ordenada<int>& concatena_lista(const lista_ordenada<int>& a,const lista_ordenada<int>& b)
{
    static lista_ordenada<int> res;
    int elem=a.inicio();
    while (elem!=a.ultimo())
    {
        res.insertar(elem);
        elem=a.siguiente(elem);
    }
    res.insertar(a.ultimo());
    elem=b.inicio();
    while (elem!=b.ultimo())
    {
        res.insertar(elem);
        elem=b.siguiente(elem);
    }
    res.insertar(b.ultimo());
    return res;
}