#include <stdio.h>
#include <stdlib.h>

typedef struct arvno ArvNo;
typedef struct arv Arv;
typedef struct lista Lista;

/*Estruturas*/
struct arvno {
 int info, bf;
 ArvNo* ramodir;
 ArvNo* ramoesq;
};

struct arv{
ArvNo* raiz;

};


struct lista{
int info, nivel;

Lista* prox;
};
