#include <string>
#include <iostream>
#include "oper_pila.h"
using namespace std;
int main()
{
    char cadenamax[100];
    cout << "Introduce la cadena a comprobar" << endl;
    cin >> cadenamax;
    cout << endl << secuencia_inversa_xy(cadenamax) << endl;
    return 0;
}