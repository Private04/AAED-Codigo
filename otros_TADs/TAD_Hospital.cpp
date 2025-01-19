#include "TAD_Hospital.h"
#include <cassert>

Hospital::Hospital(size_t n_uci,size_t n_planta) :
uci(),planta(),MaxPlanta(n_planta),MaxUci(n_uci)
{
    for (size_t i=0;i<=8;i++)
    {
        n_gravedad[i]=0;
    }
}

void Hospital::ingreso(const Hospital::Paciente& p)
{
    assert(p.gravedad!=0);
    if (p.gravedad<6)
    {
        if(planta.tama()==MaxPlanta)//Si planta esta llena, se da el alta al paciente mas leve
        {
            n_gravedad[planta.elemento(planta.primera()).id-1]--;//Se decrementa el contador del paciente a dar el alta
            planta.eliminar(planta.primera());  
        }
        insertar_planta(p);
    }
    else
    {
        if(uci.tama()==MaxUci)//Si uci esta llena, se mueve el paciente mas leve a planta
        {
            if(planta.tama()==MaxPlanta)//Si ademas planta esta llena se da de alta al paciente mas leev
            {
                n_gravedad[planta.elemento(planta.primera()).id-1]--;
                planta.eliminar(planta.primera());
            }
            insertar_planta(uci.elemento(uci.primera()));//De todas formas se mueve a planta
            uci.eliminar(uci.primera());
        }
        insertar_uci(p);
    }
    n_gravedad[p.gravedad-1]++;//Incrementa el contador de pacientes con dicha gravedad
}

void Hospital::alta(const Hospital::Paciente& p)
{
    Lista<Paciente>::posicion pos=buscar_planta(p);
    if (pos!=planta.fin())
    {
        n_gravedad[p.gravedad-1]--;
        planta.eliminar(pos);
    }
    else
    {
        pos=buscar_uci(p);
        if (pos!=uci.fin())
        {
            n_gravedad[p.gravedad-1]--;
            uci.eliminar(pos);
        }
    }
}

void Hospital::muerte(const Paciente& p)
{
    alta(p);
}

size_t Hospital::pacientes_uci() const
{
    return uci.tama();
}

size_t Hospital::pacientes_planta() const
{
    return planta.tama();
}

size_t Hospital::pacientes_gravedad(size_t gravedad)
{
    return n_gravedad[gravedad-1];
}

Lista<Hospital::Paciente>::posicion Hospital::buscar_uci(const Hospital::Paciente& p) const
{
    Lista<Paciente>::posicion pos=uci.primera();
    while(pos!=uci.fin()&&uci.elemento(pos).id!=p.id)
    {
        pos=uci.siguiente(pos);
    }
    return pos;
}

Lista<Hospital::Paciente>::posicion Hospital::buscar_planta(const Hospital::Paciente& p) const
{
    Lista<Paciente>::posicion pos=planta.primera();
    while(pos!=planta.fin()&&planta.elemento(pos).id!=p.id)
    {
        pos=planta.siguiente(pos);
    }
    return pos;
}

void Hospital::insertar_planta(const Paciente& p)
{
    Lista<Paciente>::posicion pos=planta.primera();
    while (pos!=planta.fin()&&planta.elemento(pos).gravedad<p.gravedad)//Hasta el fin de la lista o hasta el primer elmento de la lista con numero de gravedad inferior a p
    {
        pos=planta.siguiente(pos);
    }
    planta.insertar(p,pos);
}

void Hospital::insertar_uci(const Paciente& p)
{
    Lista<Paciente>::posicion pos=uci.primera();
    while (pos!=uci.fin()&&uci.elemento(pos).gravedad<p.gravedad)
    {
        pos=uci.siguiente(pos);
    }
    uci.insertar(p,pos);
}