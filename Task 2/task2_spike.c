#include<stdio.h>


int main(){
int i;
long product =1;

for (i=1;i<=5;i++){

product*=i;

}
printf("The product from 1-5 is %ld ",product);

return 0;

}
