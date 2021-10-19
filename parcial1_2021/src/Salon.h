#include <stdio.h>
#include <stdlib.h>
#define LEN_LIST 128

#ifndef SALON_H_
#define SALON_H_

typedef struct
{
	int id;
	char nombre [LEN_LIST];
	char direccion [LEN_LIST];
	int tipo;
	int flagEmpty;
}Salon;
int salon_initSalon(Salon* list, int len);
int salon_addSalon(Salon list []);
int salon_dameUnLugarLibre (Salon list[], int len, int* retornoPosicionLibre);
int salon_printSalones(Salon* list, int len);
int salon_buscarPorID(Salon* list, int len,int id);
int salon_altaForzada (Salon* array, int limite, int indice, int id, char* nombre, char* direccion,int tipo);
int salon_tipoSalones (Salon listSalones[], int tipo, char retornoTipo[]);
#endif /* SALON_H_ */
