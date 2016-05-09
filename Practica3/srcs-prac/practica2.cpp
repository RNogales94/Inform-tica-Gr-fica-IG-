// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 2  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica2.hpp"
#include "MallaPLY.hpp"
#include "MallaRevol.hpp"
#include "Objeto3D.hpp"
#include "rotacion.hpp"

const int P2_numero_objetos = 4;
unsigned P2_objeto_activo = 0 ; // objeto activo: cubo (0), tetraedro (1), otros....

// ---------------------------------------------------------------------
// declaraciones de clases para organizacion de datos....





// declaraciones de estructuras de datos....
static MallaPLY* ant;
static MallaPLY* car;
static MallaPLY* bethoven;

static MallaRevol* peon;





// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// incializado OpenGL.

void P2_Inicializar( int argc, char *argv[] )
{
    ant = new MallaPLY("../plys/ant.ply");
    peon = new MallaRevol("../plys/peon.ply", 50);
    bethoven = new MallaPLY("../plys/beethoven.ply");
    car = new MallaPLY("../plys/big_dodge.ply");
    
}

// ---------------------------------------------------------------------
// Función invocada al pulsar una tecla con la práctica 1 activa:
// (si la tecla no se procesa en el 'main').
//
//  - devuelve 'true' si la tecla se usa en esta práctica para cambiar
//    entre el cubo, el tetraedro u otros objetos (cambia el valor de
//    'objeto_activo').
//  - devuelve 'false' si la tecla no se usa en esta práctica (no ha
//    cambiado nada)

bool P2_FGE_PulsarTeclaNormal( unsigned char tecla )
{
    if (tecla=='o' || tecla=='O') {
        P2_objeto_activo = (P2_objeto_activo+1) %P2_numero_objetos;
        return true;
    }
    else
        return false;
}


// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez , >=4 otros....

void P2_DibujarObjetos( unsigned modo )
{
    // objeto activo: hormiga (0), peon (1)
    if (P2_objeto_activo==0) {
        glPushMatrix();
        glScalef (0.06, 0.06, 0.06);
        glRotatef(40,0,-1,0);
        ant->visualizar(modo);
        glPopMatrix();
    }
    
    if (P2_objeto_activo==1) {
        glPushMatrix();
        glScalef (0.5, 0.5, 0.5);
        peon->visualizar(modo);
        glPopMatrix();

    }
    
    if (P2_objeto_activo==2) {
        glPushMatrix();
        glScalef (0.1, 0.1, 0.1);
        bethoven->visualizar(modo);
        glPopMatrix();
    }
    
    if (P2_objeto_activo==3) {
        glPushMatrix();
        glScalef (0.1, 0.1, 0.1);
        car->visualizar(modo);
        glPopMatrix();
    }
 
}
