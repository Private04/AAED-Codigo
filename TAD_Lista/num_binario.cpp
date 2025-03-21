#include <string>
#include <cstddef>
#include "num_binario.h"
binario::binario(const std::string& s) : bits()
{
    for (int i=0;s[i]!='\0';i++)
    {
        bits.insertar(s[i]=='1',bits.fin());
    }
}
std::string binario::verNumero() const
{
    Lista<bool>::posicion p=bits.primera();
    std::string res;
    while(p!=bits.fin())
    {
        res+=('0'+int(bits.elemento(p)));//resultado '0' o '0'+1='1'
        p=bits.siguiente(p);
    }
    return res;
}
size_t binario::tama() const
{
    return bits.tama();
}
binario operator ~(const binario& a)
{
    binario res;
    Lista<bool> bits_invertidos;//Crear una lista para luego asignársela al resultado
    Lista<bool>::posicion p=a.bits.primera();
    while(p!=a.bits.fin())
    {
        bits_invertidos.insertar(!a.bits.elemento(p),bits_invertidos.fin());
        p=a.bits.siguiente(p);
    }
    res.bits=bits_invertidos;
    return res;
}
binario operator &(const binario& a,const binario& b)
{
    int diferencia_tamas=a.tama()-b.tama();
    Lista<bool>::posicion p_a=a.bits.primera(),p_b=b.bits.primera();
    Lista<bool> bits_res;
    binario res;
    while (diferencia_tamas>0)//a es más grande que b
    {
        bits_res.insertar(false,bits_res.fin());
        p_a=a.bits.siguiente(p_a);
        diferencia_tamas--;
    }
    while (diferencia_tamas<0)//b es más grande que a
    {
        bits_res.insertar(false,bits_res.fin());
        p_b=b.bits.siguiente(p_b);
        diferencia_tamas++;
    }
    while (a.bits.fin()!=p_a)//No hace falta comprobar b
    {
        bits_res.insertar(a.bits.elemento(p_a)&b.bits.elemento(p_b),bits_res.fin());
        p_a=a.bits.siguiente(p_a);
        p_b=b.bits.siguiente(p_b);
    }
    res.bits=bits_res;
    return res;
}
binario operator |(const binario& a,const binario& b)
{
    int diferencia_tamas=a.tama()-b.tama();
    Lista<bool>::posicion p_a=a.bits.primera(),p_b=b.bits.primera();
    Lista<bool> bits_res;
    binario res;
    while (diferencia_tamas>0)//a es más grande que b
    {
        bits_res.insertar(a.bits.elemento(p_a),bits_res.fin());
        p_a=a.bits.siguiente(p_a);
        diferencia_tamas--;
    }
    while (diferencia_tamas<0)//b es más grande que a
    {
        bits_res.insertar(b.bits.elemento(p_b),bits_res.fin());
        p_b=b.bits.siguiente(p_b);
        diferencia_tamas++;
    }
    while (a.bits.fin()!=p_a)//No hace falta comprobar b
    {
        bits_res.insertar(a.bits.elemento(p_a)|b.bits.elemento(p_b),bits_res.fin());
        p_a=a.bits.siguiente(p_a);
        p_b=b.bits.siguiente(p_b);
    }
    res.bits=bits_res;
    return res;
}
binario operator ^(const binario& a,const binario& b)
{
    int diferencia_tamas=a.tama()-b.tama();
    Lista<bool>::posicion p_a=a.bits.primera(),p_b=b.bits.primera();
    Lista<bool> bits_res;
    binario res;
    while (diferencia_tamas>0)//a es más grande que b
    {
        bits_res.insertar(!a.bits.elemento(p_a),bits_res.fin());//0 XOR a = !a
        p_a=a.bits.siguiente(p_a);
        diferencia_tamas--;
    }
    while (diferencia_tamas<0)//b es más grande que a
    {
        bits_res.insertar(!b.bits.elemento(p_b),bits_res.fin());
        p_b=b.bits.siguiente(p_b);
        diferencia_tamas++;
    }
    while (a.bits.fin()!=p_a)//No hace falta comprobar b
    {
        bits_res.insertar(a.bits.elemento(p_a)==b.bits.elemento(p_b),bits_res.fin());
        p_a=a.bits.siguiente(p_a);
        p_b=b.bits.siguiente(p_b);
    }
    res.bits=bits_res;
    return res;
}
binario operator <<(const binario& a,size_t n)
{
    binario res(a);
    for (size_t i=1;i<=n;i++)
    {
        res.bits.eliminar(res.bits.primera());
        res.bits.insertar(false,res.bits.fin());
    }
    return res;
}
binario operator >>(const binario& a,size_t n)
{
    binario res(a);
    for (size_t i=1;i<=n;i++)
    {
        res.bits.eliminar(res.bits.anterior(res.bits.fin()));//Eliminar el elemento de la posicion anterior a fin
        res.bits.insertar(false,res.bits.primera());
    }
    return res;
}