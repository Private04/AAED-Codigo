#include "mi_polinom.h"
#include "arit_polinom.h"
#include <cstddef>
polinomio operator +(polinomio& x,polinomio& y) //Devuelve x+y
{
    polinomio suma((x.grado()>y.grado())?x.grado() : y.grado());
    unsigned GradoSumado;
    for (GradoSumado=0;GradoSumado<=suma.grado();GradoSumado++) 
    {
        suma.coeficiente(GradoSumado,x.coeficiente(GradoSumado)+y.coeficiente(GradoSumado));
    }
    
    return suma;
}
polinomio operator -(polinomio& x,polinomio& y) //Devuelve x-y
{
    polinomio resta((x.grado()>y.grado())?x.grado() : y.grado());
    unsigned GradoRestado;
    for (GradoRestado=0;GradoRestado<=resta.grado();GradoRestado++) 
    {
        resta.coeficiente(GradoRestado,x.coeficiente(GradoRestado)-y.coeficiente(GradoRestado));
    }
    return resta;
}
polinomio operator *(polinomio& x,polinomio& y) //Devuelve x*y
{
    polinomio prod(x.grado()+y.grado());
    unsigned GradoX,GradoY;
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
    unsigned grado;
    for (grado=0;grado<=deriv.grado();grado++)
    {
        deriv.coeficiente(grado,(grado+1)*x.coeficiente(grado+1));
    }
    return deriv;
}