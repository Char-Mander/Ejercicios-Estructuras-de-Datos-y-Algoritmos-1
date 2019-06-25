//Grupo E29, laura Jiménez Fernández
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

//Se declaran un maximo (que serán la cantidad de números que forman la secuencia más larga, la pos inicial, la pos
//final, y el contador (Que empieza en 1). Se recorre el vector desde la segunda posicion, y se compara v[i] y v[i-1].
//Si resulta que ambos son mayores que la altura del transporte, el contador aumenta. Si solo el mayor el v[i], el contador vuelve a 1.
//Después, se comprueba si el máximo es menor que el contador, y si lo es, el max)contador, y la posición final será la de i.
//Para calcular la posición inicial, basta con restar a la posición final, el máximo - 1.


//Es problema es de complejidad O(n), ya que la función que resuelve el caso tiene un único bucle for, con condicionales, 
// y se recorre n-1 veces.


void resolver(std::vector<int> const &v, int altura) {
	int max=0, ini=0, fin=0, cont=1;
	
	
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > altura && i>0 && v[i - 1] > altura) {
			cont++;
			if (max < cont) {
				max = cont;
				fin = i;
			}
		}
		else if (v[i]>altura) {
			cont = 1;
			if (max < cont) {
				max = cont;
				fin = i;
			}
		}
	}
	if (fin == 0)
		ini = fin;
	else ini = fin - (max - 1);
	std::cout << ini << " " << fin << '\n';

}

void resuelveCaso() {
	int n, altura;
	std::cin >> n;
	std::vector<int> v(n);
	std::cin >> altura;
	for (int i = 0; i < n; i++)
		std::cin >> v[i];


	 resolver(v, altura);

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P12/EDA LAB P12/prueba.txt");
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