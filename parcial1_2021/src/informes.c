#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Salon.h"
#include "Arcade.h"
#include "informes.h"

#define ESTADO_LIBRE 1
#define ESTADO_OCUPADO 0
#define TIPO_SHOPPING 1
#define TIPO_LOCAL 2
#define	LEN_CADENA 32

/**
 *\brief funsion para dar de baja un salon utilizando la baja logica y cambiando
 *el estado de la posicion del array como libre
 *\param listSalon
 *\param largo del array de salones
 *\param listArcade
 *\param largo del array de arcades
 *\param id ingresado
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */

int salon_removeSalon(Salon* listSalon, int lenSalon, Arcade* listArcade, int lenArcade, int id)
{
		int retorno = -1;
		int indice;

		if (listSalon != NULL && lenSalon >0 && listArcade != NULL && lenArcade >0 && id >-1)
		{
			for (indice = 0; indice < lenSalon; indice++)
			{
				if (id == listSalon[indice].id && listSalon[indice].flagEmpty == ESTADO_OCUPADO)
				{
					listSalon[indice].flagEmpty = ESTADO_LIBRE;
					retorno = 0;
					for (indice = 0; indice < lenArcade; indice++)
						{
							if (id == listArcade[indice].idSalon && listArcade[indice].flagEmpty == ESTADO_OCUPADO)
							{
								listSalon[indice].flagEmpty = ESTADO_LIBRE;
								retorno = 0;
								break;
							}
							else
							{
								break;
							}
						}
				}
			}
		}
		return retorno;
}

