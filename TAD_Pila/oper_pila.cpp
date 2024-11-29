#include <string>

#include "pila_ce.h"
#include "oper_pila.h"

bool secuencia_inversa_xy (char * s)
{
    
    Pila<char> x;
    size_t c_act=0;//
    bool EsCorrecta=true;//booleano a devolver
    for (c_act;s[c_act]!='&'&&s[c_act]!=0;c_act++)//Insercion de la cadena 1 en la pila
    //c_act es el número de carácteres leídos menos 1.
    {
        x.push(s[c_act]);
    }
    if (s[c_act]!='&')//Comprobación de que el caracter separador está en el medio
    {
        EsCorrecta=false;
    }
    while(s[++c_act]&&EsCorrecta)//Hasta que s[c_act]=='/0' o haya discrepancia entre las cadenas, empezando por el primer caracter de la segunda secuencia.
    {
        if (s[c_act]!=x.tope()) {EsCorrecta=false;}//Este bucle se ejecuta el mismo número de veces que el tamaño de la pila, por lo que siempre se va a cumplir la precondición.
        x.pop();
    }
    return EsCorrecta;
}
bool secuencia_abcd(char *s)
{
    bool EsCorrecta=true;
    char *cad_comprobando;
    size_t c_act=0;
    size_t i_act;
    Pila <char> p;
    while(s[c_act]&&EsCorrecta)
    {
        if (s[c_act]!='#')
        {
            p.push(s[c_act]);
        }
        else
        {
            cad_comprobando=new char[p.tama()];
            i_act=0;
            while (!p.vacia())
            {
                cad_comprobando[i_act]=p.tope();
                p.pop();
                i_act++;
            }
            
        }
    }
}