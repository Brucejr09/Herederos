#include "lista.h"

Lista::Lista(){
    cantidad = 0;
    primero = 0;
    actual = primero;
}

int Lista::obtener_cantidad(){
    return cantidad;
}

void Lista::alta(Dato dato, int posicion){
    Nodo_lista* nuevo = new Nodo_lista(dato);
    if(posicion==0){
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    } else {
        Nodo_lista* anterior = obtener_nodo(posicion-1);
        Nodo_lista* siguiente = anterior->obtener_siguiente();
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}

void Lista::baja(int posicion){
    if(posicion==0){
        Nodo_lista* siguiente = primero->obtener_siguiente();
        delete primero;
        primero = siguiente;
    }else {
        Nodo_lista* anterior = obtener_nodo(posicion-1);
        Nodo_lista* eliminar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(eliminar->obtener_siguiente());
        delete eliminar;
    }
    cantidad--;
}

Dato* Lista::consulta(int posicion){
    return obtener_nodo(posicion)->obtener_dato();
}

bool Lista::vacia(){
    return cantidad == 0;
}

Nodo_lista* Lista::obtener_nodo(int posicion){
    Nodo_lista* auxiliar = primero;
    int index = 0;
    while(index!=posicion){
        auxiliar = auxiliar->obtener_siguiente();
        index++;
    }
    return auxiliar;
}

void Lista::reiniciar_actual() {
    actual = primero;
}

bool Lista::hay_siguiente_actual() {
    return (actual != 0);
}

Dato* Lista::obtener_dato_actual(){
    return actual->obtener_dato();
}

void Lista::siguiente_actual() {
    actual = actual->obtener_siguiente();
}

Lista::~Lista(){
    while(!vacia()){
        baja(0);
    }
}