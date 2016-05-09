#include "MallaInd.hpp"
#include "aux.hpp"


//GL_POINTS
//GL_TRIANGLES
//GL_LINE_LOOP
//GL_LINES
//GL_LINE_STRIP

void MallaInd::visualizar(unsigned modo_vis){
    if (modo_vis==0) {
        int num_indices = tabla_indices.size();
        glEnableClientState( GL_VERTEX_ARRAY); // habilitar array de vertices
        glVertexPointer( 3, GL_FLOAT, 0, &tabla_vertices[0] );  // establecer dirección y estructura
        glDrawElements( GL_POINTS, num_indices*3, GL_UNSIGNED_INT, &tabla_indices[0] );     // visualizar recorr iendo los vertices en el orden de los indices:
        glDisableClientState( GL_VERTEX_ARRAY ); // deshabilitar array
    }

    if (modo_vis==1) {
        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
        int num_indices = tabla_indices.size();
        glEnableClientState( GL_VERTEX_ARRAY); // habilitar array de vertices
        glVertexPointer( 3, GL_FLOAT, 0, &tabla_vertices[0] );  // establecer dirección y estructura
        glDrawElements( GL_TRIANGLES, num_indices*3, GL_UNSIGNED_INT, &tabla_indices[0] );     // visualizar recorr iendo los vertices en el orden de los indices:
        glDisableClientState( GL_VERTEX_ARRAY ); // deshabilitar array
        glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

        
    }
    if (modo_vis==2) {
        int num_indices = tabla_indices.size();
        glEnableClientState( GL_VERTEX_ARRAY); // habilitar array de vertices
        glVertexPointer( 3, GL_FLOAT, 0, &tabla_vertices[0] );  // establecer dirección y estructura
        glDrawElements( GL_TRIANGLES, num_indices*3, GL_UNSIGNED_INT, &tabla_indices[0] );     // visualizar recorr iendo los vertices en el orden de los indices:
        glDisableClientState( GL_VERTEX_ARRAY ); // deshabilitar array
    }
    
    if (modo_vis==3) {
        int num_indices = tabla_indices.size();
        glEnableClientState( GL_VERTEX_ARRAY); // habilitar array de vertices
        glVertexPointer( 3, GL_FLOAT, 0, &tabla_vertices[0] );  // establecer dirección y estructura
        for (int i=0; i<num_indices; i++) {
            if (i%2==0) {
                glColor3f( 1.0, 0.0, 0.0 );
            }
            else{
                glColor3f( 0.0, 1.0, 0.0 );
            }
            //std::cout << "Dibujando cara" << i*sizeof(GL_FLOAT) << std::endl;
            glDrawElements( GL_TRIANGLES, 3, GL_UNSIGNED_INT, &tabla_indices[i] );     // visualizar
        }
        glDisableClientState( GL_VERTEX_ARRAY ); // deshabilitar array
    }
}