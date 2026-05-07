#include <stdio.h>

int main() {
    int num;
    int suma=0;

    printf("Ejercicio Final:\n");

    while (1) {
        printf("Ingresa un número o 0 para salir: ");
        scanf("%d", &num);

        if (num == 0) {
            break; 
        }

        if (num > 100) {
            printf("Número mayor a 100. Finalizando...\n");
            break;
        }

        if (num < 0) {

            continue;
        }

        suma += num;
    }

    printf("La suma total de los números positivos es: %d\n", suma);

    return 0;
}