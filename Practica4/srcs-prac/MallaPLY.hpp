#ifndef IG_MALLAPLY_HPP
#define IG_MALLAPLY_HPP

#include "mallaInd.hpp"
using namespace std;
// clase mallas indexadas obtenidas de un archivo PLY
class MallaPLY : public MallaInd
{
public:
    // constructor
    // se debe especificar el nombre completo del archivo a leer
    MallaPLY( const char * nombre_arch ) ;
} ;

#endif