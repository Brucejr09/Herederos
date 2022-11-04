#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

class Lista {
        //Atributos
    private:
        Nodo* primero;
        Nodo* ultimo;
        int cantidad;

        //Metodos
    public:
        //Constructor de Lista
        /*
         *POST:
         *      Construye un objeto Lista vacia
         */
        Lista();

        //Destructor de Lista
        /*
         *POST:
         *      Destruye el objeto Lista y a su vez libera el espacio de memoria dinamica pedido
         */
        ~Lista();

        //Agrega un Nodo a la lista
        /*
         *PRE:
         *      Recibe una direccion de memoria de un objeto de Animal para poder instanciar un objeto de Nodo
         *POST:
         *      Instancia un nuevo objeto de Nodo con memoria dinamica, lo agrega a la lista y aumenta el atributo cantidad
         */
        void alta(Animal* animal);

        //Devuelve una direccion de memoria de un objeto de Animal
        /*
         *PRE:
         *      Recibe string para poder hacer la comparacion
         *POST:
         *      En caso de existir el string recibido devuelve una direccion de memoria de un objeto de Animal, en caso contrario devuelve 0. Tambien devolvera 0 si la lista esta vacia.
         */
        Animal* consulta(string nombre);

        //Quita un Nodo de la lista
        /*
         *PRE:
         *      Recibe string para poder hacer la comparacion y la lista no debe estar vacia
         *POST:
         *      Si existe el string, busca el nodo anterior y a dicho nodo le asigana su atributo siguiente la direccion de memoria del siguiente nodo al que queremos dar de baja, se elimina de la lista el nodo que queremos dar de baja, se libera la memoria dinamica reservada y se diminuye la cantidad
         */
        void baja(string nombre);

        //Corrobora si la lista esta vacia
        /*
         *POST:
         *      Devuelve true si el atributo cantidad es igual a 0, en caso cotrario devuelve false
         */
        bool vacia();

        //Devuelve la direccion de memoria del primer nodo de la lista
        /*
         *POST:
         *      Devuelve la direccion de memoria del primer nodo de la lista si no hay un primer nodo devuelve 0
         */
        Nodo* obtener_primero();

        //Devuelve la cantidad de nodos que hay en la lista
        /*
         *POST:
         *      Devuelve la cantidad de nodos que hay en la lista
         */
        int obtener_cantidad();

    private:
        //Devuelve la direccion de memoria del nodo buscado en la lista
        /*
         *PRE:
         *      Recibe string para poder hacer la comparacion
         *POST:
         *      Si se encuentra el string recibido en las comparaciones se devuelve la direccion de memoria del nodo buscado en la lista, en caso de no encotrar dicho string se devuelve 0
         */
        Nodo* obtener_nodo(string nombre);

        //Devuelve la direccion de memoria del nodo anterior al nodo actual en la lista
        /*
         *PRE:
         *      Recibe un nodo actual para poder realizar la busqueda
         *POST:
         *      Devuelve la direccion de memoria del nodo anterior al nodo actual en la lista
         */
        Nodo* obtener_nodo_anterior(Nodo* actual);
};

#endif // LISTA_H_INCLUDED
