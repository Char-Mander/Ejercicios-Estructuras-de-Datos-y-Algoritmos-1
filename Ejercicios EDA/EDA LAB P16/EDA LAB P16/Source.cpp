// Grupo E29,Laura Jiménez Fernández
/* En resolver, se recorre la matriz con un for (todas las columnas), que lo primero que hace es comparar si el elemento a comparar
es igual que el que hay en la primera fila de cada columna. Después tiene  un while dentro (que va de fila en fila, mientras que 
franjaEntera sea true, y fil sea menor que matriz.size(). Cuando sale del while, si franjaEntera es true,  aumenta el contador, 
y se compara con el máximo. Si es mayor que el máximo, el máximo pasará a tener el valor del contador. Después se vuelve a poner franjaEntera
a true de nuevo, */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>



// función que resuelve el problema
/* Este problema tiene coste lineal, O(n*m), (siendo n *m la dimensión total de la matriz) ya que al cargar la "matriz" se tratan los elementos una sola vez, y en la función
que resuelve recorre la "matriz" en un único bucle for, tratando los elementos una sola vez (recorre toda la matriz excepto la primera fila)*/

int resolver(const std::vector<std::vector<int>> &matriz, int f, int c) {
	int max = 0, ancho = 0, contador = 0, elemento = matriz[0][0];
	bool franjaEntera = true;

	for (int c = 0; c < matriz[0].size(); c++){
		if (elemento != matriz[0][c]) {
			elemento = matriz[0][c];
			contador = 0;
		}
		franjaEntera = true;
		int fil = 1;
		while (franjaEntera && fil < matriz.size()){
			if (elemento != matriz[fil][c]) 
				franjaEntera = false;
			else fil++;
		}
				if (franjaEntera) {
					contador++;
					if (max < contador)
						max = contador;
				}
				else contador = 0;

				ancho = 0;
			}



	return max;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int f, c, n;

	std::cin >> f;
	if (!std::cin)
		return false;
	else {
		std::cin >> c;
		std::vector<std::vector<int>> matriz(f, std::vector<int>(c));

		for (int i = 0; i < matriz.size(); i++)
			for (int j = 0; j < matriz[0].size(); j++)
			std::cin >> matriz[i][j];
		

		n = resolver(matriz, f, c);
		std::cout << n << '\n';

	}


	// escribir sol


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P16/EDA LAB P16/prueba.txt");
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