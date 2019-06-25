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

int mezcla(std::vector<int> &v, int ini, int fin, int mitad){
	int cont = 0;
	int i = ini, j = mitad + 1;
	std::vector<int>sol(v.size());
	for (int k = 0; k <= fin; k++) {
		sol[k] = v[k];
	}

	int k = 0;

	while (i <= mitad && j <= fin) {
		if (sol[i] <= sol[j]) {
			v[k] = sol[i];
			i = i + 1;
			k = k + 1;
		}
		else {
			v[k] = sol[j];
			j = j + 1;
			k = k + 1;
		}
	}

		while (i <=mitad) { // copio elementos pendientes de la parte izquierda
			v[k] = sol[i];
			i = i + 1;
			k = k + 1;
			cont += 1;
		}

		while (j<= fin) { // copio elementos pendientes de la parte derecha
			v[k] = sol[j];
			j = j + 1;
			k = k + 1;
			cont += 1;
		}
		sol.clear();

		return cont;
}


int resolver(std::vector<int> &v, int ini, int fin, int &ac) {
	
	if (ini <= fin){
		int mitad = (ini + fin) / 2;
		resolver(v, ini, mitad-1, ac);
		resolver(v, mitad+1, fin, ac);
		ac+= mezcla(v, ini, fin, mitad);
	}
	return ac;
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
		int ac = 0;
		std::vector<int>v(n);
		

		for (int i = 0; i < v.size(); i++)
			std::cin >> v[i];

		n = resolver(v, 0, v.size()-1, ac);
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