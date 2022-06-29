/*
 * controller.c
 *
 *  Created on: Jun 28, 2022
 *      Author: Dell
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "controller.h"
#include "movie.h"
#include "parser.h"
#include "menu.h"
#include "utn.h"

int controller_loadFromText(char* path , LinkedList* pArrayListMovies)
{
    int todoOk=0;

    FILE* f = fopen(path, "r");

    if(pArrayListMovies!=NULL)
    {
    	if(parser_MovieFromText(f, pArrayListMovies))
    	{
			todoOk=1;
    	}
    }
    return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListMovies)
{
    int todoOk=0;
    FILE* pFile;
    eMovie* pMovie;
    int tam;
    int id;
    char titulo[50];
    char genero[50];
    float rating;

    if(path!=NULL && pArrayListMovies!=NULL)
    {
    	todoOk=1;

    	pFile = fopen(path, "w");

    	if(pFile!=NULL)
    	{
    		fprintf(pFile, "id_peli,titulo,genero, rating\n");

			tam = ll_len(pArrayListMovies);

			for(int i=0; i<tam; i++)
			{
				pMovie = ll_get(pArrayListMovies, i);

				if( pMovie!=NULL &&
				movie_getId(pMovie, &id) &&
				movie_getTitulo(pMovie, titulo) &&
				movie_getGenero(pMovie, genero) &&
				movie_getRating(pMovie, &rating))
				{
					fprintf(pFile, "%d,%s,%s,%.1f\n", id, titulo, genero, rating);
					//falta validar el retonro de fprintf
				}
				else
				{
					todoOk = -1;
				}
			}
    	}
    	fclose(pFile);
    }
	return todoOk;
}

int controller_ListMovies(LinkedList* pArrayListMovies)
{
	int todoOk=0;
	int tam;
	eMovie* pMovie = NULL;

	if(pArrayListMovies!=NULL)
	{
		todoOk=1;
		tam = ll_len(pArrayListMovies);

		if(tam>0)
		{
			printf("  Id Peli          Titulo             Genero            Rating\n"
					"--------------------------------------------------------------\n");


			for (int i=0; i < tam; i++)
			{
				pMovie = ll_get(pArrayListMovies, i);
				movie_print(pMovie);
			}

			printf("----------------------------------------------------------------\n\n");
		}
		else
		{
			printf("No hay peliculas para mostrar.\n");
			todoOk=-1;
		}
	}
	return todoOk;
}

int controller_asignarRatingPeliculas(LinkedList* pArrayListMovies)
{
	int todoOk=0;
	int tam;

	if(pArrayListMovies!=NULL)
	{
		todoOk=1;
		tam = ll_len(pArrayListMovies);

		if(tam>0)
		{
			pArrayListMovies = ll_map(pArrayListMovies, movie_asignarRating);
		}
		else
		{
			printf("No hay peliculas.\n");
		}
	}

	return todoOk;
}

int controller_asignarGeneroPeliculas(LinkedList* pArrayListMovies)
{
	int todoOk=0;
	int tam;

	if(pArrayListMovies!=NULL)
	{
		todoOk=1;
		tam = ll_len(pArrayListMovies);

		if(tam>0)
		{
			pArrayListMovies = ll_map(pArrayListMovies, movie_asignarGenero);
		}
		else
		{
			printf("No hay peliculas.\n");
		}
	}

	return todoOk;
}

int controller_filtrarPeliculasDrama(LinkedList* pArrayListMovies)
{
	int todoOk=0;
	LinkedList* listaFiltro = NULL;

	if(pArrayListMovies!=NULL)
	{
		listaFiltro = ll_filter(pArrayListMovies, movie_comparaGeneroDrama);
		if(controller_saveAsText("peliculasDrama.csv", listaFiltro))
		{
			todoOk=1;
		}
	}

	return todoOk;
}

int controller_filtrarPeliculasComedia(LinkedList* pArrayListMovies)
{
	int todoOk=0;
	LinkedList* listaFiltro = NULL;

	if(pArrayListMovies!=NULL)
	{
		listaFiltro = ll_filter(pArrayListMovies, movie_comparaGeneroComedia);
		if(controller_saveAsText("peliculasComedia.csv", listaFiltro))
		{
			todoOk=1;
		}
	}

	return todoOk;
}

int controller_filtrarPeliculasAccion(LinkedList* pArrayListMovies)
{
	int todoOk=0;
	LinkedList* listaFiltro = NULL;

	if(pArrayListMovies!=NULL)
	{
		listaFiltro = ll_filter(pArrayListMovies, movie_comparaGeneroAccion);
		if(controller_saveAsText("peliculasAccion.csv", listaFiltro))
		{
			todoOk=1;
		}
	}

	return todoOk;
}

int controller_filtrarPeliculasTerror(LinkedList* pArrayListMovies)
{
	int todoOk=0;
	LinkedList* listaFiltro = NULL;

	if(pArrayListMovies!=NULL)
	{
		listaFiltro = ll_filter(pArrayListMovies, movie_comparaGeneroTerror);
		if(controller_saveAsText("peliculasTerror.csv", listaFiltro))
		{
			todoOk=1;
		}
	}

	return todoOk;
}

int controller_filtrarPeliculasPorGenero(LinkedList* pArrayListMovies)
{
	int todoOk=0;
	int opcionIngresada;

	if(pArrayListMovies!=NULL)
	{
		if(!menuFiltrar(&opcionIngresada))
		{
			switch(opcionIngresada)
			{
			case 1:
				if(controller_filtrarPeliculasDrama(pArrayListMovies))
				{
					todoOk=1;
				}
				break;
			case 2:
				if(controller_filtrarPeliculasComedia(pArrayListMovies))
				{
					todoOk=1;
				}
				break;
			case 3:
				if(controller_filtrarPeliculasAccion(pArrayListMovies))
				{
					todoOk=1;
				}
				break;
			case 4:
				if(controller_filtrarPeliculasTerror(pArrayListMovies))
				{
					todoOk=1;
				}
				break;
			case 5:
				printf("Operacion cancelada.\n");
				break;

			}
		}
	}
	return todoOk;
}

int controller_OrdenarPorGeneroYRating(LinkedList* pArrayListMovies)
{
	int todoOk=0;

	if(pArrayListMovies!=NULL)
	{
		if(!ll_sort(pArrayListMovies, movie_compararGenerosYRating, 0))
		{
			todoOk=1;
		}
	}

	return todoOk;
}






























int controller_finalizarPrograma(LinkedList* pArrayListMovies)
{
	int todoOk=0;
	char confirmacion;
	if(pArrayListMovies!=NULL)
	{
		if(!utn_getCaracter(&confirmacion, "Esta seguro que desea salir? (s/n): ", "Error, opcion no valida.\n", 'a', 'z', 2))
		{
			movie_deleteAll(pArrayListMovies);
			ll_deleteLinkedList(pArrayListMovies);
			todoOk=1;
		}

	}
	return todoOk;
}
