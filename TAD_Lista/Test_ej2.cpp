#include <iostream>
#include <cstddef>
#include "lista_c2e.h"
#include "oper_lista.h"
#include "e_s_lista.h"

int main()
{
    int vector_prueba1[20]={1,3,5,7,9,11,13,17,19,23,29,31,32,33,34,35,36,37,38,39};
    int vector_prueba2[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    Lista<int> lista_prueba1;
    Lista<int> lista_prueba2;
    Lista<int> lista_res;
    insertar_vector_en_lista<int>(vector_prueba1,lista_prueba1,20);
    insertar_vector_en_lista<int>(vector_prueba2,lista_prueba2,15);
    lista_res=concatena_orden(lista_prueba1,lista_prueba2);
    imprimir_lista(lista_res);
}