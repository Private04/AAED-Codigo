#include <cassert>
#include <cstddef>
#include <cstring>
#include <utility>
#include "TAD_Diccionario.h"
char * Diccionario::crear_palabra(const char * palabra)
{
    char * p=new char[strlen(palabra)+1];
    strcpy(p,palabra);
    return p;
}

void Diccionario::borrar_palabra(const char * palabra)
{
    delete [] palabra;
}

Lista<Diccionario::Traduccion>::posicion Diccionario::buscar_ingles(const char * p) const
{
    Lista<Traduccion>::posicion pos=T.primera();
    while(pos!=T.fin()&&strcmp(p,T.elemento(pos).t_ingles))
    {
        pos=T.siguiente(pos);
    }
    return pos;
}

Lista<char *>::posicion Diccionario::buscar_espaniol(const char * p, Lista<Traduccion>::posicion pos_ingles) const
{
    const Lista<char *>& l_espaniol=T.elemento(pos_ingles).t_espaniol;
    Lista<char *>::posicion pos_espaniol=l_espaniol.fin();
    while (pos_espaniol!=l_espaniol.fin()&&strcmp(p,l_espaniol.elemento(pos_espaniol)))
    {
        pos_espaniol=l_espaniol.siguiente(pos_espaniol);
    }
}

Diccionario::Diccionario() : T()
{}

bool Diccionario::es_correcta(const char * ingles, const char * espaniol) const
{
    Lista<Traduccion>::posicion pos_traducciones=buscar_ingles(ingles);//posicion para recorrer la lista de traducciones
    Lista<char *>::posicion pos_espanioles;//poscion para recorrer la lista de palabras en español.
    bool encontrado=false;
    if (pos_traducciones!=T.fin())
    {
        pos_espanioles=buscar_espaniol(espaniol,pos_traducciones);//Si hay una palabra en ingles en la lista, que lo busque en su lista en español
        if (pos_espanioles!=T.elemento(pos_traducciones).t_espaniol.fin())
        {
            encontrado=true;
        }
    }
    return encontrado;
}

const Lista<char *>& Diccionario::traducciones(const char * ingles) const
{
    Lista<Traduccion>::posicion pos=buscar_ingles(ingles);
    assert(pos!=T.fin());
    return T.elemento(pos).t_espaniol;
}

void Diccionario::insertar_traduccion(const char *ingles,const char *espaniol)
{
    Lista<Traduccion>::posicion pos_ingles=buscar_ingles(ingles);
    if (pos_ingles==T.fin())
    {
        T.insertar(Traduccion(crear_palabra(ingles)),pos_ingles);
    }
    //Insertar la palabra en la última posición de la lista de palabras en español
    T.elemento(pos_ingles).t_espaniol.insertar(crear_palabra(espaniol),T.elemento(pos_ingles).t_espaniol.fin());
}

void Diccionario::eliminar_traduccion(const char *ingles, const char * espaniol)
{
    Lista<Traduccion>::posicion pos_ingles=buscar_ingles(ingles);
    Lista<char *>::posicion pos_espaniol;
    if (pos_ingles!=T.fin())
    {
        pos_espaniol=buscar_espaniol(espaniol,pos_ingles);//Busca en español, si lo encuentra, libera la cadena en memoria y lo elimina de la lista.
        if (pos_espaniol!=T.elemento(pos_ingles).t_espaniol.fin())
        {
            borrar_palabra(T.elemento(pos_ingles).t_espaniol.elemento(pos_espaniol));
            T.elemento(pos_ingles).t_espaniol.eliminar(pos_espaniol);
            if(T.elemento(pos_ingles).t_espaniol.vacia())//Si tras el borrado, está vacía, se borra la palabra en inglés y se elimina de la lista de traducciones
            {
                borrar_palabra(T.elemento(pos_ingles).t_ingles);
                T.eliminar(pos_ingles);
            }
        }

    }
}

Diccionario::Diccionario(const Diccionario& D) : T()
{
    Lista<Traduccion>::posicion d_inglespos=D.T.primera();//Variable para recorrer la lista D.T
    Lista<Traduccion>::posicion this_inglespos=T.fin();//Variable que almacena la posición de la estructura de traducción una vez insertada
    Lista<char *>::posicion d_espaniolpos;//Variable para recorrer las listas de palabras en español de D
    while (d_inglespos!=D.T.fin())
    {
        //Crear una nueva traducción e insertarla en this.T
        T.insertar(Traduccion(crear_palabra(D.T.elemento(d_inglespos).t_ingles)),this_inglespos);
        d_espaniolpos=D.T.elemento(d_inglespos).t_espaniol.primera();
        //Recorrer la lista de palabras en español
        while (d_espaniolpos!=D.T.elemento(d_inglespos).t_espaniol.fin())
        {
            //Insertar la palabra en español, creando el espacio de memoria adecuado
            T.elemento(this_inglespos).t_espaniol.insertar(crear_palabra(D.T.elemento(d_inglespos).t_espaniol.elemento(d_espaniolpos)),T.elemento(this_inglespos).t_espaniol.fin());
            //Avanzar a la siguiente posición
            d_espaniolpos=D.T.elemento(d_inglespos).t_espaniol.siguiente(d_espaniolpos);
        }
        this_inglespos=T.siguiente(this_inglespos);
        d_inglespos=D.T.siguiente(d_inglespos);
    }
}

Diccionario& Diccionario::operator=(const Diccionario& D)
{
    Diccionario aux(D);
    Lista<Traduccion> swap_aux;
    //Super ineficiente
    swap_aux=aux.T;
    aux.T=T;
    T=swap_aux;

    return *this;
}

Diccionario::~Diccionario()
{
    Lista<Traduccion>::posicion posingles=T.primera();
    Lista<char *>::posicion posespaniol;
    while (!T.vacia())
    {
        borrar_palabra(T.elemento(posingles).t_ingles);
        posespaniol=T.elemento(posingles).t_espaniol.primera();
        while(!T.elemento(posingles).t_espaniol.vacia())
        {
            borrar_palabra(T.elemento(posingles).t_espaniol.elemento(posespaniol));
            T.elemento(posingles).t_espaniol.eliminar(posespaniol);
        }
        T.eliminar(posingles);
    }
}