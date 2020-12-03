/*
 * mascotas.c
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

int inicializarMascotas(eMascota mascotas[], int tam)
{
	int error = -1; //falla

	if(mascotas != NULL && tam > 0) //verifico si el array esta vacio y si el tamanio de este es mayor a 0
	{
		for(int i=0;i<tam;i++) //recorro array de mascotas
		{
			mascotas[i].isEmpty = 1; //primer indice vacio
		}
		error = 0; //no hubo errores
	}

	return error;
}

int buscarLibreMascotas(eMascota mascotas[], int tam)
{
	int indice = -1;

	for(int i=0;i<tam;i++)
	{
		if(mascotas[i].isEmpty == 1)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

void mostrarMascota(eMascota unaMascota, eTipo tipos[], eColor colores[], eCliente clientes[] ,int tam_tc, int tam_c)
{
	char descripcionTipo[20];
	char nombreColor[20];
	char nombreCliente[20];

	if(obtenerDescripcionTipo(tipos, tam_tc, unaMascota.idTipo, descripcionTipo)==0 &&
	   obtenerDescripcionColor(colores, tam_tc, unaMascota.idColor, nombreColor)==0 &&
	   obtenerNombreCliente(clientes, tam_c, unaMascota.idCliente, nombreCliente)==0)
	{
		printf("%d %s %s %s %d %s\n", unaMascota.id, unaMascota.nombre, descripcionTipo, nombreColor, unaMascota.edad, nombreCliente);
	}else
	{
		printf("Problema al obtener la descripcion del tipo o color!");
	}

}

int mostrarMascotas(eMascota mascotas[], eTipo tipos[], eColor colores[], eCliente clientes[],int tam, int tam_tc, int tam_c)
{
	int error = 1;
	int flag = 0;

	if(mascotas !=NULL && tam>0)
	{
		printf("  ID  NOMBRE  TIPO  COLOR  EDAD  DUENIO\n");
		printf("----------------------------------------\n");

		for(int i=0; i<tam; i++)
		{
			if(mascotas[i].isEmpty == 0)
			{
				mostrarMascota(mascotas[i], tipos, colores, clientes, tam_tc, tam_c);
				flag = 1;
			}
		}

		if(flag == 0)
		{
			printf("  No hay ninguna mascota en la lista!");
		}
		printf("\n\n");

		error = 0;
	}
	return error;
}

int altaMascota(eMascota mascotas[], eTipo tipos[], eColor colores[], eCliente clientes[], int tam, int tam_tc, int tam_c, int idMascota)
{
	int error = 1; //falla en el alta
	int indice;
	eMascota nuevaMascota;

	if(mascotas !=NULL && tam>0 && idMascota>0)
	{
		system("cls");
		printf("========== ALTA DE MASCOTAS ==========\n\n");
		indice = buscarLibreMascotas(mascotas, tam);

		if(indice==-1) //error sistema completo
		{
			printf("     >>> El sistema esta completo <<<");
		}else
		{
			nuevaMascota.id = idMascota;
			printf("Ingrese el nombre: "); //ingreso del nombre
			fflush(stdin);
			gets(nuevaMascota.nombre);

			mostrarTipos(tipos, tam_tc);

			printf("Ingrese el ID del tipo: "); //ingreso del tipo y validacion
			scanf("%d", &nuevaMascota.idTipo);
			while(validarIdTipo(tipos, tam_tc, nuevaMascota.idTipo) == 0)
			{
				printf("\n>La id ingresada no es valida! Intente nuevamente: ");
				scanf("%d", &nuevaMascota.idTipo);
			}

			mostrarColores(colores, tam_tc);

			printf("Ingrese el ID del color: "); //ingreso del color y validacion
			scanf("%d", &nuevaMascota.idColor);
			while(validarIdColor(colores, tam_tc, nuevaMascota.idColor) == 0)
			{
				printf("\n>La id ingresada no es valida! Intente nuevamente: ");
				scanf("%d", &nuevaMascota.idColor);
			}

			printf("\nIngrese la edad: ");  //ingreso de la edad y validacion
			scanf("%d", &nuevaMascota.edad);
			while(nuevaMascota.edad > 30 || nuevaMascota.edad < 1)
			{
				printf("\n>La edad ingresada no es valida. Ingrese nuevamente la edad: ");
				scanf("%d", &nuevaMascota.edad);
			}

			mostrarClientes(clientes, tam_c);

			printf("Ingrese el ID del cliente dueño de la mascota: "); //ingreso del cliente y validacion
			scanf("%d", &nuevaMascota.idCliente);
			while(validarIdCliente(clientes, tam_c, nuevaMascota.idCliente) == 0)
			{
				printf("\n>La id ingresada no es valida! Intente nuevamente: ");
				scanf("%d", &nuevaMascota.idCliente);
			}

			nuevaMascota.isEmpty = 0;
			mascotas[indice] = nuevaMascota;
			error = 0;
			printf("\n>Se ha ingresado la mascota al sistema con exito!");
		}
	}
	return error;
}

int buscarMascota(eMascota mascotas[], int tam, int idMascota)
{
	int indice = -1;

	for(int i=0;i<tam;i++)
	{
		if(mascotas[i].id == idMascota)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

int modificarMascota(eMascota mascotas[], eTipo tipos[], eColor colores[], eCliente clientes[], int tam, int tam_tc, int tam_c)
{
	int error = 1;
	int idMascota;
	int indice;
	char opcion;
	char seguir = 's';

	if(mascotas != NULL && tam > 0)
	{
		system("cls");
		printf("========== MODIFICACION MASCOTAS ==========\n\n");
		mostrarMascotas(mascotas, tipos, colores, clientes,tam, tam_tc, tam_c);
		printf(">Ingrese el ID de la mascota que desea modificar: ");
		scanf("%d", &idMascota);

		indice = buscarMascota(mascotas, tam, idMascota);

		if(indice == -1)
		{
			printf("\n>>> No existe una mascota con esa ID! <<<\n\n");
		}else
		{
			mostrarMascota(mascotas[indice], tipos, colores, clientes, tam_tc, tam_c);

			do{
				printf("\n===== MODIFICACIONES =====\n\n");
				printf("A ---> TIPO\n");
				printf("B ---> EDAD\n\n");
				printf("Z ---> Volver atras\n\n");
				scanf("%c", &opcion); //FALTA VALIDAR QUE SEA UNA LETRA
				fflush(stdin);
				opcion = tolower(getchar());

				switch(opcion)
				{
					case 'a':
						mostrarTipos(tipos, tam_tc);
						printf("\nIngrese la ID del tipo deseado: ");
						scanf("%d", &mascotas[indice].idTipo);
						printf("\n\nEl cambio de tipo ha sido realizado con exito!\n");
						system("pause");
						break;
					case 'b':
						printf("\nIngrese la edad: \n\n");
						scanf("%d", &mascotas[indice].edad);
						printf("\n\nEl cambio de edad ha sido realizado con exito!\n");
						system("pause");
						break;
					case 'z':
						seguir = 'n';
						break;
					default:
						printf("\nLa opcion ingresada no existe!\n\n"); //validacion de las opciones disponibles
						system("pause");
						break;
				}
				error = 0;
			}while(seguir == 's');
		}
	}
	return error;
}

int bajaMascota(eMascota mascotas[], eTipo tipos[], eColor colores[], eCliente clientes[], int tam, int tam_tc, int tam_c)
{
	int error = 1; //error en la baja
	int idMascota;
	int indice;
	char confirma;

	if(mascotas != NULL && tam > 0)
	{
		system("cls");
		printf("========== BAJA DE MASCOTA ==========\n\n");
		mostrarMascotas(mascotas, tipos, colores, clientes, tam, tam_tc, tam_c);
		printf("Ingrese el ID de la mascota: ");
		scanf("%d", &idMascota);

		indice = buscarMascota(mascotas, tam, idMascota);

		if(indice == -1)
		{
			printf(">>> No existe una mascota con esa ID! <<<\n\n");
		}else
		{
			mostrarMascota(mascotas[indice], tipos, colores, clientes, tam_tc, tam_c);
			printf("Confirma el borrado?: Ingrese s/n"); //falta validacion
			fflush(stdin);
			scanf("%c", &confirma);
			confirma = tolower(confirma);

			if(confirma =='s')
			{
				mascotas[indice].isEmpty = 1;
				error = 0; //borrado correctamente
			}else
			{
				error = 2; //no confirma el borrado
			}
		}
	}
	return error;
}

int ordenarMascotasTipoNombre(eMascota mascotas[], int tam, int criterioTipo, int criterioNombre)
{
	int error = 1;
	eMascota auxMascota;

	if(mascotas !=NULL && tam>0 && criterioTipo >= 0 && criterioTipo <= 1 && criterioNombre >= 0 && criterioNombre <= 1)
	{
		for(int i=0; i<tam-1; i++)
		{
			for(int j=i+1; j<tam; j++)
			{
				if(mascotas[i].idTipo > mascotas[j].idTipo && criterioTipo == 1)
				{
					auxMascota = mascotas[i];
					mascotas[i] = mascotas[j];
					mascotas[j] = auxMascota;
				}
				else if(mascotas[i].idTipo < mascotas[j].idTipo && criterioTipo == 0)
				{
					auxMascota = mascotas[i];
					mascotas[i] = mascotas[j];
					mascotas[j] = auxMascota;
				}
				else if(mascotas[i].idTipo == mascotas[j].idTipo && mascotas[i].nombre > mascotas[j].nombre && criterioNombre == 1)
				{
					auxMascota = mascotas[i];
					mascotas[i] = mascotas[j];
					mascotas[j] = auxMascota;
				}
				else if(mascotas[i].idTipo == mascotas[j].idTipo && mascotas[i].nombre < mascotas[j].nombre && criterioNombre == 0)
				{
					auxMascota = mascotas[i];
					mascotas[i] = mascotas[j];
					mascotas[j] = auxMascota;
				}
			}
		}
		error = 0;
	}
	return error;
}

int mostrarMascotasColor(eMascota mascotas[], eColor colores[],  int tam, int tam_tc)
{
	int error = 1;
	int idColorElegido;
	int flag = 0;
	char nombre[20];

	if(mascotas !=NULL && tam>0 && colores !=NULL && tam_tc>0)
	{
		system("cls");
		printf(">Mascotas del color elegido\n\n");

		mostrarColores(colores, tam_tc);

		printf("\n\nIngrese el ID del color deseado: ");
		scanf("%d", &idColorElegido);
		while(validarIdColor(colores, tam_tc, idColorElegido) == 0)
		{
			printf("/n>La id ingresada no es valida! Intente nuevamente: \n");
			scanf("%d", &idColorElegido);
		}

		for(int i=0;i<tam;i++)
		{
			if(mascotas[i].idColor == idColorElegido)
			{
				obtenerNombreMascota(mascotas, tam, mascotas[i].id, nombre);
				printf(">Mascotas del color elegido\n\n");
				printf("\n%s \n\n", nombre);
				flag = 1;
			}
		}

		if(flag ==0)
		{
			printf(">No hay niguna mascota de ese color\n\n");
		}

		error = 0;
	}
	return error;
}

int obtenerNombreMascota(eMascota mascotas[], int tam, int idMascota, char nombre[])
{
	int error = 1;

	if(mascotas != NULL && tam>0 && nombre !=NULL)
	{
		for(int i=0; i<tam; i++)
		{
			if(mascotas[i].id == idMascota && mascotas[i].isEmpty == 0)
			{
				strcpy(nombre, mascotas[i].nombre);
				error = 0;
				break;
			}
		}
	}
	return error;
}

int mostrarMascotasTipo(eMascota mascotas[], eTipo tipos[], int tam, int tam_tc)
{
	int error = 1;
	int idTipoElegido;
	int flag = 0;
	char nombre[20];

	if(mascotas !=NULL && tam>0 && tipos !=NULL && tam_tc>0)
	{
		system("cls");

		mostrarTipos(tipos, tam_tc);

		printf("\n\nIngrese el ID del tipo deseado: ");
		scanf("%d", &idTipoElegido);
		while(validarIdTipo(tipos, tam_tc, idTipoElegido) == 0)
		{
			printf("/n>La id ingresada no es valida! Intente nuevamente: \n");
			scanf("%d", &idTipoElegido);
		}

		for(int i=0;i<tam;i++)
		{
			if(mascotas[i].idTipo == idTipoElegido)
			{
				obtenerNombreMascota(mascotas, tam, mascotas[i].id, nombre);
				printf(">Mascotas del tipo elegido\n\n");
				printf("\n%s \n\n", nombre);
				flag = 1;
			}
		}

		if(flag ==0)
		{
			printf(">No hay niguna mascota de ese tipo\n\n");
		}

		error = 0;
	}
	return error;
}

int mostrarMascotasMenores(eMascota mascotas[], int tam)
{
	int error = 1;
	int flag = 0;
	char nombre[20];

	if(mascotas !=NULL && tam>0)
	{
		system("cls");
		printf("===== Mascotas menores de edad =====\n\n");
		for(int i=0;i<tam;i++)
		{
			if(mascotas[i].edad < 18 && mascotas[i].isEmpty == 0)
			{
				obtenerNombreMascota(mascotas, tam, mascotas[i].id, nombre);
				printf("\n%s \n\n", nombre);
				flag = 1;
			}
		}
		if(flag == 0)
		{
			printf(">No hay ninguna mascota de ese tipo\n\n");
		}
		error = 0;
	}
	return error;
}

int ordenarMascotasTipo(eMascota mascotas[], int tam, int criterioTipo)
{
	int error = 1;
	eMascota auxMascota;

	if(mascotas !=NULL && tam>0 && criterioTipo >= 0 && criterioTipo <= 1)
	{
		for(int i=0; i<tam-1; i++)
		{
			for(int j=i+1; j<tam; j++)
			{
				if(mascotas[i].idTipo > mascotas[j].idTipo && criterioTipo == 1)
				{
					auxMascota = mascotas[i];
					mascotas[i] = mascotas[j];
					mascotas[j] = auxMascota;
				}
				else if(mascotas[i].idTipo < mascotas[j].idTipo && criterioTipo == 0)
				{
					auxMascota = mascotas[i];
					mascotas[i] = mascotas[j];
					mascotas[j] = auxMascota;
				}
			}
		}
		error = 0;
	}
	return error;
}

int contarMascotasColorTipo(eMascota mascotas[], eColor colores[], eTipo tipos[], int tam, int tam_tc)
{
	int flagColorTipo = 0;
	int idColorElegido;
	int contadorColorTipo = 0;
	int idTipoElegido;

	if(mascotas !=NULL && tam>0 && colores !=NULL && tipos !=NULL && tam_tc>0)
	{
		mostrarColores(colores, tam_tc);

		printf("\n\nIngrese el ID del color deseado: ");
		scanf("%d", &idColorElegido);
		while(validarIdColor(colores, tam_tc, idColorElegido) == 0)
		{
			printf("/n>La id ingresada no es valida! Intente nuevamente: \n");
			scanf("%d", &idColorElegido);
		}

		mostrarTipos(tipos, tam_tc);

		printf("\n\nIngrese el ID del tipo deseado: ");
		scanf("%d", &idTipoElegido);
		while(validarIdTipo(tipos, tam_tc, idTipoElegido) == 0)
		{
			printf("/n>La id ingresada no es valida! Intente nuevamente: \n");
			scanf("%d", &idTipoElegido);
		}

		for(int i=0;i<tam;i++)
		{
			if(mascotas[i].idColor == idColorElegido)
			{
				if(mascotas[i].idTipo == idTipoElegido)
				{
					contadorColorTipo++;
					flagColorTipo = 1;
				}
			}

		}
		if(flagColorTipo == 0)
		{
			printf(">No hay ninguna mascota de ese color y ese tipo\n\n");
		}

	}
	return contadorColorTipo;
}
