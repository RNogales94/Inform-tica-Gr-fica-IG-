#ifndef TEXTURA_HPP
#define TEXTURA_HPP

#include "jpg_imagen.hpp"
#include "MaterialEstandar.hpp"
//#include "jpg_imagen.cpp"
//#include "jpg_memsrc.cpp"
//#include "jpg_readwrite.cpp"
#include "jpg_jinclude.h"
#include "aux.hpp"
#include <GL/gl.h>
#include <GL/glu.h>

// ---------------------------------------------------------------------
// Imagen de textura  

/* Las texturas tienen asociado, esencialmente, el identificador de textura, lo cual permite activarlas.
 * Tambien incluyen diversos parámetros para activar o desactivar la generación automática de coordenadas de textura.*/ 

class Textura
{  
	public:   
		GLuint        id_text ;    // identificador OpenGL de la textura
		jpg::Imagen * img;		   // puntero a imagen con los texels
		unsigned      mgct ;       // modo de gen. cc.tt. (0 = desactivado, 1 = objeto, 2 = camara)
		float         cs[4],ct[4]; // coeficientes para generación de coords. de textura
   
		void activar(  );          // activa textura en el cauce fijo de OpenGL
		Textura( const std::string & archivoJPG ) ; // crea un textura a partir de un archivo
};

#endif
