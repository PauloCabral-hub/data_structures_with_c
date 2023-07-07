#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*void rewrite_mat("dimensões do mapa","mapa com os pontos a serem considerados","mapa com os valores da interação anterior",*/
/*"mapa com os valores da iteração atual", "iteração")*/

void rewrite_mat(int* mdim,int** map_mask,double** map_val,double** n_fmat, int it){
int i,j,o;
/* Reescrevendo os valores.*/
for(i=0;i<mdim[0];i++){
    for(j= 0;j<mdim[1];j++){
        if(map_mask[i][j] == 1){
        map_val[i][j] = n_fmat[i][j];
        }
    }
}

/* verificação dos valores em intervalos específicos*/
if((((it == 1)||(it == 50))||(it == 100))||( it == 150)){
printf("\n ...iteracao (%d), continuar? ",it);scanf("%d",&o);/* possibilita ver os passos do processo.*/
    printf("\n Map of Values updated. \n");

    for(i = 0; i < mdim[0]; i++){
        for(j = 0;j< mdim[1]; j++){
            if(map_val[i][j]<100){
            printf(" ");
                if(map_val[i][j]<10){
                printf(" ");
                }
            }
        printf("%.5f ", map_val[i][j]);
        }
        printf("\n");
    }
}


return;
}



