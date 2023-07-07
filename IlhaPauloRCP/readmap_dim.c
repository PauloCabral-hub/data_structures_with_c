/* Homework 1 - Data structures*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* readmap_dim ( "arquivo contendo as dimens�es", "endere�o da vari�vel de armazenamento das dimens�es", "valor do ponteiro para o arquivo")*/

/* Fun��o que retorna as dimens�es do mapa. Estas dimens�es est�o contidas na primeira*/
/* linha do arquivo contendo os pontos do mapa a serem considerados.*/


void readmap_dim(const char adress[121], int* mdim, FILE* map){
char hold[100] = "";
int l = 0, i = 0;
char iarrow = '\0';
char digit_f = 48, digit_c = 57;/*ASCII n�meros: 48-57*/



if(map == NULL){
printf("The file wasn't found.");
return;
}


while((iarrow) != '\n'){
iarrow = fgetc(map); /* fun��o que retorna o caracter do arquivo texto e anda com o cursor.*/
    if((iarrow<=digit_c) && (iarrow>=digit_f)){ /* verifica se o caracter � um n�mero inteiro pela compara��o com a table ASCII.*/
        while(hold[l] != '\0'){ /* busca pelo fim da string contida em "hold".*/
        l++;
        }
        hold[l] = iarrow; /*substitui��o do marcador de fim pelo caracter.*/
        hold[++l] = '\0'; /*atualiza��o do marcador de fim da string.*/

    }
    else{
    *(mdim+i) = (int) strtod(hold,NULL); /* entrega da dimens�o ao vetor de dimens�es.*/
    hold[0] = '\0'; l = 0; /* volta dos valores de hold as condi��es iniciais para leitura da pr�xima dimens�o.*/
    i++;
    }
}

*(mdim+i) = (int) strtod(hold,NULL); /* entrega do valor da segunda dimens�o ao vetor de dimens�es.*/

printf("\nNumber of lines: %d\nNumber of columns: %d\n", *(mdim+0), *(mdim+1)); /* verifica��o da leitura.*/


rewind(map); /* volta do cursor para o in�cio do arquivo.*/
}



