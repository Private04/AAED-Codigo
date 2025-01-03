#include <iostream>
#include <string>
#include "num_binario.h"
int main(int argc,char **argv)
{
    if (argc < 3)
    {
        std::cout << argv[0] << "<conjunto 1> <conjunto 2>" << std::endl;
        return 1;
    }
    binario a(argv[1]),b(argv[2]);
    std::cout << "NOT a: " << (~a).verNumero() << std::endl;
    std::cout << "a AND b" << (a&b).verNumero() << std::endl;
    std::cout << "a OR b" << (a|b).verNumero() << std::endl;
    std::cout << "a XOR b" << (a^b).verNumero() << std::endl;
    std::cout << "a << 4" << (a<<4).verNumero() << std::endl;
    std::cout << "b >> 4" << (b>>4).verNumero() << std::endl;
}