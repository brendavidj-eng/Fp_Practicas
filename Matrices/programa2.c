// Clase 27_04_26

#include <stdio.h>

#define TAM 100

void sum_matrices(float *a, float *b, float *c, int nr, int nc){
    for(int i=0; i<nr; i++){
        *(c+i) = *(a+i) + *(b+i);
    }
}

void leer_matrices(float *m, int nr, int nc){
    int j=0, k=0;
    for (int i=0; i<nr*nc; i++){
        printf("Ingresa el valor M[%d, %d]: ", k, j++);
        scanf ("%f", (m+i));
        if(j%nc==0) j=0;
        if(j==0) k++;
    }
}

void escribir_matrices(float *m, int nr, int nc){
    for (int i=0; i<nr*nc; i++){
        printf("%0.2f", *(m+i));
        if((i+1)%nc==0)printf("\n");
    }
}

int main(){
    float a[TAM][TAM], b[TAM][TAM], c[TAM][TAM]; //Arreglo de dos dimensiones
    int nrA, ncA, nrB, ncB;
    printf ("Ingresa el número de columnas y renglones de la primera matriz: \n");
    scanf("%i %i", &nrA, &ncA);
    leer_matrices(&a[0][0], nrA, ncA);
    printf("Ingresa el número de columnas y renglones de la segunda matriz: \n");
    scanf("%i %i", &nrB, &ncB);
    leer_matrices(&b[0][0], nrB, ncB);
    sum_matrices(&a[0][0], &b[0][0], &c[0][0], nrA, ncA);
    escribir_matrices(&c[0][0], nrA, ncB);
    return 0;
}