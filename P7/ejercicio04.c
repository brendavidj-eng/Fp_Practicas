#include <stdio.h>

/*
INSTRUCCIONES:
Completa la condición:
- Positivo si > 0
- En otro caso imprimir "Negativo o cero"
*/

int main() {
    int num;
    printf("Ingresa un número\n");
    scanf("%d", &num);

    if (num>0) {
        printf("Positivo\n");
    } else {
        printf("Negativo o cero\n");
    }
    
    return 0;
}