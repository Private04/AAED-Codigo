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
    int v[N];//Vector aleatorizado
    int w[N];//Vectorr a ordenar
    int cont;
    const double err_rel=0.5e-6;
    const double err_abs=1e-6;
    for (int i=0;i<=19999;i++)//Inicializacion del vector
    {
        v[i]=i+1;
    }
    for (int n=1000;n<=20000;n+=1000)
    {
        random_shuffle(v,v+n);
        cont = 0;//Numero de veces que se ejecuta la funcion
        c.activar();
        do{
            
            memcpy(w,v,sizeof(int)*n);
            ordenacion_intercambio(w,w+n);
            
            cont++;
        }while(c.tiempo()<err_abs/err_rel+err_abs);//Repetir hasta que pase suficiente tiempo tal que el error absoluto<error relativo y esperar un instante para asegurar que se supera
        c.parar();
        cout << "Tiempo de ejecucion para n=" << n << ": " << c.tiempo()/cont << endl << "Numero de veces ejecutado: " << cont << endl;  
    }
    cin.ignore(); 
    return 0;
}