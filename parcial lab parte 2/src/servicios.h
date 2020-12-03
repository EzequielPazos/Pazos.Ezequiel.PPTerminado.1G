/*
 * servicios.h
 *
 *  Created on: 16 oct. 2020
 *      Author: Pazos Ezequiel
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_

typedef struct
{
	int id; //comienza en 20000
	char descripcion[25];
	float precio;
} eServicio;

#include "trabajos.h"

#endif /* SERVICIOS_H_ */

/**
 * @brief muestra una lista de servicios ya hardcodeados
 * @param servicios array de servicios
 * @param tam tamanio del array
 * @return 1 si hubo algun error al mostrar los servicios o devuelve 0 si no hubo ningun error
 */
int mostrarServicios(eServicio servicios[], int tam);

/**
 * @brief
 * @param servicios
 * @param mascotas
 * @param tipos
 * @param colores
 * @param clientes
 * @param trabajos
 * @param tam_s
 * @param tam
 * @param tam_tc
 * @param tam_c
 * @return
 */
int sumaServiciosMascota(eServicio servicios[], eMascota mascotas[],eTipo tipos[], eColor colores[], eCliente clientes[], eTrabajo trabajos[], int tam_s, int tam, int tam_tc, int tam_c);

/**
 * @brief
 * @param servicios
 * @param mascotas
 * @param trabajos
 * @param tam_s
 * @param tam
 * @return
 */
int mascotasDeUnServicio(eServicio servicios[], eMascota mascotas[], eTrabajo trabajos[], int tam_s, int tam);
