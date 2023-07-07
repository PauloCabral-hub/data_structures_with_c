#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*Trabalho: C�lculo de polui��o total da ilha.*/

int main(void){
int o;
char adress[121] = "mapam.txt"; /*nome do arquivo contendo o mapa de pontos a ser considerados no c�clulo (figura 9.1).*/
char adress2[121] = "mapav.txt"; /* nome do arquivo contendo o mapa com os valores iniciais de cada ponto.*/
int mdim[2]; int i = 0, j;
int it = 0;
int ok = 0, totalp;
int** map_mask;
double** map_val;
double** n_fmap;

FILE* map = fopen("mapam.txt","rt"); /* Abre o mapa contendo os pontos a ser considerados.*/
if(map == NULL){
printf("\nThe file wasn't found.\n");
}

readmap_dim(adress, mdim, map); /* Fun��o que retorna as dimens�es do mapa.*/
map_mask = readmap_mask(adress, mdim, map); /*Fun��o que retorna o mapa contendo os pontos a ser considerados no c�lculo.*/
fclose(map);

FILE* map2 = fopen("mapav.txt", "rt"); /* Abre o mapa contendo os valores iniciais de polui��o cada ponto do mapa.*/
map_val = readmap_val(adress2, mdim, map2); /* leitura dos valores de polui��o inicial. Retorna matriz de ponto flutuante.*/
close(map2);

n_fmap = new_fmat(mdim); /*cria uma matriz conforme as dimens�es especificadas no vetor mdim.*/

while(ok!=1){
it = refresh_map(mdim, map_mask,map_val,n_fmap,it); /*atualiza os valores de polui��o.*/
ok = verify_map(mdim,map_mask,map_val,n_fmap); /* verifica se n�o h� necessidade de mais uma itera��o.*/
    if(ok == 0){
    rewrite_mat(mdim,map_mask,map_val,n_fmap,it); /* Escreve a matriz atual na anterior.*/
    }
}
printf("\n Number of iteration: %d \n", it);

totalp = total_pollutant(mdim,map_mask,n_fmap); /* C�lcula a quantidade total de poluente.*/


return 0;
}

