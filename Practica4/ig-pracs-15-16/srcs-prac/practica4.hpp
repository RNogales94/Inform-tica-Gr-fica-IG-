// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 4  (declaraciones públicas)
// **
// *********************************************************************

#ifndef IG_PRACTICA4_HPP
#define IG_PRACTICA4_HPP

// Para evitar colisiones de nombres, es conveniente que todas las funciones declaradas en practica4.hpp (.cpp) tengan un nombre que comienze con P4_..... 

void P4_Inicializar( int argc, char *argv[] ) ;
bool P4_FGE_PulsarTeclaNormal(  unsigned char tecla ) ;
void P4_DibujarObjetos( unsigned modo ) ; 
bool P4_FGE_TeclaEspecial( unsigned char tecla );


#endif
