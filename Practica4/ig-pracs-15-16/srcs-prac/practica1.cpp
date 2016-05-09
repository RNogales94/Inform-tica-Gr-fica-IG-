// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f 
#include "practica1.hpp"
#include "Objeto3D.hpp"
#include "MallaInd.hpp"
#include "Cubo.hpp"
#include "Tetraedro.hpp"
#include "Cono.hpp"
#include "Cilindro.hpp"

unsigned objeto_activo = 0 ; // objeto activo: cubo (0), tetraedro (1), otros....

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....
Cubo * cubo;
Tetraedro * tetraedro;
// cubo y tetraedro son dos variables globales nuevas (son punteros)

Cono * cono;
Cilindro * cilindro;


// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e 
// incializado OpenGL. 

/*	Función P1_Inicializar, para crear las tablas de vértices y caras que se
 *	requieren para la práctica. Esta función se invoca desde main.cpp una única vez al
 *	inicio del programa, cuando ya se ha creado la ventana e inicializado OpenGL.
 */

void P1_Inicializar( int argc, char *argv[] )
{
   cubo = new Cubo();
   tetraedro = new Tetraedro();
   cono = new Cono(121); //pongo un nº impar para que no se repita el último color de las caras
   cilindro = new Cilindro(151); //pongo un nº impar para que no se repita el último color de las caras
   
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

/*	Función P1_FGE_PulsarTeclaNormal, está función se invoca desde
 * 	main.cpp cuando se pulsa una tecla normal, la práctica 1 está activa, y la tecla no
 * 	es procesada en el main.cpp. Sirve para cambiar entre la visualización del
 * 	tetraedro y el cubo (cambiar el valor de la variable objeto_activo) cuando se
 * 	pulsan alguna tecla. Debe devolver true para indicar que la tecla pulsada
 * 	corresponde al cambio de objeto activo, y false para indicar que la tecla no
 * 	corresponde a esta práctica.
 */

bool P1_FGE_PulsarTeclaNormal( unsigned char tecla ) 
{
	
	if (tecla == 'o' || tecla == 'O'){
		if (objeto_activo == 0){
			objeto_activo = 1;
			return true;
		}
		
		else if (objeto_activo == 1){
			objeto_activo = 2;
			return true;
		}
		
		else if (objeto_activo == 2){
			objeto_activo = 3;
			return true;
		}
		
		else if (objeto_activo == 3){
			objeto_activo = 0;
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

/*	Función P1_Redibujar, para dibujar las mallas, usando el parámetro modo_vis
 * 	para determinar el tipo o modo de visualización de primitivas. Esta función se invoca
 * 	desde main.cpp cada vez que se recibe el evento de redibujado.
 */

void P1_DibujarObjetos( unsigned modo ) 
{
	if (objeto_activo == 0){
		(*cubo).visualizar(modo);
	}
	
	else if (objeto_activo == 1){
		(*tetraedro).visualizar(modo);
	}
	
	else if (objeto_activo == 2){
		(*cono).visualizar(modo);
	}
	
	else if (objeto_activo == 3){
		(*cilindro).visualizar(modo);
	}
}
 
 
/* ¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡
 * En el archivo main.cpp es necesario gestionar los eventos de teclado que permiten
 * cambiar el valor de la variable global modo_vis, que determina el modo de visualización actual.
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */
