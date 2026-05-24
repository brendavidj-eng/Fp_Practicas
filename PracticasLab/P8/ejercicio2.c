#include <stdio.h>

int main()
{
    int n;
    int suma=0;
    printf("Ingresa un número a sumar o 0 para terminar. \n");
    scanf("%d", &n);
    while (n != 0) {
        suma = suma + n;
        printf ("Ingresa otro número: \n");
        scanf("%d", &n);
    }
    printf ("La suma es: %d\n", suma);

    return 0;

}