#ifndef __BALDOSA__
#define __BALDOSA__
#include "coordenada.h"
#include "animal.h"
#include "perro.h"
#include "gato.h"
#include "caballo.h"
#include "roedor.h"
#include "conejo.h"
#include "erizo.h"
#include "lagartija.h"

namespace bds{
    enum Topografia {CAMINO = 1, TIERRA = 2, MONTANIA = 5, PRECIPICIO = 40};
};

class Baldosa{
    //Atributos
private:
    bds::Topografia topografia;
    Coordenada posicion;
    Animal* animal;
    bool tiene_animal;

    //Metodos
public:

    //pre: -
    //pos: Crea un objeto Baldosa
    Baldosa();

    //pre: -
    //pos: Crea un objeto Baldosa con topografia=topografia y posicion=Coordenada(fila, columna)
    Baldosa(bds::Topografia topografia, int fila, int columna);
    
    //pre: -
    //pos: Devuelve la topografia
    int obtener_topografia();
    //pre: -
    //pos: Devuelve la posicion 
    Coordenada obtener_posicion();

    //pre: -
    //pos: Devuelve true si hay un animal en la baldosa, false sino.
    bool hay_animal();

    //pre: Los parametros deben ser validos para un animal.
    //pos: Crea un animal en el heap con los datos recibidos.
    void agregar_animal(char especie, string nombre, int edad, string tamanio, string personalidad);

    //pre: -
    //pos: Devuelve puntero a animal.
    Animal* obtener_animal();

    //pre: -
    //pos: Devuelve puntero a animal y cambia tiene_animal por false.
    // Debe encargarse de liberar la memoria reservada por animal.
    Animal* eliminar_animal();

    //pre: -
    //pos: Libera la memoria
    ~Baldosa();
};
#endif