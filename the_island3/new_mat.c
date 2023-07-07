#include<stdlib.h>

double** new_fmat(int* mdim){
    int i, j;
    int k, l;
    double** n_fmat;

    n_fmat = (double**) malloc(sizeof(double*)*mdim[0]);
    for(i = 0;i<mdim[1];i++){
    n_fmat[i] = (double*) malloc(sizeof(double)*mdim[1]);
    }

    for(k=0;k<mdim[0];k++){
        for(l= 0;l<mdim[1];l++){
        n_fmat[k][l]= (double)0;
        }
    }

    printf("\n This is the New Matrix \n");

    for(i=0;i<mdim[0];i++){
        for(j= 0;j<mdim[1];j++){
        printf("%.3f ",n_fmat[i][j]);
        }
    printf("\n");
    }
    return n_fmat;
}
