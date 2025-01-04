#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H
template <typename T>
class listaCir{
    public:
        listaCir();
        size_t tama() const;
        bool vacia() const;
        void insertar(const T& x, posicion p);
        void eliminar(posicion p);
        const T& elemento(posicion p) const;
        posicion inipos() const;
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        const posicion POS_NULA=nullptr;
    private:
        struct nodo{
            T elemento;
            nodo *sig;
            nodo(nodo * p=nullptr) : sig(p) {} 
        }
        size_t n_elementos;
        nodo * L;
};
#endif