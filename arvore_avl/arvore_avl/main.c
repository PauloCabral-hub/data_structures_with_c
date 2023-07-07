#include <stdio.h>
#include <stdlib.h>
#include "estruturas_avl.h"
#include "functions.h"

int main(void){
int item = 6;
Arv* arvore = cria_arvore(item);
arvore = avl_inA(arvore,4);
arvore = avl_inA(arvore,8);
arvore = avl_inA(arvore,5);
arvore = avl_inA(arvore,3);
arvore = avl_inA(arvore, 2);
imprime_arvore(arvore);

return 0;
}

