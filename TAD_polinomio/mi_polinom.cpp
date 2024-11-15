#include "mi_polinom.h"
#include <cassert>
polinomio::polinomio(unsigned gradoMax)
{
    gradopoli=gradoMax;
    for (int i=0;i<=gradoMax;i++)
    {
        acoeficientes[i]=0;
    }
}
unsigned polinomio::grado() const
{
    return gradopoli;
}
double polinomio::coeficiente (unsigned n) const
{
    return (n>gradopoli) ? 0 : acoeficientes[n];
}
void polinomio::coeficiente (unsigned n,double c)
{
    assert (n<=gradopoli);
    acoeficientes[n]=c;
}
polinomio operator +(polinomio& x,polinomio& y) //Devuelve x+y
{
    polinomio suma((x.grado()<y.grado()) ? y.grado() : x.grado());
    unsigned GradoSumado;
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
    polinomio resta((x.grado()<y.grado()) ? y.grado() : x.grado());
    unsigned GradoRestado;
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
    unsigned GradoX,GradoY;
    for (GradoX=0;GradoX<=x.grado();GradoX++)
    {
        if (x.coeficiente(GradoX)!=0) { //optimizacion
            for (GradoY=0;GradoY<=y.grado();GradoY++)
            {
                prod.coeficiente(GradoX+GradoY,prod.coeficiente(GradoX+GradoY)+(x.coeficiente(GradoX)*y.coeficiente(GradoY))); //coef[gX+gY]+=coefx[gX]*coefy[gY]
            }
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