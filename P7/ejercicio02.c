#include <stdio.h>

/*
INSTRUCCIONES:
Completa la condición para que imprima "Mayor de edad"
si la edad es 18 o más.
*/

int main() {
    int edad;
    printf("Ingresa la edad: \n");
    scanf("%d", &edad);

    if (edad >= 18) {
        printf("Mayor de edad\n");
    } else {
        printf("Menor de edad\n");
    }

    return 0;
}