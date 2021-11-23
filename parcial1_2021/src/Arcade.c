#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Salon.h"
#include "Arcade.h"
#include "utn_pedirCadena.h"
#define ESTADO_LIBRE 1
#define ESTADO_OCUPADO 0
#define TIPO_MONO 1
#define TIPO_ESTEREO 2
#define LEN_ARCADE 1000
static int arcade_dameUnIdNuevo(void);
static int elegirOpcion (int* opcion);
static void imprimirOpciones (void);
static int modificarCantidadJugadores (int* pArray);
static int modificarNombreJuego (char array[]);

Arcade* arcade_new(void)
{
	Arcade* pArcade = (Arcade*)malloc(sizeof(Arcade));
	if(pArcade!=NULL)
	{
		pArcade->flagEmpty=ESTADO_OCUPADO;
	}
	return pArcade;
}
/**
 *\brief funcion para incializar el array de arcades
 *para eso pone todas las posiciones del array como libres
 *\param list
 *\param largo de la lista
 *\return retorna el indice en el caso de que este todo bien y -1 en caso de error
 */
int arcade_initArcade(Arcade* list[], int len)
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
/**
 *\brief funsion para añadir un nuevo arcade
 *\param list
 *\param largo de la lista
 *\return retorna el indice en el caso de que este todo bien y -1 en caso de error
 */
int arcade_addArcade(Arcade listArcades[], Salon* listSalones[])
{
	char nacionalidadAux [LEN_LIST];
	int tipoSonidoAux;
	int cantidadJugadoresAux;
	int capacidadFichasAux;
	int idIngresado;
	int posicionAllada;
	char NombreDelJuegoAux [LEN_NOMBREJUEGO];
	int retorno;

	if (listArcades != NULL && listSalones != NULL)
	{
		if (utn_getText(nacionalidadAux, LEN_LIST, "Ingrese nacionalidad del arcade:\n", "Error de tipeo, Intente nuevamente:\n", 5)==0)
			{
			if (utn_getNumeroInt(&tipoSonidoAux, "Ingrese tipo de sonido [1 MONO - 2 ESTÉREO]:\n", "Error de tipeo, se debe ingresar [1 MONO - 2 ESTÉREO]\n",1,2,5)==0)
				{
					if (utn_getNumeroInt(&cantidadJugadoresAux, "Ingrese cantidad de jugadores:\n", "Error de tipeo, Intente nuevamente:\n", 1, 100000, 5)==0)
					{
						if (utn_getNumeroInt(&capacidadFichasAux, "Ingrese capacidad maxima de fichas:\n", "Error de tipeo, Intente nuevamente:\n", 1, 100000, 5)==0)
						{
							utn_getNumeroInt(&idIngresado, "Ingrese el ID del salón al que pertenece:\n", "Error de tipeo, Intente nuevamente:\n", 0, 1000, 5);

							while (salon_buscarporId(listSalones, 100 , idIngresado, &posicionAllada)==-1)
							{
								utn_getNumeroInt(&idIngresado, "Error ingresaste in ID invalido!!!\n", "Error de tipeo, Intente nuevamente:\n", 0, 100, 5);
							}
								if (utn_getText(NombreDelJuegoAux, LEN_NOMBREJUEGO, "Ingrese nombre del juego que contiene:\n", "Error de tipeo, Intente nuevamente:\n", 5)==0)
								{
									strncpy(listArcades->nacionalidad, nacionalidadAux, sizeof (listArcades->nacionalidad));
									listArcades->tipoSonido = tipoSonidoAux;
									listArcades->cantidadJugadores = cantidadJugadoresAux;
									listArcades->capacidadFichas = capacidadFichasAux;
									strncpy(listArcades->nombreDelJuego, NombreDelJuegoAux, sizeof (listArcades->nombreDelJuego));
									listArcades->id = arcade_dameUnIdNuevo();
									listArcades->idSalon = idIngresado;
									listArcades ->flagEmpty = ESTADO_OCUPADO;
									retorno = 0;
								}
						}
					}
				}
			}
	}
	return retorno;
}
/** \brief funsion que devuelve un ID nuevo cada vez que se la invoca
*/
static int arcade_dameUnIdNuevo(void)
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
int arcade_dameUnLugarLibre (Arcade* list[], int len, int* retornoPosicionLibre)
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

