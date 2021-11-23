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
int arcade_initArcade(Arcade* list[], int len);
int arcade_dameUnLugarLibre (Arcade* list[], int len, int* retornoPosicionLibre);
Arcade* arcade_new(void);
int arcade_addArcade(Arcade listArcades[], Salon* listSalones[]);
int arcade_buscarArcadeDeSalon (Arcade* arrayArcades[], int listLen, int id, int* pPosicionEncontrada);
int arcade_buscarporId (Arcade* arrayArcades[], int listLen, int id, int* pPosicionEncontrada);
int modificarArcade(Arcade* list,int len);
int arcade_printArcades(Arcade* list[], int len);
int arcade_removeArcade(Arcade* list, int len, int id);
int arcade_JuegosCargados (Arcade* list[], int len);
int arcade_altaForzada (Arcade* array, int limite, int indice, int id, char* nombre, char* nacionalidad,int idSalon, int tipoSonido, int cantidadJugadores, int capacidadFichas);
#endif /* ARCADE_H_ */
