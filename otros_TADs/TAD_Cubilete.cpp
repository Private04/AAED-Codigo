#include "TAD_Cubilete.h"
Pila<tCubo> apilacion(Pila<tCubo> base)
{
    Pila<tCubo> res(base.tama());//Parametro a devolver
    Pila<tCubo> aux(base.tama());//Pila para realizar el proceso de buscar
    while(!base.vacia())
    {
        if (res.vacia()||base.tope().tama>res.tope().tama)//Si la pila res esta vacia o su tope es menor o igual que el elemento a insertar, se inserta primero el elemento y luego la pila aux
        {
            res.push(tCubo(base.tope().tama,tCubo::eEstado::BOCA_ABAJO));
            base.pop();
            while (!aux.vacia())
            {
                res.push(aux.tope());
                aux.pop();
            }
        }
        else//Si no, se saca el tope de res, se guarda en aux y se vuelve a comprobar
        {
            aux.push(res.tope());
            res.pop();
        }
    }
    return res;
}