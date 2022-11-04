#include "menu.h"

bool Menu::lista_asignada () {
	return (procesar_archivo() == 0);
}

int Menu::accion_menu () {
	int accion = pedir_accion();

	validar_accion_menu (accion);

	return accion;
}

void Menu::mostrar () {
	cout << "\t\tMENU PRINCIPAL" << endl << endl;
	cout << "1.\tListar" << endl;
	cout << "2.\tRescatar" << endl;
	cout << "3.\tBuscar" << endl;
	cout << "4.\tCuidar" << endl;
	cout << "5.\tAdoptar" << endl;
	cout << "6.\tGuardar y salir" << endl << endl;
}

void Menu::listar () {
	if (refugio.vacia())
		cout << "El refugio no posee animales por el momento, no se puede realizar dicha accion." << endl;
	else {
		pasar_tiempo();
	
		Nodo* auxiliar = refugio.obtener_primero();
		
		cout << endl << "Nombre         Edad           Tamanio        Especie        Personalidad   Hambre         Higiene" << endl;
	
		while (auxiliar != NULL) {
			( auxiliar -> obtener_dato() )-> caracteristicas();
	
			auxiliar = auxiliar -> obtener_siguiente();
		}
	}

	presionar_enter ();
}

void Menu::rescatar () {
	if (!refugio.vacia()) 
		pasar_tiempo();

	Descripcion nuevo_animal;
	
	cout << endl << "Ingrese un nombre:" << endl;

	cin.ignore();

	getline(cin, nuevo_animal.nombre);
	
	while ( refugio.consulta(nuevo_animal.nombre) && (nuevo_animal.nombre != "0") ) {
		cout << "El animal de nombre " << refugio.consulta(nuevo_animal.nombre) -> obtener_nombre() << " ya existe, ingrese uno nuevo o ingrese 0 para volver al menu:" << endl;

		getline(cin, nuevo_animal.nombre);
	}
	
	if (nuevo_animal.nombre != "0") {
		system("clear");

		nuevo_animal.edad = ingresar_edad ();
		
		system("clear");

		nuevo_animal.tamanio = ingresar_tamanio ();
		
		system("clear");

		nuevo_animal.especie = ingresar_especie ();
		
		system("clear");

		nuevo_animal.personalidad = ingresar_personalidad ();

		agregar_animal (nuevo_animal.especie, nuevo_animal);

		cout << endl << nuevo_animal.nombre << " fue rescatado con exito." << endl;
	}

	presionar_enter ();
}

void Menu::buscar () {
	if (refugio.vacia())
		cout << "El refugio no posee animales por el momento, no se puede realizar dicha accion." << endl;
	else {
		pasar_tiempo();
	
		string nombre;
	
		cout << endl << "Ingrese el nombre del animal:" << endl;
		
		cin.ignore();
		
		getline(cin, nombre);
	
		system("clear");
	
		if ( refugio.consulta(nombre) ) {
			cout << "Nombre         Edad           Tamanio        Especie        Personalidad   Hambre         Higiene" << endl;
			refugio.consulta(nombre)->caracteristicas();
		}
		else
			cout << endl << "Error dicho animal no se encuentra en el refugio." << endl;
	}
	presionar_enter ();
}

void Menu::cuidar () {
	if (refugio.vacia())
		cout << "El refugio no posee animales por el momento, no se puede realizar dicha accion." << endl;
	else {
		pasar_tiempo();
		
		int accion = 0;
	
		while (accion != REGRESAR) {
			mostrar_mini_menu ();
	
			accion = accion_mini_menu ();
			
			switch (accion) {
				case ELEGIR:
					elegir_individualmente ();
					
					presionar_enter ();
	
					system("clear");
					break;
				case ALIMENTAR:
					alimentar_a_todos ();
					
					presionar_enter ();
	
					system("clear");
					break;
				case BANIAR:
					baniar_a_todos ();
					
					presionar_enter ();
	
					system("clear");
					break;
				default :
					presionar_enter ();
			}
		}
	}
}

void Menu::adoptar () {
	if (refugio.vacia())
		cout << "El refugio no posee animales por el momento, no se puede realizar dicha accion." << endl;
	else {
		pasar_tiempo();
		
		int espacio_disponible = ingresar_metros();
	
		int contador = 1;
	
		string opciones_adopcion[refugio.obtener_cantidad()];
	
		asignar_posibles_adoptados(espacio_disponible, opciones_adopcion, contador);
	
		mostrar_posibles_adoptados (opciones_adopcion, contador);
	
		int opcion = corroborar_adopcion (contador);
	
		if (opcion) {
			refugio.baja(opciones_adopcion[opcion - 1]);
	
			cout << "Has adoptado a: " << opciones_adopcion[opcion - 1] << endl;
		}
	}
	presionar_enter ();
}

