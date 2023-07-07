#include <stdio.h>
#include <stdlib.h>

typedef struct arvno ArvNo;
typedef struct arv Arv;

/*Basic Functions*/
Arv* cria_raiz(ArvNo* novo_no);
ArvNo* cria_no(int info, ArvNo* esq, ArvNo* dir);
ArvNo* buscaAle(Arv* arvore, int elemento);
ArvNo* buscaAle_no(ArvNo* no, int elemento);
void imprime_arvore(Arv* arvore);
void imprime_no(ArvNo* No);

/*Height calculation */
void altura_arvA(Arv* arvore, int* altura);
int altura_arvB(ArvNo* nos);
int compara(int e, int d);

/*Search functions*/
ArvNo* buscaAle(Arv* arvore, int elemento);
ArvNo* buscaAle_no(ArvNo* no, int elemento);
int busca_rapidaA(Arv* arvore, ArvNo** recebe, int item);
int busca_rapidaB(ArvNo* no_raiz,ArvNo** recebe, int item);

/*Insertion and deletion - Simple Binary tree*/
Arv* insere_noA(Arv* arvore, int item);
void insere_noB(ArvNo* no_atual, int item);
Arv* removeA(Arv* arvore, int item);
ArvNo* removeB(ArvNo* no, int item);

/*Structures*/
struct arvno {
 int info, bf;
 ArvNo* ramodir;
 ArvNo* ramoesq;
};

struct arv{
ArvNo* raiz;

};

/*Basic Functions*/
/*Initializing a tree*/
Arv* cria_raiz(ArvNo* novo_no){
Arv* nova_raiz = (Arv*) malloc(sizeof(Arv));
nova_raiz->raiz = novo_no;

return nova_raiz;
}

ArvNo* cria_no(int info, ArvNo* esq, ArvNo* dir){
ArvNo* novo_no = (ArvNo*) malloc(sizeof (ArvNo));
novo_no->info = info; novo_no->bf = 0;
novo_no->ramoesq = esq;
novo_no->bf = (esq != NULL)?novo_no->bf--:novo_no->bf;
novo_no->ramodir = dir;
novo_no->bf = (dir != NULL)?novo_no->bf++:novo_no->bf;

return novo_no;
}

/* Printing a tree*/
void imprime_arvore(Arv* arvore){

if(arvore->raiz == NULL){
return;
}
imprime_no(arvore->raiz);
}

void imprime_no(ArvNo* No){
    printf("<_");
    if(No!= NULL){
        if(No->ramoesq!=NULL){imprime_no(No->ramoesq);
        }
        printf("%d",No->info);
        if(No->ramodir!=NULL){imprime_no(No->ramodir);
        }
    }
    printf("_>");
return;

};

/*Freeing a tree*/
void libera_arv(Arv* arvore){

if(arvore->raiz != NULL){
libera_no(arvore->raiz);
}

return;
}

void libera_no(ArvNo* no){

if(no!=NULL){
    if(no->ramoesq != NULL){
    libera_no(no->ramoesq);
    }
    if(no->ramodir != NULL){
    libera_no(no->ramodir);
    }
    free(no);
}

return;
}

/* Basic search */
ArvNo* buscaAle(Arv* arvore, int elemento){
ArvNo* item = NULL;

if(arvore->raiz != NULL){
item = buscaAle_no(arvore->raiz, elemento);
}

return item;
}

ArvNo* buscaAle_no(ArvNo* no, int elemento){
ArvNo* item = NULL;

if(no != NULL){
item = (no->info == elemento)?(no):(NULL);
    if(item != NULL){
    item = buscaAle_no(no->ramoesq, elemento);
    }
    if(item != NULL){
    item = buscaAle_no(no->ramodir, elemento);
    }int buscaB(ArvNo* no_raiz,ArvNo* recebe, int item);
}

return item;
}

/*Height functions*/
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

/* More interesting operations */

/*The function below performs a search in the binary tree. The variable "recebe" keeps the pointer to the desired element,
the variable "item" contains the value of the information of interest. The variable "arvore" contains the pointer to the tree. "result" is 1
for the case in which the element is found and zero otherwise.*/

