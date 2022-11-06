#ifndef ERIZO_H_INCLUDED
#define ERIZO_H_INCLUDED

#include "animal.h"

//Clase dereivada de Animal
class Erizo : public Animal{
	//Metodos
	public:
		//Constructor de Erizo con parametros
		/*
		 *PRE:
		 *		Debe utiliza el constructor de la clase Animal
		 *POST:
		 *		Construye un objeto de Erizo asignando la informacion correspondiente a ciertos atributos y asigna la especie designada para la clase
		 */
		Erizo(string nombre, int edad, string tamanio, string personalidad);
		
		//Muestra que comio el erizo
		/*
		 *POST:
		 *		Redefine el metodo void fue_alimentado(); de Animal y muestra el nombre y con que fue alimentado el erizo
		 */
		void fue_alimentado();
};

#endif // ERIZO_H_INCLUDED