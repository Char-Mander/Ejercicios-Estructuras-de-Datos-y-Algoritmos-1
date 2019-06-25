// Grupo E29,Laura Jiménez Fernández
/* Si fin-ini==1 (será el caso base, en el que solo haya 2 elementos para comparar) se comprueba si el de v[ini] 
es menor que v[fin], se cumplirá el degradado, por lo que devolvemos true y acumulamos la suma de los elmentos 
que hemos comparado. Si no, devolvemos false.
Si no, se llama recursivamente a la mitad primera hasta llegar al caso base. (Y si llega y se cumple, se devuelve true, y 
se llama recursivamente a la segunda mitad, y si llega al caso base, y lo cumple, se acumulan los valores comparados en 
otro acumulador, y devuelve true. Si en algún momento no se llega a cumplir el degradado, devolvería false y saldría de la
recursividad.*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>



// función que resuelve el problema
/* comentario sobre el coste, O(logn)

		-c0, c1				cte
t(n) 
		-2 * t(n/2) 				
*/

bool resolver(const std::vector<int>&v, int ini, int fin, int &a1) {

	if (fin-ini == 1) {
		if (v[ini] >= v[fin]) return false;
		else {
			a1 = v[ini] + v[fin];
			return true;
		}
	}
	else {
		if (resolver(v, ini, (ini + fin) / 2, a1)) {
			int a2 = 0;
			if (resolver(v, ((ini + fin) / 2 + 1), fin, a2)) {

				if (a1 < a2) {
					a1 += a2;
					return true;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	int f, c, ac=0, cont = 0;
	bool sol=true;
	// leer los datos de la entrada
	std::cin >> f;
	if (!std::cin)
		return false;
	else {
	std::cin >> c;
		std::vector<std::vector<int>>matriz(f, std::vector<int>(c));
		for (int i = 0; i < f; i++) {
			for (int j = 0; j < c; j++) {
				std::cin >> matriz[i][j];
			}
		}


		if (matriz[0].size() > 1) {
			while (sol && cont < f) {
				sol = resolver(matriz[cont], 0, matriz[0].size() - 1, ac);
				cont++;
			}
		}
		if (sol) std::cout << "SI" << '\n';
		else std::cout << "NO" << '\n';
		return true;
	}

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P28/EDA LAB P28/prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
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