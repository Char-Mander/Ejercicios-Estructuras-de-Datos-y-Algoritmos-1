// Grupo E29,Laura Jiménez Fernández
/* En resolver, primero se hace la media de las diagonales inferiores y se guarda en la posición
correspondiente del vector auxiliar v. Después, se comprueba con un bucle cuántas posiciones seguidas
de v son >= que la cantidad que se trata.*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>



// función que resuelve el problema
/* Tiene un coste lineal (O(n)), ya que el resolver es un simple for que trata a los elementos del vector auxiliar una sola vez. (O(v.size()) */

int resolver(const std::vector<std::vector<int>> &matriz, int cantidad, int &ini, int &contador) {
	int f, cont = 0, max = 0, elems;
	std::vector<int>v(matriz.size());
	for (int i = 0; i <matriz.size(); i++) {
		elems = 0;
		f = (matriz.size() - 1);
		for (int j =(matriz.size()-1)-i; j >=0 &&f>= 0; j--) {
			v[i] += matriz[f][j];
			f--;
			elems++;
		}
		v[i] = v[i] / elems;
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i] >= cantidad) {
			cont++;
		}
		else cont = 0;

		if (cont == max)
			contador++;

		if (cont > max) {
			ini = (i - max);
			max = cont;
			contador = 1;
		}
	}
	return max;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	int n, cantidad;
	// leer los datos de la entrada
	std::cin >> n;
	if (!std::cin)
		return false;
	else {
		std::cin >> cantidad;
		std::vector<std::vector<int>>matriz(n, std::vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cin >> matriz[i][j];
			}
		}
		int ini = 0, contador = 0;
		n = resolver(matriz, cantidad, ini, contador);
		if (n == 0)std::cout << "NO" << '\n';
		else 	std::cout << n << " " << ini << " " << contador << '\n';
		// escribir sol


		return true;
	}
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P24/EDA LAB P24/prueba.txt");
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