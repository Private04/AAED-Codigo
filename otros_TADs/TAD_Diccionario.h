/*
    Se define diccionario inglés-español como un conjunto de traducciones.
    Una traducción es una relación entre una palabra inglesa y una palabra española.
    Las palabras inglesas y españolas son cadenas de carácteres.
    La relación no es simétrica, se relaciona a una palabra española dada una palabra inglesa.
    Puede haber más de una traducción las cuales usen la misma palabra inglesa o española, pero no ambas.

    Operaciones:
        Constructora:
            Diccionario(); Crea un diccionario vacío.
        Obseradoras:
            bool es_correcta(const char * ingles,const char * espaniol) const; Devuelve true si existe en el diccionario una traaducción que relacione la ingles a espaniol
            const Lista<char *>& traducciones(const char * ingles) const; Devuelve el conjunto de las palabras en español que tienen una traducción con ingles.
            Precondición: Hay al menos una traducción con ingles como palabra inglesa
        Modificadoras:
            void insertar_traduccion(const char * ingles,const char * espaniol); Añade una traducción relacionando ingles a espaniol
            void eliminar_traduccion(const char * ingles,const char * espaniol); Elimina la traducción relacionando ingles a espaniol, si no la hay, no hace nada. 
*/
//ADVERTENCIA: Este código es malo y poco legible, no lo recomiendo analizar.
#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include "../TAD_Lista/lista_c1e.h"
class Diccionario{
    public:
    Diccionario();
    bool es_correcta(const char * ingles,const char * espaniol) const;
    const Lista<char *>& traducciones(const char * ingles) const;
    void insertar_traduccion(const char * ingles, const char * espaniol);
    void eliminar_traduccion(const char * ingles, const char * espaniol);
    //Requeridas por la implementación.
    Diccionario(const Diccionario& D);
    Diccionario& operator =(const Diccionario& D);
    ~Diccionario();
    private:
    struct Traduccion{
        char * t_ingles;//Palabra en inglés de referencia
        Lista<char *> t_espaniol;//Todas las palabras en español que referencia
        Traduccion(char * ingles) : t_espaniol() {t_ingles=ingles;}
    };//LA ALOCACIÓN DE LAS PALABRAS SE ENCARGARÁN LAS FUNCIONES DE LA CLASE Y NO LAS DE LA ESTRUCTURA.
    Lista<Traduccion> T;
    char * crear_palabra(const char * palabra);//Crea una cadena a partir de otra, reservando memoria para eso.
    void borrar_palabra(const char * palabra);//Libera la memoria de palabra.
    Lista<Traduccion>::posicion buscar_ingles(const char *p) const;//Busca la primera ocurrencia de p en la lista T
    //Si no lo encuentra, devuelve T.fin()
    Lista<char *>::posicion buscar_espaniol(const char *p,Lista<Traduccion>::posicion pos_ingles) const;//Lo mismo pero en la lista de palabras españolas de una traducción de la lista
};
#endif