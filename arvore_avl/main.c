#include <stdio.h>
#include <stdlib.h>
#include "estruturas_avl.h"
#include "functions.h"

int main(void){
ArvNo* arvore;
int h, dim;
int* spc;
arvore = cria_arvore(5);
arvore = avl_inA(arvore, 8);
arvore = avl_inA(arvore, 3);
arvore = avl_inA(arvore, 1);
impressao_especial(arvore);
arvore = avl_inA(arvore, 2);
impressao_especial(arvore);
arvore = avl_inA(arvore, 6);
impressao_especial(arvore);
arvore = avl_inA(arvore, 7);
impressao_especial(arvore);
arvore = avl_inA(arvore, 9);
impressao_especial(arvore);
arvore = avl_inA(arvore, 4);
impressao_especial(arvore);
imprime_arvore(arvore);
arvore = avl_delA(arvore, 7);
imprime_arvore(arvore);
impressao_especial(arvore);
arvore = avl_delA(arvore, 1);
arvore = avl_delA(arvore, 3);
arvore = avl_delA(arvore, 4);
impressao_especial(arvore);







return 0;
}

