/*
 * trabajos.c
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

int inicializarTrabajos(eTrabajo trabajos[], int tam)
{
	int error = -1;

	if(trabajos != NULL && tam > 0)
	{
		for(int i=0;i<tam;i++)
		{
			trabajos[i].isEmpty = 1;
		}
		error = 0;
	}

	return error;
}

int buscarLibreTrabajo(eTrabajo trabajos[], int tam)
{
	int indice = -1;

	for(int i=0;i<tam;i++)
	{
		if(trabajos[i].isEmpty == 1)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

int altaTrabajo(eTrabajo trabajos[], eMascota mascotas[], eServicio servicios[], eTipo tipos[], eColor colores[], eCliente clientes[], int tam, int tam_s, int tam_tc, int tam_c,int idTrabajo)
{
	int error = 1; //falla en el alta
	int indice;
	eTrabajo nuevoTrabajo;

	if(trabajos !=NULL && tam>0 && idTrabajo>0)
	{
		system("cls");
		printf("========== ALTA DE TRABAJOS ==========\n\n");
		indice = buscarLibreTrabajo(trabajos, tam);

		if(indice==-1) //error
		{
			printf("     >>> El sistema esta completo <<<");
		}else
		{
			nuevoTrabajo.id = idTrabajo;
			nuevoTrabajo.isEmpty = 0;

			mostrarMascotas(mascotas, tipos, colores, clientes, tam, tam_tc, tam_c);

			printf("\n>Ingrese el ID de la mascota deseada: ");
			scanf("%d", &nuevoTrabajo.idMascota); //falta validar
			while(validarIdMascota(mascotas, tam, nuevoTrabajo.idMascota) == 0)
			{
				printf("\n>La id ingresada no es valida! Intente nuevamente: \n");
				scanf("%d", &nuevoTrabajo.idMascota);
			}

			mostrarServicios(servicios, tam_s);

			printf("\n>Ingrese el ID del servicio deseado: ");
			scanf("%d", &nuevoTrabajo.idServicio); //falta validar
			while(validarIdServicio(servicios, tam_s, nuevoTrabajo.idServicio) == 0)
			{
				printf("\n>La id ingresada no es valida! Intente nuevamente: \n");
				scanf("%d", &nuevoTrabajo.idServicio);
			}
			printf("\nIngrese la fecha de hoy: dd/mm/aaaa");
			scanf("%d/%d/%d", &nuevoTrabajo.fechaTrabajo.dia, &nuevoTrabajo.fechaTrabajo.mes, &nuevoTrabajo.fechaTrabajo.anio); //falta validar
			while(validarFecha(nuevoTrabajo.fechaTrabajo.dia, nuevoTrabajo.fechaTrabajo.mes, nuevoTrabajo.fechaTrabajo.anio) == 0)
			{
				printf("\n\n>La fecha ingresada es invalida! Intente nuevamente: dd/mm/aaaa");
				scanf("%d/%d/%d", &nuevoTrabajo.fechaTrabajo.dia, &nuevoTrabajo.fechaTrabajo.mes, &nuevoTrabajo.fechaTrabajo.anio); //falta validar
			}


			trabajos[indice] = nuevoTrabajo;
			error = 0;
			printf(">Se ha ingresado el trabajo al sistema con exito!");
		}
	}

	return error;
}

int mostrarTrabajos(eTrabajo trabajos[], int tam)
{
	int error = 1;

	if(trabajos !=NULL && tam>0)
	{
		system("cls");
		printf("========== LISTADO TRABAJOS ==========\n");
		printf("-------------------------------------\n");
		printf("  ID  ID-MASCOTA  SERVICIO  FECHA  \n");
		for(int i=0; i<tam; i++)
		{
			if(trabajos[i].isEmpty == 0)
			{
				printf("  %d      %d        %d   %02d/%02d/%d\n", trabajos[i].id, trabajos[i].idMascota, trabajos[i].idServicio, trabajos[i].fechaTrabajo.dia, trabajos[i].fechaTrabajo.mes, trabajos[i].fechaTrabajo.anio);
			}
		}
		printf("\n\n");
		error = 0;
	}
	return error;
}

int mostrarTrabajosMascota(eTrabajo trabajos[], eMascota mascotas[], eTipo tipos[], eColor colores[], eCliente clientes[], int tam, int tam_tc, int tam_c)
{
	int error = 1;
	int idMascota;

	system("cls");
	mostrarMascotas(mascotas, tipos, colores, clientes, tam, tam_tc, tam_c);

	printf("\n\nIngrese la id de la mascota deseada: ");
	scanf("%d", &idMascota);

	if(trabajos !=NULL && idMascota>0 && tam>0)
	{
		system("cls");
		printf("========== LISTADO TRABAJOS DE UNA MASCOTA ==========\n");
		printf("-------------------------------------\n");
		printf("  ID  ID-MASCOTA  SERVICIO  FECHA  \n");
		for(int i=0; i<tam; i++)
		{
			if(idMascota==trabajos[i].idMascota && trabajos[i].isEmpty == 0)
			{
				printf("  %d      %d        %d   %02d/%02d/%d\n", trabajos[i].id, trabajos[i].idMascota, trabajos[i].idServicio, trabajos[i].fechaTrabajo.dia, trabajos[i].fechaTrabajo.mes, trabajos[i].fechaTrabajo.anio);
			}
		}
		error = 0;
	}

	return error;
}
