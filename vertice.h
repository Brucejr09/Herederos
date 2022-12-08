#ifndef __VERTICE__
#define __VERTICE__
#include "baldosa.h"

const int INFINITO = -1;

class Vertice{
    //Atributos
private:
    Coordenada posicion;
    Vertice* anterior;
    bool visitado;
    int peso;
    int distancia;

    //Metodos
public:
    //pre:
    //pos:
    Vertice();

    //pre:
    //pos:
    Vertice(const Vertice &copia);

    //pre:
    //pos:
    Vertice(int distancia, bool visitado, Vertice* anterior, int peso, int fila, int columna);

    //pre:
    //pos:
    void cambiar_visitado(bool visitado);

    //pre:
    //pos:
    void cambiar_peso(int peso);

    //pre:
    //pos:
    void cambiar_anterior(Vertice* nuevo_anterior);

    //pre:
    //pos:
    int obtener_distancia();

    //pre:
    //pos:
    bool obtener_visitado();

    //pre:
    //pos:
    int obtener_peso();

    //pre:
    //pos:
    Coordenada obtener_posicion();

    //pre:
    //pos:
    Vertice* obtener_anterior();
};
#endif