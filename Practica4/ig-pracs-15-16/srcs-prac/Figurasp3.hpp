#include "NodoGrafoEscena.hpp"
#include "Objeto3D.hpp"
#include "MallaInd.hpp"
#include "Cilindro.hpp"
#include <vector>
#include "tuplasg.hpp" // Tupla3f
#include "matrices-tr.hpp"
#include "matrizg.hpp"



class ColumnaIzquierda : public NodoGrafoEscena{
	public:
		ColumnaIzquierda(); //constructor
};

class ColumnaDerecha : public NodoGrafoEscena{
	public:
		ColumnaDerecha(); //constructor
};

class Cabina : public NodoGrafoEscena{
	protected:
		float coord_giro = 0;
		float altura_cabina = 0;
	public:
		Cabina(float giro_inicial, float altura_inicial); //constructor
		void girarCabina(float giro_nuevo);
		void desplazarCabina(float altura_nueva);
};

class Base : public NodoGrafoEscena{
	public:
		Base(); //constructor
};


class Atraccion : public NodoGrafoEscena{
	protected:
		float giro_atraccion = 0;
		float giro_cabina = 0;
		float altura_cabina = 0;
	public:
		Atraccion(float giro_cabina_inicial, float altura_cabina_inicial, float giro_atraccion_inicial); //constructor
		void girarAtraccion(float giro_atraccion_nuevo);
		void girarCabina(float giro_cabina_nuevo);
		void desplazarCabina(float altura_cabina_nueva);
};
