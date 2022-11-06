#ifndef ROEDOR_H_INCLUDED
#define ROEDOR_H_INCLUDED

#include "animal.h"

//Clase dereivada de Animal
class Roedor : public Animal{
	//Metodos
	public:
		//Constructor de Roedor con parametros
		/*
		 *PRE:
		 *		Debe utiliza el constructor de la clase Animal
		 *POST:
		 *		Construye un objeto de Roedor asignando la informacion correspondiente a ciertos atributos y asigna la especie designada para la clase
		 */
		Roedor(string nombre, int edad, string tamanio, string personalidad);
		
		//Muestra que comio el roedor
		/*
		 *POST:
		 *		Redefine el metodo void fue_alimentado(); de Animal y muestra el nombre y con que fue alimentado el roedor
		 */
		void fue_alimentado();

		//Muestra que comio el roedor
		/*
		 *POST:
		 *		Redefine el metodo void se_bania(); de Animal y muestra el nombre, que no se necesita baniar por ser Roedor la cual es la especie desiganada de la clase
		 */
		void se_bania();
};

#endif // ROEDOR_H_INCLUDED