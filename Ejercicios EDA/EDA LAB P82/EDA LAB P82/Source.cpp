//Grupo E, laura Jiménez Fernández
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>



// Habiendo cogido por teclado n, primero se comprueba si el vector es ascendente, si el primer elemento es mayor o igual que el último,
// o si el máximo está en la primera posición. Si cumple alguna de estas condiciones, p sería v.size()-1 (y también coge el máximo del vector)
//Si no, se va recorriendo el vector, (y también se coge otro máximo auxiliar) se considera el primer elemento del vector como maxu (el máximo por la izquierda
// y el último elemento del vector como minw (el mínimo por la derecha)
//se establece el inicio en 1, y el fin en v.size()-2 (ya que el máximo y el mínimo ocupan la posición
//0 y v.size()-1. Se recorre el vector hasta que fin sea menor que ini de una forma peculiar; ini va ascendiendo,
//mientras que fin va descendiendo, de tal modo que:
//-Si el maxu es menor o igual que el v[ini] y también  v[ini] es menor que minw, el nuevo maxu será v[ini],
//e ini será ini+1. si no, se declarará el fin en ini-1, ya que sabemos que ese elemento es mayor que alguno de la 
//derecha, por lo que no cumple la condición.
//-Si minw es mayor o igual que v[fin], y v[fin] es mayor que maxu, minw será igual a v[fin], y fin
//pasará a ser fin-1. Si v[fin] fuera mayor o igual que minw, ini sería fin+1. 
//-Si no se cumpliera ninguna de las condiciones anteriores, aumentaría el contador de ini en caso de que  
//v[fin-1]>maxu, y disminuiría el de fin si v[ini+1] fuera menor que minw, si no, aumentaría el contador 
//de i++ y disminuiría el de j--.
//Cuando salga del bucle, se comprueba si el minw es menor o igual que maxu; si lo fuera, p estará en la posición v.size()-1;
//si no se hubiera encontrado el máximo, p sería v.size()-1 también, y si no, p sería fin-1;


// Tiene un coste lineal, O(n)  ya que primero hace un bucle cuyo coste es n, hay asignaciones de valor, un if, y
// en el peor caso, recorrerá el vector desde el principio y desde el final,(hasta que la variable ini es mayor que fin)
//con el bucle del while, y comparando con los ifs, lo cual tiene también tiene coste O(n).
//hasta que la variable ini es mayor que fin, haciendo simplemente 

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
int resolver(std::vector<int> const &v) {
	// leer los datos de la entrada
	int p;/*, max1, posmax1=0;*/
	int ini = 1, fin = v.size() - 2;
	int max1 = v[0], posmax1=0, max2 = v[0];
	int maxu = v[0], minw = v[v.size() - 1];
	bool ascendente = true;
	max1 = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i] > max1) {
			max1 = v[i];
			posmax1 = i;
		}
		else ascendente = false;
	}

	if (posmax1 == 0 || v[0] >= v[v.size() - 1])
		p = v.size() - 1;
	else if (ascendente)
		p = 0;
	else {
		while (fin > ini) {
			if (max2 < v[ini])
				max2 = v[ini];
			else if (max2<v[fin])
				max2 = v[fin];
			else if (v[ini] > minw || v[fin] < maxu)
				fin = ini - 1;
			else if (maxu < v[ini]) {
				if (v[ini] < minw) {
					maxu = v[ini];
					ini++;
				}
				else fin = ini - 1;
			}
			else if (minw > v[fin]) {
				if (v[fin] >  maxu) {
					minw = v[fin];
					fin--;
				}
				else ini = fin + 1;
			}
			else {
				if (v[ini + 1] > maxu)
					fin--;
				else if (v[fin - 1] < minw)
					ini++;
				else {
					ini++;
					fin--;
				}
			}
		}
		if (minw <= maxu || (max1 != max2&&max1 != v[v.size() - 1]))
			p = v.size() - 1;
		else p = fin;
	}
	

	

	
	// escribir sol

	return p;
}

void resuelveCaso(){
	int n, p;
	std::cin >> n;
	std::vector<int> v(n);
	
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	

	p = resolver(v);
	std::cout << p << '\n';
}


int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P82/EDA LAB P82/prueba.txt");
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