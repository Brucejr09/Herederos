#include "vehiculo.h"

void Vehiculo::desplazarse(){
   
}

bool Vehiculo::puede_llegar(Coordenada posicion_destino){
    //Crear mapa de distancias de posicion a posicion_destino
    //Comparar cantidad combustible con coste distancia
    return true;
}

void Vehiculo::cambiar_posicion(Coordenada posicion){
    this->posicion = posicion;
}

void Vehiculo::cambiar_posicion(int fila, int columna){
    this->posicion = Coordenada(fila, columna);
}

Coordenada* Vehiculo::obtener_posicion(){
    return (&posicion);
}

void Vehiculo::cargar_combustible(int carga_combustible){
    combustible += carga_combustible;
}