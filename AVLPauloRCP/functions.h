#include <stdio.h>
#include <stdlib.h>

typedef struct arvno ArvNo;
typedef struct arv Arv;

/*Funções básicas*/

/*Função de criação da árvore*/
Arv* cria_arvore(int item);
ArvNo* cria_no(int item);

/*Funções de impressão*/
void imprime_arvore(Arv* arvore);
void imprime_no(ArvNo* No);

/* Funções de cálculo de altura*/
void altura_arvA(Arv* arvore, int* altura);
int altura_arvB(ArvNo* nos);
int compara(int e, int d);

/* Funções de busca*/
int busca_rapidaA(Arv* arvore, ArvNo** recebe, int item);
int busca_rapidaB(ArvNo* no_raiz,ArvNo** recebe, int item);

/*Funções de inserção*/
Arv* avl_inA(Arv* arvore, int item);
ArvNo* avl_inB(ArvNo* No, int item);

/*Funções de deleção*/
Arv* avl_delA(Arv* arvore, int item);
ArvNo* avl_delB(ArvNo* No, int item);

/*Funções auxiliares*/
int weight(ArvNo* no_atual); /* fornece o fator de balanceamento da árvore*/
ArvNo* rotaciona(ArvNo* no_atual, int sit, int doue); /* rotaciona em caso de desbalanceamento. 'sit' indica a situação, 'doue' indica se o nó está a direita ou esquerda do nó atual*/

/*Funções de liberação da memória dinâmica*/
void libera_arv(Arv* arvore);
void libera_no(ArvNo* no);

/*Funções auxiliares de impressão */
Lista* listagemA(Arv* arvore);
ArvNo* listagemB(ArvNo* No, Lista **itens, int n, int* v);
void impressao_especial(Arv* arvore);

/*Função de balanceamento*/
ArvNo* balanceia(ArvNo* No);


/*-----------------------------------------------------------------------------------------*/

/*Função de criação do primeiro nó*/
Arv* cria_arvore(int item){
Arv* arvore = (Arv*) malloc(sizeof(Arv));
arvore->raiz = (ArvNo*) malloc(sizeof(ArvNo));

arvore->raiz->info = item;
arvore->raiz->bf = 0;
arvore->raiz->ramodir = NULL; arvore->raiz->ramoesq = NULL;


return arvore;
}

ArvNo* cria_no(int item){
ArvNo* novo_no = (ArvNo*) malloc(sizeof(ArvNo));
novo_no->info = item;
novo_no->bf = 0;
novo_no->ramodir=NULL;
novo_no->ramoesq=NULL;
return novo_no;
}

/*Função de impressão da árvore */
void imprime_arvore(Arv* arvore){

if(arvore->raiz == NULL){
return;
}
imprime_no(arvore->raiz);
}

/*auxiliar de impressão*/
void imprime_no(ArvNo* No){
    printf("<");
    if(No!= NULL){
        if(No->ramoesq!=NULL){imprime_no(No->ramoesq);
        }
        printf("%d (%d)",No->info, No->bf);
        if(No->ramodir!=NULL){imprime_no(No->ramodir);
        }
    }
    printf(">");
return;

};

/*Funções para o cálculo da altura da árvore*/
void altura_arvA(Arv* arvore, int* altura){

*altura = altura_arvB(arvore->raiz);
}

int altura_arvB(ArvNo* nos){

if(nos== NULL){
return -1;
}
else{
return 1+ compara(altura_arvB(nos->ramoesq),altura_arvB(nos->ramodir));
}

}

int compara(int e, int d){
return (e>d)?e:d;
}

/*Funções de Busca*/
int busca_rapidaA(Arv* arvore, ArvNo** recebe, int item){
int result;

result = busca_rapidaB(arvore->raiz, recebe, item);

return result;
}

int busca_rapidaB(ArvNo* no_raiz,ArvNo** recebe, int item){
int result;
ArvNo* holder = no_raiz;

/*condição de contorno*/
if(holder == NULL){
result =  0;
return result;
}
if(holder->info > item){
result = busca_rapidaB(holder->ramoesq, recebe, item);

}
else if(holder->info < item){
result = busca_rapidaB(holder->ramodir, recebe, item);

}
else{
*recebe = holder; result = 1;

return result;
}

return result;
}

/* Funções Auxiliares: As seguintes funções são necessárias para implementação da inserção e deleção em árvore avl*/

/*Função de cálculo do fator de balanceamento: faz uso de altura_arvB*/
int weight(ArvNo* no_atual){
int weight, a, b;

a = altura_arvB(no_atual->ramodir);
b = altura_arvB(no_atual->ramoesq);

weight = a-b;

return weight;
}



