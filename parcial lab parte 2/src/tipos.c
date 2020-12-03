/*
 * tipos.c
 *
 *  Created on: 16 oct. 2020
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

int mostrarTipos(eTipo tipos[], int tam)
{
	int error = 1;

	if(tipos !=NULL && tam>0) //verificacion de nulos y tamanios
	{
		system("cls");
		printf("========== LISTADO TIPOS ==========\n");
		printf("-------------------------------------\n");
		printf("   ID         DESCRIPCION\n");
		for(int i=0; i<tam; i++)
		{
			printf("  %d  %20s  \n", tipos[i].id, tipos[i].descripcion); //muestro los tipos
		}
		printf("\n\n");
		error = 0;
	}
	return error;
}

int obtenerDescripcionTipo(eTipo tipos[], int tam, int idMascota, char descripcion[])
{
	int error = 1;

	if(tipos != NULL && tam > 0 && idMascota>0 && descripcion !=NULL) //verificacion de nulos y tamanios
	{
		for(int i=0; i<tam; i++)  //recorro el array
		{
			if(tipos[i].id == idMascota) //busco coincidencias entre id mascota y los id en el array de tipos
			{
				strcpy(descripcion, tipos[i].descripcion); //copio el string en descripcion
				error = 0;
				break;
			}
		}
	}
	return error;
}
