#include "Arcade.h"


Arcade* arcade_new()
{
		Arcade* pEmployee = (Arcade*)malloc(sizeof(Arcade));
		return pEmployee;
}

Arcade* arcade_newParametros(char* idStr,char* nacionalidadStr,char* tipoSonidoStr, char* CantidadJugadoresStr, char* capacidadFichasStr, char* nombreSalonStr, char* nombreJuegoStr)
{
	Arcade* pArcade = NULL;
	pArcade = arcade_new();
	if (pArcade != NULL && idStr  != NULL && nacionalidadStr != NULL  && tipoSonidoStr != NULL && CantidadJugadoresStr != NULL && capacidadFichasStr != NULL && nombreSalonStr != NULL && nombreJuegoStr != NULL)
	{
		arcade_setId(pArcade,atoi(idStr));
		arcade_setNacionalidad(pArcade, nacionalidadStr);
		arcade_setTipoSonido(pArcade, atoi(tipoSonidoStr));
		arcade_setCantidadJugadores(pArcade, atoi(CantidadJugadoresStr));
		arcade_setCapacidadFichas(pArcade, atoi(capacidadFichasStr));
		arcade_setNombreSalon(pArcade, nombreSalonStr);
		arcade_setNombreJuego(pArcade, nombreJuegoStr);

	}
		return pArcade;
}

int arcade_setId(Arcade* this,int id)
{
	int retorno = -1;
	char aux [LENID];

	sprintf (aux, "%d", id);
	if (this != NULL && id >=0)
	{
		if (validarEntero(aux)==0)
		{
			retorno = 0;
			this->id = id;
		}
	}
	return retorno;
}

int arcade_getId(Arcade* this,int* id)
{
	int retorno = -1;
	if (this != NULL && id >= 0)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int arcade_setNacionalidad(Arcade* this,char* nacionalidad)
{
	int retorno;
	if (this != NULL && nacionalidad != NULL)
	{
		if (esNombre(nacionalidad)==0)
		{
			retorno = 0;
			strncpy (this->nacionalidad, nacionalidad, LEN_NACIONALIDAD);
		}
	}
	return retorno;
}

int arcade_getNacionalidad(Arcade* this,char* nacionalidad)
{
	int retorno;
	if (this != NULL && nacionalidad != NULL)
	{
			retorno = 0;
			strncpy (nacionalidad, this->nacionalidad, LEN_NACIONALIDAD);
	}
	return retorno;
}

int arcade_setTipoSonido(Arcade* this,int tipoSonido)
{
	int retorno = -1;
	char aux [25];

		sprintf (aux, "%d", tipoSonido);

		if (this != NULL && tipoSonido >=0)
		{
			if (validarEntero(aux)==0)
			{
				retorno = 0;
				this->tipoSonido = atoi (aux);
			}

		}
		return retorno;
}

int arcade_getTipoSonido(Arcade* this,int* tipoSonido)
{
	int retorno = -1;
		if (this != NULL && tipoSonido != NULL)
		{
			retorno = 0;
			*tipoSonido = this -> tipoSonido;
		}
		return retorno;
}

int arcade_setCantidadJugadores(Arcade* this,int cantidadJugadores)
{
	int retorno = -1;
	char aux [25];

		sprintf (aux, "%d", cantidadJugadores);

		if (this != NULL && cantidadJugadores >=0)
		{
			if (validarEntero(aux)==0)
			{
				retorno = 0;
				this->cantidadJugadores = atoi (aux);
			}

		}
		return retorno;
}

int arcade_getCantidadJugadores(Arcade* this,int* cantidadJugadores)
{
	int retorno = -1;
		if (this != NULL && cantidadJugadores != NULL)
		{
			retorno = 0;
			*cantidadJugadores = this -> cantidadJugadores;
		}
		return retorno;
}

int arcade_setCapacidadFichas(Arcade* this,int capacidadFichas)
{
	int retorno = -1;
	char aux [25];

		sprintf (aux, "%d", capacidadFichas);

		if (this != NULL && capacidadFichas >=0)
		{
			if (validarEntero(aux)==0)
			{
				retorno = 0;
				this->capacidadFichas = atoi (aux);
			}

		}
		return retorno;
}

int arcade_getCapacidadFichas(Arcade* this,int* capacidadFichas)
{
	int retorno = -1;
		if (this != NULL && capacidadFichas != NULL)
		{
			retorno = 0;
			*capacidadFichas = this -> capacidadFichas;
		}
		return retorno;
}

int arcade_setNombreSalon(Arcade* this,char* nombreSalon)
{
	int retorno;
	if (this != NULL && nombreSalon != NULL)
	{
		if (esAlfanumerica(nombreSalon, LEN_SALON)==0)
		{
			retorno = 0;
			strncpy (this->nombreSalon, nombreSalon, LEN_SALON);
		}
	}
	return retorno;
}

int arcade_getNombreSalon(Arcade* this,char* nombreSalon)
{
	int retorno;
	if (this != NULL && nombreSalon != NULL)
	{
			retorno = 0;
			strncpy (nombreSalon, this->nombreSalon, LEN_SALON);
	}
	return retorno;
}


int arcade_setNombreJuego(Arcade* this,char* nombreJuego)
{
	int retorno;
	if (this != NULL && nombreJuego != NULL)
	{
		if (esNombre(nombreJuego)==0)
		{
			retorno = 0;
			strncpy (this->nombreJuego, nombreJuego, LEN_JUEGO);
		}
	}
	return retorno;
}

int arcade_getNombreJuego(Arcade* this,char* nombreJuego)
{
	int retorno;
	if (this != NULL && nombreJuego != NULL)
	{
			retorno = 0;
			strncpy (nombreJuego, this->nombreJuego, LEN_JUEGO);
	}
	return retorno;
}

void arcade_delete(LinkedList* this, int indice)
{
	if (this != NULL && ll_len(this)>0 && indice >=0)
	{
		 ll_remove(this, indice);
	}
}

int arcade_CriterioEsMultijugador(void* pAuxiliar)
{
	int retorno = -1;

	int auxCantidadJugadores;

	Arcade* pArcade;

	if(pAuxiliar!= NULL)
	{
		pArcade = (Arcade*)pAuxiliar;

		if(arcade_getCantidadJugadores(pArcade, &auxCantidadJugadores)==0)
		{
			if(auxCantidadJugadores>1)
			{
				retorno = -1;
			}
			else
			{
				retorno= 0;
			}
		}
	}
	return retorno;
}

void arcade_criterioActulizarFichas(void* pAuxiliar)
{
	int auxCapacidadFIchas;
	Arcade* pArcade;
	if(pAuxiliar!=NULL)
	{
		pArcade = (Arcade*)pAuxiliar;
		if(arcade_getCapacidadFichas(pArcade, &auxCapacidadFIchas)==0)
		{
			if(auxCapacidadFIchas > 0)
			{
				auxCapacidadFIchas = auxCapacidadFIchas * 2;
				arcade_setCapacidadFichas(pArcade,auxCapacidadFIchas);
			}
		}
	}
}
