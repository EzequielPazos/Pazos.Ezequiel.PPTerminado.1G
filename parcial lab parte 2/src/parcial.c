/*
 ============================================================================
 Name        : parcial.c
 Author      : Pazos Ezequiel
 Version     : 1.1.0
 Curso       : 1ro G
 Description : PP Laboratorio 1
 ============================================================================
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

#define TAM 100
#define TAM_TC 5
#define TAM_S 3
#define TAM_C 5
#define ASC 1
#define DESC 0

char menuVeterinaria();

int main(void) {

	setbuf(stdout, NULL);

	char seguir = 's';
	char opcionDeseada;
	char confirmacion;
	int proximoIdMascota = 1;
	int proximoIdTrabajo = 1;
	int flagPrimerAlta = 0;
	int flagPrimerTrabajo = 0;
	int rta;
	int contadorMascotasColorTipo;
	eFecha unaFecha;
	eMascota listaMascotas[TAM];
	eTipo listaTipos[TAM_TC] =
	{
			{1000, "Ave"},
			{1001, "Perro"},
			{1002, "Gato"},
			{1003, "Roedor"},
			{1004, "Pez"}
	};
	eColor listaColores[TAM_TC] =
	{
			{5000, "Negro"},
			{5001, "Blanco"},
			{5002, "Gris"},
			{5003, "Rojo"},
			{5004, "Azul"}
	};
	eServicio listaServicios[TAM_S] =
	{
			{20000, "Corte", 250},
			{20001, "Desparasitado", 300},
			{20002, "Castrado", 400}
	};
	eTrabajo listaTrabajos[TAM];
	eCliente listaClientes[TAM_C] =
	{
			{30000, "Carlos", 'm'},
			{30001, "Roberto", 'm'},
			{30002, "Guillermo", 'm'},
			{30003, "Candela", 'f'},
			{30004, "Veronica", 'f'}
	};

	if(inicializarMascotas(listaMascotas ,TAM)== 0)
	{
		printf("> Mascotas inicializadas con exito!\n\n");
	}else
	{
		printf("> Problemas al inicializar las mascotas.\n\n");
	}

	if(inicializarTrabajos(listaTrabajos ,TAM)== 0)
	{
		printf("> Trabajos inicializadas con exito!\n\n");
	}else
	{
		printf("> Problemas al inicializar los trabajos.\n\n");
	}

	do{
		opcionDeseada = menuVeterinaria(); //Muestra menu de opciones

		switch(opcionDeseada)
		{
			case 'a': //alta mascota
	        	if(altaMascota(listaMascotas, listaTipos, listaColores, listaClientes, TAM, TAM_TC, TAM_C, proximoIdMascota) == 0)
				{
					proximoIdMascota++;
					printf("\n\n >>>Alta exitosa!<<<\n\n");
					flagPrimerAlta = 1;
				}else
				{
					printf("\n\n>>>Problemas para realizar el alta\n\n");
				}
				break;
			case 'b': //modificacion de mascotas
				if(flagPrimerAlta == 0)
				{
					printf("\n\n>>>No se puede modificar nada ya que todavia no se ha dado ningun alta!<<<\n\n");
				}else if(modificarMascota(listaMascotas, listaTipos, listaColores, listaClientes, TAM, TAM_TC, TAM_C) == 0)
				{
					printf("\n\n >>>Modificacion exitosa!<<<\n\n");
				}else
				{
					printf("\n\n >>>Se ha producido un error en la modificacion<<<\n\n");
				}
				break;
			case 'c': //baja mascota
				if(flagPrimerAlta == 0)
				{
					printf("\n\n>>>No se puede dar de baja ninguna mascota ya que todavia no se ha dado ninguna de alta!<<<\n\n");
				}else
				{
					rta = bajaMascota(listaMascotas, listaTipos, listaColores, listaClientes, TAM, TAM_TC, TAM_C);
					if(rta == 0)
					{
						printf("\n\n >>>Baja exitosa!<<<\n\n");
					}else if(rta == 2)
					{
						printf("\n\n >>>La baja se ha cancelado por el usuario<<< \n\n");
					}else
					{
						printf("\n\n >>>Se ha producido un error en la baja<<<\n\n");
					}
				}
				break;
			case 'd': //listar mascotas
				if(flagPrimerAlta == 0)
				{
					printf("\n\n>>>No se puede listar ninguna mascota ya que todavia no se ha dado ninguna de alta!<<<\n\n");
				}else
				{
					if(ordenarMascotasTipoNombre(listaMascotas, TAM, ASC, ASC)) //falta elegir asc o desc
					{
						printf("\n\n>>> Error al intentar ordenar los autos <<<\n\n");
					}else
					{
						printf("\n\n>>> Personas ordenadas con exito! <<<\n\n");
					}
					mostrarMascotas(listaMascotas, listaTipos, listaColores, listaClientes, TAM, TAM_TC, TAM_C);
				}
				break;
			case 'e': //listar tipos
				if(mostrarTipos(listaTipos, TAM_TC))
				{
					printf("\n\n>>> Error al intentar mostrar las marcas <<<\n\n");
				}else
				{
					printf("\n\n>>> Tipos mostradas con exito! <<<\n\n");
				}
				break;
			case 'f': //listar colores
				if(mostrarColores(listaColores, TAM_TC))
				{
					printf("\n\n>>> Error al intentar mostrar los colores <<<\n\n");
				}else
				{
					printf("\n\n>>> Colores mostrados con exito! <<<\n\n");
				}
				break;
			case 'g': //listar servicios
				if(mostrarServicios(listaServicios, TAM_S))
				{
					printf("\n\n>>> Error al intentar mostrar los servicios <<<\n\n");
				}else
				{
					printf("\n\n>>> Servicios mostrados con exito! <<<\n\n");
				}
				break;
			case 'h': //alta trabajo
				if(flagPrimerAlta == 0)
				{
					printf("\n\n>>>No se puede dar de alta ningun trabajo ya que todavia no se ha dado ninguna mascota de alta!<<<\n\n");
				}else
				{
					if(altaTrabajo(listaTrabajos, listaMascotas, listaServicios, listaTipos, listaColores, listaClientes, TAM, TAM_S, TAM_TC, TAM_C,proximoIdTrabajo) == 0)
					{
						proximoIdTrabajo++;
						printf("\n\n >>>Alta exitosa!<<<\n\n");
						flagPrimerTrabajo = 1;
					}else
					{
						printf("\n\n>>>Problemas para realizar el alta<<<\n\n");
					}
				}
				break;
			case 'i': //listar trabajos
				if(flagPrimerTrabajo == 0)
				{
					printf("\n\n>>>No se pueden listar los trabajos ya que todavia no se ha dado ninguno de alta!<<<\n\n");
				}else if(mostrarTrabajos(listaTrabajos, TAM))
				{
					printf("\n>>> Error al intentar mostrar los trabajos <<<\n\n");
				}else
				{
					printf("\n>>> Trabajos mostrados con exito! <<<\n\n");
				}
				break;
			case 'j': //informar mascotas por color
				if(flagPrimerAlta == 0)
				{
					printf("\n\n>>>No se puede informar nada ya que todavia no se ha dado ninguna de alta ninguna mascota!<<<\n\n");
				}else
				{
					if(mostrarMascotasColor(listaMascotas, listaColores, TAM, TAM_TC)==0)
					{
						printf("\n>>> Mascotas mostradas con exito! <<<\n\n");
					}else
					{
						printf("\n>>> Error al intentar mostrar las mascotas <<<\n\n");
					}
				}
				break;
			case 'k': //informar mascotas por tipo
				if(flagPrimerAlta == 0)
				{
					printf("\n\n>>>No se puede informar nada ya que todavia no se ha dado ninguna de alta ninguna mascota!<<<\n\n");
				}else
				{
					if(mostrarMascotasTipo(listaMascotas, listaTipos, TAM, TAM_TC)==0)
					{
						printf("\n>>> Mascotas mostradas con exito! <<<\n\n");
					}else
					{
						printf("\n>>> Error al intentar mostrar las mascotas <<<\n\n");
					}
				}
				break;
			case 'l': //informar mascotas menores
				if(flagPrimerAlta == 0)
				{
					printf("\n\n>>>No se puede informar nada ya que todavia no se ha dado ninguna de alta ninguna mascota!<<<\n\n");
				}else
				{
					if(mostrarMascotasMenores(listaMascotas, TAM)==0)
					{
						printf("\n>>> Mascotas mostradas con exito! <<<\n\n");
					}else
					{
						printf("\n>>> Error al intentar mostrar las mascotas <<<\n\n");
					}
				}
				break;
			case 'm': //listar mascotas por tipo
				if(flagPrimerAlta == 0)
				{
					printf("\n\n>>>No se puede listar ninguna mascota ya que todavia no se ha dado ninguna de alta!<<<\n\n");
				}else
				{
					if(ordenarMascotasTipo(listaMascotas, TAM, ASC)) //falta elegir asc o desc
					{
						printf("\n\n>>> Error al intentar ordenar las mascotas <<<\n\n");
					}else
					{
						printf("\n\n>>> Personas ordenadas con exito! <<<\n\n");
					}
					mostrarMascotas(listaMascotas, listaTipos, listaColores, listaClientes, TAM, TAM_TC, TAM_C);
				}
				break;
			case 'n':
				if(flagPrimerAlta == 0)
				{
					printf("\n\n>>>No se puede contar ninguna mascota ya que todavia no se ha dado ninguna de alta!<<<\n\n");
				}else
				{
					contadorMascotasColorTipo = contarMascotasColorTipo(listaMascotas, listaColores, listaTipos, TAM, TAM_TC);
					if(contadorMascotasColorTipo !=0)
					{
						printf("Hay %d mascotas de ese color y ese tipo en el sistema", contadorMascotasColorTipo);
					}
				}
				break;
			case 'o':
				if(flagPrimerAlta == 0)
				{
					printf("\n\n>>>No se puede contar ninguna mascota ya que todavia no se ha dado ninguna de alta!<<<\n\n");
				}else
				{
					if(coloresConMasMascotas(listaColores, listaMascotas, TAM_TC, TAM))
					{
						printf("\n\n>>> Error al intentar contar las mascotas <<<\n\n");
					}
				}
				break;
			case 'p':
				if(flagPrimerTrabajo == 0)
				{
					printf("\n\n>>>No se puede mostrar ningun trabajo ya que todavia no se ha dado ninguno de alta!<<<\n\n");
				}else
				{
					if(mostrarTrabajosMascota(listaTrabajos, listaMascotas, listaTipos, listaColores, listaClientes, TAM, TAM_TC, TAM_C))
					{
						printf("\n\n>>> Error al intentar mostrar los trabajos de esa mascota <<<\n\n");
					}else
					{
						printf("\n\n>>> Trabajos de la mascota mostrados con exito! <<<\n\n");
					}
				}
				break;
			case 'q':
				if(flagPrimerTrabajo == 0)
				{
					printf("\n\n>>>No se puede sumar ningun servicio ya que todavia no se ha dado ningun trabajo de alta!<<<\n\n");
				}else
				{
					if(sumaServiciosMascota(listaServicios, listaMascotas, listaTipos, listaColores, listaClientes, listaTrabajos, TAM_S, TAM, TAM_TC, TAM_C))
					{
						printf("\n\n>>> Error al intentar mostrar el total a pagar por los servicios de esa mascota <<<\n\n");
					}else
					{
						printf("\n\n>>> Total a pagar mostrado con exito! <<<\n\n");
					}
				}
				break;
			case 'r':
				if(flagPrimerTrabajo == 0)
				{
					printf("\n\n>>>No se puede mostrar ningun servicio realizado ya que todavia no se ha dado ningun trabajo de alta!<<<\n\n");
				}else
				{
					if(mascotasDeUnServicio(listaServicios, listaMascotas, listaTrabajos, TAM_S, TAM))
					{
						printf("\n\n>>> Error al intentar mostrar las mascotas que realizaron ese servicio <<<\n\n");
					}else
					{
						printf("\n\n>>> Mascotas mostradas con exito! <<<\n\n");
					}
				}
				break;
			case 's':
				if(flagPrimerTrabajo == 0)
				{
					printf("\n\n>>>No se puede mostrar ningun servicio realizado ya que todavia no se ha dado ningun trabajo de alta!<<<\n\n");
				}else
				{
					if(serviciosEnUnaFecha(unaFecha, listaTrabajos, TAM))
					{
						printf("\n\n>>> Error al intentar mostrar los servicios que se realizaron en esa fecha <<<\n\n");
					}else
					{
						printf("\n\n>>> Servicios mostrados con exito! <<<\n\n");
					}
				}
				break;
			case 'z': //salir
				printf("Confirma que quiere salir? Ingrese s/n\n"); //falta validar que lo que ingresa sea una letra
				fflush(stdin);
				scanf("%c", &confirmacion);
				confirmacion = tolower(confirmacion);
				while(confirmacion != 's' && confirmacion != 'n')
				{
					printf("La respuesta ingresada no es valida. Ingrese s/n\n");
					fflush(stdin);
					scanf("%c", &confirmacion);
					confirmacion = tolower(confirmacion);
				}
				if(confirmacion == 's')
				{
					seguir = 'n';
				}
				break;
			default: //validacion de las otra letras elegidas
				printf("\n>>> La opcion elegida es invalida! <<<\n");
				break;
		}

		system("pause");

	}while(seguir == 's');

	return EXIT_SUCCESS;
}

char menuVeterinaria()
{
	char opcion;

	system("cls");

	printf("========== VETERINARIA ==========\n\n");
	printf("A. ALTA MASCOTA\n");
	printf("B. MODIFICAR MASCOTA\n");
	printf("C. BAJA MASCOTA\n");
	printf("D. LISTAR MASCOTAS\n");
	printf("E. LISTAR TIPOS\n");
	printf("F. LISTAR COLORES\n");
	printf("G. LISTAR SERVICIOS\n");
	printf("H. ALTA TRABAJO\n");
	printf("I. LISTAR TRABAJOS\n");
	printf("J. INFORMAR MASCOTAS SEGUN COLOR\n");
	printf("K. INFORMAR MASCOTAS SEGUN TIPO\n");
	printf("L. INFORMAR MASCOTAS MENORES\n");
	printf("M. LISTAR MASCOTAS ORDENADAS POR SU TIPO\n");
	printf("N. INFORME DE CANTIDAD DE MASCOTAS DE UN COLOR Y TIPO\n");
	printf("O. INFORME DE COLOR CON MAS CANTIDAD DE MASCOTAS\n");
	printf("P. INFORME DE TRABAJOS DE UNA MASCOTA\n");
	printf("Q. INFORME DEL TOTAL A PAGAR SERVICIOS DE UNA MASCOTA\n");
	printf("R. INFORME DE MASCOTAS A LAS QUE SE LES REALIZO UN SERVICIO EN ESPECIFICO\n");
	printf("S. INFORME DE SERVICIOS REALIZADOS EN UN DIA EN ESPECIFICO\n");
	printf("Z. SALIR\n\n");
	printf("Ingrese la opcion deseada: ");
	fflush(stdin);
	opcion = tolower(getchar());

	return opcion;
}
