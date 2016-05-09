// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 3  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f 
#include "Objeto3D.hpp"
#include "MallaInd.hpp"
#include "practica3.hpp"
#include "matrizg.hpp"
#include "Cilindro.hpp"
#include "NodoGrafoEscena.hpp"
#include "Figurasp3.hpp"
#include <vector>
#include "matrices-tr.hpp"
#include "matrizg.hpp"
#include <math.h>

#define PI 3.14159265359


unsigned p3_objeto_activo = 0 ;
unsigned p3_grado_libertad_activo = 0; //	0 : girar cabina , 1: subir/bajar cabina, 2: girar atraccion  
float giro_cab = 0;
float altura_cab = 0;
float giro_todo = 0;


Atraccion *atraccion = NULL;
NodoGrafoEscena *nodo = NULL; 

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....



// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e 
// incializado OpenGL. 

// Matriz4f MAT_Rotacion(const float ang_gra, const float ex, const float ey, const float ez);

void P3_Inicializar( int argc, char *argv[] )
{
    int n = 8;
    int contador_tras = 10;
    int contador_rot = 45;
    atraccion = new Atraccion(0,0,0);
    nodo = new NodoGrafoEscena;
    
    nodo->agregar(MAT_Traslacion(0.0, 0.0, 10.0));
    nodo->agregar(MAT_Traslacion(-5.0, 0.0, 0.0));
	nodo->agregar(atraccion);
	
    for (int i = 0; i < n; i++){
		nodo->agregar(MAT_Rotacion(45, 0, 1, 0));
		//nodo->agregar(MAT_Traslacion(contador_tras, 0.0, 0.0));
		//nodo->agregar(MAT_Traslacion(0.0, 0.0, 15.0));
		nodo->agregar(MAT_Traslacion(0.0, 0.0, 10.0));
		nodo->agregar(MAT_Traslacion(-5.0, 0.0, 0.0));
		nodo->agregar(new Atraccion(0, 0, 0));
		
		contador_tras = contador_tras + 10;
		contador_rot = contador_rot + 45;
	}
    std::cout << "\nActivado por defecto grado de libertad girar cabina.\n";
    std::cout << "\nGiro de la cabina = " << giro_cab << ".\n";
    std::cout << "\nAltura de la cabina = " << altura_cab << ".\n";
    std::cout << "\nGiro de la atracción = " << giro_todo << ".\n";

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

bool P3_FGE_PulsarTeclaNormal( unsigned char tecla ) 
{
	if (tecla == 'g' || tecla == 'G'){
		if (p3_grado_libertad_activo == 0){
			p3_grado_libertad_activo = 1;
			std::cout << "\nActivado grado de libertad subir/bajar cabina.\n";
			return true;
		}
		
		else if (p3_grado_libertad_activo == 1){
			p3_grado_libertad_activo = 2;
			std::cout << "\nActivado grado de libertad girar atracción.\n";
			return true;
		}
		
		else if (p3_grado_libertad_activo == 2){
			p3_grado_libertad_activo = 0;
			std::cout << "\nActivado grado de libertad girar cabina.\n";
			return true;
		} 	
	}
	
	if (tecla == '>'){ // aumentar el valor del grado de libertad actual
		if (p3_grado_libertad_activo == 0){
				giro_cab = giro_cab + 1;
				atraccion->girarCabina(giro_cab);
				std::cout << "\nGiro de la cabina = " << giro_cab << ".\n";
				return true;
		}
		
		else if (p3_grado_libertad_activo == 1){
			if(altura_cab < 4.0){
				altura_cab = altura_cab + 0.1;
				atraccion->desplazarCabina(altura_cab);
				std::cout << "\nAltura de la cabina = " << altura_cab << ".\n";
			}
			return true;
		}
		
		else if (p3_grado_libertad_activo == 2){
				giro_todo = giro_todo + 1;
				atraccion->girarAtraccion(giro_todo);
				std::cout << "\nGiro de la atracción = " << giro_todo << ".\n";
				return true;
		} 	
	}
	
	if (tecla == '<'){ //disminuir el valor del grado de libertad actual
		if (p3_grado_libertad_activo == 0){
				giro_cab = giro_cab - 1;
				atraccion->girarCabina(giro_cab);
				std::cout << "\nGiro de la cabina = " << giro_cab << ".\n";
				return true;
		}
		
		else if (p3_grado_libertad_activo == 1){
			if (altura_cab > 0.1){
				altura_cab = altura_cab - 0.1;
				atraccion->desplazarCabina(altura_cab);
				std::cout << "\nAltura de la cabina = " << altura_cab << ".\n";
			}
			return true;
		}
		
		else if (p3_grado_libertad_activo == 2){
				giro_todo = giro_todo - 1;
				atraccion->girarAtraccion(giro_todo);
				std::cout << "\nGiro de la atracción = " << giro_todo << ".\n";
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

void P3_DibujarObjetos( unsigned modo ){

	//(*atraccion).visualizar(modo);
	(*nodo).visualizar(modo);
	 
}




/*// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 3  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f 
#include "Objeto3D.hpp"
#include "MallaInd.hpp"
#include "practica3.hpp"
#include "matrizg.hpp"
#include "Cilindro.hpp"
#include "NodoGrafoEscena.hpp"
#include "Figurasp3.hpp"


unsigned p3_objeto_activo = 0 ;
unsigned p3_grado_libertad_activo = 0; //	0 : girar cabina , 1: subir/bajar cabina, 2: girar atraccion  
float giro_cab = 0;
float altura_cab = 0;
float giro_todo = 0;


Atraccion *atraccion = NULL;

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....



// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e 
// incializado OpenGL. 

void P3_Inicializar( int argc, char *argv[] )
{
    
    atraccion = new Atraccion(0,0,0);
    std::cout << "\nActivado por defecto grado de libertad girar cabina.\n";
    std::cout << "\nGiro de la cabina = " << giro_cab << ".\n";
    std::cout << "\nAltura de la cabina = " << altura_cab << ".\n";
    std::cout << "\nGiro de la atracción = " << giro_todo << ".\n";

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

bool P3_FGE_PulsarTeclaNormal( unsigned char tecla ) 
{
	if (tecla == 'g' || tecla == 'G'){
		if (p3_grado_libertad_activo == 0){
			p3_grado_libertad_activo = 1;
			std::cout << "\nActivado grado de libertad subir/bajar cabina.\n";
			return true;
		}
		
		else if (p3_grado_libertad_activo == 1){
			p3_grado_libertad_activo = 2;
			std::cout << "\nActivado grado de libertad girar atracción.\n";
			return true;
		}
		
		else if (p3_grado_libertad_activo == 2){
			p3_grado_libertad_activo = 0;
			std::cout << "\nActivado grado de libertad girar cabina.\n";
			return true;
		} 	
	}
	
	if (tecla == '>'){ // aumentar el valor del grado de libertad actual
		if (p3_grado_libertad_activo == 0){
				giro_cab = giro_cab + 1;
				atraccion->girarCabina(giro_cab);
				std::cout << "\nGiro de la cabina = " << giro_cab << ".\n";
				return true;
		}
		
		else if (p3_grado_libertad_activo == 1){
			if(altura_cab < 4.0){
				altura_cab = altura_cab + 0.1;
				atraccion->desplazarCabina(altura_cab);
				std::cout << "\nAltura de la cabina = " << altura_cab << ".\n";
			}
			return true;
		}
		
		else if (p3_grado_libertad_activo == 2){
				giro_todo = giro_todo + 1;
				atraccion->girarAtraccion(giro_todo);
				std::cout << "\nGiro de la atracción = " << giro_todo << ".\n";
				return true;
		} 	
	}
	
	if (tecla == '<'){ //disminuir el valor del grado de libertad actual
		if (p3_grado_libertad_activo == 0){
				giro_cab = giro_cab - 1;
				atraccion->girarCabina(giro_cab);
				std::cout << "\nGiro de la cabina = " << giro_cab << ".\n";
				return true;
		}
		
		else if (p3_grado_libertad_activo == 1){
			if (altura_cab > 0.1){
				altura_cab = altura_cab - 0.1;
				atraccion->desplazarCabina(altura_cab);
				std::cout << "\nAltura de la cabina = " << altura_cab << ".\n";
			}
			return true;
		}
		
		else if (p3_grado_libertad_activo == 2){
				giro_todo = giro_todo - 1;
				atraccion->girarAtraccion(giro_todo);
				std::cout << "\nGiro de la atracción = " << giro_todo << ".\n";
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

void P3_DibujarObjetos( unsigned modo ){

	(*atraccion).visualizar(modo);
	 
}*/
