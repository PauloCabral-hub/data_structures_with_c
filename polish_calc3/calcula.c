#include <stdio.h>
#include <stdlib.h>
#include<math.h>

/*last update: 04/05/2017*/

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


// Functions prototypes
Pilha* cria_pilha(void);
Pilha* empilha(char element[50], Pilha *p);
Pilha* desempilha(char* poped[50], Pilha* p);
void imprime_pilha(Pilha* p);

Fila* cria_fila(void);
Fila* insere_fila(char n[50], Fila* f);
Fila* fila_sai(char* popped[50], Fila* f);
void imprime_fila(Fila* f);

double to_float(char wnum[50]);

double calcula(Fila* fexp){
int i, f;
char out[50], hold1[50], hold2[50], hold3[50], hold4[50];
double a, b, result;

Pilha *numbers = cria_pilha();
Pilha *signs = cria_pilha();

while(fexp->ini != NULL){
fexp = fila_sai(out,fexp);
printf("\n reading %s \n", out);

    // case of lined number
    if(((int)out[0]<58)&&((int)out[0]>47)){
    numbers = empilha(out,numbers);
    }

    //case of operators of operators
    if((((out[0]== '-')||(out[0]== '+'))||(out[0]== '*'))||(out[0]== '/')){
            numbers = desempilha(hold1, numbers); a = to_float(hold1);
            //working line 72
            if(numbers->topo == NULL){
                printf(" Case B1 ");
                if(out[0]== '-'){
                printf(" Case B11 ");
                result = a*(-1);
                f = snprintf(hold4,50,"%f",result);
                }
                else{
                    printf(" Case B12 ");
                    result = a;
                    f = snprintf(hold4,50,"%f",result);
                }
            }
            else{
            numbers = desempilha(hold2, numbers); b = to_float(hold2);
            printf(" Case B2 ");
                if(out[0]== '-'){result = b-a;}
                if(out[0]== '+'){result = b+a;}
                if(out[0]== '*'){result = b*a;}
                if(out[0]== '/'){result = b*a;}
            f = snprintf(hold4,50, "%f", result);
            }
            numbers = empilha(hold4,numbers);
    }

    //case of sqrt
    if(out[0] == 's'){
    //printf("Case C");
    numbers = desempilha(hold1,numbers);a = to_float(hold1);
    a = sqrt(a);
    f = snprintf(hold4,50, "%f", a);
    numbers = empilha(hold4, numbers);
    }
checking_ppf(signs,numbers,fexp);
}

numbers = desempilha(hold4,numbers);

result = to_float(hold4);

printf("RESULT: %f", result);

return result;
}







