/*
 * TADJuego.cpp
 *
 *  Created on: 10 dic 2021
 *      Author: Alexeido & Lete
 */
#include "TADJuego.h"
#include "entorno.h"
#include "TADTablero.h"

void resaltarSett(posicion filas, posicion columnas) {
	int i;
	for (i = 2; i >= 0; i--) {
		entornoSeleccionarCarta(filas[i], columnas[i]);
	}
	entornoPausa(2);
	for (i = 2; i >= 0; i--) {

		entornoDeseleccionarCarta(filas[i], columnas[i]);
	}
}

void iniciarJuego() {
	juego sett;

	int numero, forma, color, relleno; //características de las cartas
	iniciarBaraja(sett.b);

	int n; //número de columnas de 3 cartas con las que se iniciará el juego, valores permitidos 3,4,5
	int pc;	//número de puntos que se sumarán cada vez que el usuario compile un SET (> 0)
	int p;		//número de puntos que debe lograr el usuario para ganar (> 0)
	int pa;		//número de puntos mínimos para poder solicitar la ayuda (>= 0)

	srand((time(NULL)));

	if (entornoCargarConfiguracion(n, pc, p, pa)) { //se obtienen, del fichero de configuración, valores necesarios para el juego
		entornoIniciar(n);

		iniciarTableroAjustado(sett.tab, sett.b, n);

		for (int i = 0; i < MAXFILAS; i++)
			for (int j = 0; j < n; j++) {
				numero = obtenerNumeroTab(sett.tab, i, j);
				forma = obtenerFormaTab(sett.tab, i, j);
				color = obtenerColorTab(sett.tab, i, j);
				relleno = obtenerRellenoTab(sett.tab, i, j);
				entornoPintarCarta(i, j, numero, forma, color, relleno);
			}
	}
	jugarJuego(sett, n, pc, p, pa);

}

