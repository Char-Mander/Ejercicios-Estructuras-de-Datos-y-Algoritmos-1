//Grupo E29, laura Jim�nez Fern�ndez
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

/*En la funci�n resolver, primero se comprueba que ini sea mayor que fin (i > j). Si no lo es, n ser� v[j]+1. Si lo es, y la mitad ((j+i)/2) m�s el n�mero
por el que comienza el vector es igual a v[mitad], se coge la segunda mitad. Si no, se coge la primera mitad, y de esta forma se va reduciendo el vector..*/


/* Tiene coste logar�tmico, (O(lgn)), ya que va recorriendo mitades de mitades (el vector se reduce) */

int resolver(std::vector<int> const &v,int i, int j, int comienzo) {
	int n, mitad = (j + i) / 2;

	if (i > j)
		n = v[j] + 1;
	else if (mitad + comienzo == v[mitad]) {
		n = resolver(v, mitad+1, j, comienzo);
	}
	else if (mitad + comienzo != v[mitad])
		n = resolver(v, i, mitad-1, comienzo);
	return n;
}

void resuelveCaso() {
	int p, ini, fin, mitad;
	std::cin >> ini >> fin;
	std::vector<int> v(fin-ini);

	if (v.size() <= 2) {
		mitad = (fin - (ini + 1));
		if (mitad % 2 != 0)
			mitad = (mitad / 2) + 1;
		else mitad = mitad / 2;
	}
	else mitad = (fin - (ini + 1)) / 2;
	
	for (int i = 0; i < v.size(); i++)
		std::cin >> v[i];

	if (v[0] != ini)
		p = ini;
	else if (v[v.size() - 1] != fin)
		p = fin;
	else p = resolver(v, 0, v.size(), ini);


	std::cout << p << '\n';

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y m�s/Universidad/2� E/EDA - 2� E/Ejercicios EDA/EDA LAB P22/EDA LAB P22/prueba.txt");
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