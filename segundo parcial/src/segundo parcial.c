/*
 ============================================================================
 Name        : segundo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "utn.h"
#include "controller.h"
#include <time.h>
#include "movie.h"
#include "menu.h"

int main(void) {
	setbuf(stdout, NULL);
	srand(time(NULL));

	int opcion;
	int flagLoad=0;
	int flagSave=0;
	int flagGenero=0;
	int flagRating=0;
	int flagOrdenar=0;
	char confirmacion;

	LinkedList* listaPeliculas = ll_newLinkedList();


	do {
			if (!menuPrincipal(&opcion)) {

				switch (opcion) {
				case 1:
					//Cargar archivo
					if(!flagLoad)
					{
						 if(controller_loadFromText("movies.csv", listaPeliculas))
						 {
							 printf("Lista cargada correctamente.\n\n");
							 flagLoad=1;
						 }
						 else
						 {
							 printf("Error al cargar archivo.\n\n");
						 }
					}
					break;
				case 2:
					//imprimir lista
					if(flagLoad)
					{
						if(!controller_ListMovies(listaPeliculas))
						{
							printf("Error al mostrar.\n\n");
						}
					}
					else
					{
						printf("Primero debe cargar el archivo\n\n");
					}
					break;
				case 3:
					//asignar rating
					if(flagLoad)
					{
						if(controller_asignarRatingPeliculas(listaPeliculas))
						{
							printf("Asignacion exitosa.\n\n");
							flagRating=1;
						}
						else
						{
							printf("Error al asignar rating.\n\n");
						}
					}
					else
					{
						printf("Primero debe cargar el archivo.\n\n");
					}
					break;
				case 4:
					//asignar genero
					if(flagLoad)
					{
						if(controller_asignarGeneroPeliculas(listaPeliculas))
						{
							printf("Asignacion exitosa.\n\n");
							flagGenero=1;
						}
						else
						{
							printf("Error al asignar generos.\n\n");
						}
					}
					else
					{
						printf("Primero debe cargar el archivo.\n\n");
					}
					break;
				case 5:
					//filtrar por genero
					if(flagLoad && flagGenero)
					{
						if(controller_filtrarPeliculasPorGenero(listaPeliculas))
						{
							printf("Archivo creado con exito.\n\n");
						}
						else
						{
							printf("Error al intentar generar archivo nuevo.\n\n");
						}
					}
					else
					{
						printf("Primero debe cargar el archivo y asignar generos a las peliculas.\n\n");
					}
					break;
				case 6:
					//ordenar peliculas
					if(flagLoad && flagRating && flagGenero)
					{
						if(controller_OrdenarPorGeneroYRating(listaPeliculas))
						{
							printf("Lista ordenada con exito.\n\n");
							flagOrdenar=1;
						}
						else
						{
							printf("Error al ordenar.\n\n");
						}
					}
					else
					{
						printf("Primero debe cargar el archivo y asignar generos y rating a las peliculas.\n\n");
					}
					break;
				case 7:
					//guardar como txt
					if(flagLoad && flagOrdenar)
					{
						if(controller_saveAsText("movies.txt", listaPeliculas))
						{
							printf("Arhivo guardado correctamente.\n\n");
							flagSave=1;
						}
						else
						{
							printf("Error al guardar.\n\n");
						}
					}
					else
					{
						printf("Primero debe cargar el archivo y ordenarlo en el punto 6\n\n");
					}
					break;
				case 8:
					//salir
					if(flagLoad && flagSave)
					{

						utn_getCaracter(&confirmacion, "desea salir? (s/n) :", "respuesta no valida", 'a', 'z', 1);
						if(confirmacion == 's')
						{
							movie_deleteAll(listaPeliculas);
							ll_deleteLinkedList(listaPeliculas);
							printf("Programa finalizado.\n\n");
						}
						fflush(stdin);
					}
					else
					{
						printf("No puede salir sin antes cargar y guardar el archivo.\n\n");
					}
					break;
				}
			}
			else
			{
				printf("ERROR. Cantidad de reintentos agotada. \nPrograma finalizado\n");
				break;
			}
		} while (confirmacion != 's');
	return EXIT_SUCCESS;
}
