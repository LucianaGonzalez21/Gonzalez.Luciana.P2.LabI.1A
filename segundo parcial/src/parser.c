/*
 * parser.c
 *
 *  Created on: Jun 28, 2022
 *      Author: Dell
 */

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "linkedList.h"
#include "movie.h"

int parser_MovieFromText(FILE* pFile , LinkedList* pArrayListMovies)
{
	int todoOk=0;
	eMovie* auxiliar;
	int cantidad;
	int retorno;
	char buffer[4][50];


	if (pFile != NULL && pArrayListMovies != NULL)
	{
		todoOk = 1;
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1], buffer[2], buffer[3]);

		while (!feof(pFile))
		{
			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1], buffer[2], buffer[3]);

			if (cantidad == 4)
			{
				auxiliar = movie_newParametros(buffer[0], buffer[1],buffer[2], buffer[3]);

				if (auxiliar != NULL)
				{
					retorno = ll_add(pArrayListMovies, auxiliar);

					if (retorno != 0)
					{
						movie_delete(auxiliar);
						break;
					}
				}
			}
			else
			{
				break;
			}
		}
	}

    return todoOk;
}
