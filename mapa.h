#ifndef __MAPA__
#define __MAPA__
#include "numeros_aleatorios.h"
#include "vehiculo.h"

const char REPRESENTACION_CAMINO = '1';
const char REPRESENTACION_TIERRA = '2';
const char REPRESENTACION_MONTANIA = '3';
const char REPRESENTACION_PRECIPICIO = '4';
const char REPRESENTACION_VEHICULO = 'V';

const int ANCHO_TERRENO = 8;
const int ALTO_TERRENO = 8;
const int FILA_INICIO_VEHICULO = 0;
const int COLUMNA_INICIO_VEHICULO = 0;
const int CANTIDAD_ANIMALES = 5;

class Mapa{
    //Atributos
private:
    Baldosa** terreno;
    Vehiculo vehiculo;

    //Metodos
public:
    
    //pre: -
    //pos: Crea un objeto Mapa con un terreno aleatorio, CANTIDAD_ANIMALES aleatorios en el mismo 
    //  y la posicion de un vehiculo en Coordenada(FILA_INICIO_VEHICULO, COLUMNA_INICIO_VEHICULO).
    Mapa();

    //pre: -
    //pos: Imprime el terreno
    void imprimir_terreno();

    //pre: -
    //pos: Devuelve el terreno
    Baldosa** obtener_terreno();

    //pre: -
    //pos: Devuelve un puntero al vehiculo.
    Vehiculo* obtener_vehiculo();

    //
    //
    void dijkstras();

    void floyd(int tamanio_matriz);

    //pre: -
    //pos: Libera la memoria de terreno y elimina el objeto de tipo Mapa
    ~Mapa();
private:
    //pre: -
    //pos: Carga el terreno con Baldosas aleatorias
    void generar_terreno_aleatorio();

    //pre: -
    //pos: Agrega un animal con datos aleatorios y nombre=nombre en una baldosa del mapa aleatoria 
    //donde no haya otro animal o se encuentre el vehiculo.
    void generar_animal_aleatorio(std::string nombre);

    //pre: -
    //pos: Devuelve una especie aleatoria.
    char generar_especie_aleatoria();

    //pre: -
    //pos: Devuelve un tamanio aleatorio.
    std::string generar_tamanio_aleatorio();

    //pre: -
    //pos: Devuelve una personalidad aleatoria.
    std::string generar_personalidad_aleatoria();

};
#endif