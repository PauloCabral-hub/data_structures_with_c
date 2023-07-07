
int total_pollutant(int* mdim, int** map_mask, double** n_fmap){
int i,j;
double totalp = 0;
double area = 20.0;
double h = 1.0;

for(i=0;i<mdim[0];i++){
    for(j=0;j<mdim[1];j++){
        if((map_mask[i][j] == 1)||(map_mask[i][j] == 2)){
        totalp = totalp+ n_fmap[i][j];
        }
    }
}

totalp = totalp*area*h;

printf("\n The total amount of pullutant is: %f litters \n", totalp);

return totalp;
}
