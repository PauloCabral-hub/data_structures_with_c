#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*Trabalho: Cálculo de poluição total da ilha.*/

int main(void){
int o;
char adress[121] = "mapam.txt"; /*nome do arquivo contendo o mapa de pontos a ser considerados no cáclulo (figura 9.1).*/
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

readmap_dim(adress, mdim, map); /* Função que retorna as dimensões do mapa.*/
map_mask = readmap_mask(adress, mdim, map); /*Função que retorna o mapa contendo os pontos a ser considerados no cálculo.*/
fclose(map);

FILE* map2 = fopen("mapav.txt", "rt"); /* Abre o mapa contendo os valores iniciais de poluição cada ponto do mapa.*/
map_val = readmap_val(adress2, mdim, map2); /* leitura dos valores de poluição inicial. Retorna matriz de ponto flutuante.*/
close(map2);

n_fmap = new_fmat(mdim); /*cria uma matriz conforme as dimensões especificadas no vetor mdim.*/

while(ok!=1){
it = refresh_map(mdim, map_mask,map_val,n_fmap,it); /*atualiza os valores de poluição.*/
ok = verify_map(mdim,map_mask,map_val,n_fmap); /* verifica se não há necessidade de mais uma iteração.*/
    if(ok == 0){
    rewrite_mat(mdim,map_mask,map_val,n_fmap,it); /* Escreve a matriz atual na anterior.*/
    }
}
printf("\n Number of iteration: %d \n", it);

totalp = total_pollutant(mdim,map_mask,n_fmap); /* Cálcula a quantidade total de poluente.*/


return 0;
}