bool Menu::guardar_salir () {
	ofstream refugio_actualizado (NOMBRE_ARCHIVO);
	
	if (!refugio_actualizado.is_open()){
		cout << "Error al escribir el archivo." << endl;
		return false;
	}

	Nodo* auxiliar = refugio.obtener_primero();

	Animal* animal;

	while (auxiliar != NULL) {
		animal = ( auxiliar -> obtener_dato() );
		
		refugio_actualizado << animal -> obtener_nombre() << DELIMITADOR << animal -> obtener_edad() << DELIMITADOR << animal -> obtener_tamanio() << DELIMITADOR << (animal -> obtener_especie())[0] << DELIMITADOR << animal -> obtener_personalidad() << endl;

		auxiliar = auxiliar -> obtener_siguiente();
	}

	refugio_actualizado.close();

	return true;
}

void Menu::presionar_enter () {
	string continuar;

	cout << endl << "Presione ENTER para continuar." << endl;

	cin.ignore();
	
	getline(cin, continuar);
}

int Menu::pedir_accion () {
	int accion;

	cout << "Ingrese el numero correspondiente a la accion que desea realizar." << endl;

	cin >> accion;

	return accion;
}

void Menu::validar_accion_menu (int &accion) {
	while ( (accion < LISTAR) || (accion > GUARDAR_SALIR) ) {
		system("clear");

		cout << "Error opcion invalida." << endl << endl;
		
		mostrar();

		accion = pedir_accion();
	}
}

void Menu::pasar_tiempo () {
	Nodo* auxiliar = refugio.obtener_primero();

	while (auxiliar != NULL) {
		( auxiliar -> obtener_dato() )-> modificar_higiene_hambre();

		auxiliar = auxiliar -> obtener_siguiente();
	}
}

void Menu::agregar_animal (char especie, Descripcion caracteristicas) {
	Animal* animal;

	switch (especie) {
		case PERRO :
			animal = new Perro(caracteristicas.nombre, caracteristicas.edad, caracteristicas.tamanio, caracteristicas.personalidad);
			break;
		case GATO :
			animal = new Gato(caracteristicas.nombre, caracteristicas.edad, caracteristicas.tamanio, caracteristicas.personalidad);
			break;
		case CABALLO :
			animal = new Caballo(caracteristicas.nombre, caracteristicas.edad, caracteristicas.tamanio, caracteristicas.personalidad);
			break;
		case ROEDOR :
			animal = new Roedor(caracteristicas.nombre, caracteristicas.edad, caracteristicas.tamanio, caracteristicas.personalidad);
			break;
		case CONEJO :
			animal = new Conejo(caracteristicas.nombre, caracteristicas.edad, caracteristicas.tamanio, caracteristicas.personalidad);
			break;
		case ERIZO :
			animal = new Erizo(caracteristicas.nombre, caracteristicas.edad, caracteristicas.tamanio, caracteristicas.personalidad);
			break;
		default	:
			animal = new Lagartija(caracteristicas.nombre, caracteristicas.edad, caracteristicas.tamanio, caracteristicas.personalidad);
	}

	refugio.alta(animal);
}

void Menu::crear_refugio (ifstream &reserva) {
	Descripcion caracteristicas;
	string edad;
	string especie;

	while ( getline (reserva, caracteristicas.nombre, DELIMITADOR) ) {
		getline (reserva, edad, DELIMITADOR);
		getline (reserva, caracteristicas.tamanio, DELIMITADOR);
		getline (reserva, especie, DELIMITADOR);
		getline (reserva, caracteristicas.personalidad);

		caracteristicas.edad = stoi(edad);
		caracteristicas.especie = especie[0];
		
		agregar_animal (caracteristicas.especie, caracteristicas);
	}
}

int Menu::procesar_archivo () {
	ifstream reserva (NOMBRE_ARCHIVO);
	
	if ( !reserva.is_open() ){
		cout << "Error al abrir el archivo." << endl << endl;
		return 1;
	}

	crear_refugio(reserva);

	reserva.close();

	return 0;
}

int Menu::ingresar_edad () {
	int edad_solicitada;

	cout << "La edad debe estar entre 0 y 100, ambos inclusive" << endl;
	cout << "Ingrese edad:" << endl;

	cin >> edad_solicitada;
	
	validar_edad(edad_solicitada);

	return edad_solicitada;
}

