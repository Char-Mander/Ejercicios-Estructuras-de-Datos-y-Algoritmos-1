//Grupo E29, laura Jiménez Fernández

/* Primero coge de teclado el número de casos, y llama a resuelveCaso. En resuelve caso, se crean dos vectores, w y z (en z estará la
intersección de vectores), y se coge por teclado el número de vectores que hay. Luego se almacena el primer "vector" en z (mientras que 
sea distinto de 0 el valor). Después, se crea el vector w, se cargan los elementos, y se llama a la función resolver, (será el vector que 
compararemos con z). Declararemos las variables i=0, y k=0 (i y k son contadores), y se creará un vector v. 
Después, mientras que i sea menor que z.size() y k sea menor que w.size(), se compará z[i] y w[k]. Si son iguales, el elemento 
z[i] entrará en el vector v, y aumenta el contador de la i y de la k. Si i es menor que k, aumenta el contador de i. Si i es mayor 
que k, aumentará k. Si cuando salga del bucle, i no es z.size(), e i=0, significa que no hay valores comunes (la intersección de vectores 
es vacía), por lo que se limpia el vector z. Si no se cumplen las condiciones anteriores, se borra el vector z, y se le pasará el vector v 
(que tendrá los valores de la intersección).
Al final, en la función resuelveCaso, si el vector z tiene elementos, los muestra, y si no, muestra una línea vacía*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>



/* La función que resuelve tiene un coste lineal O(n), ya que los elementos se tratan una sola vez tanto en el bucle while
que compara los valores de ambos vectores, como en el bucle que pasa los elementos de la intersección al vector z.
En le función resuelveCaso, a pesar de haber un bucle while dentro del for (el for llega hasta que no haya más vectores que
tratar en el caso), no trata los elementos más de una vez; el while simplemente coge los elementos del que sería el segundo
vector, y cuando sale del bucle while, llama a la función resolver. */

void resolver(std::vector<int> &z, const std::vector<int> &w) {
	int n, i = 0, k = 0;
	std::vector<int>v;

	while (i < z.size() && k < w.size()) {
		if (z[i] == w[k]) {
			v.push_back(z[i]);
			i++;
			k++;
		}
		else if (z[i] < w[k])i++;
		else k++;
	}

	if (i != z.size() && i == 0) z.clear();
	else {
		z.clear();
		for (int i = 0; i < v.size(); i++)
			z.push_back(v[i]);
	}
	v.clear();
}


void resuelveCaso() {
	std::vector<int>z;
	std::vector<int>v;
	int n, numVectores;   
	std::cin >> numVectores;

	std::cin >> n;
	while (n != 0) {
		z.push_back(n);
		std::cin >> n;
	}

	numVectores--;
	for (int i = numVectores; i > 0; i--) {
		std::vector<int>w;
		std::cin >> n;
		while (n != 0) {
			w.push_back(n);
			std::cin >> n;
		}
		resolver(z, w);
		w.clear();
	}
	
	if (z.size() > 0) {
		for (int i = 0; i < z.size(); i++)
			std::cout << z[i] << " ";
	}


	std::cout << '\n';

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P10/EDA LAB P10/prueba.txt");
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