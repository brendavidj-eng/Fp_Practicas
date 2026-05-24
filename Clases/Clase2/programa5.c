#include<stdio.h>
int main(){

    // Negación
    int x,y;
    x=(!(7>15));
    printf("%d",x);
    y=(!0);
    printf("%d",y);

    // Conjunción
    x=(35>20)&&(20<=23);
    
    return 0;
}