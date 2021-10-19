#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Salon.h"
#include "Arcade.h"
#include "informes.h"
#include "utn_pedirCadena.h"
#define ESTADO_LIBRE 1
#define ESTADO_OCUPADO 0
#define TIPO_SHOPPING 1
#define TIPO_LOCAL 2
#define LEN_CADENA 32
static int salon_dameUnIdNuevo(void);
/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int salon_initSalon(Salon* list, int len)
{
	int retorno;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			list[i].flagEmpty = ESTADO_LIBRE;
			retorno = 0;
		}
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}

int salon_addSalon(Salon list [])
{
	char nombre [LEN_LIST];
	char direccion [LEN_LIST];
	int tipo;
	int retorno;

	if (list != NULL)
	{
		if (utn_getText(nombre, LEN_LIST, "Ingrese nombre del salon:\n", "Error de tipeo, Intente nuevamente:\n", 5)==0)
		{
			if (utn_getTextAlfanumerico(direccion, LEN_LIST, "Ingrese direccion:\n", "Error de tipeo, Intente nuevamente:\n", 5)==0)
				{
					if (utn_getNumeroInt(&tipo, "Ingrese tipo de salon [1 SHOPPING - 2 LOCAL]:\n", "Error de tipeo, se debe ingresar [1 SHOPPING - 2 LOCAL]", 1, 2, 5)==0)
					{
							strncpy(list->nombre, nombre, sizeof (list->nombre));
							strncpy(list->direccion, direccion, sizeof (list->direccion));
							list->tipo = tipo;
							list->id = salon_dameUnIdNuevo();
							list ->flagEmpty = ESTADO_OCUPADO;
							retorno = 0;
					}
				}
		}
	}
	return retorno;
}

static int salon_dameUnIdNuevo(void)
{
	static int contador = 0;

	return contador++;
}

/**
 *\brief funsion que devuelve un lugar libre en el array
 *\param lista employe
 *\param largo de la lista
 *\param retorno de posicion libre
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
int salon_dameUnLugarLibre (Salon list[], int len, int* retornoPosicionLibre)
{
	int retorno;
	int indice;
	int auxLugarLibre;
	if (list != NULL && len > 0 && retornoPosicionLibre != NULL)
	{
		for (indice = 0; indice < len; indice++)
		{
			if (list[indice].flagEmpty == 1)
			{
				auxLugarLibre = indice;
				retorno = 0;
				break;
			}
		}
	}
	*retornoPosicionLibre = auxLugarLibre;
	return retorno;
}

int salon_printSalones(Salon* list, int len)
{
	int indice;
	int retorno = -1;
	char cadena [LEN_CADENA];
	if (list != NULL && list >= 0)
	{
	for (indice = 0; indice < len; indice++)
	{
		if (salon_tipoSalones(list, list[indice].tipo, cadena)==0)
		{
			if (list[indice].flagEmpty == ESTADO_OCUPADO)
			{
				printf ("\nID: %d - NOMBRE: %s - DIRECCION: %s - TIPO: %s", list[indice].id, list[indice].nombre, list[indice].direccion, cadena);
				retorno = 0;
			}
		}

	}
	}
	return retorno;
}

int salon_tipoSalones (Salon listSalones[], int tipo, char retornoTipo[])
{
	int retorno = -1;
	char cadena[LEN_CADENA];

	if (listSalones != NULL && tipo >-1)
	{
		switch(tipo)
			{
			case TIPO_SHOPPING:
				strncpy(cadena, "SHOPPING", LEN_CADENA);
				break;
			case TIPO_LOCAL:
				strncpy(cadena, "LOCAL", LEN_CADENA);
				break;
			}
		retorno = 0;
	}
	strncpy (retornoTipo,cadena,LEN_CADENA);
	return retorno;
}

int salon_buscarPorID(Salon* list, int len,int id)
{
	int retorno = -1;
	int indice;

	if (list != NULL && id >=0 && len >= 0)
	{
		for (indice = 0; indice < len; indice++)
		{
			if (id == list[indice].id && list[indice].flagEmpty == ESTADO_OCUPADO)
			{
				retorno = indice;
				break;
			}
		}
	}
	return retorno;
}



int salon_altaForzada (Salon* array, int limite, int indice, int id, char* nombre, char* direccion,int tipo)
{
	int retorno = -1;
	Salon bufferSalon;
	if (array != NULL && indice >= 0 && indice < limite)
	{
				strncpy(bufferSalon.nombre, nombre, sizeof (bufferSalon.nombre));
				strncpy(bufferSalon.direccion, direccion, sizeof (bufferSalon.direccion));
				bufferSalon.tipo = tipo;
				bufferSalon.id = id;
				bufferSalon.flagEmpty = 0;
				array[indice] = bufferSalon;
				(id)++;
				retorno = 0;
	}
	return retorno;

}