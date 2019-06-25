// Grupo E46, Manuel Pastor Cobo

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>



// función que resuelve el problema
// comentario sobre el coste, O(f(N))
int resolver(std::vector <int> const & v) {
 std::vector <int> vmin(v.size() - 1);
 unsigned int i = vmin.size() - 1;

 int min = v[v.size() - 1];
 vmin[i] = min;
 for (int i = vmin.size() - 1; i > 0; i--) {
	 if (min > v[i]) {
		 min = v[i];
	 }
	 vmin[i - 1] = min;
 } 
 i = 0;
 int max = v[0];
 while(i < vmin.size() && max >= vmin[i]){
	 if (max < v[i]) max = v[i];
	 i++;
 }
 return i;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso(int const n){
	// leer los datos de la entrada
	int aux;
	std::vector <int> v(n);
	std::vector <int>::size_type tam = v.size();
	//Cargo los datos en un vector;
	for (std::vector <int>::size_type i = 0; i < tam; i++){
		std::cin >> aux;
		v[i] = aux;
	}
	int p;
	p = resolver(v);
	std::cout << p << '\n';
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("08EntradaEjemplo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::string res;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i){
		int n;
		std::cin >> n; //Cargo el num. de elementos del vector
		if (n > 0 && n < 10000){
			resuelveCaso(n);
		}
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}