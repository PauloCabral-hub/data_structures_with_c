#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Defini��o das estruturas utilizadas.*/

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


/* Prot�tipos das fun��es.*/
Pilha* cria_pilha(void);
Pilha* empilha(char element[50], Pilha *p);
Pilha* desempilha(char* poped[50], Pilha* p);
void imprime_pilha(Pilha* p);

Fila* cria_fila(void);
Fila* insere_fila(char n[50], Fila* f);
Fila* fila_sai(char* popped[50], Fila* f);
void imprime_fila(Fila* f);


parser(char sExp[256], Fila** stpolonesa){
char out[50], hold[50], sqrt[50]="sqrt";
char read;
int i, j, p=1, w;
int par[10]; par[0]= 0;

int sit1=0, sit2=0,sit3=0,sit4= 0, case1, case2, case3;
char pre[] = "(-+*/"; /* avaliar a necessidade ao fim.*/

/*Pilhas: operadores (signs), operandos (numbers);*/
/*Fila: fila de armazenamento da express�o polonesa;*/
Pilha* signs = cria_pilha(); Pilha* numbers = cria_pilha();Fila* fexp = cria_fila();


for(i = 0;;i++){
printf("\n - leitura atual: %c - \n", sExp[i]); /* apresenta o caracter lido.*/
read = sExp[i];w = 0;j=0; /*read recebe a leitura atual.*/
case1 = ((int)read<58)&&((int)read>47); /* avalia se o caracter lido constitue um operando.*/
case2 = (read == '-') || (read == '+'); /* avalia se o caracter lido � de baixa preced�ncia.*/
case3 = (read == '*')||(read == '/'); /* avalia se o caracter lido � de alta preced�ncia.*/


/*Caso - operadores*/
if(case1){
hold[j] = '\0'; /*limpa o vetor de armazenamento. O vetor hold armazena o n�mero em formato string.*/
/*working*/
    do{
    hold[j] = read;
        if( (((int)sExp[i+1]<58)&&((int)sExp[i+1]>47))||(sExp[i+1] == '.')){ /* Se verdadeiro, continuar a ler os pr�ximos n�meros.*/
        i++;j++; read = sExp[i]; /*avan�o na leitura.*/
        }
        else{
        break;
        }
    }while((((int)read<58)&&((int)read>47) )||(read == '.')) ;
    hold[++j] ='\0'; /* atualiza o marcador de fim do n�mero lido.*/
numbers = empilha(hold, numbers); /* empilha o n�mero ap�s leitura completa.*/
}

/*Caso de leitura de parentesis.*/
if(read == '('){ /* leitura do parentesis.*/
hold[0] = read; hold[1] = '\0';
signs = empilha(hold,signs); /*empilha o parentesis em qualquer hip�tese (preced�ncia m�xima).*/
par[p] = (sExp[i+1]== '-')||(sExp[i+1]== '+');p++; /* vetor que acompanha a abertura de parentesis. AVALIAR NECESSIDADE DO PAR.*/
}

if(case2){
    /*Caso '-' ou '+' un�rio no in�cio da express�o*/
    if(i==0){
    par[p-1] = 1; /*Indica que o un�rio est� fora do parentesis.*/
    }
    if(sExp[i+1] == '('){ /*Subcaso '+' ou '-' un�rio associado a parentesis.*/
    read = (read == '-')?'M':'P'; /* Mudan�a da representa��o do '-' ou '+' un�rio antes da inser��o na pilha.*/
    }
    else{ /* subcasos restantes.*/
        if(signs->topo != NULL){ /* Avalia��o da preced�ncia dos operadores da pilha.*/
        sit1 = (signs->topo->info[0] == '-') || (signs->topo->info[0] == '+');
        sit2 = (signs->topo->info[0] == '*') || (signs->topo->info[0] == '/');
        }
        while(sit1||sit2){
            if(((fexp->ini == NULL)&&(!par[p-1]))&&(w==0)){ /*caso n�o haja nenhum elemento na fila e a express�o n�o inicie com un�rio '-' ou '+'.*/
                while(w<2){ /* desempilha 2 numeros e insere na fila.*/
                    if(numbers->topo!=NULL){
                    numbers = desempilha(&out, numbers);  insere_fila(out,fexp); w++;
                    }
                }
                if(signs->topo!=NULL){signs = desempilha(&out, signs); /*desempilha um operador e insere na fila.*/
                    if(out[0]!='('){ /* caso o operador retirado seja um parentesis n�o realiza a inser��o na fila.*/
                    insere_fila(out,fexp);
                    }
                    else{
                        if( (signs->topo != NULL)&&( (signs->topo->info[0] == 'M')||(signs->topo->info[0] == 'P') ) ){ /*avalia se ap�s a saida do parentesis existe um un�rio '-' ou '+'.*/
                        signs = desempilha(&out,signs);
                        out[0] = (out[0] == 'M')?'-':'+'; /* em caso de un�rio '-' ou '+',  atribui a este seu formato original.*/
                        insere_fila(out,fexp); /* insere na fila. */
                        }
                    }
                }
            }
            else{ /*casos restantes. Desempilha apenas um n�mero.*/
                if(numbers->topo!=NULL){
                numbers = desempilha(&out, numbers); insere_fila(out,fexp);
                }
                if(signs->topo!=NULL){signs = desempilha(&out, signs);
                    if(out[0]!='('){ /* caso o operador retirado seja um parentesis n�o realiza a inser��o na fila.*/
                    insere_fila(out,fexp);
                    }
                    else{
                        if( (signs->topo != NULL)&&( (signs->topo->info[0] == 'M')||(signs->topo->info[0] == 'P') ) ){
                        signs = desempilha(&out,signs);
                        out[0] = (out[0] == 'M')?'-':'+';
                        insere_fila(out,fexp);
                        }
                    }
                }
            }
        if(signs->topo != NULL){ /*Reavalia��o dos operadores na pilha.*/
        sit1 = (signs->topo->info[0] == '-') || (signs->topo->info[0] == '+');
        sit2 = (signs->topo->info[0] == '*') || (signs->topo->info[0] == '/');
        }
        else{
        sit1=sit2=0;
        }
        }

    }
hold[0] = read; hold[1] = '\0'; /* trasfere o caracter para o vetor.*/
signs = empilha(hold,signs); /* empilha o vetor.*/
} /*end of case 2*/


/*Leitura de operador de preced�ncia elevada.*/
if(case3){
if(signs->topo != NULL){
sit2 = (signs->topo->info[0] == '*') || (signs->topo->info[0] == '/');
}
    /*operators with same precedence*/
    while(sit2){
        if((fexp->ini == NULL)&&(w==0)){ /* operador de mesma preced�ncia no topo da pilha e fila vazia.*/
            while(w<2){ /* desempilha dois n�meros.*/
                if(numbers->topo!=NULL){
                numbers = desempilha(&out, numbers);
                insere_fila(out,fexp); w++;
                }
            }
            if(signs->topo!=NULL){
            signs = desempilha(&out, signs);
            insere_fila(out,fexp);
            }
        }
        else{ /*demais situa��es. Desempilha apenas um n�mero.*/
            if(numbers->topo!=NULL){
            numbers = desempilha(&out, numbers);
            insere_fila(out,fexp);
            }
            if(signs->topo!=NULL){signs = desempilha(&out, signs);
            insere_fila(out,fexp);
            }
        }
        if(signs->topo != NULL){
        sit2 = (signs->topo->info[0] == '*') || (signs->topo->info[0] == '/');
        }
        else{
        sit2=0;
        }
    }
hold[0]= read; hold[1] = '\0'; /*transfer�ncia do caracter lido para o vetor a ser empilhado.*/
signs = empilha(hold,signs);
}


/*Caso de fun��o raiz quadrada.*/
if(read == 's'){
i = i+3; /* avan�o na leitura.*/
signs = empilha(sqrt,signs);
}

/*Caso fechamento de parentesis.*/
if(read == ')'){
strcpy(out,"");
sit3 = 1; /* situa��o operador retirado igual a parentesis ou raiz quadrada.*/
    while(sit3){
        if(((fexp->ini == NULL)||(par[p-1]==0))&&(w==0)){ /* avalia se o primeiro elemento do parentesis � um operador ou n�o e se a fila est� vazia.*/
            while(w<2){
                if(numbers->topo!= NULL){
                numbers = desempilha(&out, numbers); insere_fila(out,fexp);
                }w++;
            }
            if(signs->topo!=NULL){
            signs = desempilha(&out, signs);
                if(out[0]!='('){ /* n�o insere o elemento na fila em caso de parentesis.*/
                insere_fila(out,fexp);
                }
                else{
                    if((signs->topo->info[0] == 'M')||(signs->topo->info[0] == 'P') ){ /* avalia se o elemento no topo da pilha de operadores � um '-' ou '+' un�rio.*/
                    signs = desempilha(&out,signs);
                    out[0] = (out[0] == 'M')?'-':'+';
                    insere_fila(out,fexp); out[0] = '(';
                    }
                }
            }
        sit3 = (out[0]!= '(')&&(out[0]!='s');
        }
        else{ /*casos restantes.*/
            if(numbers->topo!=NULL){
            numbers = desempilha(&out, numbers); insere_fila(out,fexp);
            }
            if(signs->topo!=NULL){
            signs = desempilha(&out, signs);
                if(out[0]!='('){
                insere_fila(out,fexp);
                    if(signs->topo->info[0] == '('){
                    signs = desempilha(&out, signs);
                        if( (signs->topo != NULL)&&( (signs->topo->info[0] == 'M')||(signs->topo->info[0] == 'P') ) ){
                        signs = desempilha(&out, signs);
                        out[0] = (out[0] == 'M')?'-':'+';
                        insere_fila(out,fexp); out[0] = '(';
                        }
                    }
                }
            }
        sit3 = (out[0]!= '(')&&(out[0]!='s');
        p--; /* indica sa�da do parentesis.*/
        }
    }
}

/*Caso marcador de fim da express�o*/
if(read == '\0'){
sit4 = 1; /* pilha de operandos e operadores n�o vazia.*/
    while(sit4){
        if((fexp->ini == NULL)&&(w==0)){ /*caso de fila vazia desempilha dois n�meros.*/
            while(w<2){
                if(numbers->topo!= NULL){
                numbers = desempilha(&out, numbers);
                insere_fila(out,fexp); w++;
                }
            }
            if(signs->topo!=NULL){
            signs = desempilha(&out, signs);
                if(out[0]!= '('){
                    if((out[0]== 'M')||(out[0] == 'P')){
                    out[0] = (out[0]== 'M')?'-':'+';
                    }
                    insere_fila(out,fexp);
                }
            }
        }
        else{ /* subcasos restantes.*/
            if(numbers->topo!=NULL){
            numbers = desempilha(&out, numbers);
            insere_fila(out,fexp);
            }
            if(signs->topo!=NULL){
            signs = desempilha(&out, signs);
                if(out[0]!= '('){
                    if((out[0]== 'M')||(out[0] == 'P')){
                    out[0] = (out[0]== 'M')?'-':'+';
                    }
                    insere_fila(out,fexp);
                }
            }
        }
    sit4 = (numbers->topo != NULL)||(signs->topo != NULL);
    }
break;
}


checking_ppf(signs,numbers,fexp);
printf(".......................................");
/*end*/
}

*stpolonesa = fexp; /* entrega ao ponteiro a express�o polonesa.*/

printf("\nEXPRESSAO POLONESA CORRESPONDENTE: ");
imprime_fila(fexp); /* imprime a express�o polonesa.*/

}






