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
void avl_inB(ArvNo* no_atual, int item, int* ap_rot, int* reb);

/*Funções de deleção*/
Arv* avl_outA(Arv* arvore,int item);
ArvNo* avl_outB(ArvNo* no, int item, int* stop, int* found);

/*Funções auxiliares*/
int weight(ArvNo* no_atual); /* fornece o fator de balanceamento da árvore*/
ArvNo* rotaciona(ArvNo* no_atual, int sit, int doue); /* rotaciona em caso de desbalanceamento. 'sit' indica a situação, 'doue' indica se o nó está a direita ou esquerda do nó atual*/

/*Funções de liberação da memória dinâmica*/
void libera_arv(Arv* arvore);
void libera_no(ArvNo* no);


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
int weight;

weight = altura_arvB(no_atual->ramodir)- altura_arvB(no_atual->ramoesq);

return weight;
}

/* Função rotaciona: Aplica a rotação do tipo 'sit' no nó a direita ou esquerda, conforme indicado por 'doue'*/
ArvNo* rotaciona(ArvNo* no_atual, int sit, int doue){
printf("\n Rotacao aplicada apos o no: %d \n", no_atual->info);
/*case ++,+*/
if(sit == 1){
    if(doue == 0){
    ArvNo* holder = no_atual->ramoesq->ramodir;
    no_atual->ramoesq->ramodir = holder->ramoesq;
    no_atual->ramoesq->bf = weight(no_atual->ramoesq); /*rebalancing*/
    holder->ramoesq = no_atual->ramoesq;
    holder->bf = weight(holder); /*rebalancing*/
    no_atual->ramoesq = holder;
    }
    else if(doue == 1){
    ArvNo* holder = no_atual->ramodir->ramodir;
    no_atual->ramodir->ramodir = holder->ramoesq;
    no_atual->ramodir->bf = weight(no_atual->ramodir);/*rebalancing*/
    holder->ramoesq = no_atual->ramodir;
    holder->bf = weight(holder); /*rebalancing*/
    no_atual->ramodir = holder;
    }
    else{ //funcionando
    ArvNo* holder = no_atual->ramodir;
    no_atual->ramodir = holder->ramoesq;
    no_atual->bf = weight(no_atual);
    holder->ramoesq= no_atual;
    holder->bf = weight(holder);
    no_atual = holder;
    //tratando a raiz;
    }
}

/*case --,- */
if(sit == 2){ //REVISAR TODOS OS CASOS A PARTIR DAQUI
    if(doue == 1){
    ArvNo* holder = no_atual->ramodir->ramoesq;
    no_atual->ramodir->ramoesq = holder->ramodir;
    no_atual->ramodir->bf = weight(no_atual->ramodir); /*rebalancing*/
    holder->ramodir = no_atual->ramodir;
    holder->bf=weight(holder); /*rebalancing*/
    no_atual->ramodir = holder;
    }
    else if (doue == 0){
    ArvNo* holder = no_atual->ramoesq->ramoesq;
    no_atual->ramoesq->ramoesq = holder->ramodir;
    no_atual->ramoesq->bf = weight(no_atual->ramoesq); /*rebalancing*/
    holder->ramodir = no_atual->ramoesq;
    holder->bf=weight(holder); /*rebalancing*/
    no_atual->ramoesq = holder;
    }
    else{ //funcionando
    ArvNo* holder = no_atual->ramoesq;
    no_atual->ramoesq = holder->ramodir;
    no_atual->bf = weight(no_atual);
    holder->ramodir = no_atual;
    holder->bf = weight(no_atual);
    no_atual = holder;
    }
}

/* case of ++,- */
if(sit == 3){
    if(doue==1){
    /* proceeding in the lower pivot*/
    ArvNo* saver = no_atual->ramodir->ramodir;
    ArvNo* holder = saver->ramodir->ramoesq;
    saver->ramoesq = holder->ramodir; saver->bf = weight(saver);
    holder->ramodir = saver; holder->bf = weight(holder);
    no_atual->ramodir->ramodir = holder; no_atual->ramodir->bf = weight(no_atual->ramodir); /* balancing*/
    /*proceeding in the higher pivot*/
    saver = no_atual->ramodir;
    holder = saver->ramodir;
    saver->ramodir = holder->ramoesq; saver->bf = weight(saver);
    holder->ramoesq = saver; holder->bf = weight(holder);
    no_atual->ramodir = holder;
    }
    else{
    /*proceeding in the lower pivot*/
    ArvNo* saver = no_atual->ramoesq->ramodir;
    ArvNo* holder = saver->ramoesq; saver->bf = weight(saver);
    holder->ramodir = saver; holder->bf = weight(holder);
    no_atual->ramodir->ramodir = holder; no_atual->ramodir->bf = weight(no_atual->ramodir);
    /*proceeding in the higher pivor*/
    saver = no_atual->ramoesq;
    holder = saver->ramodir;
    saver->ramodir = holder->ramoesq; saver->bf = weight(saver);
    holder->ramoesq = saver; holder->bf = weight(holder);
    no_atual->ramoesq = holder; no_atual->ramoesq->bf = weight(no_atual->ramoesq);
    }
}

if(sit == 4){
    if(doue == 0){
    /*proceeding in the lower pivot*/
    ArvNo* saver  = no_atual->ramoesq;
    ArvNo* holder = saver->ramoesq->ramodir;
    saver->ramoesq->ramodir = holder->ramoesq;
    holder->ramoesq = saver->ramodir;
    saver->ramodir = holder;
    /*proceeding in the higher pivot*/
    holder = no_atual->ramoesq->ramoesq;
    no_atual->ramoesq->ramoesq = holder->ramodir;
    holder->ramodir = no_atual->ramoesq;
    no_atual->ramoesq = holder;
    }
    else{
    /*proceeding in the lower pivot*/
    ArvNo* saver = no_atual->ramodir;
    ArvNo* holder = saver->ramoesq->ramodir;
    saver->ramoesq->ramodir = holder->ramoesq;
    holder->ramoesq = saver->ramodir;
    saver->ramodir = holder;
    /*proceeding in the higher pivot */
    holder = no_atual->ramodir->ramoesq;
    no_atual->ramodir->ramoesq = holder->ramodir;
    holder->ramodir = no_atual->ramodir;
    no_atual->ramodir = holder;
    }
}

}




