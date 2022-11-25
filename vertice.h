#ifndef __VERTICE__
#define __VERTICE__
#include "baldosa.h"

class Vertice{
    //Atributos
private:
    Vertice* anterior;
    Baldosa baldosa;
    bool visitado;
    int peso;

    //Metodos
public:
    //pre:
    //pos:
    Vertice();

    //pre:
    //pos:
    Vertice( Vertice &copia);

    //pre:
    //pos:
    Vertice(Baldosa baldosa, bool visitado, Vertice* anterior, int peso);

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
    Baldosa obtener_baldosa();

    //pre:
    //pos:
    bool obtener_visitado();

    //pre:
    //pos:
    int obtener_peso();

    //pre:
    //pos:
    Vertice* obtener_anterior();
};
#endif