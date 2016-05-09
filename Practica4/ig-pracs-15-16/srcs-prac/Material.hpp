#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "jpg_imagen.hpp"
#include "Textura.hpp"

// Clase abstracta para materiales

// La clase base abstracta para cualquier tipo de material contiene un único método virtual puro para activarla.
class Material{
	public:
		virtual void activar() = 0;
};

#endif
