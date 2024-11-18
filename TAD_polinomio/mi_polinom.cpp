#include "mi_polinom.h"
#include <cassert>
polinomio::polinomio(unsigned gradoMax)
{
    GRADOMAX=gradoMax;
    acoeficientes=new double[GRADOMAX];
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
