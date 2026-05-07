#include <stdio.h>

/*
* Este programa ilustra que todas las variables tienen una direcciòn
*/

int main (){

    int x, y;
    float f, g;
    int array[5];
    float array2[3];

    printf ("La direcciòn de x es: %p\n", &x);
    printf ("La direcciòn de y es: %p\n", &y);
    printf ("La direcciòn de f es: %p\n", &f);
    printf ("La direcciòn de g es: %p\n", &g);
    printf ("La direcciòn de array es: %p\n", array);
    printf ("La direcciòn de array2 es: %p\n", array2);
    printf ("La direcciòn de array es: %p\n", &array[0]);
    printf ("La direcciòn de array2 es: %p\n", &array2[0]);

    return 0;

}