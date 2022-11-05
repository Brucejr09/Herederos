#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "menu.h"

/*
 *PRE:
 *		Debe recibir un objeto de Menu por referencia, con el metodo de bool lista_asignada(); de Menu ya realizado previo al pasaje por referencia
 *POST:
 *		Utiliza los metodos de Menu para realizar ciertas acciones especificas las cuales el usuario decide cual realizar y luego se llama a si misma hasta que realiza el metodo de bool guardar_salir(); de Menu 
 */
void realizar_accion (Menu &menu_principal);

#endif // FUNCIONES_H_INCLUDED