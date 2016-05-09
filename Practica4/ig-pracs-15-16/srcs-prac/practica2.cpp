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
#include "MallaTraslacion.hpp"

unsigned p2_objeto_activo = 0 ; // objeto activo: cubo (0), tetraedro (1), otros....
MallaPLY * mallaPLY;
MallaPLY * mallaPLY2;
MallaPLY * mallaPLY3;
MallaRevol * mallaRevol;
MallaTraslacion * mallaTraslacion;

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....



// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e 
// incializado OpenGL. 

void P2_Inicializar( int argc, char *argv[] )
{
	if (argc == 2){
		mallaPLY = new MallaPLY(argv[1]);
		mallaPLY2 = new MallaPLY(argv[1]);
		mallaPLY3 = new MallaPLY(argv[1]);
	}
	
	else{
		mallaPLY = new MallaPLY("beethoven.ply");
		mallaPLY2 = new MallaPLY("ant.ply");
		mallaPLY3 = new MallaPLY("big_dodge.ply");
	}	
	
	mallaRevol = new MallaRevol("peon.ply", 50, false);
	mallaTraslacion = new MallaTraslacion("polilineacerrada.ply", 8, Tupla3f (-1.0, 1.0, -1.0), false);
    
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
	if (tecla == 'o' || tecla == 'O'){
		if (p2_objeto_activo == 0){
			p2_objeto_activo = 1;
			return true;
		}
		
		else if (p2_objeto_activo == 1){
			p2_objeto_activo = 2;
			return true;
		}	
		
		else if (p2_objeto_activo == 2){
			p2_objeto_activo = 3;
			return true;
		}
		
		else if (p2_objeto_activo == 3){
			p2_objeto_activo = 4;
			return true;
		}
		
		else if (p2_objeto_activo == 4){
			p2_objeto_activo = 0;
			return true;
		}
	}
	
	else{
		return false;
	}
	
}


// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez , >=4 otros....

void P2_DibujarObjetos( unsigned modo ){
	
	if (p2_objeto_activo == 0){
		(*mallaPLY).visualizar(modo);
	}
	
	else if (p2_objeto_activo == 1){
		(*mallaPLY2).visualizar(modo);
	}
	
	else if (p2_objeto_activo == 2){
		(*mallaPLY3).visualizar(modo);
	}
	
	else if (p2_objeto_activo == 3){
		(*mallaRevol).visualizar(modo);
	}
	
	else if (p2_objeto_activo == 4){
		(*mallaTraslacion).visualizar(modo);
	}
	 
}
