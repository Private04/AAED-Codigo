/*
    Un símbolo es una sucesión de trazos de número arbitrario. Se denomina trazo como una línea recta que puede tomar cuatro direcciones: arriba, abajo, izquierda y derecha.
    El último trazo añadido al símbolo se declara como último.

    OPERACIONES:
        simbolo() Crea un símbolo vacío
        size_t tama() const Devuelve el número de trazos del símbolo
        void insertar_trazo(Trazo T) Añade un trazo al símbolo, este trazo se convertirá en el último
        void deshacer_trazo(size_t n) PRECONDICIÓN: n<=simbolo::tama() Elimina n trazos del símbolo, partiendo desde el último trazo
        simbolo simetrico_x() Devuelve un simbolo cuyas trazas son iguales a las de this, excepto que las trazas con dirección arriba tienen dirección abajo y viceversa
        simbolo simetrico_y() Devuelve un simbolo cuyas trazas son iguales a las de this, excepto que las trazas con dirección izquierda tienen dirección derecha y viceversa
        simbolo simetrico_xy() Devuelve un simbolo igual a this, pero con las trazas invertidas de sentido (arriba->abajo,izquierda->derecha,etc...)

*/

#ifndef TAD_SIMBOLO_H
#define TAD_SIMBOLO_H
#include <cassert>
#include "..\TAD_lista\lista_c1e.h"
enum Trazo {ARRIBA,ABAJO,IZQUIERDA,DERECHA};
class Simbolo {
    public:
        Simbolo();
        size_t tama() const;
        void insertar_trazo(Trazo T);
        void deshacer_trazo(size_t n);
        Simbolo simetrico_x();
        Simbolo simetrico_y();
        Simbolo simetrico_xy();
    private:
        Lista<Trazo> L;
};
#endif