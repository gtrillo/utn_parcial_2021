/*
 ============================================================================
 Name        : parcial1_2021.c
 Author      : Trillo Gonzalo
 Version     : 1.0
 Description : Primer Parcial de laboratorio I
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
		setbuf (stdout, NULL);
		Salon* arraypSalones [LEN_LIST_SALONES];
		Arcade* arraypArcades [LEN_LIST_ARCADES];
		salon_initSalon(arraypSalones, LEN_LIST_SALONES);
		arcade_initArcade(arraypArcades, LEN_LIST_ARCADES);
		//salon_altaForzada(salones, LEN_LIST_SALONES, 0, 0, "caseros", "caseros 125", 1);
		/*salon_altaForzada(salones, LEN_LIST_SALONES, 1, 1, "Brasil", "caseros 125", 1);
			arcade_altaForzada(arcades, LEN_LIST_ARCADES, 0, 0, "pacman", "peruana", 0, 2, 4, 8);
			arcade_altaForzada(arcades, LEN_LIST_ARCADES, 1, 1, "contra", "argentina", 0, 1, 4, 2);
			arcade_altaForzada(arcades, LEN_LIST_ARCADES, 2, 2, "pacman", "colombiana", 0, 1, 7, 11);
			arcade_altaForzada(arcades, LEN_LIST_ARCADES, 3, 3, "MARIO", "colombiana", 0, 1, 6, 11);
		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 4, 4, "pacman", "colombiana", 0, 1, 7, 11);
		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 5, 5, "street fighter", "peruana", 0, 1, 6, 8);
		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 6, 6, "contra", "argentina", 0, 1, 7, 2);
		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 7, 7, "pacman", "colombiana", 0, 1, 3, 11);
		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 8, 8, "pacman", "colombiana", 0, 1, 4, 11);
		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 9, 9, "pacman", "colombiana", 0, 1, 4, 11);
		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 10, 10, "pacman", "colombiana", 0, 1, 4, 11);
		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 11, 11, "pacman", "colombiana", 0, 1, 4, 11);

		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 12, 12, "pacman", "peruana", 1, 2, 4, 8);
		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 13, 13, "contra", "argentina", 1, 1, 4, 2);
		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 14, 14, "pacman", "colombiana", 1, 1, 7, 11);
		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 15, 15, "MARIO", "colombiana", 1, 1, 6, 11);
		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 16, 16, "MARIO", "colombiana", 1, 1, 6, 11);
		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 17, 17, "MARIO", "colombiana", 1, 1, 6, 11);
		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 18, 18, "MARIO", "colombiana", 1, 1, 6, 11);
		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 19, 19, "MARIO", "colombiana", 1, 1, 6, 11);
		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 20, 20, "MARIO", "colombiana", 1, 1, 6, 11);
		arcade_altaForzada(arcades, LEN_LIST_ARCADES, 21, 21, "MARIO", "colombiana", 1, 1, 6, 11);*/

		utn_menu (arraypSalones, LEN_LIST_SALONES, arraypArcades, LEN_LIST_ARCADES);
		return EXIT_SUCCESS;
}
