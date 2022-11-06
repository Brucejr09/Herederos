#include "erizo.h"

Erizo::Erizo(string nombre, int edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, personalidad) {
	this -> especie = "Erizo";
}

void Erizo::fue_alimentado(){
	cout << nombre << " fue alimentado con insectos." << endl;
}