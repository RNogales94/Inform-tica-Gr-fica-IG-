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
        int num_indices = tabla_indices.size();
        glEnableClientState( GL_VERTEX_ARRAY); // habilitar array de vertices
        glVertexPointer( 3, GL_FLOAT, 0, &tabla_vertices[0] );  // establecer dirección y estructura
        glDrawElements( GL_LINE_STRIP, num_indices*3, GL_UNSIGNED_INT, &tabla_indices[0] );     // visualizar recorr iendo los vertices en el orden de los indices:
        glDisableClientState( GL_VERTEX_ARRAY ); // deshabilitar array
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

 
    if (modo_vis==4) {
        glBegin(GL_TRIANGLES);
        // Dibujamos un triángulo
        glColor3f(1.0,0.0,0.0);
        // Color del primer vértice: rojo
        glVertex3f(tabla_vertices[0][X], tabla_vertices[0][Y], tabla_vertices[0][Z]);
        // Coordenadas del primer vértice
        glColor3f(0.0,1.0,0.0);
        // Color del segundo vértice: verde
        glVertex3f(tabla_vertices[1][X], tabla_vertices[1][Y], tabla_vertices[1][Z]);
        // Coordenadas del  segundo vértice
        glColor3f(0.0,0.0,1.0);
        // Color del tercer vértice: azúl
        glVertex3f(tabla_vertices[2][X], tabla_vertices[2][Y], tabla_vertices[2][Z]);
        // Coordenadas del  tercer vértice
        glEnd();
        // Terminamos de dibujar
    }
}