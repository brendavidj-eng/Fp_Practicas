#include <stdio.h>

/* 
* Este programa permite trabajar con un arreglo a través de un apuntador 
*(Apuntador: variable que almacena una dirección de memoria(& o nombre de un arreglo)
*/

int main (){
    int array[10];
    int *apuntador;

    apuntador = &array[7]; //Apuntador almacenala dirección de memoria del primer elemento del array
    // apuntador = &array[0];

    for (int i=-4; i<8; i++){
        printf ("Ingresa el valor del elemento %d: ", i+2);
        //scanf("%d", &array[i]);
        scanf ("%d", (apuntador+i));
    }
    printf("[ ");
    for (int i=-7; i<8; i++){
        printf ("%d , ", *(apuntador+i));
    }
    printf("]\n");
    return 0;
}