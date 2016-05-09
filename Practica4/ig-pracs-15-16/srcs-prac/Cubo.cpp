#include "Cubo.hpp"

Cubo::Cubo(){
	
	nombre_obj = "Cubo";
	
	//El cubo posee 8 vértices
	
	//vértices inferiores
	vertices.push_back(Tupla3f(0,0,0)); //v0
	vertices.push_back(Tupla3f(1,0,0)); //v1
	vertices.push_back(Tupla3f(0,0,1)); //v2
	vertices.push_back(Tupla3f(1,0,1)); //v3
	//vértices superiores
	vertices.push_back(Tupla3f(0,1,0)); //v4
	vertices.push_back(Tupla3f(1,1,0)); //v5
	vertices.push_back(Tupla3f(0,1,1)); //v6
	vertices.push_back(Tupla3f(1,1,1)); //v7
	
	//El cubo posee 6 caras y cada una de ellas 2 triángulos
	caras.push_back(Tupla3i(0,2,1));
	caras.push_back(Tupla3i(1,2,3));
	caras.push_back(Tupla3i(3,7,2));
	caras.push_back(Tupla3i(2,7,6));
	caras.push_back(Tupla3i(6,4,0));
	caras.push_back(Tupla3i(0,2,6));
	
	caras.push_back(Tupla3i(6,7,5));
	caras.push_back(Tupla3i(6,5,4));
	caras.push_back(Tupla3i(3,5,7));
	caras.push_back(Tupla3i(3,1,5));
	caras.push_back(Tupla3i(1,0,4));
	caras.push_back(Tupla3i(4,5,1));
	
}
