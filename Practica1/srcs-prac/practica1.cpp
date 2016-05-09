// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica1.hpp"
#include "MallaInd.hpp"
#include "Objeto3D.hpp"

const int numero_objetos = 5;
unsigned objeto_activo = 0 ; // objeto activo: cubo (0), tetraedro (1), otros....

// ---------------------------------------------------------------------
// declaraciones de clases para organizacion de datos....



Tupla3f rotacion(Tupla3f &v, double angulo){
    Tupla3f *t = new Tupla3f( v(X)*cos(angulo) - v(Z)*sin(angulo), v(Y), v(X)*sin(angulo) + v(Z)*cos(angulo) );
    return *t;
}



class Triangulo : public MallaInd{
public:
    Triangulo(){
        nombre_obj = "Triangulo";
        float punto1[3] = {0, 1, 0};
        float punto2[3] = {-0.6, 0, 0};
        float punto3[3] = {0.6, 0, 0};
        Tupla3f p1(punto1);
        Tupla3f p2(punto2);
        Tupla3f p3(punto3);
        tabla_vertices.push_back(p1);
        tabla_vertices.push_back(p2);
        tabla_vertices.push_back(p3);
        Tupla3i i1( 0,1,2 ), i2(1,2,0), i3(0,0,0);
        tabla_indices.push_back(i1);
        tabla_indices.push_back(i2);
        tabla_indices.push_back(i3);
    }
};
class Cubo : public MallaInd{
public:
    Cubo(){
        nombre_obj = "Cubo";
        //Vertices de la base
        Tupla3f p0(-0.35, 0, -0.35), p1(-0.35, 0, 0.35), p2(0.35, 0, 0.35) , p3(0.35, 0, -0.35);
        
        //Vertices de la tapa
        Tupla3f p4(-0.35, 0.7, -0.35), p5(-0.35, 0.7, 0.35), p6(0.35, 0.7, 0.35), p7(0.35, 0.7, -0.35);
        
        tabla_vertices.push_back(p0);
        tabla_vertices.push_back(p1);
        tabla_vertices.push_back(p2);
        tabla_vertices.push_back(p3);
        tabla_vertices.push_back(p4);
        tabla_vertices.push_back(p5);
        tabla_vertices.push_back(p6);
        tabla_vertices.push_back(p7);
        
        //Ahora creamos las caras uniendo los vertices:
        
        //Base
        Tupla3i c0( 0,1,2 ), c1(0,3,2);
        tabla_indices.push_back(c0);
        tabla_indices.push_back(c1);
        
        //Cara frontal
        Tupla3i c4( 1,6,5 ), c5( 1,2,6 );
        tabla_indices.push_back(c4);
        tabla_indices.push_back(c5);
        
        //Cara Izda
        Tupla3i c10( 4,5,1 ), c11( 4,0,1 );
        tabla_indices.push_back(c10);
        tabla_indices.push_back(c11);
        
        //Cara trasera
        Tupla3i c8( 4,7,0 ), c9( 0,3,7 );
        tabla_indices.push_back(c8);
        tabla_indices.push_back(c9);
        
        //Cara Derecha
        Tupla3i c6( 7,6,2 ), c7( 3,2,7 );
        tabla_indices.push_back(c6);
        tabla_indices.push_back(c7);
        
        
        //Tapa
        Tupla3i c2(4,5,6), c3(7,4,6);
        tabla_indices.push_back(c2);
        tabla_indices.push_back(c3);
        
    }
    
};
class Tetraedro : public MallaInd{
public:
    Tetraedro(){
        nombre_obj = "Tetraedro";
        float punto1[3] = {0.7, 0.0, 0.0};
        Tupla3f p1(punto1);
        Tupla3f p2, p3, p4(0.0, 0.7, 0.0);
        double angulo120 = 2*M_PI/3;
        p2 = rotacion(p1, angulo120);
        p3 = rotacion(p1, -angulo120);
        tabla_vertices.push_back(p1);
        tabla_vertices.push_back(p2);
        tabla_vertices.push_back(p3);
        tabla_vertices.push_back(p4);
        
        Tupla3i i1( 1,2,0 ), i2(1,2,3), i3(2,3,0), i4(1,3,0);
        tabla_indices.push_back(i1);
        tabla_indices.push_back(i2);
        tabla_indices.push_back(i3);
        tabla_indices.push_back(i4);
    }
};
class Cono : public MallaInd{
    