/**
 *\brief funsion que informa los salones con mas de 4 arcades
 *\param listSalon
 *\param largo del array de salones
 *\param listArcade
 *\param largo del array de arcades
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
int informes_SalonConMas4Arcades (Arcade listArcades[], int lenArcades, Salon listSalones[], int lenSalones)
{

	int retorno = -1;
	int i;
	int j;
	int contador = 0;
	char cadena[LEN_CADENA];

	if(listArcades != NULL && lenArcades > 0 && listSalones != NULL && lenSalones > 0)
	{

		for(i = 0; i < lenSalones; i++)
		{
			if(listSalones[i].flagEmpty == ESTADO_OCUPADO)
			{
				contador = 0;

				for(j = 0; j < lenArcades; j++)
				{
					if(listArcades[j].flagEmpty == ESTADO_OCUPADO && listArcades[j].idSalon == listSalones[i].id)
					{
						contador++;
					}
				}

				if(contador > 4)
				{
					if (salon_tipoSalones(listSalones, listSalones[i].tipo, cadena)==0)
					{
						printf ("ID: %d - NOMBRE: %s - DIRECCIÓN: %s - TIPO: %s", listSalones[i].id, listSalones[i].nombre, listSalones[i].direccion, cadena);
					}

				}
			}

			}
		}

	return retorno;
}

/**
 *\brief funsion que informa los salones con mas de 4 arcades
 *\param listSalon
 *\param largo del array de salones
 *\param listArcade
 *\param largo del array de arcades
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
int informes_AParamasDe2Jugadores (Salon listSalones[], int lenSalones, Arcade listArcades[], int lenArcades)
{
	int retorno = -1;
	int i;
	int j;

	if (listSalones != NULL && lenSalones > 0 && listArcades != NULL && lenArcades >0)
	{
		for (i = 0; i < lenArcades; i++)
		{
			if (listArcades[i].cantidadJugadores > 2)
			{
				for (j = 0; j < lenSalones ; j++)
				{
					if (listArcades[i].idSalon == listSalones[j].id)
					{
						printf ("\nID: %d - CANTIDAD DE JUGADORES: %d - NOMBRE DEL JUEGO: %s - NOMBRE DEL SALON: %s", listArcades[i].id, listArcades[i].cantidadJugadores, listArcades[i].nombreDelJuego, listSalones[j].nombre);
						retorno = 0;
						break;
					}
				}
			}
		}
	}
	return retorno;
}

/**
 *\brief funsion que informa la cantidad de arcades que posee un salon
 *\param listArcades
 *\param largo del array de Arcades
 *\param idIngresado por el usuario
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
int informes_contadorArcades (Arcade listArcades[], int lenArcades, int idIngresado)
{
	int retorno = -1;
	int contadorArcades;
	int i;

	if(listArcades != NULL && lenArcades > 0 && idIngresado >=0)
	{
		for (i = 0; i< lenArcades; i++)
		{
			if (listArcades [i].flagEmpty == ESTADO_OCUPADO && idIngresado == listArcades[i].idSalon)
			{
				contadorArcades++;
				retorno = contadorArcades;
			}
		}
	}
	return retorno;
}

/**
 *\brief funsion que informa los salones con mas de 4 arcades
 *\param listSalon
 *\param largo del array de salones
 *\param listArcade
 *\param largo del array de arcades
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
int informes_ListaArcades (Arcade listArcades[], int lenArcades, Salon listSalones[], int lenSalones ,int idIngresado)
{
	int retorno = -1;
	int i;
	char cadena[LEN_CADENA];
	if (listArcades != NULL && lenArcades > 0 && idIngresado >=0)
	{
		switch(listSalones->tipo)
		{
			case TIPO_SHOPPING:
				strncpy(cadena, "SHOPPING", LEN_CADENA);
				break;
			case TIPO_LOCAL:
				strncpy(cadena, "LOCAL", LEN_CADENA);
				break;
		}
		printf ("\nID: %d - NOMBRE DEL JUEGO: %s - TIPO DE SALON: %s \nJUEGOS:", listSalones[idIngresado].id, listSalones[idIngresado].nombre, cadena);
		for (i = 0; i < lenArcades; i++)
		{
			if(listArcades[i].flagEmpty == ESTADO_OCUPADO &&idIngresado == listArcades[i].idSalon)
			{
				if (arcade_JuegosCargados(listArcades, lenArcades)==0)
				{
					printf ("\n%s",listArcades[i].nombreDelJuego);
					break;
				}
				retorno = 0;
			}
		}
	}
	return retorno;
}
/**
 *\brief funsion que informa el salon con mas cantidad de arcades
 *\param listSalon
 *\param largo del array de salones
 *\param listArcade
 *\param largo del array de arcades
 *\param puntero  al Id de la posicion que contiene el salon con mas cantidad de arcades
 *\param puntero a la direccion de memoria donde se copiara el resultado del contadorMaximo
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
int informes_SalonConMasArcades (Salon listSalones [], int lenSalones, Arcade listArcades [], int lenArcades, int* idMaximo, int* contadorMaximo)
{
	int i;
	int j;
	int contador = 0;
	int id;
	int contadorMax;
	int retorno = -1;
	int bandera = 1;
	if (listSalones != NULL && lenSalones > 0 && listArcades != NULL && lenArcades > 0)
	{
		for (i = 0; i < lenSalones; i++)
				{
					if (listSalones[i].flagEmpty == ESTADO_OCUPADO)
					{
						contador = 0;
						for (j = 0; j < lenArcades ; j++)
						{
							if (listArcades[j].flagEmpty == ESTADO_OCUPADO && listArcades[j].idSalon == listSalones[i].id)
							{
								contador++;
							}
						}
						if (bandera || contador > contadorMax)
						{
							contadorMax = contador;
							id = i;
							bandera = 0;
							retorno = 0;
						}
					}
				}
			*idMaximo = id;
			*contadorMaximo = contadorMax;
			}
	return retorno;
}
/**
 *\brief funsion que informa la recaudacion maxima diaria que puede hacer un arcade
 *\param listArcades
 *\param largo del array de arcades
 *\param listSalones
 *\param largo del array de salones
 *\param idIngresado por el usuario
 *\param precioIngresado por el usuario
 *\param puntero al espacio en memoria donde se guardara el resultado
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
int informes_recaudacionArcades (Arcade listArcades[], int lenArcades, int idIngresado,float precioIngresado, float* pResultado)
{
	int retorno = -1;
	int i;
	int acumuladorFichas = 0;;
	float recaudacion;

	if (listArcades != NULL && lenArcades >0 && idIngresado>=0 && precioIngresado > 0 && pResultado != NULL)
	{
		for (i = 0; i < lenArcades; i++)
		{
			if (listArcades[i].flagEmpty == ESTADO_OCUPADO && listArcades[i].idSalon == idIngresado)
			{
				acumuladorFichas += listArcades[i].capacidadFichas;
				retorno = 0;
			}
		}
	}
	recaudacion = (float)precioIngresado * acumuladorFichas;
	*pResultado = recaudacion;
	return retorno;
}
/**
 *\brief funsion que informa la cantidad de arcades que contienen un juego el cual es ingreado por consola por el usuario
 *\param listArcades
 *\param largo del array de arcades
 *\param texto ingresado por el usuario
 *\param puntero al espacio en memoria donde se guardara el resultado del contador
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
int contadorJuegos (Arcade list[], int len, char textoIngresado[], int* pContador)
{
	int retorno = -1;
	int i;
	int contador = 0;

	if (list != NULL && len > 0 && pContador != NULL)
	{
		for (i=0; i<len;i++)
		{
			if (list[i].flagEmpty == ESTADO_OCUPADO)
			{
				  strcpy(textoIngresado, list[i].nombreDelJuego);
				  strlwr(textoIngresado);
				if(strncmp(list[i].nombreDelJuego, textoIngresado,sizeof(list[i].nombreDelJuego))==0)
				{
					contador++;
					retorno = 0;
				}
			}
		}
	}
	*pContador = contador;
	return retorno;
}
