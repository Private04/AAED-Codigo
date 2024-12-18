#ifndef CONJUNTO_H
#define CONJUNTO_H
/*
Un conjunto es una secuencia de varios elementos del mismo tipo pero con distinto valor.
Los conjuntos pueden insertar o eliminar elementos de el, al igual que hacer operaciones de 
union interseccion y diferencia.

OPERACIONES
    conjunto() Crea un conjunto vacio
    size_t cardinal() const devuelve el numero de elementos (cardinal del conjunto)
    bool vacio() const devuelve si es un conjunto vacio
    bool esta_en_conjunto(const T& elem) const devuelve si el elemento esta en el conjunto
    const Lista<T>& elementos() const devuelve una lista de los elementos de la cola
    void insertar(const T& elem) inserta el elemento en el conjunto
    void eliminar(const T& elem) PRECONDICION: El elemento esta en el conjunto. elimina el elemento del conjunto
    conjunto& operator &(const conjunto& b) Devuelve la interseccion de ambos conjuntos, es decir, un conjunto que contenga los elementos comunes en ambos conjuntos
    conjunto& operator |(const conjunto& b) Devuelve la union de ambos conjuntos, es decir, un conjunto que contiene elementos comunes y no comunes de ambos conjuntos
    conjunto& operator /(const conjunto& b) Devuelve la diferencia del primero sobre el segundo conjunto, es decir, un conjunto con los elementos de a que no estan contenidos en b
*/
template <typename T>
class Conjunto{
    public:
        conjunto();
        size_t cardinal() const;
        bool vacio() const;
        bool esta_en_conjunto(const T& elem) const;
        const Lista<T>& elementos() const;
        void insertar(const T& elem);
        void eliminar(const T& elem);
        friend conjunto& operator &(const conjunto<T>& b);
        friend conjunto& operator |(const conjunto<T>& b);
        friend conjunto& operator /(const conjunto<T>& b);
    private:
        Lista<T> elementos;
};
#endif