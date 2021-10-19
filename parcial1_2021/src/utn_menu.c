#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Salon.h"
#include "Arcade.h"
#include "informes.h"
#include "utn_pedirCadena.h"
static void utn_subMenuModificar (Arcade list [], int len);
static void utn_subMenuInformes (Salon listSalon[], int lenSalon, Arcade listArcade[], int lenArcade);
static void imprimirOpciones (void);
/** \brief funsion de menu
* \param lista Employee*
* \param largo del array
*
*/
void utn_menu (Salon listSalon [], int lenSalon, Arcade listArcade [], int lenArcade)
{
	int opcion;
	int lugarLibre;
	int contadorSalones = 0;
	int contadorArcades = 0;
	int idEliminarSalon;
	int idEliminarArcade;
	int confirmacion;
	int auxiliar;
	do{
		if (utn_getNumeroInt(&opcion, "\nBienvenido \nUtilice el teclado numerico para elecionar una opcion:\n1)ALTA DE SAL�N\n2)ELIMINAR SAL�N\n3)IMPRIMIR SALONES\n4)INCORPORAR ARCADE\n5)MODIFICAR ARCADE\n6)ELIMINAR ARCADE\n7)IMPRIMIR ARCADES\n8)IMPRIMIR JUEGOS\n9)INFORMES\n", "\nA seleccionado una opcion Invalida", 1, 9, 100000)==0)
			{
			switch (opcion)
				{
					case 1:
						if (contadorSalones <  lenSalon)
						{
							if (salon_dameUnLugarLibre(listSalon, lenSalon, &lugarLibre)==0)
								{
									salon_addSalon(&listSalon[lugarLibre]);
									printf ("Sal�n dado de alta con exito.");
									salon_printSalones(listSalon, lenSalon);
									contadorSalones++;
								}
						}
						else
						{
							printf ("Limite de salones creados.");
						}
					break;
					case 2:
						if (contadorSalones > 0)
						{
							salon_printSalones(listSalon, lenSalon);
							if (utn_getNumeroInt(&idEliminarSalon, "\nIngrese el id del salon a eliminar:\n", "El id ingresado es invalido,intente nuevamente:\n", 0, 100, 5)==0)
							{
								if (salon_removeSalon(listSalon, lenSalon, listArcade, lenArcade, idEliminarSalon)!=-1)
								{
									printf ("El salon con ID: %d, ha sido dado de baja.", idEliminarSalon);
									contadorSalones--;
								}
							}
						}
						else
						{
							printf ("No se podra ingresar a esta opcion sin antes tener salones cargados");
						}
					break;
					case 3:
						if (contadorSalones > 0)
						{
							salon_printSalones(listSalon, lenSalon);
						}
						else
						{
							printf ("No se podra ingresar a esta opcion sin antes tener salones cargados");
						}
					break;
					case 4:
						if (contadorSalones > 0)
						{
							if (arcade_dameUnLugarLibre(listArcade, lenArcade, &lugarLibre)==0)
							{
								arcade_addArcade(&listArcade[lugarLibre], listSalon);
								contadorArcades++;
							}
						}
						else
						{
							printf ("No se puede dar de alta un arcade sin antes haber dado de alta un salon");
						}
					break;
					case 5:
						if (contadorArcades > 0)
						{
							utn_subMenuModificar (listArcade, lenArcade);
						}
						else
						{
							printf ("No se puede ingresar a esta opcion sin antes haber dado de alta algun arcade");
						}
					break;
					case 6:
						if (contadorArcades > 0)
						{
							arcade_printArcades(listArcade, lenArcade);
							if (utn_getNumeroInt(&idEliminarArcade, "\nIngrese el ID del salon a eliminar:\n", "El ID ingresado no es valido", 0,1000, 5)==0)
							{
								auxiliar = arcade_buscarPorID(listArcade, lenArcade, idEliminarArcade);
								if (auxiliar != -1)
								{
									printf ("esta seguro que desea dar de baja el arcade con ID: %d\n", idEliminarArcade);
									if(utn_getNumeroInt(&confirmacion, "Ingrese 0 para confirmar y para 1 cancelar", "Error intente nuevamente", 0, 1, 3)==0)
									{
										if (arcade_removeArcade(listArcade, lenArcade, idEliminarArcade)==0)
										{
											printf ("El arcade con ID: %d, ha sido dado de baja.", idEliminarArcade);
											contadorArcades--;
										}
										else
										{
											printf ("accion cancelada");
										}
									}
								}
							}
						}

							else
							{
								printf ("No se pueden dar de baja un arcade sin antes tener cargado alguno en el sistema");
							}
					break;
					case 7:
						if (contadorArcades > 0)
						{
							arcade_printArcades(listArcade, lenArcade);
						}
						else
						{
							printf ("no se puede ingresar a esta opcion sin antes haber dado de alta algun arcade");
						}
					break;
					case 8:
						if (contadorArcades > 0)
						{
							printf ("Lista de juegos:");
							arcade_JuegosCargados(listArcade, lenArcade);
						}
						else
						{
							printf ("No se puede ingresar a esta opcion sin antes haber dado de alta algun arcade");
						}
					break;
					case 9:

						if (contadorArcades > 0 && contadorSalones >0)
						{
							utn_subMenuInformes(listSalon, lenSalon, listArcade, lenArcade);
						}
						else
						{
							printf ("No se puede ingresar a esta opcion sin antes tener cargados al menos 1 salon y un arcade");
						}
					break;
				}
			}
	}while (opcion <10);

}
/** \brief funsion de submenu donde se encuentra la opcion modificar
*
* \param lista Employee*
* \param largo del array
*
*/
static void utn_subMenuModificar (Arcade list [], int len)
{
	int IDaModificar;

		if (arcade_printArcades(list, len)==0)
		{
			if (utn_getNumeroInt(&IDaModificar, "\nIngrese ID de la maquina arcade que desea modificar: \nVolver al menu principal", "Error opcion incorrecta", 0, 1000, 5)==0)
			{
				if(arcade_buscarPorID(list, len, IDaModificar)!=-1)
				{
					modificarArcade(&list[IDaModificar], len);
					arcade_printArcades(list, len);
				}
				else
				{
					printf ("El ID ingresado es invalido.");
				}
			}
		}
}

