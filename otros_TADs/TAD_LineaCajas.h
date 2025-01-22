/*
    Se define LineaCajas como un conjunto de 50 cajas, cada una de ellas identificadas por un número del 1 al 50. El número asociado a cada caja es único.
    Una caja es una estructura formada por un cajero, solo si está abierta, y un contador denominado facturación.
    Una caja tiene además dos estados, abierta o cerrada. Solo cuando está abierta se podrá incrementar facturación y cuando la caja está cerrada, el valor es 0.
    Un cajero es un elemento de la caja formado por un número entre 0 y 999 inclusives y que es único en cada caja, es decir, dos cajas de la misma línea de cajas no pueden tener el mismo cajero.
    El cajero solo está en una caja abierta, cuándo pasa a cerrada, se deja de asociar el cajero a esa caja.

    Operaciones:
        LineaCajas(); Crea una línea de cajas con todas las cajas cerradas y facturación a 0

        void abrir_caja(Cajero c,int caja); PRECONDICIÓN: 0 <= c < 1000 y 0 < caja < 51 y la caja está cerrada
                                            Abre la caja, asociando c como cajero de esa caja.
        int cerrar_caja(int caja);  PRECONDICIÓN: La caja está abierta y 0 < caja < 51.
                                    Cierra la caja y devuelve la facturación de esta antes de cerrarla.
        void cobrar_cliente(int caja,int importe);  PRECONDICIÓN: 0 < caja < 51 , la caja está abierta y 0 <= importe.
                                                    Añade a la facturación de la caja el valor de importe.
        void sustituir_cajero(int caja, Cajero c);  PRECONDICIÓN: 0 < caja < 51 , la caja está abierta y 0 <= c < 1000
                                                    Remplaza el cajero de la caja por c.
        int cambiar turno(const Cajero *c,int n); PRECONDICIÓN {c0,c1,...,cn} y 0 <= n <= 50
                                            Cierra todas las cajas abiertas, y luego por cada elemento en c, abre una caja asociada a ese cajero.
                                            Devuelve la suma de las facturaciones de las cajas previas al cierre.
        int cierre(); Cierra todas las cajas de la línea y devuelve la suma de las facturaciones de las que estaban previamente abiertas.  
*/

#ifndef TAD_LINEACAJAS_H
#define TAD_LINEACAJAS_H
class LineaCajas{
    public:
        typedef short unsigned int Cajero;
        LineaCajas();
        void abrir_caja(Cajero c,int caja);
        int cerrar_caja(int caja);
        void cobrar_cliente(int caja,int importe);
        void sustituir_cajero(int caja,Cajero c);
        int cambiar_turno(const Cajero *c,int n);
        int cierre(); 
    private:
    struct Caja
    {
        Cajero cajero;
        int facturacion;
        enum {ABIERTO,CERRADO} estado;
        Caja() : cajero(0),facturacion(0),estado(CERRADO) {}
    };
    static const int MaxCajas=50;
    Caja cajas[50];
};
#endif