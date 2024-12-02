#include <string>
#include <iostream>
#include <fstream>
#include "pila_ce.h"
#include "oper_pila.h"
#include "e_s_pila.h"
int main()
{
    std::fstream f("prueba.txt");
    suma_lineas_fichero(f);
    f.close();
    return 0;
}