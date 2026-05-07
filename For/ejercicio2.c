#include <stdio.h>

int main() {
    int n;

    printf("Ingresa un número: ");
    if (scanf("%d", &n) != 1) {
        printf("Error: Ingresa un número entero válido.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {      
        for (int j = 1; j <= i; j++) { 
            printf("%d ", j);
        }
        printf("\n");   
    }
    for (int i = n-1; i >= 1; i--) {      
        for (int j = 1; j <= i; j++) {  
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}