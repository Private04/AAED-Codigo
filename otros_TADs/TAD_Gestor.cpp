#include <cassert>
#include "TAD_Gestor.h"

GestorImpresion::GestorImpresion(size_t n) : NMax(n), turno()
{
    U=new Usuario[NMax];
}
bool GestorImpresion::tiene_trabajos(size_t usuario)
{
    return !(U[usuario].no_urgente.vacia()&&U[usuario].urgente.vacia());
}
void GestorImpresion::insertar_trabajo(size_t usuario, const std::string& identificador,Prioridad p)
{
    assert(usuario>=1&&usuario<=NMax);
    usuario--;//Ajustar el valor al vector
    if(!tiene_trabajos(usuario))
    {
        turno.push(usuario);
    }
    if (p==URGENTE)
    {
        U[usuario].urgente.push(identificador);
    }
    else
    {
        U[usuario].no_urgente.push(identificador);
    }
}

void GestorImpresion::eliminar_trabajo()
{
    assert(!turno.vacia());
    size_t usuario=turno.frente();
    turno.pop();
    if (!U[usuario].urgente.vacia())
    {
        U[usuario].urgente.pop();
    }
    else
    {
        U[usuario].no_urgente.pop();
    }
}

void GestorImpresion::cancelar_trabajos(size_t usuario)
{
    assert(1<=usuario&&usuario<=NMax);
    usuario--;
    if (tiene_trabajos(usuario));
    {
        Cola_ce<Trabajo> aux;//Las colas de urgente y no_urgente serán copias de esta cola vacia
        while(turno.frente()!=usuario)
        {
            turno.push(turno.frente());
            turno.pop();
        }
        turno.pop();
        U[usuario].no_urgente=U[usuario].urgente=aux;
    }
}

GestorImpresion::GestorImpresion(const GestorImpresion& g) : NMax(g.NMax), turno(g.turno)
{
    U=new Usuario[g.NMax];
    for (size_t i=0;i<g.NMax;i++)
    {
        U[i]=g.U[i];
    }
}

GestorImpresion& GestorImpresion::operator=(const GestorImpresion& g)
{
    if (U!=g.U)//Si son distintos gestores
    {
        GestorImpresion aux(g);
        //Intercambio del vector
        Usuario * aux_U=U;
        U=aux.U;
        aux.U=aux_U;

        NMax=aux.NMax;
        turno=aux.turno;
    }
    return *this; //Borra aux con el puntero previo de this
}

GestorImpresion::~GestorImpresion()
{
    delete [] U;
    NMax=0;
}