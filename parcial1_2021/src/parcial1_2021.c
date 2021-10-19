/*
 ============================================================================
 Name        : parcial1_2021.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Salon.h"
#include "Arcade.h"
#include "utn_menu.h"
#define LEN_LIST_SALONES 100
#define LEN_LIST_ARCADES 1000
int main(void)
{
		Salon salones [LEN_LIST_SALONES];
		Arcade arcades [LEN_LIST_ARCADES];
		setbuf (stdout, NULL);
		salon_initSalon(salones, LEN_LIST_SALONES);
		arcade_initArcade(arcades, LEN_LIST_ARCADES);



			salon_altaForzada(salones, LEN_LIST_SALONES, 0, 0, "caseros", "caseros 125", 1);
			//salon_altaForzada(salones, LEN_LIST_SALONES, 1, 1, "Brasil", "caseros 125", 1);
			//arcade_altaForzada(arcades, LEN_LIST_ARCADES, 0, 0, "pacman", "peruana", 0, 2, 4, 8);
			//arcade_altaForzada(arcades, LEN_LIST_ARCADES, 1, 1, "contra", "argentina", 1, 1, 2, 2);
			arcade_altaForzada(arcades, LEN_LIST_ARCADES, 2, 2, "pacman", "colombiana", 1, 1, 7, 11);
			arcade_altaForzada(arcades, LEN_LIST_ARCADES, 3, 3, "MARIO", "colombiana", 0, 1, 1, 11);
		//arcade_altaForzada(arcades, LEN_LIST_ARCADES, 4, 4, "pacman", "colombiana", 0, 1, 1, 11);
		//arcade_altaForzada(arcades, LEN_LIST_ARCADES, 5, 5, "street fighter", "peruana", 1, 1, 6, 8);
		//arcade_altaForzada(arcades, LEN_LIST_ARCADES, 6, 6, "contra", "argentina", 1, 1, 7, 2);
		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 7, 7, "pacman", "colombiana", 1, 1, 1, 11);
		//arcade_altaForzada(arcades, LEN_LIST_ARCADES, 8, 8, "pacman", "colombiana", 1, 1, 1, 11);
		utn_menu (salones, LEN_LIST_SALONES, arcades, LEN_LIST_ARCADES);
		return EXIT_SUCCESS;
}
