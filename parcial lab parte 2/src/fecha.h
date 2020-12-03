/*
 * fecha.h
 *
 *  Created on: 16 oct. 2020
 *      Author: Pazos Ezequiel
 */

#ifndef FECHA_H_
#define FECHA_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
} eFecha;

#include "trabajos.h"

#endif /* FECHA_H_ */

/**
 * @brief
 * @param unaFecha
 * @param trabajos
 * @param tam
 * @return
 */
int serviciosEnUnaFecha(eFecha unaFecha, eTrabajo trabajos[], int tam);
