// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 4  (Material)
// **
// *********************************************************************

#include "material.hpp"

// activa material en el cauce fijo
void MaterialEstandar::activar(){
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color[3]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color[1]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color[2]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, color[0]);
    glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, exponente ) ;
    
    if (text != NULL)
    {
        // Carga la imagen
        glTexImage2D(GL_TEXTURE_2D, 0, 3, text->img->tamX(), text->img->tamY(), 0, GL_RGB, GL_UNSIGNED_BYTE, text->img->leerPixels());
        
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        /*glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
         glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);*/
        
        text->activar();
        glDisable(GL_COLOR_MATERIAL);
    }
    else{
        glDisable(GL_TEXTURE_2D);
    }
}