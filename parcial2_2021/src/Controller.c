#include "Controller.h"
static int elergirOpcion (int* opcion);
static void imprimirOpciones (void);
static int modificarNombreJuego (char pNombre[]);
static int modificarCantidadJugadores (int* pCantidadJugadores);
int controller_dameUnIdNuevo(LinkedList* pArrayListEmployee);
static void controller_imprimirOpciones();
static int controller_subSort(void* primerNombre, void* segundoNombre);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListArcade)
{
	int retorno = -1;
	FILE* archivo = fopen (path, "r");
	if (archivo != NULL)
	{
		if (parser_ArcadeFromText(archivo, pArrayListArcade)==0)
		{
			retorno = 0;
		}else
		{
			printf ("\nerror al cargar el archivo de texto");
		}
		fclose(archivo);
	}
	return retorno;
}

/** \brief Alta de arcade
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_addArcade(LinkedList* pArrayListArcade)
{
	int	auxId = controller_dameUnIdNuevo(pArrayListArcade);
	char auxNacionalidad [LEN_NACIONALIDAD];
	int auxTipoSonido;
	int auxCantidadJugadores;
	int auxCapacidadFichas;
	char auxNombreSalon[LEN_SALON];
	char auxNombreJuego[LEN_JUEGO];
	Arcade* auxpArcade;
	int retorno = -1;
	if (pArrayListArcade != NULL)
	{
		if (utn_pedirTexto(auxNacionalidad, LEN_NACIONALIDAD, 5, "Ingrese nacionalidad del arcade:\n", "Error, caracter invalido.\n")==0)
		{
			if (utn_pedirInt(&auxTipoSonido, 0, 1, 5, "Ingrese tipo de sonido del arcade [0. MONO - 1. ESTEREO]:\n", "Error, caracter invalido.\n")==0)
			{
				if (utn_pedirInt(&auxCantidadJugadores, 0, 50, 5, "Ingrese cantidad jugadores:\n", "Error, intente nuevamente;\n")==0)
				{
					if (utn_pedirInt(&auxCapacidadFichas, 0, 1000, 5, "Ingrese capacidad maxima de fichas:\n", "Error, intente nuevamente;\n")==0)
					{
						if (utn_pedirTexto(auxNombreSalon, LEN_SALON, 5, "Ingrese nombre del salon al que pertenece el arcade:\n", "Error, caracter invalido.\n")==0)
						{
							if (utn_pedirTexto(auxNombreJuego, LEN_JUEGO, 5, "Ingrese nombre del juego que contiene el arcade:\n", "Error, caracter invalido.\n")==0)
							{
								auxpArcade = arcade_new();
								if (auxpArcade != NULL)
								{
									arcade_setId(auxpArcade,auxId);
									arcade_setNacionalidad(auxpArcade,auxNacionalidad);
									arcade_setTipoSonido(auxpArcade,auxTipoSonido);
									arcade_setCantidadJugadores(auxpArcade,auxCantidadJugadores);
									arcade_setCapacidadFichas(auxpArcade,auxCapacidadFichas);
									arcade_setNombreSalon(auxpArcade,auxNombreSalon);
									arcade_setNombreJuego(auxpArcade,auxNombreJuego);
									ll_add(pArrayListArcade, auxpArcade);
									retorno = 0;
								}
							}
						}
					}
				}
			}
		}
	}
    return retorno;
}

/** \brief Modificar datos del arcade
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editArcade(LinkedList* pArrayListArcade)
{
    int opcion;
    int idIngresado;
    int retornoId;
    int retorno = -1;
    char auxNombreJuego[LEN_JUEGO];
    int auxCantidadJugadores;
    Arcade* auxPListArcade;
    int largoLista = ll_len(pArrayListArcade);
    if (pArrayListArcade != NULL)
    {
    	if (utn_pedirInt(&idIngresado, 1, largoLista, 5, "\nIngrese id del arcade a modificar:\n", "Error, intente nuevamente:\n")==0)
    	{
    		if (controller_findById (pArrayListArcade, idIngresado, &retornoId)==0)
    		{
    			auxPListArcade = ll_get(pArrayListArcade, retornoId);
    			if (elergirOpcion(&opcion)==0)
					{
						retorno = 1;
						switch (opcion)
						{
							retorno = 0;
						case 1:
							if (modificarCantidadJugadores(&auxCantidadJugadores)==0)
							{
								arcade_setCantidadJugadores(auxPListArcade, auxCantidadJugadores);
							}
							break;
						case 2:
							if (modificarNombreJuego(auxNombreJuego)==0)
							{
								arcade_setNombreJuego(auxPListArcade, auxNombreJuego);
							}
							break;
						}
					}
				}

    	}
  }
	return retorno;
}
static int elergirOpcion (int* opcion)
{
	int retorno = -1;
	int auxiliarOpcion;
	imprimirOpciones();
	if (utn_pedirInt(&auxiliarOpcion, 1, 2, 5, "\ningrese una opcion:\n", "opcion invalida, intente nuevamente:\n")==0)
	{
		 *opcion = auxiliarOpcion;
		 retorno = 0;
	}
	return retorno;
}

static void imprimirOpciones (void)
{
	printf ("\n¿Que campo desea modificar?");
	printf ("\n1.Cantidad maxima de jugadores");
	printf ("\n2.nombre del juego que contiene");
}

static int modificarNombreJuego (char pNombre[])
{
	int retorno = -1;
	char mensaje[100];
	char auxNombre[LEN_JUEGO];
	strncpy(mensaje, "\nnombre del juego",sizeof(mensaje));
	if (utn_pedirTexto(auxNombre, LEN_JUEGO, 5, "ingrese el nombre del juego:\n", "Error, intente nuevamente:\n") == 0)
	{
		retorno = 0;
		strncpy(pNombre, auxNombre, LEN_JUEGO);
	}
	return retorno;
}

static int modificarCantidadJugadores (int* pCantidadJugadores)
{
	int retorno = -1;
	char mensaje[100];
	int auxCantidadJugadores;
	strncpy(mensaje, "\nIngrese cantidad maxima de jugadores:\n",sizeof(mensaje));
	if (utn_pedirInt(&auxCantidadJugadores, 1, 50, 5, "ingrese cantidad de jugadores:\n", "Error, intente nuevamente:\n")== 0)
	{
		retorno = 0;
		*pCantidadJugadores = auxCantidadJugadores;
	}
	return retorno;
}
/** \brief Baja de arcade
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_removeArcade(LinkedList* pArrayListArcade)
{
    int retorno;
    int IDIngresado;
    int retornoId;
    int validacion;
    int lenll = ll_len(pArrayListArcade);
   if (pArrayListArcade!= NULL)
   {
	   if(utn_pedirInt(&IDIngresado, 0, lenll, 5, "\nIngrese ID del arcade que desea dar de baja:\n", "Error, intente nuevamente:\n")==0)
	   {
		   if (controller_findById(pArrayListArcade, IDIngresado, &retornoId)==0)
		   {
			   printf ("\nEsta seguro que desea dar de baja el arcade con ID: %d", IDIngresado);
			   if (utn_pedirInt(&validacion, 0, 1, 5, "\nPrecione 0 para confirmar o 1 para cancelar la baja:\n", "\Error intente nuevamente:\n")==0)
			   {
				   if (validacion==0)
				   {
					   ll_get(pArrayListArcade, retornoId);
					   arcade_delete(pArrayListArcade, retornoId);
					   retorno = 0;
				   }else
				   {
					   puts ("Se ha cancelado la baja");
				   }
			   }
		   }
	   }
   }
    return retorno;
}

/** \brief Listar arcades
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int controller_ListArcade(LinkedList* pArrayListGame)
{
	int retorno = -1;
	int i;
	Arcade* auxiliar;
	int auxId;
	  if(pArrayListGame != NULL && ll_len(pArrayListGame) > 0)
	    {
	    	for(i = 0; i < ll_len(pArrayListGame); i++)
			{
				auxiliar = ll_get(pArrayListGame, i);
				if(auxiliar != NULL)
				{
					if(arcade_getId(auxiliar, &auxId) == 0)
					   {
						controller_printArcade(pArrayListGame, auxId);
					   }
				}
			}
	    }
    return retorno;
}

int controller_findById(LinkedList* pArray,int id, int* indiceDeId)
{
	int retorno=-1;
	Arcade *pAux;
	int idAux;

	if(pArray!=NULL&&indiceDeId!=NULL)
	{
		for(int i=0;i<ll_len(pArray);i++)
		{
			pAux=ll_get(pArray, i);
			if(pAux!=NULL)
			{
				arcade_getId(pAux, &idAux);
				if(idAux==id)
				{
					*indiceDeId=i;
					retorno=0;
					break;
				}
			}
		}
	}
	return retorno;
}


int controller_printArcade (LinkedList* pArrayListArcade, int id)
{
	int retorno;
	int retornoId;
	char auxNacionalidad [LEN_NACIONALIDAD];
	int auxTipoSonido;
	char auxTipoSonidoChar [128];
	int auxCantidadJugadores;
	int auxCapacidadFichas;
	char auxNombreSalon[LEN_SALON];
	char auxNombreJuego[LEN_JUEGO];
    Arcade* auxiliarArcade;

	if (pArrayListArcade != NULL && id >=0 && ll_len(pArrayListArcade)>0)
	{
		if(controller_findById(pArrayListArcade, id, &retornoId)==0)
		{
			if (retornoId != -1)
			{
				auxiliarArcade = ll_get(pArrayListArcade, retornoId);
				if (auxiliarArcade != NULL)
				{
					arcade_getTipoSonido(auxiliarArcade,&auxTipoSonido);
					switch(auxTipoSonido)
					{
					case 0:
						sprintf (auxTipoSonidoChar, "%d", auxTipoSonido);
						strncpy(auxTipoSonidoChar, "MONO", 32);
						break;
					case 1:
						sprintf (auxTipoSonidoChar, "%d", auxTipoSonido);
						strncpy(auxTipoSonidoChar, "ESTÉREO", 32);
						break;
					}
					arcade_getId(auxiliarArcade, &retornoId);
					arcade_getNacionalidad(auxiliarArcade,auxNacionalidad);
					arcade_getCantidadJugadores(auxiliarArcade,&auxCantidadJugadores);
					arcade_getCapacidadFichas(auxiliarArcade,&auxCapacidadFichas);
					arcade_getNombreSalon(auxiliarArcade,auxNombreSalon);
					arcade_getNombreJuego(auxiliarArcade,auxNombreJuego);
					printf("\nID: %d| NACIONALIDAD: %s| TIPO : %s| CANTIDAD JUGADORES: %d| CAPACIDAD DE FICHAS: %d| NOMBRE DEL SALON: %s| NOMBRE DEL JUEGO: %s|", retornoId, auxNacionalidad, auxTipoSonidoChar, auxCantidadJugadores,auxCapacidadFichas,auxNombreSalon,auxNombreJuego);
					retorno = 0;
				}
		}
		}
	}
	return retorno;
}
/** \brief Genera un numero id nuevo.
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_dameUnIdNuevo(LinkedList* pArrayListArcade)
{
	    int retorno = -1;
	    int i;
	    int idAux;
	    int idMax=0;
	    Arcade *pAux;
	    if(pArrayListArcade != NULL)
	    {
	        for(i=0;i<ll_len(pArrayListArcade);i++)
	        {
	            pAux = ll_get(pArrayListArcade, i);
	            if(i == 0)
	            {
	                arcade_getId(pAux, &idMax);
	            }
	            else
	            {
	                arcade_getId(pAux, &idAux);
	                if(idAux > idMax)
	                {
	                    idMax = idAux;
	                }
	            }
	        }
	        retorno = idMax+1;
	    }
	    return retorno;

}
int controller_sortArcade(LinkedList* pArrayListArcade)
{
	int opcion;
	int retorno = -1;

	if (pArrayListArcade != NULL && ll_len(pArrayListArcade)>0)
	{
		controller_imprimirOpciones();
		if (utn_pedirInt(&opcion, 0, 1, 5, "opcion:\n", "Error. opcion:\n")==0)
		{
			retorno = ll_sort(pArrayListArcade, controller_subSort, opcion);
		}
	}

	return retorno;
}

static void controller_imprimirOpciones()
{
	printf ("\nIngrese 0 o 1:");
	printf ("\n0-ordenar nombre de manera descendente:\n");
	printf ("\n1-ordenar nombre de manera ascendente:\n");
}

static int controller_subSort(void* primerJuego, void* segundoJuego)
{
	int retorno;
	char auxPrimerNombre [LEN_JUEGO];
	char auxSegundoNombre [LEN_JUEGO];
	Arcade* primero = (Arcade*) primerJuego;
	Arcade* segundo = (Arcade*) segundoJuego;

	if (arcade_getNombreJuego(primero, auxPrimerNombre) != -1 && arcade_getNombreJuego(segundo, auxSegundoNombre)!= -1)
	{
		retorno = strcmp (auxPrimerNombre, auxSegundoNombre);
	}


	return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListArcade)
{
	int retorno = -1;
	Arcade* auxpArcade;
	FILE* archivo = fopen (path, "wb");
	char auxNacionalidad [LEN_NACIONALIDAD];
	int idAux;
	int auxTipoSonido;
	int auxCantidadJugadores;
	int auxCapacidadFichas;
	char auxNombreSalon[LEN_SALON];
	char auxNombreJuego[LEN_JUEGO];
	int i;
	if (path != NULL && pArrayListArcade != NULL && archivo != NULL)
	{
		fprintf(archivo,"ID, Nacionalidad, Tipo sonido, Cantidad jugadores, Capacidad fichas, Salon, Juego \n");
		for (i = 0; i < ll_len(pArrayListArcade); i++)
		{
			auxpArcade = ll_get(pArrayListArcade, i);
			if (auxpArcade != NULL)
			{
				retorno = 0;
				arcade_getId(auxpArcade,&idAux);
				arcade_getNacionalidad(auxpArcade, auxNacionalidad);
				arcade_getTipoSonido(auxpArcade,&auxTipoSonido);
				arcade_getCantidadJugadores(auxpArcade,&auxCantidadJugadores);
				arcade_getCapacidadFichas(auxpArcade,&auxCapacidadFichas);
				arcade_getNombreSalon(auxpArcade, auxNombreSalon);
				arcade_getNombreJuego(auxpArcade, auxNombreJuego);
				fprintf(archivo,"%d,%s,%d,%d,%d,%s,%s\n",idAux,auxNacionalidad,auxTipoSonido,auxCantidadJugadores,auxCapacidadFichas,auxNombreSalon,auxNombreJuego);
			}
		}
		fclose(archivo);
	}
	return retorno;
}

int controller_saveAsTextGames(char* path , LinkedList* this)
{
    FILE* archivo;
    Arcade* auxpGame;
    Arcade* auxpGame2;
    int i;
    int retorno = -1;
    char gameName[LEN_JUEGO];
    archivo = fopen(path, "w");
    if(archivo != NULL && this != NULL)
    {
    	ll_sort(this, controller_subSort, 0);
    	fprintf(archivo,"Juego \n");
		for (i = 0; i < ll_len(this) -1; i++)
		{
			auxpGame = ll_get(this, i);
			auxpGame2 = ll_get(this, i + 1);
			if (auxpGame != NULL && auxpGame2 != NULL)
			{
				if (strnicmp (auxpGame->nombreJuego, auxpGame2->nombreJuego, LEN_JUEGO)!=0)
				{
					if (arcade_getNombreJuego(auxpGame, gameName)==0)
					{
						fprintf(archivo,"%s\n",gameName);
					}
				}
			}
	retorno = 0;
		}
    }
    fclose(archivo);
    return retorno;
}

int controller_subSortID(void* primerId, void* SegundoId)
{
	int retorno;
	int auxPrimerID;
	int auxSegundoID;
	Arcade* primero = (Arcade*) primerId;
	Arcade* segundo = (Arcade*) SegundoId;

	if (arcade_getId(primero, &auxPrimerID) != -1 && arcade_getId(segundo, &auxSegundoID)!= -1)
	{
		if (auxPrimerID == auxSegundoID)
		{
			retorno = 0;
		}else if (auxPrimerID > auxSegundoID)
		{
			retorno = 1;
		}else
		{
			retorno = -1;
		}
	}


	return retorno;
}
