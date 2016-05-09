#ifndef OBJETO3D_HPP
#define OBJETO3D_HPP

#include <string>
#include "material.hpp"

class ContextoVis{
public:
    unsigned modo_vis;
    Material * materialActivo;
    
    ContextoVis(){
        modo_vis = 0;
        materialActivo = NULL;
    }
};

// clase abstracta para objetos 3D visualizables con OpenGL
class Objeto3D
{
protected:
    std::string nombre_obj ; // nombre asignado al objeto
public:
    virtual void visualizar( unsigned modo_vis ) = 0 ; // visualizar el objeto con OpenGL
    virtual void calcularNormales() = 0;
    std::string nombre() ;  // devuelve el nombre del objeto
} ;
#endif