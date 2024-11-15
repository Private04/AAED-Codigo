#include <iostream>
#include "polinom.h"
#include "arit_polinom.h"
#include "e_s_polinom.h"
using namespace std;
int main()
{
    char op;
    polinomio x=escritura(),y=escritura();//Parametros de entrada
    polinomio res;
    bool op_valida;
    char salida;
    do {
        op_valida=true;
        cout << endl << "Escribe * para multiplicar, + para sumar, - para restar o 'd' para calcular la derivada" << endl;
        cin >> op;
        switch (op)
        {
            case '+':
            res=x+y;
            break;
            case '*':
            res=x*y;
            break;
            case '-':
            res=x-y;
            break;
            case 'd':
            res=deriv(x);
            break;
            default:
            cout << endl << "Entrada no valida" << endl;
            op_valida=false;
        }
        if (op_valida){
            cout << endl << "El resultado es: " << endl;
            lectura(res);
        }
        cout << "Desea realizar otra operacion? Escriba s para continuar y cualquier tecla si no.";
        cin >> salida;
    }while(salida=='s');
    return 0;
}