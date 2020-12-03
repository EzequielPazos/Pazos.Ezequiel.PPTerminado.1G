/*
 * validaciones.h
 *
 *  Created on: 23 oct. 2020
 *      Author: Pazos Ezequiel
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



#endif /* VALIDACIONES_H_ */

/**
 * @brief valida que la id del color ingresado por el usuario coincida con alguna existente en el sistema
 * @param colores array de colores
 * @param tam tamanio del array de colores a recorrer
 * @param idColor id del color ingresado
 * @return devuelve 0 en caso de que la id no sea valida o 1 en caso de que la id sea valida
 */
int validarIdColor(eColor colores[], int tam, int idColor);

/**
 * @brief valida que la id del color ingresado por el usuario coincida con alguna existente en el sistema
 * @param tipos array de tipos
 * @param tam tamanio del array de tipos a recorrer
 * @param idTipo id a validar
 * @return devuelve 0 en caso de que la id no sea valida o 1 en caso de que la id sea valida
 */
int validarIdTipo(eTipo tipos[], int tam, int idTipo);

/**
 * @brief valida que el id ingresado sea igual al de algun servicio ya existente en el array de servicios
 * @param servicios array de servicios
 * @param tam tamanio del array servicios
 * @param idServicio id del servicio a validar
 * @return devuelve un 0 si la id no es valida o un 1 si la id es valida
 */
int validarIdServicio(eServicio servicios[], int tam, int idServicio);

/**
 * @brief valida que el id ingresado sea igual al de alguna mascota ya existente en el array de mascotas
 * @param mascotas array de mascotas
 * @param tam tamanio del array de mascotas
 * @param idMascota id de la mascota especifica
 * @return devuelve un 0 si la id no es valida o un 1 si la id es valida
 */
int validarIdMascota(eMascota mascotas[], int tam, int idMascota);

/**
 * @brief valida una fecha especifica
 * @param dia dia introducido
 * @param mes mes introducido
 * @param anio anio introducido
 * @return 0 si la fecha es invalida o 1 si al fecha es valida
 */
int validarFecha(int dia, int mes, int anio);

/**
 * @brief valida que el id ingresado sea igual al de algun cliente ya existente en el array de clientes
 * @param clientes array de clientes donde se realiza la busqueda
 * @param tam tamanio del array de clientes
 * @param idCliente id del cliente a validar
 * @return devuelve un 0 si la id no es valida o un 1 si la id es valida
 */
int validarIdCliente(eCliente clientes[], int tam, int idCliente);
