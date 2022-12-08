#include "mapa.h"

Mapa::Mapa(){
    vehiculo.cambiar_posicion(FILA_INICIO_VEHICULO, COLUMNA_INICIO_VEHICULO);
    terreno = new Baldosa*[ALTO_TERRENO];
    for (int i = 0; i < ALTO_TERRENO; i++){
            terreno[i] = new Baldosa[ANCHO_TERRENO];
    }
    generar_terreno_aleatorio();
    std::string nombre_temporal;
    for(int i=0; i<CANTIDAD_ANIMALES; i++){
        do{
            cout << endl << "Ingrese un nombre para el animal aleatorio "<< i << " del mapa" << endl;
            getline(cin, nombre_temporal);
        }while(nombre_temporal == "");
        generar_animal_aleatorio(nombre_temporal);
    }
}

void Mapa::generar_terreno_aleatorio(){
    Numeros_aleatorios::generar_semilla();
    int random = 0;
    for(int indice_fila=0; indice_fila<ALTO_TERRENO; indice_fila++){
        for(int indice_columna=0; indice_columna<ANCHO_TERRENO; indice_columna++){
            random = Numeros_aleatorios::generar_aleatorio(0,4);
            bds::Topografia topografia;
            switch (random)
            {
            case 0:
                topografia = bds::Topografia::CAMINO;
            break;
            case 1:
                topografia = bds::Topografia::TIERRA;
            break;
            case 2:
                topografia = bds::Topografia::MONTANIA;
            break;
            case 3:
                topografia = bds::Topografia::PRECIPICIO;
            break;
            }
            terreno[indice_fila][indice_columna] = Baldosa(topografia, indice_fila, indice_columna);
        }   
    }
}

