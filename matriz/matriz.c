#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

#ifndef _MATRIZ_C_
#define _MATRIZ_C_

struct matriz{
    int lin;
    int col;
    float ** v;
};

Matriz* cria_matriz(int nl, int nc){

    Matriz *mat = (Matriz*) malloc(sizeof(Matriz));

    if(mat){

        mat->lin = nl;
        mat->col = nc;
        mat->v = (float**) malloc(nl*sizeof(float*));
        if(mat->v){ 

            for(int i = 0;i< nl;i++){
                mat->v[i] == (float*)malloc(nc*sizeof(float));
            
                if (mat->v[i] == NULL){
                    libera_matriz(mat);
                    return NULL;
                }
            }
            return mat;       
        }    
    }
    return NULL;
}

void libera_matriz(Matriz * mat){
    int i;
    for (i=0; i<mat->lin; i++)
        free(mat->v[i]);

    free(mat->v);
    free(mat);
}

int acessa_matriz(Matriz * mat, int i, int j, float * v){
    if (i<0 || i>=mat->lin || j<0 || j>=mat->col) {
        
        return 0;
    }
    return mat->v[i][j];
}

int atribui_matriz(Matriz * mat, int i, int j, float v) {
    if (i<0 || i>=mat->lin || j<0 || j>=mat->col) {

        return 0;
    }

    mat->v[i][j] = v;
    return 1;
}

int nlinhas(Matriz * mat){
    return mat->lin;
}

int ncolunas(Matriz * mat){
    return mat->col;

}

Matriz* gerar_transposta(Matriz* matriz){
    int ind;
    Matriz* mat = cria_matriz(matriz->col,matriz->lin);
    if(mat){
        for(int i = 0;i < mat->lin;i++){
            for(int j = 0;i < mat->col;i++){
                mat->v[i][j] = matriz->v[j][i];
            }

        }
        return mat;
    }
    return NULL;
}


#endif
