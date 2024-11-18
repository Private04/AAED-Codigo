#include <iostream>
#include "polinom.h"
#include "arit_polinom.h"
#include "e_s_polinom.h"
using namespace std;
int main()
{
    char op;
    polinomio x=escritura(),y=escritura();//Parametros de entrada
    
    bool op_valida;
    char salida;
    do {
        op_valida=true;
        cout << endl << "Escribe * para multiplicar, + para sumar, - para restar o 'd' para calcular la derivada" << endl;
        cin >> op;
        switch (op)
        {
            case '+':
            {
                polinomio res(/*(x.grado()>y.grado())? x.grado() :*/ y.grado());
                res=x+y;
                lectura(res);
            }
            break;
            case '*':
            {
                polinomio res(x.grado()+y.grado());
                res=x*y;
                lectura(res);
            }
            break;
            case '-':
            {
                polinomio res((x.grado()>y.grado())? x.grado() : y.grado());
                res=x-y;
                lectura(res);
            }
            break;
            case 'd':
            {
                polinomio res(x.grado()-1);
                res=deriv(x);
                lectura(res);
            }
            break;
            default:
            cout << endl << "Entrada no valida" << endl;
            op_valida=false;
        }
        
        cout << "Desea realizar otra operacion? Escriba s para continuar y cualquier tecla si no.";
        cin >> salida;
    }while(salida=='s');
    return 0;
}