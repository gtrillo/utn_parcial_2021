#include "parser.h"
/** \brief Parsea los datos de los arcades desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayListArcade)
{
	Arcade* auxpArcade;
	char auxID [LENENTERO];
	char auxNacionalidad [LEN_NACIONALIDAD];
	char auxTipoSonido [LENENTERO];
	char auxCantidadJugadores [LENENTERO];
	char auxCapacidadFichas [LENENTERO];
	char auxNombreSalon [LEN_SALON];
	char auxnNombreJuego [LEN_JUEGO];
	int retorno = -1;

	if (pFile != NULL && pArrayListArcade != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxID,auxNacionalidad,auxTipoSonido,auxCantidadJugadores,auxCapacidadFichas,auxNombreSalon,auxnNombreJuego);
		do {
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxID,auxNacionalidad,auxTipoSonido,auxCantidadJugadores,auxCapacidadFichas,auxNombreSalon,auxnNombreJuego)>6)
				{
					if (strcmp(auxTipoSonido, "MONO")==0)
					{
						strcpy (auxTipoSonido, "0");
					}else
					{
						strcpy (auxTipoSonido, "1");
					}
					auxpArcade = arcade_newParametros(auxID, auxNacionalidad, auxTipoSonido, auxCantidadJugadores, auxCapacidadFichas, auxNombreSalon, auxnNombreJuego);

					if (auxpArcade != NULL)
					{
						ll_add(pArrayListArcade, auxpArcade);
						retorno = 0;
					}else
					{
						retorno = -1;
						break;
					}
				}
		}while(feof (pFile) == 0);
	}
    return retorno;

}
