#include <stdio.h>

int main () {
    int x, y;

    // Negación
    x=(!(7>15));
    printf("Not x: %d\n", x);

    // Conjunción 
    x= (35>20)&&(20<=23);
    printf("And x: %d\n", x);
    y=0 && 1;
    printf("And y: %d\n", y);

    //Disyunción
    x=(35>20)||(20<=18);
    printf("Or x: %d\n", x);
    y=0 || 1;
    printf("Or y: %d\n", y);

    return 0;

}