#include <stdio.h>
#include <stdlib.h>

typedef struct arvno ArvNo;
typedef struct arv Arv;

Arv* cria_raiz(ArvNo* novo_no);
ArvNo* cria_no(int info, ArvNo* esq, ArvNo* dir);
ArvNo* buscaAle(Arv* arvore, int elemento);
ArvNo* buscaAle_no(ArvNo* no, int elemento);
void altura_arvA(Arv* arvore, int* altura);
int altura_arvB(ArvNo* nos);
int compara(int e, int d);
void imprime_arvore(Arv* arvore);
void imprime_no(ArvNo* No);

int busca_rapidaA(Arv* arvore, ArvNo** recebe, int item);
int busca_rapidaB(ArvNo* no_raiz, ArvNo** recebe, int item);

Arv* insere_noA(Arv* arvore, int item);
void insere_noB(ArvNo* no_atual, int item);

Arv* removeA(Arv* arvore, int item);
ArvNo* remove_noB(ArvNo* no, int item);


struct arvno {
 int info, bf;
 ArvNo* ramodir;
 ArvNo* ramoesq;
};

struct arv{
ArvNo* raiz;

};

int main(void){
ArvNo* item = NULL;
int este = 1,alt = 0, result;


imprime_arvore(arvore); printf("\n");


/* Testing the search function */
result = busca_rapidaA(arvore, &recebe, item2);

printf("\n The following item was returned from searching the binary tree: %d", recebe->info);

/* Testing remove function */
arvore = removeA(arvore,5);
imprime_arvore(arvore);


return 0;
}


