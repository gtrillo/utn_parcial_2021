#include <stdio.h>
#include <stdlib.h>
#define LEN_LIST 128
#define LEN_NOMBREJUEGO 63

#ifndef ARCADE_H_
#define ARCADE_H_

typedef struct
{
	int id;
	char nacionalidad [LEN_LIST];
	int tipoSonido;
	int cantidadJugadores;
	int capacidadFichas;
	int idSalon;
	char nombreDelJuego[LEN_NOMBREJUEGO];
	int flagEmpty;
}Arcade;
int arcade_initArcade(Arcade* list, int len);
int arcade_dameUnLugarLibre (Arcade list[], int lenArray, int* retornoPosicionLibre);
int arcade_addArcade(Arcade listArcades[], Salon listSalones[]);
int arcade_buscarPorID(Arcade* list, int len,int id);
int modificarArcade(Arcade* list,int len);
int arcade_printArcades(Arcade* list, int len);
int arcade_removeArcade(Arcade* list, int len, int id);
int arcade_JuegosCargados (Arcade list[], int len);;
int arcade_altaForzada (Arcade* array, int limite, int indice, int id, char* nombre, char* nacionalidad,int idSalon, int tipoSonido, int cantidadJugadores, int capacidadFichas);
int arcade_JuegosCargados (Arcade list[], int len);
#endif /* ARCADE_H_ */
