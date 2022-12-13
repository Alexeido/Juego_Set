/*
 * Pruebas_TADTablero.h
 *
 *  Created on: 18 dic 2022
 *      Author: Alexeido & Lete
 */

#ifndef PRUEBAS_TADTABLERO_H_
#define PRUEBAS_TADTABLERO_H_
#include "TADTablero.h"
#include "Pruebas_TADCarta.h"

//Comprueba que el tablero se ha generado correctamente y que no haya ningúna carta repetida
void PruebasIniciarTablero();

//Comprueba que el tablero se ha generado correctamente, tanto el número de columnas
//como que la generación de cartas del tablero y que no haya ningúna repetida
void PruebasIniciarTableroAjustado();

//Comprueba que se obtiene correctamente el nº de colunmas que tiene el tablero
void PruebasObtenerColumnas();

//Comprueba que se obtiene correctamente el nº de cartas que quedan en la baraja
void PruebasObtenerBaraja();

//Comprueba que la carta que se obtiene de este modulo sea igual que la que queriamos obtener
void PruebasObtenerCarta();

//Comprueba que el numero de la carta que queremos obtener sea el correcto
void PruebasObtenerNumeroTab();

//Comprueba que la forma de la carta que queremos obtener sea el correcto
void PruebasObtenerFormaTab();

//Comprueba que el color de la carta que queremos obtener sea el correcto
void PruebasObtenerColorTab();

//Comprueba que el relleno de la carta que queremos obtener sea el correcto
void PruebasObtenerRellenoTab();

//Comprueba que se devuelva correctamente si esa carta esta seleccionada o no
void PruebasEstaSeleccionada();

//Comprueba que la carta se seleccione y deseleccione correctamente
void PruebasSeleccionarCarta();

//Comprueba que la carta se sustituya y se deseleccione correctamente
void PruebasSustituirCarta();

//Comprueba manuelmente si un set es correcto o no
void PruebasFormanSet();

//Une todos los modulos de prueba en una sola llamada
void PruebasTADTablero();

#endif /* PRUEBAS_TADTABLERO_H_ */
