/*
 * fecha.c
 *
 *  Created on: 16 oct. 2020
 *      Author: EZE_XD
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

int serviciosEnUnaFecha(eFecha unaFecha, eTrabajo trabajos[], int tam)
{
	int error = 1;
	int flagServicio = 0;

	if(trabajos !=NULL && tam>0)
	{
		system("cls");
		printf("Ingrese una fecha deseada : dd/mm/aaaa ");
		scanf("%d/%d/%d", &unaFecha.dia, &unaFecha.mes, &unaFecha.anio);
		while(validarFecha(unaFecha.dia, unaFecha.mes, unaFecha.anio)==0)
		{
			printf("La fecha ingresada no es valida. Ingrese nuevamente: dd/mm/aaaa");
			scanf("%d/%d/%d", &unaFecha.dia, &unaFecha.mes, &unaFecha.anio);
		}

		system("cls");
		printf("========== LISTADO TRABAJOS EN LA FECHA INDICADA ==========\n");
		printf("-------------------------------------\n");
		printf("  ID  ID-MASCOTA  SERVICIO  FECHA  \n");
		for(int i=0; i<tam; i++)
		{
			if(unaFecha.dia == trabajos[i].fechaTrabajo.dia &&
			   unaFecha.mes == trabajos[i].fechaTrabajo.mes &&
			   unaFecha.anio == trabajos[i].fechaTrabajo.anio)
			{
				printf("  %d      %d        %d   %02d/%02d/%d\n", trabajos[i].id, trabajos[i].idMascota, trabajos[i].idServicio, trabajos[i].fechaTrabajo.dia, trabajos[i].fechaTrabajo.mes, trabajos[i].fechaTrabajo.anio);
				flagServicio = 1;
			}
		}
		if(flagServicio == 0)
		{
			printf("\n\n>>> No se realizo ningun servicio en esa fecha <<<\n\n");
		}
		error = 0;
	}

	return error;
}
