#include "MallaTraslacion.hpp"
#include <vector>
#include <math.h>
#include <file_ply_stl.hpp>
#include "tuplasg.hpp" // Tupla3f


MallaTraslacion::MallaTraslacion( const char * nombre_arch, unsigned ntraslaciones, Tupla3f vector_traslacion, bool quiero_coord_textura){
	
	std::vector<float> vertices_ply; // coordenadas de vértices 
	
	ply::read_vertices( nombre_arch, vertices_ply );
	
	// Creamos los vértices
	for (int i=0; i < vertices_ply.size(); i+=3){ 
		vertices.push_back(Tupla3f(vertices_ply[i], vertices_ply[i+1], vertices_ply[i+2]));
	}
	
	int num_vertices_polilinea = vertices.size();
	Tupla3f vector_traslacion_nuevo = vector_traslacion;
		
	for (int i=0; i < ntraslaciones; i++){ //En cada traslacion
		for (int j=0; j < num_vertices_polilinea; j++){ //generar la siguiente polilinea (4 vertices)
				vertices.push_back(vertices[j] + vector_traslacion_nuevo); //para multiplicar el vector de traslacion por la altura querida
		}
		vector_traslacion_nuevo = vector_traslacion_nuevo + vector_traslacion;
	}
	
	// Creamos las caras
	for (int i=0; i < (vertices.size() - num_vertices_polilinea); i+=num_vertices_polilinea){
		for (int j=0; j < num_vertices_polilinea; j++){
			int vertice_superior = i + j + num_vertices_polilinea;
			int vertice_adyacente = i + j + 1;
			int vertice_diagonal = i + j + 1 + num_vertices_polilinea;
			
			if (j == (num_vertices_polilinea - 1)){
				vertice_adyacente = i;
				vertice_diagonal = vertice_adyacente + num_vertices_polilinea;					
			}	
						
			caras.push_back(Tupla3i(i+j, vertice_adyacente, vertice_diagonal));
			caras.push_back(Tupla3i(i+j, vertice_diagonal, vertice_superior));
		}
	}
	
	// Añado las coordenadas de textura
	if (quiero_coord_textura){
		std::vector<float> s(ntraslaciones);
		std::vector<float> d(vertices.size()); //distancia (medida a lo largo del perfil) entre el primer vértice del mismo (v0) y dicho vértice j-ésimo.
		std::vector<float> t(vertices.size());
		
		for (int i = 0; i < ntraslaciones; i++){
			for (int j = 0; j < vertices.size(); j++){
			/* El perfil de partida tiene vertices.size() vértices
			 * Hay ntraslaciones copias del perfil
			 * y en cada copia hay vertices.size() vértices
			 * 
			 * El j-ésimo vértice en la i-ésima copia del perfil es qij
			 * y tendrá unas coordenadas de textura (si, tj) donde si es común a todos los vértices en una copia del perfil.
			 */ 
			 
			 s[i] = i / (ntraslaciones - 1); //coordenada X en el espacio de la textura. Va desde 0 en el 1º perfil hasta 1 en el último de ellos.
			 
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
