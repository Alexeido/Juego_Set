/*
 * TADTablero.cpp
 *
 *  Created on: 9 dic 2021
 *      Author: Alexeido & Lete
 */

#include "TADTablero.h"
#include <ctime>
#include <iostream>
using namespace std;

void iniciarTablero(tablero &Table, baraja &b) {
	Table.columnas = 4;
	int f;
	int c;
	for (f = 0; f < MAXFILAS; f++) {
		for (c = 0; c < Table.columnas; c++) {
			Table.mTablero[c][f] = quitarCarta(b);
			Table.selected[c][f] = false;

		}
	}

}

void iniciarTableroAjustado(tablero &Table, baraja &b, int columnas) {
	Table.columnas = columnas;
	int f;
	int c;
	for (f = 0; f < MAXFILAS; f++) {
		for (c = 0; c < Table.columnas; c++) {
			Table.mTablero[c][f] = quitarCarta(b);
			Table.selected[c][f] = false;

		}
	}
}

void sumarColumnas(tablero &tab, baraja &b) {
	int f;
	for (f = 0; f < MAXFILAS; f++) {
		if (obtenerBaraja(b) > 0) {
			tab.mTablero[tab.columnas][f] = quitarCarta(b);
		} else {
			borrarCarta(tab, f, tab.columnas);
		}
		tab.selected[tab.columnas][f] = false;
	}
	tab.columnas++;

}

int obtenerColumnas(tablero Tab) {
	return Tab.columnas;
}

int obtenerBaraja(baraja b) {
	return cuantasCartas(b);
}

carta obtenerCarta(tablero Tab, int fila, int columna) {
	return Tab.mTablero[columna][fila];
}

int obtenerNumeroTab(tablero Tab, int fila, int columna) {
	return obtenerNumero(Tab.mTablero[columna][fila]);
}

int obtenerFormaTab(tablero Tab, int fila, int columna) {
	return obtenerForma(Tab.mTablero[columna][fila]);
}

int obtenerColorTab(tablero Tab, int fila, int columna) {
	return obtenerColor(Tab.mTablero[columna][fila]);
}

int obtenerRellenoTab(tablero Tab, int fila, int columna) {
	return obtenerRelleno(Tab.mTablero[columna][fila]);
}

bool estaSeleccionada(tablero Tab, int fila, int columna) {
	return Tab.selected[columna][fila];
}

void seleccionarCarta(tablero &Tab, int fila, int columna) {
	Tab.selected[columna][fila] = !Tab.selected[columna][fila];
}

void sustituirCarta(tablero &Tab, baraja &b, int fila, int columna) {
	Tab.mTablero[columna][fila] = quitarCarta(b);

}

void borrarCarta(tablero &Tab, int fila, int columna) {
	carta borrada;
	crearCarta(borrada, -1, -1, -1, -1);
	Tab.mTablero[columna][fila] = borrada;

}

void matrizCondiciones(tablero Tab, mCondiciones &Condiciones) {
	int f, c, i;
	i = 0;
	for (f = 0; (f < MAXFILAS) && (i < 3); f++) {
		for (c = 0; (c < Tab.columnas) && (i < 3); c++) {
			if (estaSeleccionada(Tab, f, c)) {
				Condiciones[i][0] = obtenerNumero(obtenerCarta(Tab, f, c));
				Condiciones[i][1] = obtenerForma(obtenerCarta(Tab, f, c));
				Condiciones[i][2] = obtenerColor(obtenerCarta(Tab, f, c));
				Condiciones[i][3] = obtenerRelleno(obtenerCarta(Tab, f, c));
				i++;
			}
		}
	}

}

bool comprobarSet(mCondiciones Condiciones) {
	bool cumplen;
	int igualdades[4];
	int f, i;
	cumplen = true;
	i = 0;
	while (i < 4) {
		igualdades[i] = 0;
		i++;
	}
	for (f = 0; (f < 4) && (cumplen); f++) {
		if (Condiciones[0][f] == Condiciones[1][f]) {
			igualdades[f]++;
		}
		if (Condiciones[2][f] == Condiciones[1][f]) {
			igualdades[f]++;
		}
		if (Condiciones[0][f] == Condiciones[2][f]) {
			igualdades[f]++;
		}
		if (igualdades[f] == 1 || igualdades[f] == 2) {
			cumplen = false;
		}
	}

	return cumplen;
}

bool formanSet(tablero &Tab) {
	int f, c;
	bool forman;
	mCondiciones Condiciones;
	matrizCondiciones(Tab, Condiciones);

	forman = comprobarSet(Condiciones);

	for (f = 0; f < MAXFILAS; f++) {
		for (c = 0; c < Tab.columnas; c++) {
			if (estaSeleccionada(Tab, f, c)) {
				seleccionarCarta(Tab, f, c);
			}
		}
	}

	return forman;
}

bool buscarSett(tablero tab, posicion &filas, posicion &columnas) {

	int f, c, f1, c1, f2, c2, f3, c3;
	bool enc;
	enc = false;

	for (f = 0; f < MAXFILAS; f++) {
		for (c = 0; c < tab.columnas; c++) {
			if (estaSeleccionada(tab, f, c)) {
				seleccionarCarta(tab, f, c);
			}
		}
	}

	for (f1 = 0; f1 < MAXFILAS && !enc; f1++) {
		for (c1 = 0; c1 < obtenerColumnas(tab) && !enc; c1++) {
			for (f2 = 0; f2 < MAXFILAS && !enc; f2++) {
				for (c2 = 0; c2 < obtenerColumnas(tab) && !enc; c2++) {
					for (f3 = 0; f3 < MAXFILAS && !enc; f3++) {
						for (c3 = 0; c3 < obtenerColumnas(tab) && !enc; c3++) {
							if ((f1 != f2 || c1 != c2) && (f2 != f3 || c2 != c3)
									&& (f3 != f1 || c3 != c1)) {
								if (obtenerFormaTab(tab, f1, c1) > 0
										&& obtenerFormaTab(tab, f2, c2) > 0
										&& obtenerFormaTab(tab, f3, c3) > 0) {
									seleccionarCarta(tab, f1, c1);
									seleccionarCarta(tab, f2, c2);
									seleccionarCarta(tab, f3, c3);
									if (formanSet(tab)) {
										enc = true;

									}
								}
							}
						}

					}

				}
			}
		}
	}

	filas[0] = f1 - 1;
	columnas[0] = c1 - 1;
	filas[1] = f2 - 1;
	columnas[1] = c2 - 1;
	filas[2] = f3 - 1;
	columnas[2] = c3 - 1;
	return enc;
}

