#include <cassert>
#include <cstring>
#include "TAD_TokenBus.h"
TokenBus::Identificador::Identificador(const char *c) : id()
{
    strcpy(id,c);
}

TokenBus::TokenBus(const Identificador& id)
{
    
}