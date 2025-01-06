#include <iostream>
#include "lista_circular.h"
int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << argv[0] << " <lista_circular>" << std::endl;
        return 1;
    }
    listaCir<char> lista;
    listaCir<char>::posicion p;
    lista.insertar(argv[1][0],lista.inipos());
    p=lista.inipos();
    for (int i=1;argv[1][i]!='\0';i++)
    {
        lista.insertar(argv[1][i],p);
        p=lista.siguiente(p);
    }
    p=lista.inipos();
    for (int i=1;i<=2*lista.tama();i++)
    {
        std::cout << lista.elemento(p);
        p=lista.siguiente(p);
    }
    std::cout << std::endl;
    lista.eliminar(lista.siguiente(p));
    p=lista.inipos();
    for (int i=1;i<=3*lista.tama();i++)
    {
        std::cout << lista.elemento(p);
        p=lista.siguiente(p);
    }
    return 0;
}