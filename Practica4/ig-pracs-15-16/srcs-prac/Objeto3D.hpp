#ifndef OBJETO3D_HPP
#define OBJETO3D_HPP

#include <string>
#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f

/* La implementación de los diversos tipos de objetos 3D a visualizar en las prácticas se hará mediante
 * la declaración de clases derivadas de una clase base, llamada Objeto3D, con un método virtual llamado visualizar.
 * 
 * 	Cualquier tipo de objeto que pueda ser visualizado en pantalla con OpenGL se implementará con una clase derivada
 * de esta, que contendrá una implementación concreta del método virtual visualizar. El parámetro modo_vis servirá
 * para distinguir el modo de visualización que se requiere, y que puede ser puntos (0), alambre (1), solido (2),
 * ajedrez (3) u otros. La declaración de la clase se hará en un archivo de cabecera llamado Objeto3D.hpp.
 * La implementación se incluirá en Objeto3D.cpp, y en ese archivo se pondrá la implementación del método nombre
 * (que simplemente devuelve nombre_obj, y se puede usar para depurar). Es necesario añadir al archivo makefile el
 * nombre Objeto3D (en units_loc), para lograr que el nuevo archivo se compile y enlace con el resto.
 */


// clase abstracta para objetos 3D visualizables con OpenGL
class Objeto3D
{
	
protected:
	std::string nombre_obj ; // nombre asignado al objeto
	
public:
	virtual void visualizar( unsigned modo_vis ) = 0 ; // visualizar el objeto con OpenGL
	std::string nombre() ; // devuelve el nombre del objeto
	
} ;

#endif
