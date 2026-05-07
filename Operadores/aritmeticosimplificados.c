#include <stdio.h>

int main () {
    int x, y;

    //Suma
    x=6;
    y=4;
    x += 3;
    printf("x=%d\n", x);
    x += y;
    printf("x=%d\n", x);

    //Resta
    x=6;
    printf("x=%d\n", x);
    y=2;
    printf("y=%d\n", y);
    x-=1;
    printf("x=%d\n", x);
    x-=y;
    printf("x=%d\n", x);
    
    //Multiplicación
    x=5;
    y=3;
    x*=2;
    printf("x=%d\n", x);
    x*=y;
    printf("x=%d\n", x);

    //División
    x=30;
    y=2;
    x/=3;
    printf("x=%d\n", x);
    x/=y;
    printf("x=%d\n", x);

    //Módulo
    x=20;
    y=3;
    x%=12;
    printf("x=%d\n", x);
    x%=y;
    printf("x=%d\n", x);

    //Incremento
    x=7;
    y= x++; //Post-incremento
    printf("x=%d\n", x);
    printf("y=%d\n", y);
    x=7;
    y=++x; //Pre-incremento
    printf("x=%d\n", x);
    printf("y=%d\n", y);

    //Decrecemento
    x=7;
    y=x--; //Post-decremento
    printf("x=%d\n", x);
    printf("y=%d\n", y);
    x=7;
    y=--x; //Pre-incremento
    printf("x=%d\n", x);
    printf("y=%d\n", y);

    return 0;

}