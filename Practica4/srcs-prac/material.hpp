// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 4  (Clase Material)
// **
// *********************************************************************

#ifndef IG_MATERIAL_HPP
#define IG_MATERIAL_HPP


#include "textura.hpp"
#include "tuplasg.hpp"
#include "aux.hpp"


class Material
{
  public:
    virtual void activar ( ) = 0;
    
};

class MaterialEstandar  : public Material
{
public:
    
    Textura * text  ;        // puntero a la textura (NULL si no hay)
    Tupla4f   color[4] ;    // colores: 0=emisión, 1=ambiental, 2=difuso, 3=especular
    float     exponente ;   // exponente para la componente pseudo-especular
    
    virtual void activar();// activa material en el cauce fijo
    //   si tiene textura: activa uso de la textura 'text'
    //   si no tiene textura: desactiva uso de texturas
} ;


#endif



























