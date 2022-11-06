#ifndef CABALLO_H_INCLUDED
#define CABALLO_H_INCLUDED

#include "animal.h"

//Clase dereivada de Animal
class Caballo : public Animal{
	//Metodos
	public:
		//Constructor de Caballo con parametros
		/*
		 *PRE:
		 *		Debe utiliza el constructor de la clase Animal
		 *POST:
		 *		Construye un objeto de Caballo asignando la informacion correspondiente a ciertos atributos y asigna la especie designada para la clase
		 */
		Caballo(string nombre, int edad, string tamanio, string personalidad);
		
		//Muestra que comio el caballo
		/*
		 *POST:
		 *		Redefine el metodo void fue_alimentado(); de Animal y muestra el nombre y con que fue alimentado el caballo
		 */
		void fue_alimentado();
};

#endif // CABALLO_H_INCLUDED