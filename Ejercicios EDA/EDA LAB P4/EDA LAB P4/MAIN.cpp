//Grupo E, Laura Jiménez Fernández
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

//mientras que resolver() devuelva true, irá cogiendo datos del vector (que se va creando a medida que
//coge nuevos elementos del vector, hasta llegar a 0) 
//Tras haber cogido todos los datos, va multiplicando (pisando los valores del vector) el valor de v[i], menos el anterior
//(en v[0] se deja como está)


bool resolver() {
	int n;
	std::cin >> n;
	if (n == 0)
		return false;
	else {
		std::vector<int>v;
		while(n != 0) {
			v.push_back(n);
			std::cin >> n;
		}
		std::cout << v[0] << " ";
		for (int i = 1; i < v.size(); i++) {
			v[i] = v[i - 1] + v[i];
			std::cout << v[i] << " ";
		}
		std::cout << '\n';

		return true;
	}
	
}


int main() {

	#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/EDA LAB P4/EDA LAB P4/prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif 
	while (resolver())
		;
	#ifndef DOMJUDGE 
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}
