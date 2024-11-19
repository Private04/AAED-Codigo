#include <iostream>
#include "mi_polinom.h"
#include "arit_polinom.h"
#include "e_s_polinom.h"
using namespace std;
int main()
{
    char op;
    unsigned gradx,grady;
    bool op_valida;
    cout << "Escribe el grado de x seguido del de y" << endl;
    cin >> gradx;
    cin >> grady;
    polinomio x(gradx),y(grady);//Parametros de entrada
    escritura(x,gradx);
    escritura(y,grady);
    
    
    char salida;
    do {
        op_valida=true;
        cout << endl << "Escribe * para multiplicar, + para sumar, - para restar o 'd' para calcular la derivada" << endl;
        cin >> op;
        switch (op)
        {
            case '+':
            {
                polinomio res((x.grado()>y.grado())? x.grado() : y.grado());
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