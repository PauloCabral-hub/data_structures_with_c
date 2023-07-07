/*Dynamic allocation and linked lists*/
#include<stdio.h>
#include<stdlib.h>

struct lista{
int info;
struct lista *prox;
};

typedef struct lista Lista;

/*Empty list creation function */
Lista* cria(void){
    return NULL;
}

/*Insert new element function */
Lista* insere(Lista* l, int i){
Lista *novo = (Lista*) malloc(sizeof(Lista));
novo-> info = i;
novo-> prox = l;
return novo;
}

void imprime(Lista *l){
Lista *needle;
    for(needle = l; needle != NULL; needle = needle->prox){
    printf("\n%d", needle->info);

    }
}

int vazia(Lista* l){
int i;
    if(l!= NULL){
    return 1;
    }
    else{
    return 0;
    }
}

int busca(Lista *l,int i){
Lista *aux;
for(aux = l; (aux!= NULL)&&(aux->info != i); aux = aux->prox){

}
return (int) aux;
}

Lista* inclui(Lista* l, int i){
Lista *pauxa;
Lista *pauxb;
Lista *novo = (Lista*) malloc(sizeof(Lista));
if (( l->prox == NULL)&&(l->info <i)){
    novo->info = i;
    novo->prox = l;
    return novo;
}
else{
    for(pauxa = l, pauxb = l->prox; (pauxb != NULL)&&(pauxb->info<i); pauxa = pauxa->prox, pauxb = pauxb->prox);
    novo->info = i;
    novo->prox = pauxb;
    pauxa->prox = novo;
    return l;
}
}

int main(void){
int e, f;
Lista *l;

l = cria();

l = inclui(l,23);
imprime(l);

/*l = insere(l,23); l = insere(l, 45);l = inclui(l,26); e = vazia(l); f = busca(l,45);*/

printf("\n This: %d", f);


return 0;
}
