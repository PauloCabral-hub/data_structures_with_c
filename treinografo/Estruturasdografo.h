#include<stdio.h>
#include<stdlib.h>

typedef struct vert Vert;
typedef struct adj Adj;
typedef struct lista Lista;

struct vert{
int valor;
char nome;

Vert* prox; /* aponta para o próximo vertice*/
Adj* adj; /* aponta para o primeiro elemento da vizinhança*/

};

struct adj{
int custo;

Vert* viz; /* aponta para o vizinho */
Adj* adj; /* aponta para os outros elementos da vizinhança*/

};

struct lista{

char nome;
Vert* vert;
Lista* prox;
};

/*Protótipo das funções*/
Vert* incluir_vertice(char nome, int valor, Vert* grafo);
Vert* busca_vertice(char nome, Vert* grafo);
void inclui_aresta(char nomeA, char nomeB, int custo, Vert* grafo);
int excluir_aresta(char nomeA, char nomeB, Vert* grafo);
Vert* excluir_vertice(char nome, Vert* grafo);
Lista* insere_lista(Lista* itens, char nome, Vert* vert);
int busca_lista(Lista* itens, char nome);

Vert* incluir_vertice(char nome, int valor, Vert* grafo){
Vert* aux = grafo;

while(aux!= NULL){
    if(aux->nome == nome){
    printf("\n O elemento já consta no grafo.");
    return grafo;
    }
aux = aux->prox;
}


Vert* novo = (Vert*) malloc(sizeof(Vert));
if(novo == NULL){
printf("\n Memoria insuficiente\n");
return 0;
}
novo->valor = valor;
novo->nome = nome;
novo->adj = NULL;

novo->prox = grafo;

aux = novo;
printf("\nElementos do grafo: ");
while(aux!= NULL){
printf("%c valor %d,", aux->nome, aux->valor);
aux = aux->prox;
}


return novo;
}

/*A função abaixo retorna o ponteiro para o vertice se o mesmo existe, e Nulo caso contrario */
Vert* busca_vertice(char nome, Vert* grafo){
Vert* aux;

aux = grafo;

while(aux!= NULL){
    if(aux->nome == nome){
    printf("\nVertice encontrado.");
    break;
    }
aux= aux->prox;
}

return aux;
}

void inclui_aresta(char nomeA, char nomeB, int custo, Vert* grafo){
Vert *VA,*VB;
Adj *arA,*arB;
Vert* aux; Adj* auxar; /*Para verificação */


VA = busca_vertice(nomeA,grafo);
VB = busca_vertice(nomeB,grafo);

if((VA ==  NULL)||(VB == NULL)){
printf("\n Ao menos um dos elementos nao e parte do grafo. \n");
return;
}

arA = (Adj*) malloc(sizeof(Adj));
arB = (Adj*) malloc(sizeof(Adj));

arA->custo= custo;
arA->viz = VB;
arA->adj = VA->adj;
VA->adj = arA;

arB->custo= custo;
arB->viz = VA;
arB->adj = VB->adj;
VB->adj = arB;




aux = grafo;
printf("\n");
while(aux!= NULL){
printf("|%c|->",aux->nome);auxar = aux->adj;
    while(auxar!= NULL){
    printf("%c (%d)->", auxar->viz->nome, auxar->custo);
    auxar = auxar->adj;
    }
printf("\n");
aux = aux->prox;
}


return;
}

int excluir_aresta(char nomeA, char nomeB, Vert* grafo){
Vert *VA, *VB;
Adj *auxar, *auxar0;

Vert* aux;

VA = busca_vertice(nomeA, grafo);
VB = busca_vertice(nomeB, grafo);

if((VA == NULL)||(VB == NULL)){
printf("\n Ao menos um dos elementos nao pertence ao grafo.  \n");
return 0;
}

/* Procedimento para o primeiro elemento */
auxar = VA->adj;auxar0 = NULL;
while((auxar!= NULL)&&(auxar->viz->nome != VB->nome)){
auxar0 = auxar; auxar=auxar->adj;
}

if(auxar == NULL){
printf("\n %c e %b nao sao vizinhos.", VA->nome, VB->nome);
return 0;
}

/*Deleção em lista ligada*/
if(auxar == VA->adj){
Adj* guarda;
guarda = auxar->adj;
VA->adj = guarda;
free(auxar);
}

/*Deleção do último elemento*/

if((auxar0!= NULL)&&(auxar->adj == NULL)){
free(auxar);
auxar0->adj = NULL;
}

/*Deleção de elemento no meio*/
if((auxar0!= NULL)&&(auxar->adj != NULL)){
auxar0->adj = auxar->adj;
free(aux);
}

/*Procedimento para o elemento B */

auxar = VB->adj;auxar0=NULL;
while((auxar!= NULL)&&(auxar->viz->nome != VA->nome)){
auxar0 = auxar; auxar=auxar->adj;
}

if(aux == NULL){
printf("\n %c e %b nao sao vizinhos.", VA->nome, VB->nome);
return 0;
}

/*Deleção em lista ligada*/

/*Deleção em lista ligada*/
if(auxar == VB->adj){
Adj* guarda;
guarda = auxar->adj;
VB->adj = guarda;
free(auxar);
}

/*Deleção do último elemento*/
if((auxar0!= NULL)&&(auxar->adj == NULL)){
free(auxar);
auxar0->adj == NULL;
}

/*Deleção de elemento no meio*/
if((auxar0!= NULL)&&(auxar->adj != NULL)){
auxar0->adj = auxar->adj;
free(aux);
}


aux = grafo;
printf("\n");
while(aux!= NULL){
printf("|%c|->",aux->nome);auxar = aux->adj;
    while(auxar!= NULL){
    printf("%c (%d)->", auxar->viz->nome, auxar->custo);
    auxar = auxar->adj;
    }
printf("\n");
aux = aux->prox;
}



return 1;
}






