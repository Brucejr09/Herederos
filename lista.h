#ifndef __LISTA__
#define __LISTA__
#include "nodo_lista.h"

class Lista{
    //Atributos
    private:
        Nodo_lista* primero;
        Nodo_lista* actual;
        int cantidad;

    //Metodos
    public:
        //Constructor sin parametros.
        //pre: -
        //pos: Construye una lista vacia apuntando a 0 con 0 elementos.
        Lista();

        //pre: 0 <= posicion <= (cantidad-1).
        //pos: Devuelve un puntero al nodo de la lista en la posicion del parametro posicion.
        Nodo_lista* obtener_nodo(int posicion);

        //pre: -
        //pos: Devuelve la cantidad de nodos.
        int obtener_cantidad();

        //Agrega un nodo.
        //pre: 0 <= posicion <= cantidad.
        //pos: Se crea y agrega un nodo con dato = dato en posicion del parametro posicion reestructurando la lista.
        void alta(Dato dato, int posicion);

        //Elimina un nodo
        //pre: 0 <= posicion <= (cantidad-1).
        //pos: Se elimina el nodo en la posicion del parametro posicion y reestructura la lista.
        void baja(int posicion);

        //pre: 0 <= posicion < cantidad.
        //pos: Devuelve el dato del nodo en la posicion del parametro posicion.
        Dato* consulta(int posicion);

        //pre: -
        //pos: Devuelve true si la lista esta vacia, false sino.
        bool vacia();
        
        //pre: -
        //pos: Apunta actual al primer nodo de la lista.
        void reiniciar_actual();

        //pre: -
        //pos: Devuelve true si hay un nodo despues de actual, false sino.
        bool hay_siguiente_actual();

        //pre: -
        //pos: Devuelve el dato de actual.
        Dato* obtener_dato_actual();

        //pre: Debe haber un nodo despues de actual.
        //pos: Apunta actual al siguiente nodo.
        void siguiente_actual();

        //Destruye la lista.
        //pre: -
        //pos:Destruye la lista y libera la memoria reservada de cada nodo.
        ~Lista();
};
#endif