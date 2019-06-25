// Grupo E29,Laura Jiménez Fernández
/*Se considera que mientras que f y c sean positivos, se seguirá ejecutando el programa. Coge los valores necesarios, crea la matriz, y después
coge el string. En la función resolver se mira cada string, y dependiendo de cuál sea, coge los parámetros necesarios, y llama a la función que 
resuelve cada caso. En las funciones intercambiaFila e intercambiaColumna simplemente se guardan los valores de cada vuelta del bucle en un auxiliar, y se 
intercambian. En  rotarFila y rotarCol, se comprueba si es hacia la izquierda o hacia la derecha, si el valor es negativo se coge el absoluto, y se hace
el intercambio (con otro valor auxiliar) a izquierda/derecha o arriba/abajo. En cruzDiag, hace l*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>



// función que resuelve el problema
/* Tienen un coste lineal O(n), ya que los valores se tratan una vez unos con otros dentro de los bucles en cualquiera de las funciones. */
void intercambiaFila(std::vector<std::vector<int>> &matriz, int a, int b) {
	int aux;
	for (int i = 0; i < matriz[0].size(); i++) {
		aux = matriz[a][i];
		matriz[a][i] = matriz[b][i];
		matriz[b][i] = aux;
	}

}

void intercambiaColumna(std::vector<std::vector<int>> &matriz, int a, int b) {
	int aux;
	for (int i = 0; i < matriz.size(); i++) {
		aux = matriz[i][a];
		matriz[i][a] = matriz[i][b];
		matriz[i][b] = aux;
	}
}

void cruzDiag(std::vector<std::vector<int>> &matriz, int a, int b, int c) {
	int tam_columna = matriz.size(), tam_fila = matriz[0].size();
	int f = a, col = b;
	while (f >= 0 && col >= 0) {
		col--;
		f--;
	}
	f++;
	col++;

	while (f <tam_columna && col < tam_fila) {
		matriz[f][col] = c;
		col++;
		f++;
	}
	f = a;
	col = b;
	while (f >= 0 && col <tam_fila) {
		col++;
		f--;
	}
	f++;
	col--;

	while (f < tam_columna && col >= 0) {
		matriz[f][col] = c;
		col--;
		f++;
	}

}

void rotarFila(std::vector<std::vector<int>> &matriz, int f) {
	if (f < 0) {
		f = -f;
		f--;
		int aux = matriz[f][0];
		for (int i = 1; i < matriz[0].size(); i++)
			matriz[f][i - 1] = matriz[f][i];
		matriz[f][matriz[0].size() - 1] = aux;
	}
	else {
		f--;
		int aux = matriz[f][matriz[0].size() - 1];
		for (int i = matriz[0].size() - 2; i >= 0; i--)
			matriz[f][i + 1] = matriz[f][i];
		matriz[f][0] = aux;
	}

}

void rotarCol(std::vector<std::vector<int>> &matriz, int c) {
	if (c < 0) {
		c = -c;
		c--;
		int aux = matriz[0][c];
		for (int i = 1; i < matriz.size(); i++)
			matriz[i - 1][c] = matriz[i][c];
		matriz[matriz.size() - 1][c] = aux;
	}
	else {
		c--;
		int aux = matriz[matriz.size() - 1][c];
		for (int i = matriz.size() - 2; i >= 0; i--)
			matriz[i + 1][c] = matriz[i][c];
		matriz[0][c] = aux;
	}
}

void resolver(std::vector<std::vector<int>> &matriz) {
	std::string instr;
	int a, b, c;
	std::cin >> instr;
	
	if (instr == "filas") {
		std::cin >> a >> b;
		a--;
		b--;
		intercambiaFila(matriz, a, b);
	}
	else if (instr == "columnas") {
		std::cin >> a >> b;
		a--;
		b--;
		intercambiaColumna(matriz, a, b);
	}
	else if (instr == "cruz") {
		std::cin >> a >> b >> c;
		a--;
		b--;
		cruzDiag(matriz, a, b, c);
	}
	else if (instr == "rotarFila") {
		std::cin >> a;
		rotarFila(matriz, a);
	}
	else if (instr == "rotarCol") {
		std::cin >> b;
		rotarCol(matriz, b);
		
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso(int fila, int columna) {
	int f=fila, c=columna, num;
	// leer los datos de la entrada

		std::vector<std::vector<int>>matriz(f, std::vector<int>(c));
		for (int i= 0; i < matriz.size(); i++) {
			for (int j = 0; j < matriz[0].size(); j++)
			std::cin >> matriz[i][j];
		}

		std::cin >> num;
		for (int i = 0; i < num; i++)
			resolver(matriz);
		//muestra la matriz tras los cambios
		 for (int i = 0; i < matriz.size(); i++) {
			 for (int j = 0; j < matriz[0].size(); j++)
			 std::cout << matriz[i][j] << " ";
			 std::cout << '\n';
		 }
	 
	 std::cout << "---" << '\n';
	

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P19/EDA LAB P19/prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int fila, columna;
	std::cin >> fila >> columna;
	while (fila != 0 && columna != 0) {
		resuelveCaso(fila, columna);
		std::cin >> fila >> columna;
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}