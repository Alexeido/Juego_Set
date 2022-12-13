/*
 * TADCarta.cpp
 *
 *  Created on: 25 nov 2021
 *      Author: Alexeido & Lete
 */
#include <iostream>
#include "TADCarta.h"
using namespace std;

// 		{ 1 <= numero  <= 3: número de elementos que contiene de la carta }
// 		{ 1 <= forma   <= 3: forma de los elementos   => 1 = elipse | 2 = rombo   | 3 = onda }
// 		{ 1 <= color   <= 3: color de los elementos   => 1 = azul   | 2 = verde   | 3 = rojo }
//		{ 1 <= relleno <= 3: relleno de los elementos => 1 = vacío  | 2 = rayado  | 3 = relleno }
// DESCRIPCIÓN: Pinta una carta en la posición (fila, columna) del tablero con *numero* elementos
// 				con forma *forma*, color *color* y relleno *relleno*

void crearCarta(carta &c, int num, int form, int color, int relleno) {
	c.numero = num;
	c.forma = form;
	c.color = color;
	c.relleno = relleno;
}

int obtenerNumero(carta c) {
	return c.numero;
}

int obtenerForma(carta c) {
	return c.forma;
}

int obtenerColor(carta c) {
	return c.color;
}

int obtenerRelleno(carta c) {
	return c.relleno;
}

