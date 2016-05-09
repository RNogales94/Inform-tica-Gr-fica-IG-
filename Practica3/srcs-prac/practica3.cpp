// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 3  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica3.hpp"
#include "MallaPLY.hpp"
#include "MallaRevol.hpp"
#include "Objeto3D.hpp"
#include "rotacion.hpp"
#include "NodoGrafoEscena.hpp"


const int P3_numero_objetos = 4;
unsigned P3_objeto_activo = 0 ; // objeto activo: cubo (0), tetraedro (1), otros....


// Controladores de los grados de libertad
const int numero_grados_libertad = 3;
const float MAX_velocidad=10;
const float MIN_velocidad=1;

unsigned p3_grado_libertad_activo = 0;
float valor_grado_libertad_0 = 0;
float valor_grado_libertad_1 = 0;
float valor_grado_libertad_2 = 0;

float velocidad_grado_libertad_0 = 2;
float velocidad_grado_libertad_1 = 0.5;
float velocidad_grado_libertad_2 = 3;

void aumentar_grado_libertad_activo(){
    const float MAX_valor_grado_libertad_0 = 30;
    const float MAX_valor_grado_libertad_1 = 10;
    const float MAX_valor_grado_libertad_2 = 30;
    
    switch (p3_grado_libertad_activo) {
        case 0:
            if (valor_grado_libertad_0 < MAX_valor_grado_libertad_0) {
                valor_grado_libertad_0 = valor_grado_libertad_0+velocidad_grado_libertad_0;
                //Controlamos que no se pase del Maximo
                if (valor_grado_libertad_0 > MAX_valor_grado_libertad_0) {
                    valor_grado_libertad_0 = MAX_valor_grado_libertad_0;
                }
            }
            break;
        case 1:
            if (valor_grado_libertad_1 < MAX_valor_grado_libertad_1) {
                valor_grado_libertad_1 = valor_grado_libertad_1+velocidad_grado_libertad_1;
                //Controlamos que no se pase del Maximo
                if (valor_grado_libertad_1 > MAX_valor_grado_libertad_1) {
                    valor_grado_libertad_1 = MAX_valor_grado_libertad_1;
                }
            }
            break;
        case 2:
            if (valor_grado_libertad_2 < MAX_valor_grado_libertad_2) {
                valor_grado_libertad_2 = valor_grado_libertad_2+velocidad_grado_libertad_2;
                //Controlamos que no se pase del Maximo
                if (valor_grado_libertad_2 > MAX_valor_grado_libertad_2) {
                    valor_grado_libertad_2 = MAX_valor_grado_libertad_2;
                }
            }
            break;

        default:
            cerr << "Error en el numero de grados de libertad"<<endl;
            break;
    }
}
void reducir_grado_libertad_activo(){
    const float MIN_valor_grado_libertad_0 = -30;
    const float MIN_valor_grado_libertad_1 = -5;
    const float MIN_valor_grado_libertad_2 = -30;
    
    switch (p3_grado_libertad_activo) {
        case 0:
            if (valor_grado_libertad_0 > MIN_valor_grado_libertad_0) {
                valor_grado_libertad_0 = valor_grado_libertad_0-velocidad_grado_libertad_0;
                //Controlamos que no se pase del Maximo
                if (valor_grado_libertad_0 < MIN_valor_grado_libertad_0) {
                    valor_grado_libertad_0 = MIN_valor_grado_libertad_0;
                }
            }
            break;
        case 1:
            if (valor_grado_libertad_1 > MIN_valor_grado_libertad_1) {
                valor_grado_libertad_1 = valor_grado_libertad_1-velocidad_grado_libertad_1;
                //Controlamos que no se pase del Maximo
                if (valor_grado_libertad_1 < MIN_valor_grado_libertad_1) {
                    valor_grado_libertad_1 = MIN_valor_grado_libertad_1;
                }

            }
            break;
        case 2:
            if (valor_grado_libertad_2 > MIN_valor_grado_libertad_2) {
                valor_grado_libertad_2 = valor_grado_libertad_2-velocidad_grado_libertad_2;
                //Controlamos que no se pase del Maximo
                if (valor_grado_libertad_2 < MIN_valor_grado_libertad_2) {
                    valor_grado_libertad_2 = MIN_valor_grado_libertad_2;
                }
            }
            break;
            
        default:
            cerr << "Error en el numero de grados de libertad"<<endl;
            break;
    }
}

