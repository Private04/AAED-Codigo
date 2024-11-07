/*3. Utilizando rand(), escriba una función que genere un número pseudoaleatorio de coma
flotante y precisión doble en el intervalo continuo [a, b].
4. Escriba un programa que genere 10 000 000 de números pseudoaleatorios de precisión doble
en el intervalo [0, 1] e imprima la media de los valores y = 4 · √1 − x2 correspondientes a
cada número x. Emplee la función del ejercicio anterior.*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

float rand_float(int a,int b);
float rand_float(int a,int b)
{
    return (float(rand())/RAND_MAX)*(b-a)+a;
}

int main()
{
    const int NUM_PRUEBAS = 10000000;
    srand(time(nullptr));
    float cont=0;
    for(int i=0;i<NUM_PRUEBAS;i++)
    {
        cont += 4*sqrt(1-pow(rand_float(0,1),2));
    }
    cout << "La media aritmetica es: " << cont/NUM_PRUEBAS << endl;
}