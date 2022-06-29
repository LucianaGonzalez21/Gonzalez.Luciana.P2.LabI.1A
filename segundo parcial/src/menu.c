/*
 * menu.c
 *
 *  Created on: Jun 28, 2022
 *      Author: Dell
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int menuPrincipal(int *opcion) {

	int rta;

	if (opcion != NULL) {

		printf("1. Cargar Archivo.\n"
				"2. Imprimir lista\n"
				"3. Asignar rating\n"
				"4. Asignar genero\n"
				"5. Filtrar por genero\n"
				"6. Ordenar peliculas \n"
				"7. Guardar peliculas\n"
				"8. Salir\n");

		rta = utn_getNumero(opcion, "Ingrese una opcion: ","Error. Opcion no valida\n", 1, 8, 3);
	}
	return rta;
}

int menuFiltrar(int *opcion) {

	int rta;

	if (opcion != NULL) {

		printf("1. Drama.\n"
				"2. Comedia\n"
				"3. Accion\n"
				"4. Terror\n"
				"5. Cancelar\n");

		rta = utn_getNumero(opcion, "Ingrese una opcion: ","Error. Opcion no valida\n", 1, 5, 3);
	}
	return rta;
}
