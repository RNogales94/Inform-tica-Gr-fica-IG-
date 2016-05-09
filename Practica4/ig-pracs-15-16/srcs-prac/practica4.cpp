// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 4  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f 
#include "Objeto3D.hpp"
#include "MallaInd.hpp"
#include "matrizg.hpp"
#include "practica4.hpp"
#include "jpg_imagen.hpp"
#include "MallaInd.hpp"
#include "MallaPLY.hpp"
#include "MallaRevol.hpp"
#include "MallaTraslacion.hpp"
#include "NodoGrafoEscena.hpp"
#include "Material.hpp"
#include "MaterialEstandar.hpp"
#include "Materialesp4.hpp"
#include "Textura.hpp"
#include "FuenteLuz.hpp"
#include "ColeccionFL.hpp"
#include "FuentesLuzp4.hpp"

// Es necesario declarar como variables globales las variables que guardan los parámetros de los materiales y el MIL.
unsigned p4_objeto_activo = 0 ;
float angulo_actual = 0;
const int P4_numero_objetos = 1;

NodoGrafoEscena *nodo = NULL; 
MallaRevol *peon = NULL;

ColeccionFL * fuentes_luz = NULL;
FuenteDireccional * fuente_direc = NULL;

int modo_vis_p4 = 0;

/*
MallaInd * peon_madera;
MallaInd * peon_blanco;
MallaInd * peon_negro;
MallaInd * lata_lateral;
MallaInd * lata_superior;
MallaInd * lata_inferior;

FuenteLuz * luz_direccional;
FuenteLuz * luz_posicional;

Material * material_peon_madera;
Material * material_peon_blanco;
Material * material_peon_negro;
Material * material_lata;
Material * material_tapas;

Textura * madera;
Textura * coca_cola;

NodoGrafoEscena * nodo_escena;
NodoGrafoEscena * nodo_peon_madera;
NodoGrafoEscena * nodo_peon_blanco;
NodoGrafoEscena * nodo_peon_negro;
NodoGrafoEscena * nodo_lata;*/




// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....



// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e 
// incializado OpenGL.

/* La función P4_Inicializar debe usarse para cualquier inicialización que requiera la práctica 4.
 * Como mínimo, habrá que cargar las texturas y crear los materiales y las fuentes de luz
 * (dandoles valores iniciales a las estructuras o clases relacionadas)
 */ 

void P4_Inicializar( int argc, char *argv[] )
{
	fuentes_luz = new ColeccionFL;
	
	glEnable(GL_RESCALE_NORMAL);
	
	FuenteLuz * fuente_pos1 = new FuentePosicional(Tupla3f(-10.0, 10.0, 10.0));
	FuenteLuz * fuente_pos2 = new FuentePosicional(Tupla3f(5.0, -3.0, 5.0));
	fuente_direc = new FuenteDireccional(5, 5);
	
	peon = new MallaRevol("peon.ply", 100, true);
	nodo = new NodoGrafoEscena;

	nodo->agregar(MAT_Traslacion(0,1.4,3));
	nodo->agregar(new MaterialPeonMadera());
	nodo->agregar(peon);
	nodo->agregar(MAT_Traslacion(3,0,0));
	nodo->agregar(new MaterialPeonBlanco());
	nodo->agregar(peon);
	nodo->agregar(MAT_Traslacion(3,0,0));
	nodo->agregar(new MaterialPeonNegro());
	nodo->agregar(peon);
	
    fuentes_luz->fuentes_luz.push_back(fuente_pos1);
    fuentes_luz->fuentes_luz.push_back(fuente_pos2);
    fuentes_luz->fuentes_luz.push_back(fuente_direc);

	fuentes_luz->activar();
	
	/*coca_cola = new Textura("lata-coke.jpg");
	madera = new Textura("text-madera.jpg");
	
	material_lata = new MaterialLata();
	material_tapas = new MaterialTapasLata();
	material_peon_madera = new MaterialPeonMadera();
	material_peon_blanco = new MaterialPeonBlanco();
	material_peon_negro = new MaterialPeonNegro();
	
	nodo_lata = new NodoGrafoEscena();
	nodo_lata ->agregar();
	nodo_peon_madera 
	nodo_peon_blanco
	nodo_peon_negro
	
	luz_direccional = new FuenteDireccional(0, 0);
	luz_posicional = new FuentePosicional();*/

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

bool P4_FGE_PulsarTeclaNormal( unsigned char tecla ) 
{
	/*acceder y modificar los valores actuales de los parámetros
	 * que determinan el material y las fuentes de luz.*/
	
	// Conmutar entre el ángulo alpha y el ángulo beta
	if (tecla == g || tecla == G){
		if (angulo_actual == 0){
			angulo_actual = 1;
			return true;
		}
		
		else if (angulo_actual == 1){
			angulo_actual = 0;
			return true;
		}
	}
	
	// Aumentar el valor del ángulo actual
	if (tecla == >){
		fuente_direc->variarAngulo(angulo_actual, 2);
		fuentes_luz->activar();
		return true;
	}
	
	// Disminuir el valor del ángulo actual
	if (tecla == <){
		fuente_direc->variarAngulo(angulo_actual, -2);
		fuentes_luz->activar();
		return true;	
	}
	
	else{
		return false;
	}
}


// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez , >=4 otros....

void P4_DibujarObjetos( unsigned modo ){
	
	if (P4_objeto_activo == 0){
		nodo -> activar();
	}	
	
	/*glEnable( GL_LIGHTING );
	glEnable( GL_NORMALIZE );
	glDisable( GL_COLOR_MATERIAL );
	
	luz_direccional->activar();
	luz_posicional->activar();

	nodo_escena->visualizar();

	luz_direccional->desactivar();
	luz_posicional->desactivar();

	glDisable( GL_LIGHTING );
	glDisable( GL_NORMALIZE );
	glEnable( GL_COLOR_MATERIAL );	*/ 
}


bool P4_FGE_PulsarTeclaEspecial( unsigned char tecla ){

	

}
