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
public:
    virtual void visualizar( unsigned modo_vis );
} ;

#endif