int busca_rapidaB(ArvNo* no_raiz,ArvNo** recebe, int item){
int result;
ArvNo* holder = no_raiz;

/*boundary condition*/
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

int busca_rapidaA(Arv* arvore, ArvNo** recebe, int item){
int result;

result = busca_rapidaB(arvore->raiz, recebe, item);

return result;
}

/*Insertion operation - not avl*/

Arv* insere_noA(Arv* arvore, int item){
if(arvore->raiz == NULL){
arvore->raiz = cria_no(item, NULL, NULL);
return arvore;
}
else{
insere_noB(arvore->raiz, item);
}
return arvore;
}

void insere_noB(ArvNo* no_atual, int item){

if(no_atual->info == item){
printf("\n O item ja esta presente na arvore. \n");
}
else if(no_atual->info < item){
    if(no_atual->ramodir == NULL){
    no_atual->ramodir = cria_no(item, NULL,NULL);
    }
    else{
    insere_noB(no_atual->ramoesq, item);
    }
}
else if(no_atual->info > item){
    if(no_atual->ramoesq == NULL){
    no_atual->ramoesq = cria_no(item, NULL,NULL);
    }
    else{
    insere_noB(no_atual->ramoesq, item);
    }
}

}

/*Deletion -  not AVL*/
Arv* removeA(Arv* arvore,int item){
ArvNo* recebe;

recebe = removeB(arvore->raiz, item);
arvore->raiz = recebe;

return arvore;
}

ArvNo* removeB(ArvNo* no, int item){

if(no == NULL){
return NULL;
}
else if(no->info > item){
no->ramoesq = removeB(no->ramoesq, item);
}
else if(no->info < item){
no->ramodir = removeB(no->ramodir, item);
}
else{

/*case of node without offspring*/
if( (no->ramodir == NULL)&&(no->ramoesq == NULL) ){
free(no);
return NULL;
}
else if (no->ramodir == NULL){
ArvNo* holder = no;
no = no->ramoesq; free(holder);
}
else if (no->ramoesq == NULL){
ArvNo* holder = no;
no = no->ramodir; free(holder);
}

else{
ArvNo* holder = no->ramoesq;
    while(holder->ramodir != NULL){
    holder= holder->ramodir;
    }
no->info = holder->info;
holder->info = item;
no->ramoesq = removeB(no->ramoesq, item);
}

}
return no;
}

/*Recalculation of the balancing factor*/

int weight(ArvNo* no_atual){
int weight;

weight = altura_arvB(no_atual->ramodir)- altura_arvB(no_atual->ramoesq);

return weight;
}



/* Insertion AVL */

Arv* avl_inA(Arv* arvore, item){
int* ap_rot =  (int*) malloc(sizeof(int)); /* the following pointer decides if there is a rotation to be applied*/
*ap_rot = 0;

if(arvore->raiz == NULL){
arvore->raiz = cria_no(item, NULL, NULL);
arvore->raiz->bf=0;
return arvore;
}
else{
insere_noB(arvore->raiz, item, &ap_rot);
}
return arvore;

}

void avl_inB(ArvNo* no_atual, int item, int* ap_rot){

if(no_atual->info == item){
printf("\n O item ja esta presente na arvore. \n");
}
else if(no_atual->info < item){
    if(no_atual->ramodir == NULL){
    no_atual->ramodir = cria_no(item, NULL,NULL);
    no_atual->ramodir->bf = 0;

    }
    else{
    insere_noB(no_atual->ramoesq, item);

    /*Evaluating if it is a case of ration*/
    if(*ap_rot != 0){
    rotaciona(no_atual, *ap_rot);
    }
    /* */

    no_atual->bf = weight(no_atual);

    /* Evaluating if the tree is unbalanced*/
    // case of ++,+
    *ap_rot = (no_atual->bf == 2 && no_atual->ramodir->br == 1)?1:*ap_rot;
    // case of --,-
    *ap_rot = (no_atual->bf == -2 && no_atual->ramodir->br == -1)?2:*ap_rot;
    // case of ++,-
    *ap_rot = (no_atual->bf == 2 && no_atual->ramodir->br == -1)?1:*ap_rot;
    // case of --,+
    *ap_rot = (no_atual->bf == -2 && no_atual->ramodir->br == 1)?1:*ap_rot;
    /* */

    }
}
else if(no_atual->info > item){
    if(no_atual->ramoesq == NULL){
    no_atual->ramoesq = cria_no(item, NULL,NULL);
    no_atual->ramodir->bf = 0;
    }
    else{
    int doue = 0; /*means we need to go left*/
    insere_noB(no_atual->ramoesq, item);

    /*Evaluating if it is a case of ration*/
    if(*ap_rot != 0){
    rotaciona(no_atual, *ap_rot);
    }
    /* */

    no_atual->bf = weight(no_atual);

    /* Evaluating if the tree is unbalanced*/
    /*case ++,+*/
    *ap_rot = (no_atual->bf == 2 && no_atual->ramodir->br == 1)?1:*ap_rot;
    // case of --,-
    *ap_rot = (no_atual->bf == -2 && no_atual->ramodir->br == -1)?2:*ap_rot;
    // case of ++,-
    *ap_rot = (no_atual->bf == 2 && no_atual->ramodir->br == -1)?1:*ap_rot;
    // case of --,+
    *ap_rot = (no_atual->bf == -2 && no_atual->ramodir->br == 1)?1:*ap_rot;
    /* */

    }
}

}

void rotaciona(ArvNo* no_atual, int sit, int doue){
/*case ++,+*/
if(sit == 1){
    if(doue == 0){
    ArvNo* holder = no_atual->ramoesq->ramodir;
    no_atual->ramoesq->ramodir = holder->ramoesq;
    holder->ramoesq = no_atual->ramoesq;
    no_atual->ramoesq = holder;
    }
    else{
    ArvNo* holder = no_atual->ramodir->ramodir;
    no_atual->ramodir->ramodir = holder->ramoesq;
    holder->ramoesq = no_atual->ramodir;
    no_atual->ramodir = holder;
    }
    if(sit == 2){
        if(doue == 0){
        ArvNo* holder = no_atual->ramodir->ramoesq;
        no_atual->ramodir->ramoesq = holder->ramodir;
        holder->ramodir = no_atual->ramodir;
        no_atual->ramodir = holder;
        }
        else{
        ArvNo* holder = no_atual->ramoesq->ramoesq;
        no_atual->ramoesq->ramoesq = holder->ramodir;
        holder->ramodir = no_atual->ramoesq;
        no_atual->ramoesq = holder;
        }
    }
}
//working
}

//working1





