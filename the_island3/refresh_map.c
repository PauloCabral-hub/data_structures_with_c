//This function refresh values of n_fmat matrix.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int refresh_map(int* mdim, int** map_mask, double** map_val, double** n_fmat, int it){
int i, j, l = 0;
double s1,s2,s3,s4;

printf("\n This is the New Matrix before. \n");

for(i=0;i<mdim[0];i++){
    for(j= 0;j<mdim[1];j++){
    printf("%3.2f ",n_fmat[i][j]);
    }
printf("\n");
}



for(i = 0;i< mdim[0]; i++){
    for(j = 0;j< mdim[1]; j++){
        if(map_mask[i][j] == 1){
            if((i-1)<0){
            s1 = 0;
            }
            else{
            s1 = map_val[i-1][j];
            }

            if((j+1)>=mdim[1]){
            s2 = 0;
            }
            else{
            s2 = map_val[i][j+1];
            }

            if((i+1)>=mdim[0]){
            s3 = 0;
            }
            else{
            s3 = map_val[i+1][j];
            }

            if((j-1)<0){
            s4 = 0;
            }
            else{
            s4 = map_val[i][j-1];
            }

            n_fmat[i][j] = (s1+s2+s3+s4)/4;
                }
            if(map_mask[i][j] == 2){
            n_fmat[i][j]=map_val[i][j];
            }
    }
}


printf("\n Mask Matrix. \n");

for(i=0;i<mdim[0];i++){
    for(j= 0;j<mdim[1];j++){
    printf("%d ",map_mask[i][j]);
    }
printf("\n");
}

printf("\n New Matrix. \n");

for(i=0;i<mdim[0];i++){
    for(j= 0;j<mdim[1];j++){
    printf("%3.5f ",(float) n_fmat[i][j]);

    }
printf("\n");
}

return it+1;
}
