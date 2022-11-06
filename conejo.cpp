#include "conejo.h"

Conejo::Conejo(string nombre, int edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, personalidad) {
	this -> especie = "Conejo";
}

void Conejo::fue_alimentado(){
	cout << nombre << " fue alimentado con lechuga." << endl;
}
