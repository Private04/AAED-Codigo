/*  ESPECIFICACIÓN
Se define un Tren como una secuencia de un número arbitrario de vagones. 
Cada vagón del tren tiene un vagón del tren asociado a la izquierda, excepto uno denominado primero, y un vagón a la derecha, excepto uno denominado último.
Siempre que haya al menos un vagón en el tren, hay un vagón denominado activo y las operaciones del tren se realizarán en base a este.

OPERACIONES

Constructora:
    Tren() : Crea un tren vacío de 0 vagones.

Observadoras:
    bool vacio() const; Devuelve true si hay 0 vagones y false si no.
    const vagon& activo() const; PRECONDICIÓN: Tren no está vacío ; Devuelve el vagón activo del tren

Modificadoras:
    void despl_izquierda(); PRECONDICIÓN: Tren no está vacío ; Convierte en vagón activo el vagón a la derecha al activo. Si no hay vagón a la derecha, no hace nada
    void despl_derecha(); PRECONDICIÓN: Tren no está vacío ; Convierte en vagón activo el vagón a la izquierda del activo. Si no hay vagón a la izquierda, no hace nada.
    void insertar_activo(const vagon& v); Inserta v en el tren, convirtiéndose en el vagón activo. Si ya había un vagón activo, el previamente activo se convierte en el derecho del nuevo
    void eliminar_activo(); PRECONDICIÓN: Tren no está vacío ; Elimina el vagón activo del tren, pasándo el vagón de su derecha a ser el activo. Si no hay vagón a su derecha, el de la izquierda 
                                                               es el activo, y si no hay, entonces el tren pasa a estar vacío.
*/

#ifndef TAD_TREN_H
#define TAD_TREN_H
#include <cassert>
#include "..\TAD_Pila\pila_ce.h"
typedef int Vagon;//NO NECESARIA, ES PARA QUE COMPILE
class Tren{
    public:
        Tren();
        bool vacio() const;
        const Vagon& activo() const;
        void despl_izquierda();
        void despl_derecha();
        void insertar_activo(const Vagon& v);
        void eliminar_activo();
    private:
        Pila<Vagon> anterior;//Esta pila está formada por los vagones a la izquierda del activo
        Pila<Vagon> siguientes;//El tope de esta pila es el vagón activo seguido de los vagones a la derecha
};
#endif