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


Salon* Salon_new(void)
{
	Salon* pSalon = (Salon*)malloc(sizeof(Salon));
	if(pSalon!=NULL)
	{
		pSalon->flagEmpty=ESTADO_OCUPADO;
	}
	return pSalon;
}


/** \brief funsion inicializar array de salones para eso pone todas las pocisiones en ESTADO_LIBRE
* \param list
* \param len int
* \return retorna 0 en caso de estar todo ok o -1 en caso de error
*/
int salon_initSalon(Salon* list[], int len)
{
	int retorno;
	int i;

	if (list != NULL && len > 0)
	{
			retorno = 0;
		for (i = 0; i < len; i++)
		{
			list[i] = NULL;
		}
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}
/** \brief funsion para añadir un nuevo salón
* \param list
* \return retorna 0 en caso de estar todo ok o -1 en caso de error
*/
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
/** \brief funsion que devuelve un ID nuevo cada vez que se la invoca
*/
static int salon_dameUnIdNuevo(void)
{
	static int contador = 0;

	return contador++;
}

/**
 *\brief funsion que devuelve un lugar libre en el array
 *\param list
 *\param largo de la lista
 *\param retorno de posicion libre
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
int salon_dameUnLugarLibre (Salon* list[], int len, int* retornoPosicionLibre)
{
	int retorno;
	int indice;
	int auxLugarLibre;
	if (list != NULL && len > 0 && retornoPosicionLibre != NULL)
	{
		for (indice = 0; indice < len; indice++)
		{
			if (list[indice] == NULL)
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
/**
 *\brief funsion que imprime todos los salones dados de alta
 *\param list
 *\param largo de la lista
 *\param retorno de posicion libre
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
int salon_printSalones(Salon* list[], int len)
{
	int indice;
	int retorno = -1;
	char cadena [LEN_CADENA];
	if (list != NULL && list >= 0)
	{
		for (indice = 0; indice < len; indice++)
		{
				if (list[indice] != NULL)
				{
					if (salon_tipoSalones(list, list[indice]->tipo, cadena)==0)
					{
						printf ("\nID: %d - NOMBRE: %s - DIRECCION: %s - TIPO %s", list[indice]->id, list[indice]->nombre, list[indice]->direccion, cadena);
						retorno = 0;
					}
				}
		}
	}
	return retorno;
}
/**
 *\brief funsion que imprime el tipo de salon
 *\param list
 *\param largo de la lista
 *\param retorno el tipo de salon en texto
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
int salon_tipoSalones (Salon* listSalones[], int tipo, char retornoTipo[])
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
/**
 *\brief funsion para chequear que un id ingresado
 *por el usuario sea valido
 *\param list
 *\param largo de la lista
 *\param id ingresado
 *\return retorna el indice en el caso de que este todo bien y -1 en caso de error
 */
int salon_buscarporId (Salon* arraySalones[], int listLen, int id, int* pPosicionEncontrada)
{
	int index;
	int status = -1;
	if (arraySalones != NULL && listLen > 0 && id>=0)
	{
		for (index = 0; index < listLen; index++)
		{
			if (arraySalones[index]!=NULL)
			{
				if (arraySalones[index]->id == id)
				{
					*pPosicionEncontrada = index;
					status = 1;
					break;
				}
			}
		}
	}
	return status;
}
/**
 *\brief funsion de alta forzada de salones
 *\param array
 *\param largo de la lista
 *\param indice
 *\param id
 *\param puntero nombre
 *\param puntero direccion
 *\param tipo
 *\return retorna el indice en el caso de que este todo bien y -1 en caso de error
 */

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
