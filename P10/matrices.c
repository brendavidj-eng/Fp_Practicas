// Ejercicio 22_04_26 lab

#include <stdio.h>
#include <stdbool.h>

#define TAM 100

void LeerMatriz(float M[][TAM], int f, int c) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            printf("Elemento [%d,%d]: ", i, j);
            scanf("%f", &M[i][j]);
        }
    }
}

void MostrarMatriz(float M[][TAM], int f, int c) {
    for (int i = 0; i < f; i++) {
        printf("[ ");
        for (int j = 0; j < c; j++) {
            printf("%.2f ", M[i][j]);
        }
        printf("]\n");
    }
}

void SumarMatrices(float A[][TAM], float B[][TAM], float C[][TAM], int f, int c) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void MultiplicarMatrices(float A[][TAM], float B[][TAM], float C[][TAM], int fA, int cA, int cB) {
    for (int i = 0; i < fA; i++) {
        for (int j = 0; j < cB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < cA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void Transpuesta(float A[][TAM], float T[][TAM], int f, int c) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            T[j][i] = A[i][j];
        }
    }
}

float Determinante(float M[][TAM], int n) {
    if (n == 1) return M[0][0];
    if (n == 2) return (M[0][0] * M[1][1]) - (M[0][1] * M[1][0]);

    float det = 0;
    float sub[TAM][TAM];
    int signo = 1;

    for (int i = 0; i < n; i++) {
        int subi = 0;
        for (int j = 1; j < n; j++) {
            int subj = 0;
            for (int k = 0; k < n; k++) {
                if (k != i) {
                    sub[subi][subj] = M[j][k];
                    subj++;
                }
            }
            subi++;
        }
        det += signo * M[0][i] * Determinante(sub, n - 1);
        signo *= -1;
    }
    return det;
}


//Proceso Principal

int main() {
    float A[TAM][TAM], B[TAM][TAM], C[TAM][TAM];
    int fA, cA, fB, cB, opcion;

    printf("Ingrese filas y columnas de la matriz A:\n");
    scanf("%d %d", &fA, &cA);
    
    LeerMatriz(A, fA, cA);

    printf("\nSeleccione operacion:\n");
    printf("1. Suma\n2. Multiplicacion\n3. Transpuesta\n4. Determinante\n");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            printf("Ingrese filas y columnas de la matriz B:\n");
            scanf("%d %d", &fB, &cB);
            if (fA == fB && cA == cB) {
                LeerMatriz(B, fB, cB);
                SumarMatrices(A, B, C, fA, cA);
                MostrarMatriz(C, fA, cA);
            } else {
                printf("No se pueden sumar\n");
            }
            break;

        case 2:
            printf("Ingrese filas y columnas de la matriz B:\n");
            scanf("%d %d", &fB, &cB);
            if (cA == fB) {
                LeerMatriz(B, fB, cB);
                MultiplicarMatrices(A, B, C, fA, cA, cB);
                MostrarMatriz(C, fA, cB);
            } else {
                printf("No se pueden multiplicar\n");
            }
            break;

        case 3:
            Transpuesta(A, C, fA, cA);
            MostrarMatriz(C, cA, fA);
            break;

        case 4:
            if (fA == cA) {
                printf("Determinante = %.2f\n", Determinante(A, fA));
            } else {
                printf("Debe ser matriz cuadrada\n");
            }
            break;
    }

    return 0;
}