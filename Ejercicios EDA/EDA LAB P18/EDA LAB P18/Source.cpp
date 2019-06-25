// Grupo E29,Laura Jiménez Fernández
/* En la función resolver, primero hacemos la diagonal superior. La recorremos desde el último número de la diagonal principal, 
de derecha a izquierda, y hacia arriba. Se va guardando cada diagonal en el vector diagonalSup. Después, se ponen las variables que usaremos
a 0 (para empezar desde la fila y columna 0), y hacemos algo muy parecido; para hallar los valores de la diagonal inferior; se recorre desde 
el primer número de la diagonal principal, de izquierda a derecha, y hacia abajo. Se guarda cada diagonal en el vector diagonalInf.*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>




/* Tiene un coste lineal, (O(n)) ya que en ambos bucles (diagonal superior, y diagonal inferior) se tratan los elementos una sola vez, guardando 
en un vector auxiliar el resultado.*/

void resolver(const std::vector<std::vector<int>> &matriz,  std::vector<int> &diagonalSup, std::vector<int> &diagonalInf) {
	int i = 0, col = matriz.size() - 1, fil = matriz.size() - 1, suma = 0, cont = 0;
	while (i < matriz.size()) {
		if (fil >= 0) {
			diagonalSup[i] += matriz[fil][col];
			fil--;
			col--;
		}
		else {
			cont++;
			i++;
			fil = (matriz.size() - 1) - cont;
			col = matriz.size() - 1;
		}
	}

	//Se ponen las variables a 0 para hacer la diagonal inferior
	i = 0;
	fil = 0;
	col = 0;
	cont = 0;
	while (i < matriz.size()) {
		if (fil <matriz.size()) {
			diagonalInf[i] += matriz[fil][col];
			fil++;
			col++;
		}
		else {
			cont++;
			i++;
			fil = cont;
			col = 0;
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n, f = 0, c = 0;
	// leer los datos de la entrada
	std::cin >> n;
	if (!std::cin)
		return false;
	else {
		std::vector<std::vector<int>> matriz(n, std::vector<int>(n));
		for (int i = 0; i < n*n; i++) {
			std::cin >> matriz[f][c];
			c++;
			if (c == matriz.size()) {
				c = 0;
				f++;
			}
		}
		std::vector<int>diagonalSup(n);
		std::vector<int>diagonalInf(n);
		resolver(matriz, diagonalSup, diagonalInf);
		
		for (int i = 0; i < diagonalSup.size(); i++)
			std::cout << diagonalSup[i] << " ";
			std::cout << '\n';
			for (int i = 0; i < diagonalInf.size(); i++)
				std::cout << diagonalInf[i] << " ";
			std::cout << '\n';
	}

	// escribir sol


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P18/EDA LAB P18/prueba.txt");
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