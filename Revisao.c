#include<stdio.h>
#include<stdlib.h>

struct lista{
int info;
struct lista *prox;
};

typedef struct lista Lista;

void imprime(Lista* l){
Lista *paux = l;
for(;paux;paux = paux->prox){
printf("\n%d", paux->info);
}
}

Lista* exclui(Lista* l, int i){
Lista *paux1, *paux2;


for (paux1 = NULL, paux2 = l; (paux2)&&(paux2->info!= i); paux1 = paux2, paux2 = paux2->prox);

if(paux2->info == i){
    if(paux1 == NULL){
    l = paux2->prox;
    }
    else
    {
    paux1->prox = paux2->prox;
    }
}
free(paux2);
return l;
}

Lista *insere(Lista* l, int i){  /*Insere o elemento na lista na ordem devida*/
Lista *paux1, *paux2;
Lista *novo = (Lista*) malloc(sizeof(Lista));
for(paux1 = NULL, paux2 = l;(paux2)&&(paux2->info < i);paux1 = paux2, paux2 = paux2->prox);

if (paux1 == NULL){
    novo->info = i;
    novo->prox = paux2;
    return novo;
}
else if (paux2 == NULL){
    novo->info = i;
    novo-> prox = paux2;
    return novo;
}
else
{
 novo->info = i;
 paux1->prox = novo;
 novo->prox = paux2;
 return l;
}

}

Lista* insere2(Lista* l,int i){
Lista *paux;
Lista *novo = (Lista*) malloc(sizeof(Lista));
novo-> info = i;
novo->prox = l;
return novo;
}

void ordem(Lista* l){
Lista *paux1, *paux2;
if (l==0){

}
else{
    for(paux1 = l, paux2 = paux1->prox; (paux2)&&(paux2->info >= paux1->info);paux1 = paux1->prox,paux2 = paux2->prox);
    if(paux2 == NULL){
    printf("It's organized.");
    }
    else{
    printf("It's not organized.");
    }
}
}

Lista* inverte(Lista** l){
Lista *aux, *aux2, *aux3 = NULL;
if (*l == NULL){
return *l;
}
else{
    while(*l!= NULL){
    aux = *l;
    aux2 = aux->prox;
    aux->prox = aux3;
        if(aux2 == NULL){/*para lista com número impar de elementos*/
        break;
        }
        else{ /*para lista com número par de elementos*/
        *l = aux2->prox;
        aux2->prox = aux;
        aux3 = aux2;
        }
    }
if(aux2 == NULL){ /*para lista com número impar de elementos*/
return aux;
}
else{ /*para lista com número par de elementos*/
return aux2;
}
}
}
;

Lista* ordena(Lista** l){
Lista *aux, *aux2, *aux3, *aux0;
int i, n, j = 0;

for(;*l!=NULL;j++){
aux = *l; aux2 = aux->prox;
    if(aux2->prox!=0){
    aux3 = aux2->prox;
    }
    else{
    aux3 == 0;
    }

    for(i = 0;(i!=n)&&(aux2!=0);i++){
        if((aux->info>aux2->info)&&(i == 0)){ /*alteração no início*/
        printf("\n case: begin \n");
        *l = aux2;
            if(aux3 == 0){
            aux2->prox = aux;
            aux->prox = 0;
            break;
            }
            else{
            aux2->prox = aux;
            aux->prox = aux3;
            aux0=aux2;
            aux2 = aux->prox;
                    if(aux2->prox!=0){
                    aux3 = aux2->prox;
                    }
                    else{
                    aux3 = 0;
                    }
            }
         printf("\nLista: %d %d %d %d\n", aux0->info, aux->info, aux2->info, aux3->info);
         imprime(*l);
         printf("Deseja continuar: ");
         scanf("%d", &n);
         if(n==0){break;}
    }
    else if((aux->info<=aux2->info)&&(aux2!=0)){ /*passagem*/
    printf("\n case: pass \n");
    aux0 = aux;
    aux = aux2;
        if(aux3!=0){
        aux2 = aux3;
        }
        else{break;}
        if(aux3->prox!=0){
        aux3 = aux3->prox;
        }
    }
    else if((aux->info>aux2->info)&&(aux3!=0)&&(i>0)){ /*alteração no meio*/
        printf("\n case: middle \n");
        aux2->prox=aux;
        aux->prox=aux3;
        aux0->prox=aux2;
        aux0= aux2; aux2=aux->prox;
            if(aux2->prox != NULL){
            aux3=aux2->prox;
            }
            else{
            aux3 == NULL;
            }
     printf("\nLista:\n");
     imprime(*l);
     printf("\n Deseja continuar: ");
     scanf("%d", &n);
     if(n==0){break;}
    }
    else if((aux->info > aux2->info)&&(aux2->prox == NULL)){ /*alteração no fim*/
        printf("\n case: end \n");
        aux2->prox=aux;
        aux->prox=NULL;
        aux0->prox= aux2;
        aux0 = aux2; aux2 = NULL; aux3 == NULL; break;
    }
    else{
        printf("\n case: none \n");
            break;
    }
    }
     if(n==0){break;}

}


return *l;
}




int main(void){
Lista *alunos = NULL;

alunos = insere2(alunos,5);
alunos = insere2(alunos,4);
alunos = insere2(alunos,3);
alunos = insere2(alunos,2);
alunos = insere2(alunos,1);
ordem(alunos);
imprime(alunos);
alunos = inverte(&alunos);
printf("\nand then: \n");
imprime(alunos);
alunos = ordena(&alunos);
printf("\nand then: \n");
imprime(alunos);
return 0;
}

