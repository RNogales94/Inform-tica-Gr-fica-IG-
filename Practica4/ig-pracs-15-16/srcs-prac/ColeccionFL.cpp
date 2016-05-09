#include "ColeccionFL.hpp"

//activar iluminación y configurarla

// activar todas las fuentes de luz en el cauce fijo
void ColeccionFL::activar(){
	// Configuración de colores de las fuentes de luz
	for (int i = 0; i < fuentes.size(); i++){
		glLightfv(GL_LIGHT0 + i, GL_AMBIENT, fuentes[i]->colores[0]);
		glLightfv(GL_LIGHT0 + i, GL_DIFFUSE, fuentes[i]->colores[1]);
		glLightfv(GL_LIGHT0 + i, GL_SPECULAR, fuentes[i]->colores[2]);
	}
	
	glEnable(GL_DEPTH_TEST); //activa el buffer de profundidad
	glEnable(GL_LIGHTING); //activa evaluacion del MIL
	
	for (int i = 0; i < fuentes.size(); i++){
		fuentes[i]->activar(i);
	}
}

//la activación de la colección supone: activar iluminación, y activar todas las fuentes de luz presentes (llamando a activar de las fuentes)
