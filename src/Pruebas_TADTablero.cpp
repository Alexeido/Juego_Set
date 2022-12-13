/*
 * Pruebas_TADTablero.cpp
 *
 *  Created on: 5 ene 2022
 *      Author: alexeido
 */
#include "Pruebas_TADTablero.h"
#include <iostream>
using namespace std;

void PruebasIniciarTablero() {
	srand(time(NULL));
	tablero tab;
	baraja b;
	bool error;
	int i, j, f, c;
	error=false;
	iniciarBaraja(b);
	iniciarTablero(tab, b);
	for (f = 0; f < MAXFILAS && !error; f++) {
		for (c = 0; c < tab.columnas && !error; c++) {
			for (j = 0; j < MAXFILAS && !error; j++) {
				for (i = 0; i < tab.columnas && !error; i++) {
					if (c != i || f != j) {
						if (obtenerForma(tab.mTablero[c][f])== obtenerForma(tab.mTablero[i][j])
								&& obtenerColor(tab.mTablero[c][f])
										== obtenerColor(tab.mTablero[i][j])
								&& obtenerNumero(tab.mTablero[c][f])
										== obtenerNumero(tab.mTablero[i][j])
								&& obtenerRelleno(tab.mTablero[c][f])
										== obtenerRelleno(tab.mTablero[i][j])) {
							error = true;
							cout<<f<<" "<<c<<endl<<j<<" "<<i<<endl;
						}
					}

				}
			}
		}
	}
	if (error) {
		cout << "Error en el modulo Iniciar Tablero" << endl;
	}

}

void PruebasIniciarTableroAjustado() {
	srand(time(NULL));
	int fallos;
	int col;
	tablero tab;
	baraja b;
	bool error;
	int i, j, f, c;
	fallos=0;
	for(col=3; col<6;col++){
		error=false;
	iniciarBaraja(b);
	iniciarTableroAjustado(tab, b, col);
	for (f = 0; f < MAXFILAS && !error; f++) {
		for (c = 0; c < tab.columnas && !error; c++) {
			for (j = 0; j < MAXFILAS && !error; j++) {
				for (i = 0; i < tab.columnas && !error; i++) {
					if (c != i || f != j) {
						if (obtenerForma(tab.mTablero[c][f])== obtenerForma(tab.mTablero[i][j])
								&& obtenerColor(tab.mTablero[c][f])
										== obtenerColor(tab.mTablero[i][j])
								&& obtenerNumero(tab.mTablero[c][f])
										== obtenerNumero(tab.mTablero[i][j])
								&& obtenerRelleno(tab.mTablero[c][f])
										== obtenerRelleno(tab.mTablero[i][j])) {
							error=true;
							mostrarCarta(obtenerCarta(tab,f,c));
							mostrarCarta(obtenerCarta(tab,j,i));
							fallos++;
						}
					}

				}
			}
		}
	}


}
	if (fallos>0) {
		cout << "Error en el modulo Iniciar Tablero Ajustado, Codigo de error: "<< fallos << endl;
	}
}

void PruebasObtenerColumnas() {
		int col;
		tablero tab;
		baraja b;
		bool error;
		error=false;
		for(col=3; col<6 && !error;col++){
			iniciarBaraja(b);
			iniciarTableroAjustado(tab,b,col);
			if(obtenerColumnas(tab)!=col){
				error=true;
			}
		}
		if(error){
			cout<<"Error en el modulo Obtener Columnas"<<endl;
		}
}

void PruebasObtenerBaraja() {
	int col;
	tablero tab;
	baraja b;
	bool error;
	error=false;
	for(col=3; col<6 && !error;col++){
		iniciarBaraja(b);
		iniciarTableroAjustado(tab,b,col);
		if(obtenerBaraja(b)!=81-(col*MAXFILAS)){
			error=true;
		}
	}
	if(error){
		cout<<"Error en el modulo Obtener Baraja"<<endl;
	}
}

void PruebasObtenerCarta() {
	tablero tab;
	baraja b;
	int f, c;
	bool error;
	error=false;
	iniciarBaraja(b);
	iniciarTablero(tab,b);
	for (f = 0; f < MAXFILAS && !error; f++) {
			for (c = 0; c < tab.columnas && !error; c++) {
			}
	}
	if(error){
		cout<<"Error en el modulo Obtener Carta"<<endl;
	}
}

void PruebasObtenerNumeroTab() {
	tablero tab;
	baraja b;
	int f, c;
	bool error;
	error=false;
	iniciarBaraja(b);
	iniciarTablero(tab,b);
	for (f = 0; f < MAXFILAS && !error; f++) {
		for (c = 0; c < tab.columnas && !error; c++) {
			if(obtenerNumeroTab(tab,f,c) != tab.mTablero[c][f].numero){
			error=true;
			}
		}
	}
	if(error){
		cout<<"Error en el modulo Obtener Numero"<<endl;
	}
}

void PruebasObtenerFormaTab() {
	tablero tab;
	baraja b;
	int f, c;
	bool error;
	error=false;
	iniciarBaraja(b);
	iniciarTablero(tab,b);
	for (f = 0; f < MAXFILAS && !error; f++) {
			for (c = 0; c < tab.columnas && !error; c++) {
				if(obtenerFormaTab(tab,f,c) != tab.mTablero[c][f].forma){
					error=true;
				}
			}
	}
	if(error){
		cout<<"Error en el modulo Obtener Forma"<<endl;
	}
}

void PruebasObtenerColorTab() {
	tablero tab;
	baraja b;
	int f, c;
	bool error;
	error=false;
	iniciarBaraja(b);
	iniciarTablero(tab,b);
	for (f = 0; f < MAXFILAS && !error; f++) {
			for (c = 0; c < tab.columnas && !error; c++) {
				if(obtenerColorTab(tab,f,c) != tab.mTablero[c][f].color){
					error=true;
				}
			}
	}
	if(error){
		cout<<"Error en el modulo Obtener Color"<<endl;
	}
}

