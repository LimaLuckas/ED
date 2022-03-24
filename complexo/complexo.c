#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complexo.h"

#ifndef _COMPLEXO_C
#define _COMPLEXO_C

struct cmp{
    float a;
    float b;
};

Complexo* cria_complexo(float a, float b){

    Complexo* cmp = (Complexo*) malloc(sizeof(Complexo*));

    if(cmp){
        cmp->a = a;
        cmp->b = b;
        return cmp;
    }
    return NULL;
}

void libera_complexo(Complexo* cmp){
    free(cmp);
}

float pega_valores(Complexo* cmp, float* a, float* b){

    if(cmp){
        *a = cmp->a;
        *b = cmp->b;
        return 1;
    }

    return 0;
}

float seta_valores(Complexo* cmp, float a, float b){
    if(cmp){
        a = cmp->a;
        b = cmp->b;
        return 1;
    }

    return 0;
}

Complexo* soma_complexos(Complexo* cmp, Complexo* cmp2){

    Complexo* cmp_result = cria_complexo(0.0,0.0);

    if(cmp_result){

        cmp_result->a = cmp->a + cmp2->a;
        cmp_result->b = cmp->b + cmp2->b;

        return cmp_result;
    }

    return NULL;
}


Complexo* sub_complexos(Complexo* cmp, Complexo* cmp2){

    Complexo* cmp_result = cria_complexo(0.0,0.0);

    if(cmp_result){

        cmp_result->a = cmp->a - cmp2->a;
        cmp_result->b = cmp->b - cmp2->b;

        return cmp_result;
    }

    return NULL;
}

Complexo* mult_complexos(Complexo* cmp, Complexo* cmp2){

    Complexo* cmp_result = cria_complexo(0.0,0.0);

    if(cmp_result){

        cmp_result->a = (cmp->a*cmp2->a - cmp->b * cmp2->b);
        cmp_result->b = (cmp->b * cmp2->a - cmp->a*cmp2->b);

        return cmp_result;
    }

    return NULL;
}

Complexo* div_complexos(Complexo* cmp, Complexo* cmp2){

    Complexo* cmp_result = cria_complexo(0.0,0.0);

    if(cmp_result){

        cmp_result->a = (cmp->a*cmp2->a - cmp->b * cmp2->b)/(pow(cmp2->a,2) + pow(cmp2->b,2));
        cmp_result->b = (cmp->b * cmp2->a - cmp->a*cmp2->b)/(pow(cmp2->a,2) + pow(cmp2->b,2));

        return cmp_result;
    }

    return NULL;
}

#endif // _COMPLEXO_C
