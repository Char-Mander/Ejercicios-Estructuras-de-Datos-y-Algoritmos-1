//Grupo E29, laura Jiménez Fernández
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

/* Carga en el vector auxiliar los mínimos de izquierda a derecha, y luego, empezando desde la izquierda, recorre el vector original. 
Si al cambiar de mínimo, el máximo hasta la posición i-1 es menor que el nuevo mínimo, será una posición partición, y se mete en el vector de la solución.*/


/* Tiene un coste lineal O(n), ya que en la función que resuelve el problema hay dos bucles, que dependen solo del tamaño de los vectores que se tratan,
y los elementos se comparan una sola vez. */

void resolver(std::vector<int> const &v, std::vector<int> &salida) {
	int min=v[v.size()-1];
	std::vector<int>aux(v.size());
	aux[v.size() - 1] = min;
	for (int i = v.size() - 2; i >= 0; i--) {
		if (v[i]<min) {
			min = v[i];
			aux[i]=v[i];
		}
		else aux[i] = min;
	}
	int max = v[0];
	if (v[0] == aux[0])
		aux[0] = -1;
	for (int i = 1; i < aux.size(); i++) {
		if (aux[i] != aux[i - 1]) {
			if (max < aux[i])
				salida.push_back(i - 1);
		} 
		if (v[i]>max)
			max = v[i];
	}
}

void resuelveCaso() {
	int n, p;
	std::cin >> n;
	std::vector<int> v(n);
	std::vector<int>salida;

	for (int i = 0; i < n; i++)
		std::cin >> v[i];


	 resolver(v, salida);

	 for (int i = 0; i <salida.size(); i++)
	std::cout << salida[i] << " ";

	 std::cout << '\n';

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB ZZ1/EDA LAB ZZ1/prueba.txt");
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