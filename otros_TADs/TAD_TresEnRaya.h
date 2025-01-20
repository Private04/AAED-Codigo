//Solo hago la especificación porque prefiero hacer otro tad antes de implementar este simple codigo
/*
    Se define un Tablero como una matriz 3x3 de casillas, una casilla es un elemento con tres estados: vacía, x u o,
    y dos jugadores, que son los símbolos x y o.
    Uno de los jugadores se declara como ganador cuando 3 casillas de la misma fila, columna o diagonal de la matriz de casillas
    tienen como estado el símbolo de ese jugador.
    Una casilla con estado de un jugador no puede cambiar su estado.
    Si hay un jugador ganador, no se puede modificar el estado de ninguna casilla.
    Si ninguna casilla está vacía y no hay ganador, el Tablero se declara como empate.

    Operaciones:
    Tablero(): Crea un tablero vacío, con todas sus casillas en estado vacío.
    void colocar_ficha(jugador j,int fila,int columna): Establece el valor j en la casilla de fila y columna indicados. PRECONDICIÓN: No hay ganador ni es empate
    Lista<Casilla> casillas_libres() const: Devuelve las casillas con estado libre en la matriz
    jugador mostrar_ficha(int fila,int columna) const: PRECONDICIÓN: La casilla no está vacía. Devuelve el símbolo de la casilla introducida
    bool es_ganador(jugador j) const: Devuelve true si j es ganador
    bool empate() const: Devuelve true si es empate.
*/