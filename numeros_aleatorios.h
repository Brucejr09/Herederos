#ifndef __NUMEROS__ALEATORIOS__
#define __NUMEROS__ALEATORIOS__
#include <cstdlib>
#include <iostream>

class Numeros_aleatorios{
    //Atributos
private:
    static bool semilla_generada;

    //Metodos
public:
    //pre: - 
    //pos: Devuelve true si ya se genero una semilla, false sino.
    static bool hay_semilla_generada();
    
    //pre: -
    //pos: Genera una semilla.
    static void generar_semilla();

    //pre: Se debe haber generado una semilla
    //pos: Devuelve un entero aleatorio.
    static int generar_aleatorio();

    //pre: Se debe haber generado una semilla
    //pos: Devuelve un entero aleatorio entre  min <= numero < max.
    static int generar_aleatorio(int min, int max);
};

#endif