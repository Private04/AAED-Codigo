#include <iostream>
#include <cassert>
#include "mi_polinom.h"
#include "e_s_polinom.h"
using namespace std;
void escritura(polinomio& p,unsigned grado)//Construccion y escritura de polinomio en pantalla
{
    double coef_act;
    for (unsigned grado_act=0;grado_act<=grado;grado_act++) //Asignacion de coeficientes
    {
        cout << endl << "Escribe el valor del grado: " << grado_act << endl;
        cin >> coef_act;
        p.coeficiente(grado_act,coef_act);
    }
} 
void lectura(const polinomio& x) //Lectura de polinomio x en pantalla.
{
    for (unsigned grado_act=0;x.coeficiente(grado_act)!=0;grado_act++)
    {
        cout << "Coeficiente del grado: " << grado_act << " = " << x.coeficiente(grado_act) << endl;
    }
}
//PROBLEMA: La lectura solo lee correctamente en multiplicación. En suma, resta y derivada solo imprime el coeficiente de grado 0, independientemente del grado otorgado.