#include <cstddef>
#include <cassert>
#include "TAD_Cocina.h"

Lista<Cocina::Mueble>::posicion Cocina::buscar_mueble(size_t i) const
{
    Lista<Mueble>::posicion p=L.primera();
    for (size_t j=1;j<i&&p!=L.fin();j++)
    {
        p=L.siguiente(p);
    }
    return p;
}

Cocina::Cocina(size_t lon) : L(),longitud(lon)
{}

size_t Cocina::n_muebles() const
{
    return L.tama();
}

bool Cocina::pos_valida(size_t posicion, size_t anchura) const
{
    
    

        Lista<Mueble>::posicion p=L.primera();
        while (p!=L.fin()&&posicion<L.elemento(p).posicion) //Hasta llegar a fin o al primer elemento cuya posicion sea mayor o igual a posicion
        {
            p=L.siguiente(p);
        }
        if (p==L.fin())
            return (posicion+anchura)<=longitud;
        else
            return (posicion+anchura)<=L.elemento(p).posicion;
    
}

const Cocina::Mueble& Cocina::mostrar_mueble(size_t i) const
{
    assert(i<=L.tama());
    Lista<Mueble>::posicion p=buscar_mueble(i);
    return L.elemento(p);
}

void Cocina::insertar_mueble(size_t posicion,size_t anchura)
{
    //assert(pos_valida(posicion,anchura));


        Lista<Mueble>::posicion p;
        while (p!=L.fin()&&posicion<L.elemento(p).posicion)
        {
            p=L.siguiente(p);
        }
        L.insertar(Mueble(posicion,anchura),p);
}

void Cocina::eliminar_mueble(size_t i)
{
    assert(i<=L.tama());
    Lista<Mueble>::posicion p=buscar_mueble(i);
    L.eliminar(p);
}

void Cocina::mover_mueble(size_t i)
{
    assert(i<=L.tama());
    Lista<Mueble>::posicion p=buscar_mueble(i);
    if (p==L.primera())
    {
        L.elemento(p).posicion=0;
    }
    else
    {
        L.elemento(p).posicion=L.elemento(p).posicion+L.elemento(p).anchura;
    }
}