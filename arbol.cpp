#include "arbol.h"

Arbol::Arbol () {
	raiz = new Nodo();
}

Nodo* Arbol::obtener_raiz () {
    return raiz;
}

Animal* Arbol::busqueda (Nodo* actual, string nombre) {
	//se empieza a buscar siempre en la primera posicion
	int posicion = 0;

    //Incrementa el indice mientras el valor de la clave del nodo sea menor
    while (posicion < actual->obtener_cantidad_claves() && nombre > actual->obtener_clave(posicion)->obtener_nombre())
        posicion++;

    //Si la clave es igual, entonces retornamos el nodo
    if (posicion < actual->obtener_cantidad_claves() && nombre == actual->obtener_clave(posicion)->obtener_nombre())
        return actual->obtener_clave(posicion);

    //Si llegamos hasta aqui, entonces hay que buscar los hijos
    //Se revisa primero si tiene hijos
    if (actual->sera_hoja())
        return NULL;
    //Si tiene hijos, hace una llamada recursiva
    else
        return busqueda(actual->obtener_hijo(posicion), nombre);
}


void Arbol::insertar (Animal* animal) {
    Nodo* raiz_auxiliar = raiz;

    insertar_en_hoja(raiz_auxiliar, animal);

    //Si el nodo esta lleno lo debe separar
    if (raiz_auxiliar->obtener_cantidad_claves() == MAXIMAS_CLAVES) {
        Nodo* nueva_raiz = new Nodo();
        raiz = nueva_raiz;
        nueva_raiz->ramificar();
        nueva_raiz->cambiar_cantidad_claves(0);
        nueva_raiz->cambiar_hijo(0, raiz_auxiliar);
        dividir_nodo(nueva_raiz, 0, raiz_auxiliar);
    }    
}

void Arbol::insertar_en_hoja(Nodo* &actual, Animal* animal) {
    //Si es una hoja
    if (actual->sera_hoja()) {
        int posicion = actual->obtener_cantidad_claves();
        //Busca la posicion donde asignar el valor
        while (posicion >= 1 && animal->obtener_nombre() < actual->obtener_clave(posicion - 1)->obtener_nombre()) {
            actual->cambiar_clave(posicion, actual->obtener_clave(posicion - 1));//Desplaza los valores mayores a nombre
            posicion--;
        }

        actual->cambiar_clave(posicion, animal);
        actual->cambiar_cantidad_claves(actual->obtener_cantidad_claves() + 1);
    }
    else {
        int posicion_hijo = 0;
        //Busca la posicion del hijo
        while (posicion_hijo < actual->obtener_cantidad_claves() && (animal->obtener_nombre() > (actual->obtener_clave(posicion_hijo)->obtener_nombre())))
            posicion_hijo++;

        Nodo* hijo_auxiliar = actual->obtener_hijo(posicion_hijo);

        insertar_en_hoja(hijo_auxiliar, animal);

        //Si el nodo hijo esta lleno lo divide
        if (actual->obtener_hijo(posicion_hijo)->obtener_cantidad_claves() == MAXIMAS_CLAVES)
            dividir_nodo(actual, posicion_hijo, hijo_auxiliar);
    }
}

void Arbol::dividir_nodo (Nodo* &padre, int posicion_hijo, Nodo* &hijo) {
    //Nodo temporal que sera el hijo[posicion_hijo + 1] de padre
    Nodo* auxiliar = new Nodo();
    
    if (!hijo->sera_hoja())
        auxiliar->ramificar();

    auxiliar->cambiar_cantidad_claves(1);

    //Copia la ultima clave del nodo hijo al inicio del nodo auxiliar
    auxiliar->cambiar_clave(0, hijo->obtener_clave(2));

    //Si no es hoja hay que reasignar los nodos hijos
    if (!hijo->sera_hoja()) {
        for (int k = 0; k < 2; k++)
            auxiliar->cambiar_hijo(k, hijo->obtener_hijo(k + 2));
    }

    //Nuevo tamanio de hijo
    hijo->cambiar_cantidad_claves(1);

    //Mueve los hijos de padre para darle espacio a auxiliar
    for (int j = padre->obtener_cantidad_claves(); j > posicion_hijo; j--)
        padre->cambiar_hijo(j + 1, padre->obtener_hijo(j));

    //Reasigna el hijo[posicion_hijo + 1] de padre
    padre->cambiar_hijo(posicion_hijo + 1, auxiliar);

    //Mueve las claves de padre
    for (int j = padre->obtener_cantidad_claves(); j > posicion_hijo; j--)
        padre->cambiar_clave(j + 1, padre->obtener_clave(j));

    //Agrega la clave situada en el medio
    padre->cambiar_clave(posicion_hijo, hijo->obtener_clave(1));
    padre->cambiar_cantidad_claves(padre->obtener_cantidad_claves() + 1);
}

bool Arbol::memoria_liberada (Nodo* &candidato) {
    bool liberado = candidato->sera_hoja();

    if (!liberado) {
        int contador = 0;

        while (contador < candidato->obtener_cantidad_claves()) {
            Nodo* auxiliar = candidato->obtener_hijo(contador);

            if (memoria_liberada(auxiliar))
                contador++;
        }
        
        liberado = true;
    }

    for (int i = 0; i < candidato->obtener_cantidad_claves(); i++) {
        if (candidato->obtener_clave(i) != NULL) 
            delete candidato->obtener_clave(i);
    }

    if (candidato != NULL)
        delete candidato; 


    return liberado;
}

void Arbol::mostrar_arbol () {
    mostrar_subarbol(raiz);
}

void Arbol::mostrar_subarbol (Nodo* actual) {
    for (int i = 0; i < actual->obtener_cantidad_claves(); i++)
        actual->obtener_clave(i)->caracteristicas();

    //Si no es hoja
    if (!actual->sera_hoja()) {
        //recorre los nodos para saber si tiene hijos
        for (int j = 0; j <= actual->obtener_cantidad_claves(); j++) {
            if (actual->obtener_hijo(j) != NULL)
                mostrar_subarbol(actual->obtener_hijo(j));
        }
    }
}

Arbol::~Arbol () {
    if (memoria_liberada(raiz))
        raiz = nullptr;
}