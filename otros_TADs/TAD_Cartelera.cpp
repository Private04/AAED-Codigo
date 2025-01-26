#include <cassert>
#include "TAD_Cartelera.h"

Cartelera::Cartelera(): L()
{}

Lista<Cartelera::Sala>::posicion Cartelera::buscar_sala(Identificador id) const
{
    Lista<Sala>::posicion pos=L.primera();
    while(pos!=L.fin()&&id!=L.elemento(pos).id)
    {
        pos=L.siguiente(pos);
    }
    return pos;
}

Lista<Cartelera::Identificador>::posicion Cartelera::buscar_espectaculo(Identificador id,Lista<Sala>::posicion pos_sala) const
{
    Lista<Identificador>::posicion pos_espectaculo=L.elemento(pos_sala).espectaculos.primera();
    while(pos_espectaculo!=L.elemento(pos_sala).espectaculos.fin()&&id!=L.elemento(pos_sala).espectaculos.elemento(pos_espectaculo))
    {
        pos_espectaculo=L.elemento(pos_sala).espectaculos.siguiente(pos_espectaculo);
    }
    return pos_espectaculo;
}

void Cartelera::insertar_sala(Identificador id)
{
    L.insertar(Sala(id),L.fin());
}

void Cartelera::insertar_espectaculo(Identificador id_espectaculo,Identificador id_sala)
{
    Lista<Sala>::posicion pos_sala=buscar_sala(id_sala);
    if (pos_sala!=L.fin())
    {
        L.elemento(pos_sala).espectaculos.insertar(id_espectaculo,L.elemento(pos_sala).espectaculos.fin());
    }
}

void Cartelera::eliminar_sala(Identificador id_sala)
{
    Lista<Sala>::posicion pos_sala=buscar_sala(id_sala);
    if (pos_sala!=L.fin())
    {
        L.eliminar(pos_sala);
    }
}

void Cartelera::eliminar_espectaculo(Identificador id_sala,Identificador id_espectaculo)
{
    Lista<Sala>::posicion pos_sala=buscar_sala(id_sala);
    Lista<Identificador>::posicion pos_espectaculo;
    if(pos_sala!=L.fin())
    {
        pos_espectaculo=buscar_espectaculo(id_espectaculo,pos_sala);
        if(pos_espectaculo!=L.elemento(pos_sala).espectaculos.fin())
        {
            L.elemento(pos_sala).espectaculos.eliminar(pos_espectaculo);
        }
    }
}