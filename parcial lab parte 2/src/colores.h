/*
 * colores.h
 *
 *  Created on: 16 oct. 2020
 *      Author: Pazos Ezequiel
 */

#ifndef COLORES_H_
#define COLORES_H_

typedef struct
{
	int id; //comienza en 5000
	char nombreColor[20];
} eColor;

#include "mascotas.h"

#endif /* COLORES_H_ */

/**
 * @brief muestra una lista de colores
 * @param colores array de colores
 * @param tam tamanio del array
 * @return devuelve 1 si hubo un error al mostrar la lista o 0 en caso de que todo haya ido correctamente
 */
int mostrarColores(eColor colores[], int tam);

/**
 * @brief obtiene la descripcion de un color a partir del id color encontrado en la estructura mascotas
 * @param colores array de colores
 * @param tam tamanio del array de colores
 * @param idMascota id de la mascota de la cual necesito saber el color
 * @param descripcion vector en el que voy a guardar el nombre del color para mostrar al usuario
 * @return devuelve 1 en caso de haber algun error o 0 si no hay ningun error
 */
int obtenerDescripcionColor(eColor colores[], int tam, int idMascota, char descripcion[]);

/**
 * @brief cuenta cuantas mascotas hay de cada color y muestra el color con mas mascotas ingresadas
 * @param colores array de colores
 * @param mascotas array de mascotas
 * @param tam_tc tamanio del array de colores
 * @param tam tamanio del array de mascotas
 * @return devuelve 1 en caso de haber algun error o 0 si no hay ningun error
 */
int coloresConMasMascotas(eColor colores[], eMascota mascotas[], int tam_tc, int tam);
