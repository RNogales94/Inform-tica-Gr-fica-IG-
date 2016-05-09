#include <vector>
#include "matrices-tr.hpp"
#include "matrizg.hpp"
#include "NodoGrafoEscena.hpp"
#include "aux.hpp"
#include "matrizg_impl.hpp"
#include "Objeto3D.hpp"

using namespace std;

void NodoGrafoEscena::visualizar (unsigned cv){
    glMatrixMode(GL_MODELVIEW); // operamos sobre la ModelView
    glPushMatrix();             // guarda modelview actual
    
    Material * materialActivoInicial = materialActivo;

    //recorrer todas las entradas del array que hay en el nodo
    for(unsigned i = 0; i< entradas.size(); i++){
        if (entradas[i].tipoE == 0){                      //Si la entrada es un objeto (tipoE == 0)
            entradas[i].objeto->visualizar(cv);
            entradas[i].objeto->calcularNormales();
        }
        else if(entradas[i].tipoE == 1){                    //Si la entrada es una transformacion (tipoE == 1)
            glMultMatrixf(*(entradas[i].matriz));
        }
        else if(entradas[i].tipoE == 2){
            if ( entradas[i].material != materialActivo) { //Activar materiales es costoso!!
                entradas[i].material->activar();
                materialActivo = entradas[i].material;
            }
            else{
              //  cout << "TEXTURE DISABLE" << endl;
              //  glDisable(GL_TEXTURE_2D);
            }
        }
    }
    // si ha cambiado el material durante la vis. de este nodo lo reactivamos:
    if ( materialActivoInicial != materialActivo )
    {
        materialActivo = materialActivoInicial ;    // restaurar el original en 'cv'
        if ( materialActivo != NULL ){              // si el original no era NULL
            materialActivo->activar();              //    reactivarlo
        }
    }
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();


}

void NodoGrafoEscena::agregar( EntradaNGE * entrada){
    entradas.push_back(*entrada);
}
void NodoGrafoEscena::agregar( Objeto3D *pObjeto){
    EntradaNGE entrada(pObjeto);
    entradas.push_back(entrada);

}
void NodoGrafoEscena::agregar( const Matriz4f & pMatriz){
    EntradaNGE entrada(pMatriz);
    entradas.push_back(entrada);
}
void NodoGrafoEscena::agregar(Material* pMaterial){
    entradas.push_back(EntradaNGE(pMaterial));
}

void NodoGrafoEscena::calcularNormales(){
    for(int i = 0; i < entradas.size(); i++){
        if(entradas[i].tipoE == 0){
            entradas[i].objeto->calcularNormales();
        }
    }

}


