#include <stdio.h>
#include "matriz.h"
#define _NUMLINHAS_ 3
#define _NUMCOLUNAS_ 3

int main(){

    Matriz *mat = cria_matriz(_NUMLINHAS_,_NUMCOLUNAS_);
    float input;

    for(int i = 0; i < _NUMLINHAS_; i++){
      for(int j = 0; j < _NUMCOLUNAS_; j++){
        printf("Digite o elemento na posição %d,%d:\n",i,j);
        scanf("%f",&input);
        atribui_matriz(mat,i,j,input);
        }
    }
    scanf("%f",&input);
    float elem = acessa_matriz(mat,1,1,&input);
    printf("%.2f",elem);


    return 0;
