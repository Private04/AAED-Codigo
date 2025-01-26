/* 
    Se define una cortelera como un conjunto de salas.
    Una sala es un conjunto de espectáculos. Cada sala de una cartelera se identifica por un entero, de tal manera que dos salas de una cartelera no pueden tener el mismo identificador.
    Un espectáculo es un evento realizado en la sala que lo contiene, y se identifican por un entero distintivo de los demás espectáculos de la sala.

    Operaciones:
        Constructora:
            Cartelera(); Crea una cartelera vacía
        Modificadoras:
            void insertar_sala(Identificador id);   Añade una sala sin espectáculos a la cartelera identificada por id. Si una sala de la cartelera tiene el mismo id que el introducido, no hace nada.
                                           
            void insertar_espectaculo(Identificador id_espectaculo,Identificador id_sala);   Precondición: Existe una sala en la cartelera con identificador id_espectaculo.
                                                                                                Añade un espectáculo con identificador id_espectaculo a la sala de id_sala.
                                                                                                Si ya hay un espectáculo con identificador igual en esa sala, no hace nada.
            void eliminar_sala(Identificador id_sala);  Borra la sala con identificador id_sala y sus espectáculos de la cartelera. Si no hay una sala en la cartelera con ese identificador, no hace nada.
            void eliminar_espectaculo(Identificador id_sala,Identificador id_espectaculo);  Elimina el espectáculo con identificador id_espectaculo de la sala id_sala de la cartelera.
                                                                                            Si id_espectaculo no coincide con los espectaculos de id_sala o no existe la sala, no hace nada.
*/

#ifndef TAD_CARTELERA_H
#define TAD_CARTELERA_H
#include "../TAD_Lista/lista_c1e.h"
class Cartelera{
    public:
        typedef unsigned int Identificador;
        Cartelera();
        void insertar_sala(Identificador id);
        void insertar_espectaculo(Identificador id_espectaculo,Identificador id_sala);
        void eliminar_sala(Identificador id_sala);
        void eliminar_espectaculo(Identificador id_sala,Identificador id_espectaculo);
    private:
        struct Sala{
            Identificador id;
            Lista<Identificador> espectaculos;
            Sala(size_t i=0) : id(i),espectaculos() {} 
        };
        Lista<Sala> L;
        Lista<Sala>::posicion buscar_sala(Identificador id) const;
        Lista<Identificador>::posicion buscar_espectaculo(Identificador id,Lista<Sala>::posicion pos_sala) const;
};
#endif