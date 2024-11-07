/*5. Escriba un programa que genere 10 000 000 de permutaciones pseudoaleatorias de los 6
primeros números naturales e imprima cuántas de ellas están ordenadas.*/
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstring>
using namespace std;
const int NUM_PRUEBAS = 10000000;
int main()
{
    int v[6] = {1,2,3,4,5,6};
    int w[6] = {1,2,3,4,5,6};
    const size_t n = sizeof w / sizeof *w;
    int cont = 0;
    for (int i=0;i<NUM_PRUEBAS;i++)
    {
        random_shuffle(w,w + n);
        if (!memcmp(v,w,sizeof v)) {cont++;}
    }
    cout << "Numero de vectores ordenados: " << cont << endl;
    return 0;
}