#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "lista.h"

class Menu {
	//Atributos
	private:
		Lista refugio;

	//Metodos
	public:
		//Devuelve un booleano
		/*
		 *POST:
		 *		Devuelve true si el archivo se pudo abrir correctamente, en caso contrario devuelve false
		 */
		bool lista_asignada ();
		
		//Devuelve un entero entre 1 y 6 ambos inclusive
		/*
		 *PRE:
		 *		El usuario debe ingresar un numero necesariamente no puede ingresar un caracter
		 *POST:
		 *		Devuelve un entero entre 1 y 6 ambos inclusive
		 */
		int accion_menu ();
		
		//Muestra por pantalla el menu principal
		/*
		 *POST:
		 *		Muestra por pantalla el menu principal
		 */
		void mostrar ();
		
		//Muestra por pantalla todas las caracteristicas de todos los elementos de la lista
		/*
		 *PRE:
		 *		La lista debe de estar inicializada y cargada, si la lista esta vacia no realizara ninguna accion
		 *POST:
		 *		Muestra por pantalla todas las caracteristicas de todos los elementos de la lista
		 */
		void listar ();
		
		//Agrega un nuevo animal a la lista
		/*
		 *POST:
		 *		El usuario debe introducir un nombre, si el nombre ya existe se le pedira que ingrese uno nuevo y si no quiere ingresa 0 para volver al menu principal, ahora si no existe se le pedira que ingrese las caracteristicas validas de dicho animal
		 */
		void rescatar ();
		
		//Muestra las caracteristicas de un animal
		/*
		 *PRE:
		 *		La lista debe de estar inicializada y cargada, si la lista esta vacia no realizara ninguna accion
		 *POST:
		 *		El usuario debe introducir un nombre si existe se mostrara por pantalla las caracteristicas de dicho animal, en caso contrario se mostrara un error en la pantalla
		 */
		void buscar ();
		
		//Alimenta e higieniza a los animales
		/*
		 *PRE:
		 *		La lista debe de estar inicializada y cargada, si la lista esta vacia no realizara ninguna accion
		 *POST:
		 *		Se le mostrar un mini menu al usuaria para que elija entre cuidar individualmente a los animales, alimentar a todos los animales, baniar a todos los animales o regresar al menu
		 */
		void cuidar ();
		
		//Quita a un animal de la lista
		/*
		 *PRE:
		 *		La lista debe de estar inicializada y cargada, si la lista esta vacia no realizara ninguna accion
		 *POST:
		 *		Le pide al usuario que ingrese su espacio disponible y le muesta por pantalla los animales que cumplen dicha caracteristica, si lo quiere el usuario ingresa su correspondiente numero y se elimina al animal de la lista, si no lo quiere ingresa 0
		 */
		void adoptar ();
		
		//Guarda el archivo actualizado
		/*
		 *POST:
		 *		Devuelve true si el archivo actualizado se pudo guardar correctamente y en caso contrario devuelve false
		 */
		bool guardar_salir ();
	private: 
		//El programa continuara con su ejecucion luego que el usuario precione la tecla ENTER
		/*
 		 *POST:
 		 *		El programa continuara con su ejecucion luego que el usuario precione la tecla ENTER, si presiona otra tecla no continuara.
 		 */
		void presionar_enter ();
		
		//El usuario debe ingresar un numero
		/*
		 *PRE:
		 *		El usuario debe ingresar necesariamente un numero, no puede ingresar un caracter
		 *POST:
		 *		El usuario debe ingresar un numero
		 */
		int pedir_accion ();
		
		//Corrobora que el numero ingresado por el usuario este en rango
		/*
		 *PRE:
		 *		Recibe un numero para corroborar si esta en rango
		 *POST:
		 *		Corrobora que el numero ingresado por el usuario esta entre 1 y 6, ambos inclusive, de caso contrario le pide que ingrese uno nuevo
		 */
		void validar_accion_menu (int &accion);
		
