// Grupo E29,Laura Jiménez Fernández
/*Primero se cogen los datos de vector de vectores (desde i=0, hasta i<filas*columnas). He declarado previamente dos auxiliares, auxf=0 y auxc=0 para que vaya 
cogiendo los valores correctamente (y cada vez que auxc llegue a c, aumenta el contador de auxf, y se vuelve a poner auxc a 0). Se pasa
el vector por la función, y se vuelven a declarar dos variables auxiliares (en este caso f=0 y c=0, y otra más, el contador=0). Se hace un for desde i=0 hasta i<filas*columnas, y 
si la posición de la matriz [f][c] es igual al valor de f (que será la fila que estamos recorriendo), el contador aumenta. Después, aumenta c, y si c llega a ser igual que
columnas, se vuelve a poner a 0, y f aumentará. Cuando haya terminado el for, devolverá el valor de contador, que será lo que mostrará el programa.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>



// función que resuelve el problema
/*Tiene un coste de  O(n), ya que el programa consistebásicamente en un while con 3 condicionales */

int resolver(const std::vector<std::vector<int>> &matriz, int filas, int columnas) {
	int cont=0, f = 0, c = 0, n;
	
	for (int i = 0; i < filas*columnas; i++) {

		if (matriz[f][c] == f)
			cont++;

		c++;
		if (c == columnas) {
			f++;
			c = 0;
		}
		
	}
	

	return cont;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n, f, c, auxf = 0, auxc = 0;
	
	// leer los datos de la entrada
	std::cin >> f;
	if (!std::cin)
		return false;

	else {
		std::cin >> c;
		std::vector<std::vector<int>> matriz(f, std::vector<int>(c));
		for (int i = 0; i < f*c; i++) {
			std::cin >> matriz[auxf][auxc];
				auxc++;
				if (auxc == c) {
					auxf++;
					auxc = 0;
				}
		}
		n = resolver(matriz, f, c);
		std::cout << n << '\n';

	}



	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P15/EDA LAB P15/prueba.txt");
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