#include "MallaInd.hpp"
#include <file_ply_stl.hpp>


// clase mallas indexadas obtenidas de un archivo PLY
class MallaTraslacion : public MallaInd
{
   public:
      // constructor
      // se debe especificar: el nombre completo del archivo a leer
      //                      el número de copias del perfil
      
      MallaTraslacion( const char * nombre_arch, unsigned ntraslaciones, Tupla3f vector_traslacion, bool quiero_coord_textura ) ; 
} ;
