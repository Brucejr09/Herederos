#include "menu.h"

Menu::Menu () {
	combustible = 100;
	escapados = 0;
	cancelado = false;
}

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
	cout << "6.\tCargar combustible" << endl;
	cout << "7.\tGuardar y salir" << endl << endl;
}

void Menu::listar () {
	system("clear");

	Nodo* temporal = diccionario.obtener_raiz();
	
	pasar_tiempo(temporal);
		
	cout << endl << "Nombre         Edad           Tamanio        Especie        Personalidad   Hambre         Higiene        Estado" << endl;
	
	diccionario.mostrar_arbol();

	presionar_enter ();
}

void Menu::rescatar () {
	system("clear");

	Nodo* temporal = diccionario.obtener_raiz();
	
	pasar_tiempo(temporal);

	cout << endl;

	Mapa mapa;

	Animal* rescatado;
	
	int fila, columna;

	bool animal_rescatado = false;
	
	do{
		mapa.imprimir_terreno();
		std::cout << "Fila: " << mapa.obtener_vehiculo()->obtener_posicion()->obtener_fila() << std::endl;
		std::cout << "Columna: " << mapa.obtener_vehiculo()->obtener_posicion()->obtener_columna() << std::endl;
		std::cout << "Ingrese a que fila desea desplazarse o -1 si desea cancelar." << std::endl;
		std::cin >> fila;
		if(fila!=-1){
			mapa.floyd(8);
			std::cout << "Ingrese a que columna desea desplazarse." << std::endl;
			std::cin >> columna;
			if(combustible > MINIMO){
				mapa.obtener_vehiculo()->cambiar_posicion(fila, columna);
				//Imprimir_viaje();
				if(mapa.obtener_terreno()[mapa.obtener_vehiculo()->obtener_posicion()->obtener_fila()][mapa.obtener_vehiculo()->obtener_posicion()->obtener_columna()].hay_animal()){
					string ignorar;
					rescatado = mapa.obtener_terreno()[mapa.obtener_vehiculo()->obtener_posicion()->obtener_fila()][mapa.obtener_vehiculo()->obtener_posicion()->obtener_columna()].eliminar_animal();
					std::cout << "Animal " << rescatado->obtener_nombre() << " con exito!" << std::endl;
					std::cout << "Ingrese un dato para continuar..." << std::endl;
					std::cin >> ignorar;
					animal_rescatado = true;
				}
			} else {
				std::cout << "No se cuenta con el combustible necesario para ir a la posicion ingresada, se necesitan: " /* coste_combustible */ << std::endl;
			}
			combustible -= 50;
		}
	}while(fila!=-1);

	if (animal_rescatado) {
		if (diccionario.busqueda(diccionario.obtener_raiz(), rescatado->obtener_nombre()))
			cout << "Dicho animal ya esta en la reserva no podemos agregarlo" << endl;
		else {
			diccionario.insertar(rescatado);
		
			cout << "El animal fue agregado con exito a la reserva" << endl;
		}
	}	

	presionar_enter ();
}

void Menu::buscar () {	
	system("clear");
	
	Nodo* temporal = diccionario.obtener_raiz();
	
	pasar_tiempo(temporal);
	
	cout << endl;

	string nombre;
	
	cout << endl << "Ingrese el nombre del animal:" << endl;
		
	cin.ignore();
		
	getline(cin, nombre);
	
	system("clear");
	
	Animal* animal = diccionario.busqueda(diccionario.obtener_raiz(), nombre);

	if (animal) {
		if (animal->obtener_adoptado())
			cout << "Error dicho animal fue adoptado ya no se encuentra en el refugio." << endl;
		else {
			cout << "Nombre         Edad           Tamanio        Especie        Personalidad   Hambre         Higiene        Estado" << endl;
			animal->caracteristicas();
		}
	}
	else
		cout << endl << "Error dicho animal no se encuentra en el refugio." << endl;

	presionar_enter ();
}

void Menu::cuidar () {
	system("clear");

	Nodo* temporal = diccionario.obtener_raiz();
	
	pasar_tiempo(temporal);
	
	cout <<	endl;

	int accion = 0;

	bool salir = false;

	while (accion != REGRESAR && !salir) {
		mostrar_mini_menu ();
	
		accion = accion_mini_menu ();
			
		if (accion == ELEGIR)
			elegir_individualmente (diccionario.obtener_raiz(), salir);
					
		presionar_enter ();
	
		system("clear");
	}
}	


