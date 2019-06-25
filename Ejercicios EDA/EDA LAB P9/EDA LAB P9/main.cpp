// Grupo E29, Laura Jiménez Fernández
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>



// Tras haber cogido la frase y el patrón por teclado, hacemos un bucle for que es hasta frase.size()-1.
//vamos comparando cada caracter con el primero del patrón, y si coinciden, encontrado se vuelve true, el contador j es 1, 
//y empieza comparando desde el segundo caracter del patrón, con frase.at(i+j). Si en algún caso no coincidiera,
//encontrado se volvería false y saldría inmediatamente del bucle. Después se comprueba con un if si encontrado es true,
//lo cual haría que n (el número de veces que se repite el patrón) incrementara

// el coste del problema es de O(n*m), donde n son los elementos del array de caracteres, y m el número de caracteres 
//que tiene el patrón, ya que tiene un bucle for que va desde i=0 hasta i=frase.size()-1, con otro dentro que entra solo
//si coincide el caracter del patrón, (y solo va desde j=1 hasta j=patron.size()-1)

int resolver(std::string frase, std::string patron) {
	int n=0, j;
	bool encontrado;


	for (int i = 0; i < frase.size(); i++) {
		if (frase.at(i) == patron.at(0)) {
			encontrado = true;
			j = 1;
			while (encontrado && j < patron.size() && (i+j)<frase.size()) {
					if (frase.at(j + i) != patron.at(j))
					encontrado = false;
				j++;
			}
			if (encontrado && j==patron.size())
				n++;
		}
	}



	return n;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string frase, patron;
	int num;
	
	
	std::getline(std::cin, frase);

	if (!std::cin)
		return false;
	
	std::getline(std::cin, patron);
	num = resolver(frase, patron);
	std::cout << num << '\n';



	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("//psf/Home/Desktop/Trabajos y más/Universidad/2º E/EDA - 2º E/Ejercicios EDA/EDA LAB P9/EDA LAB P9/prueba.txt");
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
