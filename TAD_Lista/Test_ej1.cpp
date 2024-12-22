#include <iostream>
#include <cstddef>
#include "lista_c2e.h"
#include "oper_lista.h"
#include "e_s_lista.h"

int main()
{
    char cadena_prueba[20]="Hola a todos\0";
    
    Lista<char> lista_prueba;
    insertar_vector_en_lista(cadena_prueba,lista_prueba,20);
    eliminar_ocurr(lista_prueba,'o');
    imprimir_lista(lista_prueba);
}