//Grupo E29, laura Jim�nez Fern�ndez
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>


//Al coger los datos del vector se busca el m�ximo. Despu�s se pasa el m�ximo y el vector a la funci�n que resuelve el problema.
//Despu�s, se declara n=0, vuelve a recorrer el vector, esta vez comparando si v[i]!= del m�ximo. Si lo es, n=n+v[i].


//Es problema es de complejidad O(n), ya que la funci�n que resuelve el caso tiene un �nico bucle for, con un �nico condicional, 
// y se recorre n veces.


int resolver(std::vector<int> const &v, int max) {
	int n=0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != max)
			n += v[i];
	}

	return n;
}

void resuelveCaso() {
	int n, max, suma;
	std::cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
		if (i == 0)
			max = v[0];
		else if (max < v[i])
			max = v[i];	
	}

	suma=resolver(v, max);

	std::cout << suma << '\n';

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y m�s/Universidad/2� E/EDA - 2� E/Ejercicios EDA/EDA LAB P14/EDA LAB P14/prueba.txt");
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