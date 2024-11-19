#ifndef P3EJ3_H
#define P3EJ3_H
class polinomio
{
    public:
        //Funciones constructoras
        polinomio(unsigned gradoMax); //Crea el polinomio nulo cuyo grado es gradoMax.
        //Funciones observadoras
        unsigned grado() const; //Devuelve el grado maximo del polinomio
        double coeficiente (unsigned n) const; //Devuelve el coeficiente del grado otorgado. Si n>gradoMax, devuelve 0
        unsigned gradomax() const;//Devuelve el grado maximo asignable al polinomio
        //Funciones modificadoras
        void coeficiente (unsigned n,double c); //Asigna un nuevo coeficiente de valor c al grado n. Precondicion: n<=gradoMax
        polinomio(const polinomio& p);//Constructor de copia
        polinomio operator =(const polinomio& p);//Asignación de copia
        //Función destructora
        ~polinomio();
    private:
        unsigned gradomaximo;//Tamaño del vector acoeficicentes.
        unsigned gradopoli;//Grado del último elemento con coeficiente no nulo
        double *acoeficientes;//Vector de todos los coeficientes ordenados en funcion del grado que representan
};
#endif