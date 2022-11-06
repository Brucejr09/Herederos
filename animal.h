#ifndef ANIMALES_H_INCLUDED
#define ANIMALES_H_INCLUDED

#include "constantes.h"

class Animal{
	//Atributos
	protected:
		string nombre;
		int edad;
		string tamanio;
		string especie;
		string personalidad;
		int hambre = 0;
		int higiene = 100;
	
	//Metodos
	public:
		//Constructor de Animal con parametros
		/*
		 *PRE:
		 *		El nombre puede tener espacios en blanco, la edad esta entre 0 y 100, ambos inclusive, el tamanio debe ser: diminuto, pequenio, mediano, grande o gigante, la personalidad debe ser: dormilon, jugueton, sociable o travieso
		 *POST:
		 *		Construye un objeto de Animal asignando la informacion correspondiente a ciertos atributos excepto a especie
		 */
		Animal(string nombre, int edad, string tamanio, string personalidad);
		
		//Destructor de Animal
		/*
		 *POST:
		 *		Destruye un objeto de Animal
		 */
		virtual ~Animal();

		//Alimenta al animal
		/*
		 *POST:
		 *		Asigna 0 al atributo hambre
		 */
		void alimentar();

		//Muestra que comio el animal
		/*
		 *POST:
		 *		Muestra por pantalla el nombre y con que fue alimentado el animal, redefinido en cada clase derivada
		 */
		virtual void fue_alimentado();

		//Muestra si el animal no necesita baniarse
		/*
		 *POST:
		 *		Muestra si cierto animal no necesita baniarse
		 */
		virtual void se_bania();

		//Bania al animal
		/*
		 *POST:
		 *		Asigna 100 al atributo higiene
		 */
		void baniar();

		//Muestra todas las caracteristicas del animal
		/*
		 *POST:
		 *		Muestra por pantalla todas las caracteristicas del animal
		 */
		void caracteristicas();

		//Modifica el hambre y la higiene
		/*
		 *PRE:
		 *		Las personalidades deben ser: dormilon, jugueton, sociable o travieso
		 *POST:
		 *		Dependiendo de la personalidad del animal se le sumara el hambre y se le descontara la higiene correspondiente
		 */
		void modificar_higiene_hambre();

		//Devuelve el nombre
		/*
		 *POST:
		 *		Devuelve el atributo nombre
		 */
		string obtener_nombre();
		
		//Devuelve la edad
		/*
		 *POST:
		 *		Devuelve el atributo edad
		 */
		int obtener_edad();
		
		//Devuelve el tamanio
		/*
		 *POST:
		 *		Devuelve el atributo tamanio
		 */
		string obtener_tamanio();
		
		//Devuelve la especie
		/*
		 *POST:
		 *		Devuelve el atributo especie completo
		 */
		string obtener_especie();
		
		//Devuelve el nombre
		/*
		 *POST:
		 *		Devuelve el atributo personalidad
		 */
		string obtener_personalidad();
		
	private:
		//Separa las palabras con una cierta cantidad de espacios asignados
		/*
		 *PRE:
		 *		Recibe numeros enteros los cuales uno es el tamanio de la palabra y el otro la cantidad de espacios que debe tener la palabra y los separacion en total
		 *POST:
		 *		Devuelve la separacion entre las palabras
		 */
		string espaciar_palabras(int tamanio_caracteristica, int espacio_asignado);
};

#endif	// ANIMALES_H_INCLUDED