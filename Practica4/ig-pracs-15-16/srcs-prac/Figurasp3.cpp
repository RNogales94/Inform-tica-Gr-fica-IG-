#include "Figurasp3.hpp"

/* 
 * Matriz4f MAT_Traslacion(const float d[3]);
 * Matriz4f MAT_Traslacion(const float dx, const float dy, const float dz);
 * 
 * Matriz4f MAT_Escalado(const float sx, const float sy, const float sz);
 * 
 * Matriz4f MAT_Rotacion(const float ang_gra, const float ex, const float ey, const float ez);
 * 
 */
 
// clase para el nodo del grafo etiquetado como ColumnaIzquierda
ColumnaIzquierda::ColumnaIzquierda(){
	agregar(MAT_Traslacion(1.0, 0.0, 0.0));
	agregar(MAT_Rotacion(45, 0, 1, 0));
	agregar(MAT_Escalado(1, 5, 1));
	agregar(new Cilindro(5));
}

// clase para el nodo del grafo etiquetado como Columna Derecha
ColumnaDerecha::ColumnaDerecha(){
	agregar(MAT_Escalado(1, 5, 1));
	agregar(MAT_Traslacion(9.0, 0.0, 0.0));
	agregar(MAT_Rotacion(45, 0, 1, 0));
	agregar(new Cilindro(5));
}

// clase para el nodo del grafo etiquetado como Cabina
Cabina::Cabina(float giro_inicial, float altura_inicial){
	coord_giro = giro_inicial;
	altura_cabina = altura_inicial;
	
	agregar(MAT_Traslacion(0, 0, 0));
	agregar(MAT_Traslacion(8.28, 0.7, 0.0));
	agregar(MAT_Rotacion(90, 0, 0, 1));
	agregar(MAT_Rotacion(0, 0, 1, 0));
	agregar(MAT_Rotacion(45, 0, 1, 0));
	agregar(MAT_Escalado(1, 6.6, 1));
	agregar(new Cilindro(5));
}

void Cabina::girarCabina(float giro_nuevo){
	//guardar nuevo valor de "alpha"
	coord_giro = giro_nuevo;
	
	//insertar nueva matriz en la primera entrada del array
	*(entradas[3].matriz) = MAT_Rotacion(coord_giro, 0, 1, 0);
}

void Cabina::desplazarCabina(float altura_nueva){
	//guardar nuevo valor de "alpha"
	altura_cabina = altura_nueva;
	
	//insertar nueva matriz en la primera entrada del array
	*(entradas[0].matriz) = MAT_Traslacion(0, altura_cabina, 0);
}

// clase para el nodo del grafo etiquetado como Base
Base::Base(){
	agregar(MAT_Escalado(5, -1, 3));
	agregar(MAT_Traslacion(1.0, 0, 0));
	agregar(new Cilindro(99));
}//radio es 5 y diametro 10

// clase para el nodo del grafo etiquetado como Atracción
Atraccion::Atraccion(float giro_cabina_inicial, float altura_cabina_inicial, float giro_atraccion_inicial){
	giro_atraccion = giro_atraccion_inicial;
	giro_cabina = giro_cabina_inicial;
	altura_cabina = altura_cabina_inicial;
	
	agregar(MAT_Traslacion(5.0, 0.0, 0.0));
	agregar(MAT_Rotacion(giro_atraccion, 0, 1, 0));
	agregar(MAT_Traslacion(-5.0, 0.0, 0.0));
	agregar(new ColumnaDerecha());
	agregar(new ColumnaIzquierda());
	agregar(new Cabina(giro_cabina, altura_cabina));
	agregar(new Base());
	
}

void Atraccion::girarCabina(float giro_cabina_nuevo){
	//guardar nuevo valor de "alpha"
	giro_cabina = giro_cabina_nuevo;
	
	//cambiar matriz en el nodo hijo (segunda entrada)
	Cabina * hijo = (Cabina *)entradas[5].objeto;
	hijo->girarCabina(giro_cabina);

}

void Atraccion::desplazarCabina(float altura_cabina_nueva){
	//guardar nuevo valor de "alpha"
	altura_cabina = altura_cabina_nueva;
	
	//cambiar matriz en el nodo hijo (segunda entrada)
	Cabina * hijo2 = (Cabina *)entradas[5].objeto;
	hijo2->desplazarCabina(altura_cabina);

}

void Atraccion::girarAtraccion(float giro_atraccion_nuevo){
	//guardar nuevo valor de "alpha"
	giro_atraccion = giro_atraccion_nuevo;
	
	//insertar nueva matriz en la primera entrada del array
	*(entradas[1].matriz) = MAT_Rotacion(giro_atraccion, 0, 1, 0);
}
