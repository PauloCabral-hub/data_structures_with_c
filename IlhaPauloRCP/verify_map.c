#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

/*"1 se n�o for necess�rio mais itera��es" verify_map("dimens�es da matriz", "mapa de pontos a serem considerados", "mapa de valores na itera��o passada",*/
/* "mapa de valores na itera��o atual")*/

int verify_map(int* mdim, int** map_mask, double** map_val, double** n_fmat){
int i, j, ok = 1;
double dif, ac = 0.0001; /* situa��o de equil�brio, se para todos os pontos  a diferen�a de polui��o entre a itera��o anterior e a atual form menor que este valor, ent�o ok retorna 1.*/

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
