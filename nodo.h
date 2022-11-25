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
	private:
		int cantidad_claves;
		bool es_hoja;
		Animal* claves[MAXIMAS_CLAVES];
		Nodo* hijos[MAXIMOS_HIJOS];

	public:
		//Constructor de Nodo
		/*
		 *POST:
		 *		Construye un nodo vacio
		 */
		Nodo();

		//Informa la cantidad de claves que se encuentran ingresadas
		/*
		 *POST:
		 *		Devuelve la cantidad de claves que se encuentran ingresadas en el objeto Nodo, la misma es mayor a 0
		 */
		int obtener_cantidad_claves();

		//Cambia la cantidad de claves en el objeto de Nodo
		/*
		 *PRE:
		 *		Recibe la nueva cantidad de claves, la cual debe ser 0, 1 o 2, todos enteros
		 *POST:
		 *		Le asigna la nueva cantidad de claves al atributo cantidad_claves
		 */
		void cambiar_cantidad_claves (int nueva_cantidad);

		//Informa si un nodo es hoja
		/*
		 *POST:
		 *		Devuelve true si un nodo es hoja, en caso contrario devuelve false
		 */
		bool sera_hoja();

		//Cambia el valor del atributo es_hoja de un Nodo
		/*
		 *POST:
		 *		Le asigna false al atributo es_hoja
		 */
		void ramificar();

		//Informa el valor de una clave perteneciente al nodo
		/*
		 *PRE:
		 *		Recibe la posicion en la que se encuentra la clave, los valores pueden ser 0 o 1, ambos enteros
		 *POST:
		 *		Devuelve la clave que corresponde a la posicion recibida
		 */
		Animal* obtener_clave(int posicion);

		//Cambia el elemento de la clave correspondiente a la posicion recibida
		/*
		 *PRE:
		 *		Recibe la posicion de la clave que se quiere cambiar, la cual puede ser 0 o 1, ambos enteros, y recibe elemento a asignarle
		 *POST:
		 *		Le asigna el nuevo elemento al atributo clave correspondiente a la posicion recibida
		 */
		void cambiar_clave (int posicion, Animal* nueva_clave);

		//Da la posicion de memoria del objeto de Nodo correspondiente al valor recibido
		/*
		 *PRE:
		 *		Recibe la posicion en la que se encuentra el hijo, los valores pueden ser 0, 1 o 2, todos enteros
		 *POST:
		 *		Si existe el hijo devuelve la posicion de memoria al valor recibido, en caso contrario devuelve NULL
		 */
		Nodo* obtener_hijo(int posicion);

		//Cambia la posicion de memoria de un hijo correspondiente a la posicion recibida
		/*
		 *PRE:
		 *		Recibe la posicion del hijo que se quiere cambiar, la cual puede ser 0, 1 o 2, todos enteros, y recibe la posicion de memoria del objeto de Nodo a asignarle
		 *POST:
		 *		Le asigna la nueva posicion de memoria al atributo hijo correspondiente a la posicion recibida
		 */
		void cambiar_hijo (int posicion, Nodo* nuevo_hijo);
};

#endif // NODO_H_INCLUDED