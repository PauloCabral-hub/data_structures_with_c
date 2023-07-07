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
int i, j, f =0, t = 0, w,o, flag, flag2;
int sit1=0, sit2=0,sit3=0,sit4=0,sit5= 0, case1, case2, case3, case4, case5, case6, caselast;
char pre[] = "(-+*/^", psave = ')', sqrt = 'r', seno = 's';

Pilha* signs = cria_pilha(); Pilha* numbers = cria_pilha();Fila* fexp = cria_fila();

for(i = 0; t!=1 ;i++){
printf("\n - reading %c - \n", sExp[i]);
read = sExp[i];w = 0;o = 1; flag=0;flag2=0;
case1 = ((int)read<58)&&((int)read>47);
case2 = (read == pre[1]) || (read == pre[2]);
case3 = (read == pre[3])||(read == pre[4]);
case4 = read == '\0';case5 = read == '^';case6 = (read == 's');
    /*Case - simplest operator*/
    if(read == '('){
    signs = empilha(read,signs);
    }
    /*Case - operands*/
    if(case1){
    numbers = empilha(read, numbers);
    }
    /*Case: operators + or minus*/
    if(case2){ /*Review other cases based on that*/
    if(signs->topo != NULL){
    sit1 = (signs->topo->info == pre[1]) || (signs->topo->info == pre[2]);
    sit2 = (signs->topo->info == pre[3]) || (signs->topo->info == pre[4]);
    sit3 = signs->topo->info == pre[5];
    }
        /*sub-case - signs with operator with same precedence*/
        while((sit1||sit2)||(sit3)){
            if(fexp->ini == NULL){
                while(w<2){
                if(numbers->topo!=NULL){numbers = desempilha(&out, numbers);  insere_fila(out,fexp); w++;}
                }
                if(signs->topo!=NULL){signs = desempilha(&out, signs);if(out!='('){insere_fila(out,fexp);}}
            }
            else{
                if(numbers->topo!=NULL){numbers = desempilha(&out, numbers); insere_fila(out,fexp);}
                if(signs->topo!=NULL){signs = desempilha(&out, signs); if(out!='('){insere_fila(out,fexp);} } /*add situation where '('*/
            }
        if(signs->topo != NULL){sit1 = (signs->topo->info == pre[1]) || (signs->topo->info == pre[2]);sit2 = (signs->topo->info == pre[3]) || (signs->topo->info == pre[4]); sit3 = signs->topo->info == pre[5];}
        else{sit1=sit2=sit3=0;}
        }
        /*sub-case - operators with higher precedence*/
    signs = empilha(read,signs);
    }
    /*Case: operators * and / */
    if(case3){
    if(signs->topo != NULL){
    sit2 = (signs->topo->info == pre[3]) || (signs->topo->info == pre[4]);
    sit3 = signs->topo->info == pre[5];
    }
        /*operators with same precedence*/
        if(sit2||sit3){
            if(fexp->ini == NULL){
                while(w<2){
                if(numbers->topo!=NULL){numbers = desempilha(&out, numbers); insere_fila(out,fexp); w++;}
                }
                if(signs->topo!=NULL){signs = desempilha(&out, signs);if(out!='('){insere_fila(out,fexp);}}
            if(signs->topo != NULL){sit2 = (signs->topo->info == pre[3]) || (signs->topo->info == pre[4]);sit3 = signs->topo->info == pre[5];}
            }
            while(sit2){
                if(numbers->topo!=NULL){numbers = desempilha(&out, numbers); insere_fila(out,fexp);}
                if(signs->topo!=NULL){signs = desempilha(&out, signs);if(out!='('){insere_fila(out,fexp);}}
                if(signs->topo != NULL){sit2 = (signs->topo->info == pre[3]) || (signs->topo->info == pre[4]);sit3 = signs->topo->info == pre[5];}
            }
        }
    signs = empilha(read,signs);
    }
    /*Case: closing parenthesis*/
    if(read == ')'){
    out = ' ';
    sit5 = (out!= '(')&&(out!='r');f++;
    for(;o<6;o++){
        if(signs->topo->info == pre[o]){
        flag++;
        }
    }
    if(signs->topo->info == 'r'){flag2++;}
        while(sit5){
            if(((fexp->ini == NULL)&&(!flag2))||(flag&&(w==0))){
                while(w<2){
                    if(numbers->topo!= NULL){numbers = desempilha(&out, numbers); insere_fila(out,fexp);}w++;
                }
                if(signs->topo!=NULL){signs = desempilha(&out, signs);if(out!='('){insere_fila(out,fexp);}}
            sit5 = (out!= '(')&&(out!='r');flag--;
            }
            else{
                while(sit5){
                    if(numbers->topo!=NULL){numbers = desempilha(&out, numbers); insere_fila(out,fexp);}
                    if(signs->topo!=NULL){signs = desempilha(&out, signs);if(out!='('){insere_fila(out,fexp);}}
                sit5 = (out!= '(')&&(out!='r');
                }
            }
        }
    }
    /*case - operator ^ */
    if(case5){
        if(signs->topo != NULL){
        sit3 = signs->topo->info == pre[5];
        }
        while(sit3){
                if(fexp->ini == NULL){
                    while(w<2){
                    if(numbers->topo!=NULL){numbers = desempilha(&out, numbers);  insere_fila(out,fexp); w++;}
                    }
                    if(signs->topo!=NULL){signs = desempilha(&out, signs);if(out!='('){insere_fila(out,fexp);}}
                }
                else{
                    if(numbers->topo!=NULL){numbers = desempilha(&out, numbers); insere_fila(out,fexp);}
                    if(signs->topo!=NULL){signs = desempilha(&out, signs);if(out!='('){insere_fila(out,fexp);}}
                }
                if(signs->topo != NULL){sit3 = signs->topo->info == pre[5];}
                else{sit3 = 0;}
        }
    signs = empilha(read,signs);
    }
    /*case - functions sin and sqrt*/
    if(case6){
      if(sExp[++i] == 'q'){
      i = i+3;
      /*preparing*/
      signs = empilha(sqrt,signs);
      }
      if(sExp[i] == 'i'){
      i = i+2;
      signs = empilha(seno,signs);
      }
    }
    /*case -  end of expression*/
    if(case4){
    t = 1;
    sit4 = (numbers->topo != NULL)||(signs->topo != NULL);
        while(sit4){
            if(fexp->ini == NULL){
                while(w<2){
                    if(numbers->topo!= NULL){numbers = desempilha(&out, numbers); insere_fila(out,fexp); w++;}
                }
                if(signs->topo!=NULL){signs = desempilha(&out, signs);if(out!='('){insere_fila(out,fexp);}}
            }
            else{
                if(numbers->topo!=NULL){numbers = desempilha(&out, numbers); insere_fila(out,fexp);}
                if(signs->topo!=NULL){signs = desempilha(&out, signs);if(out!='('){insere_fila(out,fexp);}}
            }
        sit4 = (numbers->topo != NULL)||(signs->topo != NULL);
        }
    }
checking_ppf(signs,numbers,fexp);
//end
}

imprime_fila(fexp);

}