void jugarJuego(juego sett, int n, int pc, int p, int pa) {
	string msg;
	bool columna_disp, encontrar_disp;
	int forma, color, numero, relleno;
	int num_filas;
	posicion seleccionFila, seleccionColumna;
	bool salir = false;
	int cartas_disponibles;
	int i;
	TipoTecla tecla;
	int seleccionadas;
	int fila_act, col_act;   //coordenadas de la carta actual en el tablero
	posicion filas, columnas;
	columna_disp = true;
	encontrar_disp = true;
	seleccionadas = 0;
	num_filas = MAXFILAS;
	fila_act = 0;
	col_act = 0;
	entornoMarcarCarta(fila_act, col_act);
	sett.puntos = 0;
	cartas_disponibles = obtenerBaraja(sett.b);
	entornoPonerPuntuacion(sett.puntos);
	entornoPonerDisponibles(cartas_disponibles);
	entornoMostrarMensaje("Pulsa ENTER para seleccionar la carta", 2);

	while (!salir) {
		//A partir de este momento se procesan las teclas que pulse el jugador:
		//Si se pulsan las teclas arriba o abajo el cursor se desplaza en vertical por el tablero;
		//Si se pulsa la tecla Enter se selecciona la carta sobre la que está el cursor durante
		//dos segundos, se decrementa en 1 el número de cartas disponibles y se incrementa la
		//puntuación con los puntos indicados en el fichero de configuración
		tecla = entornoLeerTecla();
		switch (tecla) {
		case TEnter:

			if (obtenerFormaTab((sett.tab), fila_act, col_act) != -1) {
				if (estaSeleccionada(sett.tab, fila_act, col_act)) {
					juegoDeseleccionarCarta(sett, fila_act, col_act,
							seleccionadas, seleccionFila, seleccionColumna);

				} else {
					if (juegoSeleccionarCarta(sett, fila_act, col_act,
							seleccionadas, seleccionFila, seleccionColumna)) {
						cartas_disponibles = obtenerBaraja(sett.b);
						sett.puntos = sett.puntos + pc;
						entornoPonerPuntuacion(sett.puntos);
						entornoPonerDisponibles(cartas_disponibles);
					}
				}

				if (p <= sett.puntos) {
					finalizarJuego();
				}
			}
			break;
		case TDerecha:
			entornoDesmarcarCarta(fila_act, col_act);
			if (col_act < n - 1)
				col_act++;
			else
				col_act = 0;
			entornoMarcarCarta(fila_act, col_act);
			break;
		case TIzquierda:
			entornoDesmarcarCarta(fila_act, col_act);
			if (col_act > 0)
				col_act--;
			else
				col_act = n - 1;
			entornoMarcarCarta(fila_act, col_act);
			break;
		case TArriba:
			entornoDesmarcarCarta(fila_act, col_act);
			if (fila_act > 0)
				fila_act--;
			else
				fila_act = num_filas - 1;
			entornoMarcarCarta(fila_act, col_act);
			break;
		case TAbajo:
			entornoDesmarcarCarta(fila_act, col_act);
			if (fila_act < num_filas - 1)
				fila_act++;
			else
				fila_act = 0;
			entornoMarcarCarta(fila_act, col_act);
			break;
		case TSalir:
			entornoMostrarMensajeFin(" Fin...  ");
			entornoPausa(0.75);
			entornoTerminar();
			salir = true;
			break;
		case TF1:

			if (columna_disp && sett.puntos >= pa) {
				sumarColumnas(sett.tab, sett.b);
				for (i = 0; i < MAXFILAS; i++) {
					if (obtenerNumeroTab(sett.tab, i,
							obtenerColumnas(sett.tab) - 1) != -1) {
						numero = obtenerNumeroTab(sett.tab, i,
								obtenerColumnas(sett.tab) - 1);
						forma = obtenerFormaTab(sett.tab, i,
								obtenerColumnas(sett.tab) - 1);
						color = obtenerColorTab(sett.tab, i,
								obtenerColumnas(sett.tab) - 1);
						relleno = obtenerRellenoTab(sett.tab, i,
								obtenerColumnas(sett.tab) - 1);
						entornoPintarCarta(i, obtenerColumnas(sett.tab) - 1,
								numero, forma, color, relleno);
					}
				}
				n = obtenerColumnas(sett.tab);
				columna_disp = false;
				sett.puntos = sett.puntos - pa;
				entornoPonerPuntuacion(sett.puntos);
				entornoPonerDisponibles(cartas_disponibles);
			}

			break;
		case TF2:

			if (encontrar_disp && sett.puntos >= pa) {
				encontrar_disp = false;
				if (buscarSett(sett.tab, filas, columnas)) {
					resaltarSett(filas, columnas);
					for (i = 0; i < seleccionadas; i++) {
						entornoSeleccionarCarta(seleccionFila[i],
								seleccionColumna[i]);
					}
				}

				sett.puntos = sett.puntos - pa;
				entornoPonerPuntuacion(sett.puntos);
			}
			break;
		case TNada:
			break;
		}
	}
}

void visualizarJuego() {
	juego sett;
	posicion filas;
	posicion columnas;
	int numero, forma, color, relleno; //características de las cartas
	bool automatizado;
	automatizado = true;
	iniciarBaraja(sett.b);

	int n; //número de columnas de 3 cartas con las que se iniciará el juego, valores permitidos 3,4,5
	int pc;	//número de puntos que se sumarán cada vez que el usuario compile un SET (> 0)
	int p;		//número de puntos que debe lograr el usuario para ganar (> 0)
	int pa;		//número de puntos mínimos para poder solicitar la ayuda (>= 0)

	srand((time(NULL)));

	if (entornoCargarConfiguracion(n, pc, p, pa)) { //se obtienen, del fichero de configuración, valores necesarios para el juego
		entornoIniciar(n);

		iniciarTableroAjustado(sett.tab, sett.b, n);


		for (int i = 0; i < MAXFILAS; i++)
			for (int j = 0; j < n; j++) {
				numero = obtenerNumeroTab(sett.tab, i, j);
				forma = obtenerFormaTab(sett.tab, i, j);
				color = obtenerColorTab(sett.tab, i, j);
				relleno = obtenerRellenoTab(sett.tab, i, j);
				entornoPintarCarta(i, j, numero, forma, color, relleno);
			}
	}
	sett.puntos=0;
	entornoPonerPuntuacion(sett.puntos);
	entornoPonerDisponibles(obtenerBaraja(sett.b));

	while (automatizado) {
		if (sett.puntos >= p) {
			automatizado = false;
		}
		if (buscarSett(sett.tab, filas, columnas)) {
			resaltarSett(filas, columnas);
			setEncontrado(sett, filas, columnas);
			sett.puntos = sett.puntos + pc;
		} else {
			automatizado = false;
		}
		entornoPonerPuntuacion(sett.puntos);
		entornoPonerDisponibles(obtenerBaraja(sett.b));
	}
	finalizarJuego();
}

