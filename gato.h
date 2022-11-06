#ifndef GATO_H_INCLUDED
#define GATO_H_INCLUDED

#include "animal.h"

//Clase dereivada de Animal
class Gato : public Animal{
	//Metodos
	public:
		//Constructor de Gato con parametros
		/*
		 *PRE:
		 *		Debe utiliza el constructor de la clase Animal
		 *POST:
		 *		Construye un objeto de Gato asignando la informacion correspondiente a ciertos atributos y asigna la especie designada para la clase
		 */
		Gato(string nombre, int edad, string tamanio, string personalidad);
		
		//Muestra que comio el gato
		/*
		 *POST:
		 *		Redefine el metodo void fue_alimentado(); de Animal y muestra el nombre y con que fue alimentado el gato
		 */
		void fue_alimentado();
		
		//Muestra que comio el gato
		/*
		 *POST:
		 *		Redefine el metodo void se_bania(); de Animal y muestra el nombre, que no se necesita baniar por ser Gato la cual es la especie desiganada de la clase
		 */
		void se_bania();
};

#endif // GATO_H_INCLUDED