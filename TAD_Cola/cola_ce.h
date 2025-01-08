#ifndef COLA_CE_H
#define COLA_CE_H
#include <cstddef> // size_t
#include <utility> // swap
#include <cassert>
template <typename T> class Cola_ce {
public:
 Cola_ce();
 bool vacia() const;
 size_t tama() const;
 const T& frente() const;
 void pop();
 void push(const T& x); // Requiere T copiable
 Cola_ce(const Cola_ce& C); // Ctor. de copia, req. T copiable
 Cola_ce& operator =(const Cola_ce& C); // Asig. entre colas, req. T copiable
 ~Cola_ce(); // Destructor

 private:
 struct nodo {
 T elto;
 nodo* sig;
 nodo(const T& e, nodo* p = nullptr) : elto(e), sig(p) {}
 };
 nodo *inicio, *fin; // Extremos de la cola
 size_t n_eltos; // Tamaño de la cola
 };

 template <typename T>
 inline Cola_ce<T>::Cola_ce() :
 inicio(nullptr),
 n_eltos(0)
 {}
 template <typename T>
 inline bool Cola_ce<T>::vacia() const
 { return inicio == nullptr; } // Alternativa: return n_eltos == 0;
 template <typename T>
 inline size_t Cola_ce<T>::tama() const
 { return n_eltos; }
 template <typename T>
 inline const T& Cola_ce<T>::frente() const
 {
 assert(!vacia());
 return inicio->elto;
 }
 template <typename T>
 inline void Cola_ce<T>::pop()
 {
 assert(!vacia());
 nodo* p = inicio;
 inicio = p->sig;
 delete p;
 --n_eltos;
 }
 template <typename T>
 inline void Cola_ce<T>::push(const T& x)
 {
 if (vacia())
 inicio = fin = new nodo(x);
 else
 fin = fin->sig = new nodo(x);
 ++n_eltos;
}
 // Constructor de copia
 template <typename T>
 Cola_ce<T>::Cola_ce(const Cola_ce& C) : Cola_ce()
 {
 if (!C.vacia()) {
 // Copiar el primer elemento.
 inicio = fin = new nodo(C.inicio->elto);
 for (nodo* p = C.inicio->sig; p; p = p->sig)
 fin = fin->sig = new nodo(p->elto);
 n_eltos = C.n_eltos;
 }
 }
 template <typename T>
 inline Cola_ce<T>& Cola_ce<T>::operator =(const Cola_ce& C)
 {
 Cola_ce D(C);
 std::swap(inicio, D.inicio);
 std::swap(fin, D.fin);
 std::swap(n_eltos, D.n_eltos);
 return *this;
 }
// Destructor: vacía la cola
 template <typename T>
 Cola_ce<T>::~Cola_ce()
 {
 nodo* p;
 while (inicio) {
 p = inicio->sig;
 delete inicio;
 inicio = p;
 }
 // n = nullptr; // Innecesario en esta implementación
 n_eltos = 0;
}

#endif