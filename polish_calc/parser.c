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




//Probably will be necessary changes in the stack functions to always return the pointer to the structure;

parser(char sExp[256], Fila* stpolonesa){
char out, read;
int i, j, t=0, w = 0; int sit1=0, sit2=0, sit3=0, sit4=0, sit5 = 0, sit6 = 0, case1, case2, case3, case4, case5, caselast;
char pre[] = "(-+*/^)", psave = ')';

Pilha* signs = cria_pilha(); Pilha* numbers = cria_pilha();Fila* fexp = cria_fila();

for(i = 0; t!=1 ;i++){
printf("\n - reading %c - \n", sExp[i]);
read = sExp[i];w = 0;
case1 = ((int)read<58)&&((int)read>47);
case2 = (read == pre[1]) || (read == pre[2]);
case3 = (read == pre[3])||(read == pre[4]);
case4 = read == '\0';case5 = read == '^';
    /*Case - simplest operator*/
    if(read == '('){
    signs = empilha(read,signs);
    printf("\n Case 0: signs\n"); imprime_pilha(signs); printf("\n Case 0: numbers\n");imprime_pilha(numbers); printf("\n Case 0: line\n");imprime_fila(fexp); //testing
    }
    /*Case - operands*/
    if(case1){
    numbers = empilha(read, numbers);
    printf("\n Case 1: signs\n"); imprime_pilha(signs); printf("\n Case 1: numbers\n");imprime_pilha(numbers); printf("\n Case 1: line\n");imprime_fila(fexp); //testing
    }
    /*Case: operators + or minus*/
    if(case2){ /*Review other cases based on that*/
    if(signs->topo != NULL){
    sit1 = (signs->topo->info == pre[1]) || (signs->topo->info == pre[2]);
    sit4 = (signs->topo->info == pre[3]) || (signs->topo->info == pre[4]);
    sit6 = signs->topo->info == pre[5];
    }
        /*sub-case - signs with operator with same precedence*/
        while((sit1||sit4)||(sit6)){
            if(fexp->ini == NULL){
                while(w<2){
                if(numbers->topo!=NULL){numbers = desempilha(&out, numbers);  insere_fila(out,fexp); w++;}
                }
                if(signs->topo!=NULL){signs = desempilha(&out, signs);
                    if(out!='('){insere_fila(out,fexp);}
                }
            }
            else{
                if(numbers->topo!=NULL){numbers = desempilha(&out, numbers); insere_fila(out,fexp);}
                if(signs->topo!=NULL){signs = desempilha(&out, signs); insere_fila(out,fexp); } /*add situation where '('*/
            }
        if(signs->topo != NULL){sit1 = (signs->topo->info == pre[1]) || (signs->topo->info == pre[2]);sit4 = (signs->topo->info == pre[3]) || (signs->topo->info == pre[4]); sit6 = signs->topo->info == pre[5];}
        else{sit1=sit4=sit6=0;}
        }

        /*sub-case - operators with higher precedence*/
    signs = empilha(read,signs);
    printf("\n Case 2: signs\n"); imprime_pilha(signs); printf("\n Case 2: numbers\n");imprime_pilha(numbers); printf("\n Case 2: line\n");imprime_fila(fexp); //testing
    }
    /*Case: operators * and / */
    if(case3){
    if(signs->topo != NULL){
    sit4 = (signs->topo->info == pre[3]) || (signs->topo->info == pre[4]);
    sit6 = signs->topo->info == pre[5];
    }
        /*operators with same precedence*/
        if(sit4||sit6){
            if(fexp->ini == NULL){
                while(w<2){
                if(numbers->topo!=NULL){numbers = desempilha(&out, numbers); insere_fila(out,fexp); w++;}
                }
                if(signs->topo!=NULL){signs = desempilha(&out, signs);
                    if(out!='('){insere_fila(out,fexp);}
                }
            if(signs->topo != NULL){sit4 = (signs->topo->info == pre[3]) || (signs->topo->info == pre[4]);sit6 = signs->topo->info == pre[5];}
            }
            while(sit4){
                if(numbers->topo!=NULL){numbers = desempilha(&out, numbers); insere_fila(out,fexp);}
                if(signs->topo!=NULL){signs = desempilha(&out, signs); insere_fila(out,fexp);}
                if(signs->topo != NULL){sit4 = (signs->topo->info == pre[3]) || (signs->topo->info == pre[4]);sit6 = signs->topo->info == pre[5];}
            }
        }
    signs = empilha(read,signs);
    printf("\n Case 3: signs\n"); imprime_pilha(signs); printf("\n Case 3: numbers\n");imprime_pilha(numbers); printf("\n Case 3: line\n");imprime_fila(fexp); //testing
    }
    /*Case: closing parenthesis*/
    if(read == ')'){
    out = ' ';
    while(out!= '('){
        if(fexp->ini == NULL){
            while(w<2){
                if(numbers->topo!= NULL){numbers = desempilha(&out, numbers); insere_fila(out,fexp); w++;}
            }
            if(signs->topo!=NULL){signs = desempilha(&out, signs);
                if(out!='('){insere_fila(out,fexp);}
            }
        }
        else{
            while(out != '('){
                if(numbers->topo!=NULL){numbers = desempilha(&out, numbers); insere_fila(out,fexp);}
                if(signs->topo!=NULL){signs = desempilha(&out, signs);
                    if(out!='('){insere_fila(out,fexp);}
                }
            }
        }
    }
    }
    /*case - operator ^ */
    if(case5){
        if(signs->topo != NULL){
        sit6 = signs->topo->info == pre[5];
        }
        while(sit6){
                if(fexp->ini == NULL){
                    while(w<2){
                    if(numbers->topo!=NULL){numbers = desempilha(&out, numbers);  insere_fila(out,fexp); w++;}
                    }
                    if(signs->topo!=NULL){signs = desempilha(&out, signs);
                        if(out!='('){insere_fila(out,fexp);}
                    }
                }
                else{
                    if(numbers->topo!=NULL){numbers = desempilha(&out, numbers); insere_fila(out,fexp);}
                    if(signs->topo!=NULL){signs = desempilha(&out, signs);
                        if(out!='('){insere_fila(out,fexp);}
                    }
                }
                if(signs->topo != NULL){sit6 = signs->topo->info == pre[5];}
                else{sit6 = 0;}
        }
    signs = empilha(read,signs);
    }
    /*case - sqrt */
    /*case -  end of expression*/
    if(case4){
    t = 1;
    sit5 = (numbers->topo != NULL)||(signs->topo != NULL);
        while(sit5){
            if(fexp->ini == NULL){
                while(w<2){
                    if(numbers->topo!= NULL){numbers = desempilha(&out, numbers); insere_fila(out,fexp); w++;}
                }
                if(signs->topo!=NULL){signs = desempilha(&out, signs);insere_fila(out,fexp);
                }
            }
            else{
                if(numbers->topo!=NULL){numbers = desempilha(&out, numbers); insere_fila(out,fexp);}
                if(signs->topo!=NULL){signs = desempilha(&out, signs); insere_fila(out,fexp);
                }
            }
        sit5 = (numbers->topo != NULL)||(signs->topo != NULL);
        }
    printf("\n Case 4: signs\n"); imprime_pilha(signs); printf("\n Case 4: numbers\n");imprime_pilha(numbers); printf("\n Case 4: line\n");imprime_fila(fexp); //testing
    }
//end
}

imprime_fila(fexp);

}





