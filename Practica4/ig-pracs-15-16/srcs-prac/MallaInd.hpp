#ifndef MALLAIND_HPP
#define MALLAIND_HPP

#include "Objeto3D.hpp"
#include "tuplasg.hpp" 
#include <vector>

/* Las mallas indexadas son mallas de triángulos modeladas con una tabla de coordenadas de vértices y una tabla de caras
 * (que contiene ternas de valores enteros). Se pueden visualizar con OpenGL en modo inmediato usando la instrucción
 * glDrawElements o bien glBegin/glEnd (mucho menos eficiente). Para implementar este tipo de mallas crearemos una
 * clase (MallaInd), derivada de Objeto3D y que contiene:
 * 	- Como variables de instancia privadas, la tabla de coordenadas de vértices y la tabla de caras. La primera puede ser
 * 		un vector stl con entradas de tipo Tupla3f, y la segunda un vector stl con entradas tipo Tupla3i.
 * 	- Como método público virtual, el método visualizar, que visualiza la malla teniendo en cuenta el parámetro modo, y
 * 		usando las dos tablas descritas arriba.
 * 
 * La declaración de esta clase se puede poner en un archivo de nombre MallaInd.hpp, y su implementación en MallaInd.cpp.
 * Es necesario añadir al archivo makefile el nombre MallaInd (en units_loc), para lograr que este archivo se compile y enlace con el resto. 
 */ 


//	clase para mallas indexadas o mallas TVT
class MallaInd : public Objeto3D
{
	
protected:
	// declarar aquí tablas de vértices y caras
	std::vector<Tupla3f> vertices; 
	std::vector<Tupla3i> caras;
	
	// tablas de normales de vértices y caras
	std::vector<Tupla3f> normales_vertices; 
	std::vector<Tupla3f> normales_caras;
	
	// coordenadas de textura
	std::vector<Tupla2f> coordenadas_textura;
	
	
public:
	virtual void visualizar( unsigned modo_vis ) ;
	void calcularNormales();
	
} ;

#endif
