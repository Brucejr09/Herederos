const int ESPACIO_ASIGNADO = 15;
const int HAMBRE_HABITUAL = 10;
const int HIGIENE_HABITUAL = 10;
using namespace std;

Animal::Animal(string nombre, string edad, string tamanio, string personalidad){
	this -> nombre = nombre;
	this -> edad = edad;
	this -> tamanio = tamanio;
	this -> personalidad = personalidad;
}

Animal::~Animal(){
}

string Animal::retornar_nombre(){
    return nombre;
}

string Animal::retornar_tamanio(){
	return tamanio;
}

bool Animal::necesita_alimentarse(){
	return hambre > 0;
}

void Animal::alimentar(){
	hambre = 0;
}

bool Animal::necesita_baniarse(){
	return higiene < 100;
}

void Animal::baniar(){
	higiene = 0;
}

void Animal::caracteristicas(){
	cout << nombre << espaciar_palabras(nombre.size(), ESPACIO_ASIGNADO);
	cout << edad << espaciar_palabras(edad.size(), ESPACIO_ASIGNADO);
	cout << tamanio << espaciar_palabras(tamanio.size(), ESPACIO_ASIGNADO);
	cout << especie << espaciar_palabras(especie.size(), ESPACIO_ASIGNADO);
	cout << personalidad << espaciar_palabras(personalidad.size(), ESPACIO_ASIGNADO);
	cout << hambre << espaciar_palabras((to_string(hambre)).size(), ESPACIO_ASIGNADO);
	cout << higiene << espaciar_palabras((to_string(hambre)).size(), ESPACIO_ASIGNADO) << endl;
}

void Animal::modificar_higiene_hambre(){
	bool se_bania = true;
	if(especie == "gato" || especie == "roedor" || especie == "lagartija"){
		se_bania = false;
	}

	if(personalidad == "dormilon"){
		if(hambre < 100){
			hambre = hambre + (HAMBRE_HABITUAL / 2);
		}
		if(hambre > 100){
			hambre = 100;
		}

		if(higiene > 0 && se_bania){
			higiene = higiene - HIGIENE_HABITUAL;
		}
		if(higiene < 0){
			higiene = 0;
		}
	}
	else if(personalidad == "jugueton"){
		if(hambre < 100){
			hambre = hambre + (HAMBRE_HABITUAL * 2);
		}
		if(hambre > 100){
			hambre = 100;
		}

		if(higiene > 0 && se_bania){
			higiene = higiene - HIGIENE_HABITUAL;
		}
		if(higiene < 0){
			higiene = 0;
		}
	}
	else if(personalidad == "sociable"){
		if(hambre < 100){
			hambre = hambre + HAMBRE_HABITUAL;
		}
		if(hambre > 100){
			hambre = 100;
		}

		if(higiene > 0 && se_bania){
			higiene = higiene - (HIGIENE_HABITUAL / 2);
		}
		if(higiene < 0){
			higiene = 0;
		}
	}
	else if(personalidad == "travieso"){
		if(hambre < 100){
			hambre = hambre + HAMBRE_HABITUAL;
		}
		if(hambre > 100){
			hambre = 100;
		}

		if(higiene > 0 && se_bania){
			higiene = higiene - (HIGIENE_HABITUAL * 2);
		}
		if(higiene < 0){
			higiene = 0;
		}
	}
}

void Animal::fue_alimentado(){
}

string Animal::espaciar_palabras(int tamanio_caracteristica, int espacio_asignado){
	string espaciado = "";
	for(int i = 0; i < espacio_asignado - tamanio_caracteristica; i++){
		espaciado = espaciado + " ";
	}
	return espaciado;
}

// -------------------------------------------------------------------------------------------

Perro::Perro(string nombre, string edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, personalidad){
	this -> especie = "perro";
}

void Perro::fue_alimentado(){
	cout << nombre << " fue alimentado con huesos." << endl;
}

//

Gato::Gato(string nombre, string edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, personalidad){
	this -> especie = "gato";
}


void Gato::fue_alimentado(){
	cout << nombre << " fue alimentado con atun." << endl;
}

//

Caballo::Caballo(string nombre, string edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, personalidad){
	this -> especie = "caballo";
}

void Caballo::fue_alimentado(){
	cout << nombre << " fue alimentado con manzanas." << endl;
}

//

Roedor::Roedor(string nombre, string edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, personalidad){
	this -> especie = "roedor";
}

void Roedor::fue_alimentado(){
	cout << nombre << " fue alimentado con queso." << endl;
}

//

Conejo::Conejo(string nombre, string edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, personalidad){
	this -> especie = "conejo";
}

void Conejo::fue_alimentado(){
	cout << nombre << " fue alimentado con lechuga." << endl;
}

//

Erizo::Erizo(string nombre, string edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, personalidad){
	this -> especie = "erizo";
}

void Erizo::fue_alimentado(){
	cout << nombre << " fue alimentado con insectos." << endl;
}

//

Lagartija::Lagartija(string nombre, string edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, personalidad){
	this -> especie = "lagartija";
}

void Lagartija::fue_alimentado(){
	cout << nombre << " fue alimentado con insectos." << endl;
}