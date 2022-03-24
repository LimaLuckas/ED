#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

#ifndef _MATRIZ_C_
#define _MATRIZ_C_

struct matriz{
    int lin;
    int col;
    float * v;
};

Matriz* cria_matriz(int nl, int nc){

    Matriz *mat = (Matriz*) malloc(sizeof(Matriz));

    if(mat){

        mat->lin = nl;
        mat->col = nc;
        mat->v = (float*) malloc(nl*nc*sizeof(float));

        if(!(mat->v)){
          free(mat->v);
          return NULL;
        }

        return mat;
    }

    return NULL;
}

void libera_matriz(Matriz * mat){
    free(mat->v);
    free(mat);
}

int acessa_matriz(Matriz * mat, int i, int j, float * v){
    int ind;

    if(mat && i >= 0 && i < mat->lin && j >= 0 && j < mat->col){

        ind = i*mat->col + j;

        return mat->v[ind];

    }

    return 0;
}

int atribui_matriz(Matriz * mat, int i, int j, float v) {
    int ind;

    if(mat && i >= 0 && i < mat->lin && j >= 0 && j < mat->col){

        ind = i*mat->col + j;

        return mat->v[ind] = v;

    }

    return 0;
}

int nlinhas(Matriz * mat){
    return mat->lin;
}

int ncolunas(Matriz * mat){
    return mat->col;

}


#endif
