#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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




//Probably will be necessary changes in the stack functions to always return the pointer to the structure;

parser(char sExp[256], Fila* stpolonesa){
char out[50], hold[50], sqrt[50]="sqrt";
char read;
int i, j, p=1, w;
int par[10]; par[0]= 0;

int sit1=0, sit2=0,sit3=0,sit4=0,sit5= 0, case1, case2, case3;
char pre[] = "(-+*/^", psave = ')';

Pilha* signs = cria_pilha(); Pilha* numbers = cria_pilha();Fila* fexp = cria_fila();

//falta apenas resolver o caso do número negativo dentro do parentesis

for(i = 0;;i++){
printf("\n - reading %c - \n", sExp[i]);
read = sExp[i];w = 0;j=0;
case1 = ((int)read<58)&&((int)read>47);
case2 = (read == pre[1]) || (read == pre[2]);
case3 = (read == pre[3])||(read == pre[4]);


/*Case - numbers*/
if(case1){
hold[j] = '\0';
//working
    do{
    hold[j] = read;
        if( (((int)sExp[i+1]<58)&&((int)sExp[i+1]>47))||((sExp[i+1] == '.')||(sExp[i+1] ==  ','))){
        i++;j++; read = sExp[i];
        }
        else{
        break;
        }
    }while( ( ((int)read<58)&&((int)read>47) )|| ( (read == '.')||(read ==  ',') ) ) ;
    hold[++j] ='\0';
//working
numbers = empilha(hold, numbers);
    if( (signs->topo != NULL)&&((signs->topo->info[0] == 'm') || (signs->topo->info[0] == 'p') ) ){
    numbers = desempilha(&out,numbers); insere_fila(out,fexp);
    signs = desempilha(&out,signs); out[0] = (out[0] == 'm')?'-':'+';insere_fila(out,fexp);
    }
}

/*Case - parenthesis*/
if(read == '('){
hold[0] = read; hold[1] = '\0';
signs = empilha(hold,signs);
par[p] = (sExp[i+1]== '-')||(sExp[i+1]== '+');p++;
}

if(case2){
    /*Case - unary sign as first element of the expression*/
    if(i==0){
    par[p-1] = 1;
    }
    if(sExp[i+1] == '('){ //Case unary plus or minus associated with parenthesis
    read = (read == '-')?'M':'P';
    }
    else{
        if(signs->topo != NULL){ // Evaluating precedence of operators in the stack
        sit1 = (signs->topo->info[0] == pre[1]) || (signs->topo->info[0] == pre[2]);
        sit2 = (signs->topo->info[0] == pre[3]) || (signs->topo->info[0] == pre[4]);
        sit3 = signs->topo->info[0] == pre[5];
        }
        while((sit1||sit2)||(sit3)){
            // inside the while in line 98
            if(((fexp->ini == NULL)&&(!par[p-1]))&&(w==0)){
                while(w<2){
                    if(numbers->topo!=NULL){
                    numbers = desempilha(&out, numbers);  insere_fila(out,fexp); w++;
                    }
                }
                if(signs->topo!=NULL){signs = desempilha(&out, signs);
                    if(out[0]!='('){
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
            else{
                if(numbers->topo!=NULL){
                numbers = desempilha(&out, numbers); insere_fila(out,fexp);
                }
                if(signs->topo!=NULL){signs = desempilha(&out, signs);
                    if(out[0]!='('){
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
            //end of while 98
        //working
        if(signs->topo != NULL){
        sit1 = (signs->topo->info[0] == pre[1]) || (signs->topo->info[0] == pre[2]);
        sit2 = (signs->topo->info[0] == pre[3]) || (signs->topo->info[0] == pre[4]);
        sit3 = signs->topo->info[0] == pre[5];}
        else{
        sit1=sit2=sit3=0;
        }
        }

    }
hold[0] = read; hold[1] = '\0';
signs = empilha(hold,signs);
} //end of case 2


/*Case: operators * and / */
if(case3){
if(signs->topo != NULL){
sit2 = (signs->topo->info[0] == pre[3]) || (signs->topo->info[0] == pre[4]);
sit3 = signs->topo->info[0] == pre[5];
}
    /*operators with same precedence*/
    while(sit2||sit3){
        if((fexp->ini == NULL)&&(w==0)){
            while(w<2){
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
        else{
            if(numbers->topo!=NULL){
            numbers = desempilha(&out, numbers);
            insere_fila(out,fexp);
            }
            if(signs->topo!=NULL){signs = desempilha(&out, signs);
            insere_fila(out,fexp);
            }
        }
        if(signs->topo != NULL){
        sit2 = (signs->topo->info[0] == pre[3]) || (signs->topo->info[0] == pre[4]);
        sit3 = signs->topo->info[0] == pre[5];
        }
        else{
        sit2=sit3=0;
        }
    }
hold[0]= read; hold[1] = '\0';
signs = empilha(hold,signs);
}

/*case - operator ^ */
if(read == '^'){
    if(signs->topo != NULL){
    sit3 = signs->topo->info[0] == pre[5];
    }
    while(sit3){
            if((fexp->ini == NULL)&&(w==0)){
                while(w<2){
                    if(numbers->topo!=NULL){
                    numbers = desempilha(&out, numbers);
                    insere_fila(out,fexp); w++;
                    }
                }
                if(signs->topo!=NULL){
                signs = desempilha(&out, signs);insere_fila(out,fexp);
                }
            }
            else{
                if(numbers->topo!=NULL){
                numbers = desempilha(&out, numbers);
                insere_fila(out,fexp);
                }
                if(signs->topo!=NULL){
                signs = desempilha(&out, signs);insere_fila(out,fexp);
                }
            }
            if(signs->topo != NULL){
            sit3 = signs->topo->info == pre[5];
            }
            else{
            sit3 = 0;
            }
    }
hold[0]=read;hold[1]='\0';
signs = empilha(read,signs);
}

/*case - function sqrt*/
if(read == 's'){
i = i+3;
  /*preparing*/
signs = empilha(sqrt,signs);
}

/*Case: closing parenthesis*/
if(read == ')'){
strcpy(out,"");
sit5 = 1;
    while(sit5){
        if(((fexp->ini == NULL)||(par[p-1]==0))&&(w==0)){
            while(w<2){
                if(numbers->topo!= NULL){
                numbers = desempilha(&out, numbers); insere_fila(out,fexp);
                }w++;
            }
            if(signs->topo!=NULL){
            signs = desempilha(&out, signs);
                if(out[0]!='('){
                insere_fila(out,fexp);
                }
                else{
                    if((signs->topo->info[0] == 'M')||(signs->topo->info[0] == 'P') ){
                    signs = desempilha(&out,signs);
                    out[0] = (out[0] == 'M')?'-':'+';
                    insere_fila(out,fexp); out[0] = '(';
                    }
                }
            }
        sit5 = (out[0]!= '(')&&(out[0]!='r');
        }
        else{
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
        sit5 = (out[0]!= '(')&&(out[0]!='s');
        p--;
        }
    }
}






/*case -  end of expression*/
if(read == '\0'){
sit4 = 1;
    while(sit4){
        if((fexp->ini == NULL)&&(w==0)){
            while(w<2){
                if(numbers->topo!= NULL){
                numbers = desempilha(&out, numbers);
                insere_fila(out,fexp); w++;
                }
            }
            if(signs->topo!=NULL){
            signs = desempilha(&out, signs);
            if(out[0]!= '('){insere_fila(out,fexp);}
            }
        }
        else{
            if(numbers->topo!=NULL){
            numbers = desempilha(&out, numbers);
            insere_fila(out,fexp);
            }
            if(signs->topo!=NULL){
            signs = desempilha(&out, signs);if(out[0]!= '('){insere_fila(out,fexp);}
            }
        }
    sit4 = (numbers->topo != NULL)||(signs->topo != NULL);
    }
break;
}


checking_ppf(signs,numbers,fexp);
//end
}

imprime_fila(fexp);

}






