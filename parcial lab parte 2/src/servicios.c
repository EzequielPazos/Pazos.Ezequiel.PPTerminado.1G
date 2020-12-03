/*
 * servicios.c
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

int mostrarServicios(eServicio servicios[], int tam)
{
	int error = 1; //falla

	if(servicios !=NULL && tam>0) //verificacion de nulos y tamanios
	{
		system("cls");
		printf("========== LISTADO SERVICIOS ==========\n");
		printf("-------------------------------------\n");
		printf("  ID        DESCRIPCION        PRECIO  \n");
		for(int i=0; i<tam; i++)
		{
			printf("  %d    %20s         %2.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio); //muestro los servicios
		}
		printf("\n\n");
		error = 0;
	}
	return error;
}

int sumaServiciosMascota(eServicio servicios[], eMascota mascotas[],eTipo tipos[], eColor colores[], eCliente clientes[], eTrabajo trabajos[], int tam_s, int tam, int tam_tc, int tam_c)
{
	int error = 1;
	int idMascota;
	float sumaTotalServicios = 0;

	if(servicios !=NULL && mascotas !=NULL && tam_s>0 && tam>0)
	{
		system("cls");
		mostrarMascotas(mascotas, tipos, colores, clientes, tam, tam_tc, tam_c);
		printf("\nIngrese el id de la mascota deseada: ");
		scanf("%d", &idMascota);
		for(int i=0; i<tam; i++)
		{
			if(idMascota == trabajos[i].idMascota)
			{
				for(int j=0; j<tam_s; j++)
				{
					if(trabajos[i].idServicio == servicios[j].id)
					{
						sumaTotalServicios = sumaTotalServicios + servicios[j].precio;
					}
				}
			}
		}
		printf("La suma total de los servicios de la mascota elegida es de: %.2f", sumaTotalServicios);
		error = 0;
	}

	return error;
}

int mascotasDeUnServicio(eServicio servicios[], eMascota mascotas[], eTrabajo trabajos[], int tam_s, int tam)
{
	int error = 1;
	int idServicio;
	int flagServicio = 0;

	if(servicios !=NULL && mascotas !=NULL && trabajos !=NULL && tam_s>0 && tam>0)
	{
		system("cls");
		mostrarServicios(servicios, tam_s);
		printf("\nIngrese el id del servicio deseado: ");
		scanf("%d", &idServicio);

		system("cls");
		printf("========== MASCOTAS DEL SERVICIO SELECCIONADO ==========\n");
		printf("-------------------------------------\n");
		printf("  ID-MASCOTA  FECHA  \n");
		for(int i=0; i<tam; i++)
		{
			if(idServicio == trabajos[i].idServicio)
			{
				printf("  %d   %02d/%02d/%d\n", trabajos[i].idMascota, trabajos[i].fechaTrabajo.dia, trabajos[i].fechaTrabajo.mes, trabajos[i].fechaTrabajo.anio);
				flagServicio = 1;
			}
		}

		if(flagServicio == 1)
		{
			printf("\n\nNo existen mascotas que hayan realizado ese servicio!\n\n");
		}

		error = 0;
	}

	return error;
}
