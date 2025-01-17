/*
    Un consultorio es una agrupación de un número arbitrario de colas de espera.
    Una cola de espera es una secuencia de un número arbitrario de pacientes, representados por un identificador, el cual es un entero, pendientes de ser atendidos 
    y que son identificadas dentro del consultorio mediante el nombre del médico, también representado mediante un identificador entero, que atenderá a los pacientes.
    Los pacientes se atienden en orden de llegada, siendo el paciente que se haya puesto en la cola con mayor anterioridad el siguiente a ser atendido.
    Solo un medico puede tener asociada una cola de espera.

    OPERACIONES:
    Consultorio() Crea un consultorio vacío, con 0 colas de espera.
    void alta_medico(Medico medico); PRECONDICIÖN: medico es una cadena que no representa ninguna cola de espera dentro del consultorio.
                                          Crea una cola de espera asociada a medico y la inserta en consultorio
    void baja_medico(Medico medico); Elimina la cola de espera dentro del consultorio asociada a medico. Si no existe, no hace nada.
    void insertar_paciente(Paciente paciente,Medico medico); Inserta paciente en la cola de espera asociada a medico. Si ninguna cola del consultorio esta asociada a medico, no hace nada.
    Paciente sig_paciente(Medico medico) const; PRECONDICIÓN: medico tiene asociada una cola de espera en el consultorio y dicha cola no está vacía. 
                                                        Devuelve el nombre del paciente siguiente a ser atendido en la cola de espera de medico.
    void atender_paciente(Medico medico); PRECONDICIÓN: medico tiene asociada una cola de espera en el consultorio y dicha cola no está vacía.
                                               Elimina de la cola de espera asociada a medico el paciente a ser atendido.
    bool espera_vacia(Medico medico) const; PRECONDICIÓN: medico tiene asociada una cola de espera en el consultorio.
                                                 Devuelve true si no hay ningún paciente en la cola de espera asociada a medico.
    bool medico_en _consultorio(Medico medico) const; Devuelve true si hay una cola de espera en el consultorio asociada a medico
*/
#ifndef TAD_CONSULTORIO_H
#define TAD_CONSULTORIO_H
#include "..\TAD_Lista\lista_c1e.h"
#include "..\TAD_Cola\cola_ce.h"

class Consultorio{
    public:
        typedef int Medico; 
        typedef int Paciente;
        Consultorio();
        void alta_medico(Medico medico);
        void baja_medico(Medico medico);
        void insertar_paciente(Paciente paciente,Medico medico);
        Paciente sig_paciente(Medico medico) const;
        void atender_paciente(Medico medico);
        bool espera_vacia(Medico medico) const;
        bool medico_en_consultorio(Medico medico) const;
    private:
        struct ColaEspera{
            Medico id_medico;
            Cola_ce<Paciente> cola_pacientes;
            ColaEspera(int med=0) : id_medico(med),cola_pacientes() {}
        };
        Lista<ColaEspera>::posicion buscar_medico(Medico medico) const;
        Lista<ColaEspera> L;
};

#endif