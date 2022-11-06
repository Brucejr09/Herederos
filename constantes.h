#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Constantes enteras

const int ESPACIO_ASIGNADO = 15;

const int HAMBRE_HABITUAL = 10;
const int HIGIENE_HABITUAL = 10;

const int MINIMO = 0;
const int MAXIMO = 100;

const int PRIMERA_OPCION = 1;
const int SEGUNDA_OPCION = 2;
const int SALTEAR = 3;

const int ESPACIO_INFERIOR = 10;
const int ESPACIO_INTERMEDIO = 20;
const int ESPACIO_SUPERIOR = 50;

//Constantes de cadenas de caracteres

const string NOMBRE_ARCHIVO = "animales.csv";

const string DORMILON = "dormilon";
const string JUGUETON = "jugueton";
const string SOCIABLE = "sociable";
const string TRAVIESO = "travieso";

const string DIMINUTO = "diminuto";
const string PEQUENIO = "pequenio";
const string MEDIANO = "mediano";
const string GRANDE = "grande";
const string GIGANTE = "gigante";

//Constantes de caracteres

const char PERRO = 'P';
const char GATO = 'G';
const char CABALLO = 'C';
const char ROEDOR = 'R';
const char CONEJO = 'O';
const char ERIZO = 'E';
const char LAGARTIJA = 'L';
const char DELIMITADOR = ',';

//Enumeradores usados como constantes

enum Acciones {
	LISTAR = 1,
	RESCATAR,
	BUSCAR,
	CUIDAR,
	ADOPTAR,
	GUARDAR_SALIR,
};

enum Mini_acciones {
	ELEGIR = 1,
	ALIMENTAR,
	BANIAR,
	REGRESAR,
};

//Estructura para el guardado de informacion

struct Descripcion {
	string nombre;
	int edad;
	string tamanio;
	char especie;
	string personalidad;
};

#endif // CONSTANTES_H_INCLUDED