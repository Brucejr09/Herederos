#ifndef __COORDENADA__
#define __COORDENADA__

class Coordenada{
    //Atributos
private:
    int fila;
    int columna;

    //Metodos
public:
    //pre: -
    //pos: Crea una coordenada con fila y columna
    Coordenada();
    //pre: -
    //pos: Crea una coordenada con fila y columna
    Coordenada(int fila, int columna);
    //pre: -
    //pos: Devuelve la fila
    int obtener_fila();
    //pre: -
    //pos: Devuelve la columna
    int obtener_columna();
    //pre: -
    //pos: Cambia el valor de fila por nueva_fila
    void cambiar_fila(int nueva_fila);
    //pre: -
    //pos: Cambia el columna de fila por nueva_columna
    void cambiar_columna(int nueva_columna);
};
#endif