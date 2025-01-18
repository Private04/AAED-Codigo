/*
    Se define TAD Hospital como dos agrupaciones de pacientes, denominados UCI y Planta.
    Un paciente es un elemento del hospital formado por su id, representado como un entero, y su gravedad, un entero
    que puede tomar valores entre 0 y 9, siendo 1 el máximo estado de gravedad y 9 el mínimo. El valor 0 se usa para representar el estado muerto del paciente.

    OPERACIONES:
    Hospital(size_t n_uci,size_t n_planta) Crea un hospital vacío cuyo tamaño maximo de UCI es n_uci y Planta, n_planta
    void ingreso(const Paciente& p) Precondición: p.gravedad!=0
                                Inserta p en la agrupación del Hospital siguiendo el siguiente criterio:
                                    -Si p.gravedad<6: p se inserta en Planta.
                                        -Si Planta está llena, se elimina el paciente con menor gravedad en Planta para hacer espacio a p.
                                    -Si p.gravedad>=6: p se inserta en UCI.
                                        -Si UCI está llena, se pasa el paciente con menor gravedad a Planta, eliminándolo de UCI e insertándolo en planta siguiendo el criterio anterior.
    void alta(const Paciente& p) Elimina al paciente de id p.id del hospital, dondequiera que esté. Si no está, esta función no hace nada.
                                 Si el paciente eliminado es de la UCI y hay un paciente de gravedad entre 1 y 5 en planta, este se ingresa a planta.
    void muerte(const Paciente& p) Elimina al paciente de id p.id del hospital, dondequiera que esté. Si no está, esta función no hace nada.
                                   Si el paciente eliminado es de la UCI y hay un paciente de gravedad entre 1 y 5 en planta, este se ingresa a planta.
    size_t pacientes_uci() const; Devuelve el número de pacientes en UCI.
    size_t pacientes_planta() const; Devuelve el número de pacientes en Planta.
    size_t pacientes_gravedad(size_t gravedad) const; Devuelve el número de pacientes de una gravedad determinada
*/

#ifndef TAD_HOSPITAL_H
#define TAD_HOSPITAL_H
#include "..\TAD_Lista\lista_c1e.h"
class Hospital{
    public:
        struct Paciente{
            size_t id;
            size_t gravedad;
            Paciente(size_t ident=0,size_t grav=0) : id(ident),gravedad(grav) {} 
        };
        Hospital(size_t n_uci,size_t n_planta);
        void ingreso(const Paciente& p);
        void alta(const Paciente& p);
        void muerte(const Paciente& p);
        size_t pacientes_uci() const;
        size_t pacientes_planta() const;
        size_t pacientes_gravedad(size_t gravedad);
    private:
        Lista<Paciente> uci;//Lista de pacientes en UCI
        Lista<Paciente> planta;//Lista de pacientes en Planta
        size_t MaxPlanta,MaxUci;//Tamaño máximo de pacientes en planta y pacientes en la uci
        size_t n_gravedad[9];//Contador de pacientes para cada gravedad en el hospital
        Lista<Paciente>::posicion buscar_uci(const Paciente& p);
        Lista<Paciente>::posicion buscar_planta(const Paciente& p);
};
#endif