#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* readmap_mask ( "arquivo contendo as dimensões", "endereço do vetor de dimensões", "valor do ponteiro para o arquivo")*/

/* Função que retorna uma matriz contendo os valores do mapa indicativo dos pontos válidos para o cálculo.*/


int** readmap_mask(char adress[121], int* mdim, FILE* map){
int m, i = 0, j= 0, l=0, lines = mdim[0], columns = mdim[1];
char hold[100] = "", digit_f = 48, digit_c = 57;/*ASCII for digits: 48-57*/;
char* iarrow = '\0';
int** map_mask;

/* alocação dinâmica da matriz.*/
map_mask = (int**) malloc(sizeof(int*)*lines);
for(m = 0;m<columns;m++){
map_mask[m] = (int*) malloc(sizeof(int)*columns);
}

/* verificação do sucesso na alocação.*/
if(map == NULL){
printf("The file was not found.\n");
}
else{
printf("The file was found.\n");
}

/* condução do cursor à segunda linha, uma vez que a primeira contem apenas as dimensões do mapa.*/
while(iarrow != '\n'){
iarrow = fgetc(map);
}

/* leitura do arquivo e armazenamento dos valores na matriz alocada dinâmicamente.*/
while(iarrow != EOF){
iarrow = fgetc(map);
    if((iarrow<=digit_c) && (iarrow>=digit_f)){ /* cursor sobre um número. */
        while(hold[l] != '\0'){
        l++;
        }
        hold[l] = iarrow;
        hold[++l] = '\0';
    }
    else{ /* cursor sobre um espaço ou marcador de fim de linha.*/
    map_mask[i][j] = (int) strtod(hold,NULL);
    j++;
        if(iarrow == '\n'){
        i++;j = 0;
        }
    hold[0] = '\0'; l = 0;
    }
}

map_mask[i][j] = (int) strtod(hold,NULL); /* inserção do último valor.*/

/* verificação da leitura.*/
printf("\n This is the Map mask \n");

for(i = 0; i < mdim[0]; i++){
    for(j = 0;j< mdim[1]; j++){
    printf("%d ", map_mask[i][j]);
    }
printf("\n");
}


rewind(map);

return map_mask;
}


