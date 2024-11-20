#include "mi_polinom.h"
#include "arit_polinom.h"
#include <cstddef>
polinomio operator +(polinomio& x,polinomio& y) //Devuelve x+y
{
    unsigned gradomax=(x.grado()>y.grado())?x.grado() : y.grado();
    polinomio suma(gradomax);
    unsigned GradoSumado;
    for (GradoSumado=0;GradoSumado<=gradomax;GradoSumado++) 
    {
        suma.coeficiente(GradoSumado,x.coeficiente(GradoSumado)+y.coeficiente(GradoSumado));
    }
    
    return suma;
}
polinomio operator -(polinomio& x,polinomio& y) //Devuelve x-y
{
    unsigned gradomax=(x.grado()>y.grado())?x.grado() : y.grado();
    polinomio resta(gradomax);
    unsigned GradoRestado;
    for (GradoRestado=0;GradoRestado<=gradomax;GradoRestado++) 
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
    
    unsigned gradoderivado;
    unsigned gradomaximo=x.grado()-1;
    polinomio deriv(gradomaximo);
    for (gradoderivado=0;gradoderivado<=gradomaximo;gradoderivado++)
    {
        deriv.coeficiente(gradoderivado,(gradoderivado+1)*x.coeficiente(gradoderivado+1));
    }
    return deriv;
}