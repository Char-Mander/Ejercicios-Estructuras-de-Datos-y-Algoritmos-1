// Grupo E29,Laura Jiménez Fernández
/* Comentario general sobre la solución, explicando cómo se resuelve el problema*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>



// función que resuelve el problema
/* comentario sobre el coste, O(f(N)) */

void resolver(const std::vector<std::vector<int>> &matriz, int franja, int contf, int contc, int &sol) {
	int suma = 0, aux = 0;

	for (int f = contf; f < (franja+contf); f++) {
		for (int c = contc; c < (franja + contc); c++)
			suma += matriz[f][c];
	}

	if (sol < suma)
		sol = suma;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	int mat, franja, sol = 0, contf = 0, contc = 0, n;
	// leer los datos de la entrada
	std::cin >> mat;
	if (!std::cin)
		return false;
	else {
		std::cin >> franja;
		std::vector<std::vector<int>>matriz(mat, std::vector<int>(mat));
		for (int i = 0; i < matriz.size(); i++) {
			for (int j = 0; j < matriz.size(); j++)
				std::cin >> matriz[i][j];
		}
		while(contf+(franja-1)<matriz.size()) {
			resolver(matriz, franja, contf, contc, sol);
			if ((contc + 1) + (franja - 1) == matriz.size()) {
				contc = 0;
				contf++;
			}
			else contc++;
		}
		std::cout << sol << '\n';

		// escribir sol
		return true;
	}

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB ZZ2/EDA LAB ZZ2/prueba.txt");
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