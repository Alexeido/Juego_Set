/*
 * TADCarta.h
 *
 *  Created on: 25 nov 2021
 *      Author: Alexeido & Lete
 */

#ifndef TADCARTA_H_
#define TADCARTA_H_

// 		{ 1 <= numero  <= 3: número de elementos que contiene de la carta }
// 		{ 1 <= forma   <= 3: forma de los elementos   => 1 = elipse | 2 = rombo   | 3 = onda }
// 		{ 1 <= color   <= 3: color de los elementos   => 1 = azul   | 2 = verde   | 3 = rojo }
//		{ 1 <= relleno <= 3: relleno de los elementos => 1 = vacío  | 2 = rayado  | 3 = relleno }
// DESCRIPCIÓN: Pinta una carta en la posición (fila, columna) del tablero con *numero* elementos
// 				con forma *forma*, color *color* y relleno *relleno*

struct carta {
	int numero;
	int forma;
	int color;
	int relleno;
};

/* PRE={1 <= numero  <= 3, 1 <= forma   <= 3, 1 <= color   <= 3, 1 <= relleno <= 3}
 * POST={Crea una carta con el numero, forma, color y relleno indicados}
 * 0(1)
 */
void crearCarta(carta &c, int num, int form, int color, int relleno);

/* PRE={Carta creda correctamente}
 * POS={Obtiene el numero de la carta que indiquemos}
 * 0(1)
 */
int obtenerNumero(carta c);

/* PRE={Carta creda correctamente}
 * POS={Obtiene la forma de la carta que indiquemos}
 * 0(1)
 */
int obtenerForma(carta c);

/* PRE={Carta creda correctamente}
 * POS={Obtiene el color de la carta que indiquemos}
 * 0(1)
 */
int obtenerColor(carta c);

/* PRE={Carta creda correctamente}
 * POS={Obtiene el relleno de la carta que indiquemos}
 * 0(1)
 */
int obtenerRelleno(carta c);

#endif /* TADCARTA_H_ */
