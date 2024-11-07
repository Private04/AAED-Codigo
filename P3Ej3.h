#ifndef P3EJ3_H
#define P3EJ3_H
class polinomio
{
    public:
        //Funciones constructoras
        polinomio(unsigned gradoMax); //Crea el polinomio nulo cuyo grado es gradoMax
        //Funciones observadoras
        unsigned grado() const; //Devuelve el grado maximo del polinomio
        double coeficiente (unsigned n) const; //Devuelve el coeficiente del grado otorgado. Si n>gradMax, devuelve 0
        //Funciones modificadoras
        void coeficiente (unsigned n,double c); //Asigna un nuevo coeficiente de valor c al grado n. Precondicion: n<=gradMax
        friend polinomio operator +(polinomio& x,polinomio& y); //Devuelve x+y
        friend polinomio operator -(polinomio& x,polinomio& y); //Devuelve x-y
        friend polinomio operator *(polinomio& x,polinomio& y); //Devuelve x*y
        friend polinomio deriv(polinomio& x); //Devuelve la derivada de x
    private:
        static const unsigned GRAD_MAX=100;
        unsigned gradopoli;
        double acoeficientes[GRAD_MAX];
};
#endif