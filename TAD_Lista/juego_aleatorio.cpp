#include <string>
#include <cassert>
#include "lista_ps.h"
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
std::string juego_aleatorio(const Lista<jugador>& jugadores,Lista<jugador>::posicion j_inicial)
{
    assert(jugadores.vacia());
    
   
    Lista<jugador> supervivientes(jugadores);
    Lista<jugador>::posicion j_actual=supervivientes.primera();
    int pos_eliminatoria=(jugadores.elemento(j_inicial)).numero;//Numero para calcular la posicion del siguiente jugador a eliminar
    //Transferencia de la posicion j_inicial a j_actual al hacer una copia de lista
    while (j_inicial!=jugadores.primera())//Por cada posicion que tengo que mover anterior a j_inicial para llegar al principio, avanzo j_actual
    {
        j_inicial=jugadores.anterior(j_inicial);
        j_actual=jugadores.siguiente(j_actual);
    }
    //Comienzo del juego
    while (supervivientes.tama()>1)
    {
        if (pos_eliminatoria %2==1)
            pos_eliminatoria*=-1;
        
        while (pos_eliminatoria>0)
        {
            j_actual
        }
    }
    return (supervivientes.elemento(supervivientes.primera()).nombre);//Devuelve el nombre del único jugador de la lista
}