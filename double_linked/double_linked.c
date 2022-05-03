#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "double_linked.h"

#ifndef _DOUBLE_LINKED_C
#define _DOUBLE_LINKED_C

struct node{
	int valor;
	struct node * prox;
	struct node * ant;
};

/* inserção no início */
Node* criar(int valor) {
    Node* novo = (Node*) malloc(sizeof(Node));
    
    if(novo != NULL){
        novo->valor = valor;
        novo->prox = NULL;
        novo->ant = NULL;

        return novo;
    }

    free(novo);
    return NULL;
}

int append(Node** lhead, int valor){

    Node* aux = *lhead;

    Node* novo = criar(valor);

    if(is_empty(*lhead)){

        aux = novo;
        return 1;
    }

    while(aux->prox != NULL)
        aux = aux->prox;
    
    aux->prox = novo;
    novo->ant = aux;
    return 1;


    return 0;
}

int push(Node** lhead, int valor){

    Node* novo = criar(valor);

    if(is_empty(*lhead)){
        *lhead = novo;
        return 1;
    }

    *lhead->ant = novo;
    novo->prox = *lhead;
    *lhead = novo;

    return 1;
}

void imprimir(Node* lhead){

    if(is_empty(*lhead)){
        return NULL;
    }

    Node* aux = *lhead;

    while(aux->prox != NULL){
        printf(" %d ", aux->valor);
        aux = aux->prox;
    }
}

int is_empty(Node *lhead){

    return(lhead == NULL);
}

int contar(Node *lhead){

    int count = 0;

    Node* aux = *lhead;

    while(aux->prox != NULL){
        count++;
        aux = aux->prox;
    }

    return count;
}

int remover(Node** lhead, int valor){

    if(is_empty(*lhead)){
        return 0;
    }

    Node* del = *lhead;

    while(del->prox != NULL){
        
        if(del->valor == valor){
            break;
        }

        del = del->prox;
    }

    if(del->ant == NULL){
        *lhead = del->prox;
        free(del);
        return 1;
    }
    else if(del->prox == NULL){
        del->ant->prox = NULL;
        free(del);
        return 1;
    }
    else{
        del->prox->ant = del->ant;
        del->ant->prox = del->prox;
        free(del);
        return 1;
    }

    return 0;
}

void liberar(Node** lhead){

    No* prox = NULL;
    No* aux = *lhead;

    while(aux->prox ! NULL){
        prox = aux->prox;
        free(aux);
        aux = prox;
    }

    *lhead = NULL;
}

#endif
