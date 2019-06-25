// Grupo E29,Laura Jiménez Fernández
/* Se guarda en un vector auxiliar la cantidad de ceros que hay en cada columna. Después, se recorre la matriz
de i a j (desde i=0, y j=anchofranja-1). Vamos comparando el elemento del vector aux en la posición cont, (y si es mayor o igual
que xceros, aumenta el contador de ceros). Cuando cont sea mayor que j, se comprobará si hay al menos y columnas con al menos x ceros,
y si las hay, aumenta n. Se aumenta i, j, se pone el cont=i, y el contador de ceros a 0.*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>



// función que resuelve el problema
/* Tiene un coste lineal O(n), ya que el bucle que resuelve el problema tiene un coste O((n-franja)+1)*franja), siendo n los elementos del vector, y franja el tamaño de la franja.*/

int resolver(const std::vector<std::vector<int>> &matriz, int franja, int ycolumnas, int xceros) {
	int n = 0, i = 0, j = franja - 1, contador = 0, contceros = 0;
	int topecols = ycolumnas;
	std::vector<int>aux(matriz[0].size());
	for (int k = 0; k < matriz[0].size(); k++){
		for (int l = 0; l < matriz.size(); l++) {
			if (matriz[l][k] == 0)
				contceros++;
		}
		aux[k] = contceros;
		contceros = 0;
	}
	contceros = 0;
	while (contador < aux.size()) {
		if (aux[contador]>=xceros)
			contceros++;

		contador++;
		if (contador>j) {
				if (contceros>=ycolumnas)
					n++;

				i++;
				j++;
				contador = i;
				contceros = 0;
		}
	}
	return n;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	int f, c, franja, ycolumnas, xceros, n;
	// leer los datos de la entrada
	std::cin >> f;
	if (!std::cin)
		return false;
	else {
		std::cin >> c >> franja >> ycolumnas >> xceros;
		std::vector<std::vector<int>> matriz(f, std::vector<int>(c));
		for (int i = 0; i < matriz.size(); i++) 
			for (int j = 0; j < matriz[0].size(); j++)
				std::cin >> matriz[i][j];
		n=resolver(matriz, franja, ycolumnas, xceros);
		std::cout << n << '\n';

		// escribir sol

	}
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P20/EDA LAB P20/prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto 
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}