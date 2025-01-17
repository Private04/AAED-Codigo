#include <cassert>
#include "TAD_Consultorio.h"

Consultorio::Consultorio() : L()
{}

void Consultorio::alta_medico(Consultorio::Medico medico)
{
    L.insertar(ColaEspera(medico),L.fin());
}

void Consultorio::baja_medico(Consultorio::Medico medico)
{
    Lista<ColaEspera>::posicion p=buscar_medico(medico);
    if (p!=L.fin())
    {
        L.eliminar(p);
    }
}

Lista<Consultorio::ColaEspera>::posicion Consultorio::buscar_medico(Consultorio::Medico medico) const
{
    Lista<ColaEspera>::posicion p=L.primera();
    while (p!=L.fin()&&L.elemento(p).id_medico!=medico)
    {
        p=L.siguiente(p);
    }
    return p;
}

void Consultorio::insertar_paciente(Consultorio::Paciente paciente,Consultorio::Medico medico)
{
    Lista<ColaEspera>::posicion p=buscar_medico(medico);
    if (p!=L.fin())
    {
        L.elemento(p).cola_pacientes.push(paciente);
    }
}

Consultorio::Paciente Consultorio::sig_paciente(Consultorio::Medico medico) const
{
    Lista<ColaEspera>::posicion p=buscar_medico(medico);
    assert(!L.elemento(p).cola_pacientes.vacia());
    return L.elemento(p).cola_pacientes.frente();
}

void Consultorio::atender_paciente(Consultorio::Medico medico)
{
    Lista<ColaEspera>::posicion p=buscar_medico(medico);
    assert(!L.elemento(p).cola_pacientes.vacia());
    L.elemento(p).cola_pacientes.pop();
}

bool Consultorio::espera_vacia(Consultorio::Medico medico) const
{
    Lista<ColaEspera>::posicion p=buscar_medico(medico);
    return L.elemento(p).cola_pacientes.vacia();
}

bool Consultorio::medico_en_consultorio (Consultorio::Medico medico) const
{
    Lista<ColaEspera>::posicion p=buscar_medico(medico);
    return p!=L.fin();
}