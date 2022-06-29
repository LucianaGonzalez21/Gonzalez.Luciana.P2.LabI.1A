/*
 * controller.h
 *
 *  Created on: Jun 28, 2022
 *      Author: Dell
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */

/** \brief Carga los datos de las peliculas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListMovies LinkedList* ---------
 * \return int Devuelve 0 si hubo error de parametros, 1 si pudo cargar los datos
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListMovies);

/// @brief Muestra la lista de peliculas
///
/// @param pArrayListMovies
/// @return Devuelve 0 si hubo error de parametros, 1 si no
int controller_ListMovies(LinkedList* pArrayListMovies);

/// @brief Guarda en un archivo la lista de peliculas
///
/// @param path
/// @param pArrayListMovies
/// @return Retorna 0 si hubo error de parametros, 1 si no
int controller_saveAsText(char* path , LinkedList* pArrayListMovies);

/// @brief Asigna un rating random a cada pelicula de la lista
///
/// @param pArrayListMovies
/// @return Retorna 0 si hubo error de parametros, 1 si no
int controller_asignarRatingPeliculas(LinkedList* pArrayListMovies);

/// @brief Asigna un genero random a cada pelicula de la lista
///
/// @param pArrayListMovies
/// @return Retorna 0 si hubo error de parametros, 1 si no
int controller_asignarGeneroPeliculas(LinkedList* pArrayListMovies);

/// @brief Guarda en un archivo las peliculas de genero drama
///
/// @param pArrayListMovies
/// @return Retorna 0 si hubo error de parametros, 1 si pudo guardar el archivo
int controller_filtrarPeliculasDrama(LinkedList* pArrayListMovies);

/// @brief Guarda en un archivo las peliculas de genero comedia
///
/// @param pArrayListMovies
/// @return
int controller_filtrarPeliculasComedia(LinkedList* pArrayListMovies);

/// @brief guarda en un archivo las peliculas de genero accion
///
/// @param pArrayListMovies
/// @return Retorna 0 si hubo error de parametros, 1 si pudo guardar el archivo
int controller_filtrarPeliculasAccion(LinkedList* pArrayListMovies);

/// @brief ordena la lista de peliculas recibida por genero y por rating
///
/// @param pArrayListMovies
/// @return
int controller_OrdenarPorGeneroYRating(LinkedList* pArrayListMovies);

/// @brief guarda en un archivo las peliculas de genero terror
///
/// @param pArrayListMovies
/// @return Retorna 0 si hubo error de parametros, 1 si pudo guardar el archivo
int controller_filtrarPeliculasTerror(LinkedList* pArrayListMovies);

/// @brief crea un archivo de peliculas segun el genero elegido
///
/// @param pArrayListMovies
/// @return Retorna 0 si hubo error de parametros, 1 si pudo guardar el archivo
int controller_filtrarPeliculasPorGenero(LinkedList* pArrayListMovies);


