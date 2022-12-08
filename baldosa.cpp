#include "baldosa.h"

Baldosa::Baldosa(){
    animal = 0;
    tiene_animal = false;
}

Baldosa::Baldosa(bds::Topografia topografia, int fila, int columna){
    this->topografia = topografia;
    posicion = Coordenada(fila, columna);
    animal = 0;
    tiene_animal = false;
}

int Baldosa::obtener_topografia(){
    return topografia;
}

Coordenada Baldosa::obtener_posicion(){
    return posicion;
}

bool Baldosa::hay_animal(){
    return tiene_animal;
}

void Baldosa::agregar_animal(char especie, string nombre, int edad, string tamanio, string personalidad){
    tiene_animal = true;
    switch (especie)
    {
    case PERRO:
        animal = new Perro(nombre, edad, tamanio, personalidad);
    break;
    case GATO:
        animal = new Gato(nombre, edad, tamanio, personalidad);
    break;
    case CABALLO:
        animal = new Caballo(nombre, edad, tamanio, personalidad);
    break;
    case ROEDOR:
        animal = new Roedor(nombre, edad, tamanio, personalidad);
    break;
    case CONEJO:
        animal = new Conejo(nombre, edad, tamanio, personalidad);
    break;
    case ERIZO:
        animal = new Erizo(nombre, edad, tamanio, personalidad);
    break;
    case LAGARTIJA:
        animal = new Lagartija(nombre, edad, tamanio, personalidad);
    break;
    default:
        cout << "Especie desconocida: funcion agregar_animal Clase Baldosa" << endl;
        tiene_animal = false;
    break;
    }
}

Animal* Baldosa::obtener_animal(){
    return animal;
}

Animal* Baldosa::eliminar_animal(){
    tiene_animal = false;
    return animal;
}

Baldosa::~Baldosa(){
    if(tiene_animal){
        delete animal;
    }
}