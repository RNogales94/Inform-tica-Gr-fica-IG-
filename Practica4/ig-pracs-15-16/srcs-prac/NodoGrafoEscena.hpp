#ifndef NODOGRAFOESCENA_HPP
#define NODOGRAFOESCENA_HPP

#include "Objeto3D.hpp"
#include "MallaInd.hpp"
#include "matrizg.hpp"
#include <vector>
#include "Material.hpp"
#include "MaterialEstandar.hpp"

/*
//Cada entrada del nodo puede ser una instancia de esta clase:
//Entrada del nodo del Grafo de Escena
struct EntradaNGE{
	unsigned char tipoE; //0=objeto, 1=transformación
	
	union{
		Objeto3D * objeto;	//puntero a un objeto (propietario)
		Matriz4f * matriz;	//puntero a matriz 4x4 transformación (propietario)
	};
	
	//constructores (uno por tipo)
	EntradaNGE(Objeto3D * pObjeto);	//copia solo un puntero
	EntradaNGE(const Matriz4f & pMatriz);	//crea copia
};*/

//AMPLIACIÓN EntradaNGE
struct EntradaNGE{
	unsigned char tipoE; //0=objeto, 1=transformación, 2=material
	
	union{
		Objeto3D * objeto;	//puntero a un objeto (propietario)
		Matriz4f * matriz;	//puntero a matriz 4x4 transformación (propietario)
		Material * material; //puntero a un material abstracto. Nuevo campo que puede ser, en tiempo de ejecución, un puntero a cualquier objeto de una clase derivada de Material, típicamente MaterialEstandar.
	};
	
	//constructores (uno por tipo)
	EntradaNGE(Objeto3D * pObjeto);	//copia solo un puntero
	EntradaNGE(const Matriz4f & pMatriz);	//crea copia de la matriz
	EntradaNGE(Material * pMaterial); //copia unicamente el puntero
};


class NodoGrafoEscena : public Objeto3D{
	protected:
		std::vector<EntradaNGE> entradas;		//vector de entradas
		Material * materialActivo;
		
	public:
		// visualizar usando OpenGL
		virtual void visualizar(unsigned modo_vis);
		
		// añadir una entrada (al final)
		void agregar(EntradaNGE * entrada); //genérica
		
		//construir una entrada y añadirla (al final)
		void agregar(Objeto3D * pObjeto);		//objeto
		
		void agregar(const Matriz4f & pMatriz);	//matriz //crear EntradaNGE y luego hacer un push_back
		
		//Nueva versión del método agregar, para poder agregar a un nodo una nueva entrada de tipo material.
		void agregar(Material * pMaterial); //añadir material al final
};

#endif
