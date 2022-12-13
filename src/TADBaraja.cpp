/*
 * TADBaraja.cpp
 *
 *  Created on: 25 nov 2021
 *      Author: Alexeido & Lete
 */

#include "TADBaraja.h"
#include <iostream>
#include <ctime>

using namespace std;

void iniciarBaraja(baraja &b) {
	srand(time(NULL));
	b.ocupadas = 0;
	int color;
	int forma;
	int numero;
	int relleno;
	int i;
	i = 0;
	for (numero = 1; numero < 4; numero++) {
		for (forma = 1; forma < 4; forma++) {
			for (color = 1; color < 4; color++) {
				for (relleno = 1; relleno < 4; relleno++) {
					crearCarta(b.vCartas[i], numero, forma, color, relleno);
					i++;
					b.ocupadas++;

				}
			}
		}
	}
}

carta quitarCarta(baraja &b) {
	srand(time(NULL));
	carta aux;
	int posicion;
	posicion = rand() % b.ocupadas;
	aux = b.vCartas[posicion];
	b.vCartas[posicion] = b.vCartas[b.ocupadas - 1];
	b.ocupadas--;
	return aux;
}

int cuantasCartas(baraja b) {
	return b.ocupadas;
}

