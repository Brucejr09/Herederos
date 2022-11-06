#include "animal.h"

Animal::Animal(string nombre, int edad, string tamanio,  string personalidad){
	this -> nombre = nombre;
	this -> edad = edad;
	this -> tamanio = tamanio;
	this -> personalidad = personalidad;
}

Animal::~Animal(){}

void Animal::alimentar(){
	hambre = MINIMO;
}

void Animal::fue_alimentado(){}

void Animal::se_bania(){}

void Animal::baniar(){
	higiene = MAXIMO;
}

void Animal::caracteristicas(){
	cout << nombre << espaciar_palabras(nombre.size(), ESPACIO_ASIGNADO);
	cout << edad << espaciar_palabras((to_string(edad)).size(), ESPACIO_ASIGNADO);
	cout << tamanio << espaciar_palabras(tamanio.size(), ESPACIO_ASIGNADO);
	cout << especie << espaciar_palabras(especie.size(), ESPACIO_ASIGNADO);
	cout << personalidad << espaciar_palabras(personalidad.size(), ESPACIO_ASIGNADO);
	cout << hambre << espaciar_palabras((to_string(hambre)).size(), ESPACIO_ASIGNADO);
	cout << higiene << espaciar_palabras((to_string(hambre)).size(), ESPACIO_ASIGNADO) << endl;
}

void Animal::modificar_higiene_hambre(){
	bool se_bania = true;
	if(especie[0] == GATO || especie[0] == ROEDOR || especie[0] == LAGARTIJA){
		se_bania = false;
	}
	
	if(personalidad == DORMILON){
		if(hambre < MAXIMO){
			hambre = hambre + (HAMBRE_HABITUAL / 2);
		}
		if(hambre > MAXIMO){
			hambre = MAXIMO;
		}
		
		if(higiene > MINIMO && se_bania){
			higiene = higiene - HIGIENE_HABITUAL;
		}
		if(higiene < MINIMO){
			higiene = MINIMO;
		}
	}
	else if(personalidad == JUGUETON){
		if(hambre < MAXIMO){
			hambre = hambre + (HAMBRE_HABITUAL * 2);
		}
		if(hambre > MAXIMO){
			hambre = MAXIMO;
		}
		
		if(higiene > MINIMO && se_bania){
			higiene = higiene - HIGIENE_HABITUAL;
		}
		if(higiene < MINIMO){
			higiene = MINIMO;
		}
	}
	else if(personalidad == SOCIABLE){
		if(hambre < MAXIMO){
			hambre = hambre + HAMBRE_HABITUAL;
		}
		if(hambre > MAXIMO){
			hambre = MAXIMO;
		}
		
		if(higiene > MINIMO && se_bania){
			higiene = higiene - (HIGIENE_HABITUAL / 2);
		}
		if(higiene < MINIMO){
			higiene = MINIMO;
		}
	}
	else if(personalidad == TRAVIESO){
		if(hambre < MAXIMO){
			hambre = hambre + HAMBRE_HABITUAL;
		}
		if(hambre > MAXIMO){
			hambre = MAXIMO;
		}
		
		if(higiene > MINIMO && se_bania){
			higiene = higiene - (HIGIENE_HABITUAL * 2);
		}
		if(higiene < MINIMO){
			higiene = MINIMO;
		}
	}
}


string Animal::obtener_nombre() {
	return nombre;
}

int Animal::obtener_edad() {
	return edad;
}

string Animal::obtener_tamanio() {
	return tamanio;
}

string Animal::obtener_especie() {
	return especie;
}

string Animal::obtener_personalidad() {
	return personalidad;
}

string Animal::espaciar_palabras(int tamanio_caracteristica, int espacio_asignado){
	string espaciado = "";
	for(int i = 0; i < espacio_asignado - tamanio_caracteristica; i++){
		espaciado = espaciado + " ";
	}
	return espaciado;
}