#include <stdio.h>

int main (){
    float a,b,c,d;
    printf("Ingresa los 4 números\n");
    scanf("%f %f %f %f", &a, &b, &c,&d);
    if (a>b && a>c && a>d) {
        printf("%.1f\n", a);
    } else if (b>a && b>c && b>d) {
        printf("%.1f\n", b);
    } else if (c>a && c>b && c>d) {
        printf("%.1f\n", c);
    } else if (d>a && d>b && d>c) {
        printf("%.1f\n", d);
    }
    return 0;
}