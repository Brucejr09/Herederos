#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "perro.h"
#include "gato.h"
#include "caballo.h"
#include "roedor.h"
#include "conejo.h"
#include "erizo.h"
#include "lagartija.h"

class Nodo {
    // Atributos
	private:
    	Animal* animal;
    	Nodo* siguiente;

    //Metodos
	public:
    	//Constructor de Nodo con parametros
    	/*
    	 *PRE:
    	 *		Recibe un objeto puntero animal de Animal
    	 *POST:
    	 *		Construye un objeto Nodo asignando el objeto animal correspondiente y siguiente sera 0
    	 */
    	Nodo(Animal* animal);

    	//Cambia la direccion de memoria de siguiente
    	/*
    	 *PRE:
    	 *		Recibe un objeto puntero siguiente de Nodo
    	 *POST:
    	 *		Cambia la direccion de memoria del atributo siguiente por la direccion de memoria de siguiente recibida
    	 */
    	void cambiar_siguiente(Nodo* siguiente);

    	//Devuelve la direccion de memoria de siguiente
    	/*
    	 *POST:
    	 *		Devuelve la direccion de memoria del atributo siguiente
    	 */
    	Nodo* obtener_siguiente();

    	//Devuelve la direccion de memoria del objeto de Animal
    	/*
    	 *POST:
    	 *		Devuelve la direccion de memoria del atributo objeto de Animal
    	 */
    	Animal* obtener_dato();
};

#endif // NODO_H_INCLUDED