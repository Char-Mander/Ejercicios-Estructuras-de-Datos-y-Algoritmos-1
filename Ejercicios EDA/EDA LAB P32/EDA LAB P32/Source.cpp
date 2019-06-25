// Grupo E29, Laura Jiménez Fernández
/* Cogemos la diagonal como la "mejor solución". Después, llamamos a la función resolver con la matriz, el vector de booleanos que indica si se
usó, el vector que irá guardando los trbajos, el total (donde iremos guardando la suma del tiempo), la k (el nivel por el que vamos), y la mejor solución.
Se hace un bucle desde trabajo=0 hasta una de las dimensiones de la matriz. Si no se ha usado el trabajo por el que vamos, guardamos en el
vector solución de k el trabajo usado. Después, marcamos en usadas el trabajo, y sumamos al total la posición [k][trabajo] de la matriz.
Después comprobamos si estamos en el final (k==matriz.size()-1). Si está, comprobamos si el total es menor que la mejor solución. Si lo es,
la mejor solución será el total. Si no es el final, se llama al siguiente nivel (k+1). Después, se desmarca tanto el vector de booleanos,
y se le quita la cantidad que sumamos en este nivel al total.*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>



//Función que resuelve el problema


void resolver(const std::vector<std::vector<int>> &matriz, std::vector<bool> &usadas, std::vector<int> &sol, int &total, int k, int &mejor) {
	int posibles;
	for (int trabajo = 0; trabajo<matriz.size(); trabajo++) {
		if (!usadas[trabajo]) {
			sol[k] = trabajo;
			usadas[trabajo] = true; // Marcamos en usadas el trabajo
			total += matriz[k][trabajo]; //También sumamos al total
			if (k == matriz.size() - 1) {
				if (total < mejor) mejor = total;	
			}
			else resolver(matriz, usadas, sol, total, k+1, mejor);
			usadas[trabajo] = false; //Desmarcamos
			total -=matriz[k][trabajo]; //Restamos al total lo que le sumamos
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	int n, sol, k = 0, total = 0;
	const int centinela = 0;
	// leer los datos de la entrada
	std::cin >> n;
	if (n==centinela)
		return false;
	else {
		std::vector<std::vector<int>>matriz(n, std::vector<int>(n));
		std::vector<bool>usadas(n);
		std::vector<int>sol(n);

		for (int i = 0; i < matriz.size(); i++)
			for (int j = 0; j < matriz[0].size(); j++)
				std::cin >> matriz[i][j];

		for (int i = 0; i < usadas.size(); i++)
			usadas[i] = false;

		int mejor=0;
		for (int i = 0; i < sol.size(); i++) {
			sol[i] = i;
			mejor += matriz[i][i];
		}

		resolver(matriz, usadas, sol, total, k, mejor);

		std::cout << mejor << '\n';

		return true;
	}

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P32/EDA LAB P32/prueba.txt");
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
