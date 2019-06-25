//Grupo E29, laura Jiménez Fernández
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>

/* Pasamos a la función que resuelve el vector, tam, numr, y numz. Declaramos las variables n (será lo que devolverá la función), i, j, el contador, (que controla
que el bucle se recorra de tam en tam). El bucle va desde i=0, hasta i=v.size()-fin. Primero compara si alguna de las componentes de v[contador] es igual a r o z,
(y si lo es, aumenta el contador de la letra que sea). Aumenta el contador, y si  es mayor que j, (el límite del tramo que mira) compara si el contador de la r 
y la z es >= que numr y numz, respectivamente, y si lo es, aumenta la n. Después, aumenta la i, el contador pasa a estar en la posición i, y la j aumenta.
Los contadores de la r y la z vuelven a estar a 0.*/


/* Coste de la función: O(n) ya que trata todos los elementos del vector v una sola vez, (aunque se recorra de tam en tam) */

int resolver(std::vector<std::string> const &v, int tam, int numr, int numz) {
	int n = 0, i = 0, j = (tam + i - 1), contador = 0, fin = j;
	int contr=0, contz=0;

	while (i < v.size() - fin) {
		if (v[contador] == "r")
			contr++;
		else if (v[contador] == "z")
			contz++;

		contador++;
		if (contador>j) {
			if (contr >= numr&&contz >= numz)
				n++;

			i++;	
			contador = i;
			j++;
			contr = 0;
			contz = 0;
		}
	}
	return n;
}

void resuelveCaso() {
	int n, p, tam, numr, numz;
	std::cin >> n;
	std::vector<std::string> v(n);
	std::cin >> tam >> numr >> numz;
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
		p = resolver(v, tam, numr, numz);

	std::cout << p << '\n';

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P17/EDA LAB P17/prueba.txt");
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