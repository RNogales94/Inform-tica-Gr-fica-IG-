#ifndef FUENTELUZ_HPP
#define FUENTELUZ_HPP

#include "tuplasg.hpp" // Tupla3f
#include "jpg_imagen.hpp"
#include <GL/gl.h>
#include <GL/glu.h>
// ---------------------------------------------------------------------
// Parámetros que definen una fuente de luz

class FuenteLuz
{
	public:   
		Tupla4f  posvec;       // posición (si w=1) o vector (w=0)
		Tupla4f  colores[3];   // colores: 0=ambiental, 1=difuso, 2=especular.
		float longitud, lat;      // ángulos de rotación (fuente direccional modificable interactivamente)
  
		void activar( int i ); // activa la fuente de luz (con número GL_LIGHT0+i) 
};

#endif
