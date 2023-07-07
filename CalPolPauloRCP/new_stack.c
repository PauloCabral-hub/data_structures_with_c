#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct pilhano PilhaNo;
typedef struct pilha Pilha;


struct pilhano{
  char info[50];
  PilhaNo* prox;
};

struct pilha{
PilhaNo* topo;
};




/*Função para criação da pilha*/

Pilha* cria_pilha(void){

Pilha *nova_pilha = (Pilha*) malloc(sizeof(Pilha));
if(nova_pilha == NULL){
printf("Memoria insuficiente para criacao de pilha.\n");
return 0;
}
else{
nova_pilha->topo = NULL;
}

return nova_pilha;
}

/*Função empilha*/


Pilha* empilha(char element[50], Pilha *p){

PilhaNo *novo = (PilhaNo*) malloc(sizeof(PilhaNo));

if(novo == NULL){
printf("Memoria insuficiente para insercao de elemento.\n");
return ;
}
else{
strcpy(novo->info, element); /*novo->info = element;*/
novo->prox = p->topo;
p->topo= novo;
}

return p;
}

/*Função para retirada de um elemento da pilha:*/


Pilha* desempilha(char* poped[50], Pilha* p){
PilhaNo* hold;

if(p->topo == NULL){
printf("Nao ha elementos na pilha. \n");
return;
}
else{
hold = p->topo;
strcpy(poped,p->topo->info);   /* *poped = p->topo->info;*/
p->topo= p->topo->prox;
free(hold);
}

return p;
}


void imprime_pilha(Pilha* p){
PilhaNo* aux;

if(p->topo == NULL){
printf("\n Nao ha elementos na pilha. \n");
return;
}
else{
aux = p->topo;
printf("--Topo da Pilha-- \n");
}

while(aux){
printf("%s \n", aux->info);
aux = aux->prox;
}
printf("--Topo da Fila--\n");

return;
}

