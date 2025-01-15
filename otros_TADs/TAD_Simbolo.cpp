#include "TAD_Simbolo.h"
Simbolo::Simbolo() : L()
{}

size_t Simbolo::tama() const
{
    return L.tama();
}

void Simbolo::insertar_trazo(Trazo T)
{
    L.insertar(T,L.primera());
}

void Simbolo::deshacer_trazo(size_t n)
{
    assert(n<=tama());
    for (size_t i=1;i<=n;i++)
    {
        L.eliminar(L.primera());
    }
}

Simbolo Simbolo::simetrico_x()
{
    Lista<Trazo>::posicion p_this=L.primera();//Posicion para recorrer this.L
    Simbolo sim;
    while(p_this!=L.fin())
    {
        switch (L.elemento(p_this))
        {
            case ARRIBA:
                sim.L.insertar(ABAJO,sim.L.fin());
                break;
            case ABAJO:
                sim.L.insertar(ARRIBA,sim.L.fin());
                break;
            default:
                sim.L.insertar(L.elemento(p_this),sim.L.fin());
        }
        p_this=L.siguiente(p_this);
    }
    return sim;
}

Simbolo Simbolo::simetrico_y()
{
    Lista<Trazo>::posicion p_this=L.primera();//Posicion para recorrer this.L
    Simbolo sim;
    while(p_this!=L.fin())
    {
        switch (L.elemento(p_this))
        {
            case DERECHA:
                sim.L.insertar(IZQUIERDA,sim.L.fin());
                break;
            case IZQUIERDA:
                sim.L.insertar(DERECHA,sim.L.fin());
                break;
            default:
                sim.L.insertar(L.elemento(p_this),sim.L.fin());
        }
        p_this=L.siguiente(p_this);
    }
    return sim;
}

Simbolo Simbolo::simetrico_xy()
{
    Lista<Trazo>::posicion p_this=L.primera();//Posicion para recorrer this.L
    Simbolo sim;
    while(p_this!=L.fin())
    {
        switch (L.elemento(p_this))
        {
            case ARRIBA:
                sim.L.insertar(ABAJO,sim.L.fin());
                break;
            case ABAJO:
                sim.L.insertar(ARRIBA,sim.L.fin());
                break;
            case DERECHA:
                sim.L.insertar(IZQUIERDA,sim.L.fin());
                break;
            case IZQUIERDA:
                sim.L.insertar(DERECHA,sim.L.fin());
                break;
        }
        p_this=L.siguiente(p_this);
    }
    return sim;
}