// Grupo E29,Laura Jiménez Fernández
/* Comentario general sobre la solución, explicando co´mo se resuelve el problema*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>



// función que resuelve el problema
/* comentario sobre el coste, O(f(N)) */

int resolver(std::vector<int> &v, int ini, int fin) {
	int inv;
	if (fin <= ini) return 0;
	else {
		int mitad=(ini + fin)/ 2;
		int invIz = resolver(v, ini, mitad);
		int invDr = resolver(v, mitad + 1, fin);
		std::vector<int> aux(fin - ini);
		merge(v.begin() + ini, v.begin() + fin + 1, aux); //preguntar
		copy(aux.begin(), aux.end(), v.begin() + ini);
		return invIz + invDr + inv;

	}
}




// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	int n, pivote, ac = 0;
	// leer los datos de la entrada
	std::cin >> n;
	if (!std::cin)
		return false;
	else {
		std::vector<int>v(n);

		for (int i = 0; i < v.size(); i++)
			std::cin >> v[i];

		n = resolver(v, 0, v.size() - 1);
		std::cout << n << '\n';
		return true;
	}

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P29/EDA LAB P29/prueba.txt");
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