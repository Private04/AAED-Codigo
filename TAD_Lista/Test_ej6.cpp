#include <iostream>
#include "lista_c2e.h"
#include "conjunto.h"
#include "e_s_lista.h"
int main(int argc,char* argv[])
{
    Conjunto<char> c1,c2,res;
    if (argc < 3)
    {
        std::cout << argv[0] << " <conjunto 1> <conjunto 2>" << std::endl;
        return 1;
    }
    for (int i=0;argv[1][i]!='\0';i++)
    {
        c1.insertar(argv[1][i]);
    }
    for (int i=0;argv[2][i]!='\0';i++)
    {
        c2.insertar(argv[2][i]);
    }
    res=c1&c2;
    std::cout << "Interseccion: ";
    imprimir_lista<char>(res.lista_elementos());
    res=c1-c2;
    std::cout << "Diferencia: ";
    imprimir_lista<char>(res.lista_elementos());
    res=c1|c2;
    std::cout << "Union: ";
    imprimir_lista<char>(res.lista_elementos());
    return 0;
}