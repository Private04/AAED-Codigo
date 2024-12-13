#ifndef COLA_VEC_CE_H
 #define COLA_VEC_PS_H
 #include <cstddef> // size_t
 #include <utility> // swap
 #include <cassert>
 template <typename T> class Cola {
 public:
 explicit Cola(size_t tamaMax = 0); // Requiere ctor. T()
 bool vacia() const;
 size_t tama() const;
 size_t tamaMax() const; // Requerida por la implementación
 const T& frente() const;
 void pop();
 void push(const T& x); // Requiere T asignable
 Cola(const Cola& C); // Ctor. de copia, req. T() y T asig.
 Cola& operator =(const Cola& C); // Asig., req. T() y T asig.
 ~Cola(); // Destructor
 private:
 T* elementos; // Vector de elementos
 size_t Lmax, // Tamaño del vector
 inicio, // Posición del frente
 n_eltos; // Tamaño de la cola
 };


 template <typename T>
inline Cola<T>::Cola(size_t tamaMax) : elementos(new T[tamaMax]),
 elementos(new T[tamaMax]),
 Lmax(tamaMax),
 inicio(0),
 n_eltos(0)
 {}
 template <typename T>
 inline bool Cola<T>::vacia() const
 {
 return n_eltos == 0;
 }
 template <typename T>
 inline size_t Cola<T>::tama() const
 {
 return n_eltos;
 }
  template <typename T>
 inline size_t Cola<T>::tamaMax() const
 {
 return Lmax;
 }
 template <typename T>
 inline const T& Cola<T>::frente() const
 {
 assert(!vacia());
 return elementos[inicio];
 }
 template <typename T>
 inline void Cola<T>::pop()
 {
 assert(!vacia());
 inicio = (inicio + 1) % Lmax;
 --n_eltos;}
  template <typename T>
 inline void Cola<T>::push(const T& x)
 {
 assert(n_eltos < Lmax); // Cola no llena
 elementos[(inicio + n_eltos) % Lmax] = x;
 ++n_eltos;
 }
 // Constructor de copia
 template <typename T>
 Cola<T>::Cola(const Cola& C) : Cola(C.Lmax)
 {
 if (!C.vacia()) {
 n_eltos = C.n_eltos;
 for (size_t i = 0; i < n_eltos; ++i) // Copiar elementos
 elementos[i] = C.elementos[(C.inicio + i) % Lmax];
 }
 }
 // Asignación entre colas
 template <typename T>
 inline Cola<T>& Cola<T>::operator =(const Cola& C)
 {
 Cola D(C);
 std::swap(elementos, D.elementos);
 std::swap(Lmax, D.Lmax);
 std::swap(inicio, D.inicio);
 std::swap(n_eltos, D.n_eltos);
 return *this;
 }
 // Destructor
 template <typename T>
 inline Cola<T>::~Cola()
 {
 delete[] elementos;
 }
 #endif