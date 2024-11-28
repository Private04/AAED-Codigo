#ifndef PILA_VEC_H
 #define PILA_VEC_H
 #include <cstddef> // size_t
 #include <cassert>
 template <typename T> class Pila {
 public:
 explicit Pila(size_t tamaMax = 0); // Requiere ctor. T()
 bool vacia() const;
 size_t tama() const;
 size_t tamaMax() const; // Requerida por la implementación
 const T& tope() const;
 void pop();
 void push(const T& x); // Requiere T asignable
 Pila(const Pila& P); // Ctor. de copia, req. T() y T asig.
 Pila& operator =(const Pila& P); // Asig. entre pilas, req. T() y T asig.
 ~Pila(); // Destructor
 private:
 T* elementos; // Vector de elementos
 size_t Lmax, // Tamaño del vector
 n_eltos; // Tamaño de la pila
 };

 template <typename T>
 inline Pila<T>::Pila(size_t tamaMax) :
 elementos(new T[tamaMax]),
 Lmax(tamaMax),
 n_eltos(0)
 {}
 template <typename T>
 inline bool Pila<T>::vacia() const
 {
 return (n_eltos == 0);
 }
 template <typename T>
 inline size_t Pila<T>::tama() const
 {
 return n_eltos;
 }

 template <typename T>
 inline size_t Pila<T>::tamaMax() const
 {
 return Lmax;
 }
 template <typename T>
 inline const T& Pila<T>::tope() const
 {
 assert(!vacia());
 return elementos[n_eltos - 1];
 }
 template <typename T>
 inline void Pila<T>::pop()
 {
 assert(!vacia());
 --n_eltos;
 }

 template <typename T>
 inline void Pila<T>::push(const T& x)
 {
 assert(n_eltos < Lmax); // Requerida por la implementación
 elementos[n_eltos] = x;
 ++n_eltos;
 }
 // Constructor de copia
 template <typename T>
 Pila<T>::Pila(const Pila& P) : Pila(P.Lmax)
 {
 if (!P.vacia()) {
 n_eltos = P.n_eltos;
 for (size_t i = 0; i < n_eltos; ++i) // Copiar elementos
 elementos[i] = P.elementos[i];
 }
 }

 // Asignación entre pilas
 template <typename T>
 inline Pila<T>& Pila<T>::operator =(const Pila<T>& P)
 {
 Pila Q(P); // Si falla, *this no cambia
 // Intercambiar atributos con la pila Q
 T* t = elementos;
 elementos = Q.elementos;
 Q.elementos = t;
 size_t aux = Lmax;
 Lmax = Q.Lmax;
 Q.Lmax = aux;
 aux = n_eltos;
 n_eltos = Q.n_eltos;
 Q.n_eltos = aux;
 return *this;
 } // Destrucción de Q (contenido previo de la pila de destino)

 // Destructor
 template <typename T>
 inline Pila<T>::~Pila()
 {
 delete[] elementos;
} 
#endif // PILA_VEC_H