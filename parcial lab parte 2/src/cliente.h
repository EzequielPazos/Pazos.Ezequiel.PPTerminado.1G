/*
 * cliente.h
 *
 *  Created on: 23 oct. 2020
 *      Author: Pazos Ezequiel
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct
{
	int id;
	char nombre[20];
	char sexo;
} eCliente;

#endif /* CLIENTE_H_ */

/**
 * @brief
 * @param clientes
 * @param tam
 * @param idCliente
 * @param nombre
 * @return
 */
int obtenerNombreCliente(eCliente clientes[], int tam, int idCliente, char nombre[]);

/**
 * @brief
 * @param clientes
 * @param tam
 * @return
 */
int mostrarClientes(eCliente clientes[], int tam);
