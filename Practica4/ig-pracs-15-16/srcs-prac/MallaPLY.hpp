#ifndef MALLAPLY_HPP
#define MALLAPLY_HPP

#include "MallaInd.hpp"
#include <vector>
#include <file_ply_stl.hpp>
#include "tuplasg.hpp" // Tupla3f

// clase mallas indexadas obtenidas de un archivo PLY
class MallaPLY : public MallaInd
{
   public:
      // constructor
      // se debe especificar el nombre completo del archivo a leer
      MallaPLY( char const * nombre_arch ) ; 
} ;
#endif
