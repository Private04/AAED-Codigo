#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H
#include <cstddef>
#include <cassert>
#include <utility>
template <typename T>
class listaCir{
    struct nodo;
    public:
        typedef nodo* posicion;
        const posicion POS_NULA=nullptr;

        listaCir();
        listaCir(const listaCir<T>& original);
        size_t tama() const;
        bool vacia() const;
        const T& elemento(posicion p) const;
        T& elemento(posicion p);
        posicion inipos() const;
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        void insertar(const T& x, posicion p);
        void eliminar(posicion p);
        listaCir& operator =(const listaCir& original);
        ~listaCir();
    private:
        struct nodo{
            T elemento;
            nodo *sig;
            nodo *ant;
            nodo(const T& elem,nodo *anterior=nullptr,nodo *siguiente=nullptr) : elemento(elem), sig(siguiente), ant(anterior) {}
        };
        size_t n_elementos;
        nodo * L;
};
//TODO: CAMBIAR REPRESENTACION DE POSICION

template <typename T>
listaCir<T>::listaCir() : L(nullptr), n_elementos(0)
{}

template <typename T>
inline bool listaCir<T>::vacia () const
{
    return n_elementos==0;
}

template <typename T>
inline size_t listaCir<T>::tama () const
{
    return n_elementos;
}

template <typename T>
inline const T& listaCir<T>::elemento(listaCir<T>::posicion p) const
{
    assert(p != POS_NULA && !vacia());
    return p->elemento;
}

template <typename T>
inline T& listaCir<T>::elemento (listaCir<T>::posicion p)
{
    assert(p != POS_NULA && !vacia());
    return p->elemento;
}

template <typename T>
inline typename listaCir<T>::posicion listaCir<T>::anterior(listaCir<T>::posicion p) const
{
    assert (p != POS_NULA && !vacia());
    return p->ant;
}

template <typename T>
inline typename listaCir<T>::posicion listaCir<T>::siguiente(listaCir<T>::posicion p) const
{
    assert (p != POS_NULA && !vacia());
    return p->sig;
}

template <typename T>
inline typename listaCir<T>::posicion listaCir<T>::inipos() const
{
    return (vacia())? POS_NULA : L;
}

template <typename T>
void listaCir<T>::insertar(const T& x,listaCir<T>::posicion p)
{
    if (vacia())
    {
        L=new nodo(x);
        L->ant=L;
        L->sig=L;
        n_elementos++;
    }
    else
    {
        assert(p!=POS_NULA);
        posicion aux=new nodo(x,p,p->sig);//{p,aux,p->sig}
        p->sig=aux;
        (aux->sig)->ant=aux;
        n_elementos++;
    }
}

template <typename T>
void listaCir<T>::eliminar(listaCir<T>::posicion p)
{
    
    assert(!vacia()&&p!=POS_NULA);
    (p->ant)->sig=p->sig;
    (p->sig)->ant=p->ant;
    n_elementos--;
    if (p==L)
        L=p->sig;
    delete p;
}

template <typename T>
listaCir<T>::listaCir(const listaCir<T>& original)
{
    posicion aux_original=original.L;//Posicion para navegar la lista original.
    posicion aux_this=POS_NULA;//Posicion para navegar la lista siendo creada.
    n_elementos=0;
    for (size_t i=1;i<=original.n_elementos;i++)
    {
        insertar(aux_original->elemento,aux_this);
        aux_original=original.siguiente(aux_original);
        aux_this=siguiente(aux_this==POS_NULA? inipos() : aux_this);
    }
    n_elementos=original.n_elementos;
}

template <typename T>
inline listaCir<T>& listaCir<T>::operator =(const listaCir& original)
{
    listaCir<T> L1(original);
    std::swap(L1.L,this.L);
    std::swap(L1.n_elementos,this.n_elementos);
    return *this;
}

template <typename T>
inline listaCir<T>::~listaCir()
{
    if(!vacia())
    {
        posicion aux=L->sig;
        while (aux!=L)
        {
            aux=aux->sig;//Obtengo la posicion del siguiente y borro el anterior
            delete aux->ant;
        }
        delete L;
    }
    n_elementos=0;
}
#endif