#include<stdio.h>
#include<string.h>
#include<stdlib.h>


double** readmap_val(char adress[121], int* mdim, FILE* map){
int m, i = 0, j= 0, l=0, lines = mdim[0], columns = mdim[1];
char hold[100] = "", digit_f = 48, digit_c = 57;/*ASCII for digits: 48-57*/;
char* iarrow = '\0';



double** map_val = (double**) malloc(sizeof(double*)*lines);
for(m = 0;m<columns;m++){
map_val[m] = (double*) malloc(sizeof(double)*columns);
}


if(map == NULL){
printf("The file was not found.\n");
return;
}
else{
printf("The file was found.\n");
}

while(iarrow != EOF){
iarrow = fgetc(map);
    if(((iarrow<=digit_c)&&(iarrow>=digit_f))||(iarrow == '.')){
        while(hold[l] != '\0'){
        l++;
        }
        hold[l] = iarrow;
        hold[++l] = '\0';
    }
    else{
    map_val[i][j] = strtod(hold,NULL);
    i++;
        if(iarrow == '\n'){
        j++;i = 0;
        }
    hold[0] = '\0'; l = 0;
    }
}
map_val[i][j] = (float) strtod(hold,NULL);

printf("\n This is the Map of values \n");

for(i = 0; i < mdim[0]; i++){
    for(j = 0;j< mdim[1]; j++){
    printf("%.3f ", map_val[i][j]);
    }
printf("\n");
}

rewind(map);

return map_val;
}

