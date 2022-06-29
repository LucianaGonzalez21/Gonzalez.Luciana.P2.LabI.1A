/*
 * movie.c
 *
 *  Created on: Jun 29, 2022
 *      Author: Dell
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "movie.h"

/***GETTERS Y SETTERS***/
int movie_setId(eMovie* this,int id)
{
	int todoOk=0;

	if(this!=NULL && id>=0)
	{
		todoOk=1;
		this->id_peli = id;
	}
	return todoOk;
}

int movie_setTitulo(eMovie* this,char* titulo)
{
	int todoOk=0;

	if(this!=NULL && titulo!=NULL && strlen(titulo)>1 && strlen(titulo)<50)
	{
		todoOk=1;
		strcpy(this->titulo, titulo);
	}

	return todoOk;
}

int movie_setGenero(eMovie* this,char* genero)
{
	int todoOk=0;

	if(this!=NULL && genero!=NULL && strlen(genero)>1 && strlen(genero)<50)
	{
		todoOk=1;
		strcpy(this->genero, genero);
	}

	return todoOk;
}

int movie_setRating(eMovie* this,float rating)
{
	int todoOk=0;

	if(this!=NULL && rating>=0)
	{
		todoOk=1;
		this->rating = rating;
	}
	return todoOk;
}

int movie_getId(eMovie* this,int* id)
{
	int todoOk=0;

	if(this!=NULL && id !=NULL)
	{
		todoOk=1;
		*id = this->id_peli;
	}
	return todoOk;
}

int movie_getGenero(eMovie* this,char* genero)
{
	int todoOk=0;

	if(this!=NULL && genero!=NULL)
	{
		todoOk=1;
		strcpy(genero, this->genero);
	}
	return todoOk;
}

int movie_getTitulo(eMovie* this,char* titulo)
{
	int todoOk=0;

	if(this!=NULL && titulo!=NULL)
	{
		todoOk=1;
		strcpy(titulo, this->titulo);
	}
	return todoOk;
}

int movie_getRating(eMovie* this,float* rating)
{
	int todoOk=0;

	if(this!=NULL && rating>0)
	{
		todoOk=1;
		*rating = this->rating;
	}
	return todoOk;
}

/*****CONSTRUCTORES Y DESTRUCTORES*******/
eMovie* movie_new()
{
	eMovie* newMovie = NULL;
	newMovie = (eMovie*)malloc(sizeof(eMovie));

	if(newMovie!=NULL)
	{
		movie_setId(newMovie, 1);
		movie_setTitulo(newMovie, " ");
		movie_setGenero(newMovie, " ");
		movie_setRating(newMovie, 1);
	}
	return newMovie;
}

eMovie* movie_newParametros(char* idStr,char* titulo, char* genero, char* rating)
{
	eMovie* newMovie = movie_new();

	if(newMovie!=NULL)
	{
		if(!(movie_setId(newMovie, atoi(idStr)) &&
			movie_setTitulo(newMovie, titulo) &&
			movie_setGenero(newMovie, genero) &&
			movie_setRating(newMovie, atof(rating))))
		{
			free(newMovie);
			newMovie = NULL;
		}
	}
	return newMovie;
}

void movie_delete(eMovie* movie)
{
	if(movie!=NULL)
	{
		free(movie);
	}
}

int movie_deleteAll(LinkedList* pArrayListMovies)
{
	int todoOk=0;
	eMovie* pMovie;
	int tam;

	if(pArrayListMovies!=NULL)
	{
		tam = ll_len(pArrayListMovies);
		for(int i=0; i<tam; i++)
		{
			pMovie = (eMovie*) ll_get(pArrayListMovies, i);
			movie_delete(pMovie);
		}
		todoOk=1;
	}
	return todoOk;
}

/********PRINT*******/
int movie_print(eMovie* movie)
{
	int todoOk=0;
	int id;
	char titulo[50];
	char genero[50];
	float rating;

	if(movie!=NULL)
	{
		if(movie_getId(movie, &id) &&
			movie_getTitulo(movie, titulo) &&
			movie_getGenero(movie, genero) &&
			movie_getRating(movie, &rating))
		{
			printf(" %5d   %30s      %30s     %.1f\n", id, titulo, genero, rating);
			todoOk=1;
		}
	}

	return todoOk;
}

