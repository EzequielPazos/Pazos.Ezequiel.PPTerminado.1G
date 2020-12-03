/*
 * tipos.h
 *
 *  Created on: 16 oct. 2020
 *      Author: Pazos Ezequiel
 */

#ifndef TIPOS_H_
#define TIPOS_H_

typedef struct
{
	int id; //comienza en 1000
	char descripcion[20];
} eTipo;

#endif /* TIPOS_H_ */

/**
 * @brief muestra una lista de tipos
 * @param tipos array de tipos
 * @param tam tamanio del array
 * @return devuelve 1 si hubo un error al mostrar los tipos o devuelve 0 en caso de  no haber error
 */
int mostrarTipos(eTipo tipos[], int tam);

/**
 * @brief obtiene la descripcion de un tipo a partir del id tipo encontrado en la estructura mascotas
 * @param tipos array de tipos
 * @param tam tamanio del array de tipos
 * @param idMascota id de la mascota de la cual necesito saber el tipo
 * @param descripcion vector donde voy a guardar la descripcion que necesito mostrar al usuario
 * @return devuelve 1 en caso de haber algun error o 0 si no hay ningun error
 */
int obtenerDescripcionTipo(eTipo tipos[], int tam, int idMascota, char descripcion[]);
