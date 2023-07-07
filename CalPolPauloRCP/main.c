#include <stdio.h>
#include <stdlib.h>

//Definição das estruturas de Pilha e Fila
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


// Protótipos das funções utilizadas.
Pilha* cria_pilha(void);
Pilha* empilha(char element[50], Pilha *p);
Pilha* desempilha(char* poped[50], Pilha* p);
void imprime_pilha(Pilha* p);

Fila* cria_fila(void);
Fila* insere_fila(char n[50], Fila* f);
Fila* fila_sai(char* popped[50], Fila* f);
void imprime_fila(Fila* f);



int main(void){

/*Números na tabela ASCII - 48-57 ASCII;*/
/*Operadores e marcadores decimais - 40 - 47*/

Fila* stPolonesa;
char sExp[256];
float fResultado;


printf("Calculadora - Digite a expressao parentizada:");
gets(sExp); /* captura a string digitada e imprime em no vetor especificado.*/

parser(sExp,&stPolonesa);
printf("__________________________________________________________");
calcula(stPolonesa);


return 0;
}


