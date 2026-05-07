#include <stdio.h>
#define MAX 1000

int main() {
    int n, array[MAX];

   
    printf("Ingresa el numero de datos: ");
    scanf("%d", &n);

   
    for (int i = 0; i < n; i++) {
        printf("Ingresa el dato [%i]: ", i);
        scanf("%d", &array[i]);
    }

   
    printf("\nEl arreglo invertido es: [");
    
   
    for (int i = n - 1; i >= 0; i--) {
        printf(" %d ", array[i]);
    }
    
    printf("]\n");

    return 0;
}