#include <string>
#include <iostream>
#include "Ej1.h"
using namespace std;
int main()
{
    struct elem_prueba{
        string c_prueba;
        bool res_esperado;
        elem_prueba(string s,bool b) : c_prueba(s),res_esperado(b) {}
    };
    elem_prueba cadena_inferior("12345&4321",false),cadena_superior("1234&12345",false),cadena_correcta("12345&54321",true),cadena_sin_ampersan("1234554321",false);
    if (cadena_inferior.res_esperado!=xy(cadena_inferior.c_prueba))
    {
        cout << "Error en la prueba de cadena inferior" << endl;
       
    }
    else
    {
        if (cadena_superior.res_esperado!=xy(cadena_superior.c_prueba))
        {
            cout << "Error en la prueba de cadena superior" << endl;
            
        }
        else
        {
            if (cadena_correcta.res_esperado!=xy(cadena_correcta.c_prueba))
            {
                cout << "Error en la prueba con una cadena correcta" << endl;
            }
            else
            {
                if(cadena_sin_ampersan.res_esperado!=xy(cadena_sin_ampersan.c_prueba))
                {
                    cout << "Error en la prueba de cadena sin &" << endl;
                }
                cout << "Fin de las pruebas" << endl;
            }
        }

    }
    return 0;
}