//Grupo E29, laura Jiménez Fernández
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>


//Primero se cogen los datos del tamaño del vector, del número de vagones que se pueden asaltar, y después se cogen los datos del vector.
//Se llama a la función que resuelve (a la que se le pasa el vector y el número de vagones a asaltar). En esta, se declaran un contador
//(que se pondrá a cero cada vez que llegue a numVagones), suma, (que será donde se compare si se obtiene el mayor beneficio), max, (que 
//será el mayor beneficio obtenido), y pos, (que será la posición del vagón desde el que debemos empezar a asaltar el tren.
//Se recorre el vector desde el final hastas el principio con un bucle for, sumando sus componentes, y aumentando el contador. Si el contador 
//llega a ser igual que numVagones, se comprueba si la suma obtenida es mayor que max, y si lo fuera, max sería igual que la suma, la posición
//sería la de i, y después, (haya entrado o no en el if) se vuelven a poner la suma y el contador a 0, y la i, pasa a ser i+(numVagones-1) (aunque
//como después hay otro i--, ya que en el for decrece, pasaría a ser realmente numVagones-2).



//Es problema es de complejidad O(n), ya que la función que resuelve el caso tiene un único bucle for, (con dos condicionales), 
// y se recorre n veces. (Tamaño del vector)


void resolver(std::vector<int> const &v, int numVagones) {
	int contador = 0, suma = 0, max = 0, pos;

	for (int i = v.size() - 1; i >=0; i--) {
		suma += v[i];
		contador++;
		if(contador == numVagones) {
			if (max < suma) {
				max = suma;
				pos = i;
			}
			suma = 0;
			contador = 0;
			i += numVagones - 1;
		}
	}

	std::cout << pos << " " << max << '\n';

}

void resuelveCaso() {
	int n, numVagones;
	std::cin >> n;
	std::cin>>numVagones;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) 
		std::cin >> v[i];

	resolver(v, numVagones);

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P13/EDA LAB P13/prueba.txt");
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