void Menu::adoptar () {
	system("clear");

	Nodo* temporal = diccionario.obtener_raiz();

	pasar_tiempo(temporal);

	cout << endl;

	int espacio_disponible = ingresar_metros();
		
	int total_animales = 100;

	int cantidad_adoptados = 0; // contador de animales a adoptar
		
	Animal** posibles_adoptados = new Animal*[total_animales]; // creo vector de punteros a animales, su tamaño es el total de animales existentes
	Nodo* auxiliar = diccionario.obtener_raiz();

	asignar_posibles_adoptados(auxiliar, espacio_disponible, posibles_adoptados, cantidad_adoptados);
		
	ordenar_posibles_adoptados(posibles_adoptados, cantidad_adoptados);
	
	mostrar_posibles_adoptados(posibles_adoptados, cantidad_adoptados);
	
	int opcion = corroborar_adopcion (cantidad_adoptados);
	
	if (opcion >= 0) { // recorrer el arbol diccionario y encontrar el nodo que contenga el animal con el nombre de posibles_adoptados[opcion]
		string nombre_animal_adoptar = posibles_adoptados[opcion] -> obtener_nombre();
			
		cout << "Has adoptado a: " << nombre_animal_adoptar << endl;
			
		diccionario.busqueda(diccionario.obtener_raiz(), nombre_animal_adoptar) -> fue_adoptado();
	}

	// libero memoria 
	for(int i = cantidad_adoptados + 1; i < total_animales + 1; i++)
		delete posibles_adoptados[i];

	delete[] posibles_adoptados;
	
	presionar_enter ();
}

void Menu::cargar_combustible () {
	system("clear");

	Nodo* temporal = diccionario.obtener_raiz();
	
	pasar_tiempo(temporal);

	cout << endl;

	if (combustible != MAXIMO) {
		agregar_combustible(pedir_combustible());
	
		cout << "La carga fue realizada con exito" << endl;
	}
	else
		cout << "El tanque esta lleno no puede agregarle mas combustible" << endl;
	
	presionar_enter ();
}

bool Menu::guardar_salir () {
	ofstream refugio_actualizado (NOMBRE_ARCHIVO);
	
	if (!refugio_actualizado.is_open()){
		cout << "Error al escribir el archivo." << endl;
			return false;
	}
	
	actualizar_archivo(diccionario.obtener_raiz(), refugio_actualizado);

	refugio_actualizado.close();

	return true;
}