void setEncontrado(juego &sett, posicion seleccionFila,
		posicion seleccionColumna) {
	int forma, color, numero, relleno;
	int i, j;

	for (j = 0; j < 2; j++) {
		entornoPausa(0.25);
		for (i = 2; i >= 0; i--) {

			entornoDeseleccionarCarta(seleccionFila[i], seleccionColumna[i]);
		}
		entornoPausa(0.25);
		for (i = 2; i >= 0; i--) {
			entornoSeleccionarCarta(seleccionFila[i], seleccionColumna[i]);
		}
	}
	for (i = 0; i < 3; i++) {
		entornoDeseleccionarCarta(seleccionFila[i], seleccionColumna[i]);
		if (obtenerBaraja(sett.b) > 0) {
			sustituirCarta(sett.tab, sett.b, seleccionFila[i],
					seleccionColumna[i]);
			numero = obtenerNumeroTab(sett.tab, seleccionFila[i],
					seleccionColumna[i]);
			forma = obtenerFormaTab(sett.tab, seleccionFila[i],
					seleccionColumna[i]);
			color = obtenerColorTab(sett.tab, seleccionFila[i],
					seleccionColumna[i]);
			relleno = obtenerRellenoTab(sett.tab, seleccionFila[i],
					seleccionColumna[i]);
			entornoPintarCarta(seleccionFila[i], seleccionColumna[i], numero,
					forma, color, relleno);
		} else {
			entornoBorrarCarta(seleccionFila[i], seleccionColumna[i]);
			borrarCarta(sett.tab, seleccionFila[i], seleccionColumna[i]);
		}
	}
}

void juegoDeseleccionarCarta(juego &sett, int fila_act, int col_act,
		int &seleccionadas, posicion &seleccionFila,
		posicion &seleccionColumna) {
	bool enc;
	int i;
	enc = false;
	entornoDeseleccionarCarta(fila_act, col_act);
	seleccionarCarta(sett.tab, fila_act, col_act);
	for (i = 0; i < seleccionadas && !enc; i++) {
		if (seleccionFila[i] == fila_act && seleccionColumna[i] == col_act) {
			seleccionFila[i] = seleccionFila[seleccionadas - 1];
			seleccionColumna[i] = seleccionColumna[seleccionadas - 1];
			enc = true;
		}
	}
	seleccionadas--;
}

bool juegoSeleccionarCarta(juego &sett, int fila_act, int col_act,
		int &seleccionadas, posicion &seleccionFila,
		posicion &seleccionColumna) {
	int i;
	bool enc;
	enc = false;
	entornoSeleccionarCarta(fila_act, col_act);
	seleccionarCarta(sett.tab, fila_act, col_act);
	seleccionFila[seleccionadas] = fila_act;
	seleccionColumna[seleccionadas] = col_act;
	seleccionadas++;

	if (seleccionadas == 3) {
		if (formanSet(sett.tab)) {
			enc = true;
			entornoMostrarMensaje("Set encontrado!!!", 2);
			setEncontrado(sett, seleccionFila, seleccionColumna);
		} else {
			for (i = 2; i >= 0; i--) {
				entornoDeseleccionarCarta(seleccionFila[i],
						seleccionColumna[i]);
			}
		}
		seleccionadas = 0;
	}
	return enc;
}

void finalizarJuego() {
	entornoMostrarMensajeFin(" ¡Has ganado! :D");
	entornoPausa(0.75);
	entornoTerminar();
}
