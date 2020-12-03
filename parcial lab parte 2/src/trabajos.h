/*
 * trabajos.h
 *
 *  Created on: 16 oct. 2020
 *      Author: Pazos Ezequiel
 */

#ifndef TRABAJOS_H_
#define TRABAJOS_H_

typedef struct
{
	int id; //autoincremental
	int idMascota; //validar
	int idServicio; //validar
	eFecha fechaTrabajo; //validar dia mes anio
	int isEmpty;
} eTrabajo;

#include "tipos.h"
#include "colores.h"
#include "mascotas.h"
#include "cliente.h"
#include "servicios.h"

#endif /* TRABAJOS_H_ */

/**
 * @brief añade a una lista de trabajos existente los valores recibidos como parametros de la primera posicion vacia
 * @param trabajos array de trabajos
 * @param tam tamanio del array
 * @return devuelve 1 si hubo algun error en la inicializacion o 0 si no hubo ningun error
 */
int inicializarTrabajos(eTrabajo trabajos[], int tam);

/**
 * @brief busca el primer espacio libre en un array de trabajos ya existente
 * @param trabajos array de trabajos
 * @param tam tamanio del array
 * @return devuelve -1 si hubo algun error en la busqueda(sistema completo) o el indice del primer espacio libre en el array
 */
int buscarLibreTrabajo(eTrabajo trabajos[], int tam);

/**
 * @brief da de alta al sistema un trabajo
 * @param trabajos array de trabajos ya existente
 * @param mascotas array de mascotas dadas de alta en el sistema
 * @param servicios array de lista de servicios disponibles
 * @param tipos array de tipos usado para mostrar las mascotas
 * @param colores array de colores usado para mostrar las mascotas
 * @param tam tamanio del array de trabajos
 * @param tam_s tamanio del array de servicios
 * @param tam_tc tamanio del array de tipos y colores
 * @param idTrabajo id a utilizar en el alta del trabajo
 * @return devuelve 0 si no hubo ningun error en el alta o devuelve 1 si hubo algun falla en el alta
 */
int altaTrabajo(eTrabajo trabajos[], eMascota mascotas[], eServicio servicios[], eTipo tipos[], eColor colores[], eCliente clientes[], int tam, int tam_s, int tam_tc, int tam_c,int idTrabajo);

/**
 * @brief muestra una lista de trabajos preexistente
 * @param trabajos array de trabajos
 * @param tam tamaño del array
 * @return devuelve 0 si no hubo ningun error al mostrar la lista de trabajos o devuelve 1 si hubo algun error
 */
int mostrarTrabajos(eTrabajo trabajos[], int tam);

/**
 * @brief
 * @param trabajos
 * @param mascotas
 * @param tipos
 * @param colores
 * @param clientes
 * @param tam
 * @param tam_tc
 * @param tam_c
 * @return
 */
int mostrarTrabajosMascota(eTrabajo trabajos[], eMascota mascotas[], eTipo tipos[], eColor colores[], eCliente clientes[], int tam, int tam_tc, int tam_c);
