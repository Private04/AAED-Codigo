/*
    Un TokenBus es una secuencia ordenada y circular de ordenadores denominada anillo y un indicador llamado token.

    Un ordenador es un elemento capaz de realizar las tareas de pasar el token, enviar trama y recibir trama, dependiendo del token.
    Un ordenador en un anillo se identifica por su identificador, una cadena de hasta 8 carácteres, la cual es única en cada ordenador.
    Hay un máximo de 25 ordenadores en el anillo.

    Cada ordenador del anillo tiene un ordenador siguiente y un ordenador anterior.
    El orden del anillo es por llegada, el ordenador con más tiempo en el anillo tendrá como siguiente el 2º ordenador con más tiempo, etcétera.
    El ordenador anterior a otro es el siguiente más reciente a este.
    Las únicas excepciones son el ordenador más reciente, cuyo siguiente es el ordenador más antiguo, y el ordenador más antiguo, cuyo anterior es el ordenador más reciente.

    El token de un TokenBus es un permiso que obtiene un solo ordenador del anillo y le permite realizar las tareas previamente mencionadas, las cuales son:
        Pasar token: El token se pasa al siguiente ordenador, revocando los privilegios de operación a este y otorgándoselos al siguiente.
        Envíar trama: Envía una trama al anillo, permitiendo que pueda ser recibida por un ordenador del anillo. Esta tarea pasa el token una vez finalizada.
        Recibir trama: Si hay una trama en el anillo, el ordenador puede recibir la trama, eliminándola del anillo.

    Operaciones:
        Constructora:
            TokenBus(const Identificador& id); Crea un anillo de un ordenador con identificador determinado.
        Observadora:
            const Identificador& token() const; Devuelve el identificador del ordenador que actualmente posee el token.
        Modificadoras:
            void insertar_ordenador(const Identificador& id); PRECONDICIÓN: El identificador no representa ningún ordenador del anillo y el número de computadoes en el anillo es menor a 25.
                                                                Añade un ordenador al anillo.
            void eliminar_ordenador();  PRECONDICIÓN: El número de ordenadores en el anillo es mayor estricto que 1.
                                        Elimina el ordenador más antiguo del anillo.
            void pasar_token(); El ordenador con el token realiza la tarea de pasar token.
            void envíar_trama(const Identificador& b,const Trama& t); PRECONDICIÓN: b está en el anillo
                                                                      El ordenador con el token envía una trama, y los demás ordenadores pasarán el token hasta que llegue al ordenador b, el cual la recibe y se adueña del token.
    
*/
#ifndef TAD_TOKENBUS_H
#define TAD_TOKENBUS_H
#include "../TAD_Lista/lista_c1e.h"//También se puede usar lista circular, pero como no la dejan en el examen, uso esta.
typedef int Trama;//No necesario en el examen, es para que compile.
class TokenBus{
    public:
        struct Identificador{
            char id[9];
            Identificador(const char *c);//Precondición, c es una cadena de 8 o menos caracteres con carácter nulo al final.
        };
        TokenBus(const Identificador& id);
        const Identificador& token() const;
        void insertar_ordenador(const Identificador& id);
        void eliminar_ordenador();
        void pasar_token();
        void enviar_trama(const Identificador& b,const Trama t);
    private:
        Lista<Identificador> L;
        Lista<Identificador>::posicion testigo;
        static const size_t MaxOrdenadores=25;
};
#endif