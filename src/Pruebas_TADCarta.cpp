/*
 * Pruebas_TADCarta.cpp
 *
 *  Created on: 26 nov 2021
 *      Author: Alexeido & Lete
 */
#include "Pruebas_TADCarta.h"
#include <iostream>
using namespace std;

void pruebasiniciar() {
	carta c;
	bool error;
	int i;
	error = false;
	for (i = -1; (i < 6) && (!error); i++) {
		crearCarta(c, i, i, i, i);
		if ((c.forma != i) && (c.color != i) && (c.numero != i)
				&& (c.relleno != i)) {
			cout << "Error en el modulo Iniciar Carta" << endl;
			error = true;
		}
	}
}

void pruebasobtenerNumero() {
	carta c;
	bool error;
	int i;
	error = false;
	for (i = -1; (i < 6) && (!error); i++) {
		crearCarta(c, i, 7, 8, 9);
		if ((obtenerNumero(c) != i)) {
			cout << "Error en el modulo Obtener Numero" << endl;
			error = true;
		}
	}
}

void pruebasForma() {
	carta c;
	bool error;
	int i;
	error = false;
	for (i = -1; (i < 6) && (!error); i++) {
		crearCarta(c, 6, i, 3, 99);
		if ((obtenerForma(c) != i)) {
			cout << "Error en el modulo Obtener Numero" << endl;
			error = true;
		}
	}
}

void pruebasColor() {
	carta c;
	bool error;
	int i;
	error = false;
	for (i = -1; (i < 6) && (!error); i++) {
		crearCarta(c, 7, 2, i, 6);
		if ((obtenerColor(c) != i)) {
			cout << "Error en el modulo Obtener Numero" << endl;
			error = true;
		}
	}
}

void pruebasRelleno() {
	carta c;
	bool error;
	int i;
	error = false;
	for (i = -1; (i < 6) && (!error); i++) {
		crearCarta(c, 1, 2, 4, i);
		if ((obtenerRelleno(c) != i)) {
			cout << "Error en el modulo Obtener Numero" << endl;
			error = true;
		}
	}
}

void pruebasTADCarta() {

	cout << "----Iniciando modulo de pruebas del TADCarta----" << endl;
	pruebasiniciar();
	pruebasobtenerNumero();
	pruebasForma();
	pruebasColor();
	pruebasRelleno();
	cout << "----Modulo de pruebas del TADCarta Finalizado----" << endl;

}

void mostrarCarta(carta c) {
	cout << c.numero << " - " << c.forma << " - " << c.color << " - "
			<< c.relleno << endl;
}