/*Funções de inserão*/

Arv* avl_inA(Arv* arvore, int item){
printf("\n Nova Insercao");
arvore->raiz = avl_inB(arvore->raiz, item);

return arvore;
}

ArvNo* avl_inB(ArvNo* No, int item){

if(No == NULL){
printf("\n No Nulo");
ArvNo* novo = (ArvNo*) malloc(sizeof(ArvNo));
novo->bf= 0;
novo->info = item;
novo->ramodir = novo->ramoesq = NULL;
return novo;
}
else if(No->info < item){
printf("\n No menor que o item a inserir");
No->ramodir = avl_inB(No->ramodir, item);
/*Verificar a altura, corrigir a altura*/
No->bf = weight(No);
}
else if(No->info > item){
printf("\n No maior que o item a inserir");
No->ramoesq =  avl_inB(No->ramoesq, item);
/*Verificar a altura*/
No->bf = weight(No);
}

if( (No->bf<-1)||(No->bf>1) ){
printf("\n Acao de balanceamento. No: %d.", No->info);
No = balanceia(No);
}

return No;
}

ArvNo* balanceia(ArvNo* No){
int ba,bb;

if(No == NULL){
}
else{
ba = altura_arvB(No->ramoesq)-altura_arvB(No->ramodir);

    if(ba>1){/*desbalanceamo à esquerda*/
    bb = altura_arvB(No->ramoesq->ramodir)-altura_arvB(No->ramoesq->ramodir);
        if(bb==1){ /*Rotação simples*/
        ArvNo* guarda1 = No->ramoesq;
        No->ramoesq = guarda1->ramodir;/*recalculando peso */ No->bf = weight(No);
        guarda1->ramodir = No;
        No = guarda1; /* recalculando o peso*/ No->bf = weight(No);
        }
        else{ /*Rotação dupla à esquerda*/
        ArvNo* guarda1 = No->ramoesq; ArvNo* guarda2 = guarda1->ramodir;
        guarda1->ramodir = guarda2->ramoesq; /*recalculando peso*/ guarda1->bf = weight(guarda1);
        guarda2->ramoesq = guarda1; /*recalculando peso*/ guarda2->bf = weight(guarda2);
        No->ramoesq = guarda2;
        /*fim do procedimento no pivor menor*/
        guarda1 = No->ramoesq;
        No->ramoesq = guarda1->ramodir; /*recalculando peso*/ No->bf = weight(No);
        guarda1->ramodir = No; /*recalculando peso*/ guarda1->bf = weight(guarda1);
        No = guarda1;
        }
    }
    else if(ba<-1){
    bb = altura_arvB(No->ramodir->ramoesq)-altura_arvB(No->ramodir->ramodir);
        if(bb = -1){ /*Rotação Simples*/
        ArvNo* guarda1 = No->ramodir;
        No->ramodir = guarda1->ramoesq; /*Recalculando peso*/ No->bf = weight(No);
        guarda1->ramoesq = No;
        No = guarda1; /*Recalculando peso*/ No->bf =weight(No);
        }
        else{
        ArvNo* guarda1 = No->ramodir; ArvNo* guarda2 = guarda1->ramoesq;
        guarda1->ramoesq = guarda2->ramodir; /*recalculando peso*/ guarda1->bf = weight(guarda1);
        guarda2->ramodir = guarda1; /*recalculando peso*/ guarda2->bf = weight(guarda2);
        No->ramodir = guarda2;
        /* Fim do procedimento no pivor menor*/
        guarda1 = No->ramodir;
        No->ramodir = guarda1->ramoesq; /*recalculando peso*/ No->bf = weight(No);
        guarda1->ramoesq = No; /*recalculando peso*/ guarda1->bf = weight(guarda1);
        No = guarda1;
        }
    }
    else{
    }

No->ramoesq = balanceia(No->ramoesq);
No->ramodir = balanceia(No->ramodir);
}

return No;
}



Lista* listagemA(Arv* arvore){
Lista* itens = NULL;
int n, v, h; /*n - onde deseja chegar, v -  visitando, h - altura da arv */
Lista* aux;

altura_arvA(arvore, &h); n = 0;

for(n = 0; n <= h; n++){
v = 0;
arvore->raiz = listagemB(arvore->raiz, &itens, n, &v);
}

aux = itens;
printf("\n");
while(aux!= NULL){
printf("- %d level: %d -", aux->info, aux->nivel);
aux = aux->prox;
}


return itens;
}


