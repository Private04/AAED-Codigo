#include <iostream>
#include "lista_ps.h"
#include "oper_lista.h"

void insertar_cad_en_lista(const char *str,Lista<char>& list);
void imprimir_lista(const Lista<char>& l);
int main()
{
    char cadena_prueba[20]="Hola a todos\0";
    Lista<char> lista_prueba(20);
    insertar_cad_en_lista(cadena_prueba,lista_prueba);
    eliminar_ocurr(lista_prueba,'o');
    imprimir_lista(lista_prueba);
}
void insertar_cad_en_lista(const char *str,Lista<char>& list)
{
    for(size_t i=0;str[i]!='\0';i++)
    {
        list.insertar(str[i],list.fin());
    }
}
void imprimir_lista(const Lista<char>& l)
{
    Lista<char>::posicion p=l.primera();
    while (p!=l.fin())
    {
        std::cout << l.elemento(p);
        p=l.siguiente(p);
    }
}