#include "Textura.hpp"

/* Cada estructura tiene una función (activar) que configura el cauce fijo de forma que,
 * a partir de la llamada, se usan los parámetros que hay en dicha estructura.
 * 
 * Para configurar el cauce fijo, es necesario activar la colección de fuentes de luz y el material que se va a usar.*/
 
/* Cuando se habilitan las texturas hay una textura activa en cada momento, que se consulta cada vez que un polígono
 * se proyecta en un pixel, antes de calcular el color de dicho pixel.*/

/* La primera vez que se intente activar una textura, se debe crear la textura: se deben leer los texels de un archivo y enviarlos a la GPU,
 * inicializando el identificador de textura de OpenGL.*/
 
void Textura::activar(){
//habilitar las texturas en OpenGL y habilitar el identificador de textura

	// Habilitar texturas
	glEnable(GL_TEXTURE_2D);
	
	// Hacer id_text igual a un nuevo identificador
	glGenTextures(1, &id_text);
	
	// Activar textura con identificador id_text
	glBindTexture(GL_TEXTURE_2D, id_text);
	
	// Especificación de los texels de la imagen de textura
	glTexImage2D(GL_TEXTURE_2D, 0, 3, img->tamX(), img->tamY(), 0, GL_RGB, GL_UNSIGNED_BYTE, img->leerPixels());
	
	// Determinar como los colores de la textura afectan al MIL, cuando la iluminación y la textura están activadas.
	// Función para que el color de la textura se use en lugar de todas las reflectividades del material
	glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SINGLE_COLOR);
	
	// Selección de texels
	// Hacer interpolación bilineal entre los cuatro texels con centros más cercanos al centro del pixel
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	
	if (mgct == 0){
		// Desactivación de la generación procedural de coordenadas de textura
		glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_GEN_T);	
	}
	
	else if (mgct == 1){
		// Activación de la generación procedural de coordenadas de textura
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
		
		// Tipo de función para generación procedural (coords. de objeto)
		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
		glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
		
		// Especificación de coeficientes (coords. de objeto)
		glTexGenfv(GL_S, GL_OBJECT_PLANE, cs);
		glTexGenfv(GL_T, GL_OBJECT_PLANE, ct);
	}
	
	else if (mgct == 2){
		// Activación de la generación procedural de coordenadas de textura
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
		
		// Tipo de función para generación procedural (coords. de cámara)
		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
		glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
		
		// Especificación de coeficientes (coords. de cámara)
		glTexGenfv(GL_S, GL_EYE_PLANE, cs);
		glTexGenfv(GL_T, GL_EYE_PLANE, ct);
	}
} 

Textura::Textura(const std::string & archivoJPG){
	//cargar la imagen (una sola vez!)
	img = new jpg::Imagen(archivoJPG);

}
