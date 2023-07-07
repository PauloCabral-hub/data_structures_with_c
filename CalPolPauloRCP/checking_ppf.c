#include<stdio.h>
#include<stdlib.h>

typedef struct pilhano PilhaNo;
typedef struct pilha Pilha;
typedef struct filano FilaNo;
typedef struct fila Fila;

struct pilhano{
  char info[50];
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
char info[50];
FilaNo* prox;
};


/* Prototipos de funções*/
Pilha* cria_pilha(void);
Pilha* empilha(char element[50], Pilha *p);
Pilha* desempilha(char* poped[50], Pilha* p);
void imprime_pilha(Pilha* p);

Fila* cria_fila(void);
Fila* insere_fila(char n[50], Fila* f);
Fila* fila_sai(char* popped[50], Fila* f);
void imprime_fila(Fila* f);

void checking_ppf(Pilha* signs, Pilha* numbers, Fila* fexp){
printf("\n Pilha de Operadores \n");
imprime_pilha(signs);
printf(" Pilha de Numeros");
imprime_pilha(numbers);
printf("\n Linha contendo a expressao \n");imprime_fila(fexp);
}

