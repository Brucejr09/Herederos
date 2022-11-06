#ifndef PERRO_H_INCLUDED
#define PERRO_H_INCLUDED

#include "animal.h"

//Clase dereivada de Animal
class Perro : public Animal{
	//Metodos
	public:
		//Constructor de Perro con parametros
		/*
		 *PRE:
		 *		Debe utiliza el constructor de la clase Animal
		 *POST:
		 *		Construye un objeto de Perro asignando la informacion correspondiente a ciertos atributos y asigna la especie designada para la clase
		 */
		Perro(string nombre, int edad, string tamanio, string personalidad);
		
		//Muestra que comio el perro
		/*
		 *POST:
		 *		Redefine el metodo void fue_alimentado(); de Animal y muestra el nombre y con que fue alimentado el perro
		 */
		void fue_alimentado();
};

#endif // PERRO_H_INCLUDED