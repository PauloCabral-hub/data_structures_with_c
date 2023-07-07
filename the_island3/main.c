#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(void){
//int o;
char adress[121] = "mapam.txt";
char adress2[121] = "mapav.txt";
int mdim[2]; int i = 0, j;
int it = 0;
int ok = 0, totalp;
int** map_mask;
double** map_val;
double** n_fmap;

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

n_fmap = new_fmat(mdim);

while(ok!=1){
it = refresh_map(mdim, map_mask,map_val,n_fmap,it);
ok = verify_map(mdim,map_mask,map_val,n_fmap);
    if(ok == 0){
    rewrite_mat(mdim,map_mask,map_val,n_fmap);
    }
//printf("\n ...continue? ");scanf("%d",&o);if(o==0){break;}

}
printf("\n Number of iteration: %d \n", it);

totalp = total_pollutant(mdim,map_mask,n_fmap);


return 0;
}

