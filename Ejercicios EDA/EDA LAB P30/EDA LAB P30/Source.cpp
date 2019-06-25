// Grupo E29,Laura Jim�nez Fern�ndez
/* Primero se tiene en cuenta si el vector tiene solo un elemento. Si es as�, est� parcialmente ordenado.
Si no, llama a la funci�n resolver. 
El caso base de resolver es cuando hay solo dos elementos. Si el de la izquierda es 
menor o igual que el de la derecha, se pone sol.ordenado a true, y sol.max=v[fin] y sol.min=v[ini]. Si no, 
sol.ordenado ser�false.
Para recorrer el vector, se crean dos variables tipo tSol: izq y der. Se llama a resolver con izq a la mitad izquierda, y a 
la mitad derecha con der. Despu�s, si el m�nimo de la izquierda es menor o igual que el m�nimo de la derecha, el m�ximo de 
la derecha es mayor o igual que el m�ximo de la izquierda, e izq y der est�n parcialmente ordenados, se pone sol.ordenado a true.
Si no, sol.ordenado ser� false. 
Finalmente devuelve sol.*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>



// funci�n que resuelve el problema
/*
		- c es ct
Coste:
		-T(n) = log(n)+log(n)      (ya que recorremos las dos mitades del vector por mitades)
*/

typedef struct {
	bool ordenado;
	int max, min;
}tSolucion;

tSolucion resolver(const std::vector<int>&v, int ini, int fin) {
	tSolucion sol;

	if (fin - ini == 1) {
		if (v[ini] <= v[fin]) {
			sol.ordenado = true;
			sol.max = v[fin];
			sol.min = v[ini];
		}
		else sol.ordenado = false;

	}
	else {
		tSolucion izq, der;
		int mitad = (ini + fin) / 2;
		izq=resolver(v, ini,mitad);
		der=resolver(v, mitad+1, fin);
		if (izq.min <= der.min && der.max >= izq.max && izq.ordenado && der.ordenado) sol.ordenado=true;
		else sol.ordenado = false;
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	int n;
	bool sol = true;

	std::vector<int>v;

	// leer los datos de la entrada
	std::cin >> n;
	if (n == 0)
		return false;
	else {
		v.push_back(n);
		std::cin >> n;
		while (n != 0) {
			v.push_back(n);
			std::cin >> n;
		}


		tSolucion sol;
		if (v.size() == 1) sol.ordenado = true;
		else sol = resolver(v, 0, v.size()-1);

		if (sol.ordenado) std::cout << "SI" << '\n';
		else std::cout << "NO" << '\n';
		return true;
	}
}
	



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y m�s/Universidad/2� E/EDA - 2� E/Ejercicios EDA/EDA LAB P30/EDA LAB P30/prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
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