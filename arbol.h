#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include "nodo.h"

class Arbol {
	private:
		Nodo* raiz;

	public:
		//Constructor de Arbol
		/*
		 *POST:
		 *		Construye un Arbol partiendo de su raiz vacia
		 */
		Arbol();

		//Destructor del Arbol
		/*
		 *POST:
		 *		Libera la direccion de memoria reservada en el objeto de Arbol
		 */
		~Arbol();

		//Devuelve la raiz del Arbol
		/*
		 *POST:
		 *		Devuelve la posicion de memoria de la raiz del Arbol
		 */
		Nodo* obtener_raiz ();

		//Busca la direccion de memoria donde se encuentra el nombre buscado
		/*
		 *PRE:
		 *		Recibe el objeto de Nodo del cual se empezara la busqueda y recibe el nombre donde debe estar el objeto
		 *POST:
		 *		Si el nombre existe entonces devuelve la direccion de memoria del objeto con dicho nombre, si no existe entoces devuelve NULL
		 */ 
		Animal* busqueda (Nodo* actual, string nombre);

		//Inserta un elemento en el objeto de Arbol
		/*
		 *PRE:
		 *		Recibe el nombre del elemnto que se quiere insertar
		 *POST:
		 *		Inserta el elemento en el objeto de Arbol
		 */
		void insertar(Animal* animal);

		//Muestra el Arbol por pantalla
		/*
		 *POST:
		 *		Muestra el Arbol por pantalla mediante preorden
		 */
		void mostrar_arbol ();

	private:
		//Inserta un elemento en la hoja correspondiente al objeto de Arbol
		/*
		 *PRE:
		 *		Recibe por referencia la direccion de memoria del objeto de Nodo donde se quiere insertar el elemento y recibe el elemnto que se quiere insertar
		 *POST:
		 *		Inserta el elemento en la hoja en el Nodo recibido correspondiente al objeto de Arbol
		 */
		void insertar_en_hoja(Nodo* &actual, Animal* animal);

		//Divide un Nodo
		/*
		 *PRE:
		 *		Recibe por referencia la direccion de memoria del Nodo padre, recibe la posicion de su hijo y recibe por referencia la posicion de memoria del hijo correspondiente a la posicion antes mencionada 
		 *POST:
		 *		Divide el Nodo hijo en la posicion recibida, le asigana nuevos hijos al padre y ordena y agrega una clave al Nodo padre
		 */
		void dividir_nodo (Nodo* &padre, int posicion_hijo, Nodo* &hijo);

		//Libera memoria recursivamente
		/*
		 *PRE:
		 *		Recibe por referencia la posicion de memoria del objeto de Nodo de donde se parte para liberar memoria
		 *POST:
		 *		Libera la memoria de las claves y la memoria de los hijos de manera recursiva
		 */
		bool memoria_liberada (Nodo* &candidato);

		//Muestra un subarbol por pantalla
		/*
		 *PRE:
		 *		Recibe la direccion de memoria del objeto de Nodo del cual se parte para la muestra
		 *POST:
		 *		Muestra el subarbol por pantalla mediante preorden
		 */
		void mostrar_subarbol (Nodo* actual);
};

#endif // ARBOL_H_INCLUDED