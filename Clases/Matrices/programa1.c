// Clase 24_04_26

#include <stdio.h>
#define TAM 100

void print_dir_array(float array[][TAM], int nr, int nc){
    float *ptr = &array[0][0];
    for(int i=0; i<nr*nc; i++){
        printf("%p \n", (ptr +i));
    }
}

void print_array(float array[][TAM], int nr, int nc){
    float *ptr = &array[0][0];
    printf ("[\n");
    for (int i =0; i<nr*nc; i++){
        printf("%.2f ", *(ptr+i));
        if ((i+1)%nc == 0){
            printf("\n");
        }
    }
    printf("]\n");
}

int main (){
    float matriz[][TAM] = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    int matInt[][TAM]={1, 0, 0, 1, 0, 0, 0, 1};
    float *ptr;
    //ptr=matriz;
    ptr = &matriz[0][0];

    //print_dir_array(matriz, 3, 3);
    print_array(matriz,3,3);

    return 0;
}