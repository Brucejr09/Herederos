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
		 *		Construye un Arbol vacio
		 */
		Arbol();

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

		void insertar_en_hoja(Nodo* &actual, Animal* animal);

		void dividir_nodo (Nodo* &padre, int posicion_hijo, Nodo* &hijo);

		bool memoria_liberada (Nodo* &candidato);

		//preorden
		void mostrar_arbol ();

		void mostrar_subarbol (Nodo* actual);
		
		//Destructor del Arbol
		/*
		 *POST:
		 *		Libera la direccion de memoria reservada en el objeto de Arbol
		 */
		~Arbol();
};

#endif // ARBOL_H_INCLUDED