// Programa que lee matrices _ 20/04/26
#include <stdio.h>
#define TAM 1000

int main(){
    //Tipo - identificador - [n1][n2]...[nk]
    // int cubo [3][3][3];
    // float matriz [3][3];
    //           m x n
    int matriz [TAM][TAM];

    int m, n;

    printf("Ingresa el número de renglones: ");
    scanf("%d", &m);

    printf("Ingresa el número de columnas: ");
    scanf("%d", &n);

    printf("La dirección de la Matriz es: %p\n", matriz);
    printf("La dirección del primer elemento de la Matriz es: %p\n", &matriz[0][0]);

    for(int i=0; i<m; i++){         //Sirve para cambiar de renglón
        for(int j=0; j<n; ++j){     // Cambia las columnas de un renglón
            printf ("Ingresa el valor para matriz [%d, %d]: ", i, j);
            scanf ("%d", &matriz[i][j]);
        }
    }

    for(int i=0; i<m; i++){
        printf("[ ");
        for(int j=0; j<n; ++j){
            printf("%d, ", matriz[i][j]);
        }
        printf("]\n");
    }

    return 0;
}