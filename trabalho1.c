/*This code receives a text note containing a map. This Map is a matrix
 containing 0, indicating square meter of sea, 1, indicating a square
 meter of land and 2, as a source of pollution in land. The objective of
 the program is to calculate at each iteration the dispersion of the
 pollution trough-out the island. The dispersion is calculated by the
 simple mean of the the orthogonal neighbors. Any point not shown on
 the map should be considered as a square meter of sea.*/
#include<stdio.h>


 void mapsize(int* l, int* c){
 int d, header = 0;
 char map[120];
 *c = 0;
 FILE *omap;

 printf("Type the name of the file: \n");
 scanf("%s", &map);


 /*opening the working file*/

 omap = fopen(map,"rt");

 if (omap == NULL){
    printf("It's not possible to open the file. ");
 }

/*getting to the map*/

while(header!= 3){
d = fgetc(omap);
    if(d == '\n'){
    header++;
    }
 }

/*counting the number of columns of the map*/

while((d = fgetc(omap))!= '\n'){
    if (d != ' '){
    *c = *c+1;
    }
}

/*counting the number of lines of the map*/
if(*c!= 0){*l = 1;};
while((d = fgetc(omap))!= EOF){
    if(d == '\n'){
    *l = *l+1;
    }
}
*l = *l+1;

printf("The map has %d lines and %d columns.\n", *l, *c);

close(omap);
 }



int main(void){
int d, l, c, h = 0;
int i, j, m, n;
float a;
char mapname[120];
FILE *omap;
printf("Type the name of the file: \n");
scanf("%s", &mapname);

mapsize(&l,&c);

omap = fopen(mapname,"rt");

float map[l][c];

while(h!=3){
 if(d = fgetc(omap)== '\n'){
 h++;
 }
}

for(i = 0; i<l; i++){
    for(j = 0; j<c; j++){
    d = fgetc(omap);
    map[i][j]= (float) d - 48;
    d = fgetc(omap);
    }
}



for(i = 0; i<l; i++){
    for(j = 0; j<c; j++){
    a  = 0F;
        m = i - 1;
        if(m<0){
        }
        else{
        a = a + map[m][j];
        }

        m = i + 1;
        if(m=>l){
        }
        else{
        a = a + map[m][j];
        }

        n = j-1
        if(n<0){
        }
        else{
        a = a + map[i][n];
        }

        n = j+1;
        if(n=>c){
        }
        else{
        a = a + map[i][n];
        }

        map[i][j] = a/4;
        /*This should be used if the the i,j point of the matrix must be actualized with the mean of the 4 orthogonal values.

    }
}



return 0;
}

/*
This segment print the matrix map (delete this line before using).

for(i = 0; i<l; i++){
    for(j = 0; j<c; j++){
    printf("%f ", map[i][j]);
    }
printf("\n");
}*/