void aumentar_velocidad_cambio(){
    switch (p3_grado_libertad_activo) {
        case 0:
            if (velocidad_grado_libertad_0 < MAX_velocidad){
                velocidad_grado_libertad_0 = velocidad_grado_libertad_0++;
                if (velocidad_grado_libertad_0 > MAX_velocidad) {
                    velocidad_grado_libertad_0 = MAX_velocidad;
                }
            }
            break;
        case 1:
            if (velocidad_grado_libertad_1 < MAX_velocidad){
                velocidad_grado_libertad_1 = velocidad_grado_libertad_1++;
                if (velocidad_grado_libertad_1 > MAX_velocidad) {
                    velocidad_grado_libertad_1 = MAX_velocidad;
                }
            }
            break;
        case 2:
            if (velocidad_grado_libertad_2 < MAX_velocidad){
                velocidad_grado_libertad_2 = velocidad_grado_libertad_2++;
                if (velocidad_grado_libertad_2 > MAX_velocidad) {
                    velocidad_grado_libertad_2 = MAX_velocidad;
                }
            }
            break;
        default:
            cout << "Error en aumentar_velocidad";
            break;
    }
}
void reducir_velocidad_cambio(){
    switch (p3_grado_libertad_activo) {
        case 0:
            if (velocidad_grado_libertad_0 > MAX_velocidad){
                velocidad_grado_libertad_0 = velocidad_grado_libertad_0--;
                if (velocidad_grado_libertad_0 < MAX_velocidad) {
                    velocidad_grado_libertad_0 = MAX_velocidad;
                }
            }
            break;
        case 1:
            if (velocidad_grado_libertad_1 > MAX_velocidad){
                velocidad_grado_libertad_1 = velocidad_grado_libertad_1--;
                if (velocidad_grado_libertad_1 < MAX_velocidad) {
                    velocidad_grado_libertad_1 = MAX_velocidad;
                }
            }
            break;
        case 2:
            if (velocidad_grado_libertad_2 > MAX_velocidad){
                velocidad_grado_libertad_2 = velocidad_grado_libertad_2--;
                if (velocidad_grado_libertad_2 < MAX_velocidad) {
                    velocidad_grado_libertad_2 = MAX_velocidad;
                }
            }
            break;
        default:
            cout << "Error en aumentar_velocidad";
            break;
    }
}
// ---------------------------------------------------------------------
// declaraciones de clases para organizacion de datos....

