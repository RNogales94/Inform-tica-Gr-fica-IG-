// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 4  (Clase Textura)
// **
// *********************************************************************

#ifndef IG_TEXTURA_HPP
#define IG_TEXTURA_HPP

#include "jpg_imagen.hpp"
#include "aux.hpp" // GLuint ...


class Textura
{
public:
    GLuint        id_text ;    // identificador OpenGL de la textura
    jpg::Imagen * img ;        // puntero a imagen con los texels
    unsigned      mgct ;       // modo de gen. cc.tt. (0 = desactivado, 1 = objeto, 2 = camara)
    float         cs[4],ct[4]; // coeficientes para generación de coords. de textura
    
    void activar(  );          // activa textura en el cauce fijo de OpenGL
    Textura( const std::string & archivoJPG ) ; // crea un textura a partir de un archivo
} ;


#endif
























