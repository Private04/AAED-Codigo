#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include "pila_ce.h"
#include "oper_pila.h"
#include "e_s_pila.h"
int main()
{
    tCarta Mazo[40];
    eFigura montones[4];
    size_t indice=0;
    for (ePalo i=OROS;i<=BASTOS;i=ePalo(i+1))
    {
        for (eFigura j=AS;j<=REY;j=eFigura(j+1))
        {
            Mazo[indice]=tCarta(j,i);
            indice++;
        }
    }
    srand(time(nullptr));
    std::random_shuffle(Mazo,Mazo+40);
    bool resultado=solitario(Mazo,montones);
    std::cout << std::endl << resultado << std::endl;
    for (ePalo i=OROS;i<=BASTOS;i=ePalo(i+1))
    {
        std::cout << std::endl << montones[i]; 
    }
    return 0;
}