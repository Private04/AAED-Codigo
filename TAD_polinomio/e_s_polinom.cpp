#include <iostream>
#include <cassert>
#include "mi_polinom.h"
#include "e_s_polinom.h"
using namespace std;
polinomio escritura()//Construccion y escritura de polinomio en pantalla
{
    double coef_act;
    unsigned grado;
    cout << "Escribe el grado del polinomio." << endl;
    cin >> grado;
    polinomio p(grado);
    for (unsigned grado_act=0;grado_act<=grado;grado_act++) //Asignacion de coeficientes
    {
        cout << endl << "Escribe el valor del grado: " << grado_act << endl;
        cin >> coef_act;
        p.coeficiente(grado_act,coef_act);
    }
    return p;
} 
void lectura(const polinomio& x) //Lectura de polinomio x en pantalla.
{
    for (unsigned grado_act=0;grado_act<=x.grado();grado_act++)
    {
        cout << "Coeficiente del grado: " << grado_act << " = " << x.coeficiente(grado_act) << endl;
    }
}