class Bloque : public MallaInd{
public:
    Bloque(){
        nombre_obj = "Bloque";
        //Vertices de la base
        Tupla3f p0(-1, 0, -0.2), p1(-1, 0, 0.2), p2(1, 0, 0.2) , p3(1, 0, -0.2);
        
        //Vertices de la tapa
        Tupla3f p4(-1, 2, -1), p5(-1, 2, 1), p6(1, 2, 1), p7(1, 2, -1);
        
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
class BloquePlano : public MallaInd{
public:
    BloquePlano(){
        nombre_obj = "Bloque";
        //Vertices de la base
        Tupla3f p0(-0.35, 0, 0), p1(0.35, 0, 0);
        
        //Vertices de la tapa
        Tupla3f p2(-0.35, 0.7, -0.35), p3(-0.35, 0.7, 0.35), p4(0.35, 0.7, 0.35), p5(0.35, 0.7, -0.35);
        
        tabla_vertices.push_back(p0);
        tabla_vertices.push_back(p1);
        tabla_vertices.push_back(p2);
        tabla_vertices.push_back(p3);
        tabla_vertices.push_back(p4);
        tabla_vertices.push_back(p5);
        
        //Ahora creamos las caras uniendo los vertices:
        
        //Base
        /*
        Tupla3i c0( 0,1,2 ), c1(0,3,2);
        tabla_indices.push_back(c0);
        tabla_indices.push_back(c1);
         */
        
        //Cara Izda
        Tupla3i c1( 0,2,3 );
        tabla_indices.push_back(c1);
        
        //Cara Dcha
        Tupla3i c2( 1,5,4 );
        tabla_indices.push_back(c2);
        
        //Cara Frontal
        Tupla3i c3( 0,3,4 ), c4( 0,4,1 );
        tabla_indices.push_back(c3);
        tabla_indices.push_back(c4);
        
        //Cara Trasera
        Tupla3i c5( 0,5,2 ), c6(0,1,5);
        tabla_indices.push_back(c5);
        tabla_indices.push_back(c6);
        
        //Tapa
        Tupla3i c7(2,4,3), c8(2,5,4);
        tabla_indices.push_back(c7);
        tabla_indices.push_back(c8);
        
    }
    
};

class Cabeza : public NodoGrafoEscena{
protected:
    float gamma;
public:
    Cabeza(){
        agregar(MAT_Traslacion(0, 2, 0));
        agregar(MAT_Rotacion(90, 0,1,0));
        agregar(new Bloque);
    }
    
    void moverCabeza(float nuevo_gamma){
        gamma = nuevo_gamma;
        *(entradas[1].matriz) = MAT_Rotacion(90+nuevo_gamma, 0,1,0);
    }
};

class Brazo : public NodoGrafoEscena{
protected:
    float beta;
public:
    Brazo(){
        agregar(MAT_Rotacion(60, 0, 0, 1));
        agregar(MAT_Traslacion(1, 1, 0));
        agregar(MAT_Escalado(0.5, 1, 0.5));
        agregar(new Bloque);
    }
    void moverBrazo(float beta_nuevo){
        beta = beta_nuevo;
        *(entradas[0].matriz) = MAT_Rotacion(60+beta, 0, 0, 1);
    }
};

class Pierna : public NodoGrafoEscena{
protected:
    float alpha;
public:
    Pierna(float t_inicial){
        agregar(MAT_Traslacion(0.5, 0, 0));
        agregar(MAT_Escalado(1, -1, 1));
        agregar(MAT_Rotacion(0, 1,0,0)); // entradas[2]
        agregar(MAT_Rotacion(-5, 0,0,1));
        agregar(MAT_Escalado(0.5,1,0.5));
        agregar(new Bloque);
    }
    void moverPierna(float alpha){
        *(entradas[2].matriz) = MAT_Rotacion(alpha, 1, 0, 0);
    }
};
class Cuerpo : public NodoGrafoEscena{
public:
    Cuerpo(){
        agregar(new Bloque);
    }
};

class muneco : public NodoGrafoEscena{
protected:
    float alpha, beta, gamma;
public:
    muneco(float alpha){
        alpha = this->alpha;
        agregar(MAT_Escalado(0.2,0.2,0.2));
        agregar(new Cabeza());
        agregar(new Cuerpo());
        agregar(new Brazo());
        agregar(new Pierna(alpha)); //entradas[4]
        agregar(MAT_Escalado(-1, 1, 1));
        agregar(new Brazo());
        agregar(new Pierna(alpha)); ////entradas[7]

    }
    void moverPiernas(float alpha_nuevo){
        alpha = alpha_nuevo;
        Pierna * hijo = (Pierna *) entradas[4].objeto;
        hijo->moverPierna(alpha);
        
        Pierna * hijo2 = (Pierna *) entradas[7].objeto;
        hijo2->moverPierna(-alpha);
        
    }
    
    void moverBrazos(float beta_nuevo){
        beta = beta_nuevo;
        Brazo * hijo = (Brazo *) entradas[3].objeto;
        hijo->moverBrazo(beta);
        
        Brazo * hijo2 = (Brazo *) entradas[6].objeto;
        hijo2->moverBrazo(beta);
    }
    
    void moverCabeza(float nuevo_gamma){
        gamma = nuevo_gamma;
        Cabeza * hijo = (Cabeza *) entradas[1].objeto;
        hijo->moverCabeza(nuevo_gamma);
    }
};

// declaraciones de estructuras de datos....
static muneco* hombre = NULL;

void moverGrado_Activo(){
    switch (p3_grado_libertad_activo) {
        case 0:
            hombre->moverPiernas(valor_grado_libertad_0);
            break;
        case 1:
            hombre->moverBrazos(valor_grado_libertad_1);
            break;
        case 2:
            hombre->moverCabeza(valor_grado_libertad_2);
            break;
        default:
            break;
    }
}


// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// incializado OpenGL.

void P3_Inicializar( int argc, char *argv[] )
{
    float t_pierna_inical = 0;
    hombre = new muneco(t_pierna_inical);
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

bool P3_FGE_PulsarTeclaNormal( unsigned char tecla )
{
    if (tecla=='o' || tecla=='O') {
        P3_objeto_activo = (P3_objeto_activo+1) %P3_numero_objetos;
        return true;
    }
    if (tecla=='g' || tecla=='G') {
        p3_grado_libertad_activo = (p3_grado_libertad_activo+1)%numero_grados_libertad;
        cout << "Grado de libertad "<<p3_grado_libertad_activo<<" activo"<<endl;
        if (p3_grado_libertad_activo==0) {
            cout << "MOVER PIERNAS [ACTIVADO]" <<endl;
        }
        if (p3_grado_libertad_activo==1) {
            cout << "MOVER BRAZOS [ACTIVADO]" <<endl;
        }
        if (p3_grado_libertad_activo==2) {
            cout << "MOVER CABEZA [ACTIVADO]" <<endl;
        }
        return true;
    }
    if (tecla=='<') {
        aumentar_grado_libertad_activo();
        moverGrado_Activo();
        return true;
    }
    if (tecla=='>') {
        reducir_grado_libertad_activo();
        moverGrado_Activo();
        return true;
    }
    
    if (tecla=='V') {
        aumentar_velocidad_cambio();
        return false;
    }
    if (tecla=='v') {
        reducir_velocidad_cambio();
        return false;
    }
    else
        return false;
}


// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez , >=4 otros....

void P3_DibujarObjetos( unsigned modo )
{
    if (P3_objeto_activo==0) {
        hombre->visualizar(modo);
    }
}


 //////////////////////
 //  VERSION ANTIGUA //
 //////////////////////
    
    /*
void P3_DibujarObjetos( unsigned modo )
{
    // objeto activo: hormiga (0), peon (1)
    if (P3_objeto_activo==0) {
        //Body
        glPushMatrix();
        glScalef(0.2,0.2,0.2);
        
        glPushMatrix();
        glTranslatef(0,-1.5,0);
        glScalef (1.25, 1.75, 1);
        body->visualizar(modo);
        glPopMatrix();
        
        //Head
        glPushMatrix();
        glTranslatef (0, 2, 0);
        glRotatef(90, 0,1,0);
        glScalef(1,0.75,1);
        head->visualizar(modo);
        glPopMatrix();
        
        //Right Arm
        glPushMatrix();
        glTranslatef (2.5, 0.5, 0);
        glRotatef(60, 0,0,1);
        glScalef(0.5,1,0.5);
        //glRotatef(90, 0,1,0);
        leftArm->visualizar(modo);
        glPopMatrix();
        
        //Left Arm
        glPushMatrix();
        glTranslatef (-2.5, 0.5, 0);
        glRotatef(-60, 0,0,1);
        glScalef(0.5,1,0.5);
        //glRotatef(90, 0,1,0);
        leftArm->visualizar(modo);
        glPopMatrix();
        
        glPopMatrix();
        
    }
}
*/
