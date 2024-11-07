#include "P3EJ3.h"
#include <iostream>
using namespace std;
int main()
{
    size_t GradoX,GradoY;
    double coef;
    char op;
    cout << "Escribe el grado del polinomio x" << endl;
    cin >> GradoX;
    cout << endl << "Escribe el grado del polinomio y" << endl;
    cin >> GradoY;
    polinomio x(GradoX),y(GradoY),res(GradoX+GradoY);
    for (int i=0;i<=GradoX;i++)
    {
        cout << endl << "X: Escribe el coeficiente de grado " << i << endl;
        cin >> coef;
        x.coeficiente(i,coef);
    }
    for (int i=0;i<=GradoY;i++)
    {
        cout << endl << "Y: Escribe el coeficiente de grado " << i << endl;
        cin >> coef;
        y.coeficiente(i,coef);
    }
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
        return 1;
    }
    cout << endl << "El resultado es: " << endl;
    for (int i=0;i<=res.grado();i++)
    {
        cout << endl << "Grado " << i << " = " << res.coeficiente(i) << endl;
    }
    char n;
    cin >> n;
    return 0;
}