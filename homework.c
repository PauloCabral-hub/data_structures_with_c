#include<stdio.h>

int main(void){

/*On ASCII table 0-9 corresponds to 48-57*/

char cs[]= "562,23";
double fn = 0.0, div = 0.1;
int i, j,jj,w,ww, icom, inat, idec, tn, td;
int mply = 1;



for(i = 0; i<=sizeof(cs)-1; i++){

    if(cs[i]==','){
        icom = i;
        inat = i;
        idec = sizeof(cs)-1-(i+1);
    }
    else{
    }
}
printf("the comma is at the position %d \n the number of natural numbers is %d \n The number of decimal numbers is %d", icom, inat, idec);



for(j= 0; j<icom;j++){
tn = cs[(icom-1)-j]-48;

    if (j!= 0){
        for (jj=1;jj<=j;jj++){
        mply = mply*10;
        }
    }

fn = fn + tn*mply;
mply = 1;
}

for(w = 0; w<idec; w++){
    td = cs[(icom+1)+w]-48;

    if (w!=0){
        for(ww=1;ww<=w;ww++){
         div = div/10;
        }
    }

    printf("\n %f %d", div, td);
fn = fn+ td*div;
div = 0.1;
}

printf("\n the number typed was this? %f \n",fn);


return 0;
}
