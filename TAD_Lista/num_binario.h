#ifndef BINARIO_H
#define BINARIO_H
/*
    Se define como número binario a una secuencia de n>=0 digitos que tienen valor uno o cero, denominados bits.
    El valor del numero binario equivale al sumatorio de bi*(2^i) donde b es el valor del bit e i es el numero de bits predecesores al que está siendo evaluado.
    El número de digitos no puede ser modificados, pero si los valores de estos mediante operaciones NOT, OR inclusivo, OR Exclusivo, AND y desplazamientos a la izquierda y derecha.

    OPERACIONES
        binario(const string& origen)   PRECONDICIÓN: La elementos de la cadena origen solo pueden ser '0' o '1'.
                                        Crea un número binario tomando los carácteres de la cadena como elementos en el orden en el que aparecen.
        string verNumero() const    Devuelve una cadena con los dígitos ordenados del número binario
        size_t tama() const Devuelve el número de bits en el número
        friend binario&  operator ~(const binario& a) Devuelve el número inverso, convirtiendo los bits 0 en bits 1 y viceversa. (operación NOT)
        friend binario& operator &(const binario& a, const binario& b)    Devuelve el número a AND b, realizando dígito por dígito la operación AND (1 si el valor de ambos dígitos es 1 y 0 si no)
                                                        Si un número es menor a otro, se considerarán 0s a la izquierda del bit más significativo.
        friend binario& operator |(const binario& a, const binario& b)    Devuelve el número a OR b, realizando bit por bit la operación OR inclusivo (1 si al menos 1 bit vale 1 y 0 si no)
                                                        Si un número es menor a otro, se considerarán 0s a la izquierda del bit más significativo.
        friend binadio& operator ^(const binario& a, const binario& b)    Devuelve el número a OR b, realizando bit pot bit la operación OR exclusivo (1 si los valores de los bits son distintos, 0 si no)
                                                        Si un número es menor a otro, se considerarán 0s a la izquierda del bit más significativo.
        friend binario& operator <<(const binario& a, size_t n)   Desplaza los bits del número a la izquierda n veces insertando 0s desde la parte menos significativa y descartando los bits más significativos
        friend binario& operator >>(const binairo& a, size_t n)   Desplaza los bits del número a la derecha n veces insertando 0s desde la parte más significativa y descartando los bits menos significativos
*/
class binario
{
    public:
        binario(const std::string& origen="");
        std::string verNumero() const;
        size_t tama() const;
        friend binario operator ~(const binario& a);
        friend binario operator &(const binario& a, const binario& b);
        friend binario operator |(const binario& a, const binario& b);
        friend binario operator ^(const binario& a, const binario& b);
        friend binario operator <<(const binario& a, size_t n);
        friend binario operator >>(const binario& a, size_t n);
    private:
        Lista<bool> bits;//False representa 0 y true representa 1
};
#endif