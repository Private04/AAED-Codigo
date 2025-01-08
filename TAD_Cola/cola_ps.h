#ifndef COLA_VEC_CE_H
 #define COLA_VEC_PS_H
 #include <cstddef> // size_t
 #include <utility> // swap
 #include <cassert>
 template <typename T> class Cola_ps {
 public:
 explicit Cola_ps(size_t tamaMax = 0); // Requiere ctor. T()
 bool vacia() const;
 size_t tama() const;
 size_t tamaMax() const; // Requerida por la implementación
 const T& frente() const;
 void pop();
 void push(const T& x); // Requiere T asignable
 Cola_ps(const Cola_ps& C); // Ctor. de copia, req. T() y T asig.
 Cola_ps& operator =(const Cola_ps& C); // Asig., req. T() y T asig.
 ~Cola_ps(); // Destructor
 private:
 T* elementos; // Vector de elementos
 size_t Lmax, // Tamaño del vector
 inicio, // Posición del frente
 n_eltos; // Tamaño de la cola
 };


 template <typename T>
inline Cola_ps<T>::Cola_ps(size_t tamaMax) : elementos(new T[tamaMax]),
 elementos(new T[tamaMax]),
 Lmax(tamaMax),
 inicio(0),
 n_eltos(0)
 {}
 template <typename T>
 inline bool Cola_ps<T>::vacia() const
 {
 return n_eltos == 0;
 }
 template <typename T>
 inline size_t Cola_ps<T>::tama() const
 {
 return n_eltos;
 }
  template <typename T>
 inline size_t Cola_ps<T>::tamaMax() const
 {
 return Lmax;
 }
 template <typename T>
 inline const T& Cola_ps<T>::frente() const
 {
 assert(!vacia());
 return elementos[inicio];
 }
 template <typename T>
 inline void Cola_ps<T>::pop()
 {
 assert(!vacia());
 inicio = (inicio + 1) % Lmax;
 --n_eltos;}
  template <typename T>
 inline void Cola_ps<T>::push(const T& x)
 {
 assert(n_eltos < Lmax); // Cola_ps no llena
 elementos[(inicio + n_eltos) % Lmax] = x;
 ++n_eltos;
 }
 // Constructor de copia
 template <typename T>
 Cola_ps<T>::Cola_ps(const Cola_ps& C) : Cola_ps(C.Lmax)
 {
 if (!C.vacia()) {
 n_eltos = C.n_eltos;
 for (size_t i = 0; i < n_eltos; ++i) // Copiar elementos
 elementos[i] = C.elementos[(C.inicio + i) % Lmax];
 }
 }
 // Asignación entre colas
 template <typename T>
 inline Cola_ps<T>& Cola_ps<T>::operator =(const Cola_ps& C)
 {
 Cola_ps D(C);
 std::swap(elementos, D.elementos);
 std::swap(Lmax, D.Lmax);
 std::swap(inicio, D.inicio);
 std::swap(n_eltos, D.n_eltos);
 return *this;
 }
 // Destructor
 template <typename T>
 inline Cola_ps<T>::~Cola_ps()
 {
 delete[] elementos;
 }
 #endif