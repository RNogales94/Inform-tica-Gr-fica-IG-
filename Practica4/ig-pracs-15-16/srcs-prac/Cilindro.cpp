#include "Cilindro.hpp"
#include <math.h>

#define PI 3.14159265359

Cilindro::Cilindro(int num_caras){
	
	nombre_obj = "Cilindro";
	
	//VÉRTICES
	
	//Vamos añadiendo tuplas con las coordenadas de los vértices de la base inferior
	for (int i=0; i < num_caras; i++){
		vertices.push_back(Tupla3f(cos((2*PI/(num_caras-1))*i),0,sin((2*PI/(num_caras-1))*i)));
	}
	
	//Vamos añadiendo tuplas con las coordenadas de los vértices de la base superior
	for (int i=0; i < num_caras; i++){
		vertices.push_back(Tupla3f(cos((2*PI/(num_caras-1))*i),1,sin((2*PI/(num_caras-1))*i)));
	}
	
	//Añado el vértice del centro de la base superior ~ luego lo llamaremos como vertices.size()-2
	vertices.push_back(Tupla3f(0,1,0));
	
	//Añado el vértice del centro de la base inferior ~ luego lo llamaremos como vertices.size()-1
	vertices.push_back(Tupla3f(0,0,0));
	
	
	//CARAS
	
	//caras de la base inferior
	//recorremos la primera mitad de los vértices,creando triángulos con el centro inferior
	for (int i=0; i < ((vertices.size()/2)-1); i++){
		caras.push_back(Tupla3i(i, (i+1)%((vertices.size()/2)-1), vertices.size()-1));
	}	
	
	//caras de la base superior
	//recorremos la segunda mitad de los vértices, creando triángulos con el centro superior
	for (int i=((vertices.size()/2)-1); i < (vertices.size()-2); i++){
		caras.push_back(Tupla3i(i, (i+1)%(vertices.size()-2), vertices.size()-2));
	}
	
	//caras laterales
	for (int i=0; i < ((vertices.size()/2)-1); i++){
		caras.push_back(Tupla3i(i, (i+1)%((vertices.size()/2)-1), i+((vertices.size()/2)-1))); //creación de triángulos desde la base inferior a la superior
		caras.push_back(Tupla3i(i + ((vertices.size()/2)-1), ((i+1)%((vertices.size()/2)-1)) + ((vertices.size()/2)-1), (i+1)%((vertices.size()/2)-1)));
		
	}
	
}
