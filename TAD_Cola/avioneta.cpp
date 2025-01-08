#include <cstddef>
#include <string>
#include <iostream>
#include "cola_ce.h"
#include "cola_ps.h"
#include "avioneta.h"
void entrada_avion(aerodromo& aero,const std::string& matricula);
void salida_avion(aerodromo& aero,const std::string matricula);
void estacionar_avioneta(aerodromo &aero,code_accion codigo,const std::string &matricula)
{
    if (codigo==ENTRADA||codigo==SALIDA)
    {
        if (codigo==ENTRADA)
            entrada_avion(aero,matricula);
        else
            salida_avion(aero,matricula);
    }
    else
    {
        std::cout << "El codigo introducido no es correcto.";
    }

}
void entrada_avion(aerodromo& aero,const std::string& matricula)
{
    if (aero.estacionamiento.tama()<aero.estacionamiento.tamaMax())
    {
        aero.estacionamiento.push(matricula);
    }
    else
    {
        aero.hangar.push(matricula);
    }
}
void salida_avion(aerodromo& aero,const std::string matricula)
{
    int i=0;
    std::string aux;
    while (i<=aero.estacionamiento.tama()&&aero.estacionamiento.frente()!=matricula)
    {
        aux=aero.estacionamiento.frente();
        aero.estacionamiento.pop();
        aero.estacionamiento.push(aux);
        i++;
    }
    if (aero.estacionamiento.frente()==matricula)
    {
        aero.estacionamiento.pop();
        std::cout << "El avion ha salido del estacionamiento con exito";
    }
    else
    {
        i=0;
        while (i<=aero.hangar.tama()&&aero.hangar.frente()!=matricula)
        {
            aux=aero.hangar.frente();
            aero.hangar.pop();
            aero.hangar.push(aux);
            i++;
        }
        if (aero.hangar.frente()==matricula)
        {
            aero.hangar.pop();
            std::cout << "El avion ha salido del hangar con exito";
        }
        else
        {
            std::cout << "No se ha encontrado el avion";
        }
    }
}