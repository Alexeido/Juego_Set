/*
 * TADBaraja.h
 *
 *  Created on: 25 nov 2021
 *      Author: Alexeido & Lete
 */

#ifndef TADBARAJA_H_
#define TADBARAJA_H_
#include "TADCarta.h"
const int MAX = 81;

typedef carta cartas[MAX];

struct baraja {
	cartas vCartas;
	int ocupadas;
};

/* PRE={Correcto funcionamiento del modulo crearCarta}
 * POST={Crea una baraja de 81 cartas ninguna repetidas y ordenadas en base a su numero, forma, color y relleno}
 * 0(n⁴)
 */
void iniciarBaraja(baraja &b);

/* PRE={Baraja correctamente inicializada}
 * POST={Devuelve una carta aleatoria de la baraja y la elimina de dicha baraja}
 * 0(1)
 */
carta quitarCarta(baraja &b);

/* PRE={Baraja correctamente inicializada}
 * POST={Devuelve el numero de cartas que queda en la baraja}
 * O(1)
 */
int cuantasCartas(baraja b);

#endif /* TADBARAJA_H_ */
