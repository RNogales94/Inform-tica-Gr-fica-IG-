#include "Materialesp4.hpp"

// En cada constructor se le dan valores a los atributos del material, y si es necesario se crea la textura.

MaterialLata::MaterialLata(){
	text = new Textura("text-lata-1.jpg");
	color[0] = Tupla4f(0.5, 0.5, 0.5, 1.0); //emisión
	color[1] = Tupla4f(0.0, 0.0, 0.0, 1.0); //ambiental
	color[2] = Tupla4f(0.2, 0.1, 0.1, 1.0); //difuso
	color[3] = Tupla4f(1.0, 1.0, 1.0, 1.0); //especular
	exponente = 70;
}

MaterialTapasLata::MaterialTapasLata(){
	text = NULL;
	color[0] = Tupla4f(0.192, 0.192, 0.192, 1.0); //emisión
	color[1] = Tupla4f(0.0, 0.0, 0.0, 1.0); //ambiental
	color[2] = Tupla4f(0.3, 0.3, 0.3, 1.0); //difuso
	color[3] = Tupla4f(1.0, 1.0, 1.0, 1.0); //especular
	exponente = 70;
}

MaterialPeonMadera::MaterialPeonMadera(){
	text = new Textura("text-madera.jpg");
	color[0] = Tupla4f(0.5, 0.5, 0.5, 1.0); //emisión
	color[1] = Tupla4f(0.0, 0.0, 0.0, 1.0); //ambiental
	color[2] = Tupla4f(0.2, 0.1, 0.1, 1.0); //difuso
	color[3] = Tupla4f(1.0, 1.0, 1.0, 1.0); //especular
	exponente = 70;
}

MaterialPeonBlanco::MaterialPeonBlanco(){
	text = NULL;
	color[0] = Tupla4f(0.0, 0.0, 0.0, 1.0); //emisión
	color[1] = Tupla4f(0.0, 0.0, 0.0, 1.0); //ambiental
	color[2] = Tupla4f(1.0, 1.0, 1.0, 1.0); //difuso
	color[3] = Tupla4f(0.0, 0.0, 0.0, 1.0); //especular
	exponente = 0;
}

MaterialPeonNegro::MaterialPeonNegro(){
	text = NULL;
	color[0] = Tupla4f(0.0, 0.0, 0.0, 1.0); //emisión
	color[1] = Tupla4f(0.0, 0.0, 0.0, 1.0); //ambiental
	color[2] = Tupla4f(0.0, 0.0, 0.0, 1.0); //difuso
	color[3] = Tupla4f(1.0, 1.0, 1.0, 1.0); //especular
	exponente = 50;
}
