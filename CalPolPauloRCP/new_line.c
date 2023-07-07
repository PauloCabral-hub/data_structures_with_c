#include<stdlib.h>
#include<stdio.h>
#include<string.h>



typedef struct filano FilaNo;
typedef struct fila Fila;

struct fila{
FilaNo* ini;
FilaNo* fim;
};

struct filano{
char info[50];
FilaNo* prox;
};

Fila* cria_fila(void){

Fila* new_line = (Fila*) malloc(sizeof(Fila));
if(new_line == NULL){
printf("\nMemoria insificiente para insercao de elemento \n");
return;
}
new_line->ini = NULL;
new_line->fim = NULL;


return new_line;
}

Fila* insere_fila(char n[50], Fila* f){
FilaNo* hold;
FilaNo* novo = (FilaNo*) malloc(sizeof(FilaNo));
if(novo == NULL){
printf("\nMemoria insificiente para insercao de elemento. \n");
return;
}

if(f->ini == NULL){
strcpy(novo->info, n); /*novo->info = n;*/
novo->prox = NULL;
f->ini = novo;
f->fim  = novo;
}
else{
strcpy(novo->info, n); /*novo->info = n;*/
novo->prox = NULL;
hold = f->fim;
hold->prox = novo;
f->fim = novo;
}

return f;
}

Fila* fila_sai(char* popped[50], Fila* f){
FilaNo* hold;

if(f->ini == NULL){
printf("\n Nao ha elementos na fila. \n");
return;
}
if(f->ini == f->fim){
strcpy(popped,f->ini->info); /*out = f->ini->info;*/
hold = f->ini;
f->ini = f->fim = NULL;
free(hold);
}
else{
strcpy(popped,f->ini->info);
hold = f->ini;
f->ini = f->ini->prox;
free(hold);
}

return f;
}

void imprime_fila(Fila* f){
FilaNo* hold;

if(f->ini == NULL){
printf("\nNao ha elementos a serem impressos. \n");
return;
}
hold = f->ini;

printf("\n::Fila inicio::");
while(hold != NULL){
printf("%s ", hold->info);
hold = hold->prox;
}
printf("::Fila fim :: \n");

}

