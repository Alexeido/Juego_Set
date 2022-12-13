//============================================================================
// Name        : Main.cpp
// Author      : Alexeido & Lete
// Version     : curso 21/22
// Copyright   : L.Koos
// Description : Proyecto base para el juego SetGame
//============================================================================

#include "entorno.h"
#include "TADCarta.h"
#include "TADBaraja.h"
#include "TADTablero.h"
#include "TADJuego.h"
#include "Pruebas_TADCarta.h"
#include "Pruebas_TADBaraja.h"
#include "Pruebas_TADTablero.h"
#include <ctime>

int main() {
	pruebasTADCarta();
	pruebasTADBaraja();
	PruebasTADTablero();
	iniciarJuego();

	//visualizarJuego();
	return 0;
}
