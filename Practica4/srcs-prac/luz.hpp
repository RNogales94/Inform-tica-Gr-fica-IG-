// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 4  (Clase Fuentes de Luz)
// **
// *********************************************************************

#ifndef IG_LUZ_HPP
#define IG_LUZ_HPP

#include <vector>
#include "aux.hpp" //Constantes GL_LIGHT0, GL_LIGHT0+i 
#include "tuplasg.hpp"

// ---------------------------------------------------------------------
// Fuente de Luz clase base generica
// ---------------------------------------------------------------------

class FuenteLuz
{
public:
    Tupla4f  posvec ;       // posición (si w=1) o vector (w=0)
    Tupla4f  colores[3] ;   // colores: 0=ambiental, 1=difuso, 2=especular.
    float    longitud,latitud;      // ángulos de rotación (fuente direccional modificable interactivamente)
    
    void activar( int i ) ; // activa la fuente de luz (con número GL_LIGHT0+i)
    void desactivar( int i ) ; // desactiva la fuente de luz (con número GL_LIGHT0+i)

} ;

// ---------------------------------------------------------------------
// Fuente de luz que parte desde el infinito en una direccion (rayos paralelos)
// ---------------------------------------------------------------------
class FuenteDireccional : public FuenteLuz
{
public:
    FuenteDireccional( float alpha_inicial, float beta_inicial ) ;
    void variarAngulo( unsigned angulo, float incremento ) ;  // angulo=0 --> variar alpha, angulo=1 --> variar beta
};
// ---------------------------------------------------------------------
// Fuente de luz que parte de un punto concreto en todas las direcciones
// ---------------------------------------------------------------------
class FuentePosicional : public FuenteLuz
{
public:
    FuentePosicional( const Tupla3f & posicion ) ;
};
// ---------------------------------------------------------------------
// Colección de (hasta 8) fuentes de luz.
// ---------------------------------------------------------------------

class ColeccionFL
{
public:
    std::vector<FuenteLuz *> fuentes ;  // vector de fuentes de luz
    void activar() ;                  // activa todas las fuentes de luz en el cauce fijo
    //   (antes de eso activa iluminación y la configura)
    void desactivar() ;                  // desactiva todas las fuentes de luz en el cauce fijo

} ;



class ColeccionFuentesP4 : public ColeccionFL
{
public:
    ColeccionFuentesP4() ;
};



#endif
