#include <stdio.h>
#include <stdlib.h>
#include "Salon.h"
#include "Arcade.h"

#ifndef INFORMES_H_
#define INFORMES_H_

int salon_removeSalon(Salon* listSalon[], int lenSalon, Arcade* listArcade[], int lenArcade, int id);
int informes_SalonConMas4Arcades (Arcade listArcades[], int lenArcades, Salon listSalones[], int lenSalones);
int informes_AParamasDe2Jugadores (Salon listSalones[], int lenSalones, Arcade listArcades[], int lenArcades);
int informes_contadorArcades (Arcade listArcades[], int lenArcades, int idIngresado);
int informes_ListaArcades (Arcade listArcades[], int lenArcades, Salon listSalones[], int lenSalones ,int idIngresado);
int informes_SalonConMasArcades (Salon listSalones [], int lenSalones, Arcade listArcades [], int lenArcades, int* idMaximo, int* contadorMaximo);
int informes_recaudacionArcades (Arcade listArcades[], int lenArcades, int idIngresado,float precioIngresado, float* pResultado);
int contadorJuegos (Arcade list[], int len, char textoIngresado[], int* pContador);
int informesSalonCompleto (Salon listSalones[], int lenSalones, Arcade listArcades[], int lenArcades);
int informePromedioArcadeXSalon (int contadorSalones, int contadorArcades);
#endif /* SALON_REMOVE_H_ */
