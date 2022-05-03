#include <stdio.h>
#include <stdlib.h>
#include "double_linked.h"

int main(){
    
    Node* no = criar(2);
    append(&no,3);
    push(&no,1);

    imprimir(&no);

    return 0;
}