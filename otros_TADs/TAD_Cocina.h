/*
    Se define como TAD Cocina a una secuencia de muebles colocados en la pared. Un mueble es un objeto ya insertado en la pared y se representa por su anchura y su posición. 
    Anchura define la longitud del mueble y posicion la distancia desde el lado izquierdo del mueble hasta la esquina izquierda de la pared. 
    La cocina además tiene una longitud que se define como lo que ocupa de largo, determina los muebles que se podrán colocar y cuántos de ellos. 

    OPERACIONES
    Cocina(size_t l);   Construye la cocina, definiendo l como la longitud de la pared.
    bool pos_valida(size_t posicion,size_t anchura) const; Devuelve [posicion,posicion+anchura]!=x.posicion, siendo x cualquier mueble de la cocina.
    void insertar_mueble(size_t posicion, size_t anchura); PRECONDICION: pos_valida(posicion,anchura)==true; Añade un mueble a la pared.
    const Mueble& mostrar_mueble(size_t i) const; PRECONDICIÓN: i <= numero muebles ; Devuelve el mueble i-ésimo de la pared.
    void eliminar_mueble(size_t i); PRECONDICIÓN: i <= numero muebles ; Elimina el mueble de la pared, dejando libre el espacio que ocupaba.
    void mover_mueble(size_t i); PRECONDICIÓN: i <= numero de muebles ; Desplaza el mueble i-ésimo de la pared al lado derecho del mueble anterior o a la esquina izquierda de la pared si no hay mueble anterior.
*/
#ifndef TAD_COCINA_H
#define TAD_COCINA_H
#include "..\TAD_Lista\lista_c2e.h"
class Cocina
{
    public:
        struct Mueble{
            size_t posicion;
            size_t anchura;
            Mueble(size_t p,size_t a) : posicion(p),anchura(a) {}
        };
        Cocina(size_t L);
        size_t n_muebles() const;
        bool pos_valida(size_t posicion,size_t anchura) const;
        const Mueble& mostrar_mueble(size_t i) const;
        void insertar_mueble(size_t posicion, size_t anchura);
        void eliminar_mueble(size_t i);
        void mover_mueble(size_t i);
    private:
        Lista<Mueble> L;
        Lista<Mueble>::posicion buscar_mueble(size_t i) const;
        size_t longitud;//Longitud de la pared
};
#endif