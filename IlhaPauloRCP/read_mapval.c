#include<stdio.h>
#include<string.h>
#include<stdlib.h>


double** readmap_val(char adress[121], int* mdim, FILE* map){
int m, i = 0, j= 0, l=0, lines = mdim[0], columns = mdim[1];
char hold[100] = "", digit_f = 48, digit_c = 57;/*ASCII for digits: 48-57*/
char* iarrow = '\0';


/* aloca dinâmicamente uma matriz de elementos tipo ponto flutuante de precisão dupla.*/
double** map_val = (double**) malloc(sizeof(double*)*lines);
for(m = 0;m<columns;m++){
map_val[m] = (double*) malloc(sizeof(double)*columns);
}

/* Informa sobre o sucesso na alocação.*/
if(map == NULL){
printf("The file was not found.\n");
return;
}
else{
printf("The file was found.\n");
}

/* Leitura dos valores.*/
while(iarrow != EOF){
iarrow = fgetc(map);
    if(((iarrow<=digit_c)&&(iarrow>=digit_f))||(iarrow == '.')){
        while(hold[l] != '\0'){
        l++;
        }
        hold[l] = iarrow;
        hold[++l] = '\0';
    }
    else{
    map_val[i][j] = strtod(hold,NULL); /*conversão de string para ponto flutuante.*/
    j++;
        if(iarrow == '\n'){
        i++;
        j = 0;
        }
    hold[0] = '\0'; l = 0;
    }
}
map_val[i][j] = (float) strtod(hold,NULL); /*conversão do último valor.*/

/*verificação da leitura.*/
printf("\n This is the Map of values \n");

for(i = 0; i < mdim[0]; i++){
    for(j = 0;j< mdim[1]; j++){
        if(map_val[i][j] <100){
        printf(" ");
        if(map_val[i][j] <10){
        printf(" ");
        }
        }
    printf("%.3f ", map_val[i][j]);
    }
printf("\n");
}

rewind(map); /* retorno do curso ao início do arquivo.*/

return map_val;
}


