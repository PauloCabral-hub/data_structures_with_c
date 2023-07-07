#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int verify_map(int* mdim, int** map_mask, double** map_val, double** n_fmat){
int i, j, ok = 1;
double dif, ac = 0.0001;

for(i=0;i<mdim[0];i++){
    for(j=0;j<mdim[1];j++){
        if(map_mask[i][j]==1){
        dif = fabs(map_val[i][j]-n_fmat[i][j]);
            if(dif > ac){
            ok = 0;
        break;
        }
        }
    }
}

return ok;
}
