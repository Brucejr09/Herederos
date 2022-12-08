#ifndef __VEHICULO__
#define __VEHICULO__
#include <iostream>
#include "lista.h"

class Vehiculo{
    //Atributos
private:
    int combustible;
    Coordenada posicion;

    //Metodos
public:
    //pre: -
    //pos: Aumenta combustible en carga_combustible.
    void cargar_combustible(int carga_combustible);

    //
    //
    void desplazarse(); //-> pide fila y columna -> puede? si - muestra camino / no - otro lugar o cancelar?
    
    //
    //
    bool puede_llegar(Coordenada posicion_destino);
    
    //pre: -
    //pos: Cambia la posicion a nueva_posicion.
    void cambiar_posicion(Coordenada nueva_posicion);

    //pre: -
    //pos: Cambia la posicion a Coordenada(fila, columna).
    void cambiar_posicion(int fila, int columna);
    
    //pre: -
    //pos: Devuelve un puntero a posicion.
    Coordenada* obtener_posicion();
};
#endif