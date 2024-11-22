#include "racional.h"
#include "ext_racional.h"
racional operator +(const racional& r, const racional::entero& s)
{
    racional suma(s);
    return r+suma;
}
racional operator +(const racional& r)
{
    return r;
}
racional operator /(const racional& r, const racional& s)
{
    
    return r*inv(s);
}

racional operator -(const racional& r, const racional& s)
{
    return r+(-s);
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