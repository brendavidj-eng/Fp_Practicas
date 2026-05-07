#include <stdio.h>

int main()
{
    int num;
    printf("Ingresa un número: \n");
    scanf ("%d", &num);

    for (; num >=0; ){
        printf ("%d\n", num);
        printf ("Ingresa otro número: \n");
        scanf("%d", &num);
    }
    return 0;
}