/*
 * Pruebas_TADBaraja.h
 *
 *  Created on: 26 nov 2021
 *      Author: Alexeido & Lete
 */

#ifndef PRUEBAS_TADBARAJA_H_
#define PRUEBAS_TADBARAJA_H_
#include "TADBaraja.h"
#include "TADCarta.h"
#include "Pruebas_TADCarta.h"

//Prueba que se cumplen las condiciones para crear una carta
bool cumpleCondiciones(carta c);

//Prueba que se inicia correctamente la baraja
void pruebasiniciarBaraja();

//Prueba que se obtiene y elimina correctamtne una carta al azar
void pruebasquitarCarta();

//Pueba que devuelve correctamente el numero de cartas que quedan en la baraja
void pruebascuantasCartas();

void pruebasTADBaraja();

void mostrarBaraja(baraja b);

#endif /* PRUEBAS_TADBARAJA_H_ */