void PruebasObtenerRellenoTab() {
	tablero tab;
	baraja b;
	int f, c;
	bool error;
	error=false;
	iniciarBaraja(b);
	iniciarTablero(tab,b);
	for (f = 0; f < MAXFILAS && !error; f++) {
			for (c = 0; c < tab.columnas && !error; c++) {
				if(obtenerRellenoTab(tab,f,c) != tab.mTablero[c][f].relleno){
					error=true;
				}
			}
	}
	if(error){
		cout<<"Error en el modulo Obtener Relleno"<<endl;
	}
}

void PruebasEstaSeleccionada() {
	tablero tab;
	baraja b;
	int f, c;
	bool error;
	error=false;
	iniciarBaraja(b);
	iniciarTablero(tab,b);
	for (f = 0; f < MAXFILAS && !error; f++) {
		for (c = 0; c < tab.columnas && !error; c++) {
			if(estaSeleccionada(tab, f, c)){
				error=true;
			}
			if(f==c){
				tab.selected[c][f] = true;
			}
		}
	}
	for (f = 0; f < MAXFILAS && !error; f++) {
		for (c = 0; c < tab.columnas && !error; c++) {
			if((f==c&&(!estaSeleccionada(tab, f, c)))||(f!=c&&(estaSeleccionada(tab, f, c)))){
				error=true;
			}
		}
	}
	if(error){
		cout<<"Error en el modulo Esta Seleccionada"<<endl;
	}
}

void PruebasSeleccionarCarta() {
	tablero tab;
	baraja b;
	int f, c;
	bool error;
	error=false;
	iniciarBaraja(b);
	iniciarTablero(tab,b);
	for (f = 0; f < MAXFILAS && !error; f++) {
		for (c = 0; c < tab.columnas && !error; c++) {
			if(f==c){
				seleccionarCarta(tab, f, c);
			}
			if((f==c&&(!tab.selected[c][f]))||(f!=c&&(tab.selected[c][f]))){
				error=true;
			}
			if(f==c){
				seleccionarCarta(tab, f, c);
			}
			if(tab.selected[c][f]){
				error=true;
			}
		}
	}
	if(error){
		cout<<"Error en el modulo Seleccionar Carta"<<endl;
	}
}

void PruebasSustituirCarta() {
	tablero tab;
	baraja b;
	int f, c;
	int mazo;
	carta aux;
	bool error;
	error=false;
	iniciarBaraja(b);
	iniciarTablero(tab,b);
	for (f = 0; f < MAXFILAS && !error; f++) {
		for (c = 0; c < tab.columnas && !error; c++) {
			mazo=obtenerBaraja(b);
			aux=obtenerCarta(tab, f, c);
			sustituirCarta(tab,b, f, c);
			if(obtenerBaraja(b)==mazo){
				error=true;
			}
			if(obtenerCarta(tab,f,c).numero == aux.numero&&obtenerCarta(tab,f,c).forma == aux.forma&&obtenerCarta(tab,f,c).color == aux.color&&obtenerCarta(tab,f,c).relleno == aux.relleno){
				error=true;
			}
		}
	}
	if(error){
		cout<<"Error en el modulo Sustituir Carta"<<endl;
	}
}


void PruebasFormanSet() {
	tablero tab;
	baraja b;
	int f1, c1, f2, c2, f3, c3;
	bool enc;
	iniciarBaraja(b);
	iniciarTablero(tab,b);
	enc = false;


	cout<<endl<<"Ahora aparecera en pantalla un Set, y cada fila es una carta, confirma si es correcto"<<endl<<"Numero - Forma - Color - Relleno"<<endl;

		for (f1 = 0; f1 < MAXFILAS && !enc; f1++) {
			for (c1 = 0; c1 < obtenerColumnas(tab) && !enc; c1++) {
				for (f2 = 0; f2 < MAXFILAS && !enc; f2++) {
					for (c2 = 0; c2 < obtenerColumnas(tab) && !enc; c2++) {
						for (f3 = 0; f3 < MAXFILAS && !enc; f3++) {
							for (c3 = 0; c3 < obtenerColumnas(tab) && !enc;
									c3++) {
								if ((f1 != f2 || c1 != c2) && (f2 != f3 || c2 != c3)
										&& (f3 != f1 || c3 != c1)) {
									seleccionarCarta(tab, f1, c1);
									seleccionarCarta(tab, f2, c2);
									seleccionarCarta(tab, f3, c3);
									if (formanSet(tab)) {
										enc = true;
										mostrarCarta(tab.mTablero[c1][f1]);
										mostrarCarta(tab.mTablero[c2][f2]);
										mostrarCarta(tab.mTablero[c3][f3]);


									}
								}
							}

						}

					}
				}
			}
		}
		cout<<endl<<"Fin del modulo Forman Set"<<endl<<endl;
}

void PruebasTADTablero() {
	cout<<"----Iniciando modulo de pruebas del TADTablero ----"<<endl;
	PruebasIniciarTablero();
	PruebasIniciarTableroAjustado();
	PruebasObtenerColumnas();
	PruebasObtenerBaraja();
	PruebasObtenerCarta();
	PruebasObtenerNumeroTab();
	PruebasObtenerFormaTab();
	PruebasObtenerColorTab();
	PruebasObtenerRellenoTab();
	PruebasEstaSeleccionada();
	PruebasSeleccionarCarta();
	PruebasSustituirCarta();
	PruebasFormanSet();
	cout<<"----Modulo de pruebas del TADTablero Finalizado----"<<endl;
}

