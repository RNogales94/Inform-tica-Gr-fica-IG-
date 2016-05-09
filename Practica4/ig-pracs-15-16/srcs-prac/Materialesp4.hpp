#ifndef MATERIALESP4_HPP
#define MATERIALESP4_HPP

#include "MaterialEstandar.hpp"

/* En la práctica serán necesarios 5 tipos de materiales: el de la lata (con textura de Coca-Cola),
 * el del peón de madera (con la textura de madera), y el de las tapas de la lata, el del peón negro
 * y el peón blanco (todos ellos sin textura). Para cada tipo de material definiremos una clase derivada
 * de Material, clase que únicamente añade un constructor. En cada constructor se le dan valores a los
 * atributos del material, y si es necesario se crea la textura.*/

class MaterialLata : public MaterialEstandar
{
	public:
		MaterialLata() ;
};


class MaterialTapasLata : public MaterialEstandar
{
	public:
		MaterialTapasLata() ;
};


class MaterialPeonMadera : public MaterialEstandar
{
	public:
		MaterialPeonMadera() ;
};


class MaterialPeonBlanco : public MaterialEstandar
{
	public:
		MaterialPeonBlanco() ;
};


class MaterialPeonNegro : public MaterialEstandar
{
	public:
		MaterialPeonNegro() ;
};

#endif
