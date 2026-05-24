#include <string.h>
#include <stdio.h>
// El ciclo que se ejecuta una vez es do-while
//Si el usuario ingresa la contraseña correcta desde el inicio se ejecuta una sola vez while y se concede el acceso 
int main (){
    char password[]="Hola123";
    char intento[15];

    do {
        printf("Introduce la contraseña: ");
        scanf("%s", intento);
        if(strcmp(intento,password)!=0){
            printf("Contraseña incorrecta. Intente de nuevo. \n");
        }
    } while (strcmp (intento, password)!=0);
    printf ("Acceso permitido. ¡Bienvenido/a!\n");
    return 0;
}