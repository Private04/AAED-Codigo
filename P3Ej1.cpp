#include "P3EJ1.h"
#include <cstddef>
polinomio operator +(polinomio& x,polinomio& y) //Devuelve x+y
{
    polinomio suma(x.grado() | y.grado());
    size_t GradoSumado;
    for (GradoSumado=0;GradoSumado<=x.grado() && GradoSumado<=y.grado();GradoSumado++) 
    {
        suma.coeficiente(GradoSumado,x.coeficiente(GradoSumado)+y.coeficiente(GradoSumado));
    }
    if (x.grado()>y.grado()) {
        while (x.grado()>=GradoSumado)
        {
            suma.coeficiente(GradoSumado,x.coeficiente(GradoSumado));
            GradoSumado++;
        }
    }
    else
    {
        while (y.grado()>=GradoSumado)
        {
            suma.coeficiente(GradoSumado,y.coeficiente(GradoSumado));
            GradoSumado++;
        }
    }
    return suma;
}
polinomio operator -(polinomio& x,polinomio& y) //Devuelve x-y
{
    polinomio resta(x.grado() | y.grado());
    size_t GradoRestado;
    for (GradoRestado=0;GradoRestado<=x.grado() && GradoRestado<=y.grado();GradoRestado++) 
    {
        resta.coeficiente(GradoRestado,x.coeficiente(GradoRestado)-y.coeficiente(GradoRestado));
    }
    if (x.grado()>y.grado()) {
        while (x.grado()>=GradoRestado)
        {
            resta.coeficiente(GradoRestado,x.coeficiente(GradoRestado));
            GradoRestado++;
        }
    }
    else
    {
        while (y.grado()>=GradoRestado)
        {
            resta.coeficiente(GradoRestado,-y.coeficiente(GradoRestado));
            GradoRestado++;
        }
    }
    return resta;
}
polinomio operator *(polinomio& x,polinomio& y) //Devuelve x*y
{
    polinomio prod(x.grado()+y.grado());
    size_t GradoX,GradoY;
    for (GradoX=0;GradoX<=x.grado();GradoX++)
    {
        for (GradoY=0;GradoY<=y.grado();GradoY++)
        {
            prod.coeficiente(GradoX+GradoY,prod.coeficiente(GradoX+GradoY)+(x.coeficiente(GradoX)*y.coeficiente(GradoY)));
        }
    }
    return prod;
}
polinomio deriv(polinomio& x) //Devuelve la derivada de x
{
    polinomio deriv(x.grado()-1);
    size_t grado;
    for (grado=0;grado<=deriv.grado();grado++)
    {
        deriv.coeficiente(grado,(grado+1)*x.coeficiente(grado+1));
    }
    return deriv;
}

