#include<stdlib.h>
#include<stdio.h>

typedef struct filano FilaNo;
typedef struct fila Fila;

struct fila{
FilaNo* ini;
FilaNo* fim;
};

struct filano{
char info;
FilaNo* prox;
};

Fila* cria_fila(void){

Fila* new_line = (Fila*) malloc(sizeof(Fila));
if(new_line == NULL){
printf("Insufficient memory for a line. \n");
return;
}
new_line->ini = NULL;
new_line->fim = NULL;


return new_line;
}

void insere_fila(char n, Fila* f){
FilaNo* hold;
FilaNo* novo = (FilaNo*) malloc(sizeof(FilaNo));
if(novo == NULL){
printf("Insufficient memory to insert a element on the line. \n");
return;
}

if(f->ini == NULL){
novo->info = n;
novo->prox = NULL;
f->ini = novo;
f->fim  = novo;
}
else{
novo->info = n;
novo->prox = NULL;
hold = f->fim;
hold->prox = novo;
f->fim = novo;
}

return;
}

char fila_sai(Fila* f){
char out;
FilaNo* hold;

if(f->ini == NULL){
printf("There is no element in line. \n");
return;
}
if(f->ini == f->fim){
out = f->ini->info;
hold = f->ini;
f->ini = f->fim = NULL;
free(hold);
}
else{
out = f->ini->info;
hold = f->ini;
f->ini = f->ini->prox;
free(hold);
}

return out;
}

void imprime_fila(Fila* f){
FilaNo* hold;
char n;

if(f->ini == NULL){
printf("Sorry, no element to be printed. \n");
return;
}
hold = f->ini;

printf("\n::line::");
while(hold != NULL){
n = hold->info;
printf("%c", n);
hold = hold->prox;
}
printf("::line:: \n");

}