string Menu::ingresar_tamanio () {
	string tamanio_solicitado;

	cout << "Listado de tamanios" << endl << endl;
	cout << "diminuto" << endl << "pequenio" << endl << "mediano" << endl << "grande" << endl << "gigante" << endl;
	cout  << endl << "Ingrese tamanio:" << endl;
	
	cin >> tamanio_solicitado;
	
	validar_tamanio(tamanio_solicitado);

	return tamanio_solicitado;
}

char Menu::ingresar_especie () {
	char especie_solicitada;

	cout << "Listado de especie" << endl;
	cout << endl << "P = perro" << endl << "G = gato" << endl << "C = Caballo" << endl << "R = Roedor" << endl << "O = Conejo" << endl << "E = Erizo" << endl << "L = Lagartija" << endl;
	cout  << endl << "Ingrese especie:" << endl;
	
	cin >> especie_solicitada;
	
	validar_especie(especie_solicitada);

	return especie_solicitada;
}

string Menu::ingresar_personalidad () {
	string personalidad_solicitada;

	cout << "Listado de personalidades" << endl;
	cout << endl << "dormilon" << endl << "jugueton" << endl << "sociable" << endl << "travieso" << endl;
	cout  << endl << "Ingrese personalidad:" << endl;
	
	cin >> personalidad_solicitada;
	
	validar_personalidad(personalidad_solicitada);

	return personalidad_solicitada;
}

void Menu::validar_edad(int &edad_solicitada){
	while( (edad_solicitada < MINIMO) || (edad_solicitada > MAXIMO) ){
		cout << "El numero ingresado no es valido, ingrese nuevamente:" << endl;
		
		cin >> edad_solicitada;
	}
}

void Menu::validar_tamanio(string &tamanio_solicitado){
	while( !( (tamanio_solicitado == DIMINUTO) || (tamanio_solicitado == PEQUENIO) || (tamanio_solicitado == MEDIANO) || (tamanio_solicitado == GRANDE) || (tamanio_solicitado == GIGANTE) ) ){
		cout << "Tamanio ingresado invalido, ingrese nuevamente:" << endl;
		
		cin >> tamanio_solicitado;
	}
}

void Menu::validar_especie(char &especie_solicitada){
	while ( !( (especie_solicitada == PERRO) || (especie_solicitada == GATO) || (especie_solicitada == CABALLO) || (especie_solicitada == ROEDOR) || (especie_solicitada == CONEJO) || (especie_solicitada == ERIZO) || (especie_solicitada == LAGARTIJA) ) ) {
		cout << "Especie invalido, ingrese nuevamente:" << endl;
		
		cin >> especie_solicitada;
	}
}

void Menu::validar_personalidad(string &personalidad_solicitada){
	while( !( (personalidad_solicitada == DORMILON) || (personalidad_solicitada == JUGUETON) || (personalidad_solicitada == SOCIABLE) || (personalidad_solicitada == TRAVIESO) ) ){
		cout << "Personalidad invalida, ingrese nuevamente:" << endl;
		
		cin >> personalidad_solicitada;
	}
}

void Menu::mostrar_mini_menu () {
	cout << "1.\tElegir individualmente." << endl;
	cout << "2.\tAlimentar a todos." << endl;
	cout << "3.\tBaniar a todos." << endl;
	cout << "4.\tRegresar al inicio." << endl;
}

int Menu::accion_mini_menu () {
	int accion = pedir_accion();

	validar_accion_mini_menu (accion);

	return accion;
}

void Menu::validar_accion_mini_menu (int &accion) {
	while ( (accion < ELEGIR) || (accion > REGRESAR) ) {
		system("clear");

		cout << "Error opcion invalida." << endl << endl;
		
		mostrar_mini_menu();

		accion = pedir_accion();
	}
}

void Menu::elegir_individualmente () {
	Nodo* auxiliar = refugio.obtener_primero();
	
	Animal* mascota;
	
	system("clear");

	while (auxiliar != NULL) {
		mascota = auxiliar -> obtener_dato();
		
		cout << "Nombre         Edad           Tamanio        Especie        Personalidad   Hambre         Higiene" << endl;

		mascota -> caracteristicas();

		cout << endl << "1. Alimentar." << endl;
		cout << "2. Baniar." << endl;
		cout << "3. Saltear." << endl << endl;
		
		switch (accion_individual()) {
			case PRIMERA_OPCION:
				cout << endl;
				mascota -> alimentar();
				mascota -> fue_alimentado();
				
				cout << endl << "Accion realizada con exito." << endl;
				break;
			case SEGUNDA_OPCION:
				cout << endl;
				mascota -> baniar();
				mascota -> se_bania();

				cout << "Accion realizada con exito." << endl;
				break;
			default:
				auxiliar = auxiliar -> obtener_siguiente();
		}

		presionar_enter();

		system("clear");
	}
}

