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
        friend polinomio operator =(const &polinomio);
    private:
        unsigned GRADOMAX;//Grado máximo posible. Se define por el constructor y no se debe volver a modificar.
        unsigned gradopoli;//Grado del último elemento con coeficiente no nulo
        double *acoeficientes;
};
#endif