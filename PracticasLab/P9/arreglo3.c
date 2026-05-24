#include <stdio.h>

/* 
* Este programa permite trabajar con un arreglo a través de un apuntador 
*(Apuntador: variable que almacena una dirección de memoria(& o nombre de un arreglo)
*(* a un apuntador = valor contenido en la dirección de memoria que guarda el apuntador)
*/

int main (){
    int array[10];
    int *apuntador;

    apuntador = array; //Apuntador almacenala dirección de memoria del primer elemento del array
    // apuntador = &array[0];

    for (int i=0; i<10; i++){
        printf ("Ingresa el valor del elemento %d: ", i);
        //scanf("%d", &array[i]);
        scanf ("%d", (apuntador+i));
    }
    printf("[ ");
    for (int i=0; i<10; i++){
        printf ("%d (%p) ,", *(apuntador+i), (apuntador+i));
    }
    printf("]\n");

    return 0;
}