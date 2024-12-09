#include <string>
#include <iostream>
#include <fstream>
#include "pila_ce.h"
#include "oper_pila.h"
#include "e_s_pila.h"
int main()
{
    linea_texto f;
    std::string s("Hola k ase");
    size_t i;
    for (i=0;i<s.length();i++)
    {
        f.insertar_caracter(s[i]);
    }
    f.ir_a_principio();
    f.borrar_seleccionado();
    f.avanzar_cursor();
    f.avanzar_cursor();
    f.avanzar_cursor();
    f.avanzar_cursor();
    f.borrar_anterior();
    f.ir_a_final();
    f.borrar_anterior();
    f.ir_a_principio();
    f.ir_a_final();
    f.retrasar_cursor();
    f.retrasar_cursor();
    f.borrar_anterior();
    f.ir_a_principio();
    for (i=0;i<f.tama();i++)
    {
        std::cout << std::endl << f.cursor();
        f.avanzar_cursor();
    }
}