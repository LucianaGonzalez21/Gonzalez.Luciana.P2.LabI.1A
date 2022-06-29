/*
 * parser.h
 *
 *  Created on: Jun 28, 2022
 *      Author: Dell
 */

#include "linkedList.h"

#ifndef PARSER_H_
#define PARSER_H_



#endif /* PARSER_H_ */

/// @brief Parsea los datos los datos de las peliculas desde el archivo data.csv (modo texto).
///
/// @param pFile
/// @param pArrayListMovies
/// @return Devuelve 0 si el archivo o la lista no existen, 1 si ok
int parser_MovieFromText(FILE* pFile , LinkedList* pArrayListMovies);
