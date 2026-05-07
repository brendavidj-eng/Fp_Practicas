/*Programa que muestra la serie de Ulam de un número entero*/
#include <stdio.h>

void main () {
    int n, s;
    do{
        printf("Ingresa un número entero positivo \n");
        scanf("%d", &n);
    
    }while (n<=0);
    s=n;
    while(s>1){
        if(s%2==0){
            s=s/2;
        } else {
            s=s*3+1;
        }
        printf("%d, ", s);
    }
}