void Mapa::imprimir_terreno(){
    char caracter = 0;
    for(int indice_fila=0; indice_fila<ALTO_TERRENO; indice_fila++){
        for(int indice_columna=0; indice_columna<ANCHO_TERRENO; indice_columna++){
            if( (vehiculo.obtener_posicion()->obtener_fila() == indice_fila) && (vehiculo.obtener_posicion()->obtener_columna() == indice_columna) ){
                caracter = REPRESENTACION_VEHICULO;
            }else if(terreno[indice_fila][indice_columna].hay_animal()){
                caracter = terreno[indice_fila][indice_columna].obtener_animal()->obtener_especie()[0];
            } else {
                switch (terreno[indice_fila][indice_columna].obtener_topografia())
                {
                case bds::Topografia::CAMINO:
                    caracter = REPRESENTACION_CAMINO;
                break;
                case bds::Topografia::TIERRA:
                    caracter = REPRESENTACION_TIERRA;
                break;
                case bds::Topografia::MONTANIA:
                    caracter = REPRESENTACION_MONTANIA;
                break;
                case bds::Topografia::PRECIPICIO:
                    caracter = REPRESENTACION_PRECIPICIO;
                break;
                }
            }
            
            std::cout << caracter << " ";
        }   
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Baldosa** Mapa::obtener_terreno(){
    return terreno;
}

void Mapa::generar_animal_aleatorio(std::string nombre){
    int fila = 0;
    int columna = 0;
    char especie;
    int edad;
    std::string tamanio;
    std::string personalidad;
    do{
        fila = Numeros_aleatorios::generar_aleatorio(0,ALTO_TERRENO);
        columna = Numeros_aleatorios::generar_aleatorio(0,ANCHO_TERRENO);
    }while(terreno[fila][columna].hay_animal() || 
        (fila==vehiculo.obtener_posicion()->obtener_fila() && columna==vehiculo.obtener_posicion()->obtener_columna()) );
    especie = generar_especie_aleatoria();
    edad = Numeros_aleatorios::generar_aleatorio(MINIMO,MAXIMO+1);
    tamanio = generar_tamanio_aleatorio();
    personalidad = generar_personalidad_aleatoria();
    terreno[fila][columna].agregar_animal(especie, nombre, edad, tamanio, personalidad);
}

char Mapa::generar_especie_aleatoria(){
    int random = Numeros_aleatorios::generar_aleatorio(0,7);
    char especie;
    switch (random)
    {
    case 0:
        especie = PERRO;    
    break;
    case 1:
        especie = GATO;    
    break;
    case 2:
        especie = CABALLO;    
    break;
    case 3:
        especie = ROEDOR;    
    break;
    case 4:
        especie = CONEJO;    
    break;
    case 5:
        especie = ERIZO;    
    break;
    case 6:
        especie = LAGARTIJA;    
    break;
    }
    return especie;
}

std::string Mapa::generar_tamanio_aleatorio(){
    int random = Numeros_aleatorios::generar_aleatorio(0,4);
    std::string tamanio;
    switch (random)
    {
    case 0:
        tamanio = DIMINUTO;    
    break;
    case 1:
        tamanio = PEQUENIO;    
    break;
    case 2:
        tamanio = MEDIANO;  
    break;
    case 3:
        tamanio = GRANDE;    
    break;
    case 4:
        tamanio = GIGANTE;    
    break;
    }
    return tamanio;
}

std::string Mapa::generar_personalidad_aleatoria(){
    int random = Numeros_aleatorios::generar_aleatorio(0,4);
    std::string personalidad;
    switch (random)
    {
    case 0:
        personalidad = DORMILON;    
    break;
    case 1:
        personalidad = JUGUETON;    
    break;
    case 2:
        personalidad = SOCIABLE;  
    break;
    case 3:
        personalidad = TRAVIESO;    
    break;
    }
    return personalidad;
}

Vehiculo* Mapa::obtener_vehiculo(){
    return &vehiculo;
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
void Mapa::dijkstras(){
    Vertice distancias[ALTO_TERRENO][ANCHO_TERRENO];
    Lista pendientes; //Lista de vertices pendientes por visitar
    //Carga en distancias todos los vertices como no visitados con vertice anterior = 0, peso INFINITO y posicion (indice_fila, indice_columna)
    for(int indice_fila=0; indice_fila<ALTO_TERRENO; indice_fila++){
        for(int indice_columna=0; indice_columna<ANCHO_TERRENO; indice_columna++){
            distancias[indice_fila][indice_columna] = Vertice(/*terreno[indice_fila][indice_columna],*/terreno[indice_fila][indice_columna].obtener_topografia(), false,0, INFINITO, indice_fila, indice_columna);
        }   
    }
    //Marca al vertice donde se encuentra el vehiculo como visitado y cambia su peso a 0
    distancias[vehiculo.obtener_posicion()->obtener_fila()][vehiculo.obtener_posicion()->obtener_columna()].cambiar_visitado(true);
    distancias[vehiculo.obtener_posicion()->obtener_fila()][vehiculo.obtener_posicion()->obtener_columna()].cambiar_peso(0);
    //Marca al vertice actual como el vertice donde se encuentra el vehiculo para iniciar
    Vertice actual = distancias[vehiculo.obtener_posicion()->obtener_fila()][vehiculo.obtener_posicion()->obtener_columna()];
    //Repite mientras la lista de vertices pendientes por visitar no este vacia
    do
    {
        //Para cada una de las 4 vertices adyacentes 
        for(int i=0; i<4; i++){
            Coordenada posicion_temporal = actual.obtener_posicion();
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

                //Si el peso del vertice adyacente el mayor al peso del actual + el coste al adyacente
                //Cambia el peso por peso del actual + el coste al adyacente, cambia su vertice anterior a actual
                //Y agrega el vertice a la lista pendientes por visitar
                Vertice temporal = distancias[posicion_temporal.obtener_fila()][posicion_temporal.obtener_columna()];
                if((temporal.obtener_peso() == INFINITO) ||
                   (temporal.obtener_peso() > (actual.obtener_peso()+temporal.obtener_distancia())) ){

                    temporal.cambiar_peso( actual.obtener_peso()+temporal.obtener_distancia() );
                    temporal.cambiar_anterior(&distancias[actual.obtener_posicion().obtener_fila()][actual.obtener_posicion().obtener_columna()]);
                    pendientes.alta(distancias[posicion_temporal.obtener_fila()][posicion_temporal.obtener_columna()], 0);
                }
            }
        }
        //Busca en la lista de vertices pendientes por visitar un vertice con peso <= al resto de pesos
        //Guarda dicho vertice en actual, lo marca como visitado y lo saca de la lista
        
        std::cout << "Loop: " << pendientes.obtener_cantidad() << std::endl;

        pendientes.reiniciar_actual();
        actual = (*pendientes.obtener_dato_actual());
        pendientes.siguiente_actual();
        int indice = 0, i = 0;
        while (pendientes.hay_siguiente_actual())
        {
            i++;
            if( pendientes.obtener_dato_actual()->obtener_peso() < actual.obtener_peso() ){
                actual = (*pendientes.obtener_dato_actual());
                indice = i;
            } //else if( pendientes.obtener_dato_actual().obtener_peso() == actual.obtener_peso() ) Quien tiene mas adyacentes?
            pendientes.siguiente_actual();
        }
        //Actual
            //Marcar como visitado
            actual.cambiar_visitado(true);
            //Sacar de la lista pendientes
            pendientes.baja(indice);
    }
    while ( !pendientes.vacia() );
    //Imprime matriz distancias
    for(int indice_fila=0; indice_fila<ALTO_TERRENO; indice_fila++){
        for(int indice_columna=0; indice_columna<ANCHO_TERRENO; indice_columna++){
            std::cout << "Vertice fila: " << indice_fila << " columna: " << indice_columna << std::endl;
            std::cout << "Peso: " << distancias[indice_fila][indice_columna].obtener_peso() << std::endl;
            std::cout << "Anterior fila: " <<  distancias[indice_fila][indice_columna].obtener_anterior()->obtener_posicion().obtener_fila();
            std::cout << " columna: " << distancias[indice_fila][indice_columna].obtener_anterior()->obtener_posicion().obtener_columna() << std::endl;
            std::cout << std::endl;
        }   
    }
}

void Mapa::floyd(int tamanio_matriz){
    int limite = tamanio_matriz*tamanio_matriz;
    int distancias[limite][limite];
    //Coordenada recorridos[limite][limite];
    
    //Llena la matriz distancias con infinitos
    for (int i = 0; i < limite; i++) {
        for (int j = 0; j < limite; j++) {
            distancias[i][j] = INFINITO;
        }
    }
    //Remplaza algunos infinitos por el valor de sus adyacentes conocidos
    for (int i=0; i<tamanio_matriz; i++) {
        for (int j=0; j<tamanio_matriz; j++) {
            std::cout  << "Analisando Fila: " << i << " Columna" << j << std::endl;
            
            //Para cada una de los 4 adyacentes 
            for(int k=0; k<4; k++){
                Coordenada posicion_temporal = Coordenada(i, j);
                switch (k)
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
                std::cout << "Adyacente: " << k << " Fila :" << posicion_temporal.obtener_fila() << " Columna: " << posicion_temporal.obtener_columna() << std::endl;
                //Si esta dentro del mapa...
                if( (posicion_temporal.obtener_columna()>=0 && posicion_temporal.obtener_columna()<tamanio_matriz) &&
                    (posicion_temporal.obtener_fila()>=0 && posicion_temporal.obtener_fila()<tamanio_matriz) ){
                        
                    //Asignar distancia a sus adyacentes
                    int fila_distancias = ( (i*tamanio_matriz) + j );
                    int columna_distancias = ( (posicion_temporal.obtener_fila()*tamanio_matriz) + posicion_temporal.obtener_columna() );
                    std::cout << "Distancias Fila: " << fila_distancias << " Columna: " << columna_distancias << std::endl;
                    distancias[fila_distancias][columna_distancias] = terreno[posicion_temporal.obtener_fila()][posicion_temporal.obtener_columna()].obtener_topografia();
                }
            }
        }
    }
    
    for(int i=0; i<limite; i++){
        distancias[i][i] = 0;
    }

    //Calcular distancias 
    //y recorridos
    //...
    //recorridos
    //..
    for (int k = 0; k < limite; k++) {
        for (int i = 0; i < limite; i++) {
            for (int j = 0; j < limite; j++) {
                if ( (distancias[i][k] != INFINITO) && (distancias[k][j] != INFINITO) && (distancias[i][k] + distancias[k][j] < distancias[i][j]) )
                    distancias[i][j] = distancias[i][k] + distancias[k][j];
                //recorridos[i][j] = k;
                //..
            }
        }
    }
    //Me los meto en el culo

    //Imprimo distancias
    std::cout << std::endl<< std::endl<< std::endl;
    for (int i = 0; i < limite; i++) {
        for (int j = 0; j < limite; j++) {
            if (distancias[i][j] == INFINITO)
                printf("%7s", "INF");
            else
                printf("%7d", distancias[i][j]);
        }
        printf("\n");
    }
    
}

Mapa::~Mapa(){
    for(int indice_fila=0; indice_fila<ALTO_TERRENO; indice_fila++){
        delete [] terreno[indice_fila]; 
    }
    delete [] terreno;
}