#include "TAD_Tren.h"

Tren::Tren() : anterior(),siguientes()
{}

bool Tren::vacio() const
{
    return siguientes.vacia();
}

const Vagon& Tren::activo() const
{
    assert(!vacio());
    return siguientes.tope();
}

void Tren::despl_derecha()
{
    assert(!vacio());
    if (!anterior.vacia())
    {
        siguientes.push(anterior.tope());
        anterior.pop();
    }
}

void Tren::despl_izquierda()
{
    assert(!vacio());
    if (siguientes.tama()>1)//El activo tiene siguiente?
    {
        anterior.push(siguientes.tope());
        siguientes.pop();
    }
}

void Tren::insertar_activo(const Vagon& v)
{
    siguientes.push(v);
}

void Tren::eliminar_activo()
{
    assert(!vacio);
    siguientes.pop();
    if (siguientes.vacia()&&!anterior.vacia())//El activo no tiene siguiente pero si anterior?
    {
        siguientes.push(anterior.tope());
        anterior.pop();
    }
}