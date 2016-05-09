#ifndef COLECCIONFL_HPP
#define COLECCIONFL_HPP

#include "FuenteLuz.hpp"
#include "jpg_imagen.hpp"
#include <vector>
//#include "aux.hpp"
//#include <GL/gl.h>
//#include <GL/glu.h>
// ---------------------------------------------------------------------
// Colección de (hasta 8) fuentes de luz.

// Conjunto de fuentes de luz de una escena 
class ColeccionFL
{   
	public:   
		std::vector<FuenteLuz *> fuentes ;  // vector de fuentes de luz
		void activar(  ) ;                  // activa todas las fuentes de luz en el cauce fijo
                                       //   (antes de eso activa iluminación y la configura)
};

#endif
