/*
 * TADJuego.h
 *
 *  Created on: 10 dic 2021
 *      Author: Alexeido & Lete
 */

#ifndef TADJUEGO_H_
#define TADJUEGO_H_

#include "TADTablero.h"
#include "entorno.h"

struct juego {
	tablero tab;
	baraja b;
	int puntos;
};

//PRE={Correcto funcionamiento del entorno y del tablero}
//POST={Realiza una animacion al encontar un set}
//O(n)
void resaltarSett(posicion filas, posicion columnas);

//PRE={Correcto funcionamiento del entorno y del tablero}
//POST={Inicia el juego}
//O(n^2)
void iniciarJuego();

//PRE={Correcto funcionamiento del entorno y del tablero y juego correctamente iniciado}
//POST={Permite jugar al juego}
//O(n)
void jugarJuego(juego sett, int n, int pc, int p, int pa);

//PRE={Correcto funcionamiento del entorno y del tablero y juego correctamente iniciado}
//POST={Gana el juego encontrando sets automaticamente}
//O(n^2)
void visualizarJuego();

//PRE={Correcto funcionamiento del entorno y del tablero}
//POST={Cuando encuentra el set susituye las cartas del set por otras de la baraja o las borra si la baraja esta vacia}
//O(n)
void setEncontrado(juego &sett, posicion seleccionFila,
		posicion seleccionColumna);

//PRE={Correcto funcionamiento del entorno y del tablero}
//POST={Deselecciona la carta que se encuentra en la posicion del cursor}
//O(n)
void juegoDeseleccionarCarta(juego &sett, int fila_act, int col_act,
		int &seleccionadas, posicion &seleccionFila,
		posicion &seleccionColumna);

//PRE={Correcto funcionamiento del entorno y del tablero}
//POST={Al seleccionar 3 y ver si forman set las deseleciona}
//O(n)
bool juegoSeleccionarCarta(juego &sett, int fila_act, int col_act,
		int &seleccionadas, posicion &seleccionFila,
		posicion &seleccionColumna);

//PRE={Correcto funcionamiento del entorno}
//POST={Finaliza el juego}
//O(1)
void finalizarJuego();

#endif /* TADJUEGO_H_ */
