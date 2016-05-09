#include "MallaInd.hpp"
// .....
#include "tuplasg.hpp" // Tupla3f

/* Los objetos cubo y tetraedro se implementarán usando dos clases derivadas de MallaInd, cada una de ellas
 * definirá un nuevo constructor que construirá las dos tablas correspondientes a cada tipo de objeto.
 * Estas clases se pueden declarar e implementar en un par de archivos nuevos, o se puede hacer en practica1.hpp/.cpp.
 * En cualquier caso, en el archivo practica1.cpp habrá dos variables globales nuevas, una será una instancia del cubo
 * y otra una instancia del tetraedro.
 * 
 * En la función P1_Inicializar se crearán las instancias del cubo y el tetraedro.
 * En la función P1_Visualizar se visualizará el cubo o el tetraedro.
 */

class Cubo : public MallaInd
{
	
public:
	Cubo() ; // crea las tablas del cubo, y le da nombre.
	
} ;
