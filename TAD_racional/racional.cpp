#include "racional.h"
 // Métodos públicos
 // Constructor
racional::racional(entero nu, entero de) : n(nu), d(de)
 {
 assert(d != 0); // Verificar precondición
 if (d < 0) { // Poner signo en el numerador
 n = -n;
 d = -d;
}
// Reducir fracción
entero m = mcd(n, d);
if (m != 1) {
n /= m;
d /= m;
}
}
// Operadores aritméticos no miembros
racional operator +(const racional& r, const racional& s)
{
racional::entero m = racional::mcd(r.d, s.d);
return racional(s.d / m * r.n + r.d / m * s.n,
racional::mcm(r.d, s.d));
}
racional operator *(const racional& r, const racional& s)
{
racional::entero a = racional::mcd(r.n, s.d);
racional::entero b = racional::mcd(r.d, s.n);
return racional((r.n / a) * (s.n / b),
(r.d / b) * (s.d / a));
}
// Método privado
racional::entero racional::mcd(entero x, entero y)
// Devuelve mcd(|x|, |y|). Devuelve 0 si x e y valen 0.
{
// Algoritmo de Euclides
if (x < 0) x = -x;
if (y < 0) y = -y;
if (y) while ((x %= y) && (y %= x));
return x + y; // Devolver el último divisor.
}
//Funciones implementadas
racional operator +(const racional& r, const racional::entero& s)
{
       racional suma(s);
       return r+suma;
}
racional operator /(const racional& r, const racional& s)
{
    
    return r*inv(s);
}

racional operator -(const racional& r, const racional& s)
{
    racional restando(-s.num(),s.den());
    return r+s;
}

void operator +=(racional& r, const racional& s)
{
    r=r+s;
}

void operator -=(racional& r, const racional& s)
{
    r=r-s;
}
void operator *=(racional& r, const racional& s)
{
    r=r*s;
}
void operator /=(racional& r, const racional& s)
{
    r=r/s;
}
bool operator !=(const racional& r,const racional& s)
{
    return !(r==s);
}
bool operator >(const racional& r,const racional& s)
{
    return !(r<s);
}
bool operator <=(const racional& r,const racional& s)
{
    return r<s || r==s;
}
bool operator >=(const racional& r,const racional& s)
{
    return r>s || r==s;
}