// Grupo E29, Laura Jiménez Fernández
/*Primero se comprueba si el vector tiene un solo elemento. Si es así, es caucásico. Si no se llama a la 
función resolver. 
El caso base de resolver es cuando hay solo dos elementos. Se cuentan si son pares, y se pone el sol.cauc a true.
Después, se crea un solIzq y un solDer, y se comprueba para cada mitad llamando a la función
resolver recursivamente. Para saber si es caucásico, se comprueba si el absoluto de la diferencia de la parte izquierda 
y la parte derecha es menor o igual que 2, y la parte izquierda y la derecha son caucásicas. Si no cumple ninguna de estas
condiciones, se pone sol.cauc a false;
Al final se devuelve sol.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>


typedef struct {
	bool cauc;
	int pares=0;
}tSolucion;



/*
		- c0 es ct
Coste: 
		- T(n/2) + c     (ya que recorremos las dos mitades del vector por mitades)
*/

tSolucion resolver(const std::vector<int> &v, int ini, int fin) {
	tSolucion sol;
	if (fin == ini + 1) {
			if (v[ini] % 2 == 0) sol.pares++;
			if (v[fin] % 2 == 0) sol.pares++;
			sol.cauc = true;
	}
	else {
		int mitad = (fin + ini) / 2;
		tSolucion solIzq;
		solIzq = resolver(v, ini, mitad);
		tSolucion solDer;
		solDer= resolver(v, mitad + 1, fin);
		sol.pares = solIzq.pares + solDer.pares;
		if (solIzq.cauc && solDer.cauc && abs(solDer.pares - solIzq.pares) <= 2) sol.cauc = true;
		else sol.cauc =  false;
	}

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n;
	tSolucion sol;
	const int centinela = 0;
	// leer los datos de la entrada
	std::cin >> n;
	if (n==centinela)
		return false;
	else {
		std::vector<int>v;
		v.push_back(n);
		std::cin >> n;

		while (n!=centinela) {
			v.push_back(n);
			std::cin >> n;
		}

		int ini = 0, fin = v.size() - 1;
		if (v.size() == 1) sol.cauc = true;
		else sol = resolver(v, ini, fin);
		if (sol.cauc) std::cout << "SI";
		else std::cout << "NO";
		std::cout << '\n';

		return true;
	}
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P31/EDA LAB P31/prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
