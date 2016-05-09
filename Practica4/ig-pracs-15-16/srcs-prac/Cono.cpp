#include "Cono.hpp"
#include <math.h>

#define PI 3.14159265359

Cono::Cono(int num_caras){
	
	nombre_obj = "Cono";
	
	//VÉRTICES
	
	/*	Como la base es una circunferencia, su longitud va a ser L = PI * 2r.
	 * 		- Voy a considerar la circunferencia unidad => el radio r tendrá valor 1.
	 * 	Por tanto, la longitud de la circunferencia va a ser L = PI*2.
	 * 
	 * 	Para hallar las coordenadas de cada vértice en la circunferencia, voy a usar la siguiente relación:
	 * 		como una circunferencia tiene 360º, voy a dividirla entre el número de caras que quiero poner (menos 1 ya que también
	 * 		considero la base como una cara) y voy rotando de un vértice a otro (para ello, pongo *i para rotar en cada iteración).
	 * 
	 * 	En la base, ningún punto tendrá altura => la segunda coordenada es 0.
	 */
	
	//Vamos añadiendo tuplas con las coordenadas de los vértices de la base
	for (int i=0; i < num_caras; i++){
		vertices.push_back(Tupla3f(cos((2*PI/(num_caras-1))*i),0,sin((2*PI/(num_caras-1))*i)));
	}
	
	//Añado el vértice del centro de la base
	vertices.push_back(Tupla3f(0,0,0));
	
	//Añado el vértice de la cúspide
	vertices.push_back(Tupla3f(0,1,0));
	
	
	//CARAS
	
	//caras de la base
	for (int i=0; i < num_caras; i++){
		caras.push_back(Tupla3i(i, (i+1)%(num_caras-1), vertices.size()-2));
	}	
	
	//caras laterales
	for (int i=0; i < num_caras; i++){
		caras.push_back(Tupla3i(i, (i+1)%(num_caras-1), vertices.size()-1));
	}
	
}
