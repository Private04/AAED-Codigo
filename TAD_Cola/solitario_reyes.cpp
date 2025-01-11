#include "solitario_reyes.h"
bool solitario_reyes(tMonton montones[],tCarta::figura fig_actual,tMonton& resultado)
{
    int figuras_correctas[10]={0,0,0,0,0,0,0,0,0,0};//contador de cuantas cartas correctas tiene cada monton
    tCarta::figura sig_figura;//Variable para almacenar la figura correspondiente al monton de la carta a introducir
    while(figuras_correctas[fig_actual]<4)//Mientras que no haya 4 cartas de la figura correcta en un monton
    {
        sig_figura=montones[fig_actual].frente().fig;
        montones[sig_figura].push(montones[fig_actual].frente());
        montones[fig_actual].pop();
        figuras_correctas[sig_figura]++;
        fig_actual=sig_figura;
    }
    resultado=montones[tCarta::figura::REY];
    return fig_actual==tCarta::figura::REY;
}