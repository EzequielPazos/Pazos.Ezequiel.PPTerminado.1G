/*
 * colores.c
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

int mostrarColores(eColor colores[], int tam)
{
	int error = 1; //falla

	if(colores !=NULL && tam>0) //verificacion de nulos y tamanios
	{
		system("cls");
		printf("========== LISTADO COLORES ==========\n");
		printf("-------------------------------------\n");
		printf("  ID         COLOR\n");
		for(int i=0; i<tam; i++)
		{
			printf("  %d  %20s  \n", colores[i].id, colores[i].nombreColor);
		}
		printf("\n\n");
		error = 0;
	}
	return error;
}

int obtenerDescripcionColor(eColor colores[], int tam, int idMascota, char descripcion[])
{
	int error = 1; //falla

	if(colores != NULL && tam > 0 && idMascota>0 && descripcion !=NULL) //verificacion de nulos y tamanios
	{
		for(int i=0; i<tam; i++)
		{
			if(colores[i].id == idMascota) //recorro el array de colores en la seccion de id buscando coincidencias con mi id mascota
			{
				strcpy(descripcion, colores[i].nombreColor); //copio los datos en descripcion en caso de coincidir
				error = 0;
				break;
			}
		}
	}
	return error;
}

int coloresConMasMascotas(eColor colores[], eMascota mascotas[], int tam_tc, int tam)
{
	int error = 1;
	int contadorMascotasNegras = 0;
	int contadorMascotasBlancas = 0;
	int contadorMascotasGrises = 0;
	int contadorMascotasRojas = 0;
	int contadorMascotasAzules = 0;

	if(colores !=NULL && mascotas !=NULL && tam_tc>0 && tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			switch(mascotas[i].idColor)
			{
				case 5000:
					contadorMascotasNegras++;
					break;
				case 5001:
					contadorMascotasBlancas++;
					break;
				case 5002:
					contadorMascotasGrises++;
					break;
				case 5003:
					contadorMascotasRojas++;
					break;
				default:
					contadorMascotasAzules++;
					break;
			}
		}

		if(contadorMascotasNegras>=contadorMascotasBlancas &&
		   contadorMascotasNegras>=contadorMascotasGrises &&
		   contadorMascotasNegras>=contadorMascotasRojas &&
		   contadorMascotasNegras>=contadorMascotasAzules)
		{
			printf("El color con mas mascotas es el negro con %d mascotas", contadorMascotasNegras);
		}else if(contadorMascotasBlancas>=contadorMascotasGrises &&
				 contadorMascotasBlancas>=contadorMascotasRojas &&
				 contadorMascotasBlancas>=contadorMascotasAzules)
		{
			printf("El color con mas mascotas es el blanco con %d mascotas", contadorMascotasBlancas);
		}else if(contadorMascotasGrises>=contadorMascotasRojas &&
				 contadorMascotasGrises>=contadorMascotasAzules)
		{
			printf("El color con mas mascotas es el gris con %d mascotas", contadorMascotasGrises);
		}else if(contadorMascotasRojas>=contadorMascotasAzules)
		{
			printf("El color con mas mascotas es el rojo con %d mascotas", contadorMascotasRojas);
		}else
		{
			printf("El color con mas mascotas es el azul con %d mascotas", contadorMascotasAzules);
		}

		error = 0;
	}

	return error;
}
