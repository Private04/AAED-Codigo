/*Analice empíricamente los algoritmos del primer ejercicio en el caso promedio. Utilice
permutaciones aleatorias de un vector de enteros que contenga los n primeros números
naturales, donde n variará desde 1 000 hasta 20 000 en incrementos de 1 000.*/
#include "cronometro.h"
#include "ordenacion.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main()
{
    cronometro c;
    const int N = 20000;
    int v[N];
    int cont;
    const double err_rel=0.5e-6;
    const double err_abs=1e-6;
    for (int i=0;i<=19999;i++)
    {
        v[i]=i+1;
    }
    for (int n=1000;n<=20000;n+=1000)
    {
        cont = 0;
        c.activar();
        do{
            random_shuffle(v,v+n);
            
            ordenacion_seleccion(v,v+n);
            
            cont++;
        }while(c.tiempo()<err_abs/err_rel+err_abs);
        c.parar();
        cout << "Tiempo de ejecucion para n=" << n << ": " << c.tiempo()/cont << endl;  
    }
    cin.ignore(); 
    return 0;
}