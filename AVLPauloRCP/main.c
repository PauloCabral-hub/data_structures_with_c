#include <stdio.h>
#include <stdlib.h>
#include "estruturas_avl.h"
#include "functions.h"

int main(void){
ArvNo* arvore;
int h, dim;
int* spc;
arvore = cria_arvore(50);
arvore = avl_inA(arvore, 80);
arvore = avl_inA(arvore, 30);
arvore = avl_inA(arvore, 10);
impressao_especial(arvore);
arvore = avl_inA(arvore, 20);
impressao_especial(arvore);
arvore = avl_inA(arvore, 60);
impressao_especial(arvore);
arvore = avl_inA(arvore, 70);
impressao_especial(arvore);
arvore = avl_inA(arvore, 90);
impressao_especial(arvore);
arvore = avl_inA(arvore, -20);
impressao_especial(arvore);
imprime_arvore(arvore);
arvore = avl_delA(arvore, 70);
imprime_arvore(arvore);
impressao_especial(arvore);
arvore = avl_delA(arvore, 10);
arvore = avl_delA(arvore, 30);
arvore = avl_delA(arvore, 40);
impressao_especial(arvore);







return 0;
}

