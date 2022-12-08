#include "vertice.h"

Vertice::Vertice(){}

Vertice::Vertice(const Vertice &copia){
    this->visitado = copia.visitado;
    this->anterior = copia.anterior;
    this->peso = copia.peso;
}

Vertice::Vertice(int distancia, bool visitado, Vertice* anterior, int peso, int fila, int columna){
    this->distancia = distancia;
    this->visitado = visitado;
    this->anterior = anterior;
    this->peso = peso;
    this->posicion = Coordenada(fila, columna);
}

void Vertice::cambiar_visitado(bool visitado){
    this->visitado = visitado;
}

void Vertice::cambiar_peso(int peso){
    this->peso = peso;
}

void Vertice::cambiar_anterior(Vertice* nuevo_anterior){
    anterior = nuevo_anterior;
}

int Vertice::obtener_distancia(){
    return distancia;
}

bool Vertice::obtener_visitado(){
    return visitado;
}

int Vertice::obtener_peso(){
    return peso;
}

Vertice* Vertice::obtener_anterior(){
    return anterior;
}

Coordenada Vertice::obtener_posicion(){
    return posicion;
}