int Menu::accion_individual () {
	int accion = pedir_accion();

	validar_accion_individual (accion);

	return accion;
}

void Menu::validar_accion_individual (int &accion) {
	while ( (accion < PRIMERA_OPCION) || (accion > SALTEAR) ) {
		cout << "Error opcion invalida." << endl << endl;

		accion = pedir_accion();
	}
}

void Menu::alimentar_a_todos () {
	Nodo* auxiliar = refugio.obtener_primero();
	
	Animal* mascota;
	
	system("clear");
	cout << "Todos los animales fueron alimentados." << endl << endl;

	while (auxiliar != NULL) {
		mascota = auxiliar -> obtener_dato();
		mascota -> alimentar();
		mascota -> fue_alimentado();

		cout << endl;

		auxiliar = auxiliar -> obtener_siguiente();
	}
}

void Menu::baniar_a_todos () {
	Nodo* auxiliar = refugio.obtener_primero();
	
	Animal* mascota;
	
	system("clear");

	cout << "Todos los animales fueron baniados." << endl << endl;
	
	while (auxiliar != NULL) {
		mascota = auxiliar -> obtener_dato();
		mascota -> baniar();
		mascota -> se_bania();

		auxiliar = auxiliar -> obtener_siguiente();
	}
}

int Menu::ingresar_metros () {
	int metros;

	cout << "Ingrese espacio disponible, en metros cuadrados, para adoptar al animal:" << endl;

	cin >> metros;

	while(metros <= MINIMO){
		cout << "Espacio disponible invalido, ingrese nuevamente:" << endl;
	
		cin >> metros;
	}

	return metros;
}

void Menu::asignar_posibles_adoptados (int espacio_disponible, string opciones_adopcion[], int &contador) {
	Nodo* auxiliar = refugio.obtener_primero();
	
	Animal* mascota;

	while (auxiliar != NULL) {
		mascota = auxiliar -> obtener_dato();
		
		if (espacio_disponible < ESPACIO_INFERIOR) {
			if (mascota -> obtener_tamanio() == DIMINUTO || mascota -> obtener_tamanio() == PEQUENIO) {
				opciones_adopcion[contador - 1] = mascota -> obtener_nombre();
				contador++;
			}
		}
		else if (espacio_disponible >= ESPACIO_INFERIOR && espacio_disponible < ESPACIO_INTERMEDIO) {
			if(mascota -> obtener_tamanio() == DIMINUTO || mascota -> obtener_tamanio() == PEQUENIO || mascota -> obtener_tamanio() == MEDIANO) {
				opciones_adopcion[contador - 1] = mascota -> obtener_nombre();
				contador++;
			}
		}
		else if (espacio_disponible >= ESPACIO_INTERMEDIO && espacio_disponible < ESPACIO_SUPERIOR) {
			if (mascota -> obtener_tamanio() == DIMINUTO || mascota -> obtener_tamanio() == PEQUENIO || mascota -> obtener_tamanio() == MEDIANO || mascota -> obtener_tamanio() == GRANDE) {
				opciones_adopcion[contador - 1] = mascota -> obtener_nombre();
				contador++;
			}
		}
		else { 
				opciones_adopcion[contador - 1] = mascota -> obtener_nombre();
				contador++;
		}
		auxiliar = auxiliar -> obtener_siguiente();
	}
}

void Menu::mostrar_posibles_adoptados (string opciones_adopcion[], int contador) {
	system("clear");
	
	cout << "\tNombre         Edad           Tamanio        Especie        Personalidad   Hambre         Higiene" << endl;
	for (int i = 0; i < (contador - 1); i++) {
		cout << i+1 << "\t";
		refugio.consulta(opciones_adopcion[i])-> caracteristicas();
	}
}

int Menu::corroborar_adopcion (int comparador) {
	int opcion;

	cout << endl << "Ingrese el numero correspondiente al animal que desea adoptar o si quiere cancelar la opcion ingrese 0" << endl;

	cin >> opcion;

	while (opcion >= comparador || opcion < MINIMO) {
		cout << "Erro opcion invalida." << endl;
		cout << "Ingrese el numero correspondiente al animal que desea adoptar o si quiere cancelar la opcion ingrese 0" << endl;
		cin >> opcion;
	}

	return opcion;
}