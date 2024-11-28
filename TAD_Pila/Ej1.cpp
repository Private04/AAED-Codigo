#include <string>

#include "pila_ps.h"
#include "ej1.h"

bool xy (const std::string& s)
{
    Pila<char> x(s.length()/2);
    size_t c_act=0;
    bool flag;//booleano a devolver
    for (c_act;c_act<s.length()/2;c_act++)
    //c_act es el número de carácteres leídos menos 1. Puesto que s.length()=2*longitud_x+1, s.length es impar para toda secuencia haciendo que s.length()/2 acabará siempre en el carácter antes de '&' si la cadena es correcta, sin importar el tamaño.
    {
        x.push(s[c_act]);
    }
    if (s[c_act]!='&')//Comprobación de que el caracter separador está en el medio
    {
        flag=false;
    }
    else
    {
        flag=true;
        while(s[++c_act])//Hasta que s[c_act]=='/0', empezando por el primer caracter de la segunda secuencia.
        {
            if (s[c_act]!=x.tope()) {flag=false;}//Este bucle se ejecuta el mismo número de veces que el tamaño de la pila, por lo que siempre se va a cumplir la precondición.
            x.pop();
        }
    }
    return flag;
}