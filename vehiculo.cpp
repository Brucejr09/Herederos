#include "vehiculo.h"

void Vehiculo::desplazarse(){
    int fila, columna;
    std::cout << "Ingrese la fila a la que desea moverse..." << std::endl;
    std::cin >> fila;
    std::cout << "Ingrese la columna a la que desea moverse..." << std::endl;
    std::cin >> columna;  
    Coordenada posicion(fila, columna);  
    if( puede_llegar(posicion) ){
        //imprimir_viaje();
        cambiar_posicion(posicion);
    } else {
        
    }
}

void Vehiculo::cambiar_posicion(Coordenada posicion){
    this->posicion = posicion;
    //HAY ANIMAL EN POSICION?
}

/*Repetir mientras (!lista_esta_vacia()) 
        //Del elegido 
            //Ir a cada uno de sus adyacentes 
                //Si el peso del elegido al adyacente es menor al peso que ya tienen
                    //Cambiar peso
                    //Modificar anterior
                    //Agregar a la lista
        //De los nodos en la lista
            //Cual tiene menor peso
                //Si empatan 
                    //Elegir -> (Al azar || Mayor adyacentes no visitados)
        Fin
    */
void Vehiculo::dijkstras(Baldosa baldosas[ALTO_TERRENO][ANCHO_TERRENO], Coordenada posicion_inicio){
    Vertice distancias[ALTO_TERRENO][ANCHO_TERRENO];
    for(int indice_fila=0; indice_fila<ALTO_TERRENO; indice_fila++){
        for(int indice_columna=0; indice_columna<ANCHO_TERRENO; indice_columna++){
            distancias[indice_fila][indice_columna] = Vertice(baldosas[indice_fila][indice_columna],false,0, INFINITO);
        }   
    }
    Lista pendientes;
    distancias[posicion_inicio.obtener_fila()][posicion_inicio.obtener_columna()].cambiar_visitado(true);
    distancias[posicion_inicio.obtener_fila()][posicion_inicio.obtener_columna()].cambiar_peso(0);
    Vertice actual = distancias[posicion_inicio.obtener_fila()][posicion_inicio.obtener_columna()];
    do
    {
        for(int i=0; i<4; i++){
            Coordenada posicion_temporal = actual.obtener_baldosa().obtener_posicion();
            switch (i)
            {
            case 0:
                //Izquierda
                posicion_temporal.cambiar_fila(posicion_temporal.obtener_fila()-1);
            break;
            case 1:
                //Derecha
                posicion_temporal.cambiar_fila(posicion_temporal.obtener_fila()+1);
            break;
            case 2:
                //Arriba
                posicion_temporal.cambiar_columna(posicion_temporal.obtener_columna()-1);
            break;
            case 3:
                //Abajo
                posicion_temporal.cambiar_columna(posicion_temporal.obtener_columna()+1);
            break;
            }
            //Si esta dentro del mapa y no fue visitado entonces...
            if( (posicion_temporal.obtener_columna()>=0 && posicion_temporal.obtener_columna()<ANCHO_TERRENO) &&
                (posicion_temporal.obtener_fila()>=0 && posicion_temporal.obtener_fila()<ALTO_TERRENO) && 
                (!distancias[posicion_temporal.obtener_fila()][posicion_temporal.obtener_columna()].obtener_visitado()) ){

                Vertice temporal = distancias[posicion_temporal.obtener_fila()][posicion_temporal.obtener_columna()];
                if((temporal.obtener_peso() == INFINITO) ||
                   (temporal.obtener_peso() > (actual.obtener_peso()+actual.obtener_baldosa().obtener_topografia())) ){

                    temporal.cambiar_peso( actual.obtener_peso()+actual.obtener_baldosa().obtener_topografia() );
                    temporal.cambiar_anterior(&distancias[actual.obtener_baldosa().obtener_posicion().obtener_fila()][actual.obtener_baldosa().obtener_posicion().obtener_columna()]);
                    pendientes.alta(distancias[posicion_temporal.obtener_fila()][posicion_temporal.obtener_columna()], 0);
                }
            }
        }
        pendientes.reiniciar_actual();
        actual = (*pendientes.obtener_dato_actual());
        pendientes.siguiente_actual();
        while (pendientes.hay_siguiente_actual())
        {
            if( pendientes.obtener_dato_actual()->obtener_peso() < actual.obtener_peso() ){
                actual = (*pendientes.obtener_dato_actual());
            } //else if( pendientes.obtener_dato_actual().obtener_peso() == actual.obtener_peso() ) Quien tiene mas adyacentes?
        }
        //Actual
            //Sacar de la lista pendientes
            //Marcar como visitado

    }
    while ( !pendientes.vacia() );
    
}