#include "Tetraedro.hpp"

Tetraedro::Tetraedro(){
	
	nombre_obj = "Tetraedro";
	
	//El tetraedro posee 4 vértices
	
	//vértices inferiores
	vertices.push_back(Tupla3f(0,0,0));	//v0
	vertices.push_back(Tupla3f(1,0,0));	//v1
	vertices.push_back(Tupla3f(0,0,1));	//v2
	//vértice superior
	vertices.push_back(Tupla3f(0,1,0));	//v3
	
	//El tetraedro posee 4 caras formadas, cada una de ellas, por un triángulo
	caras.push_back(Tupla3i(2,1,0));
	caras.push_back(Tupla3i(2,1,3));
	caras.push_back(Tupla3i(1,0,3));
	caras.push_back(Tupla3i(0,2,3));
	
}
