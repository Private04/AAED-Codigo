#ifndef EJ1_H
#define EJ1_H
bool secuencia_inversa_xy (char * s);//Ejercicio 1
bool secuencia_abcd(char * s);//Ejercicio 2
void inversion_delimitada(const char& a,const char& b,Pila<char>& p_inicial);//Ejercicio 3
void suma_lineas_fichero(std::fstream& f);//Ejercicio 4
class linea_texto{//Ejercicio 5
    public:
        linea_texto();
        void avanzar_cursor();
        void retrasar_cursor();
        void ir_a_final();
        void ir_a_principio();
        void borrar_seleccionado();
        void borrar_anterior();
        void insertar_caracter(char c);
        void sobrescribir_caracter(char c);
        char cursor() const;
        size_t tama() const;
    private:
        Pila<char> previo;  //Cadena previa al cursor.
        Pila<char> siguiente;//Cadena siguiente al cursor. El tope es el caracter que apunta el cursor
};//Es necesario un destructor para esta clase?

//Ejercicio 6
enum eFigura{VACIO=0,AS,DOS,TRES,CUATRO,CINCO,SEIS,SIETE,SOTA,CABALLO,REY};
enum ePalo{OROS=0,COPAS,ESPADAS,BASTOS};
struct tCarta{
    eFigura figura;
    ePalo palo;
    tCarta(eFigura f=VACIO,ePalo p=OROS):figura(f),palo(p) {}
};
bool solitario(const tCarta *baraja,eFigura *resultado); //Precondición: mazo apunta a un vector de 40+ elementos de tipo tCarta. 
                                                         //Simula una partida de solitario y devuelve true si se gana y false si no. Devuelve en resultado un vector con la última carta de cada montón.
#endif