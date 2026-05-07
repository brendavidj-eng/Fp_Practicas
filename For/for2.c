#include <stdio.h> 

void main (){
    int n, i=0;
    printf ("Ingresa un número \n");
    scanf ("%d", &n);

    for (i=1; i<=10; ++i)
        printf ("%d x %d =%d\n", n, i, n*i);

    for (i=1; i<=10; i++)
        printf ("%d x %d = %d\n", n, i, n*i);
}