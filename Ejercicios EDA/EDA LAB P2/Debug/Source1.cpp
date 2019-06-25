// Grupo E, Laura Jiménez Fernández
// Se pasarán los datos a un vector, y después se recorrerá
//según las indicaciones dadas (n tiene que ser mayor que 0 y 
//menor que 10000, p tiene que ser >= 0 y <n, etc)
//si el archivo no tiene los datos correctos, devolverá "no" 
//Si cumplen las condiciones, se recorrerá el vector por la parte "u" y por la parte "w",
//comprobando si u (>=0 y <p) es menor que w(>=p, y <n). En el caso de que todos los u sean menor que los w 
//cumplen esas condiciones, devolverá true.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

typedef struct {
	int n, p;
}tVector;

// función que resuelve el problema

bool resolver(const tVector &datos) {
std::vector<int> v(datos.n);
int max;
int w = datos.p + 1;
bool ok=true;

	for (int i = 0; i < datos.n; i++) {
		std::cin >> v[i];
	}
		
			max = v[0];
			for (int u = 1; u <= datos.p; u++) {
				if (max < v[u])
					max = v[u];
			}

			while(w<datos.n && ok==true){
				if (v[w] <= max)
					ok = false;
				w++;
			}
		
	
	return ok;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	tVector datos;

	std::cin >> datos.n;
	std::cin >> datos.p;
		

	
		switch (resolver(datos)) {
		case true: std::cout << "SI" << '\n'; break;
		case false: std::cout << "NO" << '\n'; break;
		}


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/EDA LAB P2/EDA LAB P2/02EntradaEjemplo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;

	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}