    /*
     Estructura de vertices e indices:
     
     i --- i+2
     ...   |    / |    ...
     |   /  |
     i+1 - i+3
     
     */
    
    
public:
    Cono(int n){
        nombre_obj = "Cono";
        float incremento_angulo = 2*M_PI/n;
        
        Tupla3f *t1;

        
        //Vertices Zona Lateral
        t1 = new Tupla3f(0.7, 0, 0);
        tabla_vertices.push_back(*t1); //Se pone uno en la tapa
        
        for (int i=0; i<n; i++) {
            t1 = new Tupla3f(rotacion(tabla_vertices[i],incremento_angulo));
            tabla_vertices.push_back(*t1); //Se pone uno en la tapa
    
        }
        //Vertice
        t1 = new Tupla3f(0, 1, 0);
        tabla_vertices.push_back(*t1);
        
        //Centro de la base
        t1 = new Tupla3f(0, 0, 0);
        tabla_vertices.push_back(*t1);
        
        Tupla3i* cara_actual;
        
        //Base
        for (int i=0; i<n; i++) {
            cara_actual = new Tupla3i(i, i+1, n+2);
            tabla_indices.push_back(*cara_actual);
        }

        //Zona lateral
        for (int i=0; i<n; i++) {
            cara_actual = new Tupla3i(i, i+1, n+1);
            tabla_indices.push_back(*cara_actual);
        }
        
    }
    
};
class Cilindro : public MallaInd{
    
    /*
     Estructura de vertices e indices:
     
                i --- i+2
          ...   |    / |    ...
                |   /  |
                i+1 - i+3
     
     */
    
    
public:
    Cilindro(int n){
        nombre_obj = "Cilindro";
        float incremento_angulo = 2*M_PI/n;
        
        Tupla3f *t1;
        Tupla3f *t2;
        
        t1 = new Tupla3f(0.7, 0, 0);
        t2 = new Tupla3f(0.7, 0.7, 0);

        
        //Vertices Zona Lateral
        tabla_vertices.push_back(*t1); //Se pone uno en la tapa
        tabla_vertices.push_back(*t2); //Se pone el siguiente en la base
        for (int i=0; i<2*n; i=i+2) {
            t1 = new Tupla3f(rotacion(tabla_vertices[i%(2*n)],incremento_angulo));
            t2 = new Tupla3f(rotacion(tabla_vertices[(i+1)%(2*n)],incremento_angulo));
            
            tabla_vertices.push_back(*t1); //Se pone uno en la tapa
            tabla_vertices.push_back(*t2); //Se pone el siguiente en la base
            
        }
        //Vertice centro de la tapa
        t1 = new Tupla3f(0, 0.7, 0);
        tabla_vertices.push_back(*t1);

        //Vertice centro de la base
        t1 = new Tupla3f(0, 0, 0);
        tabla_vertices.push_back(*t1);
        
        Tupla3i* cara_actual;
        
        //Tapa
        for (int i=0; i<2*n; i=i+2) {
            cara_actual = new Tupla3i((i)%(2*n),(i+2)%(2*n), (2*n)+3);
            tabla_indices.push_back(*cara_actual);
        }
        //Zona Lateral
        for (int i=0; i<2*n; i++) {
            cara_actual = new Tupla3i(i%(2*n), (i+2)%(2*n), (i+1)%(2*n));
            tabla_indices.push_back(*cara_actual);
        }
        
        
        //Base
        t1 = new Tupla3f(0, 0, 0);
        tabla_vertices.push_back(*t1);
        for (int i=1; i<2*n; i=i+2) {
            cara_actual = new Tupla3i((i)%(2*n), (i+2)%(2*n), (2*n)+2);
            tabla_indices.push_back(*cara_actual);
        }

    }
};



// declaraciones de estructuras de datos....
Triangulo* tri;
Tetraedro* tetraedro;
Cubo* cubo;
Cono* cono;
Cilindro* cilindro;



// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// incializado OpenGL.

void P1_Inicializar( int argc, char *argv[] )
{
    tri = new Triangulo;
    tetraedro = new Tetraedro;
    cubo = new Cubo;
    cilindro = new Cilindro(100);
    cono = new Cono(100);
    
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

bool P1_FGE_PulsarTeclaNormal( unsigned char tecla )
{
    if (tecla=='f' || tecla=='F') {
        objeto_activo = (objeto_activo+1) %numero_objetos;
        return true;
    }
    else
        return false;
}


// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez , >=4 otros....

void P1_DibujarObjetos( unsigned modo )
{
    // objeto activo: cubo (0), tetraedro (1), otros....
    if (objeto_activo==0) {
        tetraedro->visualizar(modo);
    }
    if (objeto_activo==1) {
        cubo->visualizar(modo);
    }
    if (objeto_activo==2) {
        cilindro->visualizar(modo);
    }
    if (objeto_activo==3) {
        cono->visualizar(modo);
    }
    if (objeto_activo==4) {
        tri->visualizar(4);
    }
    
}
