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


/*
se coge la palabra como string, y después se va comprobando caracter a caracter si es mayor que el anterior
(se empieza desde el segundo caracter, y se termina en el último, para que los compare todos)
Se lleva un contador (se inicializa a 1) que aumentará cada vez que encuentre dos letras seguidas que cumplan 
las condiciones, y si el contador supera al max, (variable inicializada a 1, que es donde se guardará el mayor
número de letras seguidas) se pasa el valor de contador a max.
*/
void resuelveCaso(std::string cadena) {
	int max = 1, contador = 1;
	
	for (int i = 1; i < cadena.size(); i++) {
		if (cadena.at(i) > cadena.at(i-1)) {
			contador++;
			if(contador>max)
			max = contador;
		}
		else contador = 1;
	}


	std::cout << cadena.size() << " " << max << '\n';
	
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/EDA LAB P6/EDA LAB P6/prueba.txt");
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