ArvNo* listagemB(ArvNo* No, Lista **itens, int n, int* v){


if(n == *v){

Lista* novo = (Lista*) malloc(sizeof(Lista));
novo->info = (No!=NULL)?No->info:-1000;
//printf("\n adding: %d", novo->info);
novo->nivel = *v; novo->prox = NULL;
    if(*itens==NULL){
    *itens = novo;
    }
    else{
    Lista* aux = *itens;
        while(aux->prox!= NULL){
        aux = aux->prox;
        }
    aux->prox = novo;
    }
}

if(No == NULL){
}
else if( (No->ramoesq== NULL)&&(No->ramodir == NULL) ){

//printf("\n Sit D: passing through: %d in level %d", No->info, *v);

    if(*v+1 == n){
    int ad;
        for(ad = 0; ad<2; ad++){
        Lista* novo = (Lista*) malloc(sizeof(Lista));
        novo->info = -1000; novo->nivel = *v+1;
        novo->prox = NULL;
            if(*itens==NULL){
            *itens = novo;
            }
            else{
            Lista* aux = *itens;
                while(aux->prox!= NULL){
                aux = aux->prox;
                }
            aux->prox = novo;
            }
        }

    }
// Sob verificação
    if(*v+2 == n){
        int ad;
            for(ad = 0; ad<4; ad++){
            Lista* novo = (Lista*) malloc(sizeof(Lista));
            novo->info = -1000; novo->nivel = *v+2;
            novo->prox = NULL;
                if(*itens==NULL){
                *itens = novo;
                }
                else{
                Lista* aux = *itens;
                    while(aux->prox!= NULL){
                    aux = aux->prox;
                    }
                aux->prox = novo;
                }
            }
    }
// Sob verificação
}
else if( (No->ramoesq != NULL)&&(No->ramodir == NULL) ){
//printf("\n Sit B: passing through: %d in level %d", No->info, *v);
*v = *v+1;
No->ramoesq = listagemB(No->ramoesq,itens,n,v);

//
if(*v+1 == n){
Lista* novo = (Lista*) malloc(sizeof(Lista));
novo->info = -1000; novo->nivel = *v+1;
novo->prox = NULL;
    if(*itens==NULL){
    *itens = novo;
    }
    else{
    Lista* aux = *itens;
        while(aux->prox!= NULL){
        aux = aux->prox;
        }
    aux->prox = novo;
    }
}
//
//Sob verificação
    if(*v+2 == n){
        int ad;
            for(ad = 0; ad<2; ad++){
            Lista* novo = (Lista*) malloc(sizeof(Lista));
            novo->info = -1000; novo->nivel = *v+2;
            novo->prox = NULL;
                if(*itens==NULL){
                *itens = novo;
                }
                else{
                Lista* aux = *itens;
                    while(aux->prox!= NULL){
                    aux = aux->prox;
                    }
                aux->prox = novo;
                }
            }
    }
//Sob verificação
}
else if( (No->ramoesq == NULL)&&(No->ramodir != NULL) ){
//printf("\n Sit C: passing through: %d in level %d", No->info, *v);

//
if(*v+1 == n){
Lista* novo = (Lista*) malloc(sizeof(Lista));
novo->info = -1000; novo->nivel = *v+1;
novo->prox = NULL;
    if(*itens==NULL){
    *itens = novo;
    }
    else{
    Lista* aux = *itens;
        while(aux->prox!= NULL){
        aux = aux->prox;
        }
    aux->prox = novo;
    }
}
//
//Sob verificação
    if(*v+2 == n){
        int ad;
            for(ad = 0; ad<2; ad++){
            Lista* novo = (Lista*) malloc(sizeof(Lista));
            novo->info = -1000; novo->nivel = *v+2;
            novo->prox = NULL;
                if(*itens==NULL){
                *itens = novo;
                }
                else{
                Lista* aux = *itens;
                    while(aux->prox!= NULL){
                    aux = aux->prox;
                    }
                aux->prox = novo;
                }
            }
    }
//Sob verificação
*v = *v+1;
No->ramodir = listagemB(No->ramodir,itens,n,v);
}
else{
//printf("\n sit A: passing through: %d in level %d", No->info, *v);
*v = *v+1;
No->ramoesq = listagemB(No->ramoesq,itens,n,v);
*v = *v+1;
No->ramodir = listagemB(No->ramodir,itens,n,v);
}

*v = *v-1;
return No;
}


