#ifndef __NODO__
#define __NODO__
#include "vertice.h"

typedef Vertice Dato;
class Nodo_lista{
    //Atributos
    private:
        Nodo_lista* siguiente;
        Dato* dato;

    //Metodos
    public:
        //Constructor con parametros
        //pre: -
        //pos: Construye un nodo apuntando a null con su atributo dato en el heap
        Nodo_lista(Dato dato);

        //pre: -
        //pos: Asigna al atributo dato el parametro dato
        void cambiar_dato(Dato* dato);

        //pre: El atributo dato debe haber sido inicializado
        //pos: Devuelve el atributo dato
        Dato* obtener_dato();

        //pre: -
        //pos: Asigna al atributo siguiente el parametro nodo_siguiente
        void cambiar_siguiente(Nodo_lista* nodo_siguiente);
        
        //pre: -
        //pos: Devuelve el atributo siguiente
        Nodo_lista* obtener_siguiente();

        //Destructor
        //pre: -
        //pos: Libera la memoria de su atributo dato y luego se elimina
        ~Nodo_lista();
};

#endif