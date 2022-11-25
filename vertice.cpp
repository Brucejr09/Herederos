#include "vertice.h"

Vertice::Vertice(){}

Vertice::Vertice( Vertice &copia){
    this->baldosa = copia.obtener_baldosa();
    this->visitado = copia.obtener_visitado();
    this->anterior = copia.obtener_anterior();
    this->peso = copia.obtener_peso();
}

Vertice::Vertice(Baldosa baldosa, bool visitado, Vertice* anterior, int peso){
    this->baldosa = baldosa;
    this->visitado = visitado;
    this->anterior = anterior;
    this->peso = peso;
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

Baldosa Vertice::obtener_baldosa(){
    return baldosa;
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