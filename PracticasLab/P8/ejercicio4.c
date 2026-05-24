#include <stdio.h>

int main()
{
    int n;
    int suma = 0;

    do {
        printf("Ingresa un número a sumar o 0 para terminar. \n");
        scanf("%d", &n);
        suma = suma + n;
    } while (n != 0);

    printf("La suma es: %d\n", suma);

    return 0;
}