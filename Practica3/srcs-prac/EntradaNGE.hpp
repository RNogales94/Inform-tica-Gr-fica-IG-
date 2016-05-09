#ifndef IG_ENTRADANGE_HPP
#define IG_ENTRADANGE_HPP


#include<vector>
#include "matrices-tr.hpp"
#include "matrizg.hpp"
#include "aux.hpp"
#include "matrizg_impl.hpp"
#include "Objeto3D.hpp"
//Entrada del nodo del Grafo de Escena
class EntradaNGE
{
public:
    unsigned char tipoE; //0=objeto, 1=transformacion
    union
    {
        Objeto3D * objeto; //ptr. a un objeto (propietario)
        Matriz4f * matriz; //ptr. a matriz 4x4 transf. (prop.)
    } ;
    // constructores (uno por tipo)
    EntradaNGE (Objeto3D * pObjeto ) ;      // (copia solo puntero)
    EntradaNGE (const Matriz4f & pMatriz ); // (crea copia)
} ;

#endif
