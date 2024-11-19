#include "mi_polinom.h"
#include <cassert>
polinomio::polinomio(unsigned gradoMax): gradopoli(0),gradomaximo(gradoMax)
{
    acoeficientes=new double[gradoMax+1];
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
    return (n>gradopoli) ? 0 : acoeficientes[n];//Si n>grado tiene que devolver 0
}
unsigned polinomio::gradomax() const
{
    return gradomaximo;
}
void polinomio::coeficiente (unsigned n,double c)
{
    assert (n<=gradomaximo);//Precondicion
    
    if (c!=0){//Reajustamos el grado si se asigna un cociente de grado superior a los demas
        if (gradopoli<n) {gradopoli=n;}
    }
    else{//Si se asigna 0 al maximo, hay que buscar el nuevo maximo
        if (gradopoli==n) {
            while(gradopoli!=0&&acoeficientes[gradopoli]==0){
                gradopoli--;
            };
        }
    }
    acoeficientes[n]=c;
}
polinomio::polinomio(const polinomio& p): polinomio(p.gradomaximo)//Posible optimización, llama a dos bucles
{
    gradopoli=p.gradopoli;
    for (int i=0;i<=gradopoli;i++)
    {
        acoeficientes[i]=p.acoeficientes[i];
    }
}
polinomio polinomio::operator =(const polinomio& p)
{
    if (this!=&p)//Evitar autoasignación
    {
        if (gradomaximo!=p.gradomaximo)//Usar un auxiliar para asegurarse de no perder el vector acoeficientes en caso de que new falle.
        {
            double *aux = acoeficientes;
            acoeficientes = new double[p.gradomaximo];
            delete aux;
        }
        gradomaximo=p.gradomaximo;
        gradopoli=p.gradopoli;
        for (int i=0;i<=gradomaximo;i++)
        {
            acoeficientes[i]=p.acoeficientes[i];
        }
    }
    return *this;
}
polinomio::~polinomio()
{
    delete[] acoeficientes;
}