static void utn_subMenuInformes (Salon listSalon[], int lenSalon, Arcade listArcade[], int lenArcade)
{
	int opcionElegida;
	int idIngresado;
	int idIngresadoListarSalon;
	int cantidadArcades;
	int retornoContMax;
	int retornoIdMax;
	int retornoContador;
	float valorFicha;
	float retornoRecaudacion;
	char textoIngresado[63];
	imprimirOpciones();
	if (utn_getNumeroInt(&opcionElegida, "\nSeleccione una opcion\n", "\nError. intente nuevamente\n", 1,7,3)==0)
	{
			switch (opcionElegida)
			{
				case 1:
					informes_SalonConMas4Arcades(listArcade, lenArcade, listSalon, lenSalon);
					break;
				case 2:
					informes_AParamasDe2Jugadores(listSalon, lenSalon, listArcade, lenArcade);
					break;
				case 3:
					salon_printSalones(listSalon, lenSalon);
					if (utn_getNumeroInt(&idIngresado, "\nIngrese ID:\n", "Error el ID ingresado no es valido\n", 0, lenSalon, 3)==0)
					{
						if(salon_buscarPorID(listSalon, lenSalon, idIngresado)!=-1)
						{
							cantidadArcades = informes_contadorArcades(listArcade, lenArcade, idIngresado);
							printf ("%d",cantidadArcades);
							if (cantidadArcades != -1)
							{
								printf ("\nID: %d - NOMBRE: %s - DIRECCION: %s - CANTIDAD DE ARCADES QUE POSEE: %d", listSalon[idIngresado].id, listSalon[idIngresado].nombre, listSalon[idIngresado].direccion, cantidadArcades);
							}
						}
					}
					break;
				case 4:
					salon_printSalones(listSalon, lenSalon);
					if (utn_getNumeroInt(&idIngresadoListarSalon, "\nIngrese ID del salon:\n", "Error Intente nuevamente\n", 0, lenSalon, 3)==0)
					{
						informes_ListaArcades(listArcade, lenArcade, listSalon, lenSalon, idIngresadoListarSalon);
					}
					break;
				case 5:
					if (informes_SalonConMasArcades(listSalon, lenSalon, listArcade, lenArcade, &retornoIdMax, &retornoContMax)==0)
					{
						printf ("ID: %d - NOMBRE: %s - DIRECCION: %s - CANTIDAD DE ARCADES QUE POSEE: %d", listSalon[retornoIdMax].id, listSalon[retornoIdMax].nombre, listSalon[retornoIdMax].direccion, retornoContMax);
					}
					break;
				case 6:
					if (utn_getNumeroInt(&idIngresado, "Ingrese el id de un salon:\n", "El id ingresado no es valido, intente nuevamente:\n", 0, lenSalon, 3)==0)
					{
						if (salon_buscarPorID(listSalon, LEN_LIST, 0)!=-1)
						{
							if (utn_getNumeroFloat(&valorFicha, "Ingrese el valor en pesos de una ficha:\n", "Error intente nuevamente:\n", 0, 9999999, 3)==0)
							{
								if (informes_recaudacionArcades(listArcade, lenArcade, idIngresado, valorFicha, &retornoRecaudacion)==0)
								{
									printf ("monto maximo de recaudacion de un local %.2f", retornoRecaudacion);
								}
							}
						}
						else
						{
							printf ("El ID ingresado es invalido");
						}
					}
					break;
				case 7:
					if (utn_getText(textoIngresado, 63, "Ingrese nombre del juego:\n", "Error. el nombre es invalido\n", 5)==0)
					{
						if (contadorJuegos (listArcade, lenArcade, textoIngresado, &retornoContador)==0)
							{
								printf ("cantidad de arcades que contiene el juego: %d", retornoContador);
							}
						else
							{
								printf ("el juego ingresado no corresponde con un juego cargado en la base de datos");
							}
					}
					break;
			}
	}
}
static void imprimirOpciones (void)
{
	printf ("INFORMES");
	printf ("\n1) Listar los salones con m�s de 4 arcades. Indicando ID de sal�n, nombre, direcci�n y tipo de sal�n.");
	printf("\n2) Listar los arcades para m�s de 2 jugadores, indicando ID de arcade, cantidad de jugadores, nombre del juego y nombre del sal�n al que pertenece.");
	printf("\n3) Listar toda la informaci�n de un sal�n en espec�fico ingresando su ID. Imprimir nombre, tipo y direcci�n y cantidad de arcades que posee.");
	printf ("\n4) Listar todos los arcades de un sal�n determinado ingresando su ID. Informar nombre y tipo de sal�n, listar todos los arcades con sus datos junto con el nombre del juego que lo compone.");
	printf("\n5) Imprimir el sal�n con m�s cantidad de arcades, indicando todos los datos del sal�n y la cantidad de arcades que posee.");
	printf("\n6) Ingresar el ID de un sal�n, y el valor en pesos de una ficha, e imprimir el monto m�ximo en pesos que puede recaudar el sal�n (sumar cantidad de fichas m�ximo de cada arcade del sal�n y multiplicarla por el valor en pesos ingresado)");
	printf ("\n7) Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen.");

}

