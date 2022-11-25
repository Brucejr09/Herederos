#include "mapa.h"

Mapa::Mapa(){
    terreno = new Baldosa*[ALTO_TERRENO];
    for (int i = 0; i < ALTO_TERRENO; i++){
            terreno[i] = new Baldosa[ANCHO_TERRENO];
    }
    generar_mapa_aleatorio();
}

void Mapa::imprimir_terreno(){

}

Baldosa** Mapa::obtener_terreno(){
    return terreno;
}

void Mapa::generar_mapa_aleatorio(){

}

void Mapa::generar_animal_aleatorio(){
    
}