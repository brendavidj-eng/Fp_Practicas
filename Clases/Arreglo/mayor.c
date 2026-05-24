#include <stdio.h>
#define MAX 1000

int main (){
    int n;
    int array [MAX];
    int max = 0;

    printf ("Ingresa el número de datos: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++){
        printf("Ingresa el dato[%i]: ", i);
        scanf ("%d", &array[i]);
    }

    for (int i=0; i<n; i++){
        if (max < array[i])
        max =array[i];
    }

    printf ("El valor máximo es: %d\n", max);
    return 0;

}