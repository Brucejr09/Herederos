#ifndef CONEJO_H_INCLUDED
#define CONEJO_H_INCLUDED

#include "animal.h"

//Clase dereivada de Animal
class Conejo : public Animal{
	//Metodos
	public:
		//Constructor de Conejo con parametros
		/*
		 *PRE:
		 *		Debe utiliza el constructor de la clase Animal
		 *POST:
		 *		Construye un objeto de Conejo asignando la informacion correspondiente a ciertos atributos y asigna la especie designada para la clase
		 */
		Conejo(string nombre, int edad, string tamanio, string personalidad);
		
		//Muestra que comio el conejo
		/*
		 *POST:
		 *		Redefine el metodo void fue_alimentado(); de Animal y muestra el nombre y con que fue alimentado el conejo
		 */
		void fue_alimentado();
};

#endif // CONEJO_H_INCLUDED