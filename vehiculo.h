#ifndef __VEHICULO__
#define __VEHICULO__
#include "lista.h"
#include "mapa.h"
#include <iostream>

const int INFINITO = -1;
const int COSTE_CAMINO = 1;
const int COSTE_TIERRA = 2;
const int COSTE_MONTANIA = 5;
const int COSTE_PRECIPICIO = 40;

class Vehiculo{
    //Atributos
private:
    int combustible;
    Coordenada posicion;
    Mapa mapa;

    //Metodos
public:
    void cargar_combustible();
    int obtener_coste_baldosa();
    void desplazarse(); //-> pide fila y columna -> puede? si - muestra camino / no - otro lugar o cancelar?
    void dijkstras(Baldosa baldosas[ALTO_TERRENO][ANCHO_TERRENO], Coordenada posicion_inicio);
    bool puede_llegar( Coordenada posicion_destino);
    void cambiar_posicion ( Coordenada nueva_posicion);
};
#endif