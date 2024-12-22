#ifndef LISTA_PS_H
#define LISTA_PS_H
#include <cstddef> // size_t
 #include <utility> // swap
 #include <cassert>


 template <typename T> 
 class Lista {
 public:
 typedef size_t posicion; // Posición de un elemento
 explicit Lista(size_t tamaMax = 0); // Requiere ctor. T()
 bool vacia() const;
 size_t tama() const;
 size_t tamaMax() const; // Requerida por la implementación
 void insertar(const T& x, posicion p); // Requiere T asignable
 void eliminar(posicion p);
 const T& elemento(posicion p) const; // Lec. elto. en Lista const
 T& elemento(posicion p); // Lec/Esc elto. en Lista no=const
 posicion siguiente(posicion p) const;
 posicion anterior(posicion p) const;
 posicion primera() const;
 posicion fin() const; // Posición después del último
 Lista(const Lista& L); // Ctor. de copia, req. T() y T asig.
 Lista& operator =(const Lista& L); // Asig., req. T() y T asig.
 ~Lista(); // Destructor
 private:
 T* elementos; // Vector de elementos
 size_t Lmax, // Tamaño del vector
 n; // Longitud de la lista
};

template <typename T>
 inline Lista<T>::Lista(size_t tamaMax) :
 elementos(new T[tamaMax]),
 Lmax(tamaMax),
 n(0)
 {}

 template <typename T>
 inline bool Lista<T>::vacia() const
 {
 return n == 0;
 }
 template <typename T>
 inline size_t Lista<T>::tama() const
 {
 return n;
 }
 template <typename T>
 inline size_t Lista<T>::tamaMax() const
 {
 return Lmax;
 }
 template <typename T>
 void Lista<T>::insertar(const T& x, posicion p)
 {
 assert(p >= primera() && p <= fin());
 assert(tama() < tamaMax());
 // Desplazar los eltos. entre p y n() a la siguiente posición
 for (posicion q = fin(); q > p; --q)
 elementos[q] = elementos[q-1];
 elementos[p] = x;
 ++n;
 }
 template <typename T>
 void Lista<T>::eliminar(posicion p)
 {
 assert(p >= primera() && p < fin());
 --n;
 // Desplazar los eltos. entre p+1 y n() a la posición anterior
 for (posicion q = p; q < fin(); ++q)
 elementos[q] = elementos[q+1];
 }
 template <typename T>
 inline const T& Lista<T>::elemento(posicion p) const
 {
 assert(p >= primera() && p < fin());
 return elementos[p];
 }
 template <typename T>
 inline T& Lista<T>::elemento(posicion p)
 {
 assert(p >= primera() && p < fin());
 return elementos[p];
 }
 // Constructor de copia
 template <typename T>
 Lista<T>::Lista(const Lista& L) : Lista(L.Lmax)
 {
 if (!L.vacia()) {
 n = L.n;
 for (posicion p = primera(); p < fin(); ++p)
 elementos[p] = L.elementos[p];
 }
 }
 // Asignación de listas
 template <typename T>
 inline Lista<T>& Lista<T>::operator =(const Lista& L)
 {
 Lista L1(L);
 std::swap(elementos, L1.elementos);
 std::swap(Lmax, L1.Lmax);
 std::swap(n, L1.n);
 return *this;
 }
// Destructor
 template <typename T>
 inline Lista<T>::~Lista()
 {
 delete[] elementos;
 }
 
#endif