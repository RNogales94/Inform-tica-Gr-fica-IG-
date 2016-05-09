#include "mallaPLY.hpp"
#include "file_ply_stl.hpp"

using namespace std;
// clase mallas indexadas obtenidas de un archivo PLY


MallaPLY::MallaPLY( const char * nombre_arch ){
    vector<float> vertices;
    vector<int> caras;
    ply::read(nombre_arch,vertices, caras);
    for (int i=0; i<vertices.size() ; i=i+3) {
        Tupla3f *actual;
        actual = new Tupla3f(vertices[i], vertices[i+1], vertices[i+2]);
        tabla_vertices.push_back(*actual);
    }
    for (int i=0; i<caras.size() ; i=i+3) {
        Tupla3i *actual;
        actual = new Tupla3i(caras[i], caras[i+1], caras[i+2]);
        tabla_indices.push_back(*actual);
    }
}