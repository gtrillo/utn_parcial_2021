#include "utn_menu.h"

static void imprimirOpciones (void);

/** \brief funsion de menu
* \param lista listSalon*
* \param largo del array arcade
* \param listArcade
* \param largo del array salones
*/
void utn_menu (LinkedList* listArcades)
{
	int opcion;
	LinkedList* clonlistArcades;

	controller_loadFromText("arcades.csv", listArcades);
	do {
		imprimirOpciones();
		utn_pedirInt(&opcion, 1, 8, 5, "\nOpcion:\n", "\nError intente nuevamente:\n");
		switch (opcion)
		{
			case 1:
				if (controller_addArcade(listArcades)==0)
				{
					printf ("Arcade dado de alta con exito.\n");
					if (controller_saveAsText("arcades.csv", listArcades)==0)
					{
						continue;
					}
					else
					{
						puts ("no se pudo guardar el arcade en el archivo");
					}
				}
				break;
			case 2:
				controller_ListArcade(listArcades);
				if (controller_editArcade(listArcades)==0)
				{
					puts ("arcade modificado correctamente");
					if (controller_saveAsText("arcades.csv", listArcades)==0)
					{
						continue;
					}
					else
					{
						puts ("no se pudo guardar el arcade en el archivo");
					}
				}
				break;
			case 3:
				controller_ListArcade(listArcades);
				if (controller_removeArcade(listArcades)==0)
				{
					printf ("arcade dado de baja con exito");
				}
				break;
			case 4:
				if (controller_sortArcade(listArcades)==0)
				{
					controller_ListArcade(listArcades);
				}
				break;
			case 5:
			if (controller_saveAsTextGames("games.csv", listArcades)==0)
					{
						continue;
					}
				break;
			case 6:
				clonlistArcades = ll_clone(listArcades);
				if (clonlistArcades != NULL)
				{
					ll_filter(clonlistArcades, arcade_CriterioEsMultijugador);
					if (controller_saveAsText("multijugador.csv", clonlistArcades)==0)
					{
						continue;
					}
				}
				break;
			case 7:
				if (ll_map(listArcades, arcade_criterioActulizarFichas)==0)
				{
					if (controller_saveAsText("arcades.csv", listArcades)==0)
					{
						continue;
					}
					else
					{
						puts ("no se pudo guardar el arcade en el archivo");
					}
				}
				break;
		}
	}while (opcion <9);

}

static void imprimirOpciones (void)
{
	printf ("\n------------------Bienvenido--------------------");
	printf ("\nUtilice su teclado numerico para seleccionar una opcion:");
	printf("\n1) INCORPORAR ARCADE");
	printf ("\n2) MODIFICAR ARCADE");
	printf ("\n3) ELIMINAR ARCADE");
	printf ("\n4) IMPRIMIR ARCADES ordenados por nombre de juego");
	printf ("\n5) Generar archivo con JUEGOS");
	printf ("\n6) Generar un archivo con arcades “Multijugador” (mas de 1 jugador).");
	printf ("\n7) Actualizar cantidad de fichas");
}
