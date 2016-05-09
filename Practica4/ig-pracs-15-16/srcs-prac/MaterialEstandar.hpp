#ifndef MATERIALESTANDAR_HPP
#define MATERIALESTANDAR_HPP

#include "Material.hpp"
#include "Textura.hpp"
#include "tuplasg.hpp"

// ---------------------------------------------------------------------
// Parámetros de un material estándar (Amb.+Diffuso+Phong)

// Clase derivada concreta para materiales estándar como los vistos en teoría, basados en una componente ambiental, difusa y una pseudo-especular.

/* Las clases derivadas concretas de la clase base abstracta (Material) contienen
 * variables de instancia e implementaciones específicas del método de activación.*/
 
 /* Los materiales concretos usados en esta práctica son instancias de clases derivadas
  * de la clase MaterialEstandard. Cada instancia tiene las reflectividades ambiental,
  * difusa y especular, la emisividad, así como opcionalmente una textura asociada.*/

class MaterialEstandar : public Material          
{  
	public:   
		Textura * text;		// puntero a la textura (NULL si no hay)
		Tupla4f   color[4];		// colores: 0 = emisión, 1 = ambiental, 2 = difuso, 3 = especular
		float     exponente;	// exponente para la componente pseudo-especular
   
		virtual void activar(  );	// activa material en el cauce fijo
									//   si tiene textura: activa uso de la textura 'text'
									//   si no tiene textura: desactiva uso de texturas 
};

#endif
