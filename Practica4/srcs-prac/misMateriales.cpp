// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 4  (Tipos de materiales)
// **
// *********************************************************************


#include "misMateriales.hpp"
// colores: 0=emisión, 1=ambiental, 2=difuso, 3=especular

MaterialLata::MaterialLata(){
    text = new Textura("text-lata-1.jpg");
    color[0] = Tupla4f( 0.5, 0.5, 0.5, 1.0 );
    color[1] = Tupla4f( 0, 0, 0, 1.0 );
    color[2] = Tupla4f( 0.2, 0.1, 0.1, 1.0 );
    color[3] = Tupla4f(1.0, 1.0, 1.0, 1.0);
    exponente = 30;
}

MaterialTapasLata::MaterialTapasLata(){
    text = NULL;
    color[1] = Tupla4f( 0.2, 0.2, 0.2, 1.0 );
    color[2] = Tupla4f( 0.5, 0.5, 0.5, 1.0 );
    color[3] = Tupla4f( 0.5, 0.5, 0.5, 1.0 );
    color[0] = Tupla4f(0.2, 0.2, 0.2, 1.0);
    exponente = 0;
}

MaterialPeonBlanco::MaterialPeonBlanco(){
    text = NULL;
    color[0] = Tupla4f( 0, 0, 0, 1.0 );
    color[1] = Tupla4f( 0.9, 0.9, 0.9, 1.0 );
    color[2] = Tupla4f( 0.8, 0.8, 0.8, 1.0);
    color[3] = Tupla4f( 0.8, 0.8, 0.8, 1.0 );
    exponente = 70;
}

MaterialPeonNegro::MaterialPeonNegro(){
    text = NULL;
    color[0] = Tupla4f( 0.0, 0.0, 0.0, 1.0 );
    color[1] = Tupla4f( 0.0, 0.0, 0.0, 1.0 );
    color[2] = Tupla4f( 0.0, 0.0, 0.0, 1.0 );
    color[3] = Tupla4f(1.0, 1.0, 1.0, 1.0);
    exponente = 50;
}

MaterialPeonMadera::MaterialPeonMadera(){
    text = new Textura("text-madera.jpg");
    color[0] = Tupla4f( 0.5, 0.5, 0.5, 1.0 );
    color[1] = Tupla4f( 0, 0, 0, 1.0 );
    color[2] = Tupla4f( 0.2, 0.1, 0.1, 1.0 );
    color[3] = Tupla4f(1.0, 1.0, 1.0, 1.0);
    exponente = 70;
}




























