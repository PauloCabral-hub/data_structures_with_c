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




int incluir(char nome, int valor, Vert** primeiro){
Vert* presente;



presente = busca_vert(nome);
if(presente == NULL){
return 0; /* retorna zero se o elemento já estiver present*/
}

Vert* novo = (Vert*) malloc(sizeof(Vert));
if(novo == NULL){
printf("\n Memoria insuficiente\n");
return 0;
}
novo->valor=valor;
novo->nome = nome;
novo->adj = NULL;
/* */
novo->prox = *primeiro->prox;
*primeiro->prox = novo;

return 1;
}


Vert* busca_vert(char nome, Vert* primeiro){
Vert* aux;

aux = primeiro;

while((aux!=NULL)&&(aux->nome!=nome)){
aux= aux->prox;
}
return (aux->nome == nome)? aux:NULL;
}


void inclui_aresta(char nomeA, char nomeB, int custo, Vert** primeiro){
Vert *A,*B;
Adj *v1,*v2;

A = busca_vert(nomeA,*primeiro);
B = busca_vert(nomeB,*primeiro);
if((!A)||(!B)){
printf("\n Ao menos um dos elementos nao e parte do grafo. \n")
return;
}
v1 = (Adj*) malloc(sizeof(Adj));
v2 = (Adj*) malloc(sizeof(Adj));

v1->custo= custo;
v1->viz = B;
v1->adj = A->adj;
A->adj = v1;

v1->custo= custo;
v1->viz = A;
v1->adj = B->adj;
B->adj = v1;

return;
}

int excluir_aresta(char nomeA, char nomeB, Vert** primeiro){
Vert *A, *B;
Adj *aux, *aux0;

A = busca_vert(nomeA,*primeiro);
B = busca_vert(nomeB,*primeiro);

if((!A)||(!B)){
printf("\n Ao menos um dos elementos nao pertence ao grafo.  \n");
return 0;
}
/* Procedimento para o primeiro elemento */
aux = A->adj;aux0 = NULL;
while((aux!= NULL)&&(aux->viz != B)){
aux0 = aux; aux=aux->prox;
}
if(aux == NULL){
printf("Os elementos nao sao vizinhos");
return 0;
}

/*Deleção em lista ligada*/
if(aux == A->adj){
Adj* salva;
salva = aux->adj;
A->adj = salva;
free(aux);
}
/*Deleção do segundo do último elemento*/
if((aux0!= NULL)&&(aux->adj == NULL)){
free(aux);
aux0->adj == NULL;
}
/*Deleção de elemento no meio*/
if((aux0!= NULL)&&(aux->adj != NULL)){
aux0->adj = aux->adj;
free(aux);
}

/*Procedimento para o segundo elemento */
aux = B->adj;aux0=NULL;
while((aux!= NULL)&&(aux->viz != A)){
aux0 = aux; aux=aux->prox;
}
if(aux == NULL){
printf("Os elementos nao sao vizinhos");
return 0;
}

/*Deleção em lista ligada*/

/*Deleção em lista ligada*/
if(aux == B->adj){
Adj* salva;
salva = aux->adj;
B->adj = salva;
free(aux);
}
/*Deleção do segundo do último elemento*/
if((aux0!= NULL)&&(aux->adj == NULL)){
free(aux);
aux0->adj == NULL;
}
/*Deleção de elemento no meio*/
if((aux0!= NULL)&&(aux->adj != NULL)){
aux0->adj = aux->adj;
free(aux);
}


return 1;
}

int excluir_vert(char nome,Vert** primeiro){
Vert *aux0, *aux;

aux0=NULL;
while( (aux!= NULL)&& (aux->nome != nome)){
aux0 =aux; aux=aux->prox;
}

if(aux==NULL){
printf("\nElemento nao pertence ao grafo.\n");
return 0;
}
if(aux->nome==*primeiro->nome){
Vert* salva;
salva = *primeiro->prox;
free(*primeiro);
primeiro = &salva;
}
if((aux0!= NULL)&&(aux->prox == NULL)){
free(aux);
aux0->prox = NULL;
}
if((aux0!= NULL)&&(aux->prox != NULL)){
aux0->prox = aux->prox;
free(aux);
}

return 1;
}





void busca_gulosa(Vert* grafo, char nome){
Vert* auxb, auxin;
Adj* auxmin, guardamin = NULL;
Lista *visitados = NULL, *auxg;
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

if(itens == NULL){
return novo;
}
else{
novo->prox = itens;
}

return novo;
}


int busca_lista(Lista* itens, char nome, Vert** buscado){
Lista* auxb;
auxb = itens;

while(auxb->prox!= NULL){
    if(auxb->nome ==  nome){
    *buscado  = auxb->vert;
    return 1;
    }
auxb =  auxb->prox;
}
return 0;

}




















//Vert* gulosinho(Vert* ultimo, Lista* visitados){
//Adj *vaux, *vaux0;
//rb = 0; /*resultado da busca*/
//
//vaux = aux->adj;
//vaux0 = NULL;
//while(vaux != NULL){
//rb = busca_lista(vaux->nome, visitados);
//    if(rb == 0){
//    //
//
//        if(vaux0 == NULL){
//        vaux0 = vaux;
//        }
//        else{
//        //
//            if(vaux0->custo > vaux->custo){
//            vaux0 = vaux;
//            }
//            else if (vaux0->custo == vaux->custo){
//            vaux0 = vaux;
//            }
//        //
//        }
//    //
//    }
//    else{
//    vaux = vaux->prox;
//    }
//}
//if(vaux0!= NULL){
////visitados = insere_lista(Vaux0->nome, Vaux0->custo, visitados);
//return vaux0->viz;
//}
//else{
//return NULL;
//}
//
//}
//
//Vert* compara(Vert* A, Vert* B){
//
//}
//
//
//
//
//
//int busca_lista(char nome, Lista* visitados){
//Lista* aux = visitados;
//int result = 0;
//
//while(aux != NULL){
//    if(aux->nome == nome){
//    result = 1;
//    }
//}
//aux = aux->prox;
//
//return result;
//}
//
//Lista* insere_lista(char nome,int custo, Lista* L){
//Lista* novo =  (Lista*) malloc(sizeof(Lista));
//if(novo == NULL){
//printf("\nMemoria insuficiente\n");
//return NULL;
//}
//novo->nome= nome;
//novo->custo = custo;
//novo->prox = L;
//
//return novo;
//}
//
