#ifndef AVIONETA_H
#define AVIONETA_H
struct aerodromo{
    Cola<std::string> estacionamiento;
    Cola<std::string> hangar;//Cola donde estan los aviones esperando a que haya un sitio libre en estacionamiento.
};
enum code_accion{ENTRADA,SALIDA};
void estacionar_avioneta(const aerodromo &aero,code_accion,const std::string &matricula);
#endif