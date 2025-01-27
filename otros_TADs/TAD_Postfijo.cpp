#include <cstddef>
#include <cassert>
#include "../TAD_Pila/pila_ce.h"
#include "TAD_Postfijo.h"
unsigned int postfijo(const char *expr,const Variable *vars)
{
    Pila<unsigned int> operandos;
    unsigned int a,b;//Variables para almacenar los operandos.
    size_t i=0,j=0;
    while(expr[i]!='\0')
    {
        if(expr[i]<'A'&&expr[i]>'Z')
        {
            a=operandos.tope();
            operandos.pop();
            b=operandos.tope();
            operandos.pop();
            switch(expr[i])
            {
                case('+'):
                    operandos.push(a+b);
                    break;
                case('-'):
                    operandos.push(b-a);//La pila es FIFO, el primer operando es b.
                    break;
                case('*'):
                    operandos.push(a*b);
                case('/'):
                    operandos.push(b/a);//Mismo motivo
                    break;
                default://Carácter inválido, la precondición se incumple, y como es culpa del usuario, no tenemos por qué hacer algo al respecto.
                    
            }
        }
        else
        {
            j=0;
            while(vars[j].nombre!=expr[i]) {j++;}
            operandos.push(vars[j].valor);
        }
        i++;//Siguiente caracter a evaluar.
    }
    return operandos.tope();//Si la expresión está bien, solo debería haber un elemento en la pila que es el resultado.
}