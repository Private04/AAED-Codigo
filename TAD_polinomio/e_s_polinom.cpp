#include <iostream>
#include "polinom.h"
#include "e_s_polinom.h"
using namespace std;
polinomio escritura()//Construccion y escritura de polinomio en pantalla
{
    unsigned gradoMax;
    unsigned coef_act;//Almacena el valor del coeficiente a escribir en el bucle

    cout << "Escribe el grado maximo del polinomio." << endl;
    cin >> gradoMax;

    polinomio nuevopol(gradoMax);//Construccion del polinomio

    for (unsigned grado_act=0;grado_act<=gradoMax;grado_act++) //Asignacion de coeficientes
    {
        cout << endl << "Escribe el valor del grado: " << grado_act << endl;
        cin >> coef_act;
        nuevopol.coeficiente(grado_act,coef_act);
    }
    return nuevopol;
} 
void lectura(const polinomio& x) //Lectura de polinomio x en pantalla.
{
    for (unsigned grado_act=0;grado_act<=x.grado();grado_act++)
    {
        cout << "Coeficiente del grado: " << grado_act << " = " << x.coeficiente(grado_act) << endl;
    }
}
//PROBLEMA: La lectura solo lee correctamente en multiplicación. En suma, resta y derivada solo imprime el coeficiente de grado 0, independientemente del grado otorgado.