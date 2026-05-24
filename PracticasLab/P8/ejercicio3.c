#include <stdio.h>

int main()
{
    int n;
    int pos = 0;
    int neg = 0;
    printf("Ingresa un número entero o 0 para terminar: \n");
    scanf("%d", &n);
    while (n != 0)
    {
        if (n < 0) {
            neg++;
        } else {
            pos++;
        }

        printf("Ingresa otro número: \n");
        scanf("%d", &n);

    }

    printf("Los números positivos totales son: %d\n", pos);
    printf("Y los números negativos totales son: %d\n", neg);

    return 0;
}