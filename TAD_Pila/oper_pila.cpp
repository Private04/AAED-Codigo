#include <string>
#include <fstream>
#include "pila_ce.h"
#include "oper_pila.h"
using namespace std;
bool secuencia_inversa_xy (char * s)//Ejercicio 1
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
bool secuencia_abcd(char *s)//Ejercicio 2
{
    bool EsCorrecta=true;
    char *cad_comprobando;
    size_t c_act=0;
    size_t i_act;
    Pila <char> p;
    while(s[c_act]&&EsCorrecta)//Guardar la cadena a comprobar en una pila
    {
        if (s[c_act]!='#')
        {
            p.push(s[c_act]);
        }
        else//Una vez sabemos el numero de caracteres, creamos una cadena para enviarselo a la funcion
        {
            cad_comprobando=new char[p.tama()+1];
            i_act=0;
            while (!p.vacia())
            {
                cad_comprobando[i_act]=p.tope();
                p.pop();
                i_act++;
            }
            cad_comprobando[i_act]='\0';
            EsCorrecta=secuencia_inversa_xy(cad_comprobando);
            delete[] cad_comprobando;
        }
        c_act++;
    }
    return EsCorrecta;
}
void inversion_delimitada(const char& a,const char& b,Pila<char>& p_inicial)//Ejercicio 3
{
    
    Pila<char> p_aux;//Pila que almacena los elementos entre a y b para invertirlos
    Pila<char> p_res;//Pila que almacena el resultado de la inversion.
    while (p_inicial.tope()!=a&&!p_inicial.vacia())//Primero recorrer la pila hasta encontrar el valor a.
    {
        p_res.push(p_inicial.tope());
        p_inicial.pop();
    }
    if (!p_inicial.vacia())
    {
        p_aux.push(p_inicial.tope());
        p_inicial.pop();
        while (p_aux.tope()!=b&&!p_inicial.vacia())//Guardar la secuencia a invertir en aux
        {
            p_aux.push(p_inicial.tope());
            p_inicial.pop();
        }
    }
    while (!p_aux.vacia())//Mover aux a res
    {
        p_res.push(p_aux.tope());
        p_aux.pop();
    }
    while (!p_res.vacia())//Mover res a inicial, invirtiendo la secuencia de aux y dando el resultado
    {
        p_inicial.push(p_res.tope());
        p_res.pop();
    }

} 
// Apila en P los valores númericos de los dígitos
// extraídos del flujo de entrada fe
fstream& operator >>(fstream& fe, Pila<int>& P)
{
char cifra ;
while (fe.get( cifra ) && cifra != '\n') // leer caracteres hasta fin de línea
P.push(cifra -= '0'); // convierte un dígito en su valor numérico
return fe;
}
// Inserta en el flujo de salida fs la pila P
fstream& operator <<(fstream& fs, Pila<int> P)
{
while (!P.vacia()) {

fs << P.tope();
P.pop();
}
fs << endl;
return fs;
}
void suma_lineas_fichero(std::fstream& f)
{
    Pila<int> P,Q,R;
    f >> P >> Q;
    while (!P.vacia()&&!Q.vacia())
    {
        R.push(P.tope()+Q.tope());
        P.pop();
        Q.pop();
    }
    f << R;
}