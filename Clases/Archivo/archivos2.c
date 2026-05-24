// Clase 04-05-26

#include <stdio.h>

int main (){
    FILE *archivo;
    archivo = fopen("datos.txt", "a"); //añadir al final

    if(archivo == NULL){
        printf("Error fatal: datos.txt No es un archivo o carpeta \n");
        return 1;
    }
    fprintf(archivo, "\nAlfonso\t20\t0\n");
    fprintf(archivo, "Nepomuceno\t42\t0\n");
    fclose(archivo);

    return 0;

}