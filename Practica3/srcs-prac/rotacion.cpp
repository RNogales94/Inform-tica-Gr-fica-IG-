// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 2  (Funcion de rotacion)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f


Tupla3f rotacion(Tupla3f &v, double angulo){
    Tupla3f *t = new Tupla3f( v(X)*cos(angulo) - v(Z)*sin(angulo), v(Y), v(X)*sin(angulo) + v(Z)*cos(angulo) );
    return *t;
}

