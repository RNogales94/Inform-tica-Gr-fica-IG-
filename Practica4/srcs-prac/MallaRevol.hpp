#ifndef IG_MALLAREVOL_HPP
#define IG_MALLAREVOL_HPP

#include "mallaInd.hpp"
using namespace std;
// clase mallas indexadas obtenidas de un archivo PLY
class MallaRevol : public MallaInd
{
public:
    // constructor
    // se debe especificar: el nombre completo del archivo a leer
    //                      el número de copias del perfil
    
    MallaRevol( const char * nombre_arch, unsigned nperfiles ) ;
    
    
    // constructor 2
    // se debe especificar: el nombre completo del archivo a leer
    //                      el número de copias del perfil
    //                      si se quieren coordenadas de textura
    //                      si es una tapa
    MallaRevol( const char * nombre_arch, unsigned nperfiles, bool coordtext, bool esTapa);
} ;

#endif