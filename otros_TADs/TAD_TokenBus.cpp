#include <cassert>
#include <cstring>
#include "TAD_TokenBus.h"
TokenBus::Identificador::Identificador(const char *c) : id()
{
    strcpy(id,c);
}

TokenBus::TokenBus(const Identificador& id) : L()
{
    L.insertar(id,L.fin());
    testigo=L.primera();
}

const TokenBus::Identificador& TokenBus::token() const
{
    return L.elemento(testigo);
}

void TokenBus::insertar_ordenador(const Identificador& id)
{
    assert(L.tama()<MaxOrdenadores);
    L.insertar(id,L.fin());
}

void TokenBus::eliminar_ordenador()
{
    assert(L.tama()>1);
    L.eliminar(L.primera());
}

void TokenBus::pasar_token()
{
    testigo=L.siguiente(testigo);
    if(testigo==L.fin())
    {
        testigo=L.primera();
    }
}

void TokenBus::enviar_trama(const Identificador& b,const Trama t)
{
    while(b.id!=L.elemento(testigo).id)
    {
        pasar_token();
    }
    /*Operar la trama*/
}