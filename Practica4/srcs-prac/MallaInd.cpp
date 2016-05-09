#include "MallaInd.hpp"
#include "aux.hpp"


//GL_POINTS
//GL_TRIANGLES
//GL_LINE_LOOP
//GL_LINES
//GL_LINE_STRIP

void MallaInd::visualizar(unsigned modo_vis){
    // BLOQUE:
    // INICIALIZACION: TEXTURAS + NORMALES (para iluminacion)
    
    if(normales_vertices.size() != 0)
        glEnableClientState( GL_NORMAL_ARRAY );
    glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vertices
    if(coords_textura.size() != 0)
        glEnableClientState( GL_TEXTURE_COORD_ARRAY );
    
    if(normales_vertices.size() != 0)
        glNormalPointer(GL_FLOAT, 0, &normales_vertices[0]);
    
    if(coords_textura.size() != 0)
        glTexCoordPointer( 2, GL_FLOAT, 0, &coords_textura[0] );
    glVertexPointer( 3, GL_FLOAT, 0, &tabla_vertices[0] );
    
    // FIN BLOQUE
    
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
    
    // BLOQUE:
    // DESHABILITACION: TEXTURAS + NORMALES (para iluminacion)
    if(coords_textura.size() != 0)
        glDisableClientState( GL_TEXTURE_COORD_ARRAY );
    if(normales_vertices.size() != 0)
        glDisableClientState( GL_NORMAL_ARRAY );
    glDisableClientState( GL_VERTEX_ARRAY );
    // FIN BLOQUE

    

}
/*
void MallaInd::visualizar(ContextoVis cv){
    cv.materialActivo->activar();
    switch (cv.modo_vis) {
        case 0:
            visualizar(0);
            break;
        case 1:
            visualizar(1);
            break;
        case 2:
            visualizar(2);
            break;
        case 3:
            visualizar(3);
            break;
        case 4:
            visualizar(2);
            break;
        default:
            break;
    }
    
}
*/

void MallaInd::calcularNormales(){
    int num_caras = tabla_indices.size();
    int num_vertices = tabla_vertices.size();
    
    //Inicializacion tabla_normales_vertices
    for (int i=0; i<num_vertices; i++) {
        normales_vertices.push_back(Tupla3f(0,0,0));
    }
    cout << "Calculando normales (Mallaind)"<<endl;
    //Calculo de los normales de las caras
    for (int i=0; i<num_caras; i++) {
        //Obtenemos los tres vertices de la cara i-esima
        Tupla3f v1 = tabla_vertices[tabla_indices[i][0] ];
        Tupla3f v2 = tabla_vertices[tabla_indices[i][1] ];
        Tupla3f v3 = tabla_vertices[tabla_indices[i][2] ];
        
        //Obtenemos dos vectores e1 y e2 (los que generan la cara i-esima)
        Tupla3f e1 = v2 - v1;
        Tupla3f e2 = v3 - v1;

        //Creamos el vector normal a la cara i-esima
        Tupla3f n = (e1.cross(e2)).normalized();
        normales_caras.push_back(n);
        for (int j=0; j<3; j++) {
            normales_vertices[tabla_indices[i][j]] = normales_vertices[tabla_indices[i][j]] + normales_caras[i];
        }
    }

    //Normalizacion tabla_normales_vertices
    for (int i=0; i<num_vertices; i++) {
        normales_vertices[i].normalized();
    }

}









