/*
 * cliente.c
 *
 *  Created on: 23 oct. 2020
 *      Author: Pazos Ezequiel
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fecha.h"
#include "tipos.h"
#include "colores.h"
#include "mascotas.h"
#include "servicios.h"
#include "trabajos.h"
#include "validaciones.h"
#include "cliente.h"

int obtenerNombreCliente(eCliente clientes[], int tam, int idCliente, char nombre[])
{
	int error = 1;

	if(clientes != NULL && tam > 0 && idCliente>0 && nombre !=NULL) //verificacion de nulos y tamanios
	{
		for(int i=0; i<tam; i++)  //recorro el array
		{
			if(clientes[i].id == idCliente) //busco coincidencias entre id mascota y los id en el array de tipos
			{
				strcpy(nombre, clientes[i].nombre); //copio el string en descripcion
				error = 0;
				break;
			}
		}
	}
	return error;
}

int mostrarClientes(eCliente clientes[], int tam)
{
	int error = 1;

	if(clientes !=NULL && tam>0) //verificacion de nulos y tamanios
	{
		system("cls");
		printf("========== LISTADO CLIENTES ==========\n");
		printf("-------------------------------------\n");
		printf("   ID         NOMBRE        SEXO   \n");
		for(int i=0; i<tam; i++)
		{
			printf("  %4d  %20s %c \n", clientes[i].id, clientes[i].nombre, clientes[i].sexo); //muestro los clientes
		}
		printf("\n\n");
		error = 0;
	}
	return error;
}