int arcade_buscarArcadeDeSalon (Arcade* arrayArcades[], int listLen, int id, int* pPosicionEncontrada)
{
	int index;
	int status = -1;
	if (arrayArcades != NULL && listLen > 0 && id>=0)
	{
		status = 0;
		for (index = 0; index < listLen; index++)
		{
			if (arrayArcades[index]!=NULL)
			{
				if (arrayArcades[index]->idSalon == id)
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
 *\brief funsion para chequear que un id ingresado
 *por el usuario sea valido
 *\param list
 *\param largo de la lista
 *\param id ingresado
 *\return retorna el indice en el caso de que este todo bien y -1 en caso de error
 */
int arcade_buscarporId (Arcade* arrayArcades[], int listLen, int id, int* pPosicionEncontrada)
{
	int index;
	int status = -1;
	if (arrayArcades != NULL && listLen > 0 && id>=0)
	{
		for (index = 0; index < listLen; index++)
		{
			if (arrayArcades[index]!=NULL)
			{
				if (arrayArcades[index]->id == id)
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
 *\brief funsion para modificar un arcade
 *\param list
 *\param largo de la lista
 *\return retorna el indice en el caso de que este todo bien y -1 en caso de error
 */
int modificarArcade(Arcade* list,int len)
{
	int opcion;
	int retorno = -1;
	int cantidadJugadoresAux;
	char nombreDelJuegoAux[63];

	if (list != NULL)
	{
		if (elegirOpcion(&opcion) == 0)
		{
			retorno = 1;
			switch (opcion)
			{
				retorno = 0;
				case 1:
					if (modificarCantidadJugadores(&cantidadJugadoresAux) == 0)
					{
						list->cantidadJugadores = cantidadJugadoresAux;
					}
					break;
				case 2:
					printf ("Lista de juegos ya cargados");
					arcade_JuegosCargados(list, len);
					if (modificarNombreJuego(nombreDelJuegoAux) == 0)
					{
						strncpy(list->nombreDelJuego, nombreDelJuegoAux, 63);
					}
					break;
			}
		}
	}
	return retorno;
}
/**
 *\brief funsion seleccionar una opcion del submenu dentro de modificar
 *\param puntero al espacio en memoria de opcion
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
static int elegirOpcion (int* opcion)
{
	int retorno = -1;
	int auxOpcion;

	imprimirOpciones();
	if (utn_getNumeroInt(&auxOpcion,"\nUtilice el teclado numerico para seleccionar una opcion:\n","Error",1,2,2) == 0)
	{
		retorno = 0;
		*opcion = auxOpcion;
	}
	return retorno;
}

static void imprimirOpciones (void)
{
	printf ("\n¿Que campo desea modificar?");
	printf("\n1. Cantidad de jugadores");
	printf("\n2. juego que contiene");
}

/**
 *\brief funsion para modificar cantidad de jugadores
 *\param pArray
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
static int modificarCantidadJugadores (int* pArray)
{
	int retorno = -1;
	char mensaje[100];
	int auxCantidadJugadores;
	strncpy(mensaje, "\nIngrese cantidad de jugadores",sizeof(mensaje));
	if (utn_getNumeroInt(&auxCantidadJugadores, mensaje, "Error", 0, 10000, 2)== 0)
	{
		retorno = 0;
		*pArray = auxCantidadJugadores;
	}
	return retorno;
}
/**
 *\brief funsion para modificar el nombre de un juego
 *\param listArray
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
static int modificarNombreJuego (char array[])
{
	int retorno = -1;
	char mensaje[100];
	char auxNombreJuego[63];
	strncpy(mensaje, "\nIngrese el nombre del juego",sizeof(mensaje));
	if (utn_getText(auxNombreJuego, 63, mensaje, "Error",2) == 0)
	{
		retorno = 0;
		strncpy(array, auxNombreJuego, 63);
	}
	return retorno;
}
/**
 *\brief funsion que imprime todos los juegos cargados
 *\param list
 *\param largo de la lista
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
int arcade_JuegosCargados (Arcade* list[], int len)
{
	int retorno = -1;
	int j;
	int i;
	int flag;

		if (list != NULL)
		{
			retorno = 0;
			for (i=0; i < len; i++)
			{
				flag = -1;
				for (j=i+1; j<len;j++)
				{
					if (strcmp (list[i]->nombreDelJuego, list[j]->nombreDelJuego) == 0)
					{
						flag = 0;
					}
				}
				if (flag == -1)
				{
					printf ("\n%s",list[i]->nombreDelJuego);
				}
			}
		}
	return retorno;
}
/**
 *\brief funsion que imprime todos los arcades dados de alta
 *\param list
 *\param largo de la lista
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
int arcade_printArcades(Arcade* list[], int len)
{
	int indice;
	int retorno = -1;
	//char cadena [32];
	if (list != NULL && list >= 0)
	{
	for (indice = 0; indice < len; indice++)
	{
		/*switch(list[indice]->tipoSonido)
		{
			case TIPO_MONO:
				strncpy(cadena, "MONO", 32);
				break;
			case TIPO_ESTEREO:
				strncpy(cadena, "ESTÉREO", 32);
				break;
		}*/
		if (list[indice] != NULL)
		{
			printf ("\nID:%d - NACIONALIDAD: %s - TIPO DE SONIDO: %d - CANTIDAD DE JUGADORES: %d - CAPACIDAD MAXIMA DE FICHAS: %d - ID DEL SALON AL QUE PERTENECE: %d - JUEGO QUE CONTIENE: %s", list[indice]->id, list[indice]->nacionalidad, list[indice]->tipoSonido, list[indice]->cantidadJugadores, list[indice]->capacidadFichas, list[indice]->idSalon, list[indice]->nombreDelJuego);
			retorno = 0;
		}
	}
	}
	return retorno;
}
/**
 *\brief funsion para dar de baja un arcade a travez de la baja logica
 *la cual pone la posicion del array que se da de baja como ESTADO_LIBRE
 *\param list
 *\param largo de la lista
 *\param id del arcade que se quiere dar de baja
 *\return retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
int arcade_removeArcade(Arcade* list, int len, int id)
{
		int retorno = -1;
		int indice;

		for (indice = 0; indice < len; indice++)
		{
			if (id == list[indice].id && list[indice].flagEmpty == ESTADO_OCUPADO)
			{
				list[indice].flagEmpty = ESTADO_LIBRE;
				retorno = 0;
				break;
			}
		}
		return retorno;
}

int arcade_altaForzada (Arcade* array, int limite, int indice, int id, char* nombre, char* nacionalidad,int idSalon, int tipoSonido, int cantidadJugadores, int capacidadFichas)
{
	int retorno = -1;
	Arcade bufferArcade;
	if (array != NULL && indice >= 0 && indice < limite)
	{
				strncpy(bufferArcade.nacionalidad, nacionalidad, sizeof (bufferArcade.nacionalidad));
				bufferArcade.tipoSonido = tipoSonido;
				bufferArcade.cantidadJugadores = cantidadJugadores;
				bufferArcade.capacidadFichas = capacidadFichas;
				bufferArcade.idSalon = idSalon;
				strncpy(bufferArcade.nombreDelJuego, nombre, sizeof (bufferArcade.nombreDelJuego));
				bufferArcade.id = id;
				bufferArcade.flagEmpty = 0;
				array[indice] = bufferArcade;
				(id)++;
				retorno = 0;
	}
	return retorno;

}
