//Grupo E29, laura Jiménez Fernández
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>


//Al coger los datos del vector se busca el máximo. Después se pasa el máximo y el vector a la función que resuelve el problema.
//Después, se declara n=0, vuelve a recorrer el vector, esta vez comparando si v[i]!= del máximo. Si lo es, n=n+v[i].


//Es problema es de complejidad O(n), ya que la función que resuelve el caso tiene un único bucle for, con un único condicional, 
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
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P14/EDA LAB P14/prueba.txt");
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