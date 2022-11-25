#ifndef __VECTOR__
#define __VECTOR__

const int CAPACIDAD_INICIO = 5;

template <class T>
class Vector{
    //Atributos
private:
    int cantidad_elementos;
    int capacidad_elementos;
    T** elementos;

    //Metodos
    Vector(){
        cantidad_elementos = 0;
        capacidad_elementos = CAPACIDAD_INICIO;
        elementos = new T*[capacidad_elementos];
        for(int i=0; i<capacidad_elementos; i++){
            elementos[i] = 0;
        }
    }

    void eliminar_elemento(int posicion){
        elementos[posicion] = 0;
    }

    void modificar_elemento(T nuevo_elemento){

    }

    void agregar_elemento(T nuevo_elemento){
        bool hay_lugar_vacio = false;
        for(int i=0; i<cantidad_elementos; i++){
            if(elementos[i]==0){
                hay_lugar_vacio = true;
                elementos[i] = new T(nuevo_elemento);
            }
        }
        if(!hay_lugar_vacio)
            elementos[cantidad_elementos] = new T(nuevo_elemento);
        cantidad_elementos++;
        verificar_capacidad();
    }

    void verificar_capacidad(){
        if(cantidad_elementos == capacidad_elementos){
            T** nuevo_vector = new T*[capacidad_elementos + capacidad_elementos]
            //crear nuevo vector
            //pasar elementos
            //borrar viejo vector
            //asignar nuevo vector a elementos
            //asigna nueva capacidad elementos
        }
    }

    void aumentar_capacidad(){

    }
};

#endif