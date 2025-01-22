#include <cassert>
#include "TAD_LineaCajas.h"

LineaCajas::LineaCajas() : cajas()
{}

int LineaCajas::cerrar_caja(int caja)
{
    assert(cajas[caja-1].estado==Caja::ABIERTO);
    int contador;
    cajas[caja-1].estado=Caja::CERRADO;
    contador=cajas[caja-1].facturacion;
    cajas[caja-1].facturacion=0;
    return contador;
}

void LineaCajas::cobrar_cliente(int caja,int importe)
{
    assert(caja<=MaxCajas);
    cajas[caja-1].facturacion+=importe;
}

void LineaCajas::abrir_caja(Cajero c,int caja)
{
    assert(cajas[caja-1].estado==Caja::CERRADO);
    cajas[caja-1].estado=Caja::ABIERTO;
    cajas[caja-1].cajero=c;
    //facturacion ya está a 0
}

void LineaCajas::sustituir_cajero(int caja,Cajero c)
{
    assert(cajas[caja-1].estado==Caja::ABIERTO);
    cajas[caja-1].cajero=c;
}

int LineaCajas::cambiar_turno(const Cajero *c,int n)
{
    assert(n<=50&&0<=n);
    int contador=0;//Contador de la facturación de las cajas
    int i;
    for (i=0;i<n;i++)//Abrir caja por cada elemento en c
    {
        if (cajas[i].estado==Caja::ABIERTO)
        {
            contador+=cajas[i].facturacion;
        }
        cajas[i].estado=Caja::ABIERTO;
        cajas[i].cajero=c[i];
        cajas[i].facturacion=0;
    }
    for(i;i<MaxCajas;i++)//Cerrar las demás cajas
    {
        if (cajas[i].estado==Caja::ABIERTO)
        {
            cajas[i].estado=Caja::CERRADO;
            contador+=cajas[i].facturacion;
            cajas[i].facturacion=0;
        }
    }
    return contador;
}

int LineaCajas::cierre()
{
    int contador;//Contador de la facturación de las cajas
    for (int i=0;i<MaxCajas;i++)
    {
        if (cajas[i].estado==Caja::ABIERTO)
        {
            cajas[i].estado=Caja::CERRADO;
            contador+=cajas[i].facturacion;
            cajas[i].facturacion=0;
        }
    }
    return contador;
}