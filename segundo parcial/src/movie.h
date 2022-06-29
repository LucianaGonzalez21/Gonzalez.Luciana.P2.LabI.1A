/*
 * movie.h
 *
 *  Created on: Jun 29, 2022
 *      Author: Dell
 */

#include "linkedList.h"

#ifndef MOVIE_H_
#define MOVIE_H_

typedef struct{
	int id_peli;
	char titulo[50];
	char genero[50];
	float rating;
}eMovie;

#endif /* MOVIE_H_ */

/// @brief Asigna el valor de id que recibe por parametro al campo id del puntero a eMovie
///
/// @param this
/// @param id
/// @return Retorna 1 si pudo hacer la asignacion, 0 si no
int movie_setId(eMovie* this,int id);

/// @brief Asigna el valor de titulo que recibe por parametro al campo titulo del puntero a eMovie
///
/// @param this
/// @param titulo
/// @return Retorna 1 si pudo hacer la asignacion, 0 si no
int movie_setTitulo(eMovie* this,char* titulo);

/// @brief Asigna el valor de genero que recibe por parametro al campo genero del puntero a eMovie
///
/// @param this
/// @param genero
/// @return Retorna 1 si pudo hacer la asignacion, 0 si no
int movie_setGenero(eMovie* this,char* genero);

/// @brief Asigna el valor de rating que recibe por parametro al campo rating del puntero a eMovie
///
/// @param this
/// @param rating
/// @return Retorna 1 si pudo hacer la asignacion, 0 si no
int movie_setRating(eMovie* this,float rating);

/// @brief Escribe el valor del campo id del puntero en el puntero a id pasado por parametro
///
/// @param this
/// @param id
/// @return Retorna 1 si pudo haceerlo, 0 si no
int movie_getId(eMovie* this,int* id);

/// @brief Escribe el valor del campo genero del puntero en el puntero a genero pasado por parametro
///
/// @param this
/// @param genero
/// @return Retorna 1 si pudo haceerlo, 0 si no
int movie_getGenero(eMovie* this,char* genero);

/// @brief Escribe el valor del campo titulo del puntero en el puntero a titulo pasado por parametro
///
/// @param this
/// @param titulo
/// @return Retorna 1 si pudo haceerlo, 0 si no
int movie_getTitulo(eMovie* this,char* titulo);

/// @brief Escribe el valor del campo rating del puntero en el puntero a rating pasado por parametro
///
/// @param this
/// @param rating
/// @return Retorna 1 si pudo haceerlo, 0 si no
int movie_getRating(eMovie* this,float* rating);

/// @brief Crea una nueva pelicula con valores determinados de cada campos
///
/// @return Retorna NULL si no pudo crearlo o el puntero a la pelicula si pudo
eMovie* movie_new();

/// @brief Crea una nueva pelicula asignandole a los campos los valores pasados por parametro
///
/// @param idStr
/// @param titulo
/// @param genero
/// @param duracion
/// @return Retorna NULL si no pudo crearla, o el puntero a la pelicula si pudo
eMovie* movie_newParametros(char* idStr,char* titulo, char* genero, char* duracion);

/// @brief Elimina una pelicula
///
/// @param movie
void movie_delete(eMovie* movie);

/// @brief Elimina todas las peliculas de la lista
///
/// @param pArrayListMovies
/// @return Retorna 0 si hubo error de parametros, sino devuelve 1
int movie_deleteAll(LinkedList* pArrayListMovies);

/// @brief Muestra en pantalla los datos de una sola pelicula
///
/// @param movie
/// @return Devuelve 0 si hubo error de parametros, 1 si no
int movie_print(eMovie* movie);

/// @brief  Asigna un numero flotante random entre 1 y 10 a la pelicula pasada por parametro
///
/// @param pElement
void* movie_asignarRating(void* pElement);

/// @brief Asigna un numero random entre 1 y 4, y segun el numero es el genero que va a asignar a la pelicula
///
/// @param pElement
void* movie_asignarGenero(void* pElement);

/// @brief Escribe en la cadena el genero de la pelicula segun el numero que le haya llegado por parametro
///
/// @param cadena
/// @param movie
/// @return Retorna 0 si hubo error de parametros, 1 si no
int movie_getDescripcionGenero(char* cadena, int movie);

/// @brief Compara si la pelicula recibida por parametro es genero drama
///
/// @param pElement
/// @return Si es genero drama, retorna 1 , sino 0
int movie_comparaGeneroDrama(void*  pElement);

/// @brief Compara si la pelicula recibida por parametro es genero comedia
///
/// @param pElement
/// @return Si es genero comedia, retorna 1 , sino 0
int movie_comparaGeneroComedia(void*  pElement);

/// @brief Compara si la pelicula recibida por parametro es genero accion
///
/// @param pElement
/// @return Si es genero accion, retorna 1 , sino 0
int movie_comparaGeneroAccion(void*  pElement);

/// @brief Compara si la pelicula recibida por parametro es genero terror
///
/// @param pElement
/// @return Si es genero terror, retorna 1 , sino 0
int movie_comparaGeneroTerror(void*  pElement);

/// @brief Compara primero los generos de una pelicula, si estos son iguales, entonces compara sus ratings
///
/// @param a
/// @param b
/// @return Devuelve 0 si son iguales, 1 si la duracion/genero de a es mayor que de b, y -1 si la duracion/genero de a es menor que la de b
int movie_compararGenerosYRating(void* a, void* b);
