// Grupo E, Laura Jiménez Fernández 

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>



typedef struct {
	int componentesvector;
	int max;
	int veces;
}tDatos;

// función que resuelve el problema
/*Se procederá a pasar cada usuario a un vector (todas las puntuaciones del mismo usuario
estarán en el mismo vector. Mientras se van pasando elementos, también se van comparando;
se define el máximo como la primera puntuación del usuario, y si encuentra una puntuación
mayor, dicha puntuación será el nuevo máximo
*/

void resolver(const tDatos &datos) {
	int aux;
	/*std::cin >> datos.componentesvector;*/
	std::vector<int> v(datos.componentesvector);
	
	for (int i = 0; i < v.size(); i++) {
	std::cin >> aux;
		v[i] = aux;
	}

	datos.max = v[0];
	datos.veces = 1;
	for (int i = 1; i < datos.componentesvector; i++) {
		if (datos.max < v[i]) {
			datos.max = v[i];
			datos.veces = 1;
		}
		else if (datos.max == v[i])
			datos.veces++;
	}

	
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta (valor más alto, y número de veces que se repite)
void resuelveCaso() {
	// leer los datos de la entrada
	std::ifstream archivo;
	tDatos datos;
	
	
		std::cin >> datos.componentesvector;
			resolver(datos);

			std::cout << datos.max << " " << datos.veces << '\n';

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/datos1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;

	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
