/*Exercises

1.1 */
#include<stdio.h>
#include<math.h>
int inside_rect(int x0, int y0, int x1, int y1, int x, int y){

if(((x<=x1)&&(x>=x0))&&((y<=y1)&&(y>=y0))){
    return 1;
}
else{
    return 0;
}

}



int isprime(int num){
int i,j,w;
float l1 = sqrt(num);

int v[num];
    for(i = 0;i<num;i++){
    v[i] = 1;
    }

for(i=2;i< l1; i++){
  if(v[i]){
    for(w=0,j=i*i;j<num;w++,j=i*i+i*w){
      v[j]=0;
    }
  }
}

return v[num-1];
}


int fibonacci(int n){
int i, a,b,c;

for (i = 0; i<=n-1; i++){
    if(i<2){
    a = 1; b = 1; c = 1;
    }
    if(i == 2){
    c = 2;
    }
    else{
    a = b;
    b = c;
    c = a+b;
    }
}
printf("The %d-esimal number of the fibonacci sequency is: %d", n,c);
return c;
}

int sumodd(int n){
int i, a, c;

for(i=1;i<=n;i++){
    if(i==1){
    a=1;c=1;
    }
    else{
    a = a+2;
    c = c+a;
    }
}

printf("the sum of the n first odd numbers is: %d %d",c, 2^2);
return c;
}

double pi_aprox(int n){
int i, j, a;
int sign = -1, m = -1;
double b, c, s;
for(i=0;i<=n-1; i++){
    for(j = 0;j<=i;j++){
    sign = m*sign;
    }
if(i == 0){
s= 1; a = 1;
}
else{
b = (double) sign*(a+2);
s = s + (1/b);
printf("\n%f\n", s);
a = a+2;
}

}

c = (double) 4*s;
printf("The pi approximation for %d-elements is: %1.12f",n,c);
return c;
}

float msqrt(int N){
float li, ls, m, min = 0.0001, n;
n = (float) N;
for(li = 0, ls = n, m = (ls+li)/2;((m*m)-n) < min; m = (ls-li)/2){
    if(m*m>n){
    ls = m;
    }
    else{
    li = m;
    }
}
return m;

}

int roots(float a, float b, float c, float* x1, float* x2){

float delta = (b)*(b)-4*a*c;
printf("%f", delta);
if(delta<0){
return 0;
}
else if (delta==0){
*x1 = (-b+sqrt(delta))/2*a;
*x2 = *x1;
return 1;
}
else{
*x1 = (-b-sqrt(delta))/2*a;
*x2 = (-b+sqrt(delta))/2*a;
return 2;
}

}

void sphere(float r, float*a, float* v){
float sup = 4*r*r;
float vol = sup*r/3;
printf("\n %f %f", sup, vol);

*a = sup;
*v = vol;

}

int negatives(int n, float *vet){
int i, num;
    for(i = 0, num = 0; i<n-1; i++){
    if(vet[i]<0){
    num++;
    }
    }
return num;
}

int even_vet(int n, int *vet){
int i, num;
for (i =  0, num = 0; i< n-1; i++){
    if(vet[i]%2 == 0){
    num++;
    }
}


printf("There are %d even number.", num);
return num;
}

void invert_vet(int n, int *v){
int i, holder, j = -1;
int *aux1, *aux2;

for (i = 0; i<n; i++){
    aux1 = v;
    for(j=0; j< (n-2)-i; j++, aux1 = v++, aux2 = aux1++){
    if (v[i]<v[i+1]){
    holder = v[i];
    *aux1 = v[i+1];
    *aux2 = holder;
    }
    }
}

}

int main(void){
int v[5] = {5,4,3,2,1};
int i, n = 5, r;

invert_vet(n, v);
for(i=0;i<n;i++){
printf("%d", v[i]);
}

return 0;
}



