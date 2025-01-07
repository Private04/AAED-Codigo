#include <iostream>
#include "bicola.h"
int main(int argc,char **argv)
{
    Bicola<char> a;
    int tamanio;
    if (argc < 2)
    {
        std::cout << "Uso: " << argv[0] << " <cadena> <elemento a> <elemento b>" << std::endl;
        return 1;
    }
    for (int i=0;argv[1][i]!='\0';i++)
    {
        a.push_final(argv[1][i]);
    }
    tamanio=a.tama();
    std::cout << std::endl;
    for (int i=1;i<=tamanio;i+=2)
    {
        std::cout << a.frente() << a.fin();
        a.pop_frente();
        a.pop_final();
    }
    return 0;
}