#include <iostream>
#include <cstddef>
#include "lista_c2e.h"
#include "oper_lista.h"
#include "e_s_lista.h"

int main()
{
    char cadena_prueba[30]="abcd\0efgh\0ijkl\0mno\0pqrs\0tuvw\0";
    
    Lista<Lista<char>> lista_prueba;
    Lista<char> aux;
    for (int i=0;i<30;i+=5)
    {
        insertar_vector_en_lista(cadena_prueba+i,aux,5);
        lista_prueba.insertar(aux,lista_prueba.fin());
        aux=Lista<char>();
    }
    aux=concatena_lista(lista_prueba);
    imprimir_lista(aux);
}