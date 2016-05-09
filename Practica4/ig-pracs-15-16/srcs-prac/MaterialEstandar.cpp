#include "MaterialEstandar.hpp"

/* Cada estructura tiene una función (activar) que configura el cauce fijo de forma que,
 * a partir de la llamada, se usan los parámetros que hay en dicha estructura.
 * 
 * Para configurar el cauce fijo, es necesario activar la colección de fuentes de luz y el material que se va a usar.
 * 
 * La activación de un material supone enviar sus parámetros al cauce fijo, y si tiene asociada una textura, activar asimismo la textura.*/
void MaterialEstandar::activar(){
	
	//Cuando se habilita un material, se habilita la iluminación de OpenGL, y se configuran los parámetros de material de OpenGL
	//usando las variables o instancias descritas en el hpp.
	
	//Para los materiales que lleven asociada una textura, se llamará a la función o método para activar dicha textura, descrita en Textura.hpp.
	//Si el material no lleva textura, se deben deshabilitar las texturas en OpenGL.
	
	// Emisividad del material
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, color[0]);
	
	// Colores del material
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color[1]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color[2]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color[3]);
	
	// Asignamos el exponente
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, exponente);
	
	if (text != NULL){		
		// Cargamos la imagen.
		glTexImage2D(GL_TEXTURE_2D, 0, 3, text->img->tamX(), text->img->tamY(), 0, GL_RGB, GL_UNSIGNED_BYTE, text->img->leerPixels());
		
		// Seleccionar el texel con centro más cercano al centro del pixel
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		
		//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		
		glEnable(GL_TEXTURE_2D);
		
		text->activar();
		
		glDisable(GL_COLOR_MATERIAL);
	}
	
	else{
		//glEnable(GL_COLOR_MATERIAL);
		glDisable(GL_TEXTURE_2D);
	
	}
} 
