#include "nodo.h"

Nodo::Nodo(Animal* animal) {
    this->animal = animal;
    siguiente = 0;
}

void Nodo::cambiar_siguiente(Nodo* siguiente) {
    this->siguiente = siguiente;
}

Nodo* Nodo::obtener_siguiente() {
    return siguiente;
}

Animal* Nodo::obtener_dato() {
    return animal;
}
