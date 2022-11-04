#include "lista.h"

Lista::Lista() {
    primero = 0;
    ultimo = 0;
    cantidad = 0;
}

Lista::~Lista() {
    Nodo* auxiliar;

    while (!vacia()){
        auxiliar = primero->obtener_siguiente();

        delete primero->obtener_dato();
        delete primero; 

        primero = auxiliar;

        cantidad--;
    }
}

void Lista::alta(Animal* animal) {
    Nodo* nuevo = new Nodo(animal);
   
    if (vacia()) 
        primero = nuevo;
    else
        ultimo->cambiar_siguiente(nuevo);

    ultimo = nuevo;
    cantidad++;
}

Animal* Lista::consulta(string nombre) {
    if ( !vacia() ) {
    	Nodo* nodo = obtener_nodo(nombre);
    
        if (nodo)
        	return (nodo->obtener_dato());
        else
        	return 0;
    }
    else
    	return 0;
}

void Lista::baja(string nombre) {
    if ( !vacia() ) {
    	Nodo* nodo = obtener_nodo(nombre);
        
        if (nodo) {
    	    if (nodo == primero) {
    	    	primero = nodo->obtener_siguiente();
    	    }
    	    else {
    	    	Nodo* anterior = obtener_nodo_anterior(nodo);
   	        	anterior->cambiar_siguiente( nodo->obtener_siguiente() );
   	        }

   	        delete nodo->obtener_dato();
    	   	delete nodo;
    	            	
    	    cantidad--;
        }
    }
}

bool Lista::vacia() {
    return (cantidad == 0);
}

Nodo* Lista::obtener_primero() {
	return primero;
}

int Lista::obtener_cantidad () {
	return cantidad;
}

Nodo* Lista::obtener_nodo(string nombre) {
	bool encontrado = false;
    Nodo* auxiliar = primero;

    while ( (auxiliar != NULL) && (!encontrado) ) {
    	if ( (( auxiliar->obtener_dato() )-> obtener_nombre()) == nombre)
    		encontrado = true;
    	else
            auxiliar = auxiliar->obtener_siguiente();
    }

    if (!encontrado)
    	auxiliar = 0;

    return auxiliar;
}

Nodo* Lista::obtener_nodo_anterior(Nodo* actual) {
	Nodo* auxiliar = primero;

	while ( (auxiliar->obtener_siguiente()) != actual)
		auxiliar = auxiliar->obtener_siguiente();
    
    return auxiliar;
}