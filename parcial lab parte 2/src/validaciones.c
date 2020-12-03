/*
 * validaciones.c
 *
 *  Created on: 23 oct. 2020
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
#include "cliente.h"

int validarIdColor(eColor colores[], int tam, int idColor)
{
	int esValido = 0;

	if(colores !=NULL && tam>0 && idColor>0)
	{
		for(int i=0; i<tam; i++)
		{
			if(colores[i].id == idColor)
			{
				esValido = 1;
				break;
			}
		}
	}
	return esValido;
}

int validarIdTipo(eTipo tipos[], int tam, int idTipo)
{
	int esValido = 0;

	if(tipos !=NULL && tam>0 && idTipo>0)
	{
		for(int i=0; i<tam; i++)
		{
			if(tipos[i].id == idTipo)
			{
				esValido = 1;
				break;
			}
		}
	}
	return esValido;
}

int validarIdServicio(eServicio servicios[], int tam, int idServicio)
{
	int esValido = 0;

	if(servicios !=NULL && tam>0 && idServicio>0)
	{
		for(int i=0; i<tam; i++)
		{
			if(servicios[i].id == idServicio)
			{
				esValido = 1;
				break;
			}
		}
	}
	return esValido;
}

int validarIdMascota(eMascota mascotas[], int tam, int idMascota)
{
	int esValido = 0;

	if(mascotas !=NULL && tam>0 && idMascota>0)
	{
		for(int i=0; i<tam; i++)
		{
			if(mascotas[i].id == idMascota)
			{
				esValido = 1;
				break;
			}
		}
	}
	return esValido;
}

int validarFecha(int dia, int mes, int anio)
{
	int esValido = 0;

	switch (mes)
	{
		case  1 :
		case  3 :
		case  5 :
		case  7 :
		case  8 :
		case 10 :
		case 12 :
			if ( dia >= 1 && dia <= 31 )
			{
				esValido = 1;
			}
			break;
		case  4 :
		case  6 :
		case  9 :
		case 11 :
			if ( dia >= 1 && dia <= 30 )
			{
				esValido = 1;
			}
			break;
		case  2 :
			if( (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0 )
			{
				if ( dia >= 1 && dia <= 29 )
				{
					esValido = 1;
				}else if( dia >= 1 && dia <= 28 )
				{
					esValido = 1;
				}
			}
			break;
		default:
			esValido = 0;
	}
	return esValido;
}

int validarIdCliente(eCliente clientes[], int tam, int idCliente)
{
	int esValido = 0;

	if(clientes !=NULL && tam>0 && idCliente>0)
	{
		for(int i=0; i<tam; i++)
		{
			if(clientes[i].id == idCliente)
			{
				esValido = 1;
				break;
			}
		}
	}
	return esValido;
}
