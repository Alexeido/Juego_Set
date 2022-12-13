/*
 * Pruebas_TADBaraja.cpp
 *
 *  Created on: 26 nov 2021
 *      Author: Alexeido & Lete
 */
#include "TADBaraja.h"
#include "TADCarta.h"
#include "Pruebas_TADCarta.h"
#include <iostream>
using namespace std;

bool cumpleCondiciones(carta c) {
	bool condiciones;
	condiciones = true;
	if (c.color <= 0) {
		condiciones = false;
	}
	if (c.color > 3) {
		condiciones = false;
	}
	if (c.forma <= 0) {
		condiciones = false;
	}
	if (c.forma > 3) {
		condiciones = false;
	}
	if (c.relleno <= 0) {
		condiciones = false;
	}
	if (c.relleno > 3) {
		condiciones = false;
	}
	if (c.numero <= 0) {
		condiciones = false;
	}
	if (c.numero > 3) {
		condiciones = false;
	}
	return condiciones;

}

bool mismaCarta(carta c, carta aux) {
	bool iguales = false;
	if ((obtenerForma(c) == obtenerForma(aux))
			&& (obtenerColor(c) == obtenerColor(aux))
			&& (obtenerNumero(c) == obtenerNumero(aux))
			&& (obtenerRelleno(c) == obtenerRelleno(aux))) {
		iguales = true;
	}
	return iguales;
}

void pruebasiniciarBaraja() {
	baraja b;
	carta aux;
	bool cumple;
	int i;
	int j;
	cumple = true;
	iniciarBaraja(b);
	for (i = 0; (i < b.ocupadas) && cumple; i++) {
		if (!cumpleCondiciones(b.vCartas[i])) {
			cout << "Error en el modulo Inicializar Baraja, código de error: "
					<< (i) << endl;
			cumple = false;
		}

	}

	if (b.ocupadas != 81) {
		cumple = false;
	}
	for (i = 0; (i < b.ocupadas) && cumple; i++) {
		aux = b.vCartas[i];
		for (j = 0; j < b.ocupadas && cumple; i++) {
			if ((i != j) && mismaCarta(aux, b.vCartas[j])) {
				cumple = false;
			}
		}
	}
}

void pruebasquitarCarta() {
	int i;
	bool error;
	error = false;
	baraja b;
	carta aux;
	carta aux2;

	iniciarBaraja(b);
	aux = quitarCarta(b);
	aux2 = aux;
	i = b.ocupadas;
	while ((b.ocupadas > 0) && !error) {
		if (mismaCarta(aux, quitarCarta(b))) {
			error = true;
		}
		if (b.ocupadas == i) {
			error = true;
		}
	}
	if (error) {
		cout << "Error en el modulo quitarCarta" << endl;
	}
}

void pruebascuantasCartas() {
	baraja b;
	int aux;
	iniciarBaraja(b);
	aux = cuantasCartas(b);
	quitarCarta(b);
	if (cuantasCartas(b) == aux) {
		cout << "Error en el modulo cartas Restantes" << endl;
	}

}

void mostrarBaraja(baraja b) {
	int i;
	for (i = 0; i < b.ocupadas; i++) {
		mostrarCarta(b.vCartas[i]);
	}
}

void pruebasTADBaraja() {

	cout << "----Iniciando modulo de pruebas del TADBaraja----" << endl;

	pruebasiniciarBaraja();
	pruebasquitarCarta();
	pruebascuantasCartas();

	cout << "----Modulo de pruebas del TADBaraja Finalizado----" << endl;
}

