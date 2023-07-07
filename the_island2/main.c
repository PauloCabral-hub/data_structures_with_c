#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(void){

char adress[121] = "mapam.txt";
char adress2[121] = "mapav.txt";
int mdim[2]; int i = 0, j, it = 0;
int** map_mask; double** map_val;
double** n_fmat;

FILE* map = fopen("mapam.txt","rt");
if(map == NULL){
printf("\nThe file wasn't found.\n");
}
readmap_dim(adress, mdim, map);
map_mask = readmap_mask(adress, mdim, map);
fclose(map);

FILE* map2 = fopen("mapav.txt", "rt");
map_val = readmap_val(adress2, mdim, map2);
close(map2);

n_fmat = new_fmat(mdim);

it = refresh_map(mdim,map_mask,map_val,n_fmat,it);

return 0;
}

