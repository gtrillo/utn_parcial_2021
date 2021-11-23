#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Arcade.h"

int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayListArcade);

#endif /* PARSER_H_ */
