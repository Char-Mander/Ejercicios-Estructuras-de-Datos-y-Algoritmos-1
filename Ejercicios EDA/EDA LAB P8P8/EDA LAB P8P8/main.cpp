//Grupo E29, laura Jiménez Fernández
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

//Se declara primero p=0, y v[0] como max1 y max2. Se va recorriendo el vector desde 1 hasta v[v.size()-1]
//Primero se compara el v[i] con max, y si es mayor v[i], entonces max=v[i].
//Luego si max2 es mayor o igual que v[i], p estará en i, (ya que todos los de detrás serán menores o iguales)
// y max2=max1


//Es problema es de complejidad O(n), ya que tiene un único bucle for (que recorre n-1 veces) en la función que resuelve cada caso
//También hay condicionales metidos, que en el peor de los casos entrará en todos, es decir, n-1;


int resolver(std::vector<int> const &v) {
	int p = 0, max1 = v[0], max2 = v[0];
	
		for (int i = 1; i < v.size(); i++) {
			if (v[i] > max1)
				max1 = v[i];

			if (max2 >= v[i]) {
				p = i;
				max2 = max1;
			}
		}
	
	return p;
}

void resuelveCaso() {
	int n, p;
	std::cin >> n;
	std::vector<int> v(n);

	for (int i = 0; i < n; i++)
		std::cin >> v[i];


	p = resolver(v);
	std::cout << p << '\n';
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P8P8/EDA LAB P8P8/prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}