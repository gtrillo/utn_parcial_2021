#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Salon.h"
#include "Arcade.h"
#include "informes.h"
#include "utn_pedirCadena.h"
static void utn_subMenuModificar (Arcade* list [], int len);
static void utn_subMenuInformes (Salon listSalon[], int lenSalon, Arcade listArcade[], int lenArcade, int contadorSalones, int contadorArcades);
static void imprimirOpciones (void);

/** \brief funsion de menu
* \param lista listSalon*
* \param largo del array arcade
* \param listArcade
* \param largo del array salones
*/
void utn_menu (Salon* arraypsalones [], int lenSalon, Arcade* arrayparcades [], int lenArcade)
{
	Arcade* pAuxiliarArcade;
	Salon* pAuxiliarSalon;
	int opcion;
	int lugarLibre;
	int contadorSalones = 0;
	int contadorArcades = 0;
	int idEliminarSalon;
	int idEliminarArcade;
	int confirmacion;
	int auxiliar;
	do{
		if (utn_getNumeroInt(&opcion, "\nBienvenido \nUtilice el teclado numerico para elecionar una opcion:\n1)ALTA DE SALÓN\n2)ELIMINAR SALÓN\n3)IMPRIMIR SALONES\n4)INCORPORAR ARCADE\n5)MODIFICAR ARCADE\n6)ELIMINAR ARCADE\n7)IMPRIMIR ARCADES\n8)IMPRIMIR JUEGOS\n9)INFORMES\n", "\nA seleccionado una opcion Invalida", 1, 9, 100000)==0)
			{
			switch (opcion)
				{
					case 1:
							if (salon_dameUnLugarLibre(arraypsalones, lenSalon, &lugarLibre)==0)
								{
									pAuxiliarSalon = Salon_new();
									if (pAuxiliarSalon != NULL)
									{
										salon_addSalon(pAuxiliarSalon);
										arraypsalones[lugarLibre] = pAuxiliarSalon;
									}
									printf ("Salón dado de alta con exito.\n");
									salon_printSalones(arraypsalones, lenSalon);
									contadorSalones++;
								}
					break;
					case 2:
						if (contadorSalones > 0)
						{
							salon_printSalones(arraypsalones, lenSalon);
							if (utn_getNumeroInt(&idEliminarSalon, "\nIngrese el id del salon a eliminar:\n", "El id ingresado es invalido,intente nuevamente:\n", 0, 100, 5)==0)
							{
								if (salon_removeSalon(arraypsalones, lenSalon, arrayparcades, lenArcade, idEliminarSalon)==0)
								{
									printf ("El salon con ID: %d, ha sido dado de baja.", idEliminarSalon);
									contadorSalones--;
								}else
								{
									printf ("El ID ingresado no es valido");
								}
							}
						}
						else
						{
							printf ("No se podra ingresar a esta opcion sin antes tener salones cargados");
						}
					break;
					case 3:
						salon_printSalones(arraypsalones, lenSalon);
						/*if (contadorSalones > 0)
						{

						}
						else
						{
							printf ("No se podra ingresar a esta opcion sin antes tener salones cargados");
						}*/
					break;
					case 4:
						if (arcade_dameUnLugarLibre(arrayparcades, lenArcade, &lugarLibre)==0)
						{
							pAuxiliarArcade = arcade_new();
							if (pAuxiliarArcade != NULL)
							{
								arcade_addArcade(pAuxiliarArcade, arraypsalones);
								arrayparcades[lugarLibre] = pAuxiliarArcade;
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
							utn_subMenuModificar (arrayparcades, lenArcade);
						}
						else
						{
							printf ("No se puede ingresar a esta opcion sin antes haber dado de alta algun arcade");
						}
					break;
					case 7:
						arcade_printArcades(arrayparcades, lenArcade);
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
static void utn_subMenuModificar (Arcade* list [], int len)
{
	int IDaModificar;
	int posEncontrada;

		if (arcade_printArcades(list, len)==0)
		{
			if (utn_getNumeroInt(&IDaModificar, "\nIngrese ID de la maquina arcade que desea modificar: \nVolver al menu principal", "Error opcion incorrecta", 0, 1000, 5)==0)
			{
				if(arcade_buscarporId(list, len, IDaModificar, &posEncontrada)!=-1)
				{
					modificarArcade(list[posEncontrada], len);
					arcade_printArcades(list, len);
				}
				else
				{
					printf ("El ID ingresado es invalido.");
				}
			}
		}
}
