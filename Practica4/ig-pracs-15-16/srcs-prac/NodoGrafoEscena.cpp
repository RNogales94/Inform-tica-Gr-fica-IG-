#include "NodoGrafoEscena.hpp"

EntradaNGE::EntradaNGE(Objeto3D * pObjeto){ //copia solo puntero
	tipoE = 0;
	objeto = pObjeto;
}

EntradaNGE::EntradaNGE(const Matriz4f & pMatriz){ //crea copia
	tipoE = 1;
	
	matriz = new Matriz4f();

	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			(*matriz)(i,j) = pMatriz(i,j);
		}
	}
}

EntradaNGE::EntradaNGE(Material * pMaterial){
	tipoE = 2;
	material = pMaterial;
}

//visualiza usando OpenGL
// El método visualizar dibuja recursivamente estructuras completas.
// Permite dibujar cualquier grafo que yo haya almacenado en memoria
void NodoGrafoEscena::visualizar(unsigned modo_vis){
	glMatrixMode (GL_MODELVIEW); //operaremos sobre la modelview
	glPushMatrix();		//guarda modelview actual
	
	Material * materialActivoInicial = materialActivo;
	
	//recorrer todas las entradas del array que hay en el nodo:
	for (unsigned i=0; i < entradas.size(); i++){
		if (entradas[i].tipoE == 0){ //si la entrada es sub-objeto:
			entradas[i].objeto -> visualizar(modo_vis); //visualizarlo
		}
		
		else if(entradas[i].tipoE == 1){	//si la entrada es transformación:
			glMultMatrixf(*(entradas[i].matriz)); //componerla
		}
		
		else{ //si la entrada es material
			if(entradas[i].material != materialActivo){
					materialActivo = entradas[i].material; //actualizamos la variable local
					entradas[i].material -> activar(); //invocar el metodo para activar dicho material
			}
		}
	}
	
		// restauracion del material original que estaba activo cuando se invocó el método
		if (materialActivoInicial != materialActivo){ // si se ha cambiado el material durante la visualización de este nodo:
			materialActivo = materialActivoInicial; // restaurar el original
			if(materialActivo != NULL) // si el original no era NULL
				materialActivo->activar(); // reactivarlo
		}
	
	
	glMatrixMode(GL_MODELVIEW); //operaremos sobre la modelview
	glPopMatrix();		//restaur modelview guardada
}

//añadir entrada (al final)
void NodoGrafoEscena::agregar(EntradaNGE * entrada){
	entradas.push_back(*entrada);
}

//construir una entrada y añadirla (al final), es decir, crear una EntradaNGE y luego hacer un push_back
void NodoGrafoEscena::agregar(Objeto3D * pObjeto){
	entradas.push_back(EntradaNGE(pObjeto)); //objeto
}

//construir una entrada y añadirla (al final), es decir, crear una EntradaNGE y luego hacer un push_back
void NodoGrafoEscena::agregar(const Matriz4f & pMatriz){
	entradas.push_back(EntradaNGE(pMatriz)); //matriz
}

void NodoGrafoEscena::agregar(Material * pMaterial){
	entradas.push_back(EntradaNGE(pMaterial)); //material
}
