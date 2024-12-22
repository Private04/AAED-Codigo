#include <iostream>
#include <cstddef>
#include "lista_c2e.h"
#include "oper_lista.h"
#include "e_s_lista.h"

int main()
{
    int cadena_prueba[25]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    
    Lista<int> lista_prueba;
    Lista<int>::posicion p=lista_prueba.primera();
    
    insertar_vector_en_lista(cadena_prueba,lista_prueba,25);
    for (int i=1;i<=10;i++)
        p=lista_prueba.siguiente(p);
    imprimir_lista(lista_prueba);
    invertir_lista(lista_prueba,p);
    imprimir_lista(lista_prueba);
}