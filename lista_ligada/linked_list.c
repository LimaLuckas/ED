#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

#ifndef _LINKED_LIST_C_
#define _LINKED_LIST_C_

struct no{
    int info;
    struct no* prox;
    
};

No* ll_create_no(int info){

    No* no =(No*) malloc(sizeof(No));
    if(no){

        no->info = info;
        no->prox = NULL;
    }
    return no;
}

int ll_is_empty(No* lhead){
    return(lhead == NULL);

}

int ll_size(No* lhead){

    int counter = 0;
    while (lhead!=NULL)
    {
        counter++;
        lhead = lhead->prox;
    }
    return counter;
}

int ll_insert_first(No** lhead, int info){

    No* aux = ll_create_no(info);
    if(aux){
        aux->prox = *lhead;
        *lhead = aux;
        return 1;
    }

    return 0;
}

int ll_insert_last(No** lhead, int info){

    if(ll_is_empty(*lhead)){
        return ll_insert_first(lhead, info);
    }

    No* aux = ll_create_no(info);

    if(aux){

        No* crt = *lhead;
        while (crt->prox!= NULL)
        {
            crt = crt->prox;
        }

        crt->prox = aux;
        return 1;
    }

    return 0;
}

int ll_exists(No* lhead, int info){

    if(ll_is_empty(lhead)){
        return 0;
    }

    while(lhead!=NULL){

        if(lhead->info == info)
            return 1;

        lhead = lhead->prox;
    }

    return 0;
}

void ll_print(No* lhead, char* message){

    printf("%s ", message);
    while (lhead!= NULL)
    {
        printf("%d", lhead->info);
        lhead = lhead->prox;
    }

    printf("\n");
}

int ll_remove(No** lhead, int info){
    No* anterior = NULL;
    No* aux = *lhead;
    int found = 0;

    while (aux->info!=NULL)
    {
        if(aux->info == info){
            found = 1;
            break;
        }

        anterior = aux;
        aux = aux->prox;
    }

    if(found){
        if(anterior == NULL){
            *lhead = aux->prox;
            free(aux);
            return 1;
        }

        anterior->prox = aux->prox;
        free(aux);
        return 1;
    }
    return 0;
}

void ll_clear(No** lhead){
    No* prox = NULL;
    No* aux = *lhead;
    while(aux!=NULL){

        prox = aux->prox;
        free(aux);
        aux = prox;
    }

    *lhead = NULL;
}

int ll_insert_sorted(No** lhead, int info){

    if(ll_is_empty(*lhead))
        return(ll_insert_first(lhead,info));

    No* novo = ll_create_no(info);
    if(novo){

        No* anterior = NULL;    
        No* aux = *lhead;
        while (aux!=NULL && aux->info < info)
        {
            anterior = aux;
            aux = aux->prox;
        }
        
        if(anterior == NULL){
            novo->prox = *lhead;
            *lhead = novo;
            return 1;
        }
        novo->prox = anterior->prox;
        anterior->prox = novo;
        return 1;
    }
    return 0;
}

#endif