void* movie_asignarRating(void* pElement)
{
	eMovie* auxMovie = NULL;
	float rating;
	int minimo=10;
	int maximo=100;

	if(pElement!=NULL)
	{
		auxMovie = (eMovie*)pElement;
		if(auxMovie!=NULL)
		{
			rating = (float)(rand()%(maximo - minimo +1)+minimo)/10;

			movie_setRating(auxMovie, rating);
		}
	}
	return auxMovie;
}

void* movie_asignarGenero(void* pElement)
{
	eMovie* auxMovie = NULL;
	int genero;
	int minimo=1;
	int maximo=4;
	char auxGenero[50];

	if(pElement!=NULL)
	{
		auxMovie = (eMovie*)pElement;
		if(auxMovie!=NULL)
		{
			genero = (rand()%(maximo - minimo +1)+minimo);
			movie_getDescripcionGenero(auxGenero, genero);
			movie_setGenero(auxMovie, auxGenero);
		}
	}
	return auxMovie;
}

int movie_getDescripcionGenero(char* cadena, int movie)
{
	int todoOk=0;

	if(cadena!=NULL && movie>0 && movie<5)
	{
		todoOk=1;
		switch(movie)
		{
		case 1:
			strcpy(cadena, "Drama");
			break;
		case 2:
			strcpy(cadena, "Comedia");
			break;
		case 3:
			strcpy(cadena, "Accion");
			break;
		case 4:
			strcpy(cadena, "Terror");
			break;
		}
	}

	return todoOk;
}

int movie_comparaGeneroDrama(void*  pElement)
{
	int todoOk=0;
	eMovie* pMovie;

	if(pElement!=NULL)
	{
		pMovie = (eMovie*)pElement;

		if(strcmp(pMovie->genero, "Drama") == 0)
		{
			todoOk=1;
		}
	}

	return todoOk;
}

int movie_comparaGeneroComedia(void*  pElement)
{
	int todoOk=0;
	eMovie* pMovie;

	if(pElement!=NULL)
	{
		pMovie = (eMovie*)pElement;

		if(strcmp(pMovie->genero, "Comedia") == 0)
		{
			todoOk=1;
		}
	}

	return todoOk;
}

int movie_comparaGeneroAccion(void*  pElement)
{
	int todoOk=0;
	eMovie* pMovie;

	if(pElement!=NULL)
	{
		pMovie = (eMovie*)pElement;

		if(strcmp(pMovie->genero, "Accion") == 0)
		{
			todoOk=1;
		}
	}

	return todoOk;
}

int movie_comparaGeneroTerror(void*  pElement)
{
	int todoOk=0;
	eMovie* pMovie;

	if(pElement!=NULL)
	{
		pMovie = (eMovie*)pElement;

		if(strcmp(pMovie->genero, "Terror") == 0)
		{
			todoOk=1;
		}
	}

	return todoOk;
}

int movie_compararGenerosYRating(void* a, void* b)
{
	int todoOk=0;
	eMovie* auxA;
	eMovie* auxB;
	char generoA[50];
	char generoB[50];
	float ratingA;
	float ratingB;

	if(a!=NULL && b!=NULL)
	{
		auxA = (eMovie*)a;
		auxB = (eMovie*)b;

		movie_getGenero(auxA, generoA);
		movie_getGenero(auxB, generoB);
		movie_getRating(auxA, &ratingA);
		movie_getRating(auxB, &ratingB);

		if(auxA!=NULL && auxB!=NULL)
		{
			if(strcmp(generoA, generoB)>0)
			{
				todoOk=1;
			}
			else if(strcmp(generoA, generoB)<0)
			{
				todoOk=-1;
			}
			else
			{
				if(ratingA>ratingB)
				{
					todoOk = 1;
				}
				else if(ratingA<ratingB)
				{
					todoOk=-1;
				}
			}
		}
	}
	return todoOk;
}
