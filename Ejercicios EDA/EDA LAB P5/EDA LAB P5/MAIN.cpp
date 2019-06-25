#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <sstream>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso(std::string cadena) {
	bool ok = true;
	int i = 0;

	/*max = cadena.at(0);*/
	while (ok && i < cadena.size()-1) {
		if (cadena.at(i) < cadena.at(i + 1))
		i++;
		else  ok = false;
	}

	if (ok)
		std::cout << "SI" << '\n';
	else std::cout << "NO" << '\n';

}

int main() {

	#ifndef DOMJUDGE
		std::ifstream in("//psf/Home/Desktop/EDA LAB P5/EDA LAB P5/prueba.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
	#endif 
		std::string cadena;

		std::cin >> cadena;
		while (cadena != "XXX") {
			resuelveCaso(cadena);
			std::cin >> cadena;
		}




	#ifndef DOMJUDGE 
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}