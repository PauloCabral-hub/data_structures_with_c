#include<stdio.h>
#include<stdlib.h>

typedef struct pilhano PilhaNo;
typedef struct pilha Pilha;
typedef struct filano FilaNo;
typedef struct fila Fila;

struct pilhano{
  char info;
  PilhaNo* prox;
};

struct pilha{
PilhaNo* topo;
};

struct fila{
FilaNo* ini;
FilaNo* fim;
};

struct filano{
int info;
FilaNo* prox;
};


// Functions prototypes
Pilha* cria_pilha(void);
Pilha* empilha(char element, Pilha *p);
Pilha* desempilha(char* poped, Pilha* p);
void imprime_pilha(Pilha* p);

Fila* cria_fila(void);
void insere_fila(int n, Fila* f);
char fila_sai(Fila* f);
void imprime_fila(Fila* f);

void checking_ppf(Pilha* signs, Pilha* numbers, Fila* fexp){
printf("\n stack - operators\n");
imprime_pilha(signs);
printf("\n stack - numbers\n");
imprime_pilha(numbers);
printf("\n line - final expression \n");imprime_fila(fexp);
}
