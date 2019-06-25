// Grupo E29,Laura Jiménez Fernández
/*El caso base sería que ini fuera mayor o igual que fin; en ese caso, n sería el número que buscamos. Si no, se compara la posición mitad
con v[mitad+1] (para no salirnos de rango en el vector), y si v[mitad] es < que v[mitad+1], cogeremos la mitad de la izquierda.
En caso contrario, cogeremos la mitad de la derecha*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>



// función que resuelve el problema
/* comentario sobre el coste, O(f(logn)) 

		-c0			si ini<=fin
T(n)=
		-T(n/2)		si fin>ini
*/

int resolver(const std::vector<int> &v, int ini, int fin) {
	int n, mitad;

	if (fin <= ini) n = v[ini];
	else {
		mitad = (ini + fin) / 2;
		if (v[mitad] < v[mitad + 1]) n = resolver(v, ini, mitad);
		else n = resolver(v, mitad+1, fin);
	

	}
	return n;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	int n, sol;
	// leer los datos de la entrada
	std::cin >> n;
	if (!std::cin)
		return false;
	else {
		std::vector<int>v(n);
		for (int i = 0; i < n; i++)
			std::cin >> v[i];

		
		sol = resolver(v, 0, v.size()-1);
		std::cout << sol << '\n';
		return true;
	}
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P27/EDA LAB P27/prueba.txt");
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