/*
    Un Gestor de Impresión es una secuencia de trabajos a operar.
    Un trabajo es un elemento del Gestor que tiene asociado un usuario e identificador y tiene dos tipos de prioridad, urgente o no urgente.
    Un usuario es un número al que se le asocian los trabajos y determinará el orden en el que se operan.
    Este número tiene valores desde 1 hasta n, donde n es el número máximo de usuarios que pueden tener uno o más trabajos simultáneamente en el gestor.

    Los trabajos se operan uno por uno, y cuando el trabajo se opera, este se elimina del gestor.
    El orden en el que los trabajos se operan dependen del usuario asociado y de su prioridad.
    Para determinar el trabajo a operar, se escogen los trabajos del usuario que lleve más tiempo desde que se insertó su primer trabajo o desde que se operó su último trabajo, lo que haya pasado después.
    Entre esos trabajos se operará el trabajo urgente con más tiempo en el gestor, y si no lo hay, el trabajo no urgente con más tiempo en el gestor.

    Operaciones:
        GestorImpresion(size_t n=0); Crea un gestor de impresion que puede almacenar trabajos de hasta n usuarios
        void insertar_trabajo(size_t usuario,const std::string& identificador,Prioridad p);   Precondición: 1 <= usuario <= n y trabajo no es igual en ningún trabajo del gestor
                                                                                            Añade un trabajo con el identificador y la prioridad introducidas, asociado a usuario.
        void eliminar_trabajo();    Precondición: El gestor tiene al menos un trabajo.
                                    Elimina el trabajo a operar.
        void cancelar_trabajos(size_t usuario)  Precondición: 1 <= usuario <= n
                                                Elimina del gestor todos los trabajos del usuario, si los hay.  
*/

#ifndef TAD_GESTORIMPRESION_H
#define TAD_GESTORIMPRESION_H
#include "..\TAD_Cola\cola_ce.h"
#include <string>
class GestorImpresion{
    public:
        enum Prioridad{URGENTE,NO_URGENTE};
        GestorImpresion(size_t n=0);
        void eliminar_trabajo();
        void insertar_trabajo(size_t usuario, const std::string& identificador,Prioridad p);
        void cancelar_trabajos(size_t usuario);
        //Requeridos por la implementación
        GestorImpresion(const GestorImpresion& g);
        GestorImpresion& operator =(const GestorImpresion& g);
        ~GestorImpresion();
    private:
        typedef std::string Trabajo;
        struct Usuario{
            Cola_ce<Trabajo> urgente;
            Cola_ce<Trabajo> no_urgente;
            Usuario(): urgente(), no_urgente() {}
        };
        size_t NMax;//Tamaño máximo del gestor
        Usuario * U;//Vector que almacena los usuarios
        Cola_ce<size_t> turno;//Cola que determina el usuario del siguiente trabajo a operar
        bool tiene_trabajos(size_t usuario); //Devuelve true si hay un trabajo U[usuario]
};
#endif