#include "FuentesLuzp4.hpp"

FuenteDireccional::FuenteDireccional( float alpha_inicial, float beta_inicial ){
	longitud = alpha_inicial;
	lat = beta_inicial;
	
	// En este caso w es 0
	posvec = Tupla4f(longitud, 0, lat, 0);
	
	colores[0] = Tupla4f(0.4, 0.4, 0.4, 1.0); //ambiental
	colores[1] = Tupla4f(0.3, 0.3, 0.3, 1.0); //difuso
	colores[2] = Tupla4f(0.3, 0.3, 0.3, 1.0); //especular
}

void FuenteDireccional::variarAngulo( unsigned angulo, float incremento ){ // angulo=0 --> variar alpha, angulo=1 --> variar beta
	if(angulo == 0){
		posvec = posvec + Tupla4f(incremento, 0, 0, 0);
		//longitud = longitud + incremento;	
	}
	
	if(angulo == 1){
		posvec = posvec + Tupla4f(0, 0, incremento, 0);
		//lat = lat + incremento;
	}
		
}

FuentePosicional::FuentePosicional( const Tupla3f & posicion ){
	// En este caso w es 1
	posvec = Tupla4f(posicion[0], posicion[1], posicion[2], 1);	
	
	colores[0] = Tupla4f(0.3, 0.3, 0.3, 1.0); //ambiental
	colores[1] = Tupla4f(0.3, 0.3, 0.3, 1.0); //difuso
	colores[2] = Tupla4f(0.3, 0.3, 0.3, 1.0); //especular
}

ColeccionFuentesP4::ColeccionFuentesP4(){
	
}
