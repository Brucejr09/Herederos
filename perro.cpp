#include "perro.h"

Perro::Perro(string nombre, int edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, personalidad) {
	this -> especie = "Perro";
}

void Perro::fue_alimentado(){
	cout << nombre << " fue alimentado con huesos." << endl;
}