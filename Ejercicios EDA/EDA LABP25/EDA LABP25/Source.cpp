// Grupo E29,Laura Jiménez Fernández
//Recursivo no final.
/*  Los casos base son cuando n=0, y n=1, en los que muestra 0 y 1 respectivamente. En resolver, se guardará 
en la variable sol a2. Cuando el contador llegue al número, se devolverá el valor almacenado en sol.
Si el contador es igual a 0, se guardará en sol la función resolver (siendo a1=1, a2=0, y el contador+2), y se le suma a la función a1.
Si no, se guarda en sol la función resolver (siendo a1=a1+a2, y a2=a1, y el contador+1, y se le suma a2.*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>



// función que resuelve el problema
/* La función resolver tiene coste lineal, ya que llama una sola vez a la misma función (recursivamente) */
//

long long int resolver(long long int n, long long int a1,/*n-1*/ long long int a2,/*n-2*/  int cont){
	long long int sol;
 	if (cont == n) return sol=a2;
	else if (cont == 0)  return sol= resolver(n, 1, 0, cont+2)+a1;
	else return sol= resolver(n, a1+a2, a1, cont+1)+a2;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	long long int n, a2=0, a1=0, sol=0;
	// leer los datos de la entrada
	std::cin >> n;
	if (!std::cin)
		return false;
	else {
		if (n == 0) std::cout << n << '\n';
		else if (n == 1) std::cout << n << '\n';
		else {
			sol = resolver(n, 1, 0, 0);
			std::cout << sol << '\n';
		}
		return true;  
	}
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LABP25/EDA LABP25/prueba.txt");
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