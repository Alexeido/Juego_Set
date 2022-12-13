/*
 * TADTablero.h
 *
 *  Created on: 9 dic 2021
 *      Author: Alexeido & Lete
 */

#ifndef TADTABLERO_H_
#define TADTABLERO_H_

#include "TADBaraja.h"

const int MAXCOLUMNAS = 6;
const int MAXFILAS = 3;

typedef int posicion[3];
typedef carta Tab[MAXCOLUMNAS][MAXFILAS];
typedef bool Seleccionada[MAXCOLUMNAS][MAXFILAS];
typedef int mCondiciones[3][4];

struct tablero {
	Tab mTablero;
	int columnas;
	Seleccionada selected;
};

//PRE={Correcto funcionamitno de los modulos del TadBaraja y el TadCarta}
//POST={Inicia el tablero del juego}
//O(n^2)
void iniciarTablero(tablero &Table, baraja &b);

//PRE={Correcto funcionamitno de los modulos del TadBaraja y el TadCarta}
//POST={Inicia el tablero juego}
//O(n^2)
void iniciarTableroAjustado(tablero &Table, baraja &b, int columnas);

//PRE={Tablero iniciado correctamente}
//POST={Añade una columa más al tablero}
//O(n)
void sumarColumnas(tablero &tab, baraja &b);

//PRE={Tablero iniciado correctamente}
//POST={Devuelve el numero de columnas que hay en el tablero}
//O(1)
int obtenerColumnas(tablero Tab);

//PRE={Baraja iniciada correctamente}
//POST={Devuelve el numero de cartas que queda en la baraja}
//O()
int obtenerBaraja(baraja b);

//PRE={Tablero iniciado correctamente}
//POST={Devuelve una carta concreta del tablero}
//O(1)
carta obtenerCarta(tablero Tab, int fila, int columna);

//PRE={Tablero iniciado correctamente y correcto funcionamento del modulo obtenerNumero del TADCarta}
//POST={Devuelve el numero de una carta concreta del tablero}
//O(1)
int obtenerNumeroTab(tablero Tab, int fila, int columna);

//PRE={Tablero iniciado correctamente y correcto funcionamento del modulo obtenerForma del TADCarta}
//POST={Devuelve la forma de una carta concreta del tablero}
//O(1)
int obtenerFormaTab(tablero Tab, int fila, int columna);

//PRE={Tablero iniciado correctamente y correcto funcionamento del modulo obtenerColor del TADCarta}
//POST={Devuelve el color de una carta concreta del tablero}
//O(1)
int obtenerColorTab(tablero Tab, int fila, int columna);

//PRE={Tablero iniciado correctamente y correcto funcionamento del modulo obtenerRelleno del TADCarta}
//POST={Devuelve el relleno de una carta concreta del tablero}
//O(1)
int obtenerRellenoTab(tablero Tab, int fila, int columna);

//PRE={Tablero iniciado correctamente}
//POST={Devuelve si una carta esta seleccionada o no}
//O(1)
bool estaSeleccionada(tablero Tab, int fila, int columna);

//PRE={Tablero iniciado correctamente}
//POST={Selecciona una carta si esta seleccionada y viceversa}
//O(1)
void seleccionarCarta(tablero &Tab, int fila, int columna);

//PRE={Tablero iniciado correctamente y buen funcionamiento del modulo quitarCarta del TADBaraja}
//POST={Sustituye una carta por otra nueva de la baraja}
//O(1)
void sustituirCarta(tablero &Tab, baraja &b, int fila, int columna);

//PRE={Tablero iniciado correctamente y buen funcionamiento del modulo crearCarta del TADCarta}
//POST={Borra una carta (Pone todas sus caracteristicas a -1)}
//O(1)
void borrarCarta(tablero &Tab, int fila, int columna);

//PRE={Tablero iniciado correctamente}
//POST={Devuelve las caracteristicas de las cartas selecionadas en el tablero}
//O(n^2)
void matrizCondiciones(tablero Tab, mCondiciones &Condiciones);

//PRE={Tablero iniciado correctamente y buen funcionamiento de los modulos del TADTablero}
//POST={Devuelce si 3 cartas selecionadas forman un set}
//O(n)
bool comprobarSet(mCondiciones);

//PRE={Tablero iniciado correctamente y buen funcionamiento de los modulos del TADTablero}
//POST={Devuelce si 3 cartas selecionadas forman un set y las deseleciona}
//O(n^2)
bool formanSet(tablero &Tab);

//PRE={Tablero iniciado correctamente y buen funcionamiento de los modulos del TADTablero}
//POST={Busca de manera automatica un set en el tablero y devuelve true si lo encuentra y false si no lo haceº}
//O(n^6)
bool buscarSett(tablero tab, posicion &filas, posicion &columnas);

#endif /* TADTABLERO_H_ */
