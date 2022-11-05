#include "funciones.h"

void realizar_accion (Menu &menu_principal) {
	menu_principal.mostrar();

	switch ( menu_principal.accion_menu() ) {
		case LISTAR:
			menu_principal.listar();
			
			system("clear");
			
			realizar_accion(menu_principal);
			break;
		case RESCATAR:
			menu_principal.rescatar();
			
			system("clear");
			
			realizar_accion(menu_principal);
			break;
		case BUSCAR:
			menu_principal.buscar();
			
			system("clear");
			
			realizar_accion(menu_principal);
			break;
		case CUIDAR:
			menu_principal.cuidar();
			
			system("clear");
			
			realizar_accion(menu_principal);
			break;
		case ADOPTAR:
			menu_principal.adoptar();
			
			system("clear");
			
			realizar_accion(menu_principal);
			break;
		default:
			system("clear");

			if ( menu_principal.guardar_salir() )
				cout << "El archivo se ha actualizado con éxito." << endl << endl;
			else
				cout << "El archivo no se pudo actualizar." << endl << endl;
	}
}