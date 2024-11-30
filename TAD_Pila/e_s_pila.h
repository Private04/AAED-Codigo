#ifndef E_S_PILA_H
#define E_S_PILA_H
void pila_leer(Pila<char> p);   //LAS LECTURAS HACEN UNA COPIA, SI NO SE QUIERE HACER COPIA SE TIENEN
                               //QUE DESTRUIR LAS PILAS PASANDOLAS POR REFERENCIA.
void pila_escribir(Pila<char>& p);
#endif