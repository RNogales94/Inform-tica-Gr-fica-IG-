#include "MallaRevol.hpp"
#include <math.h>
#include <vector>
#include "tuplasg.hpp"

#define PI 3.14159265359

MallaRevol::MallaRevol( const char * nombre_arch, unsigned nperfiles, bool quiero_coord_textura ){

	std::vector<float> vertices_ply; // coordenadas de vértices 
	
	ply::read_vertices( nombre_arch, vertices_ply );
	
	//Creamos los vértices
	
	/*
	 * 			[cos ángulo, 0, sin ángulo]
	 * R(y) = 	[0, 1, 0]
	 * 			[-sin ángulo, 0, cos ángulo]
	 */
	 
	for (int i=0; i < vertices_ply.size(); i+=3){ //i+=3 es porque en vertices_ply están de 3 en 3 (para leer la x de cada vértice) luego leemos la y con +1 y la z con +2
		for (int j=0; j < nperfiles; j++){ //para girar nperfiles veces
				vertices.push_back(Tupla3f(cos (((2*PI)/nperfiles)*j)*vertices_ply[i] + sin (((2*PI)/nperfiles)*j)*vertices_ply[i+2],
											vertices_ply[i+1],
											- sin (((2*PI)/nperfiles)*j)*vertices_ply[i] + cos (((2*PI)/nperfiles)*j) * vertices_ply[i+2]));
		}
	}
	
	//Creamos las caras laterales
	//Mejor en redondo porque la estructura la he creado en redondo
	for (int i=0; i < (vertices.size() - nperfiles) ; i+=nperfiles){
		for (int j=0; j < nperfiles ; j++){
			int vertice_superior = i + j + nperfiles;
			int vertice_adyacente = i + j + 1;
			int vertice_diagonal = i + j + 1 + nperfiles;
			
			if (j == nperfiles-1){ //máximo al que el j puede llegar (este if actúa como un módulo)
					vertice_adyacente = i; // el vértice de al lado tiene que ser el primero para que el último se una con el de al lado (que es el primero)
					vertice_diagonal = vertice_adyacente + nperfiles;
			}
			
			caras.push_back(Tupla3i(i+j, vertice_adyacente, vertice_diagonal));
			caras.push_back(Tupla3i(i+j, vertice_diagonal, vertice_superior));
		}	
	}
	
	//En el punto máximo y en el punto mínimo (primero y último) las x y las z son 0.

	Tupla3f vertice_inicial = vertices[0];
	Tupla3f vertice_final = vertices[vertices.size()-1];
	vertices.push_back(Tupla3f(0,vertice_inicial[1],0)); //vertices.size()-2 es el punto medio de la base inferior
	vertices.push_back(Tupla3f(0,vertice_final[1],0)); //vertices.size()-1 es el punto medio de la base superior

	for (int i=0; i < nperfiles; i++){
		caras.push_back(Tupla3i(i, (i+1)%nperfiles, vertices.size()-2)); //creación de la tapa de la base inferior
		
	}	
	
	for (int i = 0; i < nperfiles ; i++){
		caras.push_back(Tupla3i(i+(vertices.size()-3-nperfiles), ((i+1)%nperfiles)+(vertices.size()-3-nperfiles), vertices.size()-1)); //creación de la tapa de la base superior
	}
	
	
	// Añado las coordenadas de textura
	if (quiero_coord_textura == true){
		std::vector<float> s(nperfiles);
		std::vector<float> d(vertices.size()); //distancia (medida a lo largo del perfil) entre el primer vértice del mismo (v0) y dicho vértice j-ésimo.
		std::vector<float> t(vertices.size());
		
		for (int i = 0; i < nperfiles; i++){
			for (int j = 0; j < vertices.size(); j++){
			/* El perfil de partida tiene vertices.size() vértices
			 * Hay nperfiles copias del perfil
			 * y en cada copia hay vertices.size() vértices
			 * 
			 * El j-ésimo vértice en la i-ésima copia del perfil es qij
			 * y tendrá unas coordenadas de textura (si, tj) donde si es común a todos los vértices en una copia del perfil.
			 */

			 s[i] = (float)i / (nperfiles - 1); //coordenada X en el espacio de la textura. Va desde 0 en el 1º perfil hasta 1 en el último de ellos.
			 
			 d[0] = 0;
			 Tupla3f resta = vertices[j+1] - vertices[j];
			 float resta_normalizada = sqrt(resta.dot(resta));
			 d[j+1] = d[j] + resta_normalizada;
			 
			 t[j] = d[j]/d[vertices.size()-1]; //coordenada Y en el espacio de la textura.
			 
			 coordenadas_textura.push_back(Tupla2f(s[i],t[j]));
			 
			}
		}
	}
					
}
