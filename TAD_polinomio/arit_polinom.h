#ifndef ARIT_POLINOM
#define ARIT_POLINOM
polinomio operator +(polinomio& x,polinomio& y); //Devuelve x+y
polinomio operator -(polinomio& x,polinomio& y); //Devuelve x-y
polinomio operator *(polinomio& x,polinomio& y); //Devuelve x*y
polinomio deriv(polinomio& x); //Devuelve la derivada de x
#endif