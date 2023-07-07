#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void rewrite_mat(int* mdim,int** map_mask,double** map_val,double** n_fmat){
int i,j;

for(i=0;i<mdim[0];i++){
    for(j= 0;j<mdim[1];j++){
        if(map_mask[i][j] == 1){
        map_val[i][j] = n_fmat[i][j];
        }
    }
}

printf("\n Map of Values updated. \n");

for(i = 0; i < mdim[0]; i++){
    for(j = 0;j< mdim[1]; j++){
    printf("%.5f ", map_val[i][j]);
    }
printf("\n");
}

return;
}
