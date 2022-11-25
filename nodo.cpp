#include "nodo.h"

Nodo::Nodo () {
	cantidad_claves = 0;
	
	es_hoja = true;

	for (int i = 0; i < MAXIMAS_CLAVES; i++)
		claves[i] = NULL;

	for (int i = 0; i < MAXIMOS_HIJOS; i++)
		hijos[i] = NULL;
}

int Nodo::obtener_cantidad_claves () {
	return cantidad_claves;
}

void Nodo::cambiar_cantidad_claves (int nueva_cantidad) {
	cantidad_claves = nueva_cantidad;
}

bool Nodo::sera_hoja () {
	return es_hoja;
}

void Nodo::ramificar () {
	es_hoja = false;
}

Animal* Nodo::obtener_clave (int posicion) {
	return claves[posicion];
}

void Nodo::cambiar_clave (int posicion, Animal* nueva_clave) {
	claves[posicion] = nueva_clave;
}

Nodo* Nodo::obtener_hijo (int posicion) {
	return hijos[posicion];
}

void Nodo::cambiar_hijo (int posicion, Nodo* nuevo_hijo) {
	hijos[posicion] = nuevo_hijo;
}