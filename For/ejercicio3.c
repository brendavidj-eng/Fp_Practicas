#include <stdio.h>

int main() {
    int n, i, j, k;

    printf("Ingresa un número entero: ");
    scanf("%d", &n);
    for (i = n; i >= 1; i--) {
        
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        for (k = 1; k <= (n - i) * 4; k++) {
            printf(" ");
        }

        for (j = i; j >= 1; j--) {
            printf("%d ", j);
        }

        printf("\n"); 
    }

    return 0;
}