		//Modifica el hambre y la higiene de todos los animales de la lista
		/*
		 *PRE:
		 *		Las personalidades deben ser: dormilon, jugueton, sociable o travieso
		 *POST:
		 *		Dependiendo de la personalidad del animal se le sumara el hambre y se le descontara la higiene correspondiente a todos los animales de la lista
		 */
		void pasar_tiempo ();
		
		//Agrega un animal a la lista
		/*
		 *PRE:
		 *		Recibe una especie para definir la clase derivada que se utilizara y recibe las caracteristicas para inicializar el objero
		 *POST:
		 *		Dependiendo de la especie inicializa el objeto con su clase derivada correspondiente usando memoria dinamica, y lo agrega a la lista
		 */
		void agregar_animal (char especie, Descripcion caracteristicas);		
		
		//Lee el archivo y guarda su informacion en una lista
		/*
		 *PRE:
		 *		Recibe el archivo abierto en modo de lectura
		 *POST:
		 *		Lee el archivo y guarda su informacion en una lista
		 */
		void crear_refugio (ifstream &reserva);
		
		//Corrobora si el archivo se abrio correctamente
		/*
		 *PRE:
		 *		El archivo debe tener el nombre de animales.csv
		 *POST:
		 *		Devuelve 0 si el archivo se abrio correctamente en caso contrario devuelve 1
		 */
		int procesar_archivo ();
		
		//Devuelve un numero ingresado por el usuario
		/*
		 *PRE:
		 *		El usuario debe ingresar necesariamente un numero, no puede ingresar un caracter
		 *POST:
		 *		Devuelve un numero ingresado por el usuario que este entre 0 y 100, ambos inclusive
		 */
		int ingresar_edad ();
		
		//Devolvera un tamanio valido ingresado por el usuario
		/*
		 *PRE:
		 *		El tamanio debe ser: diminuto, pequenio, mediano, grande o gigante
		 *POST:
		 *		Devolvera un tamanio valido ingresado por el usuario
		 */
		string ingresar_tamanio ();
		
		//Devuelve un caracter valido ingresado por el usuario
		/*
		 *PRE:
		 *		El usuario debe ingresar solo un caracter, el caracter debe ser P = perro, G = gato, C = Caballo, R = Roedor, O = Conejo, E = Erizo o L = Lagartija
		 *POST:
		 *		Devuelve un caracter valido ingresado por el usuario
		 */
		char ingresar_especie ();
		
		//Devuelve una personalidad valida ingresada por el usuario
		/*
		 *PRE:
		 *		Las personalidades deben ser: dormilon, jugueton, sociable o travieso
		 *POST:
		 *		Devuelve una personalidad valida ingresada por el usuario
		 */
		string ingresar_personalidad ();
		
		//Corrobora si el numera esta entre 0 y 100
		/*
		 *PRE:
		 *		Recibe un numero para corroborar su rango
		 *POST:
		 *		Si el numero no esta entre 0 y 100, ambos inclusive, se le pedira que vuelve a ingresar un nuevo numero
		 */
		void validar_edad(int &edad);
		
		//Corrobora si el tamanio es valido
		/*
		 *PRE:
		 *		Recibe un string para corroborar si es valido
		 *POST:
		 *		Si el string no esta entre las opciones diminuto, pequenio, mediano, grande o gigante, se le pedira que vuelve a ingresar un string valido
		 */
		void validar_tamanio(string &tamanio);
		
		//Corrobora si el caracter es valido
		/*
		 *PRE:
		 *		Recibe un caracter para corroborar si es valido
		 *POST:
		 *		Si el caracter no esta entre las opciones  P = perro, G = gato, C = Caballo, R = Roedor, O = Conejo, E = Erizo o L = Lagartija, se le pedira que vuelve a ingresar un caracter valido
		 */
		void validar_especie(char &especie);
		
		//Corrobora si la personalidad es valida
		/*
		 *PRE:
		 *		Recibe un string para corroborar si es valido
		 *POST:
		 *		Si el string no esta entre las opciones dormilon, jugueton, sociable o travieso, se le pedira que vuelve a ingresar un string valido
		 */
		void validar_personalidad(string &personalidad);

		//Muestra por pantalla un mini menu
		/*
		 *POST:
		 *		Muestra por pantalla un mini menu
		 */
		void mostrar_mini_menu ();
		
