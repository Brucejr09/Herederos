#include "nodo_lista.h"

Nodo_lista::Nodo_lista(Dato dato){
    this->dato = new Dato(dato);
    siguiente = 0;
}

void Nodo_lista::cambiar_dato(Dato* dato){
    this->dato = dato;
}

Dato* Nodo_lista::obtener_dato(){
    return dato;
}

void Nodo_lista::cambiar_siguiente(Nodo_lista* nodo_siguiente){
    this->siguiente = nodo_siguiente;
}

Nodo_lista* Nodo_lista::obtener_siguiente(){
    return siguiente;
}

Nodo_lista::~Nodo_lista(){
    delete this->dato;
}