bool Menu::clausurado () {
	if (cancelado) {
		Nodo* temporal = diccionario.obtener_raiz();
	
		clausurar(temporal);
	}

	return cancelado;
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

void Menu::pasar_tiempo (Nodo* &actual) {
	for (int i = 0; i < actual->obtener_cantidad_claves(); i++){
		actual->obtener_clave(i)-> modificar_higiene_hambre();
		agregar_combustible(5);

		if ((actual->obtener_clave(i)->obtener_hambre() == MAXIMO || actual->obtener_clave(i)->obtener_higiene() == MINIMO) && !actual->obtener_clave(i)->obtener_adoptado()) {
			escapados++;
			cout << "CUIDADO!!! Se escapo " << actual->obtener_clave(i)->obtener_nombre() << " de la reserva, en total ya se escaparon: " << escapados << endl;
			actual->obtener_clave(i)->fue_adoptado();

			if (escapados == 3)
				cancelado = true;
		}
	}

    //Si no es hoja
    if (!actual->sera_hoja()) {
        //recorre los nodos para saber si tiene hijos
        for (int j = 0; j <= actual->obtener_cantidad_claves(); j++) {
            if (actual->obtener_hijo(j) != NULL) {
                Nodo* auxiliar = actual->obtener_hijo(j);
                pasar_tiempo(auxiliar);
            }
        }
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

	diccionario.insertar(animal);
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
	cout << "2.\tRegresar al inicio." << endl;
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

void Menu::elegir_individualmente (Nodo* actual, bool &salir) {
	system("clear");

	int contador = 0;
	
	while (contador < actual->obtener_cantidad_claves() && !salir){
		if (!actual->obtener_clave(contador)->obtener_adoptado()) {
			cout << "Nombre         Edad           Tamanio        Especie        Personalidad   Hambre         Higiene        Estado" << endl;
			
			actual->obtener_clave(contador)->caracteristicas();
		
			cout << endl << "1. Alimentar." << endl;
			cout << "2. Baniar." << endl;
			cout << "3. Saltear." << endl;
			cout << "4. Regresar al menu principal." << endl << endl;
				
			switch (accion_individual()) {
				case PRIMERA_OPCION:
					cout << endl;
					actual->obtener_clave(contador)->alimentar();
					actual->obtener_clave(contador)->fue_alimentado();
							
					cout << endl << "Accion realizada con exito." << endl;
					break;
				case SEGUNDA_OPCION:
					cout << endl;
					actual->obtener_clave(contador)->baniar();
					actual->obtener_clave(contador)->se_bania();
		
					cout << "Accion realizada con exito." << endl;
					break;
				case TERCERA_OPCION:
					break;
				default:
					salir = true;
			}
		
			presionar_enter();
		}
		
		contador++;
	
		system("clear");
	}

	if (!actual->sera_hoja() && !salir) {
		int contador_secundario = 0;

		while (contador_secundario <= actual->obtener_cantidad_claves() && !salir) {
		    if (actual->obtener_hijo(contador_secundario) != NULL)
	   		    elegir_individualmente(actual->obtener_hijo(contador_secundario), salir);
	   		contador_secundario++;
		}
	}
}

int Menu::accion_individual () {
	int accion = pedir_accion();

	validar_accion_individual (accion);

	return accion;
}

void Menu::validar_accion_individual (int &accion) {
	while ( (accion < PRIMERA_OPCION) || (accion > CUARTA_OPCION) ) {
		cout << "Error opcion invalida." << endl << endl;

		accion = pedir_accion();
	}
}

void Menu::actualizar_archivo (Nodo* actual, ofstream &refugio_actualizado) {
	for (int i = 0; i < actual->obtener_cantidad_claves(); i++){
		if (!actual->obtener_clave(i) -> obtener_adoptado())
			refugio_actualizado << (actual->obtener_clave(i) -> obtener_nombre()) << DELIMITADOR << (actual->obtener_clave(i) -> obtener_edad()) << DELIMITADOR << (actual->obtener_clave(i) -> obtener_tamanio()) << DELIMITADOR << ((actual->obtener_clave(i) -> obtener_especie())[0]) << DELIMITADOR << (actual->obtener_clave(i) -> obtener_personalidad()) << endl;
	}

    //Si no es hoja
    if (!actual->sera_hoja()) {
        //recorre los nodos para saber si tiene hijos
        for (int j = 0; j <= actual->obtener_cantidad_claves(); j++) {
            if (actual->obtener_hijo(j) != NULL)
                actualizar_archivo(actual->obtener_hijo(j), refugio_actualizado);
        }
    }
}

void Menu::validar_combustible (int &carga) {
	while (carga <= MINIMO || (combustible + carga) > MAXIMO ) {
		if (carga <= MINIMO)
			cout << "No puede quitarle o no agregarle combustible al tanque" << endl;
		else
			cout << "El combustible que quiere agregar excede el limite del tanque reduzca su pedido" << endl;
		
		cout << "Ingrese nuevamente la cantidad de combustible que desea agregar. Recuerde que ya hay una cantidad de " << combustible << endl;

		cin >> carga;

		system("clear");
	}
}

int Menu::pedir_combustible () {
	int carga;

	cout << "El combustible actual es: " << combustible << endl;
	cout << "Ingrese la cantidad de combustible que desea agregar" << endl;

	cin >> carga;

	system("clear");

	validar_combustible (carga);

	return carga;
}

void Menu::agregar_combustible (int carga) {
	combustible += carga;

	if (combustible > MAXIMO)
		combustible = MAXIMO;
}

void Menu::clausurar (Nodo* &actual) {
	for (int i = 0; i < actual->obtener_cantidad_claves(); i++)
		actual->obtener_clave(i)->fue_adoptado();

    //Si no es hoja
    if (!actual->sera_hoja()) {
        //recorre los nodos para saber si tiene hijos
        for (int j = 0; j <= actual->obtener_cantidad_claves(); j++) {
            if (actual->obtener_hijo(j) != NULL) {
                Nodo* auxiliar = actual->obtener_hijo(j);
                clausurar(auxiliar);
            }
        }
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

void Menu::asignar_posibles_adoptados (Nodo* actual, int espacio_disponible, Animal** posibles_adoptados, int &cantidad_adoptados) {
	Animal* mascota;

	for (int i = 0; i < actual->obtener_cantidad_claves(); i++) {
	    mascota = actual->obtener_clave(i);
	
	    if (!mascota -> obtener_adoptado()){
	    	if (espacio_disponible < ESPACIO_INFERIOR) {
	    		if (mascota -> obtener_tamanio() == DIMINUTO || mascota -> obtener_tamanio() == PEQUENIO) {
	    			posibles_adoptados[cantidad_adoptados] = mascota;
	    			cantidad_adoptados++;
	    		}
	    	}
	    	else if (espacio_disponible >= ESPACIO_INFERIOR && espacio_disponible < ESPACIO_INTERMEDIO) {
	    		if(mascota -> obtener_tamanio() == DIMINUTO || mascota -> obtener_tamanio() == PEQUENIO || mascota -> obtener_tamanio() == MEDIANO) {
	    			posibles_adoptados[cantidad_adoptados] = mascota;
	    			cantidad_adoptados++;
	    		}
	    	}
	    	else if (espacio_disponible >= ESPACIO_INTERMEDIO && espacio_disponible < ESPACIO_SUPERIOR) {
	    		if (mascota -> obtener_tamanio() == DIMINUTO || mascota -> obtener_tamanio() == PEQUENIO || mascota -> obtener_tamanio() == MEDIANO || mascota -> obtener_tamanio() == GRANDE) {
	    			posibles_adoptados[cantidad_adoptados] = mascota;
	    			cantidad_adoptados++;
	    		}
	    	}
	    	else { 
	    			posibles_adoptados[cantidad_adoptados] = mascota;
	    			cantidad_adoptados++;
	    	}
	    }
	}

    //Si no es hoja
    if (!actual->sera_hoja()) {
        //recorre los nodos para saber si tiene hijos
        for (int j = 0; j <= actual->obtener_cantidad_claves(); j++) {
            if (actual->obtener_hijo(j) != NULL)
                asignar_posibles_adoptados(actual->obtener_hijo(j), espacio_disponible, posibles_adoptados, cantidad_adoptados);
        }
    }
}

void Menu::ordenar_posibles_adoptados(Animal** posibles_adoptados, int cantidad_adoptados){
	
	Animal* mascota_insertar;
	int contador_aux;
	
	for(int i = 1; i < cantidad_adoptados; i++){
		
		contador_aux = i;
		mascota_insertar = posibles_adoptados[i];
		
		while(contador_aux > 0 && (mascota_insertar -> obtener_edad()) > (posibles_adoptados[contador_aux - 1] -> obtener_edad()) ){
			posibles_adoptados[contador_aux] = posibles_adoptados[contador_aux - 1];
			contador_aux--;
		}
		
		posibles_adoptados[contador_aux] = mascota_insertar;
	}
}

void Menu::mostrar_posibles_adoptados (Animal** posibles_adoptados, int cantidad_adoptados) {
	//system("clear");
	
	cout << "\tNombre         Edad           Tamanio        Especie        Personalidad   Hambre         Higiene        Estado" << endl;
	for (int i = 0; i < (cantidad_adoptados); i++) {
		cout << i << "\t";
		posibles_adoptados[i] -> caracteristicas();
	}	
}

int Menu::corroborar_adopcion (int comparador) {
	int opcion;

	cout << endl << "Ingrese el numero correspondiente al animal que desea adoptar o si quiere cancelar la opcion ingrese -1" << endl;

	cin >> opcion;

	while (opcion > comparador || opcion < (MINIMO - 1)) {
		cout << "Error opcion invalida." << endl;
		cout << "Ingrese el numero correspondiente al animal que desea adoptar o si quiere cancelar la opcion ingrese -1" << endl;
		cin >> opcion;
	}

	return opcion;
}