#include "coordenada.h"

Coordenada::Coordenada(){
    this->fila = 0;
    this->columna = 0;
}

Coordenada::Coordenada(int fila, int columna){
    this->fila = fila;
    this->columna = columna;
}

int Coordenada::obtener_fila(){
    return fila;
}

int Coordenada::obtener_columna(){
    return columna;
}

void Coordenada::cambiar_fila(int nueva_fila){
    fila = nueva_fila;
}

void Coordenada::cambiar_columna(int nueva_columna){
    columna = nueva_columna;
}