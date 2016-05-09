#include "MallaInd.hpp"
#include <file_ply_stl.hpp>


// clase mallas indexadas obtenidas de un archivo PLY
class MallaRevol : public MallaInd
{
		
	public:
	// constructor
	// se debe especificar: el nombre completo del archivo a leer
	//                      el número de copias del perfil
      
		MallaRevol( const char * nombre_arch, unsigned nperfiles, bool quiero_coord_textura ) ; 
} ;
