#ifndef P3EJ1_H
#define P3EJ1_H
polinomio operator +(polinomio& x,polinomio& y); //Devuelve x+y
polinomio operator -(polinomio& x,polinomio& y); //Devuelve x-y
polinomio operator *(polinomio& x,polinomio& y); //Devuelve x*y
polinomio deriv(polinomio& x); //Devuelve la derivada de x
#endif