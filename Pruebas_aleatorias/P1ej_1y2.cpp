//1.Utilizando rand(), escriba una función que genere un número pseudoaleatorio entero en el
//intervalo discreto [a, b]
/*2. Escriba un programa que simule 10 000 000 de tiradas de un dado. Imprima las frecuencias
relativas que se obtienen para cada una de las caras. Emplee la función del ejercicio anterior.*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rand_rango(int,int);

int rand_rango(int a,int b)
{
    return (rand() % (b-a+1)) + a;
}

int main()
{
    int frec_absolutas[6]={0,0,0,0,0,0};
    
    for(int i=1;i<10000000;i++)
    {
        frec_absolutas[rand_rango(0,5)]++;
    }
    cout << "Frecuencias relativas de cada resultado del dado." << endl;
    for (int i=0;i<6;i++)
    {
        cout << i+1 << ": " << frec_absolutas[i]/10000000.0 << endl;
    }
    return 0;
}