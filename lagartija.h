#ifndef LAGARTIJA_H_INCLUDED
#define LAGARTIJA_H_INCLUDED

#include "animal.h"

//Clase dereivada de Animal
class Lagartija : public Animal{
	//Metodos
	public:
		//Constructor de Lagartija con parametros
		/*
		 *PRE:
		 *		Debe utiliza el constructor de la clase Animal
		 *POST:
		 *		Construye un objeto de Lagartija asignando la informacion correspondiente a ciertos atributos y asigna la especie designada para la clase
		 */
		Lagartija(string nombre, int edad, string tamanio, string personalidad);
		
		//Muestra que comio el lagartija
		/*
		 *POST:
		 *		Redefine el metodo void fue_alimentado(); de Animal y muestra el nombre y con que fue alimentado el lagartija
		 */
		void fue_alimentado();
		
		//Muestra que comio el lagartija
		/*
		 *POST:
		 *		Redefine el metodo void se_bania(); de Animal y muestra el nombre, que no se necesita baniar por ser Lagartija la cual es la especie desiganada de la clase
		 */
		void se_bania();
};

#endif // LAGARTIJA_H_INCLUDED