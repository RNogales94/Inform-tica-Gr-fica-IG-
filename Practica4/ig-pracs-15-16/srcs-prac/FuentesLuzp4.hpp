#ifndef FUENTESLUZP4_HPP
#define FUENTESLUZP4_HPP

#include "FuenteLuz.hpp"
#include "ColeccionFL.hpp"

/* Para construir las fuentes de luz, podemos definir dos clases derivadas de la clase FuenteLuz,
 * una para las direccionales y otra para las posicionales. Asimismo, definimos una clase para la
 * colección concreta de las dos fuentes de luz (como minimo) que se usan en esta práctica 4.*/

class FuenteDireccional : public FuenteLuz
{
	public:
		FuenteDireccional( float alpha_inicial, float beta_inicial ) ;
		void variarAngulo( unsigned angulo, float incremento ) ;  // angulo=0 --> variar alpha, angulo=1 --> variar beta
};


class FuentePosicional : public FuenteLuz
{
	public:
		FuentePosicional( const Tupla3f & posicion ) ;
};


class ColeccionFuentesP4 : public ColeccionFL
{
	public:
		ColeccionFuentesP4() ;
};

#endif
