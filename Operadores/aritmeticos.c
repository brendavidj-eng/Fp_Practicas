#include <stdio.h>

int main () {
    int x;
    float v;

    //Suma 
    x=4.5+3;
    v=4.5+3;
    printf("Suma: x=%d, v=%.1f\n", x, v);
    
    //Resta
    x=4.5-3;
    v=4.5-3;
    printf("Resta: x=%d, v=%.1f\n", x, v);

    //Multiplicación 
    x=(int)4.5*3;
    printf("Mult x: %d\n", x);
    v=4.5*3;
    printf("Mult v: %.1f\n", v);
    v=4*3;
    printf("Mult v: %.1f\n", v);

    //División 
    x=4/3;
    printf("Div x: %d\n", x);
    x=4.0/3.0;
    printf("Div x: %d\n", x);
    v= 4/3;
    printf("Div v: %.1f\n", v);
    v= 4.0/3;
    printf("Div v: %.2f\n", v);
    v= (float)4/3;
    printf("Div v: %.2f\n", v);

    //Módulo
    x=15%2;
    printf("Mod x: %d\n", x);
    v=(15%2)/2;
    printf("Mod v: %.1f\n", v);
    v= (float)(15%2)/2;
    printf("Mod v: %.1f\n", v);

    return 0;

}