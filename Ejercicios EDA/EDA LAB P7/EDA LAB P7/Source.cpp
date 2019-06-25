//Grupo E, Laura Jiménez Fernández

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <sstream>

/*
Primero coge el número de filas y de píxeles.
Posteriormente, se pasa a un vector los datos. Se recorre fila a fila, para ver si los píxeles son blancos ("FFFFFF").
En caso de que sea, (y el contador sea <numPixs, ya que el contador no puede ser mayor que el número de 
píxeles por fila). Cuando contador sea mayor que maxceros, maxceros tendrá el valor de contador (que es
donde se verá la mayor secuencia de ceros)
*/


void resolver(int pixeles) {
	int pixini = 0, pixfinal= -1, contador = 0, maxceros = 0;
	const std::string BLANCO = "FFFFFF";

	std::vector<std::string>v(pixeles);


	for (int i = 0; i < v.size(); i++) 
		std::cin >> v[i];

	for (int i = 0; i < pixeles; i++){
		if (v[i] == BLANCO)
			contador++;
		else contador = 0;
	
		if (contador > maxceros) {
			maxceros = contador;
			pixini = i - (maxceros-1);
			pixfinal = i;
		}
	}

	std::cout << pixini << " " << pixfinal << '\n';

}

bool resuelveCaso() {
	int numFilas, pixeles;

	std::cin >> numFilas;
	if (!std::cin)
		return false;
	else {
		std::cin >> pixeles;
		for (int i = 0; i < numFilas; i++)
			resolver(pixeles);
			return true;
	}
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P7/EDA LAB P7/prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 


	while (resuelveCaso())
		;
	


#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}

