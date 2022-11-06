#include "lagartija.h"

Lagartija::Lagartija(string nombre, int edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, personalidad) {
	this -> especie = "Lagartija";
}

void Lagartija::fue_alimentado(){
	cout << nombre << " fue alimentado con insectos." << endl;
}

void Lagartija::se_bania() {
	cout << nombre << " No necesita baniarse por ser: " << especie << endl << endl;
}