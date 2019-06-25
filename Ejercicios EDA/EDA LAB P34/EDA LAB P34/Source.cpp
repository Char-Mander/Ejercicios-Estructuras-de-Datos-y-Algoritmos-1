// Grupo E29,Laura Jiménez Fernández
/* Comentario general sobre la solución, explicando co´mo se resuelve el problema*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>


typedef struct {
	int fila;
	int columna;
}Tpos;
// función que resuelve el problema
/* comentario sobre el coste, O(f(N)) */


Tpos siguiente(const Tpos actual, int i) {
	Tpos posicion;

	switch (i) {
		//se mueve a la derecha
	case 1: posicion.fila = actual.fila; 
		posicion.columna = actual.columna + 1;
		break;
		//se mueve a la izquierda 
	case 2: posicion.fila = actual.fila;
		posicion.columna = actual.columna - 1;
		break;
		//se mueve hacia arriba
	case 3: posicion.fila = actual.fila - 1;
		posicion.columna = actual.columna;
		break;
		//se mueve hacia abajo
	case 4: posicion.fila = actual.fila + 1;
		posicion.columna = actual.columna;
		break;
	}

	return posicion;
}

bool casilla_valida(const std::vector<std::vector<int>> &matriz, std::vector<std::vector<bool>> &usadas, 
	const Tpos pos, const Tpos posAnterior, int max) {
	bool ok = (pos.fila > 0 && pos.fila < matriz.size() && pos.columna >0 && pos.columna < matriz[0].size() &&
		!usadas[pos.fila][pos.columna] && abs(matriz[pos.fila][pos.columna] - matriz[posAnterior.fila][posAnterior.columna]) <= max);

	return ok;
}

bool resolver(const std::vector<std::vector<int>> &matriz, std::vector<std::vector<bool>> &usadas, 
	int &num_mov, int k, std::vector<Tpos> &sol, const Tpos pos_fin, int max) {
	bool fin = false;

	Tpos pos, aux;
	for (int i = 1; i < matriz.size(); i++) {
		aux = sol[k - 1];
		pos = siguiente(sol[k - 1], i);
		if (casilla_valida(matriz, usadas, pos, aux, max)) {
			sol[k] = pos;
			usadas[pos.fila][pos.columna] = true; //marcaje
			num_mov++;
			if (num_mov < num_mov) {
				if (pos.fila == pos_fin.fila && pos.columna == pos_fin.columna) fin = true;
				else resolver(matriz, usadas, num_mov, k + 1, sol, pos_fin, max);
			}
			usadas[pos.fila][pos.columna] = false; //se desmarca
				num_mov--;
		}
	}

	return fin;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	int n;
	// leer los datos de la entrada
	std::cin >> n;
	if (!std::cin)
		return false;
	else {
		int max, filcom, colcom, filfin, colfin;
		bool ok;
		
		std::cin >> max >> filcom >> colcom >> filfin >> colfin;

		std::vector<std::vector<int>> matriz(n, std::vector<int>(n));
		std::vector<std::vector<bool>> usadas(n, std::vector<bool>(n));
		std::vector<Tpos> sol(n*n);
		Tpos aux;
		aux.fila = filcom;
		aux.columna = colcom;
		sol[0] = aux;

		aux.fila = filfin;
		aux.columna = colfin;
		

		for (int i = 0; i < matriz.size(); i++) {
			for (int j = 0; j < matriz[0].size(); j++) {
				std::cin >> matriz[i][j];
			}

			int num_mov = n*n;
			ok=resolver(matriz, usadas, num_mov, 1, sol, aux, max);

			if (ok) std::cout << num_mov;
			else std::cout << "NO";
			std::cout<<'\n';

		}


		return true;
	}
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P34/EDA LAB P34/prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}