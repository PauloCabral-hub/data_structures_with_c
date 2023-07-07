#include<stdio.h>
#include<stdlib.h>
/*Função para conversão de string para ponto flutuante de precisão dupla.*/
/*"wnum" corresponds to the number which should be converted. Corresponde ao número que deve ser convertido.*/
/*"icom" corresponde a posição da vírgula.*/
/*"mply" corresponde ao fator pelo qual o número deve ser multiplicado.*/
/*"div" corresponde ao fator ao qual o valor deve ser multiplicado para atingir o decimal.*/
/*"fn" número convertido em ponto flutuante de precisão dupla.*/

double to_float(char wnum[50]){

/*Na tabela ASCII 0-9 corresponde a 48-57*/

double fn = 0.0, div = 0.1;
int i, j,jj,w,ww, icom, tn, td, n = 0, nat= 0;
int mply = 1;

/*This part verify if it is a decimal number and where the comma is.*/
for(i = 0; wnum[i] != NULL; i++){
    if(wnum[i]=='.'){
    icom = i;
    nat = 1;
    }
}
icom = (nat == 1)?icom:i;

for(j= 0; j<icom;j++){
    if(wnum[(icom-1)-j] == '-'){
    n=1;
    break;
    }
tn = wnum[(icom-1)-j]-48;
    if (j!= 0){
        for (jj=1;jj<=j;jj++){
        mply = mply*10;
        }
    }

fn = fn + tn*mply;
mply = 1;
}

w=0;
while((nat == 1)&&(wnum[(icom+1)+w] != NULL)){

td = wnum[(icom+1)+w]-48;
    if (w!=0){
        for(ww=1;ww<=w;ww++){
         div = div/10;
        }
    }
fn = fn+ td*div;
div = 0.1; w++;
}

if(n==1){
fn = fn*(-1);
}

return fn;
}

