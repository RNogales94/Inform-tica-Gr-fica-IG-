#include "mallaRevol.hpp"
#include "file_ply_stl.hpp"
#include "rotacion.hpp"

using namespace std;

// constructor se debe especificar el nombre completo del archivo a leer

MallaRevol::MallaRevol( const char * nombre_arch , unsigned nperfiles){
    vector<float> vertices;
    vector<int> caras;
    
    vector<Tupla3f> perfil;
    
    Tupla3i *cara_actual_A;
    Tupla3i *cara_actual_B;
    
    float incremento_angulo = 2*M_PI/nperfiles;
    
    
    ply::read_vertices(nombre_arch,vertices);
    
    //Generacion del perfil vertice base y tapa
    for (int i=0; i<vertices.size() ; i=i+3) {
        Tupla3f *actual;
        actual = new Tupla3f(vertices[i], vertices[i+1], vertices[i+2]);
        perfil.push_back(*actual);
    }
    const int long_perfil = perfil.size();
    //Inicializamos la tabla de vertices con la primera seccion del perfil:
    for (int i=0; i<long_perfil; i++) {
        tabla_vertices.push_back(perfil[i]);
        
    }
    
    //Escritura de la tabla de vertices
    //Para cada incremento del angulo añadimos una nueva seccion del perfil
    /*
     5   0
     6   1
     7   2
     8   3
     9   4
     .   .
     .   .
     .   .
     
     */
    Tupla3f *nueva_tupla;
    for (int i=0; i<nperfiles; i++) {
        for (int j=0; j<long_perfil; j++) {
            nueva_tupla = new Tupla3f(rotacion(tabla_vertices[i*long_perfil + j], incremento_angulo));
            tabla_vertices.push_back(*nueva_tupla);
        }
    }
    
    //Tapa
    int A, B, C, D;
    Tupla3f *tapa;
    tapa = new Tupla3f(tabla_vertices[0]);
    tapa = new Tupla3f(0, (*tapa)[Y], 0);
    int pos_tapa = tabla_vertices.size();
    tabla_vertices.push_back(*tapa);
    
    for (int i=0; i<nperfiles; i++) {
        A = pos_tapa;
        B = i*long_perfil;
        C = (i+1)*long_perfil;
        
        cara_actual_A = new Tupla3i(A,B,C);
        tabla_indices.push_back(*cara_actual_A);
    }
    
    
    //Zona Lateral
    
    /*
     ...  C---A
     ...  | \ |
     ...  D---B
     
     */
    
    for (int i=0; i<nperfiles; i++) {
        for (int j=0; j<long_perfil-1; j++) {
            A = (i*long_perfil + j);
            B = (i*long_perfil + (j+1));
            
            C = ((i+1)*long_perfil + j);
            D = ((i+1)*long_perfil + (j+1));
            
            cara_actual_A = new Tupla3i(A,B,C);
            tabla_indices.push_back(*cara_actual_A);
            cara_actual_B = new Tupla3i(B,D,C);
            tabla_indices.push_back(*cara_actual_B);
            
        }
    }
    
    Tupla3f *base;
    base = new Tupla3f(tabla_vertices[long_perfil-1]);
    base = new Tupla3f(0, (*base)[Y], 0);
    int pos_base = tabla_vertices.size();
    tabla_vertices.push_back(*base);
    
    //Base
    for (int i=0; i<nperfiles; i++) {
        A = pos_base;
        B = i*long_perfil + long_perfil-1;
        C = (i+1)*long_perfil + long_perfil-1;
        
        cara_actual_A = new Tupla3i(A,B,C);
        tabla_indices.push_back(*cara_actual_A);
    }
}