void impressao_especial(Arv* arvore){
Lista *aux, *itens, *aux0, *dig;
int ele, b, i, np, w, h, dim;
int hs, is, js,es = 0, ns = 0, haux, guarda; //spaces
int **spc; // spaces
altura_arvA(arvore, &h);

//spaces - function
hs = h+1; // CORRIGIR, ALTURA ESTÁ SENDO CALCULADA 1 A MENOS DO QUE DEVERIA.
haux = hs-1;

if(hs == -1){
printf("Nada a imprimir.");
return;
ns = 0;
}

/*determining the number of lines: supposing "h" is the number of vertical elements */
if(hs >= 0){ns = 1;}
if(hs>=1){ns = 3;}
if(hs>=2){
is = hs-2;
    while(is!=0){
    ns = 2*ns;is--;
    }
}


spc =  (int**) malloc(ns*sizeof(int*));
for(is = 0; is < ns; is++){
spc[is] = (int*) malloc(4*sizeof(int));
}

for(is = 1;is <= ns;is++){spc[is-1][0] = ns-is; printf("\n L: %d", spc[is-1][0]);}


for(is = 1;is <= ns;is++){
guarda = 2;
    if(is == 1){
    spc[ns-is][1] = 3;spc[ns-is][2] = 1;
    for(js=1;js< haux; js++){guarda = guarda*2;}
    spc[ns-is][3] = guarda;
    }
    else{spc[ns-is][1] =  spc[ns-is+1][1]-2;spc[ns-is][2] = spc[ns-is+1][2]+2;
        if(spc[ns-is][1] < 0){
        spc[ns-is][1] = spc[ns-is][2];haux--;
        }
    for(js=1;js< haux; js++){guarda = guarda*2;}
        if(ns==is){spc[ns-is][3] = 1;}
        else{spc[ns-is][3] = guarda;}
    }
}

// Em caso de digitos grandes

//Verificação da Matriz
//printf("\n");
//for(is = 0;is<ns;is++){
//    for(js = 0;js<4;js++){
//    printf("%d ", spc[is][js]);
//    }
//printf("\n");
//}


// função principal.
aux = aux0 = itens = listagemA(arvore);
dim = ns;


printf("\n");
for(w = 0; w< dim; w++){
printf("\n");
ele = b =  0;
aux = aux0;
    while(b < spc[w][0]){
    printf(" ");
    b++;
    }
    while(ele < spc[w][3]){

        if(aux->info!= -1000){
            if((spc[w][1] == spc[w][2])||(spc[w][0]==0)){
            printf("%d", aux->info);
            }
            else{
                if(ele%2 == 0){
                printf("/");
                }
                else{
                printf("\\");
                }
            }
        }
        else{
        printf(" ");
        }

    if(ele%2 == 0){
    i = 0;
        while(i< spc[w][1]){
        printf(" ");
        i++;
        }
    }
    else{
    np = 0;
        while(np<spc[w][2]){
        printf(" ");
        np++;
        }
    }
    ele++;
        if((aux->prox!= NULL)&&(aux->nivel == aux->prox->nivel)){
        aux=aux->prox;
        }
    }
    if((spc[w][1] == spc[w][2])&&((w+1< dim)&&(spc[w+1][1] != spc[w+1][2]) ) ){
    aux = aux->prox; aux0 = aux;}

}


}


/*Função de Deleção*/

Arv* avl_delA(Arv* arvore, int item){
printf("\n Delecao aplicada");

arvore->raiz = avl_delB(arvore->raiz, item);

return arvore;
}

ArvNo* avl_delB(ArvNo* No, int item){

if(No == NULL){
printf(" O elemento nao consta na arvore");
return NULL;
}
else if(No->info> item){
No->ramoesq = avl_delB(No->ramoesq,item);
}
else if(No->info< item){
No->ramodir = avl_delB(No->ramodir,item);
}
else{
    if( (No->ramoesq == NULL)&&(No->ramodir == NULL) ){
    free(No);
    No = NULL;
    }
    else if(No->ramoesq == NULL){
    ArvNo* guarda = No;
    No = No->ramodir;
    free(guarda);
    }
    else if(No->ramodir == NULL){
    ArvNo* guarda = No;
    No = No->ramoesq;
    free(guarda);
    }
    else{
    ArvNo* guarda = No->ramoesq;
        while(guarda->ramodir != NULL){
        guarda = guarda->ramodir;
        }
    No->info = guarda->info;
    guarda->info = item;
    No->ramoesq = avl_delB(No->ramoesq, item);
    }
}

if(No!= NULL){
No->bf = weight(No);
    if( (No->bf<-1)||(No->bf>1) ){
    printf("\n Acao de balanceamento. No: %d.", No->info);
    No = balanceia(No);
    }
}

return No;
}







