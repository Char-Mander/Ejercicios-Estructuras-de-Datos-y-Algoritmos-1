// Grupo E29,Laura Jiménez Fernández
/*Los casos base: -cuando a y b son iguales, y b es igual a 0, que será 1.
				  -cuando b es 1 y b es a+1, que el resultado será a.
Si no pasa por los casos base, se comprobará que para a-1 y b-1 haya un resultado en la matriz.
Si no lo hay, es decir, que esté el valor -1 en la matriz, se devuelve la posición de la matriz
con la llamada a la función para [a-1][b-1]. Se hace lo mismo [a-1][b].
Después se devuelve la suma de matriz[a-1][b]+matriz[a-1][b-1] como matriz[a][b] (y así pasa por los casos
en los que sí había resultados previos en la matriz)*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>



// función que resuelve el problema
/* comentario sobre el coste, O(f(N)) */

int resolver(std::vector<std::vector<int>> &matriz, int a, int b) {
	int sol;
	if (a == b || b == 0) return matriz[a][b] = 1;
	else if (b == 1 || b == a + 1) return matriz[a][b] = a;
	else {
		if (matriz[a - 1][b - 1] == -1) matriz[a - 1][b - 1] = resolver(matriz, a-1, b-1);
		if (matriz[a - 1][b] == -1) matriz[a - 1][b] = resolver(matriz, a - 1, b);
		return matriz[a][b] = matriz[a - 1][b - 1] + matriz[a - 1][b];
		}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	int a, b, sol;
	
	std::cin >> a;
	if (!std::cin)
		return false;
	else {
		std::cin >> b;
		std::vector<std::vector<int>> matriz(a+1, std::vector<int>(b+1));
		for (int i = 0; i < matriz.size(); i++)
			for (int j = 0; j < matriz[0].size(); j++){
				if (i == 0 || j==0 || i==j ) matriz[i][j] = 1;
				else matriz[i][j] = -1;
				}
	
		
		
	
		sol = resolver(matriz, a, b);
		std::cout << sol<< '\n';

		return true;
	}

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LABP26/EDA LABP26/prueba.txt");
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