#ifndef AVIONETA_H
#define AVIONETA_H
struct aerodromo{
    Cola_ps<std::string> estacionamiento;
    Cola_ce<std::string> hangar;//Cola donde estan los aviones esperando a que haya un sitio libre en estacionamiento.
};
enum code_accion{ENTRADA,SALIDA};
void estacionar_avioneta(aerodromo &aero,code_accion codigo,const std::string &matricula);
#endif