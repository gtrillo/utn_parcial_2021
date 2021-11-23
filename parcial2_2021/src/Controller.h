#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Arcade.h"
#include "utn_pedirTipo.h"
#define LEN_NACIONALIDAD 128
#define LEN_SALON 128
#define TIPO_MONO 0
#define LEN_JUEGO 63
#define TIPO_ESTEREO 1
int controller_dameUnIdNuevo(LinkedList* pArrayListArcade);
int controller_loadFromText(char* path , LinkedList* pArrayListArcade);
int controller_addArcade(LinkedList* pArrayListArcade);
int controller_editArcade(LinkedList* pArrayListArcade);
int controller_removeArcade(LinkedList* pArrayListArcade);
int controller_ListArcade(LinkedList* pArrayListArcade);
int controller_sortArcade(LinkedList* pArrayListArcade);
int controller_saveAsText(char* path , LinkedList* pArrayListArcade);
int controller_printArcade (LinkedList* pArrayListArcade, int id);
int controller_findById(LinkedList* pArray,int id, int* indiceDeId);
int controller_saveAsTextGames(char* path , LinkedList* this);
//int controller_buscarPorId(LinkedList* pArrayListArcade, int id);
#endif /* CONTROLLER_H_ */
