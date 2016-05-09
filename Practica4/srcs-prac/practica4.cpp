// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 4  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica4.hpp"
#include "MallaPLY.hpp"
#include "MallaRevol.hpp"
#include "Objeto3D.hpp"
#include "rotacion.hpp"
#include "NodoGrafoEscena.hpp"
#include "misMateriales.hpp"
#include "luz.hpp"

class FilaPeones : public NodoGrafoEscena{
    Objeto3D* peon;
public:
    FilaPeones(){
        peon = new MallaRevol("../plys/peon.ply",800, true, true);
        agregar(MAT_Traslacion(0,1.4,3));
        agregar(new MaterialPeonMadera());
        agregar(peon);
        agregar(MAT_Traslacion(3,0,0));
        agregar(new MaterialPeonBlanco());
        agregar(peon);
        agregar(MAT_Traslacion(3,0,0));
        agregar(new MaterialPeonNegro());
        agregar(peon);
    }
};

class Lata : public NodoGrafoEscena{
    Objeto3D* tapa;
    Objeto3D* cuerpo;
    Objeto3D* base;
    
public:
    Lata(){
        cuerpo = new MallaRevol("../plys/lata-pcue.ply",100, true, true);
        tapa = new MallaRevol("../plys/lata-psup.ply",100, true, false);
        base = new MallaRevol("../plys/lata-pinf.ply",100, true, false);
        agregar(MAT_Escalado(5,5,5));
        agregar(new MaterialTapasLata());
        agregar(tapa);
        agregar(new MaterialLata());
        agregar(cuerpo);
        agregar(new MaterialTapasLata());
        agregar(base);
    }
};


const int P4_numero_objetos = 1;
unsigned P4_objeto_activo = 0 ; // objeto activo: cubo (0), tetraedro (1), otros....
ColeccionFL * fuentes = NULL;
FilaPeones * misPeones = NULL;
Lata *  miLata = NULL;
FuenteDireccional* fuente3=NULL;

int modo_vis_p4=0;
int angulo=0;



// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// incializado OpenGL.

void P4_Inicializar( int argc, char *argv[] )
{
    fuentes = new ColeccionFL;
    
    glEnable(GL_RESCALE_NORMAL);
    FuenteLuz* fuente1= new FuentePosicional(Tupla3f( 0, 0, 0));
    FuenteLuz* fuente2= new FuentePosicional(Tupla3f( 0.0, 10, 10));
    fuente3 = new FuenteDireccional(0,0);
    
    misPeones = new FilaPeones();
    misPeones->calcularNormales();
    miLata = new Lata();
    miLata->calcularNormales();
    //escena = new Escena();
    //escena->calcularNormales();
    
   // fuentes->fuentes.push_back(fuente1);
    fuentes->fuentes.push_back(fuente2);
    fuentes->fuentes.push_back(fuente3);
    
    fuentes->activar();

    
    
}

// ---------------------------------------------------------------------
// Función invocada al pulsar una tecla con la práctica 1 activa:
// (si la tecla no se procesa en el 'main').
//
//  - devuelve 'true' si la tecla se usa en esta práctica para cambiar
//    entre el cubo, el tetraedro u otros objetos (cambia el valor de
//    'objeto_activo').
//  - devuelve 'false' si la tecla no se usa en esta práctica (no ha
//    cambiado nada)

bool P4_FGE_PulsarTeclaNormal( unsigned char tecla ){
    if(toupper(tecla) == 'O')		//cambiamos de figura con el boton O
    {
        P4_objeto_activo++;
        if(P4_objeto_activo == P4_numero_objetos)
            P4_objeto_activo = 0;
        
        return true;
    }
    if(toupper(tecla) == 'G')		//cambiamos la forma de mover el angulo con G
    {
        angulo=(angulo+1)%2;
        std::cout << angulo << std::endl;
        return true;
    }
    if(tecla == '<')
    {
        fuente3->variarAngulo(angulo,-2);
        fuentes->activar();
        return true;
    }
    if(tecla == '>')
    {
        fuente3->variarAngulo(angulo,2);
        fuentes->activar();
        return true;
    }
    
    if(toupper(tecla) == 'L'){
        modo_vis_p4++;
        modo_vis_p4=modo_vis_p4%6;
        return true;
    }
    else
        return false;
}


// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez , >=4 otros....

void P4_DibujarObjetos( unsigned modo )
{
    if(P4_objeto_activo==0){
        miLata->visualizar(modo_vis_p4);
        misPeones->visualizar(modo_vis_p4);
    }
    
}

    

