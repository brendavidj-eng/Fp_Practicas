// Clase 04-05-26

#include <stdio.h>

int main (){
    FILE *archivo;
    archivo = fopen("datos.txt", "r");

    if(archivo == NULL){
        printf("Error fatal: datos.txt No es un archivo o carpeta \n");
        return 1;
    }

    char c;
    c = getc(archivo);
    while(c!=EOF){
        printf("%c", c);
        c = getc(archivo); //getc siempre lee el siguiente caracter 
    }
    printf("\n");
    fclose(archivo);

    return 0;

}