/*Funções de inserção*/

Arv* avl_inA(Arv* arvore, int item){

arvore->raiz = avl_inB(arvore->raiz, item);

return arvore;
}

ArvNo* avl_inB(ArvNo* No, int item){

if(No == NULL){
ArvNo* novo = (ArvNo*) malloc(sizeof(ArvNo));
novo->bf= 0;
novo->info = item;
novo->ramodir = novo->ramoesq = NULL;
return novo;
}
else if(No->info < item){
No->ramodir = avl_inB(No->ramodir, item);
/*Verificar a altura, corrigir a altura*/
No->bf = weight(No);
}
else if(No->info > item){
No->ramoesq =  avl_inB(No->ramoesq, item);
/*Verificar a altura*/
No->bf = weight(No);
}

if( (No->bf<-1)||(No->bf>1) ){
No = balanceia(No);
}

return No;
}

ArvNo* balaceia(ArvNo* No){
int ba,bb;

if(No == NULL){
}
else if( (No->ramodir == NULL)&&(No->ramoesq != NULL) ){
No->ramoesq = balanceia(No->ramoesq);
}
else if((No->ramoesq == NULL)&&(No->ramodir != NULL)){
No->ramodir = balanceia(No->ramodir);
}
else{
ba = altura(No->ramoesq)-altura(No->ramodir);

    if(ba>1){/*desbalanceamo à esquerda*/
    bb = altura(No->ramoesq->ramodir)-altura(No->ramoesq->ramodir);
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
    bb = altura(No->ramodir->ramoesq)-altura(No->ramodir->ramodir);
        if(bb = -1){ /*Rotação Simples*/
        ArvNo* guarda1 = No->ramodir;
        No->ramodir = guarda1->ramoesq; /*Recalculando peso*/ No->bf = weight(No);
        guarda1->ramoesq = No;
        No = guarda1; /*Recalculando peso*/ No->bf =weight;
        }
        else{
        ArvNo* guarda1 = No->ramodir; ArvNo* guarda2 = guarda->ramoesq;
        guarda1->ramoesq = guarda2->ramodir; /*recalculando peso*/ guarda1->bf = weight(guarda1);
        guarda2->ramodir = guarda1; /*recalculando peso*/ guarda2->bf = weight(guarda2);
        No->ramodir = guarda2;
        /* Fim do procedimento no pivor menor */
        guarda1 = No->ramodir;
        No->ramodir = guarda1->ramoesq; /*recalculando peso*/ No->bf = weight(bf);
        guarda1->ramoesq = No; /*recalculando peso*/ guarda1->bf = weight(bf);
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


Lista* listagemA(Arv* arvore, int* h){
Lista* itens;
int n = 0, h = altura_arvB(arvore->raiz);
while(n<= h){
ArvNo* =  listagemB(arvore->raiz, &nova, &n, h);
n++;
}

return itens;
}

ArvNo* listagemB(ArvNo* no, **Lista itens, int* n, int h){

if (*n == h){
Lista* novo = (Lista*) malloc(sizeof(Lista));
novo->info = (no!= NULL)?no->info:0;
novo->nivel = h;
    if(*itens == NULL){
    *itens = novo;
    }
    else{
    Lista* aux = *itens;
        while(aux->prox!=NULL){
        aux = aux->prox;
        }
    aux->prox =  novo;
    }
}


if(no == NULL){
*n = *n-1;
}
else if( (no->ramoesq != NULL)&&(no->ramodir == NULL) ){
*n= *n+1;
no->ramoesq = listagemB(no->ramoesq, itens, n, h);
*n=*n-1;
}
else if( (no->ramodir != NULL)&&(no->ramoesq == NULL) ){
*n= *n+1;
no->ramodir = listagemB(no->ramodir, itens, n, h);
*n=*n-1;
}
else{
*n= *n+1;
no->ramoesq = listagemB(no->ramoesq, itens, n, h);
*n=*n-1;
*n= *n+1;
no->ramodir = listagemB(no->ramodir, itens, n, h);
*n=*n-1;
}

return no;
}

//Revisar

void espaces(int h, int* spcb, int dim){
int i,e = 0, n = 0, haux = h, guarda;
if(h = -1){
*spcb = NULL;
return;
}

/*determining the number of lines: supposing "h" is the number of vertical elements */
if(h >= 0){
n = 1;
}
if(h>=1){
n = 3;
}
if(h>2){
i = h-2;
    while(i!=0){
    n = 2*n;
    i--;
    }
}

int* lines =  (int*) malloc(sizeof(*int*n));
for(i = 0; i<n; i++){
lines[i] = (int*) malloc(sizeof(int*4));
}

for(i = 1;i <= n;i++){
lines[i-1][1] = n-i;
}

//the space between to numbers is 3-1 for first and 2*line-1 for 2 and forward
// the expression for the number of nodes is 2^k+1 -1;
for(i = 1;i <= n;i++){
guarda = 2;
    if(i == 1){
    lines[n-i][2] = 3;
    lines[n-i][3] = 1;
    }
    else{
    lines[n-i][2] =  lines[n-i-1][2]-1;
    lines[n-i][3] = lines[n-i-1][3]+1;
    if(lines[i-1][2] == 0){
    lines[n-i][2] = lines[n-i][3];
    haux--;
    }
    for(j=1;j<= haux; j++){
    guarda = guarda*2;
    }
    lines[n-i][4] = ((guarda*2)-1)-(guarda-1);


    }
}


}






