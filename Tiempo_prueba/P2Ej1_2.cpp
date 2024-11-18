/*1. Programe los algoritmos de ordenación por intercambio directo, selección directa e inser-
ción directa para vectores de enteros.*/
/*Realice pruebas de caja negra sobre los algoritmos del ejercicio anterior con las técnicas
explicadas en la práctica 1. Utilice como batería de pruebas vectores de n enteros: varíe n
desde 1 hasta 9 y pruebe todas las permutaciones de cada vector.*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void ordenacion_intercambio_directo(int *v,int *f);

void ordenacion_intercambio_directo(int *v,int *f)
{
    for (int *i=v;i != f-1;++i)
    {
        for (int *j=f-1;j != i;--j)
        {
            if (*j<*(j-1)) {swap(*j,*(j-1));}
        }
    }
}

void ordenacion_seleccion_directo(int *v,int *f)
{
    int* p;
    int m;
    for (int *i=v;i != f-1;++i)
    {
        p=i;
        m=*i;
        for (int *j=f-1;j != i;--j)
        {
            if (*j<m) {p=j;m=*j;}
        }
        swap(*p,*i);
    }
}
void ordenacion_insercion_directa(int *v,int *f)
{
    int x;
    int *j;
    for (int *i=v+1;i != f;++i)
    {
        x=*i;
        j=i;
        while (j>v&&x<*(j-1))
        {
            *j=*(j-1);
            j--;
        }
        *j=x;
    }
}

int main()
{
    int v[9];//Vector ordenado
    int w[9];//Vector a probar
    int x[9];//Vector permutado
    for (int n = 1; n <= 9;n++)
    {
        v[n-1]=n-1;
        memcpy(x,v,sizeof v);
        do{
            memcpy(w,x,sizeof(v));
            ordenacion_seleccion_directo(w,w+n);
            if (memcmp(v,w,n)) {cout << "ERROR en la comprobacion de: " << n << endl;}
        }while(next_permutation(x,x+n));

    }
    cout << "Prueba superada." << endl;
    return 0;
    
}