//Grupo E, Laura Jiménez Fernández
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <sstream>


// Dado un número de casos, llama a la función resuelveCaso(), que cogerá los datos de cada caso
//y los pasará a un vector. Posteriormente, se recorre de nuevo el vector, comparando desde la segunda
//hasta la penúltima componente con el número anterior y posterior, para ver si es pico o valle. 
//se va acumulando en max o min (contadores) si es pico o valle, respectivamente

void resuelveCaso() {
	int numdatos, max=0, min=0;
	std::cin >> numdatos;
   	std::vector<int> v(numdatos);

	for (int i = 0; i < numdatos; i++)
		std::cin >> v[i];

	for (int i = 1; i < numdatos - 1; i++) {
		if (v[i] < v[i - 1] && v[i] < v[i + 1])
			min++;
		else if (v[i] > v[i - 1] && v[i] > v[i + 1])
			max++;
	}

	std::cout << max << " " << min << '\n';

}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/EDA LAB P3/EDA LAB P3/prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 
	int numCasos;

	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();




#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}