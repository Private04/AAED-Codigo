#ifndef POSTFIJO_H
#define POSTIFIJO_H
struct Variable
{
    char nombre;
    unsigned int valor;
    Variable(char n,unsigned int v=0) : nombre(n),valor(v) {}
};
unsigned int postfijo(const char *expr,const Variable *vars);
/*
    PRECONDICIÓN: expr corresponde a una expresión válida de un postfijo terminado en carácter nulo.
    Además todos las variables cumplen lo siguiente.
        1. El campo nombre tiene un valor entre [A-Z].
        2. El campo nombre de dos variables del vector vars no tienen el mismo valor.
        3. Por cada carácter entre [A-Z] contenido en expr existe una variable del vector vars cuyo valor del campo nombre es igual a ese carácter.
    Devuelve el valor del postfijo expr tomando las variables vars.
*/
#endif