#ifndef __MAPA__
#define __MAPA__
#include "baldosa.h"

const int ANCHO_TERRENO = 8;
const int ALTO_TERRENO = 8;
const int FILA_INICIO_AUTO = 0;
const int COLUMNA_INICIO_AUTO = 0;

class Mapa{
    //Atributos
private:
    Baldosa** terreno;
    //Metodos
public:
    //pre:
    //pos:
    Mapa();

    //pre: -
    //pos: Imprime el terreno
    void imprimir_terreno();

    //pre: -
    //pos: Devuelve el terreno
    Baldosa** obtener_terreno();
private:
    void generar_mapa_aleatorio();

    void generar_animal_aleatorio();
};
#endif