		//Devuelve un entero entre 1 y 4 ambos inclusive
		/*
		 *PRE:
		 *		El usuario debe ingresar un numero necesariamente no puede ingresar un caracter
		 *POST:
		 *		Devuelve un entero entre 1 y 4 ambos inclusive
		 */
		int accion_mini_menu ();
		
		//Corrobora que el numero ingresado por el usuario este en rango
		/*
		 *PRE:
		 *		Recibe un numero para corroborar si esta en rango
		 *POST:
		 *		Corrobora que el numero ingresado por el usuario esta entre 1 y 4, ambos inclusive, de caso contrario le pide que ingrese uno nuevo
		 */
		void validar_accion_mini_menu (int &accion);
		
		//Cuidar individualmente a los animales
		/*
		 *PRE:
		 *		La lista no debe estar vacia
		 *POST:
		 *		Recorre la lista pasando por todos los animales y el usuario elege entre alimentar, baniar o saltear al animal
		 */
		void elegir_individualmente ();
		
		//Devuelve un entero entre 1 y 3 ambos inclusive
		/*
		 *PRE:
		 *		El usuario debe ingresar un numero necesariamente no puede ingresar un caracter
		 *POST:
		 *		Devuelve un entero entre 1 y 3 ambos inclusive
		 */
		int accion_individual ();
		
		//Corrobora que el numero ingresado por el usuario este en rango
		/*
		 *PRE:
		 *		Recibe un numero para corroborar si esta en rango
		 *POST:
		 *		Corrobora que el numero ingresado por el usuario esta entre 1 y 3, ambos inclusive, de caso contrario le pide que ingrese uno nuevo
		 */
		void validar_accion_individual (int &accion);
		
		//Alimenta a todos los animales de la lista
		/*
		 *PRE:
		 *		La lista no debe estar vacia
		 *POST:
		 *		Cambia 0 el atributo hambre de cada animal de la lista
		 */
		void alimentar_a_todos ();
		
		//Bania a todos los animales de la lista
		/*
		 *PRE:
		 *		La lista no debe estar vacia
		 *POST:
		 *		Cambia 100 el atributo higiene de cada animal de la lista
		 */
		void baniar_a_todos ();

		//Devuelve los metros disponibles
		/*
		 *PRE:
		 *		El usuario debe ingresar un numero necesariamente no puede ingresar un caracter
		 *POST:
		 *		Devuelve los metros disponibles ingresados por el usuario los cuales deben ser mayor a 0, en caso cotrario se le pedira que ingrese un numero valido
		 */
		int ingresar_metros ();
		
		//Asigna a un vector de string todos los posibles nombres de animales a ser adoptados
		/*
		 *PRE:
		 *		La lista no puede estar vacia, recibe el espacio disponible, el vector de string a completar y su tope por referencia para que vaya aumentando dependiendo de los candidatos
		 *POST:
		 *		Asigna a un vector de string todos los posibles nombres de animales a ser adoptado corroborando el espacio disponible ingresado por el usuario para cada animal
		 */
		void asignar_posibles_adoptados (int espacio_disponible, string opciones_adopcion[], int &contador);
		
		//Muestra por pantalla todos los posibles nombres candidatos a ser adoptados
		/*
		 *POST:
		 *		Muestra por pantalla todos los posibles nombres candidatos a ser adoptados con su correspondiente numero asignado
		 */
		void mostrar_posibles_adoptados (string opciones_adopcion[], int contador);
		
		//Devuelve un entero entre 0 y el tope maximo de nombres candidatos a ser adoptados
		/*
		 *PRE:
		 *		El usuario debe ingresar un numero necesariamente no puede ingresar un caracter y recibe un comparador que sera el tope maximo de nombres candidatos a ser adoptados
		 *POST:
		 *		Devuelve un entero entre 0 y tope maximo de nombres candidatos a ser adoptados, devuelve 0 si quiere cancelar la adopcion
		 */
		int corroborar_adopcion (int comparador);
};

#endif // MENU_H_INCLUDED