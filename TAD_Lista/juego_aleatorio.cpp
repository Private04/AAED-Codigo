#include <string>
#include <cassert>

#include "juego_aleatorio.h"
/*En una variante de un juego bastante conocido, n jugadores, identificados por su nombre,
se sitúan en círculo y se les asigna aleatoriamente un número del 1 al 6 (obviamente varios
jugadores pueden tener asignado el mismo número). Se elige al azar un jugador de comienzo
y, suponiendo que su número asignado es i, se elimina al jugador que está i posiciones hacia
la izquierda si i es impar, o hacia la derecha si i es par. Se toma como nuevo valor de i el
número que tuviera asignado el último jugador eliminado, el cuál, determina de la forma
descrita el siguiente jugador a eliminar. Este proceso se repite hasta que quede un único
jugador, el ganador del juego.
Implemente una función que determine y devuelva el jugador ganador, dado el conjunto
de n jugadores con sus números del 1 al 6 asignados y la posición del jugador de comienzo.*/
std::string juego_aleatorio(const listaCir<jugador>& jugadores,listaCir<jugador>::posicion j_inicial)
{
    assert(!jugadores.vacia());
    listaCir<jugador> supervivientes(jugadores);
    listaCir<jugador>::posicion j_actual=supervivientes.inipos();
    int pos_eliminatoria=(jugadores.elemento(j_inicial)).numero;//Numero para calcular la posicion del siguiente jugador a eliminar
    //Transferencia de la posicion j_inicial a j_actual al hacer una copia de lista
    while (j_inicial!=jugadores.inipos())//Por cada posicion que tengo que mover anterior a j_inicial para llegar al principio, avanzo j_actual
    {
        j_inicial=jugadores.anterior(j_inicial);
        j_actual=supervivientes.siguiente(j_actual);
    }
    //Comienzo del juego
    while (supervivientes.tama()>1)
    {
        if (pos_eliminatoria %2==1)//Si es impar, que sea negativa las posiciones a recorrer
            pos_eliminatoria *= -1;
        
        while (pos_eliminatoria>0)//Si es positiva, avanza posiciones a la derecha (contando 1 porque es siguiente)
        {
            j_actual=supervivientes.siguiente(j_actual);
            pos_eliminatoria--;
        }
        while (pos_eliminatoria<0)//Si es negativa, avanza posiciones a la izquierda
        {
            j_actual=supervivientes.anterior(j_actual);
            pos_eliminatoria++;
        }

        pos_eliminatoria=(supervivientes.elemento(j_actual)).numero;
        supervivientes.eliminar(j_actual);
    }
    return supervivientes.elemento(j_actual).nombre;
}