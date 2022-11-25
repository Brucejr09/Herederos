#ifndef __BALDOSA__
#define __BALDOSA__
#include "coordenada.h"

enum Topografia {camino = 1, tierra = 2, montania = 5, precipicio = 40};

class Baldosa{
    //Atributos
private:
    Topografia topografia;
    Coordenada posicion;
    
    //Metodos
public:
    //pre: -
    //pos: Crea un objeto Baldosa
    Baldosa();
    
    //pre: -
    //pos: Devuelve la topografia
    int obtener_topografia();
    //pre: -
    //pos: Devuelve la posicion 
    Coordenada obtener_posicion();
};
#endif