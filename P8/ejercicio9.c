#include <stdio.h>

int main() {
    int num;
    //El programa termina con un número negativo

    while (1) {
        printf("Introduce un número: ");
        scanf("%d", &num);

        if (num < 0) {
            printf("Número negativo. Saliendo...\n");
            break;
        }
        
    }

    return 0;
} 