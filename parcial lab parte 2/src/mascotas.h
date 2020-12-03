/*
 * mascotas.h
 *
 *  Created on: 16 oct. 2020
 *      Author: Pazos Ezequiel
 */

#ifndef MASCOTAS_H_
#define MASCOTAS_H_

typedef struct
{
	int id;
	char nombre[20];
	int idTipo;
	int idColor;
	int edad;
	int idCliente;
	int isEmpty; // 1 vacia 0 llena
} eMascota;

#endif /* MASCOTAS_H_ */

#include "cliente.h"

/**
 * @brief añade a una lista de mascotas existente los valores recibidos como parametros de la primera posicion vacia
 * @param mascotas array de mascotas a inicializar
 * @param tam tamanio del array de mascotas
 * @return devuelve 0 si no hubo ningun error o devuelve 1 si hubo algun error en la inicializacion
 */
int inicializarMascotas(eMascota mascotas[], int tam);

/**
 * @brief busca el primer espacio libre en un array de mascotas
 * @param mascotas array de mascotas en el que se realiza la busqueda
 * @param tam tamanio del array de mascotas
 * @return devuelve -1 si hubo algun error en la busqueda(sistema completo) o el indice del primer espacio libre en el array
 */
int buscarLibreMascotas(eMascota mascotas[], int tam);

/**
 * @brief da de alta en el sistema una mascota siguiendo la estructura eMascota
 * @param mascotas array de mascotas
 * @param tipos array de tipos
 * @param colores array de colores
 * @param clientes array de clientes
 * @param tam tamanio del array de mascotas
 * @param tam_tc tamanio del array de tipos y colores
 * @param tam_c tamanio del array de clientes
 * @param idMascota id de la nueva mascota dada de alta
 * @return devuelve 0 si no hubo ningun error en el alta o devuelve 1 si hubo algun falla en el alta
 */
int altaMascota(eMascota mascotas[], eTipo tipos[], eColor colores[], eCliente clientes[], int tam, int tam_tc, int tam_c, int idMascota);

/**
 * @brief muestra por pantalla los datos de una mascota en especifica
 * @param unaMascota la mascota en especifica
 * @param tipos array de tipos
 * @param colores array de colores
 * @param tam_tc tamanio del array de tipos y colores
 */
void mostrarMascota(eMascota unaMascota, eTipo tipos[], eColor colores[], eCliente clientes[] ,int tam_tc, int tam_c);

/**
 * @brief muestra por pantalla todas las mascotas ingresadas en el sistema y sus datos
 * @param mascotas array de mascotas
 * @param tipos array de tipos
 * @param colores array de colores
 * @param tam tamanio del array de mascotas
 * @param tam_tc tamanio del array de tipos y colores
 * @return devuelve 0 en caso de que no haya ningun error al mostrar la lista de mascotas o devuelve 1 en caso de que haya algun error
 */
int mostrarMascotas(eMascota mascotas[], eTipo tipos[], eColor colores[], eCliente clientes[],int tam, int tam_tc, int tam_c);

/**
 * @brief busca una mascota en especifico en el sistema
 * @param mascotas array de mascotas
 * @param tam tamanio del array de mascotas
 * @param idMascota id de la mascota a buscar
 * @return devuelve -1 si no se encontro a la mascota en el sistema o devuelve el indice del array de mascotas
 * en el que se encuentra la mascota que se buscaba
 */
int buscarMascota(eMascota mascotas[], int tam, int idMascota);

/**
 * @brief modifica el tipo o edad de una mascota en especifica
 * @param mascotas array de mascotas
 * @param tipos array de tipos
 * @param colores array de colores
 * @param tam tamanio del array de mascotas
 * @param tam_tc tamanio del array de tipos y colores
 * @return devuelve 1 si hubo algun error en la modificacion o devuelve 0 si se modifico la mascota correctamente
 */
int modificarMascota(eMascota mascotas[], eTipo tipos[], eColor colores[], eCliente clientes[], int tam, int tam_tc, int tam_c);

/**
 * @brief borrado logico de una mascota en especifica
 * @param mascotas array de mascotas
 * @param tipos array de tipos
 * @param colores array de colores
 * @param tam tamanio del array de mascotas
 * @param tam_tc tamanio del array de tipos y colores
 * @return devuelve 1 en caso de algun fallo durante la baja, 2 en caso de que el usuario
 *  no haya confirmado querido confirmar el borrado o 0 en caso de que el borrado se haya realizado correctamente
 */
int bajaMascota(eMascota mascotas[], eTipo tipos[], eColor colores[], eCliente clientes[], int tam, int tam_tc, int tam_c);

/**
 * @brief ordena las mascotas segun su tipo y luego segun su nombre y por doble criterio
 * @param mascotas array de mascotas
 * @param tam tamanio del array de mascotas
 * @param criterioTipo criterio del tipo
 * @param criterioNombre criterio del nombre
 * @return devuelve 1 si hubo algun error durante el ordenamiento o 0 si no hubo ningun tipo de error
 */
int ordenarMascotasTipoNombre(eMascota mascotas[], int tam, int criterioTipo, int criterioNombre);

/**
 * @brief muestra las mascotas por un color en especifico
 * @param mascotas array de mascotas
 * @param colores array de colores
 * @param tam tamanio del array de mascotas
 * @param tam_tc tamanio del array de color
 * @return devuelve 1 si hubo algun error o 0 si no hubo ningun tipo de error
 */
int mostrarMascotasColor(eMascota mascotas[], eColor colores[],  int tam, int tam_tc);

/**
 * @brief obtiene el nombre de una mascota a partir de la id de la misma
 * @param mascotas array de mascotas
 * @param tam tamanio del array de mascotas
 * @param idMascota id de la mascota que utilizado para buscar el nombre
 * @param nombre variable en la que guardo el nombre
 * @return devuelve 1 si hubo algun error o 0 si no hubo ningun tipo de error
 */
int obtenerNombreMascota(eMascota mascotas[], int tam, int idMascota, char nombre[]);

/**
 * @brief muestra las mascotas por un tipo en especifico
 * @param mascotas array de mascotas
 * @param tipos array de tipos
 * @param tam tamanio del array de mascotas
 * @param tam_tc tamanio del array de tipos
 * @return devuelve 1 si hubo algun error o 0 si no hubo ningun tipo de error
 */
int mostrarMascotasTipo(eMascota mascotas[], eTipo tipos[], int tam, int tam_tc);

/**
 * @brief muestra los nombres de las mascotas menores
 * @param mascotas array de mascotas
 * @param tam tamanio del array de mascotas
 * @return devuelve 1 si hubo algun error o 0 si no hubo ningun tipo de error
 */
int mostrarMascotasMenores(eMascota mascotas[], int tam);

/**
 * @brief ordena las mascotas segun su tipo
 * @param mascotas array de mascotas a ordenar
 * @param tam tamanio del array de mascotas
 * @param criterioTipo criterio ascendente o descendente
 * @return devuelve 1 si hubo algun error o 0 si no hubo ningun tipo de error
 */
int ordenarMascotasTipo(eMascota mascotas[], int tam, int criterioTipo);

/**
 * @brief cuenta las mascotas de un tipo y de un color
 * @param mascotas array de mascotas
 * @param colores array de colores
 * @param tipos array de tipos
 * @param tam tamanio del array de mascotas
 * @param tam_tc tamanio del array de colores y tipos
 * @return devuelve 1 si hubo algun error o 0 si no hubo ningun tipo de error
 */
int contarMascotasColorTipo(eMascota mascotas[], eColor colores[], eTipo tipos[], int tam, int tam_tc); //WIP
