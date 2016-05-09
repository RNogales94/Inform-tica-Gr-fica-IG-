// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 4  (Textura)
// **
// *********************************************************************

#include "material.hpp"

// activa textura en el cauce fijo de OpenGL
void Textura::activar(  ){
    glEnable(GL_TEXTURE_2D);
    std::cout << "TEXTURA OK"<<std::endl;

}

// crea un textura a partir de un archivo
Textura::Textura( const std::string & archivoJPG ){
    img = new jpg::Imagen(archivoJPG);
    std::cout << "CARGA TEXTURA OK"<<std::endl;

}

