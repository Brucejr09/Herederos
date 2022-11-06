#include "caballo.h"

Caballo::Caballo(string nombre, int edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, personalidad) {
	this -> especie = "Caballo";
}

void Caballo::fue_alimentado(){
	cout << nombre << " fue alimentado con manzanas." << endl;
}