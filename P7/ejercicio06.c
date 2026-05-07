#include <stdio.h>

/*
INSTRUCCIONES:
Determina si A es mayor que B
*/

int main() {
    int a, b;
    printf("Ingresa el valor de A y B: \n");
    scanf("%d %d", &a, &b);

    if (a>b) {
        printf("A es mayor\n");
    } else {
        printf("B es mayor o iguales\n");
    }

    return 0;
}