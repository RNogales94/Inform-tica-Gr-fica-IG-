#include "MallaInd.hpp"

void MallaInd::visualizar( unsigned modo_vis ){
	glEnableClientState(GL_VERTEX_ARRAY); //habilitar array de vértices
	glVertexPointer(3, GL_FLOAT, 0, &vertices[0]); //establecer dirección y estructura //también podría poner &vertices.front
	
	//añadir para que se lean las nuevas coordenadas
	if (normales_vertices.size() != 0){
		glEnableClientState(GL_NORMAL_ARRAY); // habilitar array de normales
		glNormalPointer(GL_FLOAT, 0, &normales_vertices[0]);
	}
	
	if (coordenadas_textura.size() != 0){
		glEnableClientState(GL_TEXTURE_COORD_ARRAY); // habilitar array de coordenadas de textura
		glTexCoordPointer(2, GL_FLOAT, 0, &coordenadas_textura[0]);
	}
		
	//visualizar recorriendo los vértices en el orden de los índices:
	/*for (int i=0; i<caras.size(); i++){
		glPolygonMode( GL_FRONT_AND_BACK, GL_POINT );
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &caras[i]);
	}*/

	//glDrawElements(modo_vis, caras.size()*3, GL_UNSIGNED_INT, &caras[0]);
	
	
	//Como glPolygonMode solo tiene 3 modos: GL_POINT, GL_LINE y GL_FILL, el modo ajedrez lo tenemos que crear nosotros
	
	//También se podría hacer con glDrawElements y sus 3 modos: GL_POINTS, GL_LINE_LOOP Y GL_POLYGON, creando también manualmente el modo ajedrez
	
	glPointSize(8.0);
	
	if (modo_vis == 0){
		for (int i=0; i<caras.size(); i++){
			//glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
			//glDrawElements(GL_POINTS, 3, GL_UNSIGNED_INT, &caras[i]);
			glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &caras[i]);
		}
	}
			
	else if (modo_vis == 1){
		for (int i=0; i<caras.size(); i++){
			//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			//glDrawElements(GL_LINE_LOOP, 3, GL_UNSIGNED_INT, &caras[i]);
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &caras[i]);
		}
	}
			
	else if (modo_vis == 2){
		for (int i=0; i<caras.size(); i++){
			//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			//glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_INT, &caras[i]);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &caras[i]);
		}
	}
		
	else if (modo_vis == 3){
		for (int i=0; i<caras.size(); i++){
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			if ((i%2)==0){
				glColor3f(0.0, 0.0, 0.0); //negro
			}
			else{
				glColor3f(1.0, 1.0, 0.0); //verde
			}
			//glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_INT, &caras[i]);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &caras[i]);
		}
	}
		
	glDisableClientState(GL_VERTEX_ARRAY); //deshabilitar array
	
	if (normales_vertices.size() != 0){
		glDisableClientState(GL_NORMAL_ARRAY);
	}
	
	if (coordenadas_textura.size() != 0){
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

/* Sirve para calcular las tablas de normales de las caras y los vértices, usando las tablas de caras y vértices.
 * Se puede invocar para cualquier malla indexada, en los constructores de las clases derivadas (mallas de revolución
 * y mallas PLY), después de haber creado las tablas de caras y vértices. 
 */
void MallaInd::calcularNormales(){
	//Cálculo de la tabla de normales de caras
	for (int i = 0; i < caras.size(); i++){
		// en cada cara consideramos las posiciones de sus 3 vértices
		int v1 = caras[i](0);
		int v2 = caras[i](1);
		int v3 = caras[i](2);
		
		Tupla3f p = vertices[v1];
		Tupla3f q = vertices[v2];
		Tupla3f r = vertices[v3];
		
		// calculamos los vectores correspondientes a dos aristas
		Tupla3f a = q - p;
		Tupla3f b = r - p;
		
		// calculamos el vector perpendicular a la cara
		// a = {a(0), a(1), a(2)} y b = {b(0), b(1), b(2)}
		//a × b= {a(1)*b(2) - a(2)*b(1); a(2)*b(0) - a(0)*b(2); a(0)*b(1) - a(1)*b(0)}
		/*Tupla3f mc = Tupla3f((a(1) * b(2))-(a(2) * b(1)),
								(a(2) * b(0)) - (a(0) * b(2)),
								(a(0) * b(1)) - (a(1) * b(0)));*/
		Tupla3f mc = a.cross(b);
		
		// obtenemos el vector normal: normalizando mc
		//float nc =  mc / ||mc||;
		Tupla3f nc = mc.normalized();
		
		normales_caras.push_back(nc);
	}
	
	//Cálculo de la tabla de normales de vértices
	/* para cada vertice
	 * 		vertice.normal = 0, 0, 0
	 * 
	 * para cada cara
	 * 		calcular normal
	 * 		para cada vertice en cara
	 * 			vertice.normal += normal de cara
	 * 
	 * para cada vertice
	 * 		vertice.normaliza norma
	 * 
	 */
	for(int i = 0; i < vertices.size(); i++){
		normales_vertices[i] = Tupla3f(0, 0, 0);
	}
	 
	for (int i = 0; i < caras.size(); i++){
		//obtenemos los vértices de cada cara y voy rellenando la tabla de normales de vértices: s = m1 + m2 + ... + mk donde cada mi es la normal de la cara adyacente
		for (int j = 0; j < 3; j++){
			int v1 = caras[i][j];
			normales_vertices[v1] = normales_vertices[v1] + normales_caras[i]; // la normal de dicho vértice va a ser igual a la suma de la normal de las caras adyacentes
		}
	}
	
	// normalizo: n = s/||s||
	for (int i = 0; i < vertices.size(); i++){
		normales_vertices[i] = normales_vertices[i].normalized();
	}
	
}
