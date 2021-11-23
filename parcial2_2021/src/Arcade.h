#ifndef arcade_H_INCLUDED
#define arcade_H_INCLUDED
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#define LEN_NACIONALIDAD 128
#define LEN_SALON 128
#define LEN_JUEGO 63
#define LENID 25
#define LENENTERO 25
typedef struct
{
	int id;
	char nacionalidad[LEN_NACIONALIDAD];
	int tipoSonido;
	int cantidadJugadores;
	int capacidadFichas;
	char nombreSalon[LEN_SALON];
	char nombreJuego[LEN_JUEGO];
}Arcade;

Arcade* arcade_new();
Arcade* arcade_newParametros(char* idStr,char* nacionalidadStr,char* tipoSonidoStr, char* CantidadJugadoresStr, char* cantidadFichasStr, char* nombreSalonStr, char* nombreJuegoStr);
void arcade_delete(LinkedList* this, int indice);
int arcade_setId(Arcade* this,int id);
int arcade_getId(Arcade* this,int* id);
int arcade_setNacionalidad(Arcade* this,char* nacionalidad);
int arcade_getNacionalidad(Arcade* this,char* nacionalidad);
int arcade_setTipoSonido(Arcade* this,int tipoSonido);
int arcade_getTipoSonido(Arcade* this,int* tipoSonido);
int arcade_setCantidadJugadores(Arcade* this,int cantidadJugadores);
int arcade_getCantidadJugadores(Arcade* this,int* cantidadJugadores);
int arcade_setCapacidadFichas(Arcade* this,int capacidadFichas);
int arcade_getCapacidadFichas(Arcade* this,int* capacidadFichas);
int arcade_setNombreSalon(Arcade* this,char* nombreSalon);
int arcade_getNombreSalon(Arcade* this,char* nombreSalon);
int arcade_setNombreJuego(Arcade* this,char* nombreJuego);
int arcade_getNombreJuego(Arcade* this,char* nombreJuego);
void arcade_delete(LinkedList* this, int indice);
int arcade_CriterioEsMultijugador(void* pAuxiliar);
void arcade_criterioActulizarFichas(void* pAuxiliar);
#endif // arcade_H_INCLUDED
