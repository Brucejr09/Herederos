#include "funciones.h"

int main () {
	Menu menu_principal;
	
	if ( menu_principal.lista_asignada() )
		realizar_accion(menu_principal);
	else
		cout << "Corrobore el archivo de texto correspondiente." << endl;
	
	return 0;
}