#include <string>
#include <cassert>
#include <cstring>
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
char * juego_aleatorio(const listaCir<jugador>& jugadores,char * j_inicial)
{
    assert(!jugadores.vacia());
    listaCir<jugador> supervivientes(jugadores);
    listaCir<jugador>::posicion j_actual=supervivientes.inipos();
    int pos_eliminatoria;//Numero para calcular la posicion del siguiente jugador a eliminar
    //Encontrar el jugador inicial
    while (!strcmp(j_inicial,supervivientes.elemento(j_actual).nombre))
    {
        j_actual=supervivientes.siguiente(j_actual);
    }
    //Comienzo del juego
    while (supervivientes.tama()>1)
    {
        if (pos_eliminatoria % 2 == 0)//Si es par, se llama a supervivientes.siguiente() y si no, a supervivientes.anterior()
        {
            while (pos_eliminatoria>0)//Si es positiva, avanza posiciones a la derecha (contando 1 porque es siguiente)
            {
                j_actual=supervivientes.siguiente(j_actual);
                pos_eliminatoria--;
            }
        }
        else
        {
            while (pos_eliminatoria>0)//Si es negativa, avanza posiciones a la izquierda
            {
                j_actual=supervivientes.anterior(j_actual);
                pos_eliminatoria--;
            }
        }

        pos_eliminatoria=(supervivientes.elemento(j_actual)).numero;
        supervivientes.eliminar(j_actual);
    }
    return supervivientes.elemento(j_actual).nombre;
}