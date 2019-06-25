//Grupo E29, laura Jiménez Fernández
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

/*En resolver, primero comprueba que la mitad ((ini+fin)/2) más el número dado es igual que v[mitad]. Si lo es, habremos
encontrado n, que será v[mitad]. Si no, comprobamos si ini>fin. Si lo es, significa que no ha encontrado el número,
por lo que se devolverá a n como -1. Si estos dos casos no se cumplen, comprobamos si mitad+el número dado es mayor que el elemento v[mitad].
Si lo es, llamaremos a la función resolver, con ini=mitad+1. Si no se cumple ninguno, llamaremos a la función resolver com fin=mitad-1.*/


/* Tiene coste logarítmico, (O(lgn)), ya que reduce el vector por mitades. */

int resolver(std::vector<int> const &v, int numero, int ini, int fin) {
	int n, mitad = (ini + fin) / 2;
		if (mitad + numero == v[mitad]) {
			n = v[mitad];
		}
		else if (ini > fin)
			n = -1;
	else if (mitad + numero > v[mitad])n = resolver(v, numero, mitad+1, fin);
	else /*if(mitad+numero<v[mitad])*/ n = resolver(v, numero, ini, mitad-1);

	return n;
}

void resuelveCaso() {
	int p, n, num;
	bool encontrado = false;
	std::cin >> n >> num;
	
	int mitad = (n / 2);
	if(n % 2 == 0)
		mitad = mitad - 1;

	std::vector<int> v(n);

	for (int i = 0; i < v.size(); i++)
		std::cin >> v[i];

	p = resolver(v, num, 0, v.size());
	if (p!=-1)
		std::cout << p;
	else std::cout << "NO";

	std::cout << '\n';

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P23/EDA LAB P23/prueba.txt");
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