#include "FuenteLuz.hpp"

/* Cada estructura tiene una función (activar) que configura el cauce fijo de forma que,
 * a partir de la llamada, se usan los parámetros que hay en dicha estructura.
 * 
 * Para configurar el cauce fijo, es necesario activar la colección de fuentes de luz y el material que se va a usar.
 * 
 * La activación de una colección de fuentes supone recorrer todas las fuentes de luz que tiene y activar cada una de ellas (pasándole su índice).*/
 
 /* Con la iluminación desactivada, el color de las primitivas dibujadas depende de una terna RGB del estado interno, que se modifica con
  * glColor.
  * 
  * Con la iluminación activada el MIL se evalua usando unos parámetros incluidos en el estado de OpenGL, y el color resultante obtenido
  * se usa en lugar del especificado con glColor.
  * 
  * (activar o desactivar el MIL es independinte del modo de sombreado activo en cada momento).*/

//Habilita (con glEnable) una fuente de luz OpenGL, configurándola con los parámetros que hay en la instancia.
void FuenteLuz::activar( int i ){
	// activar la i-esima fuente de luz
	glEnable(GL_LIGHT0+i); //glEnable (GL_LIGHTi) activa la i-esima fuente de luz
	
	glEnable(GL_LIGHTING); //activa evaluacion del MIL
	
	// Configuración de colores de una fuente de luz
	glLightfv(GL_LIGHT0 + i, GL_AMBIENT, colores[0]);
	glLightfv(GL_LIGHT0 + i, GL_DIFFUSE, colores[1]);
	glLightfv(GL_LIGHT0 + i, GL_SPECULAR, colores[2]);
	
	// Configuración de posición/dirección de una fuente de luz
	if (posvec(4) == 1){ // fuentes posicionales
		glLightfv(GL_LIGHT0 + i, GL_POSITION, posvec);
	}
	else if (posvec(4) == 0){ // fuentes direccionales
		glLightfv(GL_LIGHT0 + i, GL_POSITION, posvec);
		
		//Posición u orientación de la fuente
		//glRotatef(longitud, 0.0, 1.0, 0.0);
		//glRotatef(lat, -1.0, 0.0, 0.0);
		//glLightf(GL_LIGHTi, GL_POSITION, ejeZ);
	}
	
	
}
