/* Homework 1 - Data structures*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* readmap_dim ( "arquivo contendo as dimensões", "endereço da variável de armazenamento das dimensões", "valor do ponteiro para o arquivo")*/

/* Função que retorna as dimensões do mapa. Estas dimensões estão contidas na primeira*/
/* linha do arquivo contendo os pontos do mapa a serem considerados.*/


void readmap_dim(const char adress[121], int* mdim, FILE* map){
char hold[100] = "";
int l = 0, i = 0;
char iarrow = '\0';
char digit_f = 48, digit_c = 57;/*ASCII números: 48-57*/



if(map == NULL){
printf("The file wasn't found.");
return;
}


while((iarrow) != '\n'){
iarrow = fgetc(map); /* função que retorna o caracter do arquivo texto e anda com o cursor.*/
    if((iarrow<=digit_c) && (iarrow>=digit_f)){ /* verifica se o caracter é um número inteiro pela comparação com a table ASCII.*/
        while(hold[l] != '\0'){ /* busca pelo fim da string contida em "hold".*/
        l++;
        }
        hold[l] = iarrow; /*substituição do marcador de fim pelo caracter.*/
        hold[++l] = '\0'; /*atualização do marcador de fim da string.*/

    }
    else{
    *(mdim+i) = (int) strtod(hold,NULL); /* entrega da dimensão ao vetor de dimensões.*/
    hold[0] = '\0'; l = 0; /* volta dos valores de hold as condições iniciais para leitura da próxima dimensão.*/
    i++;
    }
}

*(mdim+i) = (int) strtod(hold,NULL); /* entrega do valor da segunda dimensão ao vetor de dimensões.*/

printf("\nNumber of lines: %d\nNumber of columns: %d\n", *(mdim+0), *(mdim+1)); /* verificação da leitura.*/


rewind(map); /* volta do cursor para o início do arquivo.*/
}



