#include <stdio.h>
#include <stdlib.h>
#include "Arcade.h"
#include "LinkedList.h"
#include "utn_menu.h"
#include "Controller.h"

int main(void)
{
	setbuf(stdout, NULL);
	LinkedList* listaArcades = ll_newLinkedList();
	utn_menu(listaArcades);
	return 0;
}
