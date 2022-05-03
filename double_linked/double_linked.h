#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _DOUBLE_LINKED_H_
#define _DOUBLE_LINKED_H_

typedef struct node Node;

Node* criar(int valor);
int is_empty(Node *lhead);
int append(Node** lhead, int valor);
int push(Node** lhead, int valor);
void imprimir(Node * lhead);
int contar(Node * lhead);
void remover(Node** lhead, int* valor);
void liberar(Node * lhead);

#endif