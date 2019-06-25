// Grupo E29, Laura Jiménez Fernández
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>



// función que resuelve el problema
// comentario sobre el coste, O(f(N))
int resolver(std::vector <int> const &v, std::vector<int> const &w) {
	int n = 0, cont = 0, i = 0, j=0, numMax;
	while (cont != w.size()) {
		if(v[i]<v[w[j]])

	}

	return n;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int sol, numVectores;
	int cont = 0, i = 0, elementos;
	std::vector<int>v;

	std::cin >> numVectores;
	std::vector <int> w(numVectores);

	while (elementos!= 0 && cont != numVectores) {
		std::cin >> elementos;

		if (elementos != 0)
			v.push_back(elementos);
		else {
			w[cont] = v.size() - 1;
			v.push_back(elementos);
			cont++;
		}
	}

	sol = resolver(v, w);
	// escribir sol
	std::cout << sol << '\n';
	
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/isabel/Dropbox/XcodePrograms/Prueba/datos1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}
