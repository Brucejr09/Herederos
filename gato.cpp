#include "gato.h"

Gato::Gato(string nombre, int edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, personalidad) {
	this -> especie = "Gato";
}

void Gato::fue_alimentado(){
	cout << nombre << " fue alimentado con atun." << endl;
}

void Gato::se_bania() {
	cout << nombre << " No necesita baniarse por ser: " << especie << endl << endl;
}
