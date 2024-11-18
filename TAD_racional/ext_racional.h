#ifndef EXT_RACIONAL_H
#define EXT_RACIONAL_H
void operator +=(racional& r, const racional& s);
void operator -=(racional& r, const racional& s);
void operator *=(racional& r, const racional& s);
void operator /=(racional& r, const racional& s);
racional operator -(const racional& r, const racional& s);
racional operator /(const racional& r, const racional& s);
racional operator +(const racional& r, const racional::entero& s);
bool operator !=(const racional& r, const racional& s);
bool operator <=(const racional& r, const racional& s);
bool operator >(const racional& r, const racional& s);
bool operator >=(const racional& r, const racional& s);
#endif