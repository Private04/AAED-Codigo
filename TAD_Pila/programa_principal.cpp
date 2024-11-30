#include <string>
#include <iostream>
#include "pila_ce.h"
#include "oper_pila.h"
#include "e_s_pila.h"
using namespace std;
int main()
{
    Pila<char> p;
    char a,b;
    pila_escribir(p);
    cout << "Escribe los dos caracteres a delimitar la inversion." << endl;
    cin >> a;
    cin >> b;
    inversion_delimitada(a,b,p);
    pila_leer(p);
    return 0;
}