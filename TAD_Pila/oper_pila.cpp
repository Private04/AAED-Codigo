#include <string>
#include <fstream>
#include <cassert>
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
    unsigned acarreo=0;
    unsigned suma;
    f >> P >> Q;
    while (!P.vacia()||!Q.vacia())
    {
        suma=(!P.vacia()? P.tope(): 0)+(!Q.vacia()? Q.tope() : 0)+acarreo;
        if (suma>=10)
        {
            suma-=10;
            acarreo=1;
        }
        else
        {
            acarreo=0;
        }
        R.push(suma);
        if (!P.vacia()) P.pop();
        if (!Q.vacia()) Q.pop();
    }
    f << R;
}

linea_texto::linea_texto()
{}
void linea_texto::avanzar_cursor()
{
    assert(!siguiente.vacia());
    previo.push(siguiente.tope());
    siguiente.pop();
}
void linea_texto::borrar_anterior()
{
    assert(!previo.vacia());
    previo.pop();
}
void linea_texto::borrar_seleccionado()
{
    assert(!siguiente.vacia());
    siguiente.pop();
}
void linea_texto::insertar_caracter(char c)
{
    previo.push(c);
}
void linea_texto::ir_a_final()
{
    while (!siguiente.vacia())
    {
        previo.push(siguiente.tope());
        siguiente.pop();
    }
}
void linea_texto::ir_a_principio()
{
    while (!previo.vacia())
    {
        siguiente.push(previo.tope());
        previo.pop();
    }
}
void linea_texto::retrasar_cursor()
{
    siguiente.push(previo.tope());
    previo.pop();
}
void linea_texto::sobrescribir_caracter(char c)
{
    assert(!previo.vacia());
    previo.pop();
    previo.push(c);
}
char linea_texto::cursor() const
{
    return siguiente.tope();
}
size_t linea_texto::tama() const
{
    return previo.tama()+siguiente.tama();
}

bool solitario(const tCarta *baraja,eFigura *resultado)
{
    Pila<tCarta> tMazo,tMonton;
    resultado[OROS]=VACIO;
    resultado[COPAS]=VACIO;
    resultado[ESPADAS]=VACIO;
    resultado[BASTOS]=VACIO;
    //0=ORO,1=COPAS,2=ESPADAS,3=BASTOS
    int tama_prev;//Almacena el tamaño previo para comprobar cuando parar de jugar
    for (size_t i=0;i<40;i++)//Preparación del mazo
    {
        tMazo.push(baraja[i]);
    }
    do
    {
        tama_prev=tMazo.tama();
        while (!tMazo.vacia())
        {
            tMonton.push(tMazo.tope());
            tMazo.pop();
            if (!tMazo.vacia())//En caso de que solo quede una carta en el mazo
            {
                tMonton.push(tMazo.tope());
                tMazo.pop();
            }
            while (!tMonton.vacia()&&tMonton.tope().figura==resultado[tMonton.tope().palo]+1)//Suma para comparaciones se puede hacer, pero no asignación?
            {
                resultado[tMonton.tope().palo]=tMonton.tope().figura;
                tMonton.pop();
            }
        }
        while (!tMonton.vacia())//Reponer el mazo
        {
            tMazo.push(tMonton.tope());
            tMonton.pop();
        }
    }while(tMazo.tama()!=tama_prev&&!tMazo.vacia());
    return tMazo.vacia();
}