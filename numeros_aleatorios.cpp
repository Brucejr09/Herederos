#include "numeros_aleatorios.h"

using namespace std;

bool Numeros_aleatorios::semilla_generada = false;

bool Numeros_aleatorios::hay_semilla_generada(){
    return semilla_generada;
}

void Numeros_aleatorios::generar_semilla(){
    if(!semilla_generada)
        srand((unsigned) time(NULL));
    semilla_generada = true;
}

int Numeros_aleatorios::generar_aleatorio(){
    return rand();
}

int Numeros_aleatorios::generar_aleatorio(int min, int max){
    return (min + (rand() % max));
}