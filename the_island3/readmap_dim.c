/* Homework 1 - Data structures*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*Reading Functions*/


void readmap_dim(const char adress[121], int* mdim, FILE* map){
char hold[100] = "";
int l = 0, i = 0;
char iarrow = '\0';
char digit_f = 48, digit_c = 57;/*ASCII for digits: 48-57*/



if(map == NULL){
printf("The file wasn't found.");
return;
}


while((iarrow) != '\n'){
iarrow = fgetc(map);
    if((iarrow<=digit_c) && (iarrow>=digit_f)){ /* strcat, strtof*/
        while(hold[l] != '\0'){
        l++;
        }
        hold[l] = iarrow;
        hold[++l] = '\0';

    }
    else{
    *(mdim+i) = (int) strtod(hold,NULL);
    hold[0] = '\0'; l = 0;
    i++;
    }
}

*(mdim+i) = (int) strtod(hold,NULL);

printf("Number of lines: %d\nNumber of columns: %d\n", *(mdim+0), *(mdim+1));


rewind(map);
}



