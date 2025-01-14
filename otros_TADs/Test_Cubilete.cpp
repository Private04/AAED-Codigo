#include <algorithm>
#include <iostream>
#include "TAD_Cubilete.h"

int main()
{
    const int N_CUBOS=10;
    Pila<tCubo> base(N_CUBOS);

    for (int i=1;i<=N_CUBOS;i++)
    {
        base.push(tCubo(rand()%100,tCubo::eEstado::BOCA_ARRIBA));
        std::cout << base.tope().tama << " ";
    }
    std::cout << std::endl;
    
    Pila<tCubo> res=apilacion(base);
    while (!res.vacia())
    {
        std::cout << res.tope().tama << " ";
        res.pop();
    }
    
    return 0;
}