Vert* excluir_vertice(char nome, Vert* grafo){
Vert *aux0, *aux = grafo;
Adj* auxar; /*para verificação*/

aux0=NULL;
while( (aux!= NULL)&& (aux->nome != nome)){
aux0 =aux; aux=aux->prox;
}

if(aux==NULL){
printf("\n O elemento %c nao pertence ao grafo.\n", nome);
return grafo;
}

/*Caso do primeiro elemento */
if(aux->nome == grafo->nome){
Vert* guarda;
guarda = grafo->prox;
free(grafo);
grafo = guarda;
}

/*Caso do último elemento */
if((aux0!= NULL)&&(aux->prox == NULL)){
free(aux);
aux0->prox = NULL;
}

/*Caso do elemento do meio */
if((aux0!= NULL)&&(aux->prox != NULL)){
aux0->prox = aux->prox;
free(aux);
}

/* Verificação */

aux = grafo;
printf("\n");
while(aux!= NULL){
printf("|%c|->",aux->nome);auxar = aux->adj;
    while(auxar!= NULL){
    printf("%c (%d)->", auxar->viz->nome, auxar->custo);
    auxar = auxar->adj;
    }
printf("\n");
aux = aux->prox;
}


return grafo;
}


/*Função cria insere elementos numa lista. O retorno é a propria lista. */

Lista* insere_lista(Lista* itens, char nome, Vert* vert){
Lista* auxb;
auxb = itens;

while(auxb!= NULL){
    if(auxb->nome == nome){
    break;
    printf("\n O elemento ja consta na lista."); return NULL;
    }
auxb = auxb->prox;
}

Lista* novo = (Lista*) malloc(sizeof(Lista));
novo->nome = nome;novo->vert = vert; novo->prox = NULL;
novo->prox = itens;


auxb = novo;
printf("\n Situacao da Lista:");
while(auxb!=NULL){
printf("%c, ", auxb->nome);
auxb = auxb->prox;
}
printf("\n");

return novo;
}

//LEMBRAR DE CRIAR FUNÇÕES PARA LIBERAR O ESPAÇO DA MEMÓRIA.
int busca_lista(Lista* itens, char nome){
Lista* auxb;
auxb = itens;

while(auxb!= NULL){
    if(auxb->nome ==  nome){
    printf("\nElemento encontrado.");
    return 1;
    }
auxb =  auxb->prox;
}

printf("\nElemento nao encontrado.");
return 0;
}




void busca_gulosa(Vert* grafo, char nome){
Vert* auxb, auxin;
Adj* auxmin, guardamin = NULL;
Lista *itens = NULL, *auxg;
int i, j;

auxb = grafo;
if(aux == NULL){printf("\n Grafo vazio."); return;}

while( (auxb->prox!= NULL)&&(auxb->nome != nome) ){
auxb=  auxb->prox;
}

if(auxb == NULL){
printf("\n Elemento nao consta no grafo.")
return;
}

// Elemento encontrado

if(auxb->adj == NULL){
printf("\n Grafo desconectado. Resultado da busca: %c", auxb->nome);
return;
}
else{
auxmin = auxb->adj
itens = insere_lista(itens, auxb->nome, auxb); auxg = auxb;
}

// busca entre os adjascentes do primeiro elemento;


while(1){
    if((guardamin == NULL)||(auxmin->custo < guardamin->custo)){
        if(!busca_lista(visitados, auxmin->viz->nome, &auxin)){
        guardamin = auxmin;
        }
    }
    if(auxmin->adj != Null){
    auxmin= auxmin->adj;
    }
    else{
    break;
    }
}

itens = insere_lista(itens, guardamin->viz->nome, guadamin->viz);
printf("\n Ordem de visitação: %c", guardamin->viz->nome);
guardamin = NULL;

do{
auxg = itens;
guardamin = NULL;
    while(auxg!= NULL){
    //
    auxmin = auxg->vert->adj;
        while(1){
            if((guardamin == NULL)||(auxmin->custo < guardamin->custo)){
                if(!busca_lista(visitados, auxmin->viz->nome, &auxin)){
                guardamin = auxmin;
                }
            }
            if(auxmin->adj!= NULL){
            auxmin= auxmin->adj;
            }
            else{
            break;
            }
        }
    auxg = auxg->prox;
    //
    }
    if(guardamin!=NULL){
    itens = insere_lista(itens,guardamin->viz->nome,guardamin->viz);
    printf(", %c", guardamin->viz->nome);
    }

}while(guardamin!= NULL);

//Comparar tamanho da lista com o do grafo;
auxg = itens;i = 0;
while(auxg!= NULL){
i++;
auxg = auxg->prox;
}
auxb = grafo;j = 0;
while(auxb!= NULL){
j++;
auxb = auxb->prox;
}
if(i == j){
printf("Grafo conexo.");
}
else{
printf("Grafo desconexo");
}


}


























