// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 4  (Luz)
// **
// *********************************************************************

#include "luz.hpp"

// activa la fuente de luz (con número GL_LIGHT0+i)
//GL_LIGHT0 es una constante de OpenGl que simboliza la primera fuentes de luz.
//Las fuentes de luz se almacenan consecutivamente en OpenGl

void FuenteLuz::activar( int i ) {
    glEnable(GL_LIGHT0+i);
}

void FuenteLuz::desactivar( int i ) {
    glDisable(GL_LIGHT0+i);
}

//Constructor de una fuente direccional
FuenteDireccional::FuenteDireccional( float alpha_inicial, float beta_inicial ){
    // posición (si w=1) o vector (w=0)
    posvec = Tupla4f(alpha_inicial, 0, beta_inicial, 0); //en este caso w=0
    // colores[]: 0=ambiental, 1=difuso, 2=especular.
    colores[0] = Tupla4f(0.4 ,0.4 ,0.4 , 1.0);
    colores[1] = Tupla4f(0.3, 0.3, 0.3 , 1.0);
    colores[2] = Tupla4f(0.7, 0.7, 0.7 , 1.0);
}

void FuenteDireccional::variarAngulo( unsigned angulo, float incremento ){
    if(angulo == 0)
        posvec = posvec+Tupla4f(incremento,0,0,0);
    else
        posvec = posvec+Tupla4f(0,0,incremento,0);
    std::cout << posvec << std::endl;
}

//Constructor de una fuente posicional
FuentePosicional::FuentePosicional( const Tupla3f & posicion ){
    // posición (si w=1) o vector (w=0)
    posvec = Tupla4f(posicion[0], posicion[1], posicion[2], 1); //en este caso w=1
    // colores[]: 0=ambiental, 1=difuso, 2=especular.
    colores[0] = Tupla4f(0.4 ,0.4 ,0.4 , 1.0);
    colores[1] = Tupla4f(0.3, 0.3, 0.3 , 1.0);
    colores[2] = Tupla4f(0.7, 0.7, 0.7 , 1.0);
}



// activa todas las fuentes de luz en el cauce fijo
//   (antes de eso activa iluminación y la configura)
void ColeccionFL::activar() {
    for(int i=0; i<fuentes.size();i++){
        glLightfv(GL_LIGHT0+i, GL_POSITION, fuentes[i]->posvec);
        glLightfv( GL_LIGHT0+i, GL_AMBIENT, fuentes[i]->colores[0] );  // hace SiA := (ra, ga, ba)
        glLightfv( GL_LIGHT0+i, GL_DIFFUSE, fuentes[i]->colores[1] );  // hace SiD := (rd, gd, bd)
        glLightfv( GL_LIGHT0+i, GL_SPECULAR, fuentes[i]->colores[2] ); // hace SiS := (rs , gs , bs)
    }
    glEnable(GL_DEPTH_TEST);   //Activa el buffer de profundidad.
    glEnable(GL_LIGHTING);     //Activa la iluminacion
    for(int i=0; i<fuentes.size(); i++){
        fuentes[i]->activar(i);
        std::cout << "ACTIVANDO LUZ"<< i << std::endl;
    }
}

// activa todas las fuentes de luz en el cauce fijo
//   (antes de eso activa iluminación y la configura)
void ColeccionFL::desactivar() {
    glDisable(GL_DEPTH_TEST);   //Activa el buffer de profundidad.
    glDisable(GL_LIGHTING);     //Activa la iluminacion
    for(int i=0; i<fuentes.size(); i++){
        fuentes[i]->desactivar(i);
        std::cout << "DESACTIVANDO LUZ" << i << std::endl;
    }
}




