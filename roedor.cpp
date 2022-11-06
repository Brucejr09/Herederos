#include "roedor.h"

Roedor::Roedor(string nombre, int edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, personalidad) {
	this -> especie = "Roedor";
}

void Roedor::fue_alimentado(){
	cout << nombre << " fue alimentado con queso." << endl;
}

void Roedor::se_bania() {
	cout << nombre << " No necesita baniarse por ser: " << especie << endl << endl;
}