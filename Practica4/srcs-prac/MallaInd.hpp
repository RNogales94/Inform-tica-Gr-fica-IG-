#ifndef IG_MALLAIND_HPP
#define IG_MALLAIND_HPP

#include "Objeto3D.hpp"
#include <vector>
#include "tuplasg.hpp"

using namespace std;
// clase para mallas indexadas o mallas TVT
class MallaInd : public Objeto3D
{
protected:
    vector<Tupla3f> tabla_vertices;
    vector<Tupla3i> tabla_indices;
    vector<Tupla3f> normales_vertices;
    vector<Tupla3f> normales_caras;
    vector<Tupla2f> coords_textura;
public:
    virtual void visualizar( unsigned modo_vis );
    //virtual void visualizar( ContextoVis cv );
    virtual void calcularNormales();
} ;

// Aclaración: ¿ Que es tabla_indices ?
//Cada indice representa una cara

//                [         (i)   ,   (i+1)      ]
// tabla_indices: [ ... , (A,B,C) ,  (P,Q,R) ... ]

// A,B,C son las posiciones que ocupan los vertices del i-esimo
// triangulo en tabla_vertices

#endif