#include <stdio.h>

/* 
* Este programa sirve para imprimir las direcciones de los elementos de un arreglo
*/

int main (){
    int array [7];
    float array2[10];

    printf("El tamaño de un entero en bytes es: %ld\n", sizeof(int));

    for (int i=0; i<7; i++){
        printf("La dirección del elemento %d es: %p\n", i, &array[i]);
    }
    printf ("\n");

    for (int i=0; i<10; i++){
        printf ("La dirección del elemento %d es: %p\n", i, &array2[i]);
    }

    return 0;
}