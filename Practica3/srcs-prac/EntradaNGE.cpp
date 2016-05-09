#include <vector>
#include "matrices-tr.hpp"
#include "matrizg.hpp"
#include "NodoGrafoEscena.hpp"
#include "aux.hpp"
#include "matrizg_impl.hpp"
#include "Objeto3D.hpp"
#include "EntradaNGE.hpp"
EntradaNGE::EntradaNGE (Objeto3D * pObjeto ) {
     objeto = pObjeto;
     tipoE = 0;
}

EntradaNGE::EntradaNGE (const Matriz4f & pMatriz ){
     matriz = new Matriz4f(pMatriz);
     tipoE = 1;
}
