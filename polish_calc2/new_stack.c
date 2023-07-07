#include<stdlib.h>
#include<stdio.h>

typedef struct pilhano PilhaNo;
typedef struct pilha Pilha;

struct pilhano{
  char info;
  PilhaNo* prox;
};

struct pilha{
PilhaNo* topo;
};




//Function for stack creation:
//Return 1 in case of success and 0 otherwise.

Pilha* cria_pilha(void){

Pilha *nova_pilha = (Pilha*) malloc(sizeof(Pilha));
if(nova_pilha == NULL){
printf("Insufficient memory for stack.\n");
return 0;
}
else{
nova_pilha->topo = NULL;
}

return nova_pilha;
}

//Function to push an element into the stack:
// return 1 in case of success and 0 otherwise.

Pilha* empilha(char element, Pilha *p){

PilhaNo *novo = (PilhaNo*) malloc(sizeof(PilhaNo));

if(novo == NULL){
printf("Insufficient memory for a new element.\n");
return ;
}
else{
novo->info = element;
novo->prox = p->topo;
p->topo= novo;
}

return p;
}

//Function to pop an element into the stack:
// return 1 in case of success and 0 otherwise.


Pilha* desempilha(char* poped, Pilha* p){
PilhaNo* hold;

if(p->topo == NULL){
printf("There is no element stacked. \n");
return;
}
else{
hold = p->topo;
*poped = p->topo->info;
p->topo= p->topo->prox;
free(hold);
}

return p;
}


void imprime_pilha(Pilha* p){
PilhaNo* aux;

if(p->topo == NULL){
printf("There is no element stacked. \n");
return;
}
else{
aux = p->topo;
printf("--stack top-- \n");
}

while(aux){
printf("%c \n", aux->info);
aux = aux->prox;
}
printf("--